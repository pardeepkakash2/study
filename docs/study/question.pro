Operating System Interview Questions :

Kernel Synchronization :
1. What are the differences between mutex and semaphore?
2. What is a race condition and How to avoid a race conditon?
3. What is a critial region?
4. What are atomic operations?

RTOS:
1. What are the differences between general purpose OS and and RTOS?
2. What are the characteristics of an RTOS?
3. What is the difference between a hard real time system and a soft real time system?
4. What is priority inversion and how to solve that problem?
5. What is priority inheritence?

Process management:
1. how to manipulate the current process
2. what are kernel thread.
3. how threads are implemented in linux kernel.
4. What are different state of a process in lunix.
5. what is difference between process and thread.
6. generally what resources are shared between threads.
7. what is process descriptor
8. what is task_struct.
9. what is therad_info structure for.
10. what was the need of thread_info structure.
11. difference betwen fork() and vfork()
12. what is process context.
13. what is zombie process.
14. how parent less process is handles in linux.

Process Scheduling
1. what is process scheduling
2. what is cooperative multitasking and pre-emptive multitasking.
3. what is yielding.
4. what is limitation of cooperative multitasking.
5. I/O bound versus Processor bound process.
6. what is process priority.
7. What kind of priority is maintained in linux.
8. what is nice value.
9. what is virtual run time.
10. what are the available scheduling classes in linux.
11. which type os scheduling used in linux.
12. how next task is picked for scheduling.
13. what is scheduler entry point in linux.
14. what is waitqueus.
15. How context switching is handled in linux.
16. what is user preemption and kernel preemption

Syscalls:
1. what is syscalls.
2. how system calls are implemented in linux.
3. what happens when process in userspace calls a syscall.
4. what is the need of verifying parameter in definition of syscall.
5. what is system calls context.
6. why it is not recommended to writing new syscall.
 
Interrupts and interrupt handlers
1. what is interrupt and Types of interrupts e.g Software interrupts, Hardware interrupts, Edge Triggering and Level triggering ?
2. what is interrupt handler or ISR.
3. what is top halves and bottom halves.
4. How interrupt is registered.
5. what are different interrupt handler flags.
6. How interrupt are freed.
7. what are the considerations needs to taken care while writing interrupt handler.
8. what are shared handlers.
9. what is interrupt context.
10. how to disable and enable interrupts.
11. what are different bottom halves techniques in linux.
12. what is tasklets , softirq and workqueus and difference among them.
13. when to choose which bottom halves.
14. how to implements softirq , tasklets and workqueus.
15. how to schedule tasklet.
16. what is ksoftirqd.
17. How to disable bottom halves.
18. How locking between bottom halves handled.
19. Why we need preemption.
20. Explain about the interrupt mechanims in linux?
21. What are the APIs that are used to register an interrupt handler?
22. How do you register an interrupt handler on a shared IRQ line?
23. Explain about the flags that are passed to request_irq().
24. Explain about the internals of Interrupt handling in case of Linux running on ARM.
25. What are the precautions to be taken while writing an interrupt handler?
26. What is request_threaded_irq()
27. If same interrupts occurs in two cpu how are they handled?
28. How to synchronize data between 'two interrupts' and 'interrupts and process'.
29. How are nested interrupts handled?
30. How is task context saved during interrupt.
31. How to disable and enable interrupts ?
32. What are the different bottom-half mechanisms in Linux? Softirq, Tasklet and Workqueues and When to choose which bottom halves ? 
33. Explain about the concurrent work queues.
34. How to schedule tasklet or bottom half ?
35. How to disable bottom halves ?
36. What is ksoftirqd ?
37. How locking between bottom halves handled ?
38. diff b/w interrupt, signal,isr and callback ?
40 What happens if interrupt handler goes to sleep?
41. What happens if interrupt handler uses semaphores
41. How to protect variable between two interrupt handlers?
42. How to protect variable between task and interrupt handler?
43. What is the difference between interruptible and uninterruptible task states?
How to debug GPIO interrupt functions?
Timer interrrupts vs Dummy loops ?
How does MSI interrupt work in linux driver?
Which processor an interrupt will be generated on?
ARM interrupt service procedure vs function call procedure
Retrieving pid of tasklet
How do I write to a __user memory from within the top half of an interrupt handler?
Why can interrupt handler has sleep functionality?
Are the Interrupt Stack and the Kernel Stack the same stack?

Why interrupt handler cannot use user stack ?
What is a user thread and a kernel thread?
Number of kernel threads = cores?
Maximum number of threads per process in Linux?
cat /proc/sys/kernel/threads-max
There is also a limit on the number of processes (an hence threads) that a single user may create, see ulimit/getrlimit
Linux implements max number of threads per process indirectly!!
number of threads = total virtual memory / (stack size*1024*1024)
ulimit -s

Kernel Synchronization:
1. what is synchronization and various synchronization techniques in linux and Why do we need synchronization mechanisms in Linux kernel?
2. what is critical section
3. what is race condition and deadlock and hung task.
4. why we need to take care of synchronization
5. What are the differences between spinlock and mutex?
6. what is deadlocks.
7. what is atomic operations.
8. what is spin locks.
9. what is reader-writer spin lock.
10. what is semaphore.
11. what is binary semaphore.
12. what is difference between semaphore and spin lock.
13. when to choose what among spin lock and semaphore.
14. what is difference between semaphore and mutex.
15. what is preemption disabling and what is the use of this.
16. What is lockdep?
17. Which synchronization mechanism is safe to use in interrupt context and why?
18. Explain about the implementation of spinlock in case of ARM architecture.
19. Explain about the implementation of mutex in case of ARM architecture.
20. Explain about the notifier chains.
21. Explain about RCU locks and when are they used?
22. Explain about RW spinlocks locks and when are they used?
23. Which are the synchronization technoques you use 'between processes', 'between processe and interrupt' and 'between interrupts'; why and how ?

Process Management and Process Scheduling:
1. What are the different schedulers class present in the linux kernel?
2. How to create a new process?
3. What is the difference between fork( ) and vfork( ) and execv?
4. Which is the first task what is spawned in linux kernel?
5. What are the processes with PID 0 and PID 1? PID 0 - idle task and PID 1 - init .
6. How to extract task_struct of a particular process if the stack pointer is given?
7. How does scheduler picks particular task?
8. How is timeout managed?
9. How does load balancing happens?

Timers and Time Management:
1. what is tick rate and jiffies and HZ.
2. what are the various way of applying delay in linux.
3. what is blocking and non blocking call
4. what is Real time clock (RTC).
5. how busy looping is implemented in linux.
6. What is the initial value of jiffies when the system has started? and how to check it ?
7. Explain about HR timers and normal timers?
8. On what hardware timers, does the HR timers are based on?
9. How to declare that a specific hardware timers is used for kernel periodic timer interrupt used by the scheduler?
10. How software timers are implemented?

Memory management:
1. how memory is managed in linux.
2. what are pages.
3. what are different memory zones in linux.
4. how to allocated pages.
5. how to freeing page.
6. what us kmalloc and what are action modifier we can pass while using kmalloc.
7. what is zone modifier in linux.
8. what is vmalloc
9. What are the differences between malloc,zmalloc, vmalloc and kmalloc? Which is preferred to use in device drivers?
10. What are the differences between slab allocator and slub allocator?
11. What is boot memory allocator?
12. How do you reserve block of memory?
13. What is virtual memory and what are the advanatages of using virtual memory?
14. What's paging and swapping?
15. Is it better to enable swapping in embedded systems? and why?
16. What is the page size in Linux kernel in case of 32-bit ARM architecture?
17. What is page frame?
18. What are the different memory zones and why does different zones exist?
19. What is high memory and when is it needed?
20 Why is high memory zone not needed in case of 64-bit machine?
21. How to allocate a page frame from high memory?
22. In ARM, an abort exception if generated, if the page table doesn't contain a virtual to physical map for a particular page. How exactly does the MMU know that a virtual to physical map is present in the pagetable or not?

Virtual file system: 
1. what is virtual file system and what is the need of it in linux.
2. are are different object types in VFS.
3. what are the operations possible on inode and superblock objects.

1. What is the need for Virtual Memory ?
2. What is the difference between the term 'Virtual Memory' and 'Virtual Address Space' ?
3. Can an user space application view the physical address Or Can an user space application access the physical address space ?
4. Is it possible for two different application to have a same virtual address but point to different physical memory ?
5. What are the functionalities performed by _start ?
6. What is the difference between Code section, Data section, ro Data section & BSS section ?
7. What is the expansion of BSS and What is the need for BSS ?
8. What is the size of the Kernel space and that of User space ? Who decides the size of it . Is it dependent/done by Processor or MMU ?
9. Tell one of the etry point to kernel ?
10. Explain the system call mechanism such that the flow is from User space to Kernel space & returning back to User space ?
11. What is the use of SYSENTER ? Does it get executed in Userspace ?
12. What is the use of SYSEXIT ? Does it get executed in Kernelspace ?
13. What is the role of __sys_open ?
14. What is the use of ABI (Application Binary Interface) document ? Who provides that manual ?
15. How do you see the size of an executable file in Linux ?
16. What is the probable size of normal vmlinux ? What kind of sizes have you come across in normal linux and embedded linux scenarios ?
17. What is vmlinux.lds ?
18. Why do you find all addresses to start after '0xC0000000' if you do 'readelf -a vmlinux' ? Can you access those addresses ?
19. What is a FDT (File Descriptor Table) ?
20. Explain the relation between File Descriptor table, Symbol File table, iNode table and harddrive/phy memory ?
21. What command is used to setup/create the relation between the device and inode ?
22. What command/API is used to create an inode for a file ?
23. What is the use of 'file_operations' ? How have you used it ?
24. What is the use of /proc/PID/maps ?
25. What is task_struct ?
26. Explain the relation between file struct,File Descriptor Table(FDT), task_struct, MM_struct, vm_area_struct, Heap, Page Global Directory(PGD), Page table(PT) & user page .
27. What is the use of ioctl fuction ?
28. Explain one level page table address translation between VA and PA with an example ?
29. Explain multi level page table address translation between VA and PA with an example ?
30. Is it better to have less level of page table address translation or more levels of page table address translation ? What is the impact on performance w.r.t memory size and memory access ?
31. What is the difference between malloc and vmalloc ?
32. What is PAE (Physical Address Extension) ?
33. What is Dual Mapping ? Can a user virtual address and kernel virtual address map to the same physical address ?


Process Address Space:
1. what is process address space.
2. what is memory descriptor in linux and which structure represents it.
3. how to allocate and destroy a memory descriptor
4. does kernel thread has any association with mm_struct.
5. what is VMA and what are various VMA operations possible in linux kernel.
6. how to manipulate memory area in linux.
7. what mmap and do_mmap().
8. what is page tables.
 
Linux Device Driver :
1. What is device driver and what is the need of it.
2. what are different kind of devices.
3. what is module in linux.
4. how mudules are loaded in linux.
5. difference between insmod and modprobe.
6. how parameters are shared between driver modules.
7. what are IOCTLS.
8. what is syscalls.
9. what are the benefits of syscalls.
10. how character driver is registered in linux.
11. what is init and exit function of a driver.
12. how and when init and exit function of driver get called.
13. what is probe function.
14. when probe is get called.
15. what is platform devices.
16. what is device tree.
17. what are the benefits of device tree over board files.
18. what is sysfs and procfs.
19. how logs are printed in linux kernel and what are the logs level available in linux.
20. what is copy_to_user and copy_from_user.
21. what do you mean by kernel configuration and what are the various way of configuring kernel.
22. what is menuconfig.
23. what is ioremap
24. what is seagmentation fault.
25. what are the various ways od debugging linux kernel.
26. how linux kernel boots.
27. what is zimage and bzimage.
28. what are different booting arguments in linux.
29. how parameter are passed from boot loader to kernel.
30. what is ATAGS.
31. from which file kernel execution starts.
32. what is bootloader.
33. what is primary and secondary bootloader.
34. why we need two bootloader.
35. difference between poll and select.
36. what is priority inheritance and priority inversion.
37. what are different type of kernel.
38. what is DMA.
39. what is cache coherency.
40. what is copy on write.
41. what is highmem and lowmem.
42. what happens if we pass invalid address from userspace by using ioctls.
43. what are different ipc mechanism in linux.
44. what are sockets.
45. how page fault is handled in linux.
46. difference between memory based io and port based io.
47. what is I2c and SPI.
48. how physical to virtual translations works in linux.
49. what is thrashing, segmentation and fragmentation.
50. what is preempt_count and what is the need of that.
51. What is mknod and it's usage ?
52. In how many ways we can allocate device number ?
53. How can we allocate device number statically and dynamically and how to free device number?

Linux Kernel Modules:
1. Explain about the Linux Device Model (LDM)?
2. Explain about about ksets, kobjects and ktypes. How are they related?
3. How to make a module as loadable module?
4. How to make a module as in-built module?
5. Explain about Kconfig build system?
6. Explain about the init call mechanism.
7. What is the difference between early init and late init?
8. What is process kernel stack and process user stack? What is the size of each and how are they allocated?
9. Why do we need seperate kernel stack for each process?
10. What all happens during context switch?
11. What is thread_info? Why is it stored at the end of kernel stack?
12. What is the use of preempt_count variable?
13. What is the difference between interruptible and uninterruptible task states?
14. How processes and threads are created? (from user level till kernel level)
15. How is virtual run time (vruntime) calculated?
16. Difference between uart_register_driver and platform_driver_register?
17. How to do a single dma transaction in kernel?
18. Translating virtual address to physical address in kernel space?
19. Can we have same major number for more than one device file ?
20. What is minor  number and it's usage ?
21. What is range of major and minor numbers?
22. How to retrieve major and minor number from dev_t type ?
23. How can i use my own major and minor number for a device file ?
24. How to see  statically assigned major numbers ?
25. how interrupt id and ISR is mapped?
26. How to pin a interrupt to a CPU in driver
27. How many maximum different CPU-Cores can be used to processing of one IP-packet?
28. What are the different modes in ARM.
29. What is the difference between IRQ & FIQ.
30. how the synchronisation works in single processor system(spinlock_irq_save).
31. how external devices access the physical address.
32. what is basic difference in insmod & modprobe.
33. What is the difference between Platform driver and normal device driver..?
34. What happens to the idle thread when a core is taken offline logically?
35. What is meant by system call?
36. What is the difference between programs and Kernel Modules?
37. What is the difference between user space and kernel space?
38. What is the importance of  /proc and /sys File system ? 
39. What is the difference between printf() and printk() ?
40. How a user mode is transferred to kernel mode?
41. How system call causes change from user to kernel space
42. Which RTOS worked on. Difference between various OS/RTOS
43. Measure of performance of OS. Define performance
44. What are the various code optimization techniques used
45. memory leak deduction and various ways of handling
46. How to proceed if system is sluggish
47. How to determine if some high prio task is hogging CPU
48. Important things to look for in code reviews
49. Understanding of schematics
50. Why driver code in not written in C++/Java
51. How to debug while system is running
52. Run Time optimization
53. what is repeate sequence in I2C?
54. How this signal will look on CRO?
55. How many lines required for SPI communication?
56. Do you need to change Clock polarity and phase for SPI?
57. Who has control of SPI clock?
58. Explain board bring up.
59. how will you verify I2C communication?How will you know if there was a software or hw problem?
60. How will you know if the I2C lines are noisy?
61. Have you worked in crash dump?
62. How will you solve memory crash, what steps would you take if a crash occurs?
63. Data sharing between ISR and threads?
64. what is NAND and NOR flash, diff between them?
65. What monitoring tools have you used like I2C sniffer
66. who schedules the scheduler
67. what is cache coherence?
68. Can a scheduler can be locked?
69. At what frequency scheduler looks for threads/processes ready for schedule?
70. what actually does a system does in a tick?
71. When cahche is enabled in a operating system ,DMA is enabled,how does DMA access the cache?
72. Diff btwn SPI & I2C
73. When a signal is raised on a interrupt line what will be passed to processor either interrupt number or anything else?
74. How kernel comes to know which device raised an interrupt when  interrupt  is shared.
75. How can an application can talk to specific device in this below case ?
      having Hard Disk devices
        SATA,SATA1,SATA2
76. if their a devce driver registered for these devices and a single drivere is used to manage thesr devies then how can an application talk to a sepcific device
Ex: if i want to read from SATA1 hard disk and Write to SATA0 and SATA1  hard disk.
How do you establish a sync mechanisam in above hard disk scenarios.
When a Mutex lock is aquired by a low priority task and High priority trys to acquires the lock
      will the low priority task will be pre emitted
The same above scenario is with sema and spinlock
77. How can two slaves can communicate with master in i2c protocol at a time?
78. How can we address different devices from same vendor i2c?
79. What is I2C protocol,I2C- dummy write,repeated start,arbitration,synchronization between masters
80. How to know whether a interrupt is an edge triggered or level triggered from registering an interrupt handler?
81. what is  i2c bus error
82. What are the different data transfer modes?
83. What are the different types of device descriptors?
84. How many END point descriptors can be present per device?
85. DO you know container macros? In all most all kernel drivers it is used?
86. What is the clock frequency used in your I2C driver designed?
87. What is the start bit condition in I2C?
88. How the master knows what is the start condition ?
89. while in between I2C communication what happens if clocks happends to be dragged low which is not as per i2c standard?
90. What if the slave device is not responding or no acknowledge bit is sent by slave device?
91. how to get physically contiguousness memory allocation if kmalloc is giving logical contiguousness allocations?
92. what is the entry points in kernel?
93. How to write a makefile to build a customized kernel
94. How to debug crash, what is the first line you see when you see a crash/oops message, explain crash console
95. How do you build only a static (.a) library for kernel modules.
96. Kernel thread vs user space thread and kernel process vs user space process and What was the need of thread_info structure?
97. Thread switching and process switching in linux kernel ?
98. How context switching is handled in linux?
99 zombiee and orphon process and How parent less process is handles in linux ?
100. What is page fualt and how it is handled in linux kernel?
101. What is local static and global static with example? 
102. Device tree  vs board file?
103. what is ioctl and What happens if you pass a invalid user space address in an ioctl?
104. Tell me any issue in which you debugged and found that there is some issue in hardware?
105. pull up / pull down register?
106. Maximum size you can allocate using kmalloc?
107. What message you will get if memory is not availeble?
108. What kind of priority is maintained in linux ?
109. What is user preemption and kernel preemptio
110. Why is interrupt disabled between spin_lock and spin_unlock in Linux?
111. sleep-free kernel functions ?
112. What is the exact definition of 'process preemption'?
113. nested interrupt is allowed in linux, but the size of interrupt stack is limited,is there any chance that too many nested interrupts cause stack overflow which crashes the whole system!
114. how it differs from user thread ?.
what is the relationship between the two threads ?.
how can i implement kernel threads ?.
Why must all user threads be mapped to a kernel thread?
What kind of hardware do the newer kernels support?
How do I identify which interrupt line shown in /proc/interrupts list is shared?
How does the Linux kernel handle shared IRQs?
What is the relationship between fork() and pthread_atfork() in Linux?
What is the relationship between System Call and Software Interrupt in Linux?
How does the fork() system call in Linux work?
user/kernel interface (system calls, procfs/sysfs, ioctl) :
synchronization between contexts (how would you synchronize access to a shared memory area used from an interrupt handler and a workqueue on a SMP preemptive kernel).
are you familiar with the Linux kernel development process? Do you have any patch accepted in the mainline?
What are good ways to debug memory corruption in C under Linux?
How do I debug a kernel module in which a NULL pointer appears?
How to let kernel not run the printk with KERN_DEBUG
How do I include the device tree with my kernel?
How to attach file operations to sysfs attribute in platform driver?
How size of virtual memory is decided and calculated in Linux ?
How to remove packet from UDP read buffer in kernel?
How can I bind my own serial device with a driver?
How does Linux Kernel know where to look for driver firmware?
How to create a device in /dev automatically upon loading of the kernel module for a device driver?
sudo mknod -m 0666 /dev/msio c 22 0
How to use netlink socket to communicate with a kernel module?
How to implement a Linux Device Driver for Data Acquisition Hardware?
How to find owner socket of sk_buff in Linux kernel?
Why Socket Connection Blocked and TCP Kernel Keeps Retransmitting [ACK] packets


Linux Kernel Debugging
1. What is Oops and kernel panic and how to understand the panic stack?
2. Does all Oops result in kernel panic?
3. What are the tools that you have used for debugging the Linux kernel?
4. What are the log levels in printk?
4. Can printk's be used in interrupt context?
6. How to print a stack trace from a particular function?
7. What's the use of early_printk( )?
8. Explan about the various gdb commands and features of gdb ?

Power Management in Linux:
1. Explain about cpuidle framework.
2. Explain about cpufreq framework.
3. Explain about clock framework.
4. Explain about regulator framework.
5. Explain about suspened and resume framwork.
6. Explain about early suspend and late resume.
7. Explain about wakelocks.

Miscellaneous:
1. How are the atomic functions implemented in case of ARM architecture?
2. How is container_of( ) macro implemented? 
3. Explain about system call flow in case of ARM Linux.
4. What 's the use of __init and __exit macros?
5. How to ensure that init function of a partiuclar driver was called before our driver's init function is called (assume that both these drivers are 	 built into the kenrel image)?
6. What's a segementation fault and what are the scenarios in which segmentation fault is triggered?
7. If the scenarios which triggers the segmentation fault has occurred, how the kernel identifies it and what are the actions that the kernel takes?

Linux Boot Sequence:
1. Explain about the Linux boot sequence in case of ARM architecture?
2. How are the command line arguments passed to Linux kernel by the u-boot (bootloader)?
3. Explain about ATAGS?
4. Explain about command line arguments that are passed to linux kernel and how/where they are parsed in kernel code?
5. Explain about device tree.

Below is the interview questions asked in an interview in Vihaan Networks for the position of Embedded Engineer having  skills of Linux Device Driver , Linux Kernel Programming, Embedded C programming , BSP, RTOS , Linux Kernel Debugging , I2C, SPI , Bootloader etc.
1.	What is breakpoints?
2.	How software and hardware breakpoints are implemented?
3.	What is volatile constant ?
4.	What is the need of volatile constant in embedded systems?
5.	How you will analyze Linux Kernel   crash dumps ?
6.	How pagefault is handled in linux kernel?
7.	What is sempahore and mutex?
8.	What is the difference  in semaphore and Mutex?
9.	What is the difference  b/w spinlock and semaphore?
10.	When to use Semaphore and Mutex?
11.	What is the difference  between constant and macro?
12.	What is difference  between inline function and macro?
13.	Questions Related to i2c
14.	Question Related to DMA
15.	Tell about Process address space of a c program?
16.	Difference  between local static and global static? 
17.	How compiler maintain the scope of local static or global static variable?
18.	Why can't we go for sleep while handling interrupt?
19.	How nested interrupts are handled in ARM?
20.	Different modes in ARM ?
21.	What are the benefits using FIQ?
22.	Tell me the Linux kernel Booting sequence? 
23.	How you will find out the issues if your device is not booting?
24.	What is reset vector
25.	pull up and pull down register?
26.	Edge triggered and level triggered Interrupt?
27.	Maximum size you can allocate using kmalloc?
28.	What message you will get if memory is not available?
29.	What is the significance of spinlock on uniprocessor system?


I2C and SPI :
Hey dudes, the following interesting questions related to I2C and SPI protocol can be used for  discussion.

1. Can devices be added and removed while the system is running (Hot swapping) in I2C ?
2. What is the standard bus speed in I2C ?
3. How many devices can be connected in a standard I2C communication ?
4. What are the 2 roles of nodes in I2C communication ?
5. What are the modes of operation in I2C communication ?
6. What is bus arbitration ?
7. Advantages and limitations of I2C communication ?
8. How many wires are required for I2C communication ? What are the signals involved in I2C ?
9. What is START bit and STOP bit ?
10. How will the master indicate that it is either address / data ? How will it intimate to the slave that it is going to either read / write ?
11. Is it possible to have multiple masters in I2C ?
12. In write transaction, the Master monitors the last ACK and issues STOP condition - True/False ?
13. In read transaction, the master doesnot acknowledge the final byte it receives and issues STOP condition - True/False ?
14. What is SPI communication ?
15. How many wires are required for SPI communication ?
16. What are the 4 logic signals specified by SPI bus ?
17. Does SPI slave acknowledge the receipt of data ?
18. SPI has higher throughput than I2C - True / False ?
19. Is it better to use I2C or SPI for data communication between a microprocessor and DSP ?
20. Is it better to use I2C or SPI for data communication from ADC ?
21. Duplex communication is possible by simultaneously using MOSI and MISO during each SPI clock cycle - True / False ?
22. Is it possible to connect SPI slaves in daisy chain ?
23. What is the role of shift register in Master and Slave devices in SPI ?
24. How will the master convey that it is stopping the transmission of data ?
25. What is bit banging ?
What is the difference between RS232 and UART?
What makes SPI faster than I2C protocol ?
What is the difference between Synchronous and Asynchronous?
How many i2c slaves can a i2c master support?

Kernel :
1. How are FLIHs and SLIHs termed in Linux ?
2. What is the main drawback for not considering Linux as realtime ?
3. What is the type of scheduler used in Linux Kernel 2.5 ?
4. What are the types of scheduler used in Linux Kernel 2.6 to 2.6.23 and after Linux kernel 2.6.23 ?
5. CFS scheduler in Linux is based on red-black tree - True / False ?
6. O(1) scheduler in Linux is based on run queues - True / False ?
7. Is the architecture of linux kernel monolithic / microkernel ?
8. How will you trace the system calls made into the kernel of lInux ?
9. Tell about the Linux Kernel Compilation method ?
10. What is 'make mrproper' and how is it different from 'make clean' ?
11. What is Kmalloc and how does it differ from normal malloc ? or Why can't we use malloc in kernel code ?
12. Does the scheduler assign a zombie state to a process ?
13. Brief up 'vmalloc' vs 'kmalloc' ?
14. Brief up 'malloc' vs 'kmalloc' ?
15. How modules begin and end in LInux ? Tell the difference between Modules and Program ?
16. What is mmap ?
17. What are the advantages of mmap over read ?
18. Most of Unix kernels are monolithic - True / False ?
19. Why is microkernel slower than monolithic kernel ?
20. What are the advantges of microkernel over monolithic kernel ?
21. What is a 'Module' ?
22. What are the main advantages of using a 'Module' ?
23. Once linked in, the object code of a 'module' is equivalent to the object code of the statically linked kernel - True / False ?
24. What are the limitations of hard links / What are advantages of soft links ?
25. Unix Kernels are Reentrant - True / False ?
26. What is Kernel Control Path ?
27. What is the drawback in using semaphore for synchronization ? How does spinlock help in overcoming it ?
28. What does a semaphore consist of ? and What does a spinlock consist of ?
29. Why spinlocks are useless in uniprocessor systems ?
30. What are the two kinds of system events ?

Microprocessor
This is a collection of microprocessor(general) based questions that can be discussed.

1. What are the two famous architecture of CPU ?
2. What is the difference between Harvard and Von Neuman architecture ?
3. What is the use of instruction cache ?
4. Is it good to have more instruction cache or data cache ?
5. What is the use of data cache ?
6. What is the use of TLB ?
7. What do you mean by Cache Hit or Cache Miss ? What is cache hit rate ?
8. What is the difference between read miss and write miss ?
9. How does cache hit or cache miss determine the selection of processor ?
10. What is cache line or cache block ?
11. What is write-back or copy-back cache ?
12. What is the need for cache coherence protocol ?
13. What are the 3 kinds of cache misses ? or Which of the below causes the most delay and why ? Instruction read miss, Data read miss, and Data write miss .
14. What is boundary alignment and what is the use of it ?
15. What will happen if the data being fetched exceeds the cache line size ? or
if the data is not being aligned at the beginning of cache block ?
16. How can grouping of data can improve the cache based operations from application-side ?
17. What is cache prefetch ?
18. Brief up on pipelined versus Run-to-Completion processor software architecture ?
19. Why multicore processors are preferred to improve performance rather than trying to make a single processor based system faster ?
20. Does memory access speed varies at various stages ? Which is the fastest memory that you can directly deal with from a processor or Which type of memory of a CPU has almost zero percent latency ?
21. What is temporal locality and spatial locality ?
22. What are the applications of temporal locality and spatial locality ? or where are they applied in a CPU architecture ?
23. What is the use of Shadow Registers in ARM architecture ?
24. How will you calculate the idle time off a processor ?
25. How will you identify the endianness of a processor programatically ?
26. What is Memory Overlay ?
27. Tell about Bank Switching ?
28. What are the Disadvantages of Bank Switching ?
29. Why is the size of L1 cache smaller than that of the L2 cache in most of the processors ?
30. When should one use polling method and when should one use interrupt based method ? Are there scenarios in which both can be used ?
31. What could be the better way to determine the exact locations in which the prefetch instruction should be used ?
32. Considering that a processor runs at 100 MHz and the data is coming to the processor from an external device/peripheral at the rate of 1000 Mbit/s (8 Bits/Clockcycle @ 125 MHz), which is the best way to handle traffic that comes at a higher speed to the processor ?
33. Consider that there are 100 plus ways of interrupts occuring from various sensors. There are chances that all can occur at the same time too. How can the software be designed to handle it efficiently ?
34. What is Write-Back Cache ?
35. What is Write-Through Cache ?
36. What is cache coherency ?
37. What is Clock Cycles Per Instruction (CPI) ?
38. What is IPC(Instructions per cycle) ?
39. Tell about the 'nested interrupt handler' , 'reentrant interrupt handler' and ' prioritized direct interrupt handler' ?
40. What is Memory Banking ? Explain w.r.t 8051 architecture
41. What is Primary Memory and What is Secondary Memory ?
42. What is the advantage of MMU ?
43. How do you determine the direction of stack growth ?
44. What is the debugger that you have used ?
45. Have you used any emulator. If yes, how have you used it ?
46. Can you tell a scenario that was very difficult to solve / fix ?
47. Have you worked on optimization w.r.t memory usage ? What techniques have you followed to optimize ?
47. Have you worked on optimization w.r.t throughput / speed ? What techniques have you followed to optimize ?
48. What kind of co-processors have you used ?

Multicore processor
Initially multicore processors were used mainly in telecom industry. But, nowadays, these multicore processors have made inroads into almost every technology/industry. Here are a few basic multicore processor based questions that can be discussed upon..

1. Will increasing the number of cores, increase the throughput of your system ?
2. What are the general methods of communication between the cores ?
3. When is it better to use single core processor compared to multi-core processor ?
4. If the CPU in a multi-core processor updates the data in the cache, copies of data in caches associated with other cores will become stale. How is the multicore processor designed to handle this scenario ?
5. What is 'Run to Completion' software architecture ?
6. What is a 'Pipelined' software architecture ?
7. What is the difference between 'Run to Completion' and 'Pipelined' software architecture ?
8. How is the debugging and testing environment in the case of multithreaded/multiprocessing applications ?
9. At what point does adding more processors or computers to the computation pool slow things down instead of speeding them up?
10. Is there an optimal number of processors for any given parallel program?
11. How Many Processes or Threads are enough for an application ?

Operating System
Earlier, i listed few of the good and highly interesting RTOS queries for discussion. Here, i am listing general Operating System based interview questions that can be discussed upon.

1. What is an interrupt Vector ?
2. How CPUs find the ISR and distinguish between the various devices ?
Is it possible for two devices to share an interrupt request line but have different ISR for those two devices ?
3. What is page fault ?
4. Which hardware unit of processor detects the page fault ?
5. Difference between Monolithic kernel, Micro kernel and Hybrid kernel ?
6. What is Interrupt Descriptor Table (IDT) ?
7. Main Difference between a process and thread ?
8. Threads are lightweight. Why and How ?
9. STACK growth is in downward direction in the case of 80x86 processor - True/False.
10. What is the difference between Multiprogramming and Multiprocessing ?
11. What is parallel programming ?
12. What is a time slice ?
13. What is the difference between multiprogramming and multiprocessing ?
14. What is parallel programming ?
15. What is ABI (Application Binary Interface ) ?
16. What is the layout of a program image in main memory ?
17. What are the types of IPC mechanisms ?
18. Tell about shared memory ? Does it provide locking mechanism ? When is it typically used ?
19. What are the types of synchronization problems and what are the resources that can cause such problems ?
20. What is data race ?
21. What is Indefinite Postponement / Indefinite blocking or starvation ?
22. What is Deadlock ?
23. What are the synchronization relationships that are present in a multithreaded or mulitprogramming applications ?
24. How Many Processes or Threads Are Enough for an application ?
25. How does memory segmentation help in memory protection ?

 RTOS
RTOS has become very important as it is concerned with time critical events. Okay, let me list down few of the famous RTOS questions that can be discussed here.

1. What is priority inversion ?
2. What are the solutions for priority inversion ?
3. What is priority inheritance ?
4. What is priority ceiling ?
5. What is deadlock ?
6. What is the famous diners problem ?
7. What is mutex ?
8. What is spinlock ?
9. Where are spinlocks used ?
10. What do you mean by atomic operations ?
11. what is a semaphore ?
12. What are the types of semaphore ?
13. What is binary semaphore ?
14. What is a counting semaphore ?
15. What is message queue ?
16. What is the role of a scheduler ? How does it function ?
17. What is the difference between a normal OS and RTOS ?
18. What is preemption ?
19. What is preemptive multi-tasking/time-sharing ? What is its difference with co-operative multi-tasking/time-sharing ?
20. Threads are described as lightweight because switching between threads does not involve changing the memory context - True/False ?
21.What are the factors considered for a RTOS selection ?
22. What is the use of the method of temporarily masking / disabling interrupts ? When is it used ? What should be taken care while doing this method ?
23. Since, disabling/masking of interrupts can be done whent the critical section is ONLY SHORT,What method can be used if the critical section is longer than few source lines or if it involves few lengthy loopings ?
24. Difference between semaphores and disabling/masking of interrupts method ?
25. Binary semaphore is equivalent to Mutex - True/False. How ?
26. How can you avoid deadlocks incase of semaphore based designs ?
27. What is Message passing method ? What is its advantages ?
28. Tell about the design of Interrupt Handler and Scheduler in RTOS ?
29. What is interrupt latency ?
30. Even if we never enables interrupts in the code, the processor automatically disables them often during hardware access - True/False ? In this case how to reduce interrupt latency ?
31. When should we re-enable the interrupts in an ISR and why ?
32. How do you measure the latency of your system ?
33. What are First Level Interrupt handlers and Second level Interrupt handlers ?
34. What could be the typical design/implementation of FLIH and SLIH ?
35. Reentrant interrupt handlers might cause a stack overflow from multiple preemptions by the same interrupt vector - True / False ?
36. What kind of memory allocation procedure is good for embedded systems ?
37. Is there any RTOS that has non-preemptive scheduling ?
38. What is reentrant code ?
39. What is preemptive multitasking ?
40. What does timeslice refer to ?
41. If the time slice is too short then the scheduler will consume too much of processing time - True / False
42. What is I/O bound ? What is CPU bound ?
43. What is non-preemptive multitasking ?
44. CFS uses 'nanosecond' granularity accounting, the atomic units by which individual process share the CPU instead of previous notion of 'timeslice' - True/False .
45. When will you use binary semaphore ?
46. When will you choose busy-wait instead of context switch ?
47. What are the possible scenarios in which context switching of threads can occur ?
48. Can you use mutex/semaphore inside an ISR ?
49. Explain a scenari that could cause deadlock ? What is the best solution for a deadlock ?
50. Will the performance of your application improve if it has only a single thread and it is running on multiple cores of a processor ?
51. What will happen if there are more threads requesting for CPU resource such as time ?
52. What is Gang Scheduling and how is it useful ?
53. Can you sleep in interrupt handler ?
54. What is the main drawback for not considering Linux as realtime / RTOS ?
55. What is the drawback in using semaphore for synchronization ? How does spinlock help in overcoming it ?
56. What does a semaphore consist of ? and What does a spinlock consist of ?
57. Why spinlocks are useless in uniprocessor systems ?
58. What is timeslice ?
59. What is the difference between multiprogramming and multiprocessing ?
60. What is parallel programming ?
61. What are the types of IPC mechanisms ?
62. What are the types of synchronization problems and what are the resources that can cause such problems ?
63. What is data race ?
64. What is Indefinite Postponement / Indefinite blocking or starvation ?
65. What are the synchronization relationships that are present in a multithreaded or mulitprogramming applications ?
66. How Many Processes or Threads Are Enough for an application ?
67. Tell the advantages and disadvantages of Co-operative multitasking.
67. When should we use mutex and when should we use semaphore ?

 Boot loader
Here are boot loader related questions that are of great interest and that can be used for our discussions.... Check it out !

1. What are the various boot loaders that you have worked on ?
2. Where is the boot loader present in an embedded system design ?
3. In general, what does the boot loader do ?
4. What is the role of boot loader in embedded systems ?
5. How will you handle a scenario in which the boot software is erased/corrupted ?
6. How will you handle boot software erasure/corruption scenario if Boot ROM is not available ?
7. What do you mean by bootstrap loader and what does it do ?
8. Is booting different from bootstrapping ?
9. When the computer is powered ON, it does not have OS it in neither ROM nor RAM - True/False ?
10. What is a second-stage boot loader ?
11. Do LILO/GRUB/Syslinux belong to either first stage boot loader(small program) or second-stage boot loaders ?
12. What is network booting ?
13. What is Chain loading or Multi-stage boot loader ?
14. Can you brief up the boot sequence of a normal desktop computer ?
15. Tell about OMAP CPU booting ?
16. What are the most common boot modes of DSP processor ?
17. Give few examples for systems that use Host Port(HPI Boot) for DSP booting ?
18. How will you put U-Boot into the target board ?
19. TFTP is a stripped down version of FTP that does not require authentication - True/False ?
20. Why do you need 2 stage boot process in OMAP processor ?
21. Can you give a highlevel view of Linux Boot process ?
22. What is the role of MBR and its relation with BIOS ?
23. Where is the MBR located ?
24. What is the structure of MBR ?
25. The secondary, or second-stage, boot loader could be more aptly called the kernel loader - True / False
26. What is the relation between GRUB and filesystem while booting ? or Main Difference between LILO and GRUB ?
27. What is the difference between zImage and bzImage ?
28. What is the role of initrd/Initial RAM disk ?
29. What is the role of initrd/Initial RAM disk in Embedded systems ?
30. Can you tell about the major function-level flow for Linux i386 booting ?
31. Does GRUB involve a 3-stage boot loading ? If yes, what are they . Brief it ?

 Networking & Telecom - I
Hey guys, few questions that can keep us discussing for sometime...

1. What is network throughput ?
2. What is bandwidth ?
3. In which layer is network throughput normally measured ?
4. What is Bandwidth-delay product ?
5. What is goodput ?
6. What is maximum bandwidth for a TCP based communication ?
7. What is MTU ?
8. What is MSS ?
9. What is Path MTU discovery ?
10. Which layer of OSI model does fragmentation based on MTU ?
11. What is a LFN (Long Fat Network) ?
12. What is Jumbo Frames ?
13. What is difference between Fast ethernet n/w i/f card and Gigabit ethernet n/w i/f card ?
14. What is the difference between outb and outportb APIs ?
15. What is the need for retransmission mechanism ?
16. What is the need for retransmission mechanism at various layers ?
17. What is socket communication ?
18. What is the use of the following APIs - socket, bind, listen, connect, accept, send, poll, receive ?
19. Have you used 'select' API ?
20. What are the types of sockets ? What is the difference between the following - datagram sockets, stream sockets and raw sockets ?
21. Provide a brief description about TCP Connection Establishment / 3 way handshake method of TCP connection establishment.
22. What is the data structure used in TCP communication ?
23. Tell about TCP and UDP wrt Transport Layer of OSI model ?
24. Why is MTU size 576 bytes ?
25. Explain the communication between DCE(Modem) and DTE(PC) ?
26. What happens as soon as a packet arrives from the network in Linux ?
27. Why is the design of TCP servers mostly such that whenever it accepts a connection, a new process is invoked to handle it . But, why in the case of UDP servers, mostly there is only a single process that handles all client requests ?
28. Why does the client end of a connection use high port number(ephemeral ports) whereas the applications listen on typically small port numbers ?
29. When should you use UDP and When should you use TCP ? Also, give some realtime examples of applications that use TCP or UDP .
30. Difference between TCP and UDP ?
What is the difference between symbol rate and bit rate ?
31. What is BER (Bit error Rate / Bit Error Ratio)?
32. What is Spatial Multiplexing ?
33. What are the advantages of OFDM ?
34. In practice, OFDM signals are generated and detected using the FFT algorithm - True/False
35. What parameters can be changed for OFDM systems / Why should we not change Frequency ?
36. What is a Symbol in OFDM ?
37. What is the purpose of guard bands in OFDM ?
38. What do you mean by Tones in OFDM ?
39. Tell the 2 important tasks to be performed on the Receiver end of OFDM system ?
40. What is Turbo Codes ?
41. What are the advantages of Turbo Coding ?
42. What is Hybrid-ARQ ?
43. What is Frequency Reuse ?
44. What is Delay Spread ?
45. What is Call Processing ?
46. What is Reed-Solomon Error Correction ?
47. What is Reed-Solomon code and its areas of Uses ?
48. What is Shannon and its relation with Channel Capacity ?
49. What is "Channel Access Method" ?
50. What is FHSS - "Frequency-hopping spread spectrum" ?
51. What is TDM ?
52. Applications of TDM ?
53. What is TDMA ?
54. What are the features of TDMA ?
55. Tell few Systems that use TDMA ?
56. Tell about TDMA in 2G and 3G ?
57. Tell about CDMA vs TDMA ?
58. What is TDD ?
59. Examples of TDD systems ?
60. What is FDM ?
61. Applications of FDM ?
62. What is FDMA ?
63. What are the features of FDMA ?
64. What is FDD ?
65. Explain CDMA / IS-95 ?
66. What is spread spectrum and its use ?
67. What is the difference between UMTS and WCDMA ?
68. What does LAC stand for in CDMA ?
69. What is RLP and What is RLC ?
70. What are the basic ways to design the channel code and protocol for an error correcting system ?
71. What is convolutional code ?
72. What is the technology behind Mobile WiMAX ?
73. What is the technology behind LTE ?

 Flash Memory
The below set of queries can be used for discussion on Flash Memory.

1. Why is serial flash memory preferred in embedded systems ?
2. Flash Memory is costlier than byte programmable EEPROM - True / False ?
3. MiniSD, MemoryStick are of NAND flash memory type - True / False ?
4. Flash memory's read access time is less than that of DRAM memory 's read access time - True / False ?
5. Flash memory has infinite number of erase-write cycles - True / False ?
6. NOR flash memory's usage is for random access read - True / False ?
7. NOR flash memory is preferred for XIP - True / False ?
8. NOR flash memory is more expensive than NAND flash memory - True/False ?
9. NAND flash memory's usage is for replacing the HDD and also to save space - True/False ?
10. NAND requires copying of memory contents into memory mapped RAM - True / False ?
11. A completely erased flash memory will have all corresponding bits set to 1 - True / False ?
12. Flash memory erases in both NOR and NAND flash memory is block basis - True / False ?
13. NAND flash memroy is not suitable for micrprocessor/microcontroller ROM - True / False ?
14. NOR memory is suitable for BIOS as it gives random access read/program - True/False ?
15. Why is NAND flash memory not suitable for ROM/Program memory of Microprocessor/Microcontroller ?
16. Erasure time of NOR flash memory is more than that of NAND flash memory - True/False ?
17. Write time of NOR flash memory is more than that of NAND flash memory - True/False ?
18. Why is blockwise erasure faster than that of bytewise erasure ?
19. Flash memory is a specific type of EEPROM - True / False ?
20. NAND flash memory is used for filesystems - True / False ? Why ?
21. In general, Flash Memory erase operation is slower than program operation . And the program operation is slower than read operation - True / False ?
22. In general, SPI interface is used by serial flash memory - True / False ?
23. What are the main areas of application of serial flash in embedded systems ?
24. NAND flash memory has greater storage density and lower cost per bit than NOR flash - True / False ?
25. What is XIP ? Where is it useful ?
26. What are the common Flash Memory problems ?
27. How will you test a Flash Memory ? Have you written any power on self test ?
How will you perform the following test procedures for flash memory -
a. Address bus test
b. Data bus test
c. Control signal test
d. Missing memory device test
28. Is writing to a flash memory straightforward ? How will you set/clear a particular bit of flash memory ?
29. How do you expand program memory space using Bank Switching/Code Banking ? Consider for 8051.
30. What are the disadvantages of Bank switching/Code Banking ? Consider for 8051.
31. Any alternative method to overcome drawbacks of Bank switching ?
32. What is the use of Common area in Code Banking ?
33. What is Overlaying ? Why is it popular in embedded systems ?

 ADC and DAC
Hey geeks, the below is a set of possible ADC/DAC basic questions that can be discussed.

1. What are the factors you consider for the selection of ADC ?
2. What do you mean by Resolution of ADC ?
3. How do you determine the number of bits of ADC is required for you ?
4. Which factor determines the number of iterations in SAR done to approximate the input voltage ?
5. What are the 2 methods of ADC interface ?
6. Can you brief up the steps involved in ADC interface with 8051 or any microprocessor for the EOC based method ?
7. Can you brief up the steps involved in ADC interface with 8051 or any microprocessor for the Interrupt based method ?
8. How do you select the particular channel of a ADC . For example, can you tell for ADC0809 ?
9. When will you make the OE high in case of ADC0809 ?
10. What will happen if SC and EOC are tied together in ADC0809 ?
11. What is sampling rate/frequency ?
12. What is the use of interpolation formula ? Are you aware of any interpolation formula ?
13. What is sample and hold ?
14. Are there any Megasample / Gigasample converters ? Where are they used ?
15. What is aliasing ?
16. What is Nyquist-Shannon theorem ?
17. Is it good to sample at a rate that is higher than that of Nyquist Frequency ?
18. What is quantization error and when does it occur ? What is the unit of measurement of it ?
19. How can dithering improve digitization of slowly varying signal ?
20. Which type of ADC implementation is good or should be chosen, if we need lot of channels ?

 ARM Processor
Hey All,
These are few very simple and general ARM processor questions that can be discussed -

1. What are the types of CORTEX-M series ?
2. How do you select a specific CORTEX-M processor ?
3. What is Trustzone System IP block ?
4. What is the use of T604 ? Have you used it ?
5. Have you come across LINARO ? Have you been involved in LINARO ?
6. What is pipeline shutdown ?
7. what are the kinds of protection available for SRAMS ?
How to use the single bit or double bit fault correction ?
8. What is interrupt pipelining ?
9. Explain the architecture of the CORTEX series ARM that you have used .
10. What is the use of the AMBA interface and where is it present in the architecture ?
11. What is branch prediction ?
12. What is out of order execution ? Have you considered it in selection of processor ?
13. If the pipleline is wider , the instruction throughput is high - True/False ?
14. What is the use of Neon Floating point engine ?
15. In what scenarios can neon do better than normal core ?
16. Is power dissipation more in neon compared to normal core ?
17. Incase of multimedia applications, what is the approximate number of times by which the throughput
is increased compared to normal core ?
18. Is Neon available with Cortex M or Cortex A series ?
19. Have you used RVDS ? Have you used gcc arm toolchain ? Which of these two tools is better ?
20. What is the use of --vectorize option ?
21. Have you used Palladium emulator ? Is it JTAG based ?
22. Have you used XDS510 emulator ?
23. What is Coresight System Trace Macrocell(STM) ?
24. What is the difference between 'intrusive trace' and 'non-intrusive trace' mechanisms ?
25. Which of the following is intrusive - printf, lttng, strace, ftrace, ltrace ?
26. Can you explain the flow from User application and the role of STM driver ?
27. What are the advantages and disadvantages of LTTng ?
28. What is hardware assisted instrumentation ?
29. What is the advantage of hardware assisted instrumentation over software instrumentation ?
30. What is PTM ?
31. What is TPIU ?
32. What is ITM ?
33. What is ETM ?
34. Low latency instrumentation is required for ISR tracing, Bootcode tracing . How is low latency
tracing achieved ?
35. STM cannot trace instructions. It traces only system level calls - True / False.
36. ETM is for data/program instructions & for cache/DMA level instructions - True / False.
37. In Kinetis, can SRAM be configured to act as either NVRAM or EEPROM ? Have you configured or tried it ?
38. How many power modes are there in Kinetis ? Can you tell the wakeup/recovery time for every mode ?
Which mode has the fastest recovery time ? Which mode has the lowest current consumption ?
39. Cortex M4 has Run , Sleep and Deep sleep modes - True / False ?
40. Is 32-pin Cortex M4 compatible with 256 pin Cortex M4 processor ?
41. What is I2S interface ?
42. What are the features of Cortex M4 ?
43. Tell about the Exception Handling in ARM processor. What does the ARM Core do automatically for every exception ?
44. Can you tell about DSP in ARM7TDMI or DSP in STRONGARM or DSP in ARM9E ?
45. Why should you design the DSP algorithm in general ARM architecture so that saturation is not required ?
46. Tell about AIF(Arm Image Format) and AOF(Arm Object Format) ?
47. What are the Memory initialization directives ?
48. What is the use of 'SWI' in ARM assembly ?
49. How to Represent a Digital Signal in ARM ?
50. Give Example of STMFD w.r.t Stack Operation push/pop ?
51. Tell about Extended Multiply Instructions in ARM
52. Tell about the NORMAL Multiply Instructions in ARM
53. Tell about ADR's relation with LDR and the Advantage of using LDR together with '=' ?
54. When does the Processor Stall in ARM and what is the pipeline hazard in ARM?
55. What is called 'pipeline bubble' in ARM ?
56. What is Saturating Arithmetic ? Explain
57. Tell the 2 software methods available to remove interlocks following load instructions
58. Tell about 'Load Scheduling By Preloading' and 'Load Scheduling by unrolling' ?
59. How will you flush the instuction Cache in ARM processor ?
60. List the issues when porting C code to the ARM processor ?
61. What are the advantages of writing in Assembly in ARM processor?
62. Explain this -> "AREA |.text|, CODE, READONLY"
63. What is the use of the 'EXPORT' directive ?
64. What is the use of various directives ?
65. How to build using command line tools w.r.t ARM ?
66. Write a simple square.s program in ARM assembly called from a C file ?
67. What will you change that program when calling ARM code from C compiled as Thumb ?
68. How will you allow Thumb C code to call the ARM assembly Code ?
69. What is the use of 'RN' directive in ARM assembly ?
70. What imports the libraries like printf automatically in the assembly side of ARM ?
71. What is the DCB directive and its relation with strings ?
72. What is ARMulator ? Where and How have you used it ?
73. How will you handle the Register Shortage problem in ARM ?
74. Relation between CPSR flags, S Suffix Instructions and Comparison Instructions ?
75. What is Conditional Execution in ARM ?
76. What is single issue multiple data (SIMD) processing ?
77. What is a Coprorcessor / CP15 in ARM ?
78. What does the 'B' mean in LDRB or What is the difference between LDR and LDRB in ARM ?
79. What is the use of Write-Back ?
80. When should i use '!' in ARM programming and where is it Not Allowed to be used in ARM programming ?
81. Tell about 'Single Data Transfer' and 'Multiple Data Transfer' in ARM
82. How will you manually Enable / Disable an interrupt in ARM Processor ?
83. Tell about MRS and MSR instructions ?
84. Can you tell a 32-bit branch instruction and the way you used it ?
85. When have you used Thumb instructions in ARM processor ?
86. Write a program to mask bytes in ARM assembly ?
87. ARM7 family of processors does not use any branch prediction scheme. Neither
ARM9 nor ARM9E family implements branch prediction - True / False
88. The ARM11 micro-architecture uses two techniques to predict branches - True / False
89. What is Translation Lookaside Buffer (TLB) ?
90. What are the types of addressing modes in ARM ?
91. Can you brief up the evolution of ARM architecture ?
92. Why ARM7TDMI alone highlights the features that it supports in its naming and why not other ARM architectures ?
93. When will you choose to use ARM and when will you choose to use Thumb instructions ?
94. Can you explain the operation of ARM7 pipeline for simple instructions ?
95. Can you tell about function performed by this instruction - ADD r3, r5, r12 ?

 Linux and Linux Device driver
Linux is one of the very common Operating Systems and hope many would like to have some linux discussion. Here is a collection of questions for our linux and linux device driver related discussion...

1. What is the difference in features between kernel 2.2, 2.4 and 2.6 ?
2. What are Static and Shared libraries ?
3. What is dynamic linking ? What is static linking ?
4. What are the advantages of Dynamic linking or Shared libraries ?
5. Does gcc search for both static and shared libraries ? Which is searched initially by gcc compiler ?
6. What should be done for Shared library based linking in gcc ?
7. What should be done for static library based linking in gcc ?
8. What is object file and what are symbols ?
9. Can you tell the memory layout based on Data,BSS,HEAP and STACK ?
10. What are the ways in which linux kernel can be compiled ?
11. How will get the driver added into the kernel ? What are Kconfig files ?
12. What is a kernel module ?
13. What is the difference between insmod and modprobe ?
14. How will you list the modules ?
15. How do you get the list of currently available drivers ?
16. How will you Access userspace memory from kernel ? What are the various methods ?
17. What is the use of ioctl(inode,file,cmd,arg) ApI ?
18. What is the use of the poll(file, polltable) API ?
19. What is the use of file->private_data in a device driver structure ?
20. What is a device number ?
21. What are the two types of devices drivers from VFS point of view ?
22. What are character devices ?
23. How does the character device driver adds and remove itself from the kernel ?
What is the use of register_chrdev and unregister_chrdev ?
24. What is the role of interrupts in a device driver ? How are interrupts handled in device driver ?
25. How will you make interrupt handlers as fast as possible ?
26. What are the types of softirqs ?
27. Difference between Timer Softirq and Tasklet Softirq ?
28. What are tasklets ? How are they activated ? when and How are they initialized ?
29. What is task_struct and how are task states maintained ?
30. What is rwlock and spinlock ? Briefly explain about both of them ?
31. When will you use rwlock instead of spinlock ?
32. Can spinlock/rwlock be used in Interrupt handler ?
33. Tell about the Memory Layout of a Process in Linux .
34. How will you trace the system calls made into the kernel of lInux ?
35. What is mmap ? MMAP & malloc ? MMAP & brk ? MMAP adv & dis-adv.
36. Tell the relation between Malloc and MMAP
37. Advantages of MMAP over Read ?
38. Tell the role of brk() in malloc / Tell the relation between heap and brk?
39. Example of using MMAP and MUNMAP in C ?
40. Tell about the method/steps in Linux Kernel Compilation.
41. What is Kmalloc and how does it differ from normal malloc ? or Why can't we use malloc in kernel code ?
42. What happens as soon as a packet arrives from the network in Linux ?
43. What is a stack frame, stack pointer & frame pointer ?
44. What is a profiler ? Which one have you used ?
45. How do you determine the direction of stack growth ?

 Networking - I
Let me share few networking related queries that can be used for our discussion ...

1. What is the use of Ethernet ?
Ethernet is a link layer protocol in TCP/IP stack and the most widely used LAN technology that provides a framework for data transmission to other devices on the same network segment.

2. How is the destination MAC address obtained ?
Destination MAC address is fetched via  ARP

3. Why is TCP called as connection oriented protocol ?
As the communication session is established by means of 3 way handshake ahead of transferring data, it is termed as connection oriented protocol. Here the client initiates the creation of logical pipes through which the messages shall be sent or received. These pipes shall be deleted at the end of connection.

4. Why is UDP called as connection less protocol ?
As the communication session is not established ahead of transferring data, it is termed as connection less protocol.

5. Why is TCP termed as Heavy weight protocol ?
TCP is heavy weight because it performs handshake for connection establishment, ordering of packets, handling reliability & congestion control. That is, TCP does lots of processing to provide reliable service and hence termed as heavy weight protocol.

6. What applications use TCP ?
SSH, HTTP, FTP, Telnet, SMTP, IMAP/POP, NFS

7. What applications use UDP ?
Tunneling/VPN, TFTP, SNMP, Media streaming, Games, local broadcast , RTP

8. Why are realtime applications using UDP even though it is unreliable ?
It is used in realtime applications where it is ok even if data is lost

9. Explain any error detection mechanism in TCP ?
Error detection is viable through sequence numbers. Duplicate packets are discarded based on SN at receiver. The lost packets are re-transmitted based on ACKs.

10. What is flow control in TCP ?
In order for the receiver and transmitter to be sync on the rate of data transmission, TCP uses sliding window protocol, where the receiver intimates the sender about the amount of data that it is willing to buffer for the connection via the receive window field. The sender can accordingly send data only up to the extent.

11. What is the use of MSS in TCP ?
It is used to represent the largest amount of data that the receiver shall receive in a single segment.   

12. What is sliding window algorithm ?
TCP uses sliding window protocol, where the receiver intimates the sender about the amount of data that it is willing to buffer for the connection via the receive window field. The sender can accordingly send data only up to the extent.
       
13. Bandwidth utilization is good in TCP or UDP ?
TCP

14. Why is connect system call invoked by client ?
Connect system call helps in connecting the socket to the address of the server thereby enabling the establishment of connection.

15. Why is bind system call optional for either UDP or TCP client ?
connect system call is optional for UDP client as UDP is a connectionless protocol.

16. What is socket ?
 Socket represents an endpoint of a connection.

17. What is a raw socket and when will we use it ?
Raw socket receives or sends raw datagram without including any link layer headers. That is, it allows direct sending and receiving of internet protocol packets without any protocol specific transport layer formatting.

18. Once the segments arrive on the receiver, who does the re-assembly in the case of TCP protocol ?
IP layer handles the re-assembly.

19. Is fragmentation applicable for UDP. If yes, who does the fragmentation ?
No.

20. Is fragmentation applicable for TCP. If yes, who does the fragmentation ?
Yes. The IP layer does the fragmentation.

21. What is the need for fragmentation in TCP ?
Fragmentation is done according the MTU of the device so that the data can be transmitted.

22. What determines the size for fragmentation in TCP ?
MTU determines the size for fragmentation.

23. What is the use of SYN field ?
The presence of SYN field conveys that sequence number is the initial sequence number(ISN). Only the first packet sent from either end shall have this SYN flag set .

24. What is the use of SN field ?
SN field carries the sequence number.
If SYN flag is set, it carries the initial sequence number (ISN).
If SYN flag is clear, then it is the accumulated sequence number of the first data byte of this segment for the current session.

25. What is the use of SACK field ?
SACK enables selective ACK which allows the client to inform on the range of packets received in order and the unreceived packets by which the server shall re-transmit only the packets that were not received by the client.

26. What is the use of Window field ?
Represents the size of the receive window.

27. When will the PSH flag bet set in TCP ?
This tells the receiver to push the data out immediately to the receiving application, rather than waiting for additional data to enter the buffer.

28. Is accept a blocking or non-blocking system call and what is the use of it ?
Accept is a blocking call.  It shall block until the connection request from client.

29. What is a concurrent server architecture ?
There will be one listening socket and multiple connected socket points at the server at any time.

30. What API is used for converting ipv4 address to NBO and vice versa ?
htons(), htonl(), ntohl(), ntohs()
   
31. What is the need for IP protocol, if ethernet can send data using the destination MAC address ?
IP header carries the source ip and destination IP that is required for addressing and routing.

32. What is the use of router, switch, bridge ? List differences between router, switch & bridge.
Router acts as a default gateway on the network segment if the packet has to go to another network. Router maintains table based on IP address & port. Router uses IP layer. Router overwrites the src MAC address with its own MAC address while sending it out.

Switch is a bridge configured to work like a hub in star topology. The received frames are processed & forwarded to the appropriate port using the forwarding table that is based on MAC address & port. Switch uses the data link layer. Switch does not overwrite the src MAC address.

Bridge is a layer 2 device which forwards to all other ports. It does not overwrite the src MAC address.
    
33. What is the use of TTL field ?
TTL determines the maximum number of hops that a packet can take while traveling in the network. While traversing through the network, the routers are expected to decrement the TTL value by 1 before forwarding the packet.

34. Who sets the congestion notification flag ?
The router in the network shall set the ECN flag incase of congestion in network.

35. Is it possible to have connection between multiple socket end points ?
A socket is one endpoint of a communication link between two programs running on the network. Endpoint is a combination of a port number and IP address. Every TCP connection shall be uniquely identified by two endpoints.
   
36. What are the limitations of ethernet ?
There is distance limitation on the maximum distance between devices on ethernet network. Transmission failure can happen as distance increases due to line noise or reduced signal strength or other degradation. Also, ethernet network face congestion problems as they increase in size.    

37. Is it true that data sent over ethernet is automatically broadcasted to every device in the network ?
Yes.

38. What is the difference between CSMA and CSMA/CD ? Why CSMA is not enough ?
CSMA - Broadcast and sense the collision
CSMA/CD - Operates by detecting the occurrence of a collision. Once collision is detected, CSMA CD immediately terminates the transmission so that the transmitter does not have to waste lot of time in continuing.
   
39. What is a Jam signal ? What is back-off period ?
Whenever a collision is detected, the detecting station broadcasts a collision or jam signal to alert other stations that a collision has occurred. Accordingly, every station will wait for a random amount of time.

40. What is the need for MII ?
Originally defined as a standard interface to connect fast ethernet MAC block to PHY chip. This has later been extended as GMII, RGMII, SGMII, XGMII etc..

41. What is the ethernet supported by CAT5 . What is the ethernet supported by CAT5e cable ?
CAT5 supports both traditional and fast ethernet. CAT5e supports Gigabit ethernet.

42. How can you overcome the limitations of ethernet cable ?
Hub can help in overcoming the limitations of ethernet cable.

43. What are the types of ethernet frame formats ? Are they compatible with each other ?
Ethernet II, IEEE 802.3, IEEE 802.2 LLC, IEEE 802.2 SNAP. The different frame types have different format and MTU values, but can coexist on the same physical medium.   

44. What is the role of LLC and MAC layer in ethernet ?
LLC interacts with the upper network layer. It is responsible for handling layer 3 protocols (mux/de-mux) and link services like reliability(error management mechanisms such as ARQ) and flow control. MAC layer interacts with the lower PHY layer. It is responsible for framing and media access control for broadcast media.

45. What is carrier sensing ?
This is a media access control protocol where the transmitter determines whether another transmission is in progress before initiating transmission.

46. What is CSMA-CA ?
Carrier sensing is done but nodes attempt to avoid collisions by transmitting only when the channel is sensed to be idle.
   
47. What is the use of preamble and FCS in Ethernet frame ?
The preamble of ethernet packet allows devices to synchronize the receiver clocks. FCS is a error detecting code added to a frame that helps in discarding the damaged frame in a communication protocol if the FCS number calculated by the destination node mismatches with the FCS number sent by the source node.

48. What are the types of CSMA access modes ?
The types of CSMA access nodes are Persistent, Non-persistent, P-persistent and O-persistent.

49. What is port mirroring ? where is port mirroring used ?
Port mirroring sends a copy of network packets seen on one port to a network monitoring connection on another switch port. It is used in network switch.

50. What is a iterative server ?
Iterative server processes one client request at a time in a sequential manner.

 IPv6

Lets discuss regarding IPv6. Feel free to post your queries or answers..

1. What is IPv6 ?
    It is the protocol with capabilities to replace/upgrade IPv4.

2. Difference between IPv6 and IPv4 addresses ?
    a. IPv4 uses decimal number as numbering format for ip address
        IPv6 uses hexadecimal number as numbering format for ip address
    b. IPv4 is 32-bit numeric address
        IPv6 is 128-bit address in hexadecimal
    c. IPv4 uses class-based addressing
        IPv6 uses classless addressing

3. What is the need for IPv6 ?
     a. Limitation in address space offered by IPv4
     b. Absence of security features on its own in IPv4
     c. Limitation in data prioritization / QoS offered by IPv4

4.How will you port an application from IPv4 to IPv6 ?
   The system calls should be updated with appropriate arguments as per IPv6.

5. How will you represent an IPv6 address ?
    It shall be represented as 8 groups of 4 hexadecimal digits separated by colons.

6. How could the IPv4 address exhaustion could be handled ?
    There are various approaches like Subnetting/CIDR, NAT/PAT, Use of Private networks & DHCP

7. What changes are made in header for IPv6 ?
    All unnecessary information and options that are present in IPv4 are moved to the end of IPv6 header

8. What is the size of IPv6 header ?
     IPv6 header has a fixed header size of 40 bytes, whereas the IPv4 header has a variable length due to options field.

9. Which fields are same in IPv4 and IPv6 ?
    Version field, Type of Service (IPv4) is similar as Traffic Class(IPv6), Total
    length(IPv4) is somewhat similar as Payload length(IPv6), TTL (IPv4) is same as Hop
    Limit(IPv6), Protocol(IPv4) is somewhat similar as Next Header(IPv6)

10.What is the additional field in IPv6 that is absent in IPv4 ?
     Flow label for sequencing of packets

11. Which fields have been eliminated/deleted in IPv6 from that of IPv4 ?
      Header checksum, Header length & Fragmentation fields are eliminated. The Options field is moved into payload

12. What are the new features with IPv6 ?
      a. Stateless auto configuration
             i) No need for DHCP
            ii) New host can assign its own host address
      b. New IP security protocols
             i) Authentication of source
           iii) Encryption of payload
      c. Jumbo payload option that can carry packet upto 4GB

13. What ways IPv6 devices can be deployed ?
      a. By Tunneling IPv6 over IPv4
      b. Using Dual stack router that supports both IPv4 and IPv6
      c. Using a NAT device for translation between IPv4 and IPv6

C Programming Interview Questions:
Volatile variable in-depth (definition, use case, impact, when to avoid, etc)
Priority inversion, priority inheritance, priority ceiling
Difference btwn Process and Thread
What is Process preemption
call back functions?
How can you avoid accessing of an array beyond its limits?
If passing name is an call by value, then array name is passed is it also call by value?
how can you determine whether your memory is in protected or un-protected mode
C program to swap every 2 bits in a 8 bit binary number
Write a program to find how many bit to toggle in 2 binary numbers so that they become equal
Write a program for to get the number of bits toggle in 2 binary numbers and toggle them to make the numbers equal
How you Decide the stack size for the function or thread
Memory Layout
How to decrease the time of booting processes
What is the functionality of PROBE function
How to detect whether a device is not detected?
How to find if their is in repeating node in linked list
Find a word from string
A thread is created by processes, how the process comes to know the completion of that created thread 
In a big array consists of 1's & 0's ,write an efficient programe to keep all 1's to right side and 0's to other side
What is Thrashing
Deadlock - example
MM - Segmentation, paging, swapping
Paging vs swapping
Different segments in a program
Does linux use segmentation
What is DMA. Modes - cycle stealing/burst (blk transfer)/transparent
Cache coherency during dma. Which component handles it
Physical Virtual and logical addresses
difference between exceptions and signals and interrupt.
In a Process Address Space what if stack or heap collide?
Delete a particular node in a linked list having argument passed as address of a node.
   without Header pointer known and other implementation with header pointer known
Write program to Insert element in static array
what all Debugging techniques you know?
Determine the minimum stack size required for given prog by end of main function?
how to debug your driver if u had any buffer issues
What is shared lib and static library? And how to create it ?
Difference between #define and CONST, which one will you chose in programming?
Difference between typedef and #define?
can we add two pointers
tell me the logic how can you find depth of a stack?
Can Volatile be applied to pointer?
why size of data types is restricted?
difference b/w macro and a constant variable

malloc vs calloc
Memory barriers; Why are they required
struct alignment and packing.
Pass by value and ref
size of void pointer
What is re-entrancy


What is structure padding?
How to write own malloc call
What is the difference between inline and macro?
Write program toreset bit in register if address of register is given
 reset (int address, int bit)
How to know size of memory allocated by malloc using pointer?
Diff between mutex and semaphore? Can semaphore be used for data synchronisation purpose?


http://cinterviewquestionandanswer.blogspot.in/2014/01/c-interview-question.html
Bitwise operation :
Bit manipulationWrite the logic for setting nth bit.
Write the logic for clearing  nth bit.
Write the logic for toggling  nth bit.
Write the logic for setting nth to mth bits, where n > m.
Write the logic for clearing nth to mth bits, where n > m.
Write the logic for toggling nth to mth bits, where n > m.
Program for finding number of 1s and 0s in a 32-bit number.
Program for finding whether a number is power of 2 or not.
Program for finding whether a number is even or odd.
Write a function to swap even bits with consecutive odd bits in a number.
Write a function to swap odd bits in a number.
Write a function to swap even bits in a number.
Write a function to find out the number of 1s in a number.
Write a function to check whether the number of 1s present in a number are even or odd.
Write a function for finding the first lowest bit set in a number.
Write a function for finding the higest bit set in a number.
Write a function for reversing the bits in a number.
Write the code for extracting nth to mth bits, where n < m.
Write the code for toggling nth to mth bits, where n < m.
Write the code for setting nth to mth bits, where n < m.
Write the code for clearing nth to mth bits, where n < m
Write a piece of code for sizeof() implementation.
Explain about container_of() and offsetof() implementations.
How to implement bit-wise operations without using bit-wise operators?

Check if a number is multiple of 9 using bitwise operators
Count strings with consecutive 1’s
Gray to Binary and Binary to Gray conversion
Find the maximum subset XOR of a given set
Given a set, find XOR of the XOR’s of all subsets.
Sum of Bitwise And of all pairs in a given array
Find Next Sparse Number
Find the maximum subarray XOR in a given array
Find XOR of two number without using XOR operator
Write a program to add one to a given number. You are not allowed to use operators like ‘+’, ‘-‘, ‘*’, ‘/’, ‘++’, ‘–‘ ?
Multiply two integers without using multiplication, division and bitwise operators, and no loops
Check if a number is a power of another number
Check perfect square using addition/subtraction
Count numbers having 0 as a digit
Number of perfect squares between two given numbers
Write an Efficient C Program to Reverse Bits of a Number
Calculate square of a number without using *, / and pow()


Linklist:
Data Structures Write a program for reversing a singly linked list?
Write a program for a singly linked list (insert, delete, count, search etc functions).
Write a program for a doubly linked list (insert, delete, count, search etc functions).
Write a program for a circular singly linked list (insert, delete, count, search etc functions).
Write a program for a circular doubly linked list (insert, delete, count, search etc functions).
Write a program for binary tree implementation.
You are given a pointer to a node (not the tail node) in a singly linked list. Delete that node from the linked list. 
How to check whether a linked list is circular or not?
How would you find a loop in a singly linked list?
Write a c program for reversing a singly linked list.
Given two singly linked list, find if they are intersecting. Do this in single iteration. Also find the intersecting node in O(n) time and O(1) space. By intersection I mean intersection by reference not by value.

Write a c program to get the intersection point of two singly linked lists.
Find loop in linked list and remove the loop
implement Stack and Queue using Linked List
Repeatedly Delete N nodes after M nodes of a Linked list
Reverse every k nodes of a linked list
Reverse a Linked List using Recursion
Remove Duplicates from a Linked List
Print Linked List Elements in Reverse order
Merge a linked list into another linked list at alternate positions
Move last node to front in linked list
Swap every two nodes in a linked list
Frequency of a given number in a Linked List
Delete alternate nodes of a Linked List
Rotate linked list by K nodes
Reverse a singly linked list
Write a function to get the intersection point of two Linked Lists (Y Shape)
Write a program to detect loop in a Linked List
Insert nodes into a linked list in a sorted fashion
Write a C program to return the nth node from the end of a linked list

Find the size of a structure with out size of operator.
why stack is always in higher location.
what is the difference between global and static
have u debug any issues using jtag/ any other debugger.if yes, how can we get the call stack in the debugger.
Write a function to find whether machine is little endian or big endian.?
Write a program to find occurrence of particular key in given string?
write a program to move all 0's to one side and 1's on ther side of array?
Write a program to find largest element in an array?
Write a program to find second largest element from array?
Write a program to count total number of vowel,consonant present in given string?
Write a program to check weather  string is palindrome or not?
Write a program to implement strncpy function using recursion
Write a program to implement strlen(), strcpy(),strncpy(), strrev(),strcmp() function"?
Write a program to find size of variable without using sizeof operator?
Can we increment the base address of array? Justify your answer.
What is difference between array and pointer?
Write a program to find weather machine is 32 bit or 64 bit?
What is memory leakage? How can we avoid it?
What is NULL , void, dangling pointer?
Can we use const keyword with volatile variable?
What does keyword const means?
Can we declare main() function as static?
Storage class static and extern and register in details.
Can we declare static variable in header file?
Where a const volatile variable is used?

1) what are the compilation steps? Explain
ans:- there are 4 compilation steps they are 1.preprocessor 2.compiler 3.assembler 4.linker.
1.preprocessor:-read the source code and resolve all preprocessor directives.
gcc -E first.c -o first.i
 vim first.i
2.compiler:-transulates preprocessor code into assembly language.
gcc -S -v first.i -o first.s
vim first.s
3.assembler:-converts the assembler language in to binary language(or ) machine instructions.
gcc -C -v first.s -o first.o
objdump -D first.o
4.linker:-applies the build process i.e., the linker links all the relocatable binary files and libraries.
gcc first.o -o first
objdump -D first

write a program to print size of integer variable without using sizeof operator
write a program to find repeated character in a given string? code should be generic?
Implement string reverse program without using temporary buffer and strrev function?
how do you transfer data from userspace to kernel space?
What is generic system call that is used to transfer data from user space to kernel space?
write a program to copy a string from source to destination without using strcpy?
what is difference between mutex and semaphores
which one is faster array or linklist ?
how you cna tell whether your system is little or big indian ?
Write a program to implement memcpy() on your own 
Difference between library call and a system call

C - I
Here is a list of 50 interesting C interview questions that can be discussed upon...

1. In order to assign attributes to the pointer itself, rather than to the pointed-to object, you put the attributes after the asterisk. like ' char *const p = &c; ' - True/False

2. What is the output of the below code ?
char **p ="Hello";
printf("%s",**p);
return 0;

3. There is a char * pointer that points to some ints, and what should be done to step over it ?

4. What changes has to be done to get the ouput as "9 8 7 6 5" by the same recursive call method ?
int main(void) {
int i=9;
printf("%d \t",i--);
if(i)
main();
return 0;
}

5. What is the output in the below program ?
void main() {
int z = 12;
printf("%d",printf("Mr.123\\"));
printf(”%d”,printf(”%d%d%d”,z,z,z));
}

6. You can't 'shift' an array - True/False

7. Is it possible to do like this in C ?
char s[8];
s="ABCD1234";

8. bit-fields do not provide a way to select bits by index value - True/False

9. Does 'char *a' allocate some memory for the pointer to point to ?

10. A null pointer is does not to point to any object or function - True/False
An uninitialized pointer might point anywhere - True/False

11. The address of operator will never yield a null pointer - True/False
malloc returns a null pointer when it fails - True/False

12. char y[] is not identical to char *y - True / False . Explain the reason for either true/false.

13. What would be output of the below code ?
char x[] = "abcde";
char *y= "abcde";
printf("%c \n", x[3]);
printf("%c \n", y[3]);

14. Is it possible to have char x[5] in one file a declaration extern char * in other file ?

15. What is dangling pointer ?

16. Why does the below code cause segmentation fault ?
int* z = NULL;
*z = 1;

17. What are the two problems in the below code ?
char *s1 = "Hello, ";
char *s2 = "world!";
char *s3 = strcat(s1, s2);

18. What is the problem with the below code ?
i) char a[] = "Hello";
char *p = "Hello";
My program crashes if I try to assign a new value to p[i].

ii) char *a = "abcdef";
*a = 'X';

19. Some compilers have a switch to control if string literals are writable or not - True/False

20. Three attributes can be assign to a pointer: const / volatile / restrict - True/False

21. What are the problems in below code. How will you fix it ?
char *check(int n)
{
char box[20];
sprintf(box, "%d", n);
return box;
}

22. What is malloc's internal bookkeeping information and how does it play a role in mis-directing the location of the actual bug ?

23. Where would you use 'const int' instead of #define and where should you use #define instead of 'const int' ?

24. Keyword 'const' refers to read-only -> True/False

25. What is the output of the below code
#define MY_CALCULATOR 2+5+6
printf("%d \n" 3 * MY_CALCULATOR);

26. How does declaring function parameters as 'const' help in better,safer code ?

27. Which of the following is correct . Why does point no 'i' gives output sometime & sometimes it does not give output ?
i. char *a = malloc(strlen(str));
strcpy(a, str);
ii. char *a = malloc(strlen(str) + 1);
strcpy(a, str);

28. How do the below get expanded ? Which one is the preferred method & Why ?
#define mydef struct s *
typedef struct s * mytype;
mydef d1,d2;
mytype t1,t2;

29. i. const values cannot be used in initializers - True/False
ii. const values cannot be used for array dimensions - True/False

30. Is char x[3] = "wow"; legal ?
Why does it work sometimes ?

31. How will the below code corrupt stack ?
void checkstackcorruption (char *var)
{
char z[12];
memcpy(z, var, strlen(var));
}
int main (int argc, char **argv)
{
checkstackcorruption (argv[1]);
}

32. Is the below method of usage of realloc() correct ?
void *z = malloc(10);
free(z);
z = realloc(z, 20);

33. What does the below mean ?
int (*)[*];

34. The rank of any unsigned integer type shall equal the rank of the corresponding
signed integer type, if any - True/False

35. The rank of long long int shall be greater than the rank of long int which shall be greater than int - True/False

36.No two signed integer types shall have the same rank, even if they have the same
representation - True/False

37. sprintf function is equivalent to fprintf, except that the output is written into an array - True/False

38. Incase of both sprintf and fprintf , A null character is written at the end of the characters written and that is not counted as part of the returned value - True/False

39. Arithmetic underflow on a negative number results in negative zero - True/False

40.Negative zero and positive zero compare equal under default numerical comparison - True/False

41. 'type cast' should not be used to override a const or volatile declaration - True/False

42. 'sizeof' yields the size of an array in bytes - True / False

43. How will you determine the number of elements in an array using sizeof operator ?

44. What is l-value & r-value ?

45. What is the output of the below code ?
char (*x)[50];
printf("%u, %u,%d\n",x,x+1,sizeof(*x));

46.How will you declare & initialize pointer to a register located at phys addrs 600000h ?

47. What is NPC ?

48. Can we compare a pointer and integer ?

49. Why does *ps.i do not work in the below code ?
struct rec
{
int i;
float f;
char c;
};
int main()
{
struct rec *ps;
ps=(struct rec *) malloc (sizeof(struct rec));
*ps.i=10;
free ps;
return 0;
}

50. The term 'Pointer to pointer' is different from the term 'double pointer' - True/False

 C - II
I have enlisted the questions related to C that can be used for discussion !

1. Will the Free API (after calling Malloc) return the Memory back to the OS or the Application ?

2. How to do array assignment ?

3. What could be the gud way to check 'Close enough' equality using Floats ?

4. What is the Problem of Floating Points with '==' operator in C . On what is that dependent upon ?

5. Tell about the size of 'empty structs' in C ?

6. Why does C language permits an extra comma in initializer list

7. What does the below do ? z = x++ +( y += x++) ;

8. What is nested union ? How is it useful ?

9. How wil you pass unions to functions or pointers to unions ?

10. What is the Behaviour of realloc for NULL argument ?

11. Write a Macro to swap 2 bytes

12. Write a Macro to swap 2 bytes

13. Write small program to Set a Bit, Clear a Bit, Toggle a Bit, Test a Bit (or Demonstrate simple Bit Manipulation in C)

14. Use #define to Set Bit, Clr Bit, Toggle and Test Bit of a volatile status register (Port) - Bit Manipulations to set/clear a bit of a particular Port Register 

 Multithreading
Hi,

Here are few possible queries that can be discussed about multithreaded programming in linux !

1. Can a child process be called as a thread ?
2. Are there multiple ways to create a thread ?
3. Is it possible for the thread to be alive if we terminate the process ? Is it possible for a child process to be alive if we terminate the parent process ? 
4. What is the memory layout of a process ?
5. What is the difference between multithreading and multiprocessing ?
6. What is the memory layout of a process with 2 threads ? What is the memory layout a process with 2 child process ?
7. If we declare a variable in the thread handler of 1st thread, will it be accessible accessible to 2nd thread ?
8. If we declare one variable locally in process and another globally in process, which one will be accessible to its threads ? Will those variable be available in child process also ?
9. Is it better to design a multi-threaded application or multi-process application ?
10. When should we need to go for multi-thread design and when should we go for a multi-process design ?
11. What is TLS ?
12. Who schedules the processes and who schedules the threads ?
13. Why process considered to be heavy weight ?
14. What are the contents of PCB ? What are the contents of TCB ?
15. How to ensure that thread1 gets terminated before thread2 ?
16. What will happen if we do not reap the zombie process ?
17. What is the use of zombie process ?
18. What are the various ways to terminate a zombie process ?
19. What is the difference between wait() and waitpid() system calls ?
20. Can two zombie process communicate with each other ?
21. How do you decide on the granularity of the lock ?
22. Is it good to have big lock or small lock ?
23. What will happen if a resource is improperly locked ?
24. What is atomicity ?
25. Where are atomic operations useful ?
26. What is spinlock ?
27. What is the use of PID ?
28. What is a process, thread ? What are the differences between process and thread?
29. If there are 2 sequential fork() calls, how many child process will be there ?
30. What is the use of reentrant function in multi-threaded environment ?
31. What is the advantage of using pthreads or POSIX threads ?
32. What are the various thread models and tell the scenario in which the particular thread model is useful / beneficial ?
33. What are the advantages & dis-advantages of 1:N user level threading (thread model)?
34. What is the difference between userspace threads and kernel space threads ?
35. Will a crash of a thread impact the other thread of the process ?
36. What is the difference between pthread_create() and fork() ?
37. What information is shared between a child process and the parent process ?
38. If a parent has 2 threads , will the child process also inherit or have a copy of those 2 threads ?
39. Why a faulty pointer does not crash a process but that of a thread can corrupt the process / other threads of the process ?
40. What is co-operative multitasking and what is pre-emptive multitasking ?
41. How do avoid race conditions in multi-threading
42. What will happen if you call a sleep() in a process or thread ?
43. Will a parent process be given higher priority compared to child process by the linux scheduler ?
44. What is vfork ?
45. What is the common mode of communication between a parent process and child process ? What are the modes of communication between threads ?
46.  Is child process light weight compared to parent process ?
47. What does a fork() call return ?
48. How to terminate a process by programming method ?
49. What are the software models for mulithreaded programming ?
50. What steps are performed during a context switch of a thread and what steps are performed during a context switch of a process ?

 Multicore processor
Initially multicore processors were used mainly in telecom industry. But, nowadays, these multicore processors have made inroads into almost every technology/industry. 
Here are a few basic multicore processor based questions that can be discussed upon..

1. Will increasing the number of cores, increase the throughput of your system ?
2. What are the general methods of communication between the cores ?
3. When is it better to use single core processor compared to multi-core processor ?
4. If the CPU in a multi-core processor updates the data in the cache, copies of data in caches associated with other cores will become stale. How is the multicore processor designed to handle this scenario ?
5. What is 'Run to Completion' software architecture ?
6. What is a 'Pipelined' software architecture ?
7. What is the difference between 'Run to Completion' and 'Pipelined' software architecture ?
8. How is the debugging and testing environment in the case of multithreaded/multiprocessing applications ?
9. At what point does adding more processors or computers to the computation pool slow things down instead of speeding them up?
10. Is there an optimal number of processors for any given parallel program?
11. How Many Processes or Threads are enough for an application ?

Preprocessor

1. Using the #define statement, how would you declare a manifest constant that returns the number of seconds in a year? Disregard leap years in your answer.

#define SECONDS_PER_YEAR (60UL * 60UL * 24UL * 365UL)

I’m looking for several things here:

(a)    Basic knowledge of the #define syntax (i.e. no semi-colon at the end, the need to parenthesize etc.).

(b)    A good choice of name, with capitalization and underscores.

(c)    An understanding that the pre-processor will evaluate constant expressions for you. Thus, it is clearer, and penalty free to spell out how you are calculating the number of seconds in a year, 
rather than actually doing the calculation yourself.

(d)    A realization that the expression will overflow an integer argument on a 16 bit machine – hence the need for the L, telling the compiler to treat the expression as a Long.

(e)    As a bonus, if you modified the expression with a UL (indicating unsigned long), then you are off to a great start because you are showing that you are mindful of the perils of signed and unsigned types –
 and remember, first impressions count!

2. Write the ‘standard’ MIN macro. That is, a macro that takes two arguments and returns the smaller of the two arguments.

#define MIN(A,B)       ((A) <=  (B) ? (A) : (B))

The purpose of this question is to test the following:

(a)    Basic knowledge of the #define directive as used in macros. This is important, because until the inline operator becomes part of standard C, 
macros are the only portable way of generating inline code. Inline code is often necessary in embedded systems in order to achieve the required performance level.

(b)    Knowledge of the ternary conditional operator.  This exists in C because it allows the compiler to potentially produce more optimal code than an if-then-else sequence. 
Given that performance is normally an issue in embedded systems, knowledge and use of this construct is important.

(c)    Understanding of the need to very carefully parenthesize arguments to macros.

(d)    I also use this question to start a discussion on the side effects of macros, e.g. what happens when you write code such as :

least = MIN(*p++, b);

3. What is the purpose of the preprocessor directive #error?

Either you know the answer to this, or you don’t. If you don’t, then see reference 1. This question is very useful for differentiating between normal folks and the nerds. 
It’s only the nerds that actually read the appendices of C textbooks that find out about such things.  Of course, if you aren’t looking for a nerd, the candidate better hope she doesn’t know the answer.
Infinite Loops

4. Infinite loops often arise in embedded systems. How does one code an infinite loop in C?

There are several solutions to this question. My preferred solution is:

while(1)

{

…

}

Another common construct is:

for(;;)

{

…

}

Personally, I dislike this construct because the syntax doesn’t exactly spell out what is going on.  Thus, if a candidate gives this as a solution, 
I’ll use it as an opportunity to explore their rationale for doing so.  If their answer is basically – ‘I was taught to do it this way and I have never thought about it since’ – 
then it tells me something (bad) about them. Conversely, if they state that it’s the K&R preferred method and the only way to get an infinite loop passed Lint, then they score bonus points.

A third solution is to use a goto:

Loop:

…

goto Loop;

Candidates that propose this are either assembly language programmers (which is probably good), or else they are closet BASIC / FORTRAN programmers looking to get into a new field.
Data declarations

5. Using the variable a, write down definitions for the following:

(a) An integer

(b) A pointer to an integer

(c) A pointer to a pointer to an integer

(d) An array of ten integers

(e) An array of ten pointers to integers

(f) A pointer to an array of ten integers

(g) A pointer to a function that takes an integer as an argument and returns an integer

(h)    An array of ten pointers to functions that take an integer argument and return an integer.

The answers are:

(a)    int a;                 // An integer

(b)    int *a;               // A pointer to an integer

(c)    int **a;             // A pointer to a pointer to an integer

(d)    int a[10];          // An array of 10 integers

(e)    int *a[10];        // An array of 10 pointers to integers

(f)     int (*a)[10];     // A pointer to an array of 10 integers

(g)    int (*a)(int);     // A pointer to a function a that takes an integer argument and returns an integer

(h)    int (*a[10])(int); // An array of 10 pointers to functions that take an integer argument and return an integer

People often claim that a couple of these are the sorts of thing that one looks up in textbooks – and I agree. While writing this article, 
I consulted textbooks to ensure the syntax was correct. However, I expect to be asked this question (or something close to it) when in an interview situation. Consequently,
 I make sure I know the answers – at least for the few hours of the interview.  Candidates that don’t know the answers (or at least most of them) are simply unprepared for the interview. 
 If they can’t be prepared for the interview, what will they be prepared for?
Static

6. What are the uses of the keyword static?

This simple question is rarely answered completely.  Static has three distinct uses in C:

(a)    A variable declared static within the body of a function maintains its value between function invocations.

(b)    A variable declared static within a module[1], (but outside the body of a function) is accessible by all functions within that module. 
It is not accessible by functions within any other module.  That is, it is a localized global.

(c)    Functions declared static within a module may only be called by other functions within that module. That is, the scope of the function is localized to the module within which it is declared.

Most candidates get the first part correct.  A reasonable number get the second part correct, while a pitiful number understand answer (c). 
 This is a serious weakness in a candidate, since they obviously do not understand the importance and benefits of localizing the scope of both data and code.
Const

7. What does the keyword const mean?

As soon as the interviewee says ‘const means constant’, I know I’m dealing with an amateur. Dan Saks has exhaustively covered const in the last year,
 such that every reader of ESP should be extremely familiar with what const can and cannot do for you. If you haven’t been reading that column, suffice it to say that const means “read-only”. 
 Although this answer doesn’t really do the subject justice, I’d accept it as a correct answer. (If you want the detailed answer, then read Saks’ columns – carefully!).

If the candidate gets the answer correct, then I’ll ask him these supplemental questions:

What do the following incomplete[2] declarations mean?

const int a;

int const a;

const int *a;

int * const a;

int const * a const;

The first two mean the same thing, namely a is a const (read-only) integer.  The third means a is a pointer to a const integer (i.e., the integer isn’t modifiable, but the pointer is).
 The fourth declares a to be a const pointer to an integer (i.e., the integer pointed to by a is modifiable, but the pointer is not). The final declaration declares a to be a const pointer to a const integer 
 (i.e., neither the integer pointed to by a, nor the pointer itself may be modified).

If the candidate correctly answers these questions, I’ll be impressed.

Incidentally, one might wonder why I put so much emphasis on const, since it is very easy to write a correctly functioning program without ever using it.  There are several reasons:

(a)    The use of const conveys some very useful information to someone reading your code. In effect, declaring a parameter const tells the user about its intended usage.  
If you spend a lot of time cleaning up the mess left by other people, then you’ll quickly learn to appreciate this extra piece of information. (Of course, programmers that use const,
 rarely leave a mess for others to clean up…)

(b)    const has the potential for generating tighter code by giving the optimizer some additional information.

(c)    Code that uses const liberally is inherently protected by the compiler against inadvertent coding constructs that result in parameters being changed that should not be.  In short, they tend to have fewer bugs.

Volatile

8. What does the keyword volatile mean? Give three different examples of its use.

A volatile variable is one that can change unexpectedly.  Consequently, the compiler can make no assumptions about the value of the variable.  
In particular, the optimizer must be careful to reload the variable every time it is used instead of holding a copy in a register.  Examples of volatile variables are:

(a)    Hardware registers in peripherals (e.g., status registers)

(b)    Non-stack variables referenced within an interrupt service routine.

(c)    Variables shared by multiple tasks in a multi-threaded application.

If a candidate does not know the answer to this question, they aren’t hired.  I consider this the most fundamental question that distinguishes between a ‘C programmer’ and an ‘embedded systems programmer’. 
 Embedded folks deal with hardware, interrupts, RTOSes, and the like. All of these require volatile variables. Failure to understand the concept of volatile will lead to disaster.

On the (dubious) assumption that the interviewee gets this question correct, I like to probe a little deeper, to see if they really understand the full significance of volatile. In particular, I’ll ask them the following:

(a) Can a parameter be both const and volatile? Explain your answer.

(b) Can a pointer be volatile? Explain your answer.

(c) What is wrong with the following function?:

int square(volatile int *ptr)

{

return *ptr * *ptr;

}

The answers are as follows:

(a)    Yes. An example is a read only status register. It is volatile because it can change unexpectedly. It is const because the program should not attempt to modify it.

(b)    Yes. Although this is not very common. An example is when an interrupt service routine modifies a pointer to a buffer.

(c)    This one is wicked.  The intent of the code is to return the square of the value pointed to by *ptr. However, since *ptr points to a volatile parameter, the compiler will generate code that looks something like this:

int square(volatile int *ptr)

{

int a,b;

a = *ptr;

b = *ptr;

return a * b;

}

Since it is possible for the value of *ptr to change unexpectedly, it is possible for a and b to be different. Consequently, this code could return a number that is not a square!  The correct way to code this is:

long square(volatile int *ptr)

{

int a;

a = *ptr;

return a * a;

}
Bit Manipulation

9. Embedded systems always require the user to manipulate bits in registers or variables. Given an integer variable a, write two code fragments. The first should set bit 3 of a. 
The second should clear bit 3 of a. In both cases, the remaining bits should be unmodified.

These are the three basic responses to this question:

(a) No idea. The interviewee cannot have done any embedded systems work.

(b) Use bit fields.  Bit fields are right up there with trigraphs as the most brain-dead portion of C.  Bit fields are inherently non-portable across compilers, and as such guarantee that your code is not reusable.  
I recently had the misfortune to look at a driver written by Infineon for one of their more complex communications chip. 
 It used bit fields, and was completely useless because my compiler implemented the bit fields the other way around. The moral – never let a non-embedded person anywhere near a real piece of hardware![3]

(c) Use #defines and bit masks.  This is a highly portable method, and is the one that should be used.  My optimal solution to this problem would be:

#define BIT3       (0x1 << 3)

static int a;

void set_bit3(void) {

a |= BIT3;

}

void clear_bit3(void) {

a &= ~BIT3;

}

Some people prefer to define a mask, together with manifest constants for the set & clear values.  This is also acceptable.  
The important elements that I’m looking for are the use of manifest constants, together with the |= and &= ~ constructs.
Accessing fixed memory locations

10. Embedded systems are often characterized by requiring the programmer to access a specific memory location. 
On a certain project it is required to set an integer variable at the absolute address 0x67a9 to the value 0xaa55. The compiler is a pure ANSI compiler. Write code to accomplish this task.

This problem tests whether you know that it is legal to typecast an integer to a pointer in order to access an absolute location.  
The exact syntax varies depending upon one’s style. However, I would typically be looking for something like this:

int *ptr;

ptr = (int *)0x67a9;

*ptr = 0xaa55;

A more obfuscated approach is:

*(int * const)(0x67a9) = 0xaa55;

Even if your taste runs more to the second solution, I suggest the first solution when you are in an interview situation.
Interrupts

11. Interrupts are an important part of embedded systems. Consequently, many compiler vendors offer an extension to standard C to support interrupts. 
Typically, this new key word is __interrupt. The following code uses __interrupt to define an interrupt service routine. Comment on the code.

__interrupt double compute_area(double radius) {

{

double area = PI * radius * radius;

printf(“\nArea = %f”, area);

return area;

}

This function has so much wrong with it, it’s almost tough to know where to start.

(a)    Interrupt service routines cannot return a value. If you don’t understand this, then you aren’t hired.

(b)    ISR’s cannot be passed parameters. See item (a) for your employment prospects if you missed this.

(c)    On many processors / compilers, floating point operations are not necessarily re-entrant. In some cases one needs to stack additional registers, in other cases, one simply cannot do floating point in an ISR.
 Furthermore, given that a general rule of thumb is that ISRs should be short and sweet, one wonders about the wisdom of doing floating point math here.

(d)    In a similar vein to point (c), printf() often has problems with reentrancy and performance.  If you missed points (c) & (d) then I wouldn’t be too hard on you.
  Needless to say, if you got these two points, then your employment prospects are looking better and better.
Code Examples

12. What does the following code output and why?

void foo(void)

{

unsigned int a = 6;

int b = -20;

(a+b > 6) ? puts(“> 6”) : puts(“<= 6”);

}

This question tests whether you understand the integer promotion rules in C – an area that I find is very poorly understood by many developers. 
 Anyway, the answer is that this outputs “> 6”.  The reason for this is that expressions involving signed and unsigned types have all operands promoted to unsigned types. 
 Thus –20 becomes a very large positive integer and the expression evaluates to greater than 6. This is a very important point in embedded systems where unsigned data types 
 should be used frequently (see reference 2).  If you get this one wrong, then you are perilously close to not being hired.

13. Comment on the following code fragment?

unsigned int zero = 0;

unsigned int compzero = 0xFFFF;       /*1’s complement of zero */

On machines where an int is not 16 bits, this will be incorrect. It should be coded:

unsigned int compzero = ~0;

This question really gets to whether the candidate understands the importance of word length on a computer.  In my experience, 
good embedded programmers are critically aware of the underlying hardware and its limitations, whereas computer programmers tend to dismiss the hardware as a necessary annoyance.

By this stage, candidates are either completely demoralized – or they are on a roll and having a good time.  If it is obvious that the candidate isn’t very good, then the test is terminated at this point. 
However, if the candidate is doing well, then I throw in these supplemental questions.  These questions are hard, and I expect that only the very best candidates will do well on them. In posing these questions, I’m looking more at the way the candidate tackles the problems, rather than the answers. Anyway, have fun…

Dynamic memory allocation.

14. Although not as common as in non-embedded computers, embedded systems still do dynamically allocate memory from the heap.  What are the problems with dynamic memory allocation in embedded systems?

Here, I expect the user to mention memory fragmentation, problems with garbage collection, variable execution time, etc. 
This topic has been covered extensively in ESP, mainly by Plauger.  His explanations are far more insightful than anything I could offer here, so go and read those back issues!
 Having lulled the candidate into a sense of false security, I then offer up this tidbit:

What does the following code fragment output and why?

char *ptr;

if ((ptr = (char *)malloc(0)) == NULL) {

puts(“Got a null pointer”);

}

else {

puts(“Got a valid pointer”);

}

This is a fun question.  I stumbled across this only recently, when a colleague of mine inadvertently passed a value of 0 to malloc, and got back a valid pointer! 
After doing some digging, I discovered that the result of malloc(0) is implementation defined, so that the correct answer is ‘it depends’. 
I use this to start a discussion on what the interviewee thinks is the correct thing for malloc to do.  Getting the right answer here is nowhere near as important 
as the way you approach the problem and the rationale for your decision.
Typedef

15. Typedef is frequently used in C to declare synonyms for pre-existing data types.  It is also possible to use the preprocessor to do something similar. For instance, consider the following code fragment:

#define dPS  struct s *

typedef  struct s * tPS;

The intent in both cases is to define dPS and tPS to be pointers to structure s.  Which method (if any) is preferred and why?

This is a very subtle question, and anyone that gets it right (for the right reason) is to be congratulated or condemned (“get a life” springs to mind). The answer is the typedef is preferred. Consider the declarations:

dPS p1,p2;

tPS p3,p4;

The first expands to

struct s * p1, p2;

which defines p1 to be a pointer to the structure and p2 to be an actual structure, which is probably not what you wanted. The second example correctly defines p3 & p4 to be pointers.
Obfuscated syntax

16. C allows some appalling constructs.  Is this construct legal, and if so what does this code do?

int a = 5, b = 7, c;

c = a+++b; 

This question is intended to be a lighthearted end to the quiz, as, believe it or not, this is perfectly legal syntax. 
 The question is how does the compiler treat it? Those poor compiler writers actually debated this issue, and came up with the “maximum munch” rule,
 which stipulates that the compiler should bite off as big a (legal) chunk as it can.  Hence, this code is treated as:

c = a++ + b;

Thus, after this code is executed, a = 6, b = 7 & c = 12;

If you knew the answer, or guessed correctly – then well done.  If you didn’t know the answer then I would not consider this to be a problem.  
I find the biggest benefit of this question is that it is very good for stimulating questions on coding styles, the value of code reviews and the benefits of using lint.

Well folks, there you have it.  That was my version of the C test.  I hope you had as much fun doing it as I had writing it.  
If you think the test is a good test, then by all means use it in your recruitment.  Who knows, I may get lucky in a year or two and end up being on the receiving end of my own work.

1. What is Storage class? Explain with example  
The storage class determines the part of memory where storage is allocated for an object (particularly variables and functions) and how long the storage allocation continues to exist. In C program, there are four storage classes: automatic, register, external and static.

         Auto
            They are declared at the start of a program’s block such as in the curly braces ( { } ).  Memory is allocated automatically upon entry to a block and freed automatically upon exit from the block.
            Automatic variables may be specified upon declaration to be of storage class auto.  However, it is not required to use the keyword auto because by default, storage class within a block is auto.
        Register
        Automatic variables are allocated in the main memory of the processor; accessing these memory location for computation will take long time.
            when we required to optimize the execution time, move the critical variable to processor register. this can be done by using the register key word.
            when storage class is register, compiler is instructed to allocate a register for this variable.
            scope of the register variable is same as auto variable.
        NOTE: Allocation of register is not guaranteed always, it depends on number register available in processor and number register used for manipulation. if you define 4 variable as register storage class and and processor has only 2 register for variable allocation, then compiler will allocate 2 variable in registers and treat the remaining 2 variable as auto variable. therefore usage of register keyword should should be justified and cross checked with disassembly weather register is allocated or not.
        Extern
            For using the external global variable from other files extern keyword is used.
            any file can access this global variable and lifetime over entire program run.
        Static
            static variable have lifetime over entire program run.
            scope of this variable is limited based on the place of declaration.
            if static variable is defined in a file and not inside any function, then scope of the variable is limited within that file.
            if static variable is defined inside a function, then the scope of the variable is limited within that function.
            we can use this variable any file and any function indirectly by accessing through pointer.

2. what is qualifiers?   
 
Qualifiers defines the property of the variable. Two qualifiers are const and volatile. The const type qualifier declares an object to be unmodifiable. The volatile type qualifier declares an item whose value can legitimately be changed by something beyond the control of the program in which it appears, such as a concurrently executing thread / interrupt routine.

3. What are volatile variables? Where we should use?

A volatile variable is one that can change unexpectedly. Consequently, the compiler can make no assumptions about the value of the variable. In particular, the optimizer must be careful to reload the variable every time it is used instead of holding a copy in a register. Examples of volatile variables are:

    Hardware registers in peripherals (for example, status registers)
    Non-automatic variables referenced within an interrupt service routine
    Variables shared by multiple tasks in a multi-threaded applications

4. What does the keyword const mean? What do the following declarations mean?

const int a;
int const a;
const int *a;
int * const a;
int const * a const;

The first two mean the same thing, namely a is a const (read-only) integer.

The third means a is a pointer to a const integer (that is, the integer isn’t modifiable, but the pointer is).

The fourth declares a to be a const pointer to an integer (that is, the integer pointed to by a is modifiable,but the pointer is not).

The final declaration declares a to be a const pointer to a const integer
(that is, neither the integer pointed to by a, nor the pointer itself may be modified).

5. Can a parameter be both const and volatile ? Explain.

Yes. An example is a read-only status register. It is volatile because it can change unexpectedly. It is const because the program should not attempt to modify it

6. Can a pointer be volatile ? Explain.

   Yes, although this is not very common. An example is when an interrupt service routine modifies a pointer to a buffer

7. What’s wrong with the following function?

int square(volatile int *ptr)
{
return *ptr * *ptr;

}

This one is wicked. The intent of the code is to return the square of the value pointed to by *ptr . However, since *ptr points to a volatile parameter, the compiler will generate code that looks something like this:

int square(volatile int *ptr)
{
int a,b;
a = *ptr;
b = *ptr;
return a * b;
}

}
Because it’s possible for the value of *ptr to change unexpectedly, it is possible for a and b to be different. Consequently, this code could return a number that is not a square! The correct way to code this is:

long square(volatile int *ptr)
{
int a;
a = *ptr;
return a * a;
}

8. Data Declarations

a) int a; // An integer
b) int *a; // A pointer to an integer
c) int **a; // A pointer to a pointer to an integer
d) int a[10]; // An array of 10 integers
e) int *a[10]; // An array of 10 pointers to integers
f) int (*a)[10]; // A pointer to an array of 10 integers
g) int (*a)(int); // A pointer to a function a that takes an integer argument and
returns an integer
h) int (*a[10])(int); // An array of 10 pointers to functions that take an integer
argument and return an integer

10. What are Dangling pointers and Wild Pointers

Dangling Pointer :

Dangling pointers in computer programming are pointers that do not point to a valid object of the appropriate type. Dangling pointers arise when an object is deleted or deallocated, without modifying the value of the pointer, so that the pointer still points to the memory location of the deallocated memory.

Examples of Dangling Pointers

int main()
{
     int *p;
     p = (int *) malloc (sizeof (int));

    free(p);
    *p=10;

}

In the above piece of code we are using *p after we free the memory to it.
Such usage is called dangling pointer usage.

int main()
{
int *p = NULL;
{
int a = 10;
p = &a;
}
/*address of a is out of scope and pointer p is now called the dangling pointer, we should initialize the p to NULL before coming out or initialize the pointer to some known value before using it again*/
…
}

int* fun1()
{
int a = 10;
return(&a); /*in this line we are returning the pointer of variable ‘a’ which is out scope.*/
}

Wild Pointers:

Wild pointers are created by omitting necessary initialization prior to first use. Thus, strictly speaking, every pointer in programming languages which do not enforce initialization begins as a wild pointer. This most often occurs due to jumping over the initialization, not by omitting it. Most compilers are able to warn about this.

{

int* a;

/* a is wild pointer, it is not initialized and it may have some garbage value*/

}

correct way is

{

int* a = NULL;

}

10. When should unions be used? Why do we need them in Embedded Systems  programming?

Unions are particularly useful in Embedded programming or in situations where direct access to the hardware/memory is needed. Here is a trivial example:

typedef union
{
    struct {
        unsigned char byte1;
        unsigned char byte2;
        unsigned char byte3;
        unsigned char byte4;
    } bytes;
    unsigned int dword;
} HW_Register;
HW_Register reg;

Then you can access the reg as follows:

reg.dword = 0x12345678;
reg.bytes.byte3 = 4;

Endianism and processor architecture are of course important.

Another useful feature is the bit modifier:

typedef union
{
    struct {
        unsigned char b1:1;
        unsigned char b2:1;
        unsigned char b3:1;
        unsigned char b4:1;
        unsigned char reserved:4;
    } bits;
    unsigned char byte;
} HW_RegisterB;
HW_RegisterB reg;

With this code you can access directly a single bit in the register/memory address:

x = reg.bits.b2;

Low level system programming is a reasonable example.

unions are used to breakdown hardware registers into the component bits. So, you can access an 8-bit register into the component bits.

This structure would allow a control register to be accessed as a control_byte or via the individual bits. It would be important to ensure the bits map on to the correct register bits for a given endianness.

typedef union {
    unsigned char control_byte;
    struct {
        unsigned int nibble  : 4;
        unsigned int nmi     : 1;
        unsigned int enabled : 1;
        unsigned int fired   : 1;
        unsigned int control : 1;
    }
} ControlRegister;

11. Why is sizeof(‘a’) not 1?
Perhaps surprisingly, character constants in C are of type int, so sizeof(‘a’) is sizeof(int) (though it’s different in C++).
Result:
In Turbo C output is: 2
In Turbo C++ output is: 1
 

12. why n++ executes faster than n+1? 

The expression n++ requires a single machine instruction such as INR to carry out the increment operation whereas, n+1 requires more instructions to carry out this operation.
13. Volatile explanation revisited !

Another use for volatile is signal handlers. If you have code like this:

quit = 0;
while (!quit)
{
    /* very small loop which is completely visible to the compiler */
}

The compiler is allowed to notice the loop body does not touch the quit variable and convert the loop to a while (true) loop. Even if the quit variable is set on the signal handler for SIGINT andSIGTERM; the compiler has no way to know that.

However, if the quit variable is declared volatile, the compiler is forced to load it every time, because it can be modified elsewhere. This is exactly what you want in this situation.

Courtesy: http://stackoverflow.com/questions/246127/why-is-volatile-needed-in-c
14. Data Alignment & Structure Padding

Data Alignment: Data alignment means putting the data at a memory offset equal to some multiple of the word size, which increases the system’s performance due to the way the CPU handles memory

Data Structure Padding: To align the data, it may be necessary to insert some meaningless bytes between the end of the last data structure and the start of the next, which is data structure padding

Here is a structure with members of various types, totaling 8 bytes before compilation:

struct MixedData
{
    char Data1;
    short Data2;
    int Data3;
    char Data4;
};

After compilation the data structure will be supplemented with padding bytes to ensure a proper alignment for each of its members:

struct MixedData  /* After compilation in 32-bit x86 machine */
{
    char Data1; /* 1 byte */
    char Padding1[1]; /* 1 byte for the following 'short' to be aligned on a 2 byte boundary 
assuming that the address where structure begins is an even number */
    short Data2; /* 2 bytes */
    int Data3;  /* 4 bytes - largest structure member */
    char Data4; /* 1 byte */
    char Padding2[3]; /* 3 bytes to make total size of the structure 12 bytes */
};

The compiled size of the structure is now 12 bytes. It is important to note that the last member is padded with the number of bytes required so that the total size of the structure should be a multiple of the largest alignment of any structure member (alignment(int) in this case, which = 4 on linux-32bit/gcc)

In this case 3 bytes are added to the last member to pad the structure to the size of a 12 bytes (alignment(int) × 3).

struct FinalPad {
  float x;
  char n[1];
};

In this example the total size of the structure sizeof(FinalPad) = 8, not 5 (so that the size is a multiple of 4 (alignment of float)).

struct FinalPadShort {
  short s;
  char n[3];                                                                                
};

In this example the total size of the structure sizeof(FinalPadShort) = 6, not 5 (not 8 either) (so that the size is a multiple of 2 (alignment(short) = 2 on linux-32bit/gcc)).

It is possible to change the alignment of structures to reduce the memory they require (or to conform to an existing format) by reordering structure members or changing the compiler’s alignment (or “packing”) of structure members.

struct MixedData  /* after reordering */
{
    char Data1;
    char Data4;   /* reordered */
    short Data2;
    int Data3;  
};

The compiled size of the structure now matches the pre-compiled size of 8 bytes. Note that Padding1[1] has been replaced (and thus eliminated) by Data4 and Padding2[3] is no longer necessary as the structure is already aligned to the size of a long word.

The alternative method of enforcing the MixedData structure to be aligned to a one byte boundary will cause the pre-processor to discard the pre-determined alignment of the structure members and thus no padding bytes would be inserted.

While there is no standard way of defining the alignment of structure members, some compilers use #pragma directives to specify packing inside source files. Here is an example:

#pragma pack(push)  /* push current alignment to stack */
#pragma pack(1)     /* set alignment to 1 byte boundary */

struct MyPackedData
{
    char Data1;
    long Data2;
    char Data3;
};

#pragma pack(pop)   /* restore original alignment from stack */

This structure would have a compiled size of 6 bytes on a 32-bit system. The above directives are available in compilers from Microsoft, Borland, GNU and many others.

Another example:

struct MyPackedData
{
    char Data1;
    long Data2 __attribute__((packed));
    char Data3;
};

Courtesy: http://en.wikipedia.org/wiki/Data_structure_alignment
http://www.geeksforgeeks.org/structure-member-alignment-padding-and-data-packing/
http://stackoverflow.com/questions/381244/purpose-of-memory-alignment
http://stackoverflow.com/questions/6968468/padding-in-structures-in-c

1.  Write a macro for set and reset, swap.

#define SET_BIT( _X_, _NO_ ) ( 1<<(_X_-1)) | _NO_
#define RESET_BIT( _X_, _NO_ ) ~( ( 1<<(_X_-1) ) ) & _NO_
#define SWAP_BIT( _X_, _NO_ ) ( 1<<(_X_-1)) ^ _NO_

2.  How to find give no is 2 power of n?

if ( ( no & ( no-1 ) ) == 0 )
printf( “Given number is 2 Power of N\n” );
else
printf( “Given number is not 2 Power of N\n” );

3. Swap two numbers without using third variable.
   A = B / A       (now, A will have value val b/ val a and B will have value val b)
   B =  B / A       (now, A will have value val b/ val a and B will have value val a)
   A = A * B       (now, A will have value val b  and B will have value val a)
Above method overflow should be take care
 
   A = A + B;
   B = A – B;
   A = A – B;
 
   A = A ^ B;
   B = A ^ B;
   A = A ^ B;

4. Program to Reverse Bits – 16 bits
int main( void )
{
        int a= 0xFF00, i, rev=0;
        for( i = 0; i < 16; ++i )
        {
               if( a & ( 1 << i ) )
               {
                       rev |= ( 0x8000 >> i );
               }
        }
        printf( “Input is 0x%04x\n”, a );
        printf( “Reverse Bit Is 0x%04x\n”, rev );
        return 0;
}
 
5. Program for String Reverse
 
int main(void)
{
        char    S[] = "Vijay C Programming";
        int     i, j;
 
        for( i=0, j=strlen(S)-1; i<((strlen(S))/2); ++i, --j )
        {
             S[i]  ^= S[j] ^=  S[i]  ^= S[j];
        }
        printf( "Reverse Is : %s\n", S );
 
        return 0;
}

 6. How to find the given number is little endian or big endian?
#include <stdio.h>
int main()
{
unsigned int n = 1;
char *p;
p = (char*)&n;
if (*p == 1)
printf(“Little Endian\n”);
else if (*(p + sizeof(int) – 1) == 1)
printf(“Big Endian\n”);
else
printf(“Surprise output!!!!\n”);
return 0;
}

7. Program to Nibble and bit swapping
int main( void )
{
  unsigned char a = 40, b=20;
  a = ( a>>4 ) | ( a<<4 );
  b = ( ( b & 0xAA ) >> 1 ) | ( ( b & 0x55 ) << 1 );
  clrscr();
  printf( “After Nibble Swap %d\n”, a );
  printf( “Bit swapping %d\n”, b );
  getch();
  return 0;
}

8. C program to count the number of set bits in an unsigned integer 

/*
Program to count no. of bits in an unsigned integer
*/
void main( void )
{
unsigned int a = 15;
int count = 0;

while( a )
{
++count;
a = a & ( a – 1 );
}

clrscr();
printf( “Count is %d\n”, count );
getch();
}

9. Program to Reverse a single linked list
Node *Reverse (Node *p)
{
  Node *pr = NULL;
  while (p != NULL)
  {
  Node *tmp = p->next;
  p->next = pr;
  pr = p;
  p = tmp;
  }
  return pr;
}

10. Finding Loop in a single linked list.

(1) If the linked list is read only, take two pointer approach( p1, p2). Both pointing to beginning of linked list. Now increment p1 by 1 and p2 by 2 and compare both. if they are equal there is a cycle. Repeat this untill p2 points to null.
(2) If you have the condition not to modify the node but you can change the links, then reverse the linked list. If you reach the head node then there is a cycle.

11. Finding middle of the single linked list in a single traversal.

Step 1:
Take two pointers P1 and P2, both pointed to the first element.
Step 2:
Increment P1 by 1 and P2 by two.
Step 3:
Whenever P2 reaches to the end, P1 will be at the middle of the list, just return P1->data.

12. quick way to determine endianness of your machine?
#include <stdio.h>
int main()
{
   unsigned int i = 1;
   char *c = (char*)&i;
   if (*c)   
       printf("Little endian");
   else
       printf("Big endian");
   getchar();
   return 0;
}
 
13. 2D Memory Allocation using C
int **p;
int i;int rows = 4,columns = 3;p = (int **)malloc(sizeof(int *)*rows);for(i=0;i<rows;i++)
{
p[i] = (int *)malloc(sizeof(int)*columns);
}

14. How to convert a byte array to word array in C?

const byte input[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
unsigned long output[sizeof(input) / sizeof(unsigned long)];
memcpy(output, input, sizeof(input));  

Word to byte:

unsigned char bytes[sizeof(int)];
intn = 123;
*(int *)bytes = n;

15.Program for printing UINT32 number as string

static char print_nibble (int nibble)
{
if (nibble <= 9)
{
return ( (char)nibble + ‘0’);
}
else
{
return ( (char)nibble + ‘A’ – 10);
}
}

void PrintUINT32(int hex)
{
char     strng[10];
int i;

for (i=0; i<8; i++)
{
strng[i] = print_nibble( (hex >> (28-(4*i)) ) & 0x0000000FU);
}
strng[8] = 0x00;

printf(“%s \n”,strng);
}
16.Byte Swap program

function swap16(val) { return ((val & 0xFF) << 8) | ((val >> 8) & 0xFF); }

function swap32(val) { return ((val & 0xFF) << 24) | ((val & 0xFF00) << 8) | ((val >> 8) & 0xFF00) | ((val >> 24) & 0xFF); }
17. Searching for duplicates in array

Simple algorithm
int yes = 1, i, j;
for (i = 0; i < n; ++i)
{
   for (j = i + 1; j < n; ++j) if (arr[i] == arr[j])
   {
       printf("Found a duplicate of %d\n", arr[i]);
       yes = 0;
       break;
   }
   if (!yes) break;
}
if (yes) printf("No duplicates");

Efficient Algorithim


void rmdup(int *array, int length)
{
    int *current , *end = array + length - 1;

    for ( current = array + 1; array < end; array++, current = array + 1 )
    {
        while ( current <= end )
        {
            if ( *current == *array )
            {
                *current = *end--;
            }
            else
            {
                current++;
            }
        }
    }
}
 

1. What is difference between the Process and the thread ?

Process:

    An executing instance of a program is called a process. Some operating systems use the term ‘task‘ to refer to a program that is being executed.
    A process is always stored in the main memory also termed as the primary memory or random access memory.Therefore, a process is termed as an active entity. It disappears if the machine is rebooted.
    Several process may be associated with a same program.
    On a multiprocessor system, multiple processes can be executed in parallel.On a uni-processor system, though true parallelism is not achieved, a process scheduling algorithm is applied and the processor is scheduled to execute each process one at a time yielding an illusion of concurrency.
    Example: Executing multiple instances of the ‘Calculator’ program. Each of the instances are termed as a process.

Thread:

    A thread is a subset of the process.It is termed as a ‘lightweight process’, since it is similar to a real process but executes within the context of a process and shares the same resources allotted to the process by the kernel
    Usually, a process has only one thread of control – one set of machine instructions executing at a time.
    A process may also be made up of multiple threads of execution that execute instructions concurrently.
    Multiple threads of control can exploit the true parallelism possible on multiprocessor systems.
    On a uni-processor system, a thread scheduling algorithm is applied and the processor is scheduled to run each thread one at a time.
    All the threads running within a process share the same address space, file descriptor, stack and other process related attributes.
    Since the threads of a process share the same memory, synchronizing the access to the shared data withing the process gains unprecedented importance.

The major difference between threads and processes is:

    Threads share the address space of the process that created it; processes have their own address space.
    Threads have direct access to the data segment of its process; processes have their own copy of the data segment of the parent process.
    Threads can directly communicate with other threads of its process; processes must use interprocess communication to communicate with sibling processes.
    Threads have almost no overhead; processes have considerable overhead.
    New threads are easily created; new processes require duplication of the parent process.
    Threads can exercise considerable control over threads of the same process; processes can only exercise control over child processes.
    Changes to the main thread (cancellation, priority change, etc.) may affect the behavior of the other threads of the process; changes to the parent process does not affect child processes.

2. Why can’t we use malloc in kernel code ?

You can’t use libraries in the kernel. None whatsoever.

This means that ANY function you’re calling in the kernel needs to be defined in the kernel. Linux does not define a malloc, hence you can’t  use it.There is a memory allocator and a family of memory allocation functions. Read the kernel docs on the memory allocator for more information.

Incidentally, there are a few functions the kernel defines which are in the standard C library as well; this is for convenience.
3. What is the major difference between kmalloc and vmalloc?

kmalloc allocates physically contiguous memory, memory which pages are laid consecutively in physical RAM. vmalloc allocates memory which is contiguous in kernel virtual memory space (that means pages allocated that way are not contiguous in RAM, but the kernel sees them as one block).

kmalloc is the preffered way, as long as you don’t need very big areas. The trouble is, if you want to do DMA from/to some hardware device, you’ll need to use kmalloc, and you’ll probably need bigger chunk. The solution is to allocate memory as soon as possible, before memory gets fragmented.

Main reason for kmalloc being used more than vmalloc in kernel is performance. when big memory chunks are allocated using vmalloc, kernel has to map the physically non-contiguous chunks (pages) into a single contiguous virtual memory region. Since the memory is virtually contiguous and physically non-contiguous, several virtual-to-physical address mappings will have to be added to the page table. And in the worst case, there will be (size of buffer/page size)number of mappings added to the page table.

This also adds pressure on TLB (the cache entries storing recent virtual to physical address mappings) when accessing this buffer. This can lead to thrashing.

You only need to worry about using physically contiguous memory if the buffer will be accessed by a DMA device on a physically addressed bus (like PCI). The trouble is that many system calls have no way to know whether their buffer will eventually be passed to a DMA device: once you pass the buffer to another kernel subsystem, you really cannot know where it is going to go. Even if the kernel does not use the buffer for DMA today, a future development might do so.

vmalloc is often slower than kmalloc, because it may have to remap the buffer space into a virtually contiguous range. kmalloc never remaps, though if not called with GFP_ATOMIC kmalloc can block.

kmalloc is limited in the size of buffer it can provide: 128 KBytes. If you need a really big buffer, you have to use vmalloc or some other mechanism like reserving high memory at boot.
 4. What is mmap?

In computing, mmap is a POSIX-compliant Unix system call that maps files or devices into memory. It is a method of memory-mapped file I/O. It naturally implements demand paging, because initially file contents are not entirely read from disk and do not use physical RAM at all. The actual reads from disk are performed in “lazy” manner, after a specific location is accessed. After the memory is not to be used, it is important to munmap the pointers to it.
5. In the linux kernel, what does the probe() method, that the driver provides, do? How different is it from the driver’s init function, i.e. why can’t the probe() functions actions be performed in the driver’s init function ?

Different device types can have probe() functions. For example, PCI and USB devices both have probe() functions.

Shorter answer, assuming PCI: The driver’s init function calls pci_register_driver() which gives the kernel a list of devices it is able to service, along with a pointer to the probe() function. The kernel then calls the driver’s probe() function once for each device.

This probe function starts the per-device initialization: initializing hardware, allocating resources, and registering the device with the kernel as a block or network device or whatever it is.That makes it easier for device drivers, because they never need to search for devices or worry about finding a device that was hot-plugged. The kernel handles that part and notifies the right driver when it has a device for you to handle.
6. What is the difference beteween kernel modules and kernel drivers

A kernel module is a bit of compiled code that can be inserted into the kernel at run-time, such as with insmod or modprobe.

            A driver is a bit of code that runs in the kernel to talk to some hardware device. It “drives” the hardware. Most every bit of hardware in your computer has an associated driver[*]. A large part of a running kernel is driver code; the rest of the code provides generic services like memory management, IPC, scheduling, etc.

A driver may be built statically into the kernel file on disk. (The one in /boot, loaded into RAM at boot time by the boot loader early in the boot process.) A driver may also be built as a kernel module so that it can be dynamically loaded later. (And then maybe unloaded.)

Standard practice is to build drivers as kernel modules where possible, rather than link them statically to the kernel, since that gives more flexibility. There are good reasons not to, however:

    Sometimes a given driver is absolutely necessary to help the system boot up. That doesn’t happen as often as you might imagine, due to the initrd feature.
    Statically built drivers may be exactly what you want in a system that is statically scoped, such as an embedded system. That is to say, if you know in advance exactly which drivers will always be needed and that this will never change, you have a good reason not to bother with dynamic kernel modules.

Not all kernel modules are drivers. For example, a relatively recent feature in the Linux kernel is that you can load a different process scheduler.

[*] One exception to this broad statement is the CPU chip, which has no “driver” per se. Your computer may also contain hardware for which you have no driver.

Courtesy: http://unix.stackexchange.com/questions/47208/what-is-the-difference-between-kernel-drivers-and-kernel-modules

7. What is Spinlock and what is difference between Mutex and Spinlock?

When you use regular locks (mutexes, critical sections etc), operating system puts your thread in the WAIT state and preempts it by scheduling other threads on the same core. This has a performance penalty if the wait time is really short, because your thread now has to wait for a preemption to receive CPU time again.

Spin locks don’t cause preemption but wait in a loop (“spin”) till the other core releases the lock. This prevents the thread from losing it’s quantum and continue as soon as the lock gets released. The simple mechanism of spinlocks allow a kernel to utilize it in almost any state.

Courtesy: http://stackoverflow.com/questions/1957398/what-exactly-are-spin-locks

Difference:

In theory, when a thread tries to lock a mutex and it does not succeed, because the mutex is already locked, it will go to sleep, immediately allowing another thread to run. It will continue to sleep until being woken up, which will be the case once the mutex is being unlocked by whatever thread was holding the lock before. When a tread tries to lock a spinlock and it does not succeed, it will continuously re-try locking it, until it finally succeeds; thus it will not allow another thread to take its place (however, the operating system will forcefully switch to another thread, once the CPU runtime quantum of the current thread has been exceeded, of course).

Read more@

Courtesy: http://stackoverflow.com/questions/5869825/when-should-one-use-a-spinlock-instead-of-mutex

What is the purpose of WFI and WFE instructions and the event signals ?

We have 2 instructions for entering low-power standby state where most clocks are gated: WFI and
WFE. 

They differ slightly in their entry and wake-up conditions, with the main difference being that
WFE makes use of the event register, the SEV instruction and EVENTI, EVENTO signals.

WFI is targeted at entering either standby, dormant or shutdown mode, where an interrupt is required to wake-up the processor. 

A usage for WFE is to put it into a spinlock loop. Where a CPU wants to access a shared resource
such as shared memory, we can use a semaphore flag location managed by exclusive load and store
access. If multiple CPUs are trying to access the resource, one will get access and will start to
use the resource while the other CPUs will be stuck in the spinlock loop. To save power, you can
insert the WFE instruction into the loop so the CPUs instead of looping continuously will enter
STANDBTWFE. Then the CPU who has been using the resource should execute SEV instruction after it
has finished using the resource. This will wake up all other CPUs from STANDBYWFE and another CPU
can then access the shared resource. 

The reason for having EVENTI and EVENTO is to export a pulse on EVENTO when an SEV instruction is
executed by any of the CPUs. This signal would connect to EVENTI of a second Cortex-A5 MPCore
cluster and would cause any CPUs in STANDBYWFE state to leave standby. So these signals just
expand the usage of WFE mode across multiple clusters. If you have a single cluster, then you do
not need to use them.

Courtesy: http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.faqs/ka15473.html

What is the differance b/w platform driver and device driver or kernel driver ?
http://www.atmel.com/Images/doc32098.pdf


1. What are storage class specifier?

Ans: Please refer this link : http://cinterviewquestionandanswer.blogspot.in/2014/01/storage-class-specifier.html


2. What is static variable?
 Ans :

There are 3 main uses for the static.

1. If you declare within a function: It retains the value between function calls.

2. If it is declared for a function name: By default function is extern..so it will be visible from other files if the function declaration is as static..it is invisible for the outer files.

3. Static for global variables: By default we can use the global variables from outside files If it is static global..that variable is limited to with in the file.

3. What is difference between static and extern?
Ans:
"The static storage class is used to declare an identifier that is a local variable either to a function or a file and that exists and retains its value after control passes from where it was declared. This storage class has a duration that is permanent. A variable declared of this class retains its value from one call of the function to the next. The scope is local. A variable is known only by the function it is declared within or if declared globally in a file, it is known or seen only by the functions within that file. This storage class guarantees that declaration of the variable also initializes the variable to zero or all bits off.
The extern storage class is used to declare a global variable that will be known to the functions in a file and capable of being known to all functions in a program. This storage class has a duration that is permanent. Any variable of this class retains its value until changed by another assignment. The scope is global. A variable can be known or seen by all functions within a program. ."

 4. What is difference between static local and static global variable?
Ans:
Static global  :
Static variable has scope only in the file in which it is declared. it can't be accessed in any other file but its value remains intact if code is running in some other file means lifetime is in complete program .
Static local:
static local variable has scope in that function in which it is declared means it can't be used in other functions in the same file also, means scope is limited to the function in which it is declared while its life time is also through out the program.

5. Can we declare static variable in header file?
Ans:
You can’t declare a static variable without defining it as well (this is because the storage class modifiers static and extern are mutuallyexclusive). A static variable can be defined in a header file, but this would cause each source file that included the header file to have its own private copy of the variable, which is probably not what was intended.

6. Can we declare main() function as static?
Ans:
No. The C spec actually says somewhere in it  that the main function cannot be static.
The reason for this is that static means "don't let anything outside this source file use this object". The benefit is that it protects against name collisions in C when you go to link (it would be bad bad bad if you had two globals both named "is_initialized" in different files... they'd get silently merged, unless you made them static). It also allows the compiler to perform certain optimizations that it wouldn't be able to otherwise. These two reasons are why static is a nice thing to have.
Since you can't access static functions from outside the file, how would the OS be able to access the main function to start your program? That's why main can't be static.
Some compilers treat "main" specially and might silently ignore you when you declare it static.

7. Draw memory layout of C program?
Ans : 
Refer This link:   http://cinterviewquestionandanswer.blogspot.in/2014/01/memory-layout-of-c-programs.html

8.What is volatile variable means?
volatile has nothing to deal with storage class.
volatile just tells the compiler or force the compiler to "not to do the optimization" for that variable. so compiler would not optimize the code for that variable and reading the value from the specified location, not through interal register which holds the previous value.
So, by declaring variable as volatile.. it gives garrantee that you will get the latest value, which may be alterred by an external event.
your code may be work fine if haven't declare that variable as volatile, but there may be chance of not getting correct value sometimes.. so to avoid that we should declare variable as volatile.
volatile is generally used when dealing with external events, like interrupts of hardware related pins.

Example. reading adc values.

const voltile means you can not modify or alter the value of that variable in code. only external event can change the value.
controller pins are generally defines as volatile. may be by declaring variable as volatile controller will do "read by pin" not "read by latch"... this is my assumtion. may be wrong...
but still there is lots of confusion when to choose variable as volatile..
A variable should be declared volatile whenever its value could change unexpectedly. In practice, only three types of variables could change:
Memory-mapped peripheral registers
Global variables modified by an interrupt service routine
Global variables within a multi-threaded application

9. What does keyword const means?
Ans:
The const qualifier explicitly declares a data object as something that cannot be changed. Its value is set at initialization. You cannot use const data objects in expressions requiring a modifiable lvalue. For example, a const data object cannot appear on the lefthand side of an assignment statement
int const volatile var


10. What do the following declaration means?

const int a;
int const a;
const int *a;
int * const a;
int const * a const;

11. Can we use const keyword with volatile variable?
Ans:
Yes. The const modifier means that this code cannot change the value
of the variable, but that does not mean that the value cannot be
changed by means outside this code. For instance, in the example  the timer structure was accessed through a volatile const pointer. The function itself did not change the value of the timer, so it was declared const. However, the value was changed by hardware on the computer, so it was declared volatile. If a variable is both const and volatile, the two modifiers can appear in either order.

 Pointer String and array question :

1. What are pointers?
Ans:
A pointer is a variable whose value is the address of another variable, i.e., direct address of the memory location. Like any variable or constant, you must declare a pointer before you can use it to store any variable address. The general form of a pointer variable declaration is:

type *var-name;

Here, type is the pointer's base type; it must be a valid C data type and var-name is the name of the pointer variable. The asterisk * you used to declare a pointer is the same asterisk that you use for multiplication. However, in this statement the asterisk is being used to designate a variable as a pointer. Following are the valid pointer declaration:

int    *ip;    /* pointer to an integer */
double *dp;    /* pointer to a double */
float  *fp;    /* pointer to a float */
char   *ch     /* pointer to a character */

The actual data type of the value of all pointers, whether integer, float, character, or otherwise, is the same, a long hexadecimal number that represents a memory address. The only difference between pointers of different data types is the data type of the variable or constant that the pointer points to.

2. What is dangling pointer?
Ans:
A dangling pointer points to memory that has already been freed. The storage is no longer allocated. Trying to access it might cause a Segmentation fault.
Common way to end up with a dangling pointer:

char* func()
{
   char str[10];
   strcpy(str,"Hello!");
   return(str); 
}
//returned pointer points to str which has gone out of scope. 

You are returning an address which was a local variable, which would have gone out of scope by the time control was returned to the calling function. (Undefined behaviour)
Another common dangling pointer example is an access of a memory location via pointer, after free has been explicitly called on that memory.

int *c = malloc(sizeof(int));
free(c);
*c = 3; //writing to freed location!


3. What is NULL pointer?
Ans:
Null pointer is special reserved value of a pointer. A pointer of any type has such a reserved value. Formally, each specific pointer type (int*, char*) has its own dedicated null-pointer value. Conceptually, when a pointer has that null value it is not pointing anywhere.

4. What is void Pointer?
Ans:
Void pointer or generic pointer is a special type of pointer that can be pointed at objects of any data type. A void pointer is declared like a normal pointer, using the void keyword as the pointer’s type.

Pointers defined using specific data type cannot hold the address of the some other type of variable i.e., it is incorrect in C++ to assign the address of an integer variable to a pointer of type float.

Example:

float *f; //pointer of type float
int i;  //integer variable
f = &i; //compilation error

The above problem can be solved by general purpose pointer called void pointer.

Void pointer can be declared as follows:

void *v // defines a pointer of type void

The pointer defined in this manner do not have any type associated with them and can hold the address of any type of variable.

Example:

void *v;
int *i;
int ivar;
char chvar;
float fvar;
v = &ivar; // valid
v = &chvar; //valid
v = &fvar; // valid
i = &ivar; //valid
i = &chvar; //invalid
i = &fvar; //invalid  

5. What is memory leakage? How can we avoid it?
Ans :
Memory leak occurs when programmers create a memory in heap and forget to delete it.
Memory leaks are particularly serious issues for programs like daemons and servers which by definition never terminate.

/* Function with memory leak */
#include 

void f()
{
   int *ptr = (int *) malloc(sizeof(int));

   /* Do some work */

   return; /* Return without freeing ptr*/
}

To avoid memory leaks, memory allocated on heap should always be freed when no longer needed.

/* Function without memory leak */
#include ;

void f()
{
   int *ptr = (int *) malloc(sizeof(int));

   /* Do some work */

   free(ptr);
   return;
}


6. What is the size of pointer in 32 bit machine?
Ans:
Sizeof  of pointer in 32 bit machine is always 4 bytes.

7. Write a program to find weather machine is 32 bit or 64 bit?
Ans:
int main()
{
    int *p = NULL;
    if(sizeof(p) == 4)
        printf("Machine is 32 bit\n");
    else
        printf("Machine is 64 bit\n");
    return 0;
}

8. What is array?
Ans:
In C programming, one of the frequently arising problem is to handle similar types of data. For example: If the user want to store marks of 100 students. This can be done by creating 100 variable individually but, this process is rather tedious and impracticable. These type of problem can be handled in C programming using arrays.
An array is a sequence of data item of homogeneous value(same type).

9. What is difference between array and pointer?
Ans:
An array is an array and a pointer is a pointer, but in most cases array names are converted to pointers.
Here is an array:
int a[7]
a contains space for seven integers, and you can put a value in one of them with an assignment, like this:
a[3] = 9;
Here is a pointer:
int *p;
p doesn't contain any spaces for integers, but it can point to a space for an integer. We can for example set it to point to one of the places in the array a, such as the first one:
p = &a[0];
What can be confusing is that you can also write this:
p = a;
This does not copy the contents of the array a into the pointer p (whatever that would mean). Instead, the array name a is converted to a pointer to its first element. So that assignment does the same as the previous one.
Now you can use p in a similar way to an array:
p[3] = 17;
The reason that this works is that the array dereferencing operator in C, "[ ]", is defined in terms of pointers. x[y] means: start with the pointer x, step y elements forward after what the pointer points to, and then take whatever is there. Using pointer arithmetic syntax, x[y] can also be written as *(x+y).
For this to work with a normal array, such as our a, the name a in a[3] must first be converted to a pointer (to the first element in a). Then we step 3 elements forward, and take whatever is there. In other words: take the element at position 3 in the array. (Which is the fourth element in the array, since the first one is numbered 0.)
So, in summary, array names in a C program are (in most cases) converted to pointers. One exception is when we use the sizeof operator on an array. If a was converted to a pointer in this contest, sizeof(a) would give the size of a pointer and not of the actual array, which would be rather useless, so in that case a means the array itself.

10. Can we increment the base address of array? Justify your answer.
Ans: 
No, Because once we initialize the array variable, the pointer points base address only & it's fixed  and constant pointer.

11.  What is the output of program.
int a[5] = {1,2,3,4,5};
int *ptr = (int*) (&a +1);
int *ptr = (int*) (a+1); 

Ans: 

you see, for your program above, a and &a will have the same numerical value,and I believe that's where your whole confusion lies.You may wonder that if they are the same,the following should give the next address after a in both cases,going by pointer arithmetic:

(&a+1) and (a+1)

But it's not so!!Base address of an array (a here) and Address of an array are not same! a and &a might be same numerically ,but they are not the same type. a is of type int* while &a is of type int (*)[5],ie , &a is a pointer to (address of ) and array of size 5.But a as you know is the address of the first element of the array.Numerically they are the same as you can see from the illustration using ^ below.
But when you increment these two pointers/addresses, ie as (a+1) and (&a+1), the arithmetic is totally different.While in the first case it "jumps" to the address of the next element in the array, in the latter case it jumps by 5 elements as that's what the size of an array of 5 elements.
 


12. What is output of the program?
int main()
{
            int arr[10];
            int *ptr = arr;
            ptr++;
            arr++;
            return 0;
}

Ans:  
The statement arr++ will give you lvalue error. Because hear you are trying to increment base address of array and by default base address of array is constant pointer(constant value) so,
arr  =  arr+1;
i.e according to rule on LHS of assignment operator there always should be lvalue i.e variable not constant.

13. What is string?
Ans:
The string in C programming language is actually a one-dimensional array of characters which is terminated by a null character '\0'. Thus a null-terminated string contains the characters that comprise the string followed by a null.

14. What is difference between these two,

char ptr[] = "string";
char *ptr = "string";

Ans:

The two declarations are not the same.
First one is the array of character i.e. string and second one is the string literals.
char ptr[] = "string"; declares a char array of size 7 and initializes it with the characters s ,t,r,i,n,g and \0. You are allowed to modify the contents of this array.
char *ptr = "string"; declares ptr as a char pointer and initializes it with address of string literal "string" which is read-only. Modifying a string literal is an undefined behavior. What you saw(seg fault) is one manifestation of the undefined behavior.


15. Write a program to find size of variable without using sizeof operator?
Ans:

#define sizeof(var)     ( (char*)(&var+1) - (char*) (&var))

int main()
{
    int val;
    printf("size of = %d\n", SIZEOF(val));
    return 0;
}

16. Write a program to find sizeof structure without using size of operator?
Ans:

#define SIZEOF(var)     ( (char*)(&var+1) - (char*) (&var))

int main()
{
        struct s {
                int a;
                char b;
                int c;
        };
        struct s obj[1];

    printf("size of = %ld\n", SIZEOF(obj));
    return 0;
}

17. What is the output of following program?

int main()
{
      char str[] = "vishnu";
      printf("%d %d\n",sizeof(str),strlen(str));
}

Ans:
7 6
Here char str[] = " 'v'. 'i' ,'s','h','n',u','\0' ";
so sizeof operator always count null character whereas strlen skip null character.

18. Write a program to implement strlen(), strcpy(),strncpy(), strrev(),strcmp() function"?

Ans:

1. strlen:

int my_strlen(const char * str)
{
    int count;
    while(* str != '\0') {
        count++;
        str++;
    }
    return 0;
}

2. strcpy:

void my_strcpy(char * dest, const char* src)
{
    while(* src != '\0') {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

3. strrev:

void my_strrev(char *str,size)
{
    int i;
    char temp;
    for(i=0;i<=size/2;i++) {
        temp = str[i];
        str[i] = str[size-i];
        str[size-i] = temp;
    }
}

int main()
{
    char str[10] = "vishnu";
    int len;
    len = strlen(str);
    my_strrev(str,len-1);
    printf("strrev = %s\n",str);
    return 0;
}

4. strcmp :

void my_strcmp(char * dest, const char* src)
{
     while(*str != '\0' && *dest != '\0') {
        str++;
        dest++;
    }
    return (*src - *dest);
}

int main()
{
    char str[10];
    char dest[10];
    int i;
    i = my_strcmp(dest,src);
    if(i == 0 )
        printf("strings are equal\n");
    if(i < 0)
        printf(" string1 is less than string2\n");
    if(i > 0)
        printf("string2 is greter than string1\n");
    return 0;
} 

5. strncpy

void my_strncpy(char * dest, const char* src,int n)
{
    while(*src != '\0' && n != 0) {
        *dest = *src;
        dest++;
        src++;
        n--;
    }
    while(n) {
        *dest = '\0';
        n--;
    }
}

19 . Write a program to implement above function using recursion?

20 . Write a program to check weather  string is palindrome or not?

int main()
{
    char string[25], reverse_string[25] = {'\0'};
    int  i, length = 0, flag = 0;
    fflush(stdin);
    printf("Enter a string \n");
    gets(string);
    for (i = 0; string[i] != '\0'; i++) {
        length++;
    }
   
    for (i = length - 1; i >= 0; i--) {
        reverse_string[length - i - 1] = string[i];
    }
    if(strcmp(string,reverse_string) == 0 )
        printf("%s is palindrome\n");
    else
        printf("%s is not palindrome\n");
    return 0;
}



21 . Write a program to count total number of vowel,consonant present in given string?
Ans:

int main()
{

    char sentence[80];
    int i, vowels = 0, consonants = 0, special = 0;
    printf("Enter a sentence \n");
    gets(sentence);
         for (i = 0; sentence[i] != '\0'; i++) {

        if ((sentence[i] == 'a' || sentence[i] == 'e' || sentence[i] == 'i' || sentence[i] == 'o' || sentence[i] == 'u') || (sentence[i] == 'A' || sentence[i] == 'E' || sentence[i] == 'I' || sentence[i] == 'O' || sentence[i] == 'U')) {
        vowels = vowels + 1;
        }
        else {
            consonants = consonants + 1;
        }
        if (sentence[i] =='t' ||sentence[i] =='\0' || sentence[i] ==' ') {
            special = special + 1;
        }

    }
    consonants = consonants - special;
      printf("No. of vowels in %s = %d\n", sentence, vowels);
    printf("No. of consonants in %s = %d\n", sentence, consonants);
    return 0;

}

22. Write a function to find whether machine is little endian or big endian.?

Ans:
void is_little_or_big(int n)
    {
        int num = 0x01;
        char * ptr = (char*)num;
        if(*ptr == 1)
            printf("little endian\n");
        else
            printf("big endian\n");
    }
    or
   
    void is_little_or_big()
    {
        enum union {
            int a;
            char c[4];
        };
        enum endian obj;
        obj.i = 1;
        if(obj.c[0] == 1)
            printf("Machine is little endian\n");
        else
            printf("machine is big endian\n");
    }
 

Write a program to find occurrence of particular key in given string?

Write a program to move all 0's to one side and 1's on ther side of array?

Write a program to find largest element in an array?

Write a program to find second largest element from array?


Bit Manipulation  :

1. Write a program to count total number of setbit in 32 bit number?

int countset(int num)
{
           int count = 0;
           while (num) {
                    if( ((num) & 1) == 1)
                           count++;
                     num = num >> 1;
              }
             return count;
}
or
unsigned int countsetbit(int num)
{
           int count = 0;
           while(num != 0) {
                      count ++;
                      num = num & (num-1);
              }
             return count;
}

2. Write a program to set n th bit in 32 bit number?

int setbit(int num, int pos)
{
           num = num | 1 << pos;
}

3. Write a program to count total number of reset bit in 32 bit integer?

 int setbit(int num)
{
           int count = 0;
           while (num) {
                    if( ((num) & 1) == 0)
                           count++;
                     num = num >> 1;
              }
             return count;
}


4. Write a program to reset nth bit in 32 bit number?

int resetbit(int num, int pos)
{
           num = num &  ~(1 << pos);
}


5. Write a program to swap nibble of a 1byte data?


6. Write a program to swap two variable using bitwise operator?

void swap(int a, int b)
{
         a = a ^ b;
         b = a ^  b;
         a = a ^ b;
}

7. Write a program to find number is even or odd?

void evnodd(int num)
{
       if( (num) & (1) )
           printf("odd");
      else
           printf("even");
} 

8. Write a program to find number is power of 2 or not?

void  power(int num)
{
       if( !( (num) & (num-1) ) )
           printf("power of 2");
      else
           printf("num is not power of 2");
} 

9 Write a function to swap even bits with consecutive odd bits in a number.
   e.g. bo swapped with b1,b2 sawpped with b3 and so on.

 Given an unsigned integer, swap all odd bits with even bits. For example, if the given number is 23 (00010111), it should be converted to 43 (00101011). Every even position bit is swapped with adjacent bit on right side (even position bits are highlighted in binary representation of 23), and every odd position bit is swapped with adjacent on left side.
If we take a closer look at the example, we can observe that we basically need to right shift (>>) all even bits (In the above example, even bits of 23 are highlighted) by 1 so that they become odd bits (highlighted in 43), and left shift (<<) all odd bits by 1 so that they become even bits. The following solution is based on this observation. The solution assumes that input number is stored using 32 bits.
Let the input number be x
1) Get all even bits of x by doing bitwise and of x with 0xAAAAAAAA. The number 0xAAAAAAAA is a 32 bit number with all even bits set as 1 and all odd bits as 0.
2) Get all odd bits of x by doing bitwise and of x with 0x55555555. The number 0x55555555 is a 32 bit number with all odd bits set as 1 and all even bits as 0.
3) Right shift all even bits.
4) Left shift all odd bits.
5) Combine new even and odd bits and return.


// C program to swap even and odd bits of a given number
#include
unsigned int swapBits(unsigned int x)
{
    // Get all even bits of x
    unsigned int even_bits = x & 0xAAAAAAAA;
    // Get all odd bits of x
    unsigned int odd_bits  = x & 0×55555555;
    even_bits >>= 1;  // Right shift even bits
    odd_bits <<= 1;   // Left shift odd bits
    return (even_bits | odd_bits); // Combine even and odd bits
}
// Driver program to test above function
int main()
{
    unsigned int x = 23; // 00010111
    // Output is 43 (00101011)
    printf("%u ", swapBits(x));
    return 0;
}
Output:

 43 

 

10. Write a function to set a particular bit.


unsigned int setbit(unsigned inr num,int pos)
{
 num = num | (1 << pos);
 return num;
}
 

11. Write a function to clear a particular bit.

unsigned int clear(unsigned inr num,int pos)
{
 num = num & ~ (1 << pos);
 return num;
}

12. Write a function to toggle particular bit.

unsigned int togglebit(unsigned inr num,int pos)
{
 num = num ^ (1 << pos);
 return num;
}

13. Write a function to swap even bits with consecutive odd bits in a number.
e.g. b0 swapped with b1, b2 swapped with b3 and so on.

unsigned int swap_bits(unsigned int num)
{
  return (num >> 1 & 0x55555555) | (num << 1 & 0xAAAAAAAA);
}

14. Write a function to swap odd bits in a number.
e.g. b1 swapped with b3, b5 swapped with b7 and so on.

unsigned int swap_odd_bits(unsigned int num)
{

 return (num >> 2 & 0x22222222) |

         (num << 2 & 0x88888888) |

         ( num   & 0x55555555) ; 

}

15. Write a function to swap even bits in a number.
e.g. b0 swapped with b2, b4 swapped with b6 and so on.
unsigned int swap_even_bits(unsigned int num)
{
  return (num >> 2 & 0x11111111) |
         (num << 2 & 0x44444444) |
         ( num   & 0xAAAAAAAA);}
16. Write a function to find out the number of 1s in a number.

unsigned int num_of_ones(unsigned int num)
{
 if( (count_ones(num) & 1) 
  return ODD;
 else
  return EVEN;
}

17. Write a function for finding the first lowest bit set in a number.

unsigned int first_lowest_bit(unsigned num)
{
 int count =0;
 while(num) {
  count ++;
  if( (num) & 1 == 1)
   break;
  num = num >> 1;
 }
 return count;
}

18. Write a function for finding the higest bit set in a number.

unsigned int first_highest_bit(unsigned num)
{
 int count =0;
 while(num) {
  count ++;
  if( (num & (1 << 31) ) == 1)
   break;
  num = num << 31;
 return count;
}

19 Write a function for reversing the bits in a number.

unsigned int reverse_bit(unsigned num)
{
 unsigned int NO_OF_BITS = sizeof(num) * 8;
 unsigned int temp,rev=0;
 for(i=0; i <= NO_OF_BITS -1 ;i++) {
  if(temp) {
   rev |= (1 << ((NO_OF_BITS-1)-i);
 }
 return rev;
}

20. Write a code to extract nth to mth bit, where n
(num >> n) & ~(~ 0 << (m-n+1))

21. write a code for toggling nth to m bits,where n < m

num ^ ((~ 0 << n) & ( ~0 >> (31-m)))



22. Write a code for setting nth to mth bit, where n < m

num | ((~0 << n) & (~0 >>(31-m)))
23. write a code for clearing nth to mth bit, where n  < m

num & ~((~0 << n) & (~0 >> (31-m))) 

 

Link List Question:

 

1. How to check whether linked list is circular or not.

Ans:

  

struct node {

    int data;
    struct node *next;
};
struct node *head = NULL;

void checkcircular(struct node *head)
{
    struct node * slow = head;
    struct node * fast = head;
    while( fast && fast->next) {
        if(slow == fast->next->next) {
            printf("Circular\n');
            break;
        }
        else {           
            slow = slow->next;
            fast = fats->next->next;
        }
    }
}


2. How would you find a loop in a singly linked list?

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL:

void detectloop(struct node * head)
{
    struct node * slow = head;
    struct node * fast = head;
    while(slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            printf("Loop detected\n');
            break;
        }
    }
}

3. Write a C function to print the middle of a given linked list.

struct node {
    int data;
    struct node *next;
};

void findmiddle(struct node *head)
{
    struct node * slow = head;
    struct head * fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = slow->next->next;
    }
    printf(" Middle element is %d\n", slow->data);
}


4. Write a c program to get the intersection point of two singly linked lists.

struct node {
    int data;
    struct node *next;
};

struct node * head = NULL:

int count_node(struct node * head)
{
    int count = 0;
    struct node * current = head;
    while (current != NULL) {
        count ++;
        current = current->next;
    }
    return count;
}

struct get_intersection_mod(int d,struct node * head1, struct node * head2)
{
    struct node current1 = head1;
    struct node current2 = head2;
   
    for(i=0;i        cureent1 = current->next;
    }
    while(cuttent1 != NULL && current2 != NULL) {
        if(current1 == current2) {
            printf(" intersection node =%d\n", current1->data);
            break;
        }
        current1 = current1->next;
        current2 = current2->next;
    }
}

void get_intersecton(struct node * head1, struct node * head2)
{
    struct node *current = head1;
    struct node *current = head2;
    int c1, c2;
    c1 = count_node(current1);
    c2 = count_node(current2);
    if(c1 > c2) {
        d= c1 -c2;
        get_intersection_mod(d,head1,head2);
    }
    else {
        d = c2 -c1;
        get_intersection_mod(d, head1,head2);
    }
}

 Spin Lock In Linux Kernel
Why are spin locks good choices in Linux Kernel Design instead of something more common in userland code, such as semaphore or mutex?
 1. When spinlock is used ?
Ans: In the following situations.

    The thread that holds the lock is not allowed to sleep.
    The thread that is waiting for a lock does not sleep, but spins in a tight loop.

When properly used, spinlock can give higher performance than semaphore. Ex: Intrrrupt handler.
2. What are the rules to use spinlocks?
Ans:
Rule - 1: Any code that holds the spinlock, can not relinquish the processor for any reason except to service interrupts ( sometimes not even then). So code holding spinlock can not sleep.
Reason: suppose your driver holding spinlock goes to sleep. Ex: calls function copy_from_user() or copy_to_user(), or kernel preemption kicks in so higher priority process pushed your code aside. Effectively the process relinquishes the CPU holding spinlock.
Now we do not know when the code will release the lock. If some other thread tries to obtain the same lock, it would spin for very long time. In the worst case it would result in deedlock.
Kernel preemption case is handled by the spinlock code itself. Anytime kernel code holds a spinlock, preemption is disabled on the relevant processor. Even uniprocessor system must disable the preemption in this way.
Rule - 2: Disable interrupts on the local CPU, while the spinlock is held.
Reason: Support your driver take a spinlock that control access to the device and then issues an interrupt. This causes the interrupt handler to run. Now the interrupt handler also needs the lock to access the device. If the interrupt handler runs on the same processor, it will start spinning. The driver code also can not run to release the lock. SO the processor will spin for ever.
Rule - 3: Spinlocks must be held for the minimum time possible.
Reason: Long lock hold times also keeps the current processor from scheduling, meaning a higher priority process may have to wait to get the CPU.
So it impacts kernel latency (time a process may have to wait to be scheduled). Typically spinlocks should be held for the time duration, less than that CPU takes to do a contex switch between threads.
Rule -4: if you have semaphores and spinlocks both to be taken. Then take semaphore first and then spinlock.

 Memory Layout of C Programs
A typical memory representation of C program consists of following sections.


1. Text segment
2. Initialized data segment
3. Uninitialized data segment
4. Stack
5. Heap



A typical memory layout of a running process

1. Text Segment:
A text segment , also known as a code segment or simply as text, is one of the sections of a program in an object file or in memory, which contains executable instructions.
As a memory region, a text segment may be placed below the heap or stack in order to prevent heaps and stack overflows from overwriting it.
Usually, the text segment is sharable so that only a single copy needs to be in memory for frequently executed programs, such as text editors, the C compiler, the shells, and so on. Also, the text segment is often read-only, to prevent a program from 
accidentally modifying its instructions.

2. Initialized Data Segment:
Initialized data segment, usually called simply the Data Segment. A data segment is a portion of virtual address space of a program, which contains the global variables and static variables that are initialized by the programmer.
Note that, data segment is not read-only, since the values of the variables can be altered at run time.
This segment can be further classified into initialized read-only area and initialized read-write area.
For instance the global string defined by char s[] = “hello world” in C and a C statement like int debug=1 outside the main (i.e. global) would be stored in initialized read-write area. And a global C statement like const char* string = “hello world” makes the string literal “hello world” to be stored in initialized read-only area and the character pointer variable string in initialized read-write area.
Ex: static int i = 10 will be stored in data segment and global int i = 10 will also be stored in data segment

3. Uninitialized Data Segment:
Uninitialized data segment, often called the “bss” segment, named after an ancient assembler operator that stood for “block started by symbol.” Data in this segment is initialized by the kernel to arithmetic 0 before the program starts executing
uninitialized data starts at the end of the data segment and contains all global variables and static variables that are initialized to zero or do not have explicit initialization in source code.
For instance a variable declared static int i; would be contained in the BSS segment.
For instance a global variable declared int j; would be contained in the BSS segment.

4. Stack:
The stack area traditionally adjoined the heap area and grew the opposite direction; when the stack pointer met the heap pointer, free memory was exhausted. (With modern large address spaces and virtual memory techniques they may be placed almost anywhere, but they still typically grow opposite directions.)
The stack area contains the program stack, a LIFO structure, typically located in the higher parts of memory. On the standard PC x86 computer architecture it grows toward address zero; on some other architectures it grows the opposite direction. A “stack pointer” register tracks the top of the stack; it is adjusted each time a value is “pushed” onto the stack. The set of values pushed for one function call is termed a “stack frame”; A stack frame consists at minimum of a return address.
Stack, where automatic variables are stored, along with information that is saved each time a function is called. Each time a function is called, the address of where to return to and certain information about the caller’s environment, such as some of the machine registers, are saved on the stack. The newly called function then allocates room on the stack for its automatic and temporary variables. This is how recursive functions in C can work. Each time a recursive function calls itself, a new stack frame is used, so one set of variables doesn’t interfere with the variables from another instance of the function.

5. Heap:
Heap is the segment where dynamic memory allocation usually takes place.
The heap area begins at the end of the BSS segment and grows to larger addresses from there.The Heap area is managed by malloc, realloc, and free, which may use the brk and sbrk system calls to adjust its size (note that the use of brk/sbrk and a single “heap area” is not required to fulfill the contract of malloc/realloc/free; they may also be implemented using mmap to reserve potentially non-contiguous regions of virtual memory into the process’ virtual address space). The Heap area is shared by all shared libraries and dynamically loaded modules in a process.
Examples.
The size(1) command reports the sizes (in bytes) of the text, data, and bss segments. ( for more details please refer man page of size(1) )
1. Check the following simple C program
#include
 
int main(void)
{
    return 0;
}

[narendra@CentOS]$ gcc memory-layout.c -o memory-layout
[narendra@CentOS]$ size memory-layout
text       data        bss        dec        hex    filename
960        248          8       1216        4c0    memory-layout

2. Let us add one global variable in program, now check the size of bss (highlighted in red color).
#include
 
int global; /* Uninitialized variable stored in bss*/
 
int main(void)
{
    return 0;
}

[narendra@CentOS]$ gcc memory-layout.c -o memory-layout
[narendra@CentOS]$ size memory-layout
text       data        bss        dec        hex    filename
 960        248         12       1220        4c4    memory-layout

3. Let us add one static variable which is also stored in bss.
#include
 
int global; /* Uninitialized variable stored in bss*/
 
int main(void)
{
    static int i; /* Uninitialized static variable stored in bss */
    return 0;
}

[narendra@CentOS]$ gcc memory-layout.c -o memory-layout
[narendra@CentOS]$ size memory-layout
text       data        bss        dec        hex    filename
 960        248         16       1224        4c8    memory-layout

4. Let us initialize the static variable which will then be stored in Data Segment (DS)
#include
 
int global; /* Uninitialized variable stored in bss*/
 
int main(void)
{
    static int i = 100; /* Initialized static variable stored in DS*/
    return 0;
}

[narendra@CentOS]$ gcc memory-layout.c -o memory-layout
[narendra@CentOS]$ size memory-layout
text       data        bss        dec        hex    filename
960         252         12       1224        4c8    memory-layout

5. Let us initialize the global variable which will then be stored in Data Segment (DS)
#include
 
int global = 10; /* initialized global variable stored in DS*/
 
int main(void)
{
    static int i = 100; /* Initialized static variable stored in DS*/
    return 0;
}

[narendra@CentOS]$ gcc memory-layout.c -o memory-layout
[narendra@CentOS]$ size memory-layout
text       data        bss        dec        hex    filename
960         256          8       1224        4c8    memory-layout

 C String interview Question
1. What will be output when you will execute following c code?
#include
void main(){
char arr[7]="Network";
printf("%s",arr);
}
Explanation:
Size of a character array should one greater than total number of characters in any string which it stores. In c every string has one terminating null character. This represents end of the string.So in the string “Network” , there are 8 characters and they are ‘N’,’e’,’t’,’w’,’o’,’r’,’k’ and ‘\0’. Size of array arr is seven. So array arr will store only first sevent characters and it will note store null character.
As we know %s in prinf statement prints stream of characters until it doesn’t get first null character. Since array arr has not stored any null character so it will print garbage value.



2.What will be output when you will execute following c code?
#include
void main(){
    char arr[11]="The African Queen";
    printf("%s",arr);
}
Explanation:
Size of any character array cannot be less than the number of characters in any string which it has assigned. Size of an array can be equal (excluding null character) or greater than but never less than.

3.What will be output when you will execute following c code?
#include
void main(){
    int const SIZE=5;
    int expr;
    double value[SIZE]={2.0,4.0,6.0,8.0,10.0};
    expr=1|2|3|4;
    printf("%f",value[expr]);
}
Explanation:
Size of any array in c cannot be constantan variable.

4.What will be output when you will execute following c code?
#include
enum power{
    Dalai,
    Vladimir=3,
    Barack,
    Hillary
};
void main(){
    float leader[Dalai+Hillary]={1.f,2.f,3.f,4.f,5.f};
    enum power p=Barack;
    printf("%0.f",leader[p>>1+1]);
}
Explanation:
Size of an array can be enum constantan.
Value of enum constant Barack will equal to Vladimir + 1 = 3 +1 = 4
So, value of enum variable p  = 4
leader[p >> 1 +1]
= leader[4 >> 1+1]
=leader[4 >> 2]   //+ operator enjoy higher precedence than >> operator.
=leader[1]  //4>>2 = (4 / (2^2) = 4/4 = 1
=2

5.What will be output when you will execute following c code?
#include
#define var 3
void main(){
    char *cricket[var+~0]={"clarke","kallis"};
    char *ptr=cricket[1+~0];
    printf("%c",*++ptr);
}
Explanation:
In the expression of size of an array can have micro constant.
var +~0 = 3 + ~0 = 3 + (-1)  = 2
Let’s assume string “clarke” and “kallis” has stored at memory address 100 and 500 respectively as shown in the following figure:
For string “clarke”:
For string “kallis”:
In this program cricket is array of character’s pointer of size 2. So array cricket will keep the memory address of first character of both strings i.e. content of array cricket is:
cricket[2] = {100,500}
ptr is character pointer which is pointing to the fist element of array cricket. So, ptr = 100
Now consider on *++ptr
Since ptr = 100 so after ++ptr , ptr = 101
*(++ptr) = *(101) = content of memory address 101. From above figure it is clear that character is l.

6.What will be output when you will execute following c code?
#include
void main(){
    char data[2][3][2]={0,1,2,3,4,5,6,7,8,9,10,11};
    printf("%o",data[0][2][1]);
}
Explanation:
%o in printf statement is used to print number in the octal format.

7.What will be output when you will execute following c code?
#include
void main(){
    short num[3][2]={3,6,9,12,15,18};
    printf("%d  %d",*(num+1)[1],**(num+2));
}
Explanation:
*(num+1)[1]=*(*((num+1)+1))=*(*(num+2))=*(num[2])=num[2][0]=15And**(num+2)=*(num[2]+0)=num[2][0]=15

8.What will be output when you will execute following c code?
#include
void main(){
    char *ptr="cquestionbank";
    printf("%d",-3[ptr]);
}
Explanation:
-3[ptr]=-*(3+ptr)=-*(ptr+3)
=-ptr[3]
=-103  //ASCII value of character ‘e’ is 103

9.What will be output when you will execute following c code?
#include
void main(){
    long  myarr[2][4]={0l,1l,2l,3l,4l,5l,6l,7l};
    printf("%ld\t",myarr[1][2]);
    printf("%ld%ld\t",*(myarr[1]+3),3[myarr[1]]);
    printf("%ld%ld%ld\t" ,*(*(myarr+1)+2),*(1[myarr]+2),3[1[myarr]]); 
}
Explanation:
Think yourself.

10.What will be output when you will execute following c code?
#include
void main(){
    int array[2][3]={5,10,15,20,25,30};
    int (*ptr)[2][3]=&array;
    printf("%d\t",***ptr);
    printf("%d\t",***(ptr+1));
    printf("%d\t",**(*ptr+1));
    printf("%d\t",*(*(*ptr+1)+2));
}
Explanation:
ptr is pointer to two dimension array.
***ptr
=***&array  //ptr = &array
=**array //* and & always cancel to each other
=*arr[0]  // *array = *(array +0) = array[0]
=array[0][0]
= 5
Rests think yourself.

11.What will be output when you will execute following c code?
#include
void main(){
    static int a=2,b=4,c=8;
    static int *arr1[2]={&a,&b};
    static int *arr2[2]={&b,&c};
    int* (*arr[2])[2]={&arr1,&arr2};
    printf("%d %d\t",*(*arr[0])[1],  *(*(**(arr+1)+1)));
}
Explanation:
Consider on the following expression:
*(*arr[0])[1]
=*(*&arr1)[1]  //arr[0] = &arr1
=*arr1[1]   //* and & always cancel to each other
=*&b
=b
=4
Consider on following expression:
*(*(**(arr+1)+1))
= *(*(*arr[1]+1))  //*(arr+1) = arr[1]
= *(*(*&arr2+1))  //arr[1] = &arr2
=*(*(arr2+1))  //*&arr2 = arr2
=*(arr2[1])  //*(arr2+1) = arr2[1]
=  *&c    //arr2[1] = &c
=  c
= 8

12.What will be output when you will execute following c code?
#include
#include
double myfun(double);
void main(){
    double(*array[3])(double);
    array[0]=exp;
    array[1]=sqrt;
    array[2]=myfun;
    printf("%.1f\t",(*array)((*array[2])((**(array+1))(4)))); 
}
double myfun(double d){
       d-=1;
       return d;
}
Explanation:
array is array of pointer to such function which parameter is double type data and return type is double.
Consider on following expression:
(*array)((*array[2])((**(array+1))(4)))
= (*array)((*array[2])((*array[1])(4)))
//*(array+1) = array[1]
= (*array)((*array[2])(sqrt(4))))
//array[1] = address of sqrt function
= (*array)((*array[2])(2.000000)))
= (*array)(myfun(2.000000)))
// array[2] = address of myfunc function
=(*array)(1.000000)
=array[0](1.000000)
=exp(1.000000)

13.What will be output when you will execute following c code?
#include
typedef struct{
    char *name;
    double salary;
}job;
void main(){
    static job a={"TCS",15000.0};
    static job b={"IBM",25000.0};
    static job c={"Google",35000.0};
    int x=5;
    job * arr[3]={&a,&b,&c};
    printf("%s  %f\t",(3,x>>5-4)[*arr]);
}
double myfun(double d){
       d-=1;
       return d;
}
Explanation:
(3,5>>5-4)[*arr]
=(3,5>>5-4)[*arr] //x=5
= (3,5>>1)[*arr] //- operator enjoy higher precedence than >>
= (3,2)[*arr]  //5>>1 = 5/(2^1) = 5 /2 = 2
= 2[*arr]  //In c comma is also operator.
= *(2 + *arr)
= *(*arr + 2)
=*arr[2]
=*(&c) //arr[2] = &c
=c   // *  and & always cancel to each other.
So,
printf("%s  %f\t",c);
=> printf("%s  %f\t", "Google",35000.0);

14.What will be output when you will execute following c code?
#include
union group{
    char xarr[2][2];
    char yarr[4];
};
void main(){
    union group x={'A','B','C','D'};
    printf("%c",x.xarr[x.yarr[2]-67][x.yarr[3]-67]);
}
Explanation:
In union all member variables share common memory space.
So union member variable, array xarray will look like:
{
{‘A’,’B’},
{‘C’,’D’}
}
And union member variable, array yarray will look like:
{
{‘A’,’B’,’C’,’D’}
}
x.xarr[x.yarr[2]-67][x.yarr[3]-67]
= x.xarr[‘C’-67][‘D’-67]
= x.xarr[67-67][68-67]
//ASCII value of ‘C’ is 67 and ‘D’ is 68.
x.xarr[0][1]
=’B’

15.What will be output when you will execute following c code?
#include
void main(){
    int a=5,b=10,c=15;
    int *arr[3]={&a,&b,&c};
    printf("%d",*arr[*arr[1]-8]);
}
Explanation:
Member of an array cannot be address of auto variable because array gets memory at load time while auto variable gets memory at run time.

16.What will be output when you will execute following c code?
#include
void main(){
    int arr[][3]={{1,2},{3,4,5},{5}};
    printf("%d %d %d",sizeof(arr),arr[0][2],arr[1][2]);
}
Explanation:
If we will not write size of first member of any array at the time of declaration then size of the first dimension is max elements in the initialization of array of that dimension.
So, size of first dimension in above question is 3.
So size of array = (size of int) * (total number of elements) = 2 *(3*3) = 18
Default initial value of rest elements are zero.  So above array will look like:
{
{1,2,0}
{3,4,5},
{5,0,0}
}         

17.What will be output when you will execute following c code?
#include
void main(){
    int xxx[10]={5};
    printf("%d %d",xxx[1],xxx[9]);
}
Explanation:
If we initialize any array at the time of declaration the compiler will treat such array as static variable and its default value of uninitialized member is zero.

18.What will be output when you will execute following c code?
#include
#define WWW -1
enum {cat,rat};
void main(){
    int Dhoni[]={2,'b',0x3,01001,'\x1d','\111',rat,WWW};
    int i;
    for(i=0;i<8 i="" span="">
         printf(" %d",Dhoni[i]);
}
Explanation:
Dhoni[0]=2
Dhoni[1]=’b’ =98  //ASCII value of character ‘b’ is 98.
Dhoni[2]=  0x3  =  3  //0x represents hexadecimal number. Decimal value of hexadecimal 3 is also 3.
Dhoni[3]=01001 = 513 //Number begins with 0 represents octal number.
Dhoni[4]  = ‘\x1d’ = 29 //’\x1d’ is hexadecimal character constant.
Dhoni[5] = ‘\111’ = 73 //’\111’ is octal character constant.
Dhoni[6] =rat = 1  //rat is enum constant
Dhoni[7] = WWW = -1  //WWW is macro constant.


19.What will be output when you will execute following c code?
#include
void main(){
    long double a;
    signed char b;
    int arr[sizeof(!a+b)];
    printf("%d",sizeof(arr));
}
Explanation:
Size of data type in TURBO C 3.0 compiler is:
S.N.
Data type
Size(In byte)
1
char
1
2
int
2
3
double
8
Consider on the expression: !a + b
! Operator always return zero if a is non-zero number other wisie 1. In general we can say ! operator always returns an int type number. So
!a +b
=! (Any double type number) + Any character type number
= Any integer type number + any character type number
= Any integer type number
Note: In any expression lower type data is always automatically type casted into the higher data type. In this case char data type is automatically type casted into the int type data.
So sizeof (!a +b) = sizeof(Any int type number)  = 2
So size of array arr is 2 and its data type is int. So
sizeof(arr) = size of array * sizeof its data type = 2* 2= 4


20.What will be output when you will execute following c code?
#include
void main(){
    char array[]="Ashfaq \0 Kayani";
    char *str="Ashfaq \0 Kayani";
    printf("%s %c\n",array,array[2]);
    printf("%s %c\n",str,str[2]);
    printf("%d %d\n",sizeof(array),sizeof(str));
}
Explanation:
A character array keeps the each element of an assigned array but a character pointer always keeps the memory address of first element. 
As we know %s in prints the characters of stream until it doesn’t any null character (‘\0’).  So first and second printf function will print same thing in the above program.  
But size of array is total numbers of its elements i.e. 16 byte (including ending null character). While size of any type of pointer is 2 byte (near pointer).
	
The information about platform drivers is one on LWN. What we can learn from this page:

    Platform devices are inherently not discoverable, i.e. the hardware cannot say "Hey! I'm present!" to the software. Typical examples are i2c devices, kernel/Documentation/i2c/instantiating-devices states:
	Unlike PCI or USB devices, I2C devices are not enumerated at the hardware level (at run time). Instead, the software must know (at compile time) which devices are connected on each I2C bus segment. 
	So USB and PCI are not platform devices.
    Platform devices are bound to drivers by matching names,
    Platform devices should be registered very early during system boot. Because they are often critical to the rest of the system (platform) and its drivers.

So basically, the question "is it a platform device or a standard device?" is more a question of which bus it uses. To work with a particular platform device, you have to:

    register a platform driver that will manage this device. It should define a unique name,
    register your platform device, defining the same name as the driver.

    Are platform drivers for those devices that are on chip ??

Not true (in theory, but true in practice). i2c devices are not onChip, but are platform devices because they are not discoverable. Also we can think of onChip devices which are normal devices. 
Example: an integrated PCI GPU chip on a modern x86 processor. It is discoverable, thus not a platform device.

    Are normal device drivers for those that are interfaced to the processor chip. before coming across one i2c driver ??

Not true. Many normal devices are interfaced to the processor, but not through an i2c bus. Example: a USB mouse

    What's the difference between OS and Linux device drivers?
    What are the differences between High Level Device Driver and Low Level Device Driver?
    What is the difference between hardware abstraction layer and a device driver?
    What is the difference between library and device drivers? Isn't both the same
    What is the difference between a device driver and an API?
    How do I design user-space device drivers in Linux?
    What's the difference between Unix and Linux device drivers?
    What is the difference between device driver and device controllers?
    What are frequently asked questions in Linux device drivers?
    What is the difference between block drivers and network device drivers?
    What is the difference between user-space and kernel-space device drivers in Linux?
    What are device drivers?
    What's the best way to learn device driver development on Linux?
    What is device driver programming?
    How do I develop Device Drivers?
    What's the prerequisite to learn device drivers?
    Which one is better windows device driver or linux device driver programming for career?
    What is the definition of 'device driver'?
    How to design device driver for your own interfacing device ?
    What is the process of writing a device driver?

How do I make an array of complex number in C?
http://c-faq.com/~scs/cgi-bin/faqcat.cgi?sec=ptrs

 Qualcomm Interview Questions

How many interrupt lines you have been used in your driver development.
UART : 1 (RX)
Ethernet: 2 (RX & TX)
I2C : what is I2C Clock Stretch, Bus line clear.

How do u debug when an process aborted.

How many Exceptions are there in ARM.

what are the methods or functions to raise execute the interrupt process when interrupt occurs.


C-Questions
1) Find the size of a structure with out size of operator.

struct  XYZ{
    int x;
    float y;
    char z;
};

int main(){
    struct XYZ arr[2];
    int sz = (char*)&arr[1] - (char*)&arr[0];
    printf("%d",sz);
    return 0;
}


OS
2) what is the output of the below program
    Function(void)
   {
     fork(); fork(); fork();
    printf("Hello world");
   }
ans: Hello world will be printed for 8 times.

L&T Interview Questions:

1) Timer Interrupts and related drivers.
2) How to delete similar nodes from a linked list, not by traversing every node.
3) ARM Internal Architecture.
4) Power Management Techniques - Experience.
5) Explain me any driver you worked on.
6) Interrupt based driver.
7) Advantages and disadvantages of Polling & Interrupt drivers.
8) Android Frame work.
9) What are the different modes in ARM.
10) How a interrupt will be handled  in Linux.
11) What is the difference between IRQ & FIQ.


Work:
1) Touch screen Device drivers.
2) USB Device driver Experience.
3) Power Management Techniques.



Some more questions:
1.how the synchronisation works in single processor system(spinlock_irq_save).
2.how external devices access the physical address.
3.can we access the variable in all the functions below

func1()
func2()
static int a;
func3()
func4()


func1()
func2()
int a;
func3()
func4()

4.why stack is always in higher location.
5. what is the difference between global and static
6. have u debug any issues using jtag/ any other debugger.
if yes, how can we get the call stack in the debugger.

 Strings Interview Q&A - c language
. What is the difference between a string copy (strcpy) and a memory copy (memcpy)? When should each be used?
The strcpy() function is designed to work exclusively with strings. It copies each byte of the source string to the destination string and stops when the terminating null character (\0) has been moved. On the other hand, the memcpy() function is designed to work with any type of data.
Because not all data ends with a null character, you must provide the memcpy() function with the number of bytes you want to copy from the source to the destination. The following program shows examples of both thestrcpy() and the memcpy() functions:

#include <stdio.h>
#include <string.h>
typedef struct cust_str {
     int  id;
     char last_name[20];
     char first_name[15];
} CUSTREC;
void main(void);
void main(void)
{
     char*   src_string = "This is the source string";
     char    dest_string[50];
     CUSTREC src_cust;
     CUSTREC dest_cust;
     printf("Hello!  I'm going to copy src_string into dest_string!\n");
     /* Copy src_string into dest_string. Notice that the destination
        string is the first argument. Notice also that the strcpy()
        function returns a pointer to the destination string. */
     printf("Done! dest_string is: %s\n",
            strcpy(dest_string, src_string));
     printf("Encore! Let's copy one CUSTREC to another.\n");
     printf("I'll copy src_cust into dest_cust.\n");
     /* First, initialize the src_cust data members. */
     src_cust.id = 1;
     strcpy(src_cust.last_name, "Strahan");
     strcpy(src_cust.first_name, "Troy");
     /* Now, use the memcpy() function to copy the src_cust structure to
        the dest_cust structure. Notice that, just as with strcpy(), the
        destination comes first. */
     memcpy(&dest_cust, &src_cust, sizeof(CUSTREC));
     printf("Done! I just copied customer number #%d (%s %s).",
               dest_cust.id, dest_cust.first_name, dest_cust.last_name);
}

When dealing with strings, you generally should use the strcpy() function, because it is easier to use with strings. When dealing with abstract data other than strings (such as structures), you should use the memcpy()function.
2. How can I remove the trailing spaces from a string?
The C language does not provide a standard function that removes trailing spaces from a string. It is easy, however, to build your own function to do just this. The following program uses a custom function namedrtrim() to remove the trailing spaces from a string. It carries out this action by iterating through the string backward, starting at the character before the terminating null character (\0) and ending when it finds the first nonspace character. When the program finds a nonspace character, it sets the next character in the string to the terminating null character (\0), thereby effectively eliminating all the trailing blanks. Here is how this task is performed:

#include <stdio.h>
#include <string.h>
void main(void);
char* rtrim(char*);
void main(void)
{
     char* trail_str = "This string has trailing spaces in it.               ";
     /* Show the status of the string before calling the rtrim()
        function. */
     printf("Before calling rtrim(), trail_str is '%s'\n", trail_str);
     printf("and has a length of %d.\n", strlen(trail_str));
     /* Call the rtrim() function to remove the trailing blanks. */
     rtrim(trail_str);
     /* Show the status of the string
        after calling the rtrim() function. */
     printf("After calling rtrim(), trail_str is '%s'\n", trail_str);
     printf("and has a length of %d.\n", strlen(trail_str));
}
/* The rtrim() function removes trailing spaces from a string. */
char* rtrim(char* str)
{
int n = strlen(str) - 1;     /* Start at the character BEFORE
                                     the null character (\0). */
     while (n>0)            /* Make sure we don't go out of bounds... */
     {
          if (*(str+n) != ' ')    /*  If we find a nonspace character: */
          {
               *(str+n+1) = '\0'; /* Put the null character at one
                                     character past our current
                                     position. */
               break;             /* Break out of the loop. */
          }
          else      /* Otherwise, keep moving backward in the string. */
               n--;
     }
     return str;                  /* Return a pointer to the string. */
}

Notice that the rtrim() function works because in C, strings are terminated by the null character. With the insertion of a null character after the last nonspace character, the string is considered terminated at that point, and all characters beyond the null character are ignored.


--------------------------------------------------------------
3. How can I remove the leading spaces from a string?
The C language does not provide a standard function that removes leading spaces from a string. It is easy, however, to build your own function to do just this. you can easily construct a custom function that uses thertrim() function in conjunction with the standard C library function strrev() to remove the leading spaces from a string. Look at how this task is performed:

#include <stdio.h>
#include <string.h>
void main(void);
char* ltrim(char*);
char* rtrim(char*);
void main(void)
{
     char* lead_str = "          This string has leading spaces in it.";
     /* Show the status of the string before calling the ltrim()
        function. */
     printf("Before calling ltrim(), lead_str is '%s'\n", lead_str);
     printf("and has a length of %d.\n", strlen(lead_str));
     /* Call the ltrim() function to remove the leading blanks. */
     ltrim(lead_str);
     /* Show the status of the string
        after calling the ltrim() function. */
     printf("After calling ltrim(), lead_str is '%s'\n", lead_str);
     printf("and has a length of %d.\n", strlen(lead_str));
}
/* The ltrim() function removes leading spaces from a string. */
char* ltrim(char* str)
{
     strrev(str);    /* Call strrev() to reverse the string. */
     rtrim(str);     /* Call rtrim() to remove the "trailing" spaces. */
     strrev(str);    /* Restore the string's original order. */
     return str;     /* Return a pointer to the string. */
}
/* The rtrim() function removes trailing spaces from a string. */
char* rtrim(char* str)
{
     int n = strlen(str) - 1;     /* Start at the character BEFORE
                                     the null character (\0). */
     while (n>0)            /* Make sure we don't go out of bounds... */
     {
          if (*(str+n) != ' ')    /* If we find a nonspace character: */
          {
               *(str+n+1) = '\0'; /* Put the null character at one
                                     character past our current
                                     position. */
               break;             /* Break out of the loop. */
          }
          else      /* Otherwise, keep moving backward in the string. */
               n--;
     }
     return str;                  /* Return a pointer to the string. */
}

Notice that the ltrim() function performs the following tasks: First, it calls the standard C library functionstrrev(), which reverses the string that is passed to it. This action puts the original string in reverse order, thereby creating "trailing spaces" rather than leading spaces. Now, the rtrim() function is used to remove the "trailing spaces" from the string. After this task is done, the strrev() function is called again to "reverse" the string, thereby putting it back in its original order.
4. How can I right-justify a string?
Even though the C language does not provide a standard function that right-justifies a string, you can easily build your own function to perform this action. Using the rtrim() function, you can create your own function to take a string and right-justify it. Here is how this task is accomplished:

#include <stdio.h>
#include <string.h>
#include <malloc.h>
void main(void);
char* rjust(char*);
char* rtrim(char*);
void main(void)
{
     char* rjust_str = "This string is not right-justified.                  ";
     /* Show the status of the string before calling the rjust()
        function. */
     printf("Before calling rjust(), rjust_str is '%s'\n.", rjust_str);
     /* Call the rjust() function to right-justify this string. */
     rjust(rjust_str);
     /* Show the status of the string
        after calling the rjust() function. */
     printf("After calling rjust(), rjust_str is '%s'\n.", rjust_str);
}
/* The rjust() function right-justifies a string. */
char* rjust(char* str)
{
     int n = strlen(str);   /* Save the original length of the string. */
     char* dup_str;
     dup_str = strdup(str);  /* Make an exact duplicate of the string. */
     rtrim(dup_str);         /* Trim off the trailing spaces. */
     /* Call sprintf() to do a virtual "printf" back into the original
        string. By passing sprintf() the length of the original string,
        we force the output to be the same size as the original, and by
        default the sprintf() right-justifies the output. The sprintf()
        function fills the beginning of the string with spaces to make
        it the same size as the original string. */
     sprintf(str, "%*.*s", n, n, dup_str);
     free(dup_str);    /* Free the memory taken by
                          the duplicated string. */
     return str;       /* Return a pointer to the string. */
}
/* The rtrim() function removes trailing spaces from a string. */
char* rtrim(char* str)
{
     int n = strlen(str) - 1;  /* Start at the character BEFORE the null
                                  character (\0). */
     while (n>0)            /* Make sure we don't go out of bounds... */
     {
          if (*(str+n) != ' ')    /* If we find a nonspace character: */
          {
               *(str+n+1) = '\0'; /* Put the null character at one
                                     character past our current
                                     position. */
               break;             /* Break out of the loop. */
          }
          else      /* Otherwise, keep moving backward in the string. */
               n--;
     }
     return str;                   /* Return a pointer to the string. */
}

The rjust() function first saves the length of the original string in a variable named n. This step is needed because the output string must be the same length as the input string. Next, the rjust() function calls the standard C library function named strdup() to create a duplicate of the original string. A duplicate of the string is required because the original version of the string is going to be overwritten with a right-justified version. After the duplicate string is created, a call to the rtrim() function is invoked (using the duplicate string, not the original), which eliminates all trailing spaces from the duplicate string.
Next, the standard C library function sprintf() is called to rewrite the new string to its original place in memory. The sprintf() function is passed the original length of the string (stored in n), thereby forcing the output string to be the same length as the original. Because sprintf() by default right-justifies string output, the output string is filled with leading spaces to make it the same size as the original string. This has the effect of right-justifying the input string. Finally, because the strdup() function dynamically allocates memory, thefree() function is called to free up the memory taken by the duplicate string.

----------------------------------------------------------
5. How can I pad a string to a known length?
Padding strings to a fixed length can be handy when you are printing fixed-length data such as tables or spreadsheets. You can easily perform this task using the printf() function. The following example program shows how to accomplish this task:

#include <stdio.h>
char *data[25] = {
     "REGION", "--Q1--",    "--Q2--",   "--Q3--", "  --Q4--",
     "North", "10090.50", "12200.10", "26653.12", "62634.32",
     "South", "21662.37", "95843.23", "23788.23", "48279.28",
     "East", "23889.38", "23789.05", "89432.84", "29874.48",
     "West", "85933.82", "74373.23", "78457.23", "28799.84" };
void main(void);
void main(void)
{
     int x;
     for (x=0; x<25; x++)
     {
          if ((x % 5) == 0 && (x != 0))
               printf("\n");
          printf("%-10.10s", data[x]);
     }
}

In this example, a character array (char* data[]) is filled with this year's sales data for four regions. Of course, you would want to print this data in an orderly fashion, not just print one figure after the other with no formatting. This being the case, the following statement is used to print the data:
printf("%-10.10s", data[x]);
The "%-10.10s" argument tells the printf() function that you are printing a string and you want to force it to be 10 characters long. By default, the string is right-justified, but by including the minus sign (-) before the first 10, you tell the printf() function to left-justify your string. This action forces the printf() function to pad the string with spaces to make it 10 characters long. The result is a clean, formatted spreadsheet-like
output:

REGION      --Q1--   --Q2--     --Q3--    --Q4--
North      10090.50  12200.10  26653.12  62634.32
South      21662.37  95843.23  23788.23  48279.28
East       23889.38  23789.05  89432.84  29874.48
West       85933.82  74373.23  78457.23  28799.84

6. How can I copy just a portion of a string?
You can use the standard C library function strncpy() to copy one portion of a string into another string. Thestrncpy() function takes three arguments: the first argument is the destination string, the second argument is the source string, and the third argument is an integer representing the number of characters you want to copy from the source string to the destination string. For example, consider the following program, which uses thestrncpy() function to copy portions of one string to another:

#include <stdio.h>
#include <string.h>
void main(void);
void main(void)
{
     char* source_str = "THIS IS THE SOURCE STRING";
     char dest_str1[40] = {0}, dest_str2[40] = {0};
     /* Use strncpy() to copy only the first 11 characters. */
     strncpy(dest_str1, source_str, 11);
     printf("How about that! dest_str1 is now: '%s'!!!\n", dest_str1);
     /* Now, use strncpy() to copy only the last 13 characters. */
     strncpy(dest_str2, source_str + (strlen(source_str) - 13), 13);
     printf("Whoa! dest_str2 is now: '%s'!!!\n", dest_str2);
}

The first call to strncpy() in this example program copies the first 11 characters of the source string intodest_str1. This example is fairly straightforward, one you might use often. The second call is a bit more complicated and deserves some explanation. In the second argument to the strncpy() function call, the total length of the source_str string is calculated (using the strlen() function). Then, 13 (the number of characters you want to print) is subtracted from the total length of source_str. This gives the number of remaining characters in source_str. This number is then added to the address of source_str to give a pointer to an address in the source string that is 13 characters from the end of source_str.
Then, for the last argument, the number 13 is specified to denote that 13 characters are to be copied out of the string. The combination of these three arguments in the second call to strncpy() sets dest_str2 equal to the last 13 characters of source_str.
The example program prints the following output:

How about that! dest_str1 is now: 'THIS IS THE'!!!
Whoa! dest_str2 is now: 'SOURCE STRING'!!!

Notice that before source_str was copied to dest_str1 and dest_st2, dest_str1 and dest_str2 had to be initialized to null characters (\0). This is because the strncpy() function does not automatically append a null character to the string you are copying to. Therefore, you must ensure that you have put the null character after the string you have copied, or else you might wind up with garbage being printed.


7. How can I convert a number to a string?
The standard C library provides several functions for converting numbers of all formats (integers, longs, floats, and so on) to strings and vice versa. One of these functions, itoa(), is used here to illustrate how an integer is converted to a string:

#include <stdio.h>
#include <stdlib.h>
void main(void);
void main(void)
{
     int num = 100;
     char str[25];
     itoa(num, str, 10);
     printf("The number 'num' is %d and the string 'str' is %s.\n",
                 num, str);
}

Notice that the itoa() function takes three arguments: the first argument is the number you want to convert to the string, the second is the destination string to put the converted number into, and the third is the base, or radix, to be used when converting the number. The preceding example uses the common base 10 to convert the number to the string.
The following functions can be used to convert integers to strings:
Function Name		Purpose
itoa()	-	Converts an integer value to a string.
ltoa()	-	Converts a long integer value to a string.
ultoa()	-	Converts an unsigned long integer value to a string.
Note that the itoa(), ltoa(), and ultoa() functions are not ANSI compatible. An alternative way to convert an integer to a string (that is ANSI compatible) is to use the sprintf() function, as in the following example:

#include <stdio.h>
#include <stdlib.h>
void main(void);
void main(void)
{
     int num = 100;
     char str[25];
     sprintf(str, "%d", num);
     printf("The number 'num' is %d and the string 'str' is %s.\n",
                 num, str);
}

When floating-point numbers are being converted, a different set of functions must be used. Here is an example of a program that uses the standard C library function fcvt() to convert a floating-point value to a string:

#include <stdio.h>
#include <stdlib.h>
void main(void);
void main(void)
{
     double num = 12345.678;
     char* str;
     int dec_pl, sign, ndigits = 3;    /* Keep 3 digits of precision. */
     str = fcvt(num, ndigits, &dec_pl, &sign);  /* Convert the float
                                                           to a string. */
     printf("Original number:  %f\n", num);     /* Print the original
                                                   floating-point
                                                   value. */
     printf("Converted string: %s\n", str);     /* Print the converted
                                                   string's value */
     printf("Decimal place:    %d\n", dec_pl);  /* Print the location of
                                                   the decimal point. */
     printf("Sign:             %d\n", sign);    /* Print the sign.
                                                   0 = positive,
                                                   1 = negative. */
}

Notice that the fcvt() function is quite different from the itoa() function used previously. The fcvt() function takes four arguments. The first argument is the floating-point value you want to convert. The second argument is the number of digits to be stored to the right of the decimal point. The third argument is a pointer to an integer that is used to return the position of the decimal point in the converted string. The fourth argument is a pointer to an integer that is used to return the sign of the converted number (0 is positive, 1 is negative).
Note that the converted string does not contain the actual decimal point. Instead, the fcvt() returns the position of the decimal point as it would have been if it were in the string. In the preceding example, the dec_pl integer variable contains the number 5 because the decimal point is located after the fifth digit in the resulting string. If you wanted the resulting string to include the decimal point, you could use the gcvt() function (described in the following table).
The following functions can be used to convert floating-point values to strings:
Function		Purpose
ecvt()	-	Converts a double-precision floating-point value to a string without an embedded decimal point.
fcvt()	-	Same as ecvt(), but forces the precision to a specified number of digits.
gcvt()	-	Converts a double-precision floating-point value to a string with an embedded decimal point.
8. How can I convert a string to a number?
The standard C library provides several functions for converting strings to numbers of all formats (integers, longs, floats, and so on) and vice versa. One of these functions, atoi(), is used here to illustrate how a string is converted to an integer:

#include <stdio.h>
#include <stdlib.h>
void main(void);
{
     int num;
     char* str = "100";
     num = atoi(str);
     printf("The string 'str' is %s and the number 'num' is %d.\n",
                 str, num);
}

To use the atoi() function, you simply pass it the string containing the number you want to convert. The return value from the atoi() function is the converted integer value.
The following functions can be used to convert strings to numbers:
Function Name		Purpose
atof()	-	Converts a string to a double-precision floating-point value.
atoi()	-	Converts a string to an integer.
atol()	-	Converts a string to a long integer.
strtod()	-	Converts a string to a double-precision floating-point value and reports any "leftover" numbers that could not be converted.
strtol()	-	Converts a string to a long integer and reports any "leftover" numbers that could not be converted.
strtoul()	-	Converts a string to an unsigned long integer and reports any "leftover" numbers that could not be converted.
Sometimes, you might want to trap overflow errors that can occur when converting a string to a number that results in an overflow condition. The following program shows an example of the strtoul() function, which traps this overflow condition:

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
void main(void);
void main(void)
{
     char* str  = "1234567891011121314151617181920";
     unsigned long num;
     char* leftover;
     num = strtoul(str, &leftover, 10);
     printf("Original string:      %s\n", str);
     printf("Converted number:     %lu\n", num);
     printf("Leftover characters:  %s\n", leftover);
}

In this example, the string to be converted is much too large to fit into an unsigned long integer variable. Thestrtoul() function therefore returns ULONG_MAX (4294967295) and sets the char* leftover to point to the character in the string that caused it to overflow. It also sets the global variable errno to ERANGE to notify the caller of the function that an overflow condition has occurred. The strtod() and strtol() functions work exactly the same way as the strtoul() function shown above. Refer to your C compiler documentation for more information regarding the syntax of these functions.


9. How can you tell whether two strings are the same?
The standard C library provides several functions to compare two strings to see whether they are the same. One of these functions, strcmp(), is used here to show how this task is accomplished:

#include <stdio.h>
#include <string.h>
void main(void);
void main(void)
{
     char* str_1 = "abc";
     char* str_2 = "abc";
     char* str_3 = "ABC";
     if (strcmp(str_1, str_2) == 0)
          printf("str_1 is equal to str_2.\n");
     else
          printf("str_1 is not equal to str_2.\n");
     if (strcmp(str_1, str_3) == 0)
          printf("str_1 is equal to str_3.\n");
     else
          printf("str_1 is not equal to str_3.\n");
}

This program produces the following output:
str_1 is equal to str_2.
str_1 is not equal to str_3.
Notice that the strcmp() function is passed two arguments that correspond to the two strings you want to compare. It performs a case-sensitive lexicographic comparison of the two strings and returns one of the following values:
Return Value		Meaning
<0	-	The first string is less than the second string.
0	-	The two strings are equal.
>0	-	The first string is greater than the second string.
In the preceding example code, strcmp() returns 0 when comparing str_1 (which is "abc") and str_2 (which is "abc"). However, when comparing str_1 (which is "abc") with str_3 (which is "ABC"), strcmp() returns a value greater than 0, because the string "ABC" is greater than (in ASCII order) the string "abc".
Many variations of the strcmp() function perform the same basic function (comparing two strings), but with slight differences. The following table lists some of the functions available that are similar to strcmp():
Function Name		Description
strcmp()	-	Case-sensitive comparison of two strings
strcmpi()	-	Case-insensitive comparison of two strings
stricmp()	-	Same as strcmpi()
strncmp()	-	Case-sensitive comparison of a portion of two strings
strnicmp()	-	Case-insensitive comparison of a portion of two strings
Looking at the example provided previously, if you were to replace the call to strcmp() with a call tostrcmpi() (a case-insensitive version of strcmp()), the two strings "abc" and "ABC" would be reported as being equal.
10. How do you print only part of a string?
The following program shows how to print only part of a string using the printf() function:

#include <stdio.h>
#include <string.h>
void main(void);
void main(void)
{
     char* source_str = "THIS IS THE SOURCE STRING";
     /* Use printf() to print the first 11 characters of source_str. */
     printf("First 11 characters: '%11.11s'\n", source_str);
     /* Use printf() to print only the
        last 13 characters of source_str. */
     printf("Last 13 characters: '%13.13s'\n",
                 source_str + (strlen(source_str) - 13));
}

This example program produces the following output:
First 11 characters: 'THIS IS THE'
Last 13 characters: 'SOURCE STRING'
The first call to printf() uses the argument "%11.11s" to force the printf() function to make the output exactly 11 characters long. Because the source string is longer than 11 characters, it is truncated, and only the first 11 characters are printed. The second call to printf() is a bit more tricky. The total length of thesource_str string is calculated (using the strlen() function). Then, 13 (the number of characters you want to print) is subtracted from the total length of source_str.
This gives the number of remaining characters in source_str. This number is then added to the address of source_str to give a pointer to an address in the source string that is 13 characters from the end ofsource_str. By using the argument "%13.13s", the program forces the output to be exactly 13 characters long, and thus the last 13 characters of the string are printed.


Finding a linked list that is either circular or not circular ?
Try using 2 pointers:

2 pointers travelling at different speeds start from the 
head of the linked list
Iterate through a loop
If the faster pointer reaches a NULL pointer then return
saying that the list is acyclic and not circular
If the faster pointer is ever equal to the slower pointer or the
faster pointer's next pointer is ever equal to the slower pointer
then return that the list is circular

Advance the slower pointer one node
Advance the faster pointer by 2 nodes

Tortoise and hare(rabbit) algorithm:
The above pseudo code is called Tortoise and rabbit algorithm

bool findCircular(Node *head)
{
   Node *slower, * faster;
   slower = head;
   faster = head->next; //start faster one node ahead
   while(true) {
   
     // if the faster pointer encounters a NULL element
     if( !faster || !faster->next)
       return false;
    //if faster pointer ever equals slower or faster's next
    //pointer is ever equal to slow then it's a circular list
     else if (faster == slower || faster->next == slower)
        return true;
     else{
       // advance the pointers
        slower = slower->next;
        faster = faster->next->next;
      }
   }
}


Memory-mapped I/O (MMIO) and port mapped I/O ?

Memory-mapped I/O (MMIO) and port I/O (also called port-mapped I/O or PMIO) are two complementary methods of performing input/output between the CPU and I/O devices in a computer. Another method is using dedicated I/O processors (channels, used in IBM mainframe computers).
Memory-mapped I/O uses the same bus to address both memory and I/O devices, and the CPU instructions used to read and write to memory are also used in accessing I/O devices. In order to accommodate the I/O devices, areas of CPU addressable space must be reserved for I/O rather than memory. This does not have to be permanent, for example the Commodore 64 could bank switch between its I/O devices and regular memory. The I/O devices monitor the CPU's address bus and respond to any CPU access of their assigned address space, mapping the address to their hardware registers.
Port-mapped I/O uses a special class of CPU instructions specifically for performing I/O. This is generally found on Intel microprocessors, specifically the IN and OUT instructions which can read and write a single byte to an I/O device. I/O devices have a separate address space from general memory, either accomplished by an extra "I/O" pin on the CPU's physical interface, or an entire bus dedicated to I/O.
Relative merits of the two I/O methods
The main advantage of using port-mapped I/O is on CPUs with a limited addressing capability. Because port-mapped I/O separates I/O access from memory access, the full address space can be used for memory. It is also obvious to a person reading an assembly language program listing when I/O is being performed, due to the special instructions that can only be used for that purpose.
The advantage of using memory mapped I/O is that, by discarding the extra complexity that port I/O brings, a CPU requires less internal logic and is thus cheaper, faster and easier to build; this follows the basic tenets of reduced instruction set computing. As 16-bit CPU architectures have become obsolete and replaced with 32-bit and 64-bit architectures in general use, reserving space on the memory map for I/O devices is no longer a problem. The fact that regular memory instructions are used to address devices also means that all of the CPU's addressing modes are available for the I/O as well as the memory.
Example
Consider a simple system built around an 8-bit microprocessor. Such a CPU might provide 16-bit address lines, allowing it to address up to 64K bytes (65,535 bytes) of memory. On such a system, perhaps the first 32K of address space would be allotted to Random access memory (RAM), a further 16K to Read only memory (ROM) and the remainder to a variety of other devices such as timers, counters, video display chips, sound generating devices, and so forth. The hardware of the system is arranged so that devices on the address bus will only respond to particular addresses which are intended for them; all other addreses are ignored. This is the job of the address decoding circuitry, and it is this that establishes the memory map of the system. Some very simple decoding circuitry might allow a device to respond to several different addresses, effectively creating virtual copies of the device at different places in the memory map. Of course there is only one real device, so there is no particular advantage in doing this, except to simplify the decoder. The decoding itself may be programmable, allowing the system to reconfigure its own memory map as required. This is commonly done.


http://embedded-thoughts.blogspot.in/2013/02/serial-subsystemuart.html

Qualcomm

1. what is your work in your company?
ans:-i work on the device drivers presently I am working on input subsystem.

2. what is your current project?
Ans: I am working on input sub system right now.

3. what you had done in that project ?
Ans:-my role in that project is to know how the kernel and the hardware is able to communicate and what are the devices that comes under the input subsystem and what are the protocols they are using.

4. explain boot sequence of omap?
ans:- explain in detail about the ROM code,X loader,u-boot and kernel.for more details click here http://omappedia.org/wiki/Bootloader_Project

6. What kind of implementations that your company doing?
ans:here we have to describe about the company presently we are working and should have a good idea about the projects it has undertaken and its clients.

2. what is machine dependent and independent code? Example
Ans:-the code that could run on a particular platform is called machine dependent where as if a code is able to run on any platform then the code is said to be machine independent code.

3. why we use volatile?
Ans:-In computer programming, particularly in the C, C++, and C# programming languages, a variable or object declared with the volatile keyword usually has special properties related to optimization and/or threading. Generally speaking, the volatile keyword is intended to prevent the (pseudo)compiler from applying any optimizations on the code that assume values of variables cannot change “on their own.”

4. what is Static variable?
Ans:-In computer programming, a static variable is a variable that has been allocated statically whose lifetime or extent extends across the entire run of the program. This is in contrast to the more ephemeral atomic variables (local variables are generally automatic), whose storage is allocated and deallocated on the call stack; and in contrast to objects whose storage is dynamically allocated in heap memory.

5. write a program to print size of integer variable without using sizeof operator ?
6. write a program to find repeated character in a given string? code should be generic?

7. Implement string reverse program without using temporary buffer and strrev function?
//not using any temp variable and assume we can use only string array and length

8. how do you transfer data from userspace to kernel space?
Ans:- with the help of copy_to_user and copy_from_user.

9. What is generic system call that is used to transfer data from user space to kernel space?
Ans:-ioctl is used along with put_user and get_user to transfer the data from user space to kernel space.

10. write a program to copy a string from source to destination without using strcpy?code should be optimised to only three lines?

