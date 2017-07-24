ls -al /proc/sys/kernel/

cat /proc/sys/net/core

ps -e -T | grep <application name or pid>
    -e shows all processes
    -T lists all threads
    | pipes the output to the next command
    grep this filters the contents

top -H -p <pid>

http://www.8bitavenue.com/2015/07/difference-between-user-level-threads-and-kernel-level-threads/:
http://www.cs.iit.edu/~cs561/cs450/ChilkuriDineshThreads/dinesh's%20files/User%20and%20Kernel%20Level%20Threads.html
https://www.quora.com/What-is-the-difference-between-user-level-and-kernel-level-threads
https://courses.cs.washington.edu/courses/cse451/11au/section/kim_au_section4.pdf

What is the difference between kernel threads and user threads? 
Is it that kernel thread are scheduled and executed in kernel mode? 
What are techniques used for creating kernel threads?
Is it that user thread is scheduled, executed in user mode? 
Is it that Kernel does not participate in executing/scheduling user threads? 
When interrupts occur in executing user thread then who handles it?
Whenever, thread is created a TCB is created for each. now in case of user level threads Is it that this TCB is created in user's address space ?
In case of switching between two user level threads who handles the context switching ?

There is a concept of multithreading models :
    Many to one
    One to one
    Many to Many.
What are these models? How are these models practically used? 

I heard that, on Linux/Unix, kernel threads(such as those of system calls) get executed faster than user threads.

Kernel threads are used for "background" tasks internal to the kernel, such as handling interrupts and flushing data to disk. 
	The bulk of system calls are processed by the kernel within the context of the process that called them.
Kernel threads are scheduled more or less the same way as user processes. Some kernel threads have higher than default priority (up to realtime priority in some cases), 
	but saying that they are "executed faster" is misleading.
    
Is it true that on a single processor box, when user thread is running, kernel will be suspended?
	Of course. Only one process can be running at a time on a single CPU core.
	
	That being said, there are a number of situations where the kernel can interrupt a running task and switch to another one (which may be a kernel thread):
    When the timer interrupt fires. By default, this occurs 100 times every second.
    When the task makes a blocking system call (such as select() or read()).
    When a CPU exception occurs in the task (e.g, a memory access fault).

https://sysplay.in/blog/tag/kernel-threads/
by default, kernel thread ignores all the signals. So, how do we send the signal to the kernel thread, if at all it’s required in some scenarios? 
Note : void allow_signal(int sig_num), int signal_pending(task_struct *p);

https://www.quora.com/What-is-the-difference-between-user-level-and-kernel-level-threads

process vs kernel_thread vs user thread

Process:
The OS maintains a special table called process control block (PCB) to keep track of process state. 
PCB table contains various information about the process, however for the sake of discussion, just keep in mind two items: program counter (PC) and CPU registers. 
Program counter points to the next instruction to execute and CPU registers hold temporary execution information such as instruction arguments.
Process = [Code + Data + Heap + Stack + PC + PCB + CPU Registers] .

Thread :
A thread has a private stack, program counter (PC) and a set of CPU registers, a small control block. 
Think of it as a lightweight process because it shares code, data, heap and open files with the parent process.
Thread = [Parent Code, Data and Heap + Stack, PC and CPU Registers] .

context switching:
In a single processor system, there is no real multitasking. CPU time is shared among running processes. When the time slice for a running process expires,
a new process has to be loaded for execution. Switching from one process or thread to another is called context switch. 
Process context switch involves saving and restoring process state information including program counter, CPU registers 
and process control block which is a relatively expensive (in terms of CPU time) operation. Similarly, thread context switch involves pushing all thread CPU registers 
and program counter to the thread private stack and saving the stack pointer. Thread context switch compared to process context switch is relatively cheap 
and fast as it only involves saving and restoring CPU registers

Thread Management :
We have learned what a process, thread and context switch mean. How is this related to the definition of user and kernel level threads ? Let us see how.

    A thread is a sequence of instructions.
    CPU can handle one instruction at a time.
    To switch between instructions on parallel threads, execution state need to be saved.
    Execution state in its simplest form is a program counter and CPU registers.
    Program counter tells us what instruction to execute next.
    CPU registers hold execution arguments for example addition operands.
    This alternation between threads requires management.
    Management includes saving state, restoring state, deciding what thread to pick next and why?

Thread management decides thread type. User level threads are managed by a user level library and kernel level threads are managed by the operating system kernel code.

Kernel threads:
	Kernel level threads are managed by the OS.
	Because kernel has full knowledge of all threads, Scheduler may decide to give more time to a process having large number of threads than process having small number of threads.
	they can also utilize multiprocessor systems by splitting threads on different processors or cores.
	They are slower than user level threads due to the management overhead.
	heavy CPU per context switch ie. Kernel level context switch involves more steps than just saving some registers.
	they are not portable because the implementation is operating system dependent.
	Blocking I/O ie. They are a good choice for processes that block frequently.

	Note : in the kernel, each thread has it's own ID, called a PID (although it would possibly make more sense to call this a TID, or thread ID) 
		and they also have a TGID (thread group ID) which is the PID of the thread that started the whole process.

User threads:
	user level threads are managed by a user level library.
	Single processor or single kernel thread.
	Light CPU per context switch.
	They are a good choice for non blocking tasks.
	User level threads are typically fast.
	Creating threads, switching between threads and synchronizing threads only needs a procedure call.
	
	Note : in user space each process has its on pid and tgid. if we create any thread under that proccess it will get new pid but the same tgid as parrent have.

thread model:

Many-To-One Model :
User level threads (explained earlier) follow the many to one threading model. This means multiple threads managed by a library in user space 
but the kernel is only aware of a single thread of the process owning these threads. so If the currently running thread blocks for input then all other threads are blocked.

One-To-One Model:
kernel level threads (explained earlier) follow the one to one model. Process threads are managed by the kernel so there are separate kernel threads for each process thread. 
Since the kernel is aware of all threads, if one thread blocks it does not affect the others. Also, threads can run on different CPUs or cores. Finally, the management overhead is significant.

Many-To-Many Model:
It multiplexes many user level threads to many kernel threads. The goal is to get the benefits of the other models without the downsides, 
however there is no such free lunch in life so it comes with an implementation difficulty.

Context switching ?
“task_struct” this a PCB or TCB? => thread control block (TCB). 

Spinning vs Blocking ?
Spinning:
	 If the lock is not free, repeatedly try to acquire the lock.
Blocking:
	 If the lock is not free, add the thread to the lock's wait queue and context switch.

When to use which?
	 Spinning is good for small critical sections.
	 Also good on multiprocessors.
	 If the overhead of the context switch is less than the time spent waiting (spinning),
	 then blocking is preferable.
		– But remember the implicit overhead of context switching as well.
	Spin locks are good for fine-grained work like you might see in your OS.
	Blocking is good for coarse-grained work like protecting large data structures.

Procedure Call vs Function Call vs Library Call?
SoC vs Controller vs CPU?
memmory mapped IO ?
How to call exported kernel module functions from another module?
difference between API (Application Programming Interface) and system call?
what is the size of pid_t, uid_t, and gid_t?

What is Monolithic Kernel?
monolithic kernel operating system as a single large static binary file process running entirely in a single address space. 
Basic OS services such as process management, memory management, interrupt handling, IO communication, file system, device drivers, networking, etc all run in kernel space. 
Entire services are loaded on boot up and reside in memory and work is done using system calls. Linux is a good monolithic kernel example.
Generally speaking a monolithic operating system kernel is faster due to small source and compiled code size. Less code means also less bugs and security issues.

Microkernel ?

The idea behind microkernel OS is to reduce the kernel to only basic process communication and IO control and let other system services run in user space just like any other normal processes. 
These services are called servers and kept separate and run in different address spaces. Contrary to monolithic OS where services are directly invoked, 
communication in a microkernel is done via message passing (inter process communication IPC).  Mac OS and WinNT are two examples on microkernel OS architecture.

