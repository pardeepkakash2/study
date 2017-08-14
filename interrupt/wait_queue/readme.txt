https://sysplay.in/blog/linux-kernel-internals/

Process States in Linux:

Before moving on to the wait mechanisms, it would be worthwhile to understand the process states in Linux. 
At any point of time, a process can be in any of the below mentioned states:

    TASK_RUNNING :- Process is in run queue or is running
    TASK_STOPPED :- Process stopped by debugger
    TASK_INTERRUPTIBLE :- Process is waiting for some event, but can be woken up by signal
    TASK_UNINTERRUPTIBLE :- Similar to TASK_INTERRUPTIBLE, but can’t be woken up by signal
    TASK_ZOMBIE :- Process is terminated, but not cleaned up yet

For a process to be scheduled, it needs to be in TASK_RUNNING state, while TASK_INTERRUPTIBLE and TASK_INTERRUPTIBLE states 
correspond to a waiting process.

set_current_state(TASK_INTERRUPTIBLE): move the process out of run queue.

Wait Queues

Wait queue is a mechanism provided in kernel to implement the wait. As the name itself suggests, wait queue is the list of processes 
waiting for an event. Below are the data structures for wait queues:

#include <linux/wait.h>
// Data structure: wait_queue_head_t
// Created statically 
DECLARE_WAIT_QUEUE_HEAD(wait_queue_name);

// Created dynamically
wait_queue_head_t my_queue;
init_waitqueue_head(&my_queue);

As seen above, wait queues can be defined and initialized statically as well as dynamically. Once the wait queue is initialized, 
next step is to add our process to wait queue. Below are variants for this:

wait_event(queue, condition);
wait_event_interruptible(queue, condition);
wait_event_timeout(queue, condition, timeout);
wait_event_interruptible_timeout(queue, condition, timeout);

As seen, there are two variants – wait_event() and wait_event_timeout(). The former is used for waiting for an event as usual,
but the latter can be used to wait for an event with timeout. Say, if the requirement is to wait for an event till 5 milliseconds,
after which we need to timeout.

So, this was about the waiting, other part of the article is to wake up. For this, we have wake_up() family of APIs as shown below:

// Wakes up all the processes waiting on the queue
wake_up(wake_queue_head_t *);

// Wakes up only the processes performing the interruptible sleep
wake_up_interruptible(wait_queue_head_t *);

Below is the sample run of the above program, assuming that the module is compiled as wait.ko:
$ insmod wait_queue.ko
Major Nr: 250
$ cat /dev/mychar0
Inside open
Inside read
Scheduling out

This gets our process blocked. Open another shell to wake up the process:
$ echo 'y' > /dev/mychar0
Inside open
Inside write
y
Inside close
Woken up
Inside close

Waking up the Process:
We have the wake_up_process() API as shown below for waking up the process.

void wake_up_process(task_struct *ts);
ts - pointer to the task_struct of the waiting process

Below is the sample run for the above example. Assuming that the above module is compiled as sched.ko:
$ insmod wait.ko
Major Nr: 250
$ cat /dev/mychar0
Inside open
Inside read
Scheduling out

When we execute the echo command, write operation gets invoked, which invokes the wake_up_process() to wake up the blocked process.
$ echo 1 > /dev/mychar0
Inside open
Inside write
Woken up
Inside close
Inside close

Waiting on an event:
The event can be some specified amount of time, waiting for some resource or it can well be waiting for some data to arrive. 
Below is the modified version of above program to wait for an even

ssize_t read(struct file *filp, char *buff, size_t count, loff_t *offp) 
{
	printk(KERN_INFO "Inside read\n");
	printk(KERN_INFO "Scheduling Out\n");
	sleeping_task = current;
slp:
	if (flag != 'y') 
	{
		set_current_state(TASK_INTERRUPTIBLE);
		schedule();
	}
	if (flag == 'y')
		printk(KERN_INFO "Woken Up\n");
	else 
	{
		printk(KERN_INFO "Interrupted by signal\n");
		goto slp;
	}
	flag = 'n';
	printk(KERN_INFO "Woken Up\n");
	return 0;
}

ssize_t write(struct file *filp, const char *buff, size_t count, loff_t *offp) 
{ 
	printk(KERN_INFO, "Inside write\n");
	ret = __get_user(flag, buffer);
	printk(KERN_INFO "%c", flag);
	wake_up_process(sleeping_task);
	return count;
}

semaphore:
#include <linux/rwsem.h>

// Data Structure
structure rw_semaphore rw_sem;

// Initialization
void init_rwsem(&rw_sem);

// Operations for reader
void down_read(&rw_sem);
void up_read(&rw_sem);

// Operations for writer
void down_write(&rw_sem);
void up_write(&rw_sem);

steps: 
cat /dev/mychar0
Inside Open
Inside Read
Got the Semaphore in Read
Going to sleep

cat /dev/mychar0 (In different shell)
Inside Open
Inside Read
Got the Semaphore in Read
Going to sleep

echo 1 > /dev/mychar0 (In different shell)
Inside Write. Waiting for semaphore...

semaphore:
#include <linux/semaphore.h>

struct semaphore /* Semaphore data structure */

// Initialization
// Statically
DEFINE_SEMAPHORE(my_sem);
// Dynamically
struct semaphore my_sem;
sema_init(&my_sem, val);

// Operations
void down((&sem);
int down_interruptible(&sem);
int down_trylock(&sem);
void up(&sem);

steps:
insmod sem.ko
cat /dev/mysem0 - This will block
echo 1 > /dev/mysem0 - Will unblock the cat process

Mutex:
#include <linux/mutex.h>

struct mutex /* Mutex data structure */

// Mutex Initialization
// Statically
DEFINE_MUTEX(my_mutex);
// Dynamically
struct mutex my_mutex;
mutex_init(&my_mutex);

// Operations
void mutex_lock(&my_mutex);
void mutex_unlock(&my_mutex);
int mutex_lock_interruptible(&my_mutex);
int mutex_trylock(&my_mutex);

steps:
cat /dev/mymutex0 - This will acquire the mutex
cat /dev/mymutex0 - This will block
echo 1 > /dev/mymutex0

Spinlock:
#include <linux/spinlock.h>

// Data structure
struct spinlock_t my_slock

// Initialization
spinlock_init(&my_slock)

// Operations
spin_lock(&my_slock)
spin_unlock(&my_slock)

kernel threads:
#include <linux/kthread.h>

kthread_create(int (*function)(void *data), void *data, const char name[], ...)
Parameters:
	function – The function that the thread has to execute
	data – The ‘data’ to be passed to the function
	name – The name by which the process will be recognized in the kernel

kthread_run(int (*function)(void *data), void *data, const char name[], ...)
Parameters:
function – The function that the thread has to execute
	data – The ‘data’ to be passed to the function
	name – The name by which the process will be recognized in the kernel
Returns: Pointer to a structure of type task_struct

stop the kernel thread:
int kthread_stop(struct task_struct *k);
kthread_should_stop();

Signalling the Kernel Thread:
allow_signal()
void allow_signal(int sig_num)
int signal_pending(task_struct *p)
kill -9 <thread_id>
