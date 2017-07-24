#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/err.h>
#include <linux/sched.h>  // for task_struct
#include <linux/time.h>   // for using jiffies 
#include <linux/timer.h>
#include <linux/types.h> //pid_t, uid_t, and gid_t.
 
static struct task_struct *thread_st;

// Function executed by kernel thread
static int thread_fn(void *unused)
{
	// Allow the SIGKILL signal kill -9 <thread_id>, ps -elf | grep thread.
	allow_signal(SIGKILL);

	/*Note : what will happen if i use while(1) insted of kthread_should_stop() and schedule() vs schedule_timeout vs sleep() */
	while (!kthread_should_stop()) {
		/*set_current_state(TASK_UNINTERRUPTIBLE), schedule_timeout(HZ);*/
		printk(KERN_INFO "Thread Running\n");
		ssleep(5);
		// Check if the signal is pending
		if (signal_pending(thread_st)) {
			printk(KERN_INFO "signal_pending got\n");
			break;
		}
		#if 0
		unsigned long j0,j1;
		int delay = 60*HZ;
		j0 = jiffies;
		j1 = j0 + delay;

		printk(KERN_INFO "In thread1");

		while (time_before(jiffies, j1))
			schedule();
		#endif
	}
	printk(KERN_INFO "Thread Stopping\n");
	do_exit(0);
	return 0;
}

// Module Initialization
static int __init init_thread(void)
{
	int err;
	printk(KERN_INFO "Creating Thread\n");
	/* Create the kernel thread with name 'mythread'
	Note : kthread_create vs kthread_run and wake_up_process.
	kthread_run - create and wake a thread. 
	threadfn: the function to run until signal_pending(current).
 	data: data ptr for @threadfn.
 	namefmt: printf-style name for the thread. 
	Description: Convenient wrapper for kthread_create() followed by wake_up_process().  Returns the kthread or ERR_PTR(-ENOMEM).
	void kthread_bind(struct task_struct *thread, int cpu); => Kernel threads are often created to run on a particular processor */
	
	thread_st = kthread_run(thread_fn, NULL, "mythread");
	if (IS_ERR(thread_st)) {
		printk(KERN_ERR "Thread creation failed\n");
		err = PTR_ERR(thread_st);
		thread_st = NULL;
		return err;
	}
	/*in the kernel, each thread has it's own ID, called a PID (although it would possibly make more sense to call this a TID, or thread ID) 
	  and they also have a TGID (thread group ID) which is the PID of the thread that started the whole process.*/
	//pid_t tid = current->pid;
	pid_t tid = thread_st->pid;
	printk(KERN_INFO "Thread Created successfully : %d\n", (int)tid);
	return 0;
}

// Module Exit
static void __exit cleanup_thread(void)
{
	printk(KERN_INFO "Cleaning Up\n");
	if (thread_st) {
		kthread_stop(thread_st);
		printk(KERN_INFO "Thread stopped");
	}
}

MODULE_LICENSE("GPL");
module_init(init_thread);
module_exit(cleanup_thread);
