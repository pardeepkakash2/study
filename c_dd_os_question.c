Multicore processor:
Will increasing the number of cores, increase the throughput of your system ?
What are the general methods of communication between the cores ?
When is it better to use single core processor compared to multi-core processor ?
If the CPU in a multi-core processor updates the data in the cache, copies of data in caches associated with other cores will become stale. How is the multicore processor designed to handle this scenario ?
What is 'Run to Completion' software architecture ?
What is a 'Pipelined' software architecture ?
What is the difference between 'Run to Completion' and 'Pipelined' software architecture ?
How is the debugging and testing environment in the case of multithreaded/multiprocessing applications ?
At what point does adding more processors or computers to the computation pool slow things down instead of speeding them up?
Is there an optimal number of processors for any given parallel program?
How Many Processes or Threads are enough for an application ?
What is difference between micro processor & micro controller?

Kernel:
What are monolithic and micro kernels and what are the differences between them?
	Monolithic kernel is a single large processes running entirely in a single address space. 
	It is a single static binary file. All kernel services exist and execute in kernel address space.
	Monolithic kernels are UNIX , LINUX.
	
	In Microkernels, the kernel is broken down into separate processes, known as servers. 
	Some of the servers run in kernel space and some run in user-space.Microkernel are QNX , L4 , HURD.


	Monolithic kernel are faster than microkernel . While The first microkernel Mach is 50% slower than Monolithic 
		kernel while later version like L4 only 2% or 4% slower than the Monolithic kernel .
	Monolithic kernel generally are bulky . While Pure monolithic kernel has to be small in size even fit in s into 
		processor first level cache (first generation microkernel).
	Monolithic kernel device driver reside in the kernel space . While In the Microkernel device driver reside in the user space.
	Since the device driver reside in the kernel space it make monolithic kernel less secure than microkernel . (Failure in the 
		driver may lead to crash) While Microkernels are more secure than the monolithic kernel hence used in some military devices.
	Monolithic kernels use signals and sockets to ensure IPC while microkernel approach uses message queues . 
		1 gen of microkernel poorly implemented IPC so were slow on context switches.
	Adding new feature to a monolithic system means recompiling the whole kernel While You can add new feature or patches 
		without recompiling.

Normal OS vs RTOS ? What is the difference between hard real-time and soft real-time OS? What type of scheduling is there in RTOS?
	RTOS: http://careerride.com/embedded-systems-interview-questions.aspx
	In an operating system, there is a module called the scheduler, which schedules different tasks and determines when a process 
		will execute on the processor. This way, the multi-tasking is achieved. 
	The scheduler in a Real Time Operating System (RTOS) is designed to provide a predictable execution pattern. In an embedded 
		system, a certain event must be entertained in strictly defined time.
	To meet real time requirements, the behaviour of the scheduler must be predictable. This type of OS which have a scheduler 
		with predictable execution pattern is called Real Time OS(RTOS). The features of an RTOS are

    Context switching latency should be short.
    Interrupt latency should be short.
    Interrupt dispatch latency should be short.
    Reliable and time bound inter process mechanisms.
    Should support kernel preemption.
	Compatibility with several plugin devices.
	Deterministic operating system having guaranteed worst-case interrupt latency and context-switch times.
	Documentation providing for the minimum, average, and maximum number of clock cycles required by each system call.
	Overall it should be very reliable.

	A Hard real-time system strictly adheres to the deadline associated with the task. If the system fails to meet the deadline, 
		even once, the system is considered to have failed. 
	In case of a soft real-time system, missing a deadline is acceptable. In this type of system, a critical real-time task 
		gets priority over other tasks and retains that priority until it completes
	
	RTOS uses pre-emptive scheduling
	
What is a linux kernel ? is it a process or thread? 
	Linux Kernel is a passive component of the OS. It does not execute, neither it is a process/thread. It itself has many 
	subsystem and could be called with system call API/Interrupt that helps in executing the user space process in system space 
	for more privileged access, either to I/O or any subsystem.

What is a Loadable Kernel Module?
	Modules are pieces of code that can be loaded and unloaded into the kernel upon demand. They extend the functionality 
	of the kernel without the need to reboot the system.

What is difference between the Process and the thread ?
Process:
    An executing instance of a program is called a process. Some operating systems use the term task to refer to a program 
	that is being executed.
    A process is always stored in the main memory also termed as the primary memory or random access memory.Therefore, a process is 
	termed as an active entity. It disappears if the machine is rebooted.
    Several process may be associated with a same program.
    On a multiprocessor system, multiple processes can be executed in parallel.On a uni-processor system, though true parallelism is 
	not achieved, a process scheduling algorithm is applied and the processor is scheduled to execute each process one at a 
	time yielding an illusion of concurrency.
    Example: Executing multiple instances of the Calculator program. Each of the instances are termed as a process.

Thread:
    A thread is a subset of the process.It is termed as a lightweight process, since it is similar to a real process but executes 
	within the context of a process and shares the same resources allotted to the process by the kernel
    Usually, a process has only one thread of control one set of machine instructions executing at a time.
    A process may also be made up of multiple threads of execution that execute instructions concurrently.
    Multiple threads of control can exploit the true parallelism possible on multiprocessor systems.
    On a uni-processor system, a thread scheduling algorithm is applied and the processor is scheduled to run each thread one at a time.
    All the threads running within a process share the same address space, file descriptor, stack and other process related attributes.
    Since the threads of a process share the same memory, synchronizing the access to the shared data withing the process 
	gains unprecedented importance.

The major difference between threads and processes is:
    Threads share the address space of the process that created it; processes have their own address space.
    Threads have direct access to the data segment of its process; processes have their own copy of the data segment of the parent process.
    Threads can directly communicate with other threads of its process; processes must use interprocess communication to communicate 
	with sibling processes.
    Threads have almost no overhead; processes have considerable overhead.
    New threads are easily created; new processes require duplication of the parent process.
    Threads can exercise considerable control over threads of the same process; processes can only exercise control over child processes.
    Changes to the main thread (cancellation, priority change, etc.) may affect the behavior of the other threads of the process; 
	changes to the parent process does not affect child processes.

What is a user thread and a kernel thread?
Number of kernel threads = cores?
Maximum number of threads per process in Linux?
	cat /proc/sys/kernel/threads-max
	There is also a limit on the number of processes (an hence threads) that a single user may create, see ulimit/getrlimit
	Linux implements max number of threads per process indirectly!!
	number of threads = total virtual memory / (stack size*1024*1024)
	ulimit -s
	
insmod vs modeprobe ?

	modprobe: reads the modules from /lib/modules/$(uname -r)/modules.dep.bin (or without the .bin suffix if the other file is not
	available). From the same file, dependencies are loaded.

	modprobe accepts the name of a .ko file in /lib/modules/$(uname -r) and aliases (modules.alias.bin). 
	Builtins (modules.alias.bin) are recognized as well, but since these modules are loaded by default, there is not 
		point in modprobing this kind of modules.

	insmod: on the other hand accepts paths to files. The module does not have to reside in /lib/modules/$(uname -r), but dependencies
		are not automatically loaded. This is the lower program used by modprobe to load modules.

	rmmod: removes a kernel name based on the name from /proc/modules. This name does not necessarily have to be the same as 
		the one passed to modprobe.
	modinfo: accepts a filename, or the filename without .ko suffix in /lib/modules/$(uname -r).
	depmod : Creates the data base of module dependencies. This is created based on the information present 
		in /lib/modules/module.dep file.
	lsmod  : lists the modules already loaded into kernel.

Explain the module loading in Linux?
	A module can be loaded to Linux Kernel in two ways
	1. Statically
	2. Dynamically

	Static loading means that the module is loaded in the memory with the kernel loading itself.

	Dynamic loading means that the module is loaded into the kernel at the run time.
	The command that is used to achieve it is insmod.

	The user must have the root permission to do so.
	e.g sudo insmod test.ko 


How to Pass Command Line Arguments to a Kernel Module?
	http://learnlinuxconcepts.blogspot.in/2014/03/how-to-pass-command-line-arguments-to.html	
	The module_param() macro takes 3 arguments: 
		arg1 : The name of the variable.
		arg2 : Its type
		arg3 : Permissions for the corresponding file in sysfs. 
	
	module_param_array(myarr, int, &arr_argc, 0);
	MODULE_PARM_DESC() macro used for giving the description of variable.

	command: insmod *.ko variable=value

	Use Cases of Module Parameters:
	When there is a need to change the irq line of the module then its the best way to pass the irq number 
		as command line argument using module parameter concept.
	Base address of the register map of a module can be passed at module load time using insmod based on this command line arguments.

Why do we need two bootloaders viz. primary and secondary?
	When the system starts the BootROM has no idea about the external RAM. It can only access the Internal RAM of the the CPU. 
	So the BootROM loads the primary bootloader from the boot media (flash memory) into the internal RAM. 
	The main job of the primary bootloader is to detect the external RAM and load the secondary bootloader into it. 
	After this, the secondary bootloader starts its execution.

Given a pid, how will you distinguish if it is a process or a thread ? 
	Do ps -AL | grep pid
	1st column is parent id and the second column is thread (LWP) id. if both are same then its a process id otherwise thread.

Memory-mapped I/O (MMIO) and port mapped I/O ?
	Memory-mapped I/O (MMIO) and port I/O (also called port-mapped I/O or PMIO) are two complementary methods of performing input/output between the CPU and I/O devices in a computer. 
		Another method is using dedicated I/O processors (channels, used in IBM mainframe computers).
	Memory-mapped I/O uses the same bus to address both memory and I/O devices, and the CPU instructions used to read and write to memory are also used in accessing I/O devices. 
		In order to accommodate the I/O devices, areas of CPU addressable space must be reserved for I/O rather than memory. This does not have to be permanent, 
		for example the Commodore 64 could bank switch between its I/O devices and regular memory. The I/O devices monitor the CPU's address bus and respond to any CPU access of their assigned address space, 
		mapping the address to their hardware registers.

	Port-mapped I/O uses a special class of CPU instructions specifically for performing I/O. This is generally found on Intel microprocessors, specifically the IN and OUT instructions 
		which can read and write a single byte to an I/O device. I/O devices have a separate address space from general memory, either accomplished by an extra "I/O" pin 
		on the CPU's physical interface, or an entire bus dedicated to I/O.

	Relative merits of the two I/O methods
		The main advantage of using port-mapped I/O is on CPUs with a limited addressing capability. Because port-mapped I/O separates I/O access from memory access, 
		the full address space can be used for memory. It is also obvious to a person reading an assembly language program listing when I/O is being performed, 
		due to the special instructions that can only be used for that purpose.
	The advantage of using memory mapped I/O is that, by discarding the extra complexity that port I/O brings, a CPU requires less internal logic and is thus cheaper, 
		faster and easier to build; this follows the basic tenets of reduced instruction set computing. As 16-bit CPU architectures have become obsolete and replaced with 32-bit 
		and 64-bit architectures in general use, reserving space on the memory map for I/O devices is no longer a problem. The fact that regular memory instructions are used to address 
		devices also means that all of the CPU's addressing modes are available for the I/O as well as the memory.
		Example
		Consider a simple system built around an 8-bit microprocessor. Such a CPU might provide 16-bit address lines, allowing it to address up to 64K bytes (65,535 bytes) of memory. 
		On such a system, perhaps the first 32K of address space would be allotted to Random access memory (RAM), a further 16K to Read only memory (ROM) and the remainder to a variety of 
		other devices such as timers, counters, video display chips, sound generating devices, and so forth. The hardware of the system is arranged so that devices on the address bus will only 
		respond to particular addresses which are intended for them; all other addreses are ignored. This is the job of the address decoding circuitry, and it is this that establishes the memory map of the system. 
		Some very simple decoding circuitry might allow a device to respond to several different addresses, effectively creating virtual copies of the device at different places in the memory map. 
		Of course there is only one real device, so there is no particular advantage in doing this, except to simplify the decoder. The decoding itself may be programmable, allowing the system to 
		reconfigure its own memory map as required. This is commonly done.

How to decrease the time of booting processes?

However, could you point me out where the kernel actually detects the device? Is it keep polling with the driver's name which was given
	at compile time? Or Is there other mechanism to detect the device? Basically, how the
	kernel detects those devices, which calls "probe"?

	Platform devices represent devices that are usually integrated into a given chip and therefore are always there. 
	The platform-specific initialization code statically initializes such arrays of platform devices and then registers them in 
	a row using platform_register. Therefore there is no need for sophisticated probing. Instead, the string contained 
	in platform_device.name is compared platform_driver.driver.name and a match is assumed if they are equal.

	Other buses have more sophisticated detection/probing methods. For more information about platform devices, including the places
	where these functions are called, see drivers/base/platform.c. Read Documentation/driver-model/platform.txt.

Why is the probe method needed in Linux device drivers in addition to init?
	The driver's init function calls pci_register_driver() which gives the kernel a list of devices it is able to service, along with 
	a pointer to the probe() function. The kernel then calls the driver's probe() function once for each device.

	This probe function starts the per-device initialization: initializing hardware, allocating resources, and registering the 
	device with the kernel as a block or network device or whatever it is.

	That makes it easier for device drivers, because they never need to search for devices or worry about finding a device that was 
	hot-plugged. The kernel handles that part and notifies the right driver when it has a device for you to handle.

	For a "platform" device the probe function is invoked when a platform device is registered and it's device name matches with the 
	compatible string or name specified on the device driver and device tree.
	https://www.kernel.org/doc/Documentation/i2c/writing-clients.

	1. The starting trigger function for the driver -> probe() callback is the module_init() macro called while loading the driver; 
		the macro is defined in `include/linux/module.h`.
	2. module_init(my_driver_init) has the callback to my_driver_init() function. my_driver_init() function should have a call 
		to platform_driver_register(my_driver).
	3. platform_driver_register(my_driver) assigns my_driver -> probe() handle to generic drv -> probe() and calls the 
		driver_register(my_driver) function.
	4. driver_register(my_driver) function adds my_driver to the platform bus and calls driver_attach() function.
    	5. In the same way, even the platform_device needs to attach to the platform bus.
	6. Finally, only if the driver_match_device() returns success based on the .name & .id_table of the driver matches in the platform
	devices list that comes either from ACPI/DTS, then the driver_probe_device() gets called that has the drv -> probe() callback.

how to know frequesntly used comman function ?
	Take any kernel modules and identify all the symbols within, extracting only the API that is NOT declared inside the 
	kernel modules: nm xxx.ko | grep “ U “, where “U” indicate that the function is not declared in the kernel module, thus belong 
	to the generic class of external kernel API function.

	nm *.ko | grep “ U “ | sort | uniq -c | sort -n (number on the left indicate the frequency count).

what are the common encountered issues while devplopment of device driver ?
	https://www.quora.com/Linux-Kernel-What-are-the-commonly-encountered-issues-in-development-of-Device-Drivers
	There are quite a lot of issues that can pop up especially in device driver development, few of the prominent ones are:
	Timing /Device Initialization issues
	Driver Lock up/Synchronization issues
	Interrupt/GPIO handling
	Performance Issues
	Memory issues

	Timing /Device Initialization issues:
	Most of the peripheral devices have specific timing requirement on various operations such as power on/off, IO, initialization etc.

	This shows timing constraints on power sequence for this IC, w.r.t the display data, interfacing bus line status, power lines 
	and so, if these constraints are not met from the corresponding driver, it may result in quite a few problem; for instance

    	the IC may send invalid data to the LVDS connected display hence making it show some garbage screen - momentarily
    	Or the power consumption by IC may go for a toss
    	or even the IC power on/off may not happen properly causing it to enter an indeterminate state and so on

	Similar timing constraint will be there on I/O Operations as well.
	Another key factor would be initialization sequence or commands, of a particular device - certain commands should be sent to the 
	IC to initialize its operational modes(for e.g: in case of displays, its refresh rates, resolution etc.)So the driver developer
	need to ensure that these timing & initialization sequences are also met .

	Driver Lockup:

    	Most of the driver are makes use of threads or workqueue - which would be initiated to process some requests from userspace 
	or events/interrupts from peripheral.
   	For synchronization between each thread/work-queue some primitives such as mutex would be used.
    	With poor implementation , of synchronization primitives or corner cases, this would result in lock up between threads and 
	worst cases complete stall of the process or even panic(if watchdog or any debug system is being used)
    	So while driver implementation put in effort for identifying such pain points for careful design ensuring proper synchronization
	(Consider points on performance issues as well) .

	Interrupt/GPIO handling:

    	Most of external peripherals (to an SoC or processor) will have an interrupt line connected - via a GPIO interface
    	The behaviour of this line would differ across peripherals. For e.g.:
        Trigger - Level or edge triggered
        Edge - rising or falling edge
    	If the GPIO interupt controller is configured with wrong interrupt detection logic, it would result in either no interrupt being
	detected or spurious interrupts to be triggered.
   	Another similar problem would be wrong configuration for a pin e.g.
    		configuring as an input while the intended function was to be output
       		configuring alternate function for the pin when it is expected to be a GPIO

	Performance issues:

	performance issues in driver can be addressed with proper design decisions i.e. when to use polling an interrupt modes of 
	operation on devices

	Some devices will have limited buffers (or FIFO) registers to hold data in I/O operations, so in order to properly handle 
	I/O requests from userspace we need to carefully design data structures and associated processing in kernel drivers. For e.g:

    	In case of GPU interface driver in kernel, the driver will play some role in process context management as well as per 
	process command queue management
    	This may also have associated buffer queue handling, prioritization and synchronization as well.
    	So the driver need to be designed & implemented considering all the necessary points.
    	If not done properly, the application through put (in case of GPU - FPS ) will be affected.

	Memory Issues:
	excessive usage of kernel memory APIs for granular allocation will result in fragmentation
    	In case the hardware has any IOMMU for address translation in a peripheral device - take care of memory mapping and unmapping 
		via provided API set - otherwise will result in page fault for memory operations by the designated peripheral
    	When buffers are shared between userspace or kernel (such as overlays or frame buffer), proper
        Synchronization of buffer access between kernel & userspace
        Allocation API usage
        IOMMU or related api usage
        Caching parameters

	There are even more issues, like:

    	Peripheral lock up - firmware malfunction
    	Bus hang up (if a peripheral is holding a shared bus in case of malfunction) or arbitration issue - which might have 
	resulted because of improper request or sequence from driver
    	Improper LDO or power supply configuration in terms of - voltage level or related parameters
    	IO memory mapping

	handling hardware errors: If your device is interrupt driven, then there are chances of excessive spurious interrupts when 
	device starts misbehaving. Interrupt handler should be written in such a way that spurious interrupts are either ignored or 
	blocked(if possible). Otherwise system will spend all its time processing interrupts.

	Memory : If you are expecting lots of operations with each operation requiring some memory to hold data structures, 
	use slab allocator instead f kmalloc all the time. Using kmalloc excessively for different size requests will fragment 
	kernel address space. Using slab will reduce external fragmentation to minimum.

	Performance: Choose interrupt v/s polling wisely. If your device has DMA capabilities, it is better to switch to polling 
	and look for all completed requests at once rather than getting interrupt for each completed request.

what are some common traps and pitfalls in development of Linux based device drivers?
How is a data sheet important, while developing Linux Device Driver, and how is it used?

What are the generic system call that is used to transfer data from user space to kernel space and vice versa?
	http://wiki.tldp.org/kernel_user_space_howto

	File system based communication:
	Procfs, Sysfs, Configfs, Debugfs, Sysctl, Character Devices.
 
	socket based communication:
	netlink socket, TCP/IP, UDP
	http://amsekharkernel.blogspot.in/2012/01/what-are-ways-of-communication-bw-user.html

	Procfs:
	procfs.c:        legacy procfs API
	Seq_file: 	API		https://lwn.net/Articles/22355/
					https://kernelnewbies.org/Documents/SeqFileHowTo
	sysfs:
	Sysfs was designed to represent the whole device model as seen from the Linux kernel. It contains information about devices,
	drivers and buses and their interconnections.

	sys/block/ all known block devices such as hda/ ram/ sda/
	sys/bus/ all registered buses. Each directory below bus/ holds by default two subdirectories:
		o device/ for all devices attached to that bus o driver/ for all drivers assigned with that bus. 
	sys/class/ for each device type there is a subdirectory: for example /printer or /sound
	sys/device/ all devices known by the kernel, organised by the bus they are connected to
	sys/firmware/ files in this directory handle the firmware of some hardware devices
	sys/fs/ files to control a file system, currently used by FUSE, a user space file system implementation
	sys/kernel/ holds directories (mount points) for other filesystems such as debugfs, securityfs.
	sys/module/ each kernel module loaded is represented with a directory.
	sys/power/ files to handle the power state of some hardware 

	debugfs:
	Debugfs is a simple to use RAM based file system especially designed for debugging purposes. Developers are encouraged to use
	debugfs instead of procfs in order to obtain some debugging information from their kernel code. Debugfs is quite flexible: it
	provides the possibility to set or get a single value with the help of just one line of code but the developer is also allowed 
	to write its own read/write functions, and he can use the seq_file interface.
	
	mount -t debugfs none /sys/kernel/debug
	debugfs.c       kernel module that implements the "one line" API for a variable of type u8 as well as the API 
		with which you can specify your own read and write functions.
	Sysctl:
	The sysctl infrastructure is designed to configure kernel parameters at run time. The sysctl interface is heavily used by the 
	Linux networking subsystem. It can be used to configure some core kernel parameters; represented as files in /proc/sys/.
	In order to change the values permanently they have to be written to the file /etc/sysctl.conf.

	sysctl.c        sysctl example module: write an integer to /proc/sys/net/test/value1 and value2 respectively

	Socket Based Mechanisms:
	AF_INET: designed for network communication, but UDP sockets can also be used for the communication between a kernel module 
		and the user space. The use of UDP sockets for node local communication involves a lot of overhead. 
	AF_NETLINK (netlink sockets): They are especially designed for the communication between the kernel space and the user space. 
	There are different netlink socket types currently implemented in the kernel, all of which deal with a specific subset of 
	the networking part of the Linux kernel.

	Ioctl:	ioctl is used along with put_user and get_user to transfer the data from user space to kernel space.
	ioctl.c  kernel module that uses ioctl in combination with a character device.The ioctl allows to send a message of up to 200 bytes.
	ioctl_user.c    user space program that uses ioctl to send a message to the kernel

	Kernel System Calls:
	System calls are used when a user space program wants to use some data or some service provided by the Linux kernel.	

	Sending Signals from the Kernel to the User Space:
	since only the kernel can send a signal to the user space, but not vice versa.

	signal_kernel.c kernel module that sends a signal to a user space process. The kernel needs to know the PID of the user space
		process. Therefore the user space process writes its PID in the debugfs file signalconfpid.
	signal_user.c   user space program that receives the signal.

	Upcall:
	The upcall functionality of the Linux kernel allows a kernel module to invoke a function in user space. It is possible to start a
	program in user space, and give it some command line arguments, as well as setting environment variables. 

	usermodehelper.c        kernel module that starts a process
	callee.c        user space program that will be executed on behalf of the kernel

	Mmap:	
	Memory mapping is the only way to transfer data between user and kernel spaces that does not involve explicit copying, and is 
	the fastest way to handle large amounts of data. 

	/dev/mem is a character device file that is an image of the main memory of the computer. It may be used.
	Byte addresses in mem are interpreted as physical memory addresses.


	mmap_simple_kernel.c    kernel module that provides the mmap system call based on debugfs.
	mmap_user.c     user space program that will share a memory area with the kernel module

	Kernel Module:
	charcater driver

	kernel API :	https://www.ibm.com/developerworks/library/l-kernel-memory-access/index.html
	access_ok	Checks the validity of the user space memory pointer
	get_user	Gets a simple variable from user space
	put_user	Puts a simple variable to user space
	clear_user	Clears, or zeros, a block in user space
	copy_to_user	Copies a block of data from the kernel to user space
	copy_from_user	Copies a block of data from user space to the kernel
	strnlen_user	Gets the size of a string buffer in user space
	strncpy_from_user	Copies a string from user space into the kernel

	
what does the probe() method, that the driver provides, do? How different is it from the driver init function, 
i.e. why cant the probe() functions actions be performed in the driver init function ?

	Different device types can have probe() functions. For example, PCI and USB devices both have probe() functions.
	Shorter answer, assuming PCI: The driver init function calls pci_register_driver() which gives the kernel a list of devices it is able to service,
	along with a pointer to the probe() function. The kernel then calls the driver probe() function once for each device.

	This probe function starts the per-device initialization: initializing hardware, allocating resources, and registering the device with the kernel as a block 
	or network device or whatever it is.That makes it easier for device drivers, because they never need to search for devices or worry about finding a device 
	that was hot-plugged. The kernel handles that part and notifies the right driver when it has a device for you to handle.
	
What is the difference beteween kernel modules and kernel drivers?

	A kernel module is a bit of compiled code that can be inserted into the kernel at run-time, such as with insmod or modprobe.
            A driver is a bit of code that runs in the kernel to talk to some hardware device. It drives the hardware. Most every bit of hardware in your computer 
			has an associated driver[*]. A large part of a running kernel is driver code; the rest of the code provides generic services like memory management, IPC, 
			scheduling, etc.

	A driver may be built statically into the kernel file on disk. (The one in /boot, loaded into RAM at boot time by the boot loader early in the boot process.) 
	A driver may also be built as a kernel module so that it can be dynamically loaded later. (And then maybe unloaded.)

	Standard practice is to build drivers as kernel modules where possible, rather than link them statically to the kernel, since that gives more flexibility. 
		There are good reasons not to, however:
		Sometimes a given driver is absolutely necessary to help the system boot up. That doesn't happen as often as you might imagine, due to the initrd feature.
		Statically built drivers may be exactly what you want in a system that is statically scoped, such as an embedded system. That is to say, 
			if you know in advance exactly which drivers will always be needed and that this will never change, you have a good reason not to bother with dynamic kernel modules.

	Not all kernel modules are drivers. For example, a relatively recent feature in the Linux kernel is that you can load a different process scheduler.
	[*] One exception to this broad statement is the CPU chip, which has no driver per se. Your computer may also contain hardware for which you have no driver.
	Courtesy: http://unix.stackexchange.com/questions/47208/what-is-the-difference-between-kernel-drivers-and-kernel-modules

What is the purpose of WFI and WFE instructions and the event signals ?
	We have 2 instructions for entering low-power standby state where most clocks are gated: WFI and WFE. 

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

What is Thrashing
What is DMA. Modes - cycle stealing/burst (blk transfer)/transparent
Cache coherency during dma. Which component handles it

MM - Segmentation, paging, swapping?
How context switching is handled in linux.
what is user preemption and kernel preemption?
what is task_struct thread_info?
how system calls are implemented in linux.
what is callback function? signal vs callback ?
What happens when recursive functions are declared inline?
What is a stack frame, stack pointer & frame pointer ?
is linux kernel a thread, process or something else?

When does the control passes from user mode to kernel mode in a Linux System? 
	System calls ,H/w Interrupts and last which I did not mention was Exceptions
	
device tree:
https://saurabhsengarblog.wordpress.com/2015/11/28/device-tree-tutorial-arm/
explain device tree concept ?
	Device tree is a data structure that describes the hardware and is passed to the kernel at boot time.
	different boards can be supported without recompiling the kernel only by writing the dtbs.

	The linux kernel requires the entire description of the hardware, like which board it is booting(machine type), which 
	all devices it is using there addresses(device/bus addresses), there interrupts numbers(irq), mfp pins configuration
	(pin muxing/gpios)  also some board level information like memory size, kernel command line etc etc …

	Before device tree, all these information use to be set in a huge cluster of board files. And, Information like command line,
	memory size etc use to be passed by bootloaders as part of ATAGS through register R2(ARM). Machine type use to be set separately 
	in register R1(ARM).
	At this time each kernel compilation use to be for only one specific chip an a specific board.

	So there was a long pending wish to compile the kernel for all ARM processors, and let the kernel somehow detect its hardware 
	and apply the right drivers as needed just like your PC.
	But how? On a PC, the initial registers are hardcoded, and the rest of the information is supplied by the BIOS. 
	But ARM processors don’t have a BIOS.
	The solution chosen was device tree, also referred to as Open Firmware (abbreviated OF) or Flattened Device Tree (FDT). 
	This is essentially a data structure in byte code format which contains information that is helpful to the kernel when booting up.

	The bootloader now loads two binaries: the kernel image and the DTB.
	DTB is the device tree blob. The bootloader passes the DTB address through R2 instead of ATAGS and R1 register is not required now.

	For a one line bookish definition “A device tree is a tree data structure with nodes that describe the physical devices in a system”

	Currently device tree is supported by ARM, x86, Microblaze, PowerPC, and Sparc architectures.

	Device Tree Compilation:
	Device tree compiler and its source code  located at scripts/dtc/.
	On ARM all device tree source are located at /arch/arm/boot/dts/.
	The Device Tree Blob(.dtb) is produced by the compiler, and it is the binary that gets loaded by the bootloader and parsed 
	by the kernel at boot time.
	scripts/dtc/dtc -I dts -O dtb -o /path/my_tree.dtb /arch/arm/boot/dts/my_tree.dts
	
	For creating the dts from dtb:
	scripts/dtc/dtc -I dtb -O dts -o /path/my_tree.dts /path/my_tree.dtb

	dts api:
	of_address_to_resource: Reads the memory address of device defined by res property
	irq_of_parse_and_map: Attach the interrupt handler, provided by the properties interrupt and interrupt-parent
	of_find_property(np, propname, NULL): To find if property named in argument2 is present or not.
	of_property_read_bool: To read a bool property named in argument 2, as it is a bool property it just like searching 
		if that property present or not. Returns true or false

	of_get_property: For reading any property named in argument 2
	of_property_read_u32: To read a 32 bit property, populate into 3rd argument. Doesn’t set anything to 3rd argument in case of error.
	of_property_read_string: To read string property
	of_match_device: Sanity check for device that device is matching with the node, highly optional, I don’t see much use of it.


interrupt:
how the synchronisation works in single processor system(spinlock_irq_save)?
how external devices access the physical address?
Advantages and disadvantages of Polling & Interrupt drivers.
Difference between Timer Softirq and Tasklet Softirq ?
what is top halves and bottom halves [tasklets , softirq and workqueus].
what are the considerations needs to taken care while writing interrupt handler.
what are shared handlers.
what is interrupt context.
what is ksoftirqd.
difference between exceptions and signals and interrupt.
How do you register an interrupt handler on a shared IRQ line?
What is request_threaded_irq()
If same interrupts occurs in two cpu how are they handled?
How to synchronize data between 'two interrupts' and 'interrupts and process'.
How are nested interrupts handled?
Explain about the concurrent work queues.
diff b/w interrupt, signal,isr and callback ?
What happens if interrupt handler goes to sleep?
How to protect variable between two interrupt handlers?
How to protect variable between task and interrupt handler?
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
What are the possible scenarios in which context switching of threads can occur ?
What will happen if there are more threads requesting for CPU resource such as time ?
While writing interrupt handlers(ISR), which are points needed to be considered?
What is preemption ?
What do you mean by atomic operations ?
What is ISR? Can they be passed any parameter and can they return a value? can we use printf, break point, function call or any blocking or sleep call or floating operation in ISR?
How CPUs find the ISR and distinguish between the various devices ?
Is it possible for two devices to share an interrupt request line but have different ISR for those two devices ?
What is difference between binary semaphore and mutex?
What is the use of file->private_data in a device driver structure ?
poll vs epoll ?
Difference between Timer Softirq and Tasklet Softirq ?
What are tasklets ? How are they activated ? when and How are they initialized ?

How many interrupt lines you have been used in your driver development.
	UART : 1 (RX)
	Ethernet: 2 (RX & TX)
	I2C : what is I2C Clock Stretch, Bus line clear.

How do u debug when an process aborted.
How many Exceptions are there in ARM.
what are the methods or functions to raise execute the interrupt process when interrupt occurs.

Why Kernel Code running in interrupt context cannot sleep? 	
	This is because the kernel design architecture wants it to be like this. Why so?
	This is because interrupt context is not considered to be a process.So, it can't sleep.The interrupt code is 
	doing some work on behalf of process and if slept then it will not only lead to the blocking of interrupt code 
	but also the process that has called it .

When should one use Polling and when should one use Interrupts?

	Both the mechanisms have their own pluses and minuses.
	We should use interrupts when we know that our event of interest is-
		1. Asynchronous
		2. Important(urgent).
		3. Less frequent
	We should use polling when we know that our event of interest is-
		1. Synchronous
		2. Not so important
		3. Frequent(our polling routine should encounter events more than not)

What is the difference between IRQ and FIQ in case of ARM? 
	ARM treats FIQ(Fast interrupt request) at a higher priority as compared to IRQ(interrupt request). 
	When an IRQ is executing an FIQ can interrupt it while vice versa is not true.

	ARM uses a dedicated banked out register for FIQ mode ; register numbers R8-R12.
	http://learnlinuxconcepts.blogspot.in/2014/06/arm-architecture.html
	So when an FIQ comes these registers are directly swapped with the normal working register and the CPU need not take 
	the pain of storing these registers in the stack. So it makes it faster.

	One more point worth noting is that  the FIQ is located at the end of exception vector table(0X1c) which means that 
	the code can run directly from 0X1C and this saves few cycles on entry to the ISR.

Explain interrupt latency and how can we decrease it?
	1. Interrupt latency basically refers to the time span an interrupt is generated and it being serviced by an appropriate 
		routine defined, usually the interrupt handler.
	2. External signals, some condition in the program or by the occurrence of some event, these could be the reasons 
		for generation of an interrupt.
	3. Interrupts can also be masked so as to ignore them even if an event occurs for which a routine has to be executed.
	4. Following steps could be followed to reduce the latency
	- ISRs being simple and short.
	- Interrupts being serviced immediately
	- Avoiding those instructions that increase the latency period.
	- Also by prioritizing interrupts over threads.
	- Avoiding use of inappropriate APIs.

what is interrupt and why we should we use it ?
	1. Interrupts enable hardware to signal to the processor.
	2. Hardware devices generate interrupts asynchronously (with respect to the processor clock).
	3. These interrupt values are often called interrupt request (IRQ) lines.

	Types of interrupts :
	Software interrupts, Hardware interrupts, Edge Triggering and Level triggering ?

How can the processor work with hardware without impacting the machine's overall performance? 

Exceptions and Interrupts ?
	Interrupts: 
	asynchronous interrupts generated by hardware.
	Exceptions: 
	synchronous interrupts generated by the processor.

what is ISR and interrupt handler ?
	An interrupt handler or interrupt service routine (ISR) is the function that the kernel runs in response to a specific interrupt:
	1. Each device that generates interrupts has an associated interrupt handler.
	2. The interrupt handler for a device is part of the device's driver (the kernel code that manages the device).

Top Halves Versus Bottom Halves ?
	Top half : 
	The interrupt handler is the top half. The top half is run immediately upon receipt of the interrupt and performs only the work
	that is time-critical, such as acknowledging receipt of the interrupt or resetting the hardware.
	
	Bottom half: 
	Work that can be performed later is deferred until the bottom half. The bottom half runs in the future, 
	at a more convenient time, with all interrupts enabled.
	1. softirq 
	2. tasklet
	3. workqueue

	softirq :
	1. Softirqs are statically allocated at compile-time. So there are fixed number of softirq and they run in priority order.
	2. Softirqs have strong CPU affinity, so they are reserved for most of time critical and important bottom half processing on the 			system.
	3. softirq is guaranteed to run on the CPU it was scheduled on in SMP systems.
	4. It Runs in interrupt context, so Interrupt context cannot perform certain actions that can result in the kernel putting 
		the current context to sleep, such as downing a semaphore, copying to or from user-space memory or non-atomically 			allocating memory
	5. it can’t preempted and can’t scheduled ie: A softirq never preempts another softirq.
		 The only event that can preempt a softirq is an interrupt handler.
	6. Atomic execution
	7. it can run simultaneously on one or more processor, even two of the same type of softirq can run concurrently

	Note : Currently, only two subsystems directly use softirqs: Networking devices and Block devices
	Additionally, kernel timers and tasklets are built on top of softirqs.

	Note : Softirqs are most often raised from within interrupt handlers. 
		First the interrupt handler(top half) performs the basic hardware-related work, raises the softirq, and then exits. 
		After the kernel is done processing interrupts, it checks wither any of the softirqs have been raised or not.
		Code flow in Linux kernel for interrupt handling is explained below.
	Tasklet :
	Tasklets are build on top of softirq. The central idea of tasklet is to provide rich bottom half mechanisum. 
	Only below points diffres from softirq.

	1. Tasklets have a weaker CPU affinity than softirqs
	2. Unlike softirqs, tasklets are dynamically allocated.
	3. A tasklet can run on only one CPU at a time.
	4. Runs in interrupt contex, Interrupt context cannot perform certain actions that can result in the kernel putting 
		the current context to sleep, such as downing a semaphore, copying to or from user-space memory or non-atomically 			allocating memory
	5. Atomic execution
	6. Two different tasklets can run concurrently on different processors, but two of the same type of tasklet cannot run 
		simultaneously on same processor.
	7. Tasklet is strictly serialized wrt itself, but not wrt another tasklets.
	8. Tasklet runs on same CPU from where is raised

	Workqueue :
	Workqueues are also like tasklets. They are useful to schedule a task that for future. There is some identical difference between  		two,Runs in kenrel process context. Because work queues run in process context (kernel threads), they are capable of sleeping.

	1. Run in process contact ie. Non atomic execution
	2. Workqueue runs on same CPU from where is raised
	3. Higher latency compared to tasklet
	4. Because work queues run in process context (kernel threads), they are capable of sleeping
	5. alternative to work queues is kernel threads

	Tasklets Vs SoftIrqs and Why softIRQ if tasklet is there ??

	Tasklets and SoftIrqs are two ways to implement bottom halves ( and definitely not the only two ways).
	Tasklets are dynamically created and are simpler to use. So while deciding upon which one to use , 
	go for tasklets unless the work is time critical. Networking and Block devices, whose work is time critical use SoftIrqs.

	SoftIrqs Vs Tasklets Vs WorkQueues ?

	1. Deferred work runs in Interrupt context in case of SoftIrqs and Tasklets while it runs in process context in case of workqueues.
	2. SoftIrqs(same or different) can run run simulatenously on different processor cores ; 
		same Tasklets can't run simultaneously on different CPU cores but different Tasklets definitely can; 
		workqueues can run of different CPU cores simultaneously.
	3. As SoftIrqs and Tasklets run in interrupt context they can't sleep while workqueues can sleep as they run in the process context.
	4. Both SoftIrqs and Tasklets can't be preempted or scheduled while Workqueues can be.
	5. SoftIrqs are not easy to use while Tasklets and WorkQueues are easy to use.
	6. If the code in question is highly threaded( too many subroutines) for ex. Networking applications 
		then SoftIrq is the best bet as they are the fastest.
	7. If the code is not highly threaded then the device driver developer must go for Tasklets as they have the simplest interface.
	8. If the deferred work has to run in the process context then WorkQueues is the only option.
	9. So, in general if your bottom halve can sleep then use WorkQueues else use Tasklets.
	10. When it comes to ease of use WorkQueues are the best then comes tasklets and in the end comes softirqs 
		as they have to be statically created and require proper thinking before implementing.
	
	For example using the network card:

	1. When network cards receive packets from the network, the network cards immediately issue an interrupt. 
		This optimizes network throughput and latency and avoids timeouts.
	2. The kernel responds by executing the network card's registered interrupt.
	3. The interrupt runs, acknowledges the hardware, copies the new networking packets into main memory, 
		and readies the network card for more packets. These jobs are the important, time-critical, and hardware-specific work.
		a. The kernel generally needs to quickly copy the networking packet into main memory because the network data buffer 
			on the networking card is fixed and miniscule in size, particularly compared to main memory. 
			Delays in copying the packets can result in a buffer overrun, with incoming packets overwhelming 
			the networking card's buffer and thus packets being dropped.
        	b. After the networking data is safely in the main memory, the interrupt's job is done, and it can return control 
			of the system to whatever code was interrupted when the interrupt was generated.
	4. The rest of the processing and handling of the packets occurs later, in the bottom half

Difference from the process context and interrupt context?
	process context :
	it is the mode of operation the kernel is in while it is executing on behalf of a process, 
	such as executing a system call or running a kernel thread.
	1. In process context, the current macro points to the associated task.
	2. Since a process is coupled to the kernel in process context, process context can sleep or otherwise invoke the scheduler.

	Interrupt context : is not associated with a process.
	1 .The current macro is not relevant, though it points to the interrupted process.
		Without a backing process, interrupt context cannot sleep and cannot reschedule. 
	2. Therefore, you cannot call certain functions from interrupt context. If a function sleeps, 
		you cannot use it from your interrupt handler: this limits the functions that can be called from an interrupt handler
	3. Interrupt context is time-critical, because the interrupt handler interrupts other code.
		so As much as possible, work should be pushed out from the interrupt handler and performed in a bottom half, 
		which runs at a more convenient time.

Stacks of an interrupt handler ?
	1. interrupt handlers did not receive their own stacks. Instead, they would share the stack of the process that they interrupted.
	2. The kernel stack is two pages in size:
		8KB on 32-bit architectures.
		16KB on 64-bit architectures.
	3. Because of sharing the stack, interrupt handlers must be exceptionally frugal with what data they allocate there.
	4. Your interrupt handler should not care what stack setup is in use or what the size of the kernel stack is. 
		Always use an absolute minimum amount of stack space

Interrupt Control and Disabling and Enabling Interrupts ?
	Controlling the interrupt system provides synchronization.
	1. Disabling interrupts guarantees that an interrupt handler will not preempt the current code.
	2. Disabling interrupts disables kernel preemption and provides protection against concurrent access from a possible 
	interrupt handler..

	local_irq_disable();
	/* interrupts are disabled .. */
	local_irq_enable();

	prefeared way ?
	unsigned long flags;
	local_irq_save(flags); /* interrupts are now disabled */
	/* ... */
	local_irq_restore(flags); /* interrupts are restored to their previous state */

	Disabling a Specific Interrupt Line ?
	void disable_irq(unsigned int irq);
	void disable_irq_nosync(unsigned int irq);
	void enable_irq(unsigned int irq);
	void synchronize_irq(unsigned int irq);

	Function 		Description
	local_irq_disable() 	Disables local interrupt delivery
	local_irq_enable() 	Enables local interrupt delivery
	local_irq_save() 	Saves the current state of local interrupt delivery and then disables it
	local_irq_restore() 	Restores local interrupt delivery to the given state
	disable_irq() 		Disables the given interrupt line and ensures no handler on the line is executing before returning
	disable_irq_nosync() 	Disables the given interrupt line
	enable_irq() 		Enables the given interrupt line
	irqs_disabled() 	Returns nonzero if local interrupt delivery is disabled; otherwise returns zero
	in_interrupt() 		Returns nonzero if in interrupt context and zero if in process context
	in_irq() 		Returns nonzero if currently executing an interrupt handler and zero otherwis

	Note : The interrupt handler is normally static because it is never called directly from another file.

How to implement your own driver which is dealing with interrupt?
	Initialization
	--------------
	Set your gpio pin value: 0 or 1
	Set your pin type, such as input or output
	Set your interrupt type, such as trigger on rising edge, low level, high level, ...
	If these are not set, they will take default values
	Initialize your interrupt using: request_irq()

	Opening Driver
	--------------
	When the driver is opened, enable your interrupt

	Interrupt Handler
	-----------------
	Disable interrupt
	Clear interrupt
	Perform the work (best done by scheduling it to be done after exiting interrupt handler)
	Enable interrupt

	Close Driver
	------------
	Disable interrupt

	Exit
	----
	Call free_irq()


Synchronization :
What is data race and how to avoid it?
what is starvation and how to avoid it?

What is priority inversion ? 
	solution : priority inheritance, priority ceiling.

What is Indefinite Postponement / Indefinite blocking or starvation ?
Can we use semaphore or mutex or spin lock in interrupt context in linux kernel? and why?
What is rwlock and spinlock ? Briefly explain about both of them ?
Which are the synchronization technoques you use 'between processes', 'between processe and interrupt' and 'between interrupts';
	why and how ?
Which synchronization mechanism is safe to use in interrupt context and why?
Diff between mutex and semaphore? Can semaphore be used for data synchronisation purpose?

what are causes for kernel concurrency?
	Interrupts:
		An interrupt can occur asynchronously at almost any time, interrupting the currently executing code.
	Softirqs and tasklets:
		The kernel can raise or schedule a softirq or tasklet at almost any time, interrupting the currently executing code.
	Kernel preemption:
		Because the kernel is preemptive, one task in the kernel can preempt another.
	Sleeping and synchronization with user-space:
		A task in the kernel can sleep and thus invoke the scheduler, resulting in the running of a new process.
	Symmetrical multiprocessing:
		Two or more processors can execute kernel code at exactly the same time.

	Kernel developers need to understand and prepare for these causes of concurrency:

	1. It is a major bug if an interrupt occurs in the middle of code that is manipulating a resource 
		and the interrupt handler can access the same resource.
	2. Similarly, it is a bug if kernel code is preemptive while it is accessing a shared resource.
	3. Likewise, it is a bug if code in the kernel sleeps while in the middle of a critical section.
	4. Finally, two processors should never simultaneously access the same piece of data.


	knowing What to Protect:
	1.Obviously, any data that is local to one particular thread of execution does not need protection, 
		because only that thread can access the data. For example, local automatic variables 
		(and dynamically allocated data structures whose address is stored only on the stack) do not need any sort of locking 
		because they exist solely on the stack of the executing thread.
	2. Likewise, data that is accessed by only a specific task does not require locking 
		(because a process can execute on only one processor at a time)
	
	Ask yourself these questions whenever you write kernel code:

	1. Is the data global? Can a thread of execution other than the current one access it?
	2. Is the data shared between process context and interrupt context? Is it shared between two different interrupt handlers?
	3. If a process is preempted while accessing this data, can the newly scheduled process access the same data?
	4. Can the current process sleep (block) on anything? If it does, in what state does that leave any shared data?
	5. What prevents the data from being freed out from under me?
	6. What happens if this function is called again on another processor?
	7. Given the proceeding points, how am I going to ensure that my code is safe from concurrency?

	Note : all global and shared data in the kernel requires some form of the synchronization methods

Explain about the implementation of spinlock in case of ARM architecture.
Explain about the implementation of mutex in case of ARM architecture.
Explain about RCU locks and when are they used?

What is deadlock ? how to deteatc and remove deadlock?
	A deadlock is a condition involving one or more threads of execution and one or more resources, 
	such that each thread waits for one of the resources, but all the resources are already held. 
	The threads all wait for each other, but they never make any progress toward releasing the resources that they already hold. 
	Therefore, none of the threads can continue, which results in a deadlock.

	Note : The simplest example of a deadlock is the self-deadlock.
	solution : recursive lock.

What is the function of DMA controller in embedded system?
	DMA stands for Direct Memory Access controller as the name suggest it does not involve processor to transfer memory between 
	two devices that handles the allocation of the memory dynamically to the components and allows the data to be transferred 
	between the devices.
	
	The interrupt can be used to complete the data transfer between the devices. It is used to give the high quality performance 
	as, the input/output device can perform the operations that are in parallel with the code that are in execution.

	- Direct memory access is mainly used to overcome the disadvantages of interrupt and progam controlled I/O.
	- DMA modules usually take the control over from the processor and perform the memory operations and this is mainly because 
		to counteract the mismatch in the processing speeds of I/O units and the procesor. This is comparatively faster.
	- It is an important part of any embedded systems,and the reason for their use is that they can be used for bursty data 
		transfers instead of single byte approaches.
	- It has to wait for the systems resources such as the system bus in case it is already in control of it.

What are the Synchronization techniques used in Linux Kernel? 
	For simple counter variables or for bitwise ------->atomic operations are best methods. 
	atomic_t count=ATOMIC_INIT(0); or atomic_set(&count,0);
	atomic_read(&count);
	atomic_inc(&count);
	atomic_dec(&count);
	atomic_add(&count,10);
	atomic_sub(&count,10); 

	Spinlocks are used to hold critical section for short time and can use from interrupt context and locks can not sleep,
	also called busy wait loops.
	fully spinlocks and reader/writer spin locks are available.
	spinlock_t my_spinlock;
	spin_lock_init( &my_spinlock );
	spin_lock( &my_spinlock );
	// critical section
	spin_unlock( &my_spinlock );
	
	Spinlock variant with local CPU interrupt disable
	spin_lock_irqsave( &my_spinlock, flags );
	// critical section
	spin_unlock_irqrestore( &my_spinlock, flags );
	
	if your kernel thread shares data with a bottom half,
	spin_lock_bh( &my_spinlock );
	// critical section
	spin_unlock_bh( &my_spinlock );

	If we have more readers than writers for our shared resource
	Reader/writer spinlock can be used 
	rwlock_t my_rwlock;
	rwlock_init( &my_rwlock );
	write_lock( &my_rwlock );
	// critical section -- can read and write
	write_unlock( &my_rwlock );

	read_lock( &my_rwlock );
	// critical section -- can read only
	read_unlock( &my_rwlock ); 


	Mutexs are used when we hold lock for longer time and if we use from process context.
	DEFINE_MUTEX( my_mutex );
	mutex_lock( &my_mutex );
	mutex_unlock( &my_mutex );

What are the differences between mutex and semaphore? give a nice example when we should use whichone?
	Strictly speaking, mutex is a locking mechanism whereas semaphore is a signaling mechanism.
	Mutex is the lock to a toilet and semaphore is the number of identical keys to a shared resource.
	Imagine a buffer being split up into 4 parts and then the semaphore count can become 4, i.e there are now 4 instance to the same
	resource. Mind it , it is not the same resource. A semaphore with a value of 0 is similar to mutex but is has a difference, 
	in mutex ,the thread within the same process can unlock the mutex whereas in semaphore an external thread can also free 
	the semaphore by giving wakeup signal.

Why are spin locks good choices in Linux Kernel Design instead of something more common in userland code, such as semaphore or mutex?
	In the following situations.
		The thread that holds the lock is not allowed to sleep.
		The thread that is waiting for a lock does not sleep, but spins in a tight loop.

	When properly used, spinlock can give higher performance than semaphore. Ex: Intrrrupt handler.

What are the rules to use spinlocks?
	Rule - 1: Any code that holds the spinlock, can not relinquish the processor for any reason except to service interrupts ( sometimes not even then). So code holding spinlock can not sleep.
		Reason: suppose your driver holding spinlock goes to sleep. Ex: calls function copy_from_user() or copy_to_user(), or kernel preemption kicks in so higher priority process pushed your code aside. 
			Effectively the process relinquishes the CPU holding spinlock.
		Now we do not know when the code will release the lock. If some other thread tries to obtain the same lock, it would spin for very long time. In the worst case it would result in deedlock.
		Kernel preemption case is handled by the spinlock code itself. Anytime kernel code holds a spinlock, preemption is disabled on the relevant processor. 
			Even uniprocessor system must disable the preemption in this way.
	Rule - 2: Disable interrupts on the local CPU, while the spinlock is held.
		Reason: Support your driver take a spinlock that control access to the device and then issues an interrupt. This causes the interrupt handler to run. Now the interrupt handler also needs the lock to access the device. If the interrupt handler runs on the same processor, it will start spinning. The driver code also can not run to release the lock. SO the processor will spin for ever.
	Rule - 3: Spinlocks must be held for the minimum time possible.
		Reason: Long lock hold times also keeps the current processor from scheduling, meaning a higher priority process may have to wait to get the CPU.
		So it impacts kernel latency (time a process may have to wait to be scheduled). Typically spinlocks should be held for the time duration, less than that CPU takes to do a contex switch between threads.
	Rule -4: if you have semaphores and spinlocks both to be taken. Then take semaphore first and then spinlock.

What is Spinlock and what is difference between Mutex and Spinlock?
	When you use regular locks (mutexes, critical sections etc), operating system puts your thread in the WAIT state and preempts it by scheduling other threads on 
	the same core. This has a performance penalty if the wait time is really short, because your thread now has to wait for a preemption to receive CPU time again.

	Spin locks don't cause preemption but wait in a loop (spin) till the other core releases the lock. This prevents the thread from losing it's quantum and continue 
	as soon as the lock gets released. The simple mechanism of spinlocks allow a kernel to utilize it in almost any state.
	Courtesy: http://stackoverflow.com/questions/1957398/what-exactly-are-spin-locks

	Difference:
	In theory, when a thread tries to lock a mutex and it does not succeed, because the mutex is already locked, it will go to sleep, immediately allowing another thread 
	to run. It will continue to sleep until being woken up, which will be the case once the mutex is being unlocked by whatever thread was holding the lock before. 
	When a tread tries to lock a spinlock and it does not succeed, it will continuously re-try locking it, until it finally succeeds; thus it will not allow another 
	thread to take its place (however, the operating system will forcefully switch to another thread, once the CPU runtime quantum of the current thread has been 
	exceeded, of course).

	Courtesy: http://stackoverflow.com/questions/5869825/when-should-one-use-a-spinlock-instead-of-mutex
	
what is a watchdog timer? what is the sinificance of it?
	Watchdog timer is basically a timing device that is set for predefined time interval and some event should occur during 
		that time interval else the device generates a time out signal.
	One application where it is most widely used is when the mobile phone hangs and no activity takes place, in those cases 
		watchdog timer performs a restart of the system and comes to the rescue of the users.
	It is used to reset to the original state whenever some inappropriate events take place such as too many commands being 
		given at the same time or other activities that result in malfunctioning of the GUI. 
	It is usually operated by counter devices.

What is a kernel Panic and oops?
	Kernel Panic:	
	It is an action taken by linux kernel when it experiences a situation from where it can't recover safely.
	In many cases the system may keep on running but due to security risk by fearing security breach the kernel reboots 
	or instructs to be rebooted manually.
	
	It can be caused due to various reasons-
	1. Hardware failure
	2. Software bus in the OS.
	3. During booting the kernel panic can happen due to one of the reasons-
		a.Kernel not correctly configured, compiled or installed.
		b.Incompatibility of OS, hardware failure including RAM.
		c.Missing device driver
		d.Kernel unable to locate root file system
		e.After booting if init process dies.
	
	OOPS:
	it is a deviation from correct behaviour of Linux kernel which produces certain error log.
	Kernel Panic is one type of OOPS. Kernel Panic doesnt allow system to continue operation while other form of OOPS 
	ALLOW WITH COMPROMISED RELIABILITY.
	When the kernel detects a problem, it prints an oops message and kills any offending process.

What is bus error? what are the common causes of bus errors? 
	The first thing that needs to be addressed is: What is a bus? A bus is a communication unit that allows the CPU to interact 
	with peripherals, there are different type of buses such as PCI, I2C, MDIO, Memory Buses, etc. Normally each bus would have 
	its own protocol for transmitting data across devices, for example in the case of PCI we can have timeout errors or windows 
	errors (data is directed to unknown addresses/devices). In memory, bus errors would refer to alignment but other errors 
	could be attributed to physical HW problems such as faulty connections. Other type of bus errors could be single 
	and multiple bit errors, this could be addressed by using ECC memory.


What is a device tree in Linux? 
	Device tree is a data structure that describes the hardware , their layout, their parameters and other details 
	and is passed to the kernel at boot time

How function pointers are shared across different processes? using which IPCs? 
	Two processes can not share function pointers. If we want to use functions in two processes we will have to make library 
	for those functions and we use that library in our processes.

what is preemption disabling and what is the use of this.
Explain about the notifier chains.
What is the difference between fork( ) and vfork( ) and execv?
Which is the first task what is spawned in linux kernel?
What are the processes with PID 0 and PID 1? PID 0 - idle task and PID 1 - init .
How to extract task_struct of a particular process if the stack pointer is given?
How does scheduler picks particular task?
what is tick rate and jiffies and HZ.
what are the various way of applying delay in linux.
what is blocking and non blocking call
what is Real time clock (RTC).
how busy looping is implemented in linux.
What is the initial value of jiffies when the system has started? and how to check it ?
Explain about HR timers and normal timers?
How to declare that a specific hardware timers is used for kernel periodic timer interrupt used by the scheduler?
How software timers are implemented?
how memory is managed in linux.what are different memory zones in linux.
what us kmalloc and what are action modifier we can pass while using kmalloc.

What are the differences between malloc,zmalloc, vmalloc and kmalloc? Which is preferred to use in device drivers?
	http://learnlinuxconcepts.blogspot.in/2014/02/linux-memory-management.html
	
	void * kmalloc(size_t size , int flags); 	kfree();
	void * vmalloc(unsigned long size); 		vfree();

	The kmalloc() function guarantees that the pages are physically contiguous (and virtually contiguous).it cannot be swapped.

	kmalloc can fail if a contiguous physical block that you want can't be found.
	
	What are the advantages of having a contiguous block of memory? 
	Specifically, why would I need to have a contiguous physical block of memory in a system call? 
	Is there any reason I couldn't just use vmalloc?

	GFP_ATOMIC : the allocation is high-priority and does not sleep.
	This is the flag to use in interrupt handlers, bottom halves and other situations where you cannot sleep like emergency pool.

	GFP_KERNEL: This is a normal allocation and might block. This is the flag to use in process context code when it is safe to sleep.
	
	GFP_DMA: for allocation of memory space capable of undergoing Direct Memory Access.
	allocate memory in DMA zone. device drivers that need DMA-able memory use this flag.

	kmalloc is the preferred way, as long as you don't need very big areas. 
	The trouble is, if you want to do DMA from/to some hardware device, you'll need to use kmalloc, and you'll probably need 
	bigger chunk. The solution is to allocate memory as soon as possible, before memory gets fragmented.
	
	the maxium of space that can be allocated by kmalloc depends on the architecture.
	kmalloc in recent kernel can allocate maximum 4mb contigious memory. to allocate more than 4mb we have to use CMA.
	The defintion of kmalloc is usually found in <slab.h> header file.

	The vmalloc() function works in a similar fashion to kmalloc(), except it allocates memory that is only virtually contiguous 
	and not necessarily physically contiguous.
	
	vmalloc is often slower than kmalloc, because it may have to remap the buffer space into a virtually contiguous range. 
	kmalloc never remaps, though if not called with GFP_ATOMIC kmalloc can block.
	
	vmalloc allocations can sleep and hence should not be used in an interrupt context unlike kmalloc.
	vmalloc would allocate memory from HIGH zone or normal zone.

	kzalloc zeroes the memory before returning a pointer. kmalloc() + memset().

	devm_kzalloc() is resource-managed kzalloc(). The memory allocated with resource-managed functions is associated with the device.
	When the device is detached from the system or the driver for the device is unloaded, that memory is freed automatically. 
	It is possible to free the memory with devm_kfree() if it's no longer needed.

which flag to use for kmalloc?

	Situation				Solution
	Process context, can sleep		Use GFP_KERNEL
	Process context, cannot sleep		Use GFP_ATOMIC, or perform your allocations with GFP_KERNEL 
						at an earlier or later point when you can sleep
	Interrupt handler			Use GFP_ATOMIC
	Softirq					Use GFP_ATOMIC
	Tasklet					Use GFP_ATOMIC
	Need DMA-able memory, can sleep		Use (GFP_DMA | GFP_KERNEL)
	Need DMA-able memory, cannot sleep	Use (GFP_DMA | GFP_ATOMIC), or perform your allocation at an earlier point when you can 						sleep 

Reading Physical Mapped Memory using /dev/mem ?
	/dev/mem
	Provides access to the computer's physical memory.

	/dev/kmem
	Provides access to the virtual address  space  of  the operating  system  kernel,  excluding  memory  that is
	associated with an I/O device.

	/dev/allkmem
	Provides access to the virtual address  space  of  the operating  system  kernel,  including  memory  that is
	associated with an I/O device.

what is Contiguous Memory Allocator (or CMA) ?
how kernel manage to allocate memory when running interrupts? will it able to allocate?
why copy_from_user() and copy_to_user() used ? why copy_to_user() user even though kernel could  write at any user space?
	
	copy_to_user is a function defined in the Linux kernel to copy data from kernel-space to user-space. It is defined 
	in <asm/uaccess.h>. The exact definition depends on the architecture, but it essentially looks like this:

	#include <asm/uaccess.h>
        int copy_to_user(void *dst, const void *src, unsigned int size);

	On success, copy_to_user copies the size bytes pointed at by src, which must exist in kernel-space, to dst, which must exist 
	in user-space. copy_to_user returns the number of bytes not copied, which means on success it returns zero.

	
	Why can't you just call, say, memcpy?
	Two reasons. One, the kernel is capable of writing to any memory. User process's can't. copy_to_user needs to check dst to 
	ensure it is accessible and writable by the current process. Two, depending on the architecture, you can't simply copy data 
	from kernel to user-space. You might need to do some special setup first, invalidate certain caches, or use special operations.

	Let's look at what copy_to_user does on everyone's favorite architecture, x86. First, copy_to_user checks that dst is writable 
	by calling access_ok on dst with a type of VERIFY_WRITE. If access_ok returns nonzero, then copy_to_user proceeds to copy. 
	Next, on x86 processors up to and including 486, the destination pages must be pinned in memory, as the page tables could 
	change at anytime. On x86 revisions after 486, the WP bit is honored from ring zero and this is not necessary. Finally,
	copy_to_user, via __copy_to_user_ll, copies the memory using what is simply an optimized version of memcpy.

	Finally, let's look at an example. This is the gethostname system call as defined in Linux kernel 3.6:
	int gethostname(char *name, int len)
        {
            int i, errno;
            struct new_utsname *u;
            if (len < 0)
                    return -EINVAL;
            down_read(&uts_sem);
            u = utsname();
            i = 1 + strlen(u->nodename);
            if (i > len)
                    i = len;
            errno = 0;
            if (copy_to_user(name, u->nodename, i))
                    errno = -EFAULT;
            up_read(&uts_sem);
            return errno;
        }
	
	The system call is rather simple: It acquires a read semaphore, grabs a pointer to the utsname structure, which contains various
	system information, and then copies the hostname from that structure into the user's provided name buffer. On error it returns
	EFAULT, signifying a problem writing to the user's memory. On success it returns zero.

Why we need copy_from_user() as the kernel can access all the memory?  If we see the copy_from_user() implementation , again we are 
	copying data to the kernel memory using memcpy (). Doesn't it an extra overhead?

What is a way to mmap kernel memory area to user space?
	https://www.ibm.com/developerworks/library/l-user-space-apps/

How to detect kernel memory leak?
	https://psankar.blogspot.in/2010/11/detecting-memory-leaks-in-kernel.html

how container_of() works? write your own MACRO?

how to add your own systemcall in kernel ?
	https://www.ibm.com/developerworks/library/l-system-calls/index.html

how to create proc entry and debugfs in linux kernel ?
	https://www.ibm.com/developerworks/linux/library/l-proc/index.html
	https://lwn.net/Articles/115405/?cm_mc_uid=83865307126915008343575&cm_mc_sid_50200000=1502132303

what is Device Tree in Linux ? what is the Advantages and Disadvantages of Device Tree?
How do the brk and mmap system calls work in the Linux kernel?
How does the code after calling schedule() gets executed in Linux Kernel?

How does Uboot pass device tree information to Linux kernel?

    void TheKernel(char *cmdline, void* dtb);

	The kernel is passed the command line, and a pointer to the device tree binary, and then the function gets called, 
	simple as that.

	From user point of view, these are the steps for booting:

	1- set the variable $cmdline to the desired kernel command line
	2- use fatload or similar command to read the kernel from the sdcard and put it to some address at the memory, 
		let's say at the address 20000000.
	3- use fatload again to read the device tree binary (dtb) to another memory address, like 21000000. (The numbers are all made up)
	4- use the bootm (boot from memory) command to start the boot

	    bootm 20000000 21000000.

how to convert virtual addrees to physical address and vice versa ?
	Documentation/{IO-mapping.txt,DMA-mapping.txt,DMA-API.txt}.
	#include <asm/io.h>
	phys_addr = virt_to_phys(virt_addr);
	virt_addr = phys_to_virt(phys_addr);
	bus_addr  =  virt_to_bus(virt_addr);
	virt_addr = bus_to_virt(bus_addr);

what is virtual memory and what are the advanatages of using virtual memory?

	Physical addresses
		addresses used between the processor and the system’s memory
	(Kernel) logical addresses
		normal address space of the kernel
		almost 1-1 mapping to physical memory
		on most architectures logical associated physical addresses
		differ only by an offset
	(Kernel) virtual addresses
		also mapping from kernel space address to physical address
		not necessarily 1-to-1 mapping
		able to allocate physical memory that has no logical address

What is memory hotplugging in Linux kernel?
	Memory hotplugging is adding or removing sections of memory from the Linux kernel. All the memory in the system is represented 
	as /sys/devices/system/memory/memory*  and their state can be checked by "cat /sys/devices/system/memory/memoryX/state" . 
	To add new memory adddresses, use "echo phys_mem_address > /sys/devices/system/memory/probe"  . 
	This will add new node (memoryY) under /sys/devices/system/memory . To make this memory available, 
	issue 'echo "online" > /sys/devices/system/memory/memoryY/state" and to disable this memory, 
	use 'echo "offline" > /sys/devices/system/memory/memoryY/state' .

What is the difference between kthread_create, kthread_run, kthread_create_on_cpu and kthread_create_on_node?

Shrinking memory will result reassignment of virtual addresses mapped to the memory offlined to new locations and will involve memory copies.
What's paging and swapping?
Is it better to enable swapping in embedded systems? and why?
What is the page size in Linux kernel in case of 32-bit ARM architecture?

What is the difference between the term 'Virtual Memory' and 'Virtual Address Space' ?
Can an user space application view the physical address Or Can an user space application access the physical address space ?
Is it possible for two different application to have a same virtual address but point to different physical memory ?
What is the difference between Code section, Data section, ro Data section & BSS section ?
What is the use of /proc/PID/maps ?
Explain the relation between file struct,File Descriptor Table(FDT), task_struct, MM_struct, vm_area_struct, Heap, Page Global Directory(PGD), Page table(PT) & user page .
What is the use of ioctl fuction ?how to add new ioctl inkernel?
what mmap and do_mmap().
 
Linux Device Driver :
What is device driver and what is the need of it.
what are different kind of devices.
Explain about the Linux Device Model (LDM)? how mudules are loaded in linux.
How to make a module as loadable module? How to make a module as in-built module?

What are the Possible Task States ? 

	TASK_RUNNING
	(R) The process is able to run and contributes to the system load. The scheduler decides which processes really receive CPU time.

	TASK_UNINTERRUPTIBLE 
	(D) The process waits for some event. It will not be considered by the scheduler. The process cannot do anything while it 
	is waiting (it cannot even be killed). This is usually used by device drivers while the process is waiting for some hardware
	to respond. Such a process contributes to the system load even though it will not receive CPU time; some other part of 
	the system is considered to be working on behalf of the process.

	TASK_INTERRUPTIBLE
	(S) The process waits for some event as in TASK_UNINTERUPTIBLE but it can be woken up by a signal. This should be used when 
	the action can be interrupted without side effects. A process in this state is considered asleep and does not contribute to
	the system load.
 
	TASK_STOPPED
	(T) The process is stopped by a signal (Ctrl-Z)
 
	TASK_ZOMBIE
	(Z) The process has exited but there are still some data structures around that could not yet be freed.The zombie will 
	usually be freed when the parent calls wait4() to get the exit status.

how parameters are shared between driver modules.
what are IOCTLS.
what is syscalls.what are the benefits of syscalls.
what is init and exit function of a driver.how and when init and exit function of driver get called.
what is probe function.when probe is get called.
what is platform devices.
what is device tree.what are the benefits of device tree over board files.
what is sysfs and procfs.
how logs are printed in linux kernel and what are the logs level available in linux.
what is copy_to_user and copy_from_user.
what do you mean by kernel configuration and what are the various way of configuring kernel.
what is ioremap
what are the various ways od debugging linux kernel.
how linux kernel boots. what are different booting arguments in linux. how parameter are passed from boot loader to kernel.
what is zimage and bzimage.
difference between poll and select.
what are different type of kernel.
what is DMA.
what is cache coherency.
what is copy on write.
what happens if we pass invalid address from userspace by using ioctls.
what are different ipc mechanism in linux.
difference between memory based io and port based io.
what is I2c and SPI.
how physical to virtual translations works in linux.
what is thrashing, segmentation and fragmentation.
what is preempt_count and what is the need of that.
What is mknod and it's usage ?
In how many ways we can allocate device number ?
How can we allocate device number statically and dynamically and how to free device number?
Explain about about ksets, kobjects and ktypes. How are they related?
mmap() and munmap() ?
	
Compare I2C and SPI protocols?
	SPI protocol requires more hardware(I²C needs 2 lines and that’s it, while SPI formally defines at least 4  Signals).
	SPI procol is faster than I2C, it works in full duplex mode, can transmit upto 10Mbps whereas I2C is limited to 1Mbps 
		in normal mode and 3.4Mbps in fast mode.
	SPI can have only one master whereas I2C supports more than one masters.
	In SPI there is no limitation to the number of bits transmitted in one frame(I2c 8bits).
	SPI is non standard whereas I2C is standard protocol.

What is the difference between early init and late init?
What is process kernel stack and process user stack? What is the size of each and how are they allocated?
What all happens during context switch?
How to do a single dma transaction in kernel?
Translating virtual address to physical address in kernel space?
Can we have same major number for more than one device file ?
What is minor  number and it's usage ?
What is range of major and minor numbers?
How to retrieve major and minor number from dev_t type ?
How can i use my own major and minor number for a device file ?
How to see  statically assigned major numbers ?
how interrupt id and ISR is mapped?
How to pin a interrupt to a CPU in driver
How many maximum different CPU-Cores can be used to processing of one IP-packet?
What are the different modes in ARM.
What is the difference between IRQ & FIQ.
how the synchronisation works in single processor system(spinlock_irq_save).
how external devices access the physical address.

What is the difference between Platform driver and normal device driver..?
    Platform devices are inherently not discoverable, i.e. the hardware cannot say "Hey! I'm present!" to the software. Typical examples are i2c devices, kernel/Documentation/i2c/instantiating-devices states:
	Unlike PCI or USB devices, I2C devices are not enumerated at the hardware level (at run time). Instead, the software must know (at compile time) which devices are connected on each I2C bus segment. 
	So USB and PCI are not platform devices.
    Platform devices are bound to drivers by matching names,
    Platform devices should be registered very early during system boot. Because they are often critical to the rest of the system (platform) and its drivers.

	So basically, the question "is it a platform device or a standard device?" is more a question of which bus it uses. 
	To work with a particular platform device, you have to:
		register a platform driver that will manage this device. It should define a unique name,
		register your platform device, defining the same name as the driver.

    Are platform drivers for those devices that are on chip ??
	Not true (in theory, but true in practice). i2c devices are not onChip, but are platform devices because they are not discoverable. Also we can think of onChip devices which are normal devices. 
	Example: an integrated PCI GPU chip on a modern x86 processor. It is discoverable, thus not a platform device.

    Are normal device drivers for those that are interfaced to the processor chip. before coming across one i2c driver ??
		Not true. Many normal devices are interfaced to the processor, but not through an i2c bus. Example: a USB mouse
		
What happens to the idle thread when a core is taken offline logically?
Measure of performance of OS. Define performance
What are the various code optimization techniques used
memory leak deduction and various ways of handling
How to proceed if system is sluggish
How to determine if some high prio task is hogging CPU
Important things to look for in code reviews
Understanding of schematics
Run Time optimization
Have you worked in crash dump?
How will you solve memory crash, what steps would you take if a crash occurs?
Data sharing between ISR and threads?
what is NAND and NOR flash, diff between them?
who schedules the scheduler
what is cache coherence?
Can a scheduler can be locked?
At what frequency scheduler looks for threads/processes ready for schedule?
what actually does a system does in a tick?
When cahche is enabled in a operating system ,DMA is enabled,how does DMA access the cache?
Diff btwn SPI & I2C
How kernel comes to know which device raised an interrupt when  interrupt  is shared.
how to get physically contiguousness memory allocation if kmalloc is giving logical contiguousness allocations?
How do you build only a static (.a) library for kernel modules.
Kernel thread vs user space thread and kernel process vs user space process and What was the need of thread_info structure?
Thread switching and process switching in linux kernel ?
How context switching is handled in linux?

difference betwen fork() and vfork()?
zombiee and orphon process and How parent less process is handles in linux ?
what is zombie and orphan process? how parent less process is handles in linux.
Can two zombie process communicate with each other ?
What will happen if we do not reap the zombie process ?
What are the various ways to terminate a zombie process ?
What is the difference between wait() and waitpid() system calls ?

Device tree  vs board file?
what is ioctl and What happens if you pass a invalid user space address in an ioctl?
Tell me any issue in which you debugged and found that there is some issue in hardware?
Maximum size you can allocate using kmalloc?
What is the exact definition of 'process preemption'?
nested interrupt is allowed in linux, but the size of interrupt stack is limited,is there any chance that too many nested interrupts cause stack overflow which crashes the whole system!
How do I identify which interrupt line shown in /proc/interrupts list is shared?
How does the Linux kernel handle shared IRQs?
What is the relationship between fork() and pthread_atfork() in Linux?
What is the relationship between System Call and Software Interrupt in Linux?
user/kernel interface (system calls, procfs/sysfs, ioctl) :
synchronization between contexts (how would you synchronize access to a shared memory area used from an interrupt handler and a workqueue on a SMP preemptive kernel).



How do I include the device tree with my kernel?
How to attach file operations to sysfs attribute in platform driver?
How to remove packet from UDP read buffer in kernel?

How does Linux Kernel know where to look for driver firmware?
How to create a device in /dev automatically upon loading of the kernel module for a device driver?
	sudo mknod -m 0666 /dev/msio c 22 0
How to use netlink socket to communicate with a kernel module?
How to implement a Linux Device Driver for Data Acquisition Hardware?
How to find owner socket of sk_buff in Linux kernel?
Why Socket Connection Blocked and TCP Kernel Keeps Retransmitting [ACK] packets
How will you Access userspace memory from kernel ? What are the various methods ?
What is the use of ioctl(inode,file,cmd,arg) ApI ?
What is the use of the poll(file, polltable) API ?
What is the use of file->private_data in a device driver structure ?

How do I debug a kernel module in which a NULL pointer appears?

Linux Kernel Debugging:
What is Oops and kernel panic and how to understand the panic stack?
Does all Oops result in kernel panic?
What are the tools that you have used for debugging the Linux kernel?
What are the log levels in printk?
Can printk's be used in interrupt context?
How to print a stack trace from a particular function?
What's the use of early_printk( )?
Explan about the various gdb commands and features of gdb ?
What are good ways to debug memory corruption in C under Linux?
have u debug any issues using jtag/ any other debugger. if yes, how can we get the call stack in the debugger?

Power Management in Linux:
Explain about cpuidle framework.
Explain about cpufreq framework.
Explain about clock framework.
Explain about regulator framework.
Explain about suspened and resume framwork.
Explain about early suspend and late resume.
Explain about wakelocks.

Miscellaneous:
How are the atomic functions implemented in case of ARM architecture?
How is container_of( ) macro implemented? 
What 's the use of __init and __exit macros?
How to ensure that init function of a partiuclar driver was called before our driver's init function is called (assume that both these drivers are 	 built into the kenrel image)?
What's a segementation fault and what are the scenarios in which segmentation fault is triggered?
How are the command line arguments passed to Linux kernel by the u-boot (bootloader)?

How nested interrupts are handled in ARM?
What are the benefits using FIQ?
What is reset vector?
What is the significance of spinlock on uniprocessor system?
What is priority inversion ? solutions for priority inversion ?
What is priority inheritance ?
What is priority ceiling ?
What is deadlock ?
what is starvation?
what is race condition?

What is the use of the method of temporarily masking / disabling interrupts ? When is it used ? What should be taken care while doing this method ?
Since, disabling/masking of interrupts can be done whent the critical section is ONLY SHORT,What method can be used if the critical section is longer than few source lines or if it involves few lengthy loopings ?
Even if we never enables interrupts in the code, the processor automatically disables them often during hardware access - True/False ? In this case how to reduce interrupt latency ?
When should we re-enable the interrupts in an ISR and why ?
How do you measure the latency of your system ?
What is data race ?
What is Indefinite Postponement / Indefinite blocking or starvation ?
How Many Processes or Threads Are Enough for an application ?

Networking:
http://amsekharkernel.blogspot.in/2014/08/what-is-skb-in-linux-kernel-what-are.html

Track a packet as it goes through the kernel (linux)?
	mkdir /debug
	mount -t debugfs nodev /debug
	mount -t debugfs nodev /sys/kernel/debug
	echo '*' >/debug/tracing/set_ftrace_filter
	echo function_graph >/debug/tracing/current_tracer
	echo 1 >/debug/tracing/tracing_on
	sleep 20
	echo 0 >/debug/tracing/tracing_on
	cat /debug/tracing/trace > /tmp/tracing.out$$

What is the difference between TCP and UDP protocol?

    TCP is a connection oriented protocol and contain the information of sender as well as receiver.
    Eg: HTTP.FTP, Telnet
    TCP is slower than UDP due to its error checking mechanism

    UDP protocols are connection less packets have no information to where they are going. These type of ports are generally used 
	for broadcasting. 
    For eg: DNS, DHCP
    UDP are faster

What is the use of /etc/hosts file?
	To map any hostname to its relevant IP.

What is the command to check all the open ports of your machine?
	nmap localhost.

What is a 3 way handshake protocol? Give an example of it?
	SYN - system 1 sends SYN signal to remote system
	SYN-ACK - remote sysstem receives the syn signal and sends ack signal
	ACK - system again receives ack signal from remote system and connection is established

	E.g: When you ping to a machine you are sending a SYN signal which is ACK by the remote machine then it sends a SYN ACK signal 
	back to the host machine. Then the host machine receives SYN ACK and sends the ACK signal back to confirm the same.

Explain range of TCP/IP classes?
	CLASS A = 1 to 126
	CLASS B = 128 to 191
	CLASS C = 192 to 223
	CLASS D = 224 to 239 (Multicasting)
	CLASS E = 240 to 255 (Research)

Explain in short about all 7 layers of OSI?
	Application layer = user interface and application
	Presentation layer  = Data conversion and transformation
	session layer  = keep data of diff. application seperately
	transport layer  = end to end connectivity using port numbers.
	network layer = logical addressing like IP address.
	Data link layer = Physical addressing like MAC address.
	Physical layer  = Physical transmission of data using 0's and 1's.

What is the use of Ethernet ?
	Ethernet is a link layer protocol in TCP/IP stack and the most widely used LAN technology that provides a framework for data transmission to other devices on the same network segment.
How is the destination MAC address obtained ?
	Destination MAC address is fetched via  ARP
Why is bind system call optional for either UDP or TCP client ?
	connect system call is optional for UDP client as UDP is a connectionless protocol.
What is a raw socket and when will we use it ?
	Raw socket receives or sends raw datagram without including any link layer headers. That is, it allows direct sending and receiving of internet protocol packets without any protocol specific transport layer formatting.
What API is used for converting ipv4 address to NBO and vice versa ?
	htons(), htonl(), ntohl(), ntohs()
	
What is network throughput ?
What is bandwidth ?
In which layer is network throughput normally measured ?
What is Bandwidth-delay product ?
What is goodput ?
What is maximum bandwidth for a TCP based communication ?
What is MTU ?
What is MSS ?
What is Jumbo Frames ?
What is difference between Fast ethernet n/w i/f card and Gigabit ethernet n/w i/f card ?
What is the difference between outb and outportb APIs ?
What is the need for retransmission mechanism ?
What is the use of the following APIs - socket, bind, listen, connect, accept, send, poll, receive ?
Have you used 'select' API ?
What are the types of sockets ? What is the difference between the following - datagram sockets, stream sockets and raw sockets ?
Provide a brief description about TCP Connection Establishment / 3 way handshake method of TCP connection establishment.
What happens as soon as a packet arrives from the network in Linux ?
Why is the design of TCP servers mostly such that whenever it accepts a connection, a new process is invoked to handle it . 
	But, why in the case of UDP servers, mostly there is only a single process that handles all client requests ?
Why does the client end of a connection use high port number(ephemeral ports) whereas the applications listen on typically small port numbers ?
When should you use UDP and When should you use TCP ? Also, give some realtime examples of applications that use TCP or UDP .
What is the difference between symbol rate and bit rate ?
What is BER (Bit error Rate / Bit Error Ratio)?

cquestions:
call back functions?
How can you avoid accessing of an array beyond its limits?
In a big array consists of 1's & 0's ,write an efficient programe to keep all 1's to right side and 0's to other side
In a Process Address Space what if stack or heap collide?
Delete a particular node in a linked list having argument passed as address of a node.
   without Header pointer known and other implementation with header pointer known
Write program to Insert element in static array
what all Debugging techniques you know?
Determine the minimum stack size required for given prog by end of main function?
how to debug your driver if u had any buffer issues
What is shared lib and static library? And how to create it ?
Difference between #define and CONST, which one will you chose in programming?
tell me the logic how can you find depth of a stack?
difference b/w macro and a constant variable?
Memory barriers; Why are they required?
What is re-entrancy
What is structure padding,alignment and packing.?
How to write own malloc call?
What is the difference between inline and macro?
How to know size of memory allocated by malloc using pointer?


Bitwise:
C program to swap every 2 bits in a 8 bit binary number?
Write a program to find how many bit to toggle in 2 binary numbers so that they become equal?
Write a program for to get the number of bits toggle in 2 binary numbers and toggle them to make the numbers equal?
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
Count strings with consecutive 1's
Gray to Binary and Binary to Gray conversion
Find the maximum subset XOR of a given set
Given a set, find XOR of the XOR's of all subsets.
Sum of Bitwise And of all pairs in a given array
Find Next Sparse Number
Find the maximum subarray XOR in a given array
Find XOR of two number without using XOR operator
Write a program to add one to a given number. You are not allowed to use airtmatic operators ?
Multiply two integers without using multiplication, division and bitwise operators, and no loops?
Check if a number is a power of another number
Check perfect square using addition/subtraction
Count numbers having 0 as a digit
Number of perfect squares between two given numbers
Write an Efficient C Program to Reverse Bits of a Number
Calculate square of a number without using *, / and pow()

Byte Swap program?
	function swap16(val) { 
		return ((val & 0xFF) << 8) | ((val >> 8) & 0xFF); 
		}

	function swap32(val) { 
		return ((val & 0xFF) << 24) | ((val & 0xFF00) << 8) | ((val >> 8) & 0xFF00) | ((val >> 24) & 0xFF); 
		}
	
Write a macro for set and reset, swap.
	#define SET_BIT( _X_, _NO_ ) ( 1<<(_X_-1)) | _NO_
	#define RESET_BIT( _X_, _NO_ ) ~( ( 1<<(_X_-1) ) ) & _NO_
	#define SWAP_BIT( _X_, _NO_ ) ( 1<<(_X_-1)) ^ _NO_


Program to Nibble and bit swapping
	int main( void )
	{
	  unsigned char a = 40, b=20;
	  a = ( a>>4 ) | ( a<<4 );
	  b = ( ( b & 0xAA ) >> 1 ) | ( ( b & 0x55 ) << 1 );
	  clrscr();
	  printf( \93After Nibble Swap %d\n\94, a );
	  printf( \93Bit swapping %d\n\94, b );
	  getch();
	  return 0;
	}

Write a program to count total number of setbit in 32 bit number?
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

Write a program to set n th bit in 32 bit number?
	int setbit(int num, int pos)
	{
			   num = num | 1 << pos;
	}

Write a program to count total number of reset bit in 32 bit integer?
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

Write a program to reset nth bit in 32 bit number?
	int resetbit(int num, int pos)
	{
			   num = num &  ~(1 << pos);
	}


Write a program to swap nibble of a 1byte data?
Write a program to find number is even or odd?
	void evnodd(int num)
	{
		   if( (num) & (1) )
			   printf("odd");
		  else
			   printf("even");
	} 

Write a program to find number is power of 2 or not?
	void  power(int num)
	{
		   if( !( (num) & (num-1) ) )
			   printf("power of 2");
		  else
			   printf("num is not power of 2");
	} 

	Write a function to swap even bits with consecutive odd bits in a number.
	   e.g. bo swapped with b1,b2 sawpped with b3 and so on.

	Given an unsigned integer, swap all odd bits with even bits. For example, if the given number is 23 (00010111), it should be converted to 43 (00101011). 
	Every even position bit is swapped with adjacent bit on right side (even position bits are highlighted in binary representation of 23), 
	and every odd position bit is swapped with adjacent on left side.
	If we take a closer look at the example, we can observe that we basically need to right shift (>>) all even bits (In the above example, even bits of 23 are highlighted) by 1
	so that they become odd bits (highlighted in 43), and left shift (<<) all odd bits by 1 so that they become even bits. The following solution is based on this observation. 
	The solution assumes that input number is stored using 32 bits.
	Let the input number be x
	1) Get all even bits of x by doing bitwise and of x with 0xAAAAAAAA. The number 0xAAAAAAAA is a 32 bit number with all even bits set as 1 and all odd bits as 0.
	2) Get all odd bits of x by doing bitwise and of x with 0x55555555. The number 0x55555555 is a 32 bit number with all odd bits set as 1 and all even bits as 0.
	3) Right shift all even bits.
	4) Left shift all odd bits.
	5) Combine new even and odd bits and return.


write a C program to swap even and odd bits of a given number?
	#include
	unsigned int swapBits(unsigned int x)
	{
		// Get all even bits of x
		unsigned int even_bits = x & 0xAAAAAAAA;
		// Get all odd bits of x
		unsigned int odd_bits  = x & 0\D755555555;
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
	Output: 43 

Write a function to set a particular bit?
	unsigned int setbit(unsigned inr num,int pos)
	{
	 num = num | (1 << pos);
	 return num;
	}
 

Write a function to clear a particular bit.
	unsigned int clear(unsigned inr num,int pos)
	{
	 num = num & ~ (1 << pos);
	 return num;
	}

Write a function to toggle particular bit.
	unsigned int togglebit(unsigned inr num,int pos)
	{
	 num = num ^ (1 << pos);
	 return num;
	}

Write a function to swap even bits with consecutive odd bits in a number?
e.g. b0 swapped with b1, b2 swapped with b3 and so on.
	unsigned int swap_bits(unsigned int num)
	{
	  return (num >> 1 & 0x55555555) | (num << 1 & 0xAAAAAAAA);
	}

Write a function to swap odd bits in a number? e.g. b1 swapped with b3, b5 swapped with b7 and so on.
	unsigned int swap_odd_bits(unsigned int num)
	{
	 return (num >> 2 & 0x22222222) |
			 (num << 2 & 0x88888888) |
			 ( num   & 0x55555555) ; 
	}

Write a function to swap even bits in a number?
	e.g. b0 swapped with b2, b4 swapped with b6 and so on.
	unsigned int swap_even_bits(unsigned int num)
	{
	  return (num >> 2 & 0x11111111) |
			 (num << 2 & 0x44444444) |
			 ( num   & 0xAAAAAAAA);}
			 
Write a function to find out the number of 1s in a number?
	unsigned int num_of_ones(unsigned int num)
	{
	 if( (count_ones(num) & 1) 
	  return ODD;
	 else
	  return EVEN;
	}

Write a function for finding the first lowest bit set in a number.
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

Write a function for finding the higest bit set in a number.
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

Write a function for reversing the bits in a number.
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

Write a code to extract nth to mth bit, where n?
	(num >> n) & ~(~ 0 << (m-n+1))

write a code for toggling nth to m bits,where n < m?
	num ^ ((~ 0 << n) & ( ~0 >> (31-m)))

Write a code for setting nth to mth bit, where n < m?
	num | ((~0 << n) & (~0 >>(31-m)))
	
write a code for clearing nth to mth bit, where n  < m?
	num & ~((~0 << n) & (~0 >> (31-m))) 
	
Which bit wise operator is suitable for checking whether a particular bit is on or off?
	The bitwise AND operator. Here is an example:
	enum {
		KBit0 = 1,
		KBit1,
		\85
		KBit31,
	};
	if ( some_int & KBit24 )
		printf ( \93Bit number 24 is ON\n\94 );
	else
		printf ( \93Bit number 24 is OFF\n\94 );

Which bit wise operator is suitable for turning off a particular bit in a number?
	The bitwise AND operator, again. In the following code snippet, the bit number 24 is reset to zero.
	some_int = some_int & ~KBit24;

Which bit wise operator is suitable for putting on a particular bit in a number?
	The bitwise OR operator. In the following code snippet, the bit number 24 is turned ON:
	some_int = some_int | KBit24;

How can you make sure that 3 rd bit (Say 8-bits given to you) is set or not?

Count the number of set bits in an integer?
How do you set/reset a particular bit?
	#define BIT3 (0x1 << 3)
	static int a;
	void set_bit3(void) {
		a |= BIT3;
	}
	void clear_bit3(void) {
		a &= ~BIT3;
	}
	
How would you obtain n bits from position p in an integer?
	First left shift 32-p bits followed by 32-n bits right shift.
	/* getbits: get n bits from position p */ unsigned getbits(unsigned x, int p, int n) { return (x >> (p+1-n)) & ~(~0 >(p+1-n) moves the desired field to the right end of the word. ~0 is all 1 bits; 
	shifting it left n bit positions with ~0 << n places zeros in the rightmost n bits; complementing that with ~ makes a mask with ones in the rightmost n bits. Directly from K&R.

check whether a number is power of 2 or not ?
	void main ()
	{
		int n;
		printf (\93\n Enter any no:\94);
		scanf (\93%d\94, & n);
		if (n & & ((n & n-1) = = 0))
			printf (\93It is power of 2\94);
		else
			printf (\93It is not power of 2\94);
	}
	Note: The logic says that if a no. is power of 2, then in the binary representation, only one bit of the no. can be \911\92 & rest are must be \910\92.
	
swap two variable without temp variable ?
	/* swapping using three variables*/ (Takes extra memory space)
	Int a=5, b=10, c;
	c=a; a=b; b=c;

	/* using arithmetic operators */
	a=a+b; b=a-b; a=a-b;

	/* using bit-wise operators */
	a=a^b; b=b^a; a=a^b;
	
	/* one line statement using bit-wise operators */ (most efficient)
	a^=b^=a^=b;
	The order of evaluation is from right to left. This is same as in approach (c) but the three statements are compounded into one statement.

	/* one line statement using arithmetic & assignment operators */
	a=(a+b) - (b=a);
	In the above axample, parenthesis operator enjoys the highest priority & the order of evaluation is from left to right. Hence (a+b) is evaluated first and replaced with 15. 
	Then (b=a) is evaluated and the value of a is assigned to b, which is 5. Finally a is replaced with 15-5, i.e. 10. Now the two numbers are swapped.

Suggest an efficient method to count the no. of 1\92s in a 32 bit no. Remember without using loop & testing each bit?
	int count_set_bits (long n)
	{
            int count = 0;
             while (n)
             {
				count ++;
				n & = n-1;
             }
            return (count);
     }

	int count_set_bits (long n)
	{
		return (n ? 1+ count_set_bits (n&n-1) : 0);
	} 

How to swap between first & 2nd byte of an integer in one line statement?
	int x=0x1234;
	x = x<<8 | x>>8;
	
linklist:
How to find if their is in repeating node in linked list
find merge point of two single linked list?
arrange elements in single linked list in odd-even group?
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
find length of circular linked list given a pointer to some node of linkedlist?
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

Finding Loop in a single linked list?
	(1) If the linked list is read only, take two pointer approach( p1, p2). Both pointing to beginning of linked list. Now increment p1 by 1 and p2 by 2 and compare both. 
		if they are equal there is a cycle. Repeat this untill p2 points to null.
	(2) If you have the condition not to modify the node but you can change the links, then reverse the linked list. If you reach the head node then there is a cycle.

Finding middle of the single linked list in a single traversal?

	Step 1:
	Take two pointers P1 and P2, both pointed to the first element.
	Step 2:
	Increment P1 by 1 and P2 by two.
	Step 3:
	Whenever P2 reaches to the end, P1 will be at the middle of the list, just return P1->data.

How to check whether linked list is circular or not?
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

How would you find a loop in a singly linked list?
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

Write a C function to print the middle of a given linked list.
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

Write a c program to get the intersection point of two singly linked lists.
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

Write a program to detect loop in a Linked List?
Finding a linked list that is either circular or not circular ?
	Try using 2 pointers:
	pointers travelling at different speeds start from the 
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

Insert nodes into a linked list in a sorted fashion
Write a C program to return the nth node from the end of a linked list

find the middle element in link list ?
		Maintain two pointers slow and fast.
		Iterate thru the list by moving slow pointer once and fast pointer twice. When fast pointer will point to null, slow pointer will be pointing to middle element.

Array vs Linked list?
	Major differences between arrays and linked lists are: 
	(i)  In array consecutive elements are stored in consecutive memory locations whereas in linked list it not so. 
		  Array Elements are stored in contiguous memory locations. Hence they will be faster to retrieve.
	(ii)  In array address of next element is consecutive and whereas in linked list it is specified in the address part of each node.
	(iii) Linked List makes better use of memory than arrays.(iv) Insertion or deletion of an element in array is difficult than insertion or deletion in linked list.
	
Can you tell me how to check whether a linked list is circular or not and delte the circulerity?

Find the size of a structure with out size of operator.
why stack is always in higher location.
what is the difference between global and static
have u debug any issues using jtag/ any other debugger.if yes, how can we get the call stack in the debugger.
Write a function to find whether machine is little endian or big endian.?
Write a program to find occurrence of particular key in given string?
write a program to move all 0's to one side and 1's on ther side of array?
Write a program to find largest element in an array?
Write a program to find second largest element from array?

Write a program to find weather machine is 32 bit or 64 bit?
What is memory leakage? How can we avoid it?
What is NULL , void, dangling pointer?
Can we use const keyword with volatile variable?
What does keyword const means?

what are the compilation steps? Explain?
	there are 4 compilation steps they are 1.preprocessor 2.compiler 3.assembler 4.linker.
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

memory layout of a running process?
	1. Text Segment:
		A text segment , also known as a code segment or simply as text, is one of the sections of a program in an object file or in memory, which contains executable instructions.
		As a memory region, a text segment may be placed below the heap or stack in order to prevent heaps and stack overflows from overwriting it.
		Usually, the text segment is sharable so that only a single copy needs to be in memory for frequently executed programs, such as text editors, the C compiler, the shells, 
			and so on. Also, the text segment is often read-only, to prevent a program from 
		accidentally modifying its instructions.

	2. Initialized Data Segment:
		which contains the global variables and static variables that are initialized by the programmer.
		Note that, data segment is not read-only, since the values of the variables can be altered at run time.
		This segment can be further classified into initialized read-only area and initialized read-write area.
		
		For instance the global string defined by char s[] = "hello world" in C and a C statement like int debug=1 outside the main (i.e. global) would be stored in initialized read-write area. 
			And a global C statement like const char* string = "hello world" makes the string literal "hello world" to be stored in initialized read-only area 
			and the character pointer variable string in initialized read-write area.
			Ex: static int i = 10 will be stored in data segment and global int i = 10 will also be stored in data segment

	3. Uninitialized Data Segment:
		Uninitialized data segment, often called the .bss segment, named after an ancient assembler operator that stood for block started by symbol. Data in this segment is initialized 
			by the kernel to arithmetic 0 before the program starts executing
		uninitialized data starts at the end of the data segment and contains all global variables and static variables that are initialized to zero or do not have explicit initialization in source code.
		
		For instance a variable declared static int i; would be contained in the BSS segment.
		For instance a global variable declared int j; would be contained in the BSS segment.

	4. Stack:
		The stack area traditionally adjoined the heap area and grew the opposite direction; when the stack pointer met the heap pointer, free memory was exhausted. 
			(With modern large address spaces and virtual memory techniques they may be placed almost anywhere, but they still typically grow opposite directions.)
		The stack area contains the program stack, a LIFO structure, typically located in the higher parts of memory. On the standard PC x86 computer architecture it grows toward address zero; 
			on some other architectures it grows the opposite direction. A stack pointer register tracks the top of the stack; it is adjusted each time a value is pushed onto the stack. 
			The set of values pushed for one function call is termed a stack frame; A stack frame consists at minimum of a return address.
		Stack, where automatic variables are stored, along with information that is saved each time a function is called. Each time a function is called, the address of where to return to and 
			certain information about the caller's environment, such as some of the machine registers, are saved on the stack. The newly called function then allocates room on the stack for its automatic 
			and temporary variables. This is how recursive functions in C can work. Each time a recursive function calls itself, a new stack frame is used, so one set of variables doesn't interfere 
			with the variables from another instance of the function.

	5. Heap:
		Heap is the segment where dynamic memory allocation usually takes place.
		The heap area begins at the end of the BSS segment and grows to larger addresses from there.The Heap area is managed by malloc, realloc, and free, 
		which may use the brk and sbrk system calls to adjust its size (note that the use of brk/sbrk and a single heap area is not required to fulfill the contract of malloc/realloc/free; 
		they may also be implemented using mmap to reserve potentially non-contiguous regions of virtual memory into the process\92 virtual address space). The Heap area is shared by all shared libraries 
		and dynamically loaded modules in a process.
		Examples.
		The size(1) command reports the sizes (in bytes) of the text, data, and bss segments. ( for more details please refer man page of size(1) )

Compilation How to reduce a final size of executable?
Can include files be nested?
In order to assign attributes to the pointer itself, rather than to the pointed-to object, you put the attributes after the asterisk. like ' char *const p = &c; ' - True/False?

What is the purpose of main( ) function ?
	The function main( ) invokes other functions within it.It is the first function to be called when the program starts execution.
	\B7 It is the starting function
	\B7 It returns an int value to the environment that called the program
	\B7 Recursive call is allowed for main( ) also.
	\B7 It is a user-defined function
	\B7 Program execution ends when the closing brace of the function main( ) is reached.
	\B7 It has two arguments 1)argument count and 2) argument vector (represents strings passed).
	\B7 Any user-defined name can also be used as parameters for main( ) instead of argc and argv

Is using exit() the same as using return?
	 No. The exit() function is used to exit your program and return controlto the operating system. The return statement is used to return from afunction and return control to the calling function. 
	 If you issue a returnfrom the main() function, you are essentially returning control to thecalling function, which is the operating system. In this case, the returnstatement and exit() function are similar.

What is the output of printf("%d") ?
	When we write printf("%d",x); this means compiler will print the value of x. But as here, there is nothing after %d so compiler will show in output window garbage value.

Typecast when to use and when not to use? implicit and explicit typecasting ?
What does the following code output and why?
	void foo(void) {
		unsigned int a = 6;
		int b = -20;
		(a +b > 6) ? puts(">6") : puts("<6");
	}

Switch vs if; which one is better? Why?
	A switch statement is generally best to use when you have more than two conditional expressions based on a single variable of numeric type.

Differentiate between a for loop and a while loop? What are it uses?
	For executing a set of statements fixed number of times we use for loop while when the number of
	iterations to be performed is not known in advance we use while loop.

What are differences between sizeof operator and strlen function?
	sizeof is keyword of c which can find size of a string constant including null character but strlen is function which has been defined string.h and can find number of characters in a string excluding null character.
Write a code for String reverse, strlen,reverse words in a string, find duplicates in an array etc. ?

Little endian vs big endian? Why it is required? Which one is better? How the conversion happens? White a pseudo code for hton() and ntoh()?
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

	void main ()
	{
		int x = 300;
		if ((* ((unsigned char *) & x) == 1)&& (*(unsigned char*) & x+1) == 44))
			printf (\93BIG ENDIAN\94);
		else
			printf (\93LITTLE ENDIAN\94);
	}

	void main ()
	{
		union xxx
		{
			unsigned int x;
			unsigned char ch[2];
		};
		union xxx p = {300};
		if ((p.ch [0] = = 1) && (p. ch [1] == 44))
			printf (\93BIG ENDIAN\94);
		else
			printf (\93LITTLE ENDIAN\94);
	}

How to reduce function call overhead in ARM based systems?
	Try to ensure that small functions take four or fewer arguments. These will not usethe stack for argument passing. It will copied into registers.\B7 
	If a function needs more than four arguments, try to ensure that it does asignificant amount of work, so that the cost of passing the stacked arguments isoutweighed.
	Pass pointers to structures instead of passing the structure itself.
	Put related arguments in a structure, and pass a pointer to the structure tofunctions. This will reduce the number of parameters and increase readability.
	Minimize the number of long long parameters, as these take two argument words.This also applies to doubles if software floating-point is enabled.
	Avoid functions with a parameter that is passed partially in a register and partiallyon the stack (split-argument). This is not handled efficiently by the currentcompilers: all register arguments are pushed on the stack.
	Avoid functions with a variable number of parameters. Varargs functions

Write a C program to encode bits in a 32-bit number such  that, most significant 16 bits should be reversed but lower 16 bits should be untouched. Then asked to generalize this to any number of bits?
	reverse the entire 32-bits first and then left shift the resulting number by 16 bits so that the upper 16 bits are now reversed. 
	In the second phase, with the help of a mask zero out the most significant 16 bits. Now XOR the two number to get the desired encoded number ?

How are signals hanled in OS ?

What is the difference between kill-6 and kill -9? 
	SIGKILL and SIGABRT are two type of signals that are sent to process to terminate it.

	SIGKILL is equivalent of "kill -9" and is used to kill zombie processes, processes that are already dead 
		and waiting for their parent processes to reap them.
	SIGABRT is equivalent of "kill -6" and is used to terminate/abort running processes.

	SIGKILL signal cannot be caught or ignored and the receiving process cannot perform any clean-up upon receiving this signal.
	SIGABRT signal can be caught, but it cannot be blocked.

differance b/w kill -9 and kill -3 ?
	kill -3: Terminates with coredump. eg SIGQUIT (QUIT) : Quit : Terminate with core dump; can be trapped
	kill -9: Forcible termination. eg SIGKILL (KILL) : Kill : Forced termination; cannot be trapped

describe the steps to add a new sysctl() or fnctl() ?
	sysctl is used to modify kernel parameters at runtime. The parameters are listed under /proc/sys/.
	Procfs is required for sysctl support in Linux. You can use sysctl to both read and write sysctl data.
	You must login as the root user to use any one of the following command.
	Method # 1: Setting value via procfs
		You can use standard echo command to write data to variables:
		# echo "value" > /proc/sys/location/variable
	Method # 2: Temporary on the command line
		Use sysctl command with -w option when you want to change a sysctl setting:
		sysctl -w variable=value
	Method # 3: Configuration file /etc/sysctl.conf
		This is recommended way. First open /etc/sysctl.conf file
		# vi /etc/sysctl.conf
	Now add value:
	variable = value
	Close and save the changes. Type the following command to load sysctl settings from the file /etc/sysctl.conf file:
	# sysctl -p

Write a program in C to add two numbers without using any maths operator (+, -, /, *).
	int sum(int x, int y) 
	{ 
		if( x == y) 
			return (x << 1); 
		else 
			return (x ^ y); } see complete program at http://www.ssiddique.info/add-two-numbers-without-using.html
	}
	
	c = a \96 (-b);
	as a+b is equivalent to a \96 (-b), binary \91+\92 operator is replaced by one unary \91-\91 & one binary \91-\91 operator.

How to print number from 1 to 100 without using conditional operators.
	void main ()
	{
		int  i=0;
		while (100 \96 i++)
		printf (\93 %d\94, i);
	}

WAP to print 100 times "Hello" without using loop & goto statement.
	void main()
	{
		show (1, 100);
	}
	show (int x, int y)
	{
		if (x>=y)
			return;
		printf (\93\n Hello\94);
		show (x+1, y);
	}
	i.e. Recursive function

Preprocessor:
Using the #define statement, how would you declare a manifest constant that returns the number of seconds in a year? Disregard leap years in your answer?
	#define SECONDS_PER_YEAR (60UL * 60UL * 24UL * 365UL)

Write the standard MIN macro. That is, a macro that takes two arguments and returns the smaller of the two arguments?
	#define MIN(A,B)       ((A) <=  (B) ? (A) : (B))

What is the purpose of the preprocessor directive #error?
	Either you know the answer to this, or you don't. If you don't, then see reference 1. This question is very useful for differentiating between normal folks and the nerds. 
	It's only the nerds that actually read the appendices of C textbooks that find out about such things.  Of course, if you aren't looking for a nerd, the candidate better hope she doesn't know the answer.

Where are macros stored in the memory? 
	Macros aren't stored anywhere separately. They get replaced by the code even before compilation.
	The compiler is unaware of the presence of any macro. If the code that replaces macro is large then the program size 
	will increase considerably due to repetition.

write a program to find sizeof structure without using size of operator?
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

Why is sizeof('a') not 1? what this mean sizeof(a++) ?

Advantages and disadvantages of using macro and inline functions?
	inline :A: 
	The ARM compilers support inline functions with the keyword __inline. This results ineach call to an inline function being substituted by its body, instead of a normal call. This
	results in faster code, but it adversely affects code size, particularly if theinline function islarge and used often.

#define vs #include?

#define vs typedef?  
Consider the two statements below and point out which one is preferred and why?
	#define dPS struct s *
	typedef struct s * tPS;

	dPS p1,p2; => struct s * p1, p2; 
	tPS p3,p4; => struct s * p1,struct s * p2;

What is the use of typedef?
	i)It increases the portability.
	(ii) It simplify the complex declaration and improve readability of the program.

What are macros? What are its advantages and disadvantages?
	Macro is a Pre-processor.Major advantage of using the macro is to increase the speed of the execution of the program.
	Major disadvantage of the macros are:
		(i) No type checking is performed in macro. This may cause error.
	(ii)  A macro call may cause unexpected results.

#define vs enum; Which one is better? And Why?
	The use of an enumeration constant (enum) has many advantages over using the traditional symbolic constant style of #define. These advantages include a lower maintenance requirement, 
	improved program readability, and better debugging capability.
	1) The first advantage is that enumerated constants are generated automatically by the compiler. Conversely, symbolic constants must be manually assigned values by the programmer.
	2) Another advantage of using the enumeration constant method is that your programs are more readable and thus can be understood better by others who might have to update your program later.
	3) A third advantage to using enumeration constants is that some symbolic debuggers can print the value of an enumeration constant. Conversely, most symbolic debuggers cannot print the value of a symbolic constant. 
		This can be an enormous help in debugging your program, because if your program is stopped at a line that uses an enum, you can simply inspect that constant and instantly know its value. 
		On the other hand, because most debuggers cannot print #define values, you would most likely have to search for that value by manually looking it up in a header file.
	4)enum actually declares a type, and therefore can be type checked.

What is the purpose of the preprocessor directive #error?
	Preprocessor error is used to throw a error message during compile time. We can check the sanity of the make file and using debug options given below

	#ifndef DEBUG
	#ifndef RELEASE
	#error Include DEBUG or RELEASE in the makefile
	#endif
	#endif

write a MACRO to set the MSB?

#define cat(x,y) x##y concatenates x to y. But cat(cat(1,2),3) does not expand but gives preprocessor warning. Why?
	The cat(x, y) expands to x##y. It just pastes x and y. But in case of cat(cat(1,2),3), it expands to cat(1,2)##3 instead of 1##2##3. That is why it is giving preprocessor warning.

Infinite loops often arise in embedded systems. Howe does one code an infinite loop in C?
	while(1), for(;;)

	loop
	...
	goto loop

Macro vs inline; Explain each of them; and which one is better why?

what are Static and Dynamic Libraries? advantage and disadvantages of both?

What is the difference between static linking and dynamic linking ?
	In static linking, all the library modules used in the program are placed in the final executable file making it larger in size. This is done by the linker. 
	If the modules used in the program are modified after linking, then re-compilation is needed. 
	The advantage of static linking is that the modules are present in an executable file. We don't want to worry about compatibility issues.

	In case of dynamic linking, only the names of the module used are present in the executable file and the actual linking is done at run time when the program and the library modules both are present in the memory.
	That is why, the executables are smaller in size. Modification of the library modules used does not force re-compilation. But dynamic linking may face compatibility issues with the library modules used.

What is the difference between #include "..." and #include <...>?
		The difference lies in where the preprocessor looks for the file to be included. For the include directive with a double quoted filename, 
		the preprocessor limits its search for the file to the same directory where the current source file resides. On the other hand, 
		when the directive uses angle brackets, the preprocessor searches for the file in directories pre-designated by the compiler - usually directories where standard library header files reside.

What is the benefit of using #define to declare a constant?
	Using the #define method of declaring a constant enables you to declare a constant in one place and use it throughout your program. This helps make your programs more maintainable, 
	because you need to maintain only the #define statement and not several instances of individual constants throughout your program.
	For instance, if your program used the value of pi (approximately 3.14159) several times, you might want to declare a constant for pi as follows:  #define PI 3.14159
	Using the #define method of declaring a constant is probably the most familiar way of declaring constants to traditional C programmers. Besides being the most common method of declaring constants, 
	it also takes up the least memory.
	Constants defined in this manner are simply placed directly into your source code, with no variable space allocated in memory. Unfortunately, this is one reason why most debuggers cannot 
	inspect constants created using the #define method
		
storge class:
what is qualifiers?   
	Qualifiers defines the property of the variable. Two qualifiers are const and volatile. The const type qualifier declares an object to be unmodifiable. 
	The volatile type qualifier declares an item whose value can legitimately be changed by something beyond the control of the program in which it appears, such as a concurrently executing thread / interrupt routine. 

Can static variables be declared in a header file?
	you can\92t declare a static variable without defining it as well (this isbecause the storage class modifiers static and extern are mutuallyexclusive). 
	A static variable can be defined in a header file, but thiswould cause each source file that included the header file to have its  own private copy of the variable, which is probably not what wasintended.
	
Can a static variable accessed from outside of the file?

	Storage class static and extern and register in details.
	storage class           declared        scope           visibility
	1. auto
                        Globel
                        local           block           block
	2. register
                        globel
                        local           block           block
	3. static
                        globel          program         file
                        local           program         block
	4. extern
                        globel          program         program
                        local           program         block
	auto :
	Automatic variables or auto variables are default storage class of local variable. An auto variable cannot be declared globally. (Why?)
	Properties :
	1. Default initial value of auto variable is garbage.
	2. Visibility of auto variable is within the block where it has declared.
	3. Scope of auto variable is within the block where it has declared.
	4. auto variable initialize each time.
	5. An auto variable gets memory at run time.

	register : 
	when we required to optimize the execution time, move the critical variable to processor register. this can be done by using the register key word.
	Automatic variables are allocated in the main memory of the processor; accessing these memory location for computation will take long time.
	NOTE: Allocation of register is not guaranteed always, it depends on number register available in processor and number register used for manipulation. 
		if you define 4 variable as register storage class and and processor has only 2 register for variable allocation, then compiler will allocate 2 variable in registers and treat the remaining 2 variable as auto variable. 
		therefore usage of register keyword should should be justified and cross checked with disassembly weather register is allocated or not.
	All register variable in c stores in CPU not in the memory so We cannot dereference register variable since it has not any memory address.
	properties :
	1. register int a; We are only requesting not forcing to compiler to store variable a in CPU.
	2. A register variable execute faster than other variables because it is stored in CPU
        so during the execution compiler has no extra burden to bring the variable from memory to CPU.
	3. Since a CPU have limited number of register so it is programmer responsibility which variable should declared
        as register variable i.e. variable which are using many times should declared as a register variable.
	4. We cannot dereference register variable since it has not any memory address.
	5. Default initial value of register variable is garbage.
	6. Scope and visibility of register variable is block.

	static :
	properties :
	1. It is not default storage class of global variables.
	2. Default initial value of static integral type variables are zero otherwise null.
	3. A same static variable can be declared many times but we can initialize at only one time.
	4. We cannot write any assignment statement globally.
	Note: Assigning any value to the variable at the time of declaration is known as initialization
        while assigning any value to variable not at the time of declaration is known assignment.
	5. A static variable initializes only one time in whole program.
	6. If we declared static variable locally then its visibility will within a block where it has declared.
	7. If declared a static variable or function globally then its visibility will only the file
        in which it has declared not in the other files.

	(a) A variable declared static within the body of a function maintains its value between function invocations.
	(b) A variable declared static within a module [1], (but outside the body of a function) is accessible by all functions within that module. 
		It is not accessible by functions within any other module. That is, it is a localized global.
	(c) Functions declared static within a module may only be called by other functions within that module. That is, the scope of the function is localized to the module within which it is declared.

	extern :
	properties:
	1. It is default storage class of all global variables as well all functions.
	2. When we use extern modifier with any variables it is only declaration i.e. memory is not allocated for these variable.
	3. If you will not use extern keyword with global variables then compiler will automatically
		initialize with default value to extern variable.
	4. Default initial value of extern integral type variable is zero otherwise null.
	5. We cannot initialize extern variable locally i.e. within any block either at the time of declaration or separately.
        We can only initialize extern variable globally.
	6. If we declare any variable as extern variable then it searches that variable either it has been initialized or not.
        If it has been initialized which may be either extern or static* then it is ok otherwise compiler will show an error.
	7. A particular extern variable can be declared many times but we can initialize at only one time.
	8. We cannot write any assignment statement globally.
	9. If declared an extern variables or function globally then its visibility will whole the program
        which may contain one file or many files.
		
What are volatile variables? Where we should use?
	A volatile variable is one that can change unexpectedly. Consequently, the compiler can make no assumptions about the value of the variable. In particular, 
	the optimizer must be careful to reload the variable every time it is used instead of holding a copy in a register. Examples of volatile variables are:

    Hardware registers in peripherals (for example, status registers)
    Non-automatic variables referenced within an interrupt service routine
    Variables shared by multiple tasks in a multi-threaded applications

What is volatile variable means?
	volatile has nothing to deal with storage class.
	volatile just tells the compiler or force the compiler to "not to do the optimization" for that variable. so compiler would not optimize the code for that variable 
	and reading the value from the specified location, not through interal register which holds the previous value.
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

volatile vs const volatile, Explain?
What does the keyword volatile mean? Give three different examples of its use.? 
	(a) Can a parameter be both const and volatile? Explain your answer.
	(b) Can a pointer be volatile? Explain your answer.
	(c) What is wrong with the following function?:
	int square(volatile int *ptr)
	{
		return *ptr * *ptr;
	}
ANS:
	A volatile variable is one that can change unexpectedly. Consequently, the compiler can make no assumptions about the value of the variable. In particular,
	the optimizer must be careful to reload the variable every time it is used instead of holding a copy in a register. Examples of volatile variables are:
	
	(a) Hardware registers in peripherals (e.g., status registers)
	(b) Non-stack variables referenced within an interrupt service routine.
	(c) Variables shared by multiple tasks in a multi-threaded application.

	The answers are as follows:
	(a) Yes. An example is a read only status register. It is volatile because it can change unexpectedly. It is const because the program should not attempt to modify it.
	(b) Yes. Although this is not very common. An example is when an interrupt service routine modifies a pointer to a buffer.
	(c) This one is wicked. The intent of the code is to return the square of the value pointed to by *ptr. However, since *ptr points to a volatile parameter, the compiler will generate code that looks something like this:
	int square(volatile int *ptr)
	{
		int a,b;
		a = *ptr;
		b = *ptr;
		return a * b;
	}
	Since it is possible for the value of *ptr to change unexpectedly, it is possible for a and b to be different. Consequently, this code could return a number that is not a square! The correct way to code this is:
	long square(volatile int *ptr)
	{
		int a;
		a = *ptr;
		return a * a;
	}

	Another use for volatile is signal handlers. If you have code like this:
	quit = 0;
	while (!quit)
	{
		/* very small loop which is completely visible to the compiler */
	}
	The compiler is allowed to notice the loop body does not touch the quit variable and convert the loop to a while (true) loop. Even if the quit variable is set on the signal handler for SIGINT andSIGTERM; 
		the compiler has no way to know that.
	However, if the quit variable is declared volatile, the compiler is forced to load it every time, because it can be modified elsewhere. This is exactly what you want in this situation.
	Courtesy: http://stackoverflow.com/questions/246127/why-is-volatile-needed-in-c

Can a parameter be both const and volatile ? Explain.
	An example is a read-only status register. It is volatile because it can change unexpectedly. It is const because the program should not attempt to modify it
	
What is difference between static and extern?
	"The static storage class is used to declare an identifier that is a local variable either to a function or a file and that exists and retains its value after control 
	passes from where it was declared. This storage class has a duration that is permanent. A variable declared of this class retains its value from one call of the function
	to the next. The scope is local. A variable is known only by the function it is declared within or if declared globally in a file, it is known or seen only by the 
	functions within that file. This storage class guarantees that declaration of the variable also initializes the variable to zero or all bits off.
	
	The extern storage class is used to declare a global variable that will be known to the functions in a file and capable of being known to all functions in a program. 
	This storage class has a duration that is permanent. Any variable of this class retains its value until changed by another assignment. The scope is global. 
	A variable can be known or seen by all functions within a program. ."

What is difference between static local and static global variable?
	Static global  :
	Static variable has scope only in the file in which it is declared. it can't be accessed in any other file but its value remains intact if code is running in some other 
	file means lifetime is in complete program .
	Static local:
	static local variable has scope in that function in which it is declared means it can't be used in other functions in the same file also, 
	means scope is limited to the function in which it is declared while its life time is also through out the program.

Can we declare static variable in header file?

	You can't declare a static variable without defining it as well (this is because the storage class modifiers static and extern are mutuallyexclusive). 
	A static variable can be defined in a header file, but this would cause each source file that included the header file to have its own private copy of the variable, 
	which is probably not what was intended.

Can a static variable accessed from outside of the file?

Can we declare main() function as static?
	No. The C spec actually says somewhere in it  that the main function cannot be static.
	The reason for this is that static means "don't let anything outside this source file use this object". The benefit is that it protects against name collisions in C 
	when you go to link (it would be bad bad bad if you had two globals both named "is_initialized" in different files... they'd get silently merged, unless you made 
	them static). It also allows the compiler to perform certain optimizations that it wouldn't be able to otherwise. These two reasons are why static is a nice thing to have.

	Since you can't access static functions from outside the file, how would the OS be able to access the main function to start your program? 
	That's why main can't be static.
	Some compilers treat "main" specially and might silently ignore you when you declare it static.
	
Array pointer:
There is a char * pointer that points to some ints, and what should be done to step over it ?
How does declaring function parameters as 'const' help in better,safer code ?
Which of the following is correct . Why does point no 'i' gives output sometime & sometimes it does not give output ?
	i. char *a = malloc(strlen(str));
	strcpy(a, str);
	ii. char *a = malloc(strlen(str) + 1);
	strcpy(a, str);

Write a program to move all 0's to one side and 1's on ther side of array?
Write a program to find largest element in an array?
Write a program to find second largest element from array?

Can we increment the base address of array? Justify your answer.
	No, Because once we initialize the array variable, the pointer points base address only & it's fixed  and constant pointer.

What is the output of program.
	int a[5] = {1,2,3,4,5};
	int *ptr = (int*) (&a +1);
	int *ptr = (int*) (a+1); 

	you see, for your program above, a and &a will have the same numerical value,and I believe that's where your whole confusion lies.You may wonder that if they are the same,
	the following should give the next address after a in both cases,going by pointer arithmetic:

	(&a+1) and (a+1)

	But it's not so!!Base address of an array (a here) and Address of an array are not same! a and &a might be same numerically ,but they are not the same type. 
	a is of type int* while &a is of type int (*)[5],ie , &a is a pointer to (address of ) and array of size 5.But a as you know is the address of the first element of the array.Numerically 
	they are the same as you can see from the illustration using ^ below.

	But when you increment these two pointers/addresses, ie as (a+1) and (&a+1), the arithmetic is totally different.While in the first case it "jumps" to the address of the next element in the array, 
	in the latter case it jumps by 5 elements as that's what the size of an array of 5 elements.
 
What is output of the program?
	int main()
	{
				int arr[10];
				int *ptr = arr;
				ptr++;
				arr++;
				return 0;
	}

	The statement arr++ will give you lvalue error. Because hear you are trying to increment base address of array and by default base address of array is constant pointer(constant value) so,
	arr  =  arr+1;
	i.e according to rule on LHS of assignment operator there always should be lvalue i.e variable not constant.
	
How do I make an array of complex number in C?
http://c-faq.com/~scs/cgi-bin/faqcat.cgi?sec=ptrs

What will be output when you will execute following c code?
	#include
	void main(){
		int const SIZE=5;
		int expr;
		double value[SIZE]={2.0,4.0,6.0,8.0,10.0};
		expr=1|2|3|4;
		printf("%f",value[expr]);
	}
	Explanation:
	Size of any array in c cannot be constantan variable, size of array can be enum, macro.
	
How function poiner are shared between different process ?
	two processes can not share function pointers.
	if you want to use functions in two processes make library for that functions and use that library in your processes.
	
Searching for duplicates in array?
	Simple algorithm:
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

	Efficient Algorithim:
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
 
differance b/w array and pointer and const strings ?
Can the sizeof operator be used to tell the size of an array passed to a function?

What is the difference between array_name and &array_name?
	One is a pointer to the first element in the array; the other is a pointer to the array as a whole.

Why can't constant values be used to define an array's initial size?
	char a[ 512 ];
	char a[ sizeof( struct cacheObject ) ];
	char buf[ sizeof( struct cacheObject ) * MAX ];
	Enumerations are allowed too.
	
	int max = 512; /* not a constant expression in C */
	char buffer[ max ]; /* not valid C */
	
Whats is Stack overflow attack??...then he gave me a scenario where there was a open source code at a server and you have your piece of code at that server.
You as a client are allowed to invoke a method which takes in a array as a parameter which is not checked for overflow validation. 
I had to induce a buffer overflow attack and make the method to pass control\85 

Pointer:
What does the keyword const mean? 
Const vs static vs #define?
	const char *ptr 		: ptr is a pointer to a char, where you can't change the value of the char (at least not through the pointer(without casting the constness away)).
	char * const ptr 		: ptr is a constant pointer to a char, where you can change the char, but you can't make the pointer point to a different char.
	const char *const ptr	: ptr is a constant pointer to a constant char, i.e. you can change neither where the pointer points nor the value of the pointee.
	
What is hashing?
memmove vs memcpy vs memset ?
write your own malloc()?
malloc vs calloc vs realloc?
what is free()? how does free know how much memory to de-allocate?


NULL vs wild vs dangling vs generic pointer ? Why NULL pointer is required?
	
	NULL pointer:
	Literal meaning of NULL pointer is a pointer which is pointing to nothing. NULL pointer points the base address of segment.
	Note: We cannot copy any thing in the NULL pointer.
	
	Examples of NULL pointer:
	1. int *ptr=(char *)0;
	2. float *ptr=(float *)0;
	3. char *ptr=(char *)0;
	4. double *ptr=(double *)0;
	5. char *ptr=\92\0\92;
	6. int *ptr=NULL;

	What is meaning of NULL?
	NULL is macro constant which has been defined in the heard file stdio.h, alloc.h, mem.h, stddef.h and stdlib.h as
	#define NULL 0

	The null pointer is used in three ways:
	1) To stop indirection in a recursive data structure.
	2) As an error value.
	3) As a sentinel value.
		
	Wild Pointers:
	Wild pointers are created by omitting necessary initialization prior to first use. Thus, strictly speaking, every pointer in programming languages which do not enforce initialization begins as a wild pointer. 
	This most often occurs due to jumping over the initialization, not by omitting it. Most compilers are able to warn about this.
	A pointer in c which has not been initialized is also known as wild pointer.
	{
		int* a;
		/* a is wild pointer, it is not initialized and it may have some garbage value*/
	}

	correct way is
	{
		int* a = NULL;
	}

	Note: There is difference between the NULL pointer and wild pointer. Null pointer points the base address of segment while wild pointer doesn\92t point any specific memory location.
	
	Dangling Pointer : how it is different from memory leak?
	If a pointer is de-allocated or freed and the pointer is not assigned to NULL, then it may still contain that address and accessing the pointer means that we are trying to access that location and it will give an error. 
	This type of pointer is called dangling pointer.
	
	Solution of this problem: Make the variable as static variable.

	Examples of Dangling Pointers
	int main()
	{
		int *p;
		p = (int *) malloc (sizeof (int));
		free(p);
		*p=10;
	}
	In the above piece of code we are using *p after we free the memory to it. Such usage is called dangling pointer usage.
	
	int main()
	{
		int *p = NULL;
		{
			int a = 10;
			p = &a;
		}
		/*address of a is out of scope and pointer p is now called the dangling pointer, we should initialize the p to NULL before coming out or initialize the pointer to some known value before using it again*/
	\85
	}
	
	int* fun1()
	{
		int a = 10;
		return(&a); /*in this line we are returning the pointer of variable \91a\92 which is out scope.*/
	}
	
	Dangling pointers are are those that point to memory locations which have already been freed. For example:
	int *a = malloc(sizeof(int));
	free(a);
	// a is now a dangling pointer

	Memory leaks are quite the opposite of dangling pointers. Memory leaks happen when memory locations are not freed, but there is no way to refer to them (i.e., no pointers are pointing to them).
	int *a = malloc(sizeof(int));
	a = 0;
	// now a no longer points to the memory that we just allocated, causing a memory leak

	Unlike higher-level languages with garbage collectors, it is critical to always keep track of allocated memory when programming in C

	Generic pointer:
	void pointer in c is known as generic pointer. Literal meaning of generic pointer is a pointer which can point type of data.
	Example:
	void *ptr;
	Here ptr is generic pointer.

	1. We cannot dereference generic pointer. 
		A void pointer can be dereferenced only after explicit casting. e.g 
		int a = 5;
		void *b = &a;
		printf(\93%d\n\94, *((int*)b));

	2. We can find the size of generic pointer using sizeof operator.
	3. Generic pointer can hold any type of pointers like char pointer, struct pointer, array of pointer etc without any typecasting.
	4. Any type of pointer can hold generic pointer without any typecasting.
	5. Generic pointers are used when we want to return such pointer which is applicable to all types of pointers. 
	For example return type of malloc function is generic pointer because it can dynamically allocate the memory space to stores 
	integer, float, structure etc. hence we type cast its return type to appropriate pointer type.
	
	some tricks for pointers:
	*array = *(array +0) = array[0];
	arr[0] = &arr1;
	p[i] = *(p+i) : P[0][0][0]=*(p[0][0]+0)=**p[0]=***p
	p[i][j] == *(*(p+i)+j);
	*&i = i;
	-> = (*).
	Rule: * and & always cancel to each other
	Note: %s is used to print stream of characters up to null (\0) character.


Why should we assign NULL to the elements (pointer) after freeing them?
	This is paranoia based on long experience. After a pointer has been freed, you can no longer use the pointed-to data. The pointer is said to dangle; it doesn\92t point at anything useful.
	If you NULL out or zero out a pointer immediately after freeing it, your program can no longer get in trouble by using that pointer. True, you might go indirect on the null pointer instead, 
	but that\92s something your debugger might be able to help you with immediately.
	Also, there still might be copies of the pointer that refer to the memory that has been deallocated; that\92s the nature of C. Zeroing out pointers after freeing them won\92t solve all problems.

What is a null pointer assignment error? What are bus errors, memory faults, and core dumps?
	These are all serious errors, symptoms of a wild pointer or subscript. Null pointer assignment is a message you might get when an MS-DOS program finishes executing. 
	Some such programs can arrange for a small amount of memory to be available \93where the NULL pointer points to (so to speak). If the program tries to write to that area, it will overwrite the data put there by the compiler.
	When the program is done, code generated by the compiler examines that area. If that data has been changed, the compiler-generated code complains with null pointer assignment. 
	This message carries only enough information to get you worried. There\92s no way to tell, just from a null pointer assignment message, what part of your program is responsible for the error. 
	Some debuggers, and some compilers, can give you more help in finding the problem.
	Bus error: core dumped and Memory fault: core dumped are messages you might see from a program running under UNIX. They\92re more programmer friendly. Both mean that a pointer or an array subscript was wildly out of bounds.
	You can get these messages on a read or on a write. They aren\92t restricted to null pointer problems. The core dumped part of the message is telling you about a file, called core, 
	that has just been written in your current directory. This is a dump of everything on the stack and in the heap at the time the program was running. 
	With the help of a debugger, you can use the core dump to find where the bad pointer was used.  That might not tell you why the pointer was bad, but it\92s a step in the right direction. 
	If you don\92t have write permission in the current directory, you won\92t get a core file, or the core dumped message

What is static memory allocation and dynamic memory allocation?
	Static memory allocation: The compiler allocates the required memoryspace for a declared variable. By using the address of operator,thereserved address is obtained and this address may be assigned to apointer variable.
	Since most of the declared variable have staticmemory,this way of assigning pointer value to a pointer variable isknown as static memory allocation. 
	memory is assigned duringcompilation time.Dynamic memory allocation: It uses functions such as malloc( ) orcalloc( ) to get memory dynamically.
	If these functions are used to getmemory dynamically and the values returned by these functions areassingned to pointer variables, such assignments are known asdynamic memory allocation.
	memory is assined during run time.

What is memory leakage? How can we avoid it?
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

malloc vs calloc vs realloc ?
Is realloc() uses the same memory location which was used by malloc()?
Difference between arrays and pointers?
Is using exit() the same as using return?
declaring a variable vs defining a variable

create a custom malloc and free function using linked lists ?
set an integer variable at the absolute address 0x67a9 to the value 0xaa55?
	int *ptr;
	ptr = (int *)0x67a9;
	*ptr = 0xaa55;

	A more obfuscated approach is:
	*(int * const)(0x67a9) = 0xaa55;

What is code optimization?
Typically, this new key word is __interrupt. The following code uses __interrupt to define an interrupt service routine. Comment on the code?
	__interrupt double compute_area(double radius) {
		double area = PI * radius * radius;
		printf(\93nArea = %f\94, area);
		return area;
	}

	This function has so much wrong with it, it\92s almost tough to know where to start.
	(a) Interrupt service routines cannot return a value. If you don\92t understand this, then you aren\92t hired.
	(b) ISR\92s cannot be passed parameters. See item (a) for your employment prospects if you missed this.
	(c) On many processors / compilers, floating point operations are not necessarily re-entrant. In some cases one needs to stack additional registers, in other cases,
		one simply cannot do floating point in an ISR. Furthermore, given that a general rule of thumb is that ISRs should be short and sweet, one wonders about the wisdom of doing floating point math here.
	(d) In a similar vein to point (c), printf() often has problems with reentrancy and performance.

What is a memory leak? What is a segmentation fault?*
what is stack  overflow and heap overflow?
what is a core dump?
	A core dump is the recorded state of the working memory of a computer program at a specific time, generally when the program has terminated abnormally includes the program counter and stack pointer, 
	memory management information, and other processor and operating system flags and information a fatal error usually triggers the core dump, often buffer overflows, 
	where a programmer allocates too little memory for incoming or computed data, or access to null pointers, a common coding error when an unassigned memory reference variable is accessed.
	
What is a stack frame, stack pointer & frame pointer ?
write a code  to check whether a stack  grows upwards or downwards?
Tell the role of brk() in malloc / Tell the relation between heap and brk?
Tell the relation between Malloc and MMAP

What does the following code fragment output and why?
	char *ptr;
	if ((ptr = (char *)malloc(0)) == NULL) {
		puts(\93Got a null pointer\94);
	}
	else {
		puts(\93Got a valid pointer\94);
	}
	
	Note: malloc(0) gives a valid pointer but allocate zero bytes.
	
What is the difference between declaring a variable and defining a variable?
	 Declaring a variable means describing its type to the compiler but notallocating any space for it. Defining a variable means declaring it andalso allocating space to hold the variable.
	 You can also initialize avariable at the time it is defined.

why n++ executes faster than n+1? 
	The expression n++ requires a single machine instruction such as INR to carry out the increment operation whereas, n+1 requires more instructions to carry out this operation.
		
When does the compiler not implicitly generate the address of the first element of an array?
	Whenever an array name appears in an expression such as
		array as an operand of the size of operator
		array as an operand of & operator
		array as a string literal initializer for a character array
	Then the compiler does not implicitly generate the address of the address of the first element of an array.

Why doesn't the following statement work?
	char str[ ] = "Hello" ;
	strcat ( str, '!' ) ;

	The string function strcat( ) concatenates strings and not a character. The basic difference between a string and a character is that a string is a collection of characters, 
	represented by an array of characters whereas a character is a single character. To make the above statement work writes the statement as shown below:
	strcat ( str, "!" ) ;

string:
What is string?
	The string in C programming language is actually a one-dimensional array of characters which is terminated by a null character '\0'. Thus a null-terminated string containn
	the characters that comprise the string followed by a null.

What is difference between these two,
	char ptr[] = "string";
	char *ptr = "string";
	
	The two declarations are not the same.
	First one is the array of character i.e. string and second one is the string literals.
	char ptr[] = "string"; declares a char array of size 7 and initializes it with the characters s ,t,r,i,n,g and \0. You are allowed to modify the contents of this array.
	char *ptr = "string"; declares ptr as a char pointer and initializes it with address of string literal "string" which is read-only. Modifying a string literal is an undefined behavior. 
	What you saw(seg fault) is one manifestation of the undefined behavior.

What is the difference between strings and character arrays?
	A major difference is: string will have static storage duration, whereasas a character array will not, unless it is explicity specified by using thestatic keyword.
	Actually, a string is a character array with following properties: 
	the multibyte character sequence, to which we generally call string,is used to initialize an array of static storage duration. 
		The size of thisarray is just sufficient to contain these characters plus the terminatingNUL character.
	it not specified what happens if this array, i.e., string, is modified.
	Two strings of same value[1] may share same memory area. Forexample, 
	
		in the following declarations:
		char *s1 = \93Calvin and Hobbes\94;
		char *s2 = \93Calvin and Hobbes\94;
		the strings pointed by s1 and s2 may reside in the same memorylocation. 
		But, it is not true for the following:
		char ca1[] = \93Calvin and Hobbes\94;
		char ca2[] = \93Calvin and Hobbes\94;
		The value of a string is the sequence of the values of the containedcharacters, in order.
		
Find a word from string?
write a program to find repeated character in a given string? code should be generic?
Implement string reverse program without using temporary buffer and strrev function?
Write a program to implement memcpy() on your own 
Difference between library call and a system call
Write a program to count total number of vowel,consonant present in given string?
Write a program to check weather  string is palindrome or not?
Can we increment the base address of array? Justify your answer.
What is difference between array and pointer?

string vs array?
	Merits:
	(a) We can easily access each element of array.
	(b) Not necessity to declare too many variables.
	(c) Array elements are stored in continuous memory location.
	Demerits:
	(a) Wastage of memory space. We cannot change size of array at the run time.
	(b) It can store only similar type of data
	
write a shortest string copy function?
while (*str++ = *dst++) 
{}

What is the difference between a string copy (strcpy) and a memory copy (memcpy)? When should each be used? when we should strncpy()?
	The strcpy() function is designed to work exclusively with strings. It copies each byte of the source string to the destination string and stops when the terminating null character (\0) has been moved. 
	On the other hand, the memcpy() function is designed to work with any type of data.
	Because not all data ends with a null character, you must provide the memcpy() function with the number of bytes you want to copy from the source to the destination.
	strncpy()= to copy a portion of a string.
	
What is the output of following program?
	int main()
	{
		  char str[] = "vishnu";
		  printf("%d %d\n",sizeof(str),strlen(str));
	}
	Here char str[] = " 'v'. 'i' ,'s','h','n',u','\0' ";
	so sizeof operator always count null character whereas strlen skip null character.

Write a program to implement strlen(), strcpy(), strncpy(), strrev(), strcmp() function"?
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

Write a program to check weather  string is palindrome or not?
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

What is the difference between a string copy (strcpy) and a memory copy (memcpy)? When should each be used?
	The strcpy() function is designed to work exclusively with strings. It copies each byte of the source string to the destination string and stops when the terminating null character (\0) has been moved. 
	On the other hand, the memcpy() function is designed to work with any type of data.
	Because not all data ends with a null character, you must provide the memcpy() function with the number of bytes you want to copy from the source to the destination. 
	The following program shows examples of both thestrcpy() and the memcpy() functions:

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

	When dealing with strings, you generally should use the strcpy() function, because it is easier to use with strings. 
	When dealing with abstract data other than strings (such as structures), you should use the memcpy()function.
	
How can I remove the trailing spaces from a string?
	The C language does not provide a standard function that removes trailing spaces from a string. It is easy, however, to build your own function to do just this. 
	The following program uses a custom function namedrtrim() to remove the trailing spaces from a string. It carries out this action by iterating through the string backward, 
	starting at the character before the terminating null character (\0) and ending when it finds the first nonspace character. When the program finds a nonspace character, 
	it sets the next character in the string to the terminating null character (\0), thereby effectively eliminating all the trailing blanks. Here is how this task is performed:

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

	Notice that the rtrim() function works because in C, strings are terminated by the null character. With the insertion of a null character after the last nonspace character, 
		the string is considered terminated at that point, and all characters beyond the null character are ignored.

How can I remove the leading spaces from a string?
	The C language does not provide a standard function that removes leading spaces from a string. It is easy, however, to build your own function to do just this. 
	you can easily construct a custom function that uses thertrim() function in conjunction with the standard C library function strrev() to remove the leading spaces from a string. Look at how this task is performed:

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

	Notice that the ltrim() function performs the following tasks: First, it calls the standard C library functionstrrev(), which reverses the string that is passed to it. 
	This action puts the original string in reverse order, thereby creating "trailing spaces" rather than leading spaces. Now, the rtrim() function is used to remove the "trailing spaces" from the string. 
	After this task is done, the strrev() function is called again to "reverse" the string, thereby putting it back in its original order.

How can I copy just a portion of a string?
	You can use the standard C library function strncpy() to copy one portion of a string into another string. Thestrncpy() function takes three arguments: the first argument is the destination string, 
	the second argument is the source string, and the third argument is an integer representing the number of characters you want to copy from the source string to the destination string. 
	For example, consider the following program, which uses thestrncpy() function to copy portions of one string to another:

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

	The first call to strncpy() in this example program copies the first 11 characters of the source string intodest_str1. This example is fairly straightforward, one you might use often. 
	The second call is a bit more complicated and deserves some explanation. In the second argument to the strncpy() function call, the total length of the source_str string 
	is calculated (using the strlen() function). Then, 13 (the number of characters you want to print) is subtracted from the total length of source_str. This gives the number of 
	remaining characters in source_str. This number is then added to the address of source_str to give a pointer to an address in the source string that is 13 characters from the end of source_str.

	Then, for the last argument, the number 13 is specified to denote that 13 characters are to be copied out of the string. The combination of these three arguments in the second call 
	to strncpy() sets dest_str2 equal to the last 13 characters of source_str.
	The example program prints the following output:

	How about that! dest_str1 is now: 'THIS IS THE'!!!
	Whoa! dest_str2 is now: 'SOURCE STRING'!!!

	Notice that before source_str was copied to dest_str1 and dest_st2, dest_str1 and dest_str2 had to be initialized to null characters (\0). 
	This is because the strncpy() function does not automatically append a null character to the string you are copying to. Therefore, you must ensure that you have put the 
	null character after the string you have copied, or else you might wind up with garbage being printed.


How can I convert a number to a string?
	Notice that the itoa() function takes three arguments: the first argument is the number you want to convert to the string, the second is the destination string to put the converted number into,
	and the third is the base, or radix, to be used when converting the number. The preceding example uses the common base 10 to convert the number to the string.
	The following functions can be used to convert integers to strings:
	Function Name		Purpose
	itoa()	-	Converts an integer value to a string.
	ltoa()	-	Converts a long integer value to a string.
	ultoa()	-	Converts an unsigned long integer value to a string.
	Note that the itoa(), ltoa(), and ultoa() functions are not ANSI compatible. An alternative way to convert an integer to a string (that is ANSI compatible) is to use the sprintf() function.

How can I convert a string to a number?
	To use the atoi() function, you simply pass it the string containing the number you want to convert. The return value from the atoi() function is the converted integer value.
	The following functions can be used to convert strings to numbers:
	Function Name		Purpose
	atof()	-	Converts a string to a double-precision floating-point value.
	atoi()	-	Converts a string to an integer.
	atol()	-	Converts a string to a long integer.
	strtod()	-	Converts a string to a double-precision floating-point value and reports any "leftover" numbers that could not be converted.
	strtol()	-	Converts a string to a long integer and reports any "leftover" numbers that could not be converted.
	strtoul()	-	Converts a string to an unsigned long integer and reports any "leftover" numbers that could not be converted.
	Sometimes, you might want to trap overflow errors that can occur when converting a string to a number that results in an overflow condition. 
	The following program shows an example of the strtoul() function, which traps this overflow condition:

How do you print only part of a string?
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

	
structure union bitfield:
What is difference between Structure and Unions?
	(i)    In structure every member has its own memory whereas in union its members share the same member space.
	(ii)  In structure, it is possible to initialize all the members at the same time which is not possible in case of union.
	(iii) A structure requires more space than union(for the same type of members).
	(iv) In union different interpretations of the same memory space are possible which is not so in case of structures.
	
	advantages of using Unions?
	(i) Efficient use of memory as it it does not demand memory space for its all members rather it require memory space for its largest member only.
	(ii) Same memory space can be interpreted differently for different members of the union
when should unions be used? Why do we need them in Embedded Systems  programming?
	Unions are particularly useful in Embedded programming or in situations where direct access to the hardware/memory is needed.
	Here is a trivial example:

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

Data Alignment & Structure Padding?
	Data Alignment: Data alignment means putting the data at a memory offset equal to some multiple of the word size, which increases the system\92s performance due to the way the CPU handles memory
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
		char Padding1[1]; /* 1 byte for the following 'short' to be aligned on a 2 byte boundary assuming that the address where structure begins is an even number */
		short Data2; /* 2 bytes */
		int Data3;  /* 4 bytes - largest structure member */
		char Data4; /* 1 byte */
		char Padding2[3]; /* 3 bytes to make total size of the structure 12 bytes */
	};

	The compiled size of the structure is now 12 bytes. It is important to note that the last member is padded with the number of bytes required 
	so that the total size of the structure should be a multiple of the largest alignment of any structure member (alignment(int) in this case, which = 4 on linux-32bit/gcc)
	In this case 3 bytes are added to the last member to pad the structure to the size of a 12 bytes (alignment(int) \D7 3).

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
	It is possible to change the alignment of structures to reduce the memory they require (or to conform to an existing format) by reordering structure members or changing the compiler\92s alignment (or \93packing\94) of structure members.
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


Why is it usually a bad idea to use gets()? Suggest a workaround?
	The function gets() reads characters from the stdin and stores them at the provided input buffer. However, gets() will keep reading until it encounters a newline character. 
	Unless the buffer is large enough, or the length of the line being read is known ahead of time, gets() can potentially overflow the input buffer and start overwriting memory it is not supposed to,
	wreaking havoc or opening security vulnerabilities.

	One way to work around this issue is to use fgets(). It allows you to put a limit on the maximum number of characters to read:
	fgets(b, 124, stdin);
	
What is setup hold time?
	Setup time is the time the data should be held constant before the arrival of the clock edge.
	Set Up time is Minimum Amount of time During which Data Signal Should be Stable Before the Clock made a Valid[Low-to-High] Transition. 
	Hold time is the Minimum Amount of time After the Clock Made a Valid Transition During which Data Signal Should Stable.
	
What is mmap?
	In computing, mmap is a POSIX-compliant Unix system call that maps files or devices into memory. It is a method of memory-mapped file I/O. 
	It naturally implements demand paging, because initially file contents are not entirely read from disk and do not use physical RAM at all. 
	The actual reads from disk are performed in lazy manner, after a specific location is accessed. After the memory is not to be used, 
	it is important to munmap the pointers to it.

Is it necessary to start the execution of a program from the main() in C?*.
Explain Order of constructor and destructor call in case of multiple inheritance?

Multithreading:
Can a child process be called as a thread ?
Is it possible for the thread to be alive if we terminate the process ? Is it possible for a child process to be alive if we terminate the parent process ? 
What is the difference between multithreading and multiprocessing ?
If we declare a variable in the thread handler of 1st thread, will it be accessible accessible to 2nd thread ?
If we declare one variable locally in process and another globally in process, which one will be accessible to its threads ? Will those variable be available in child process also ?
What is TLS ?
Who schedules the processes and who schedules the threads ?
What are the contents of PCB ? What are the contents of TCB ?
How to ensure that thread1 gets terminated before thread2 ?
What is atomicity ? Where are atomic operations useful ?
What is the use of PID ?
What are the various thread models and tell the scenario in which the particular thread model is useful / beneficial ?
What are the advantages & dis-advantages of 1:N user level threading (thread model)?
What is the difference between userspace threads and kernel space threads ?
Will a crash of a thread impact the other thread of the process ?
What is the difference between pthread_create() and fork() ?
What information is shared between a child process and the parent process ?
If a parent has 2 threads , will the child process also inherit or have a copy of those 2 threads ?
Why a faulty pointer does not crash a process but that of a thread can corrupt the process / other threads of the process ?
What will happen if you call a sleep() in a process or thread ?
What is the common mode of communication between a parent process and child process ? What are the modes of communication between threads ?
What steps are performed during a context switch of a thread and what steps are performed during a context switch of a process ?
how a func from one user process can be called in other user process ?	
write a program using two thread . one thread should print odd number and other should even number in sequesnce? how you can make it SMP safe ?
how to make it SMP safe in user space?
implemet your own string system call ? 

cbasic:
Data type :
	. Primary (primitive, fundamental) data types : char, int, flot, double, void.
	. Drived data types : array,function, pointer.
	. user defined : enum, struct, union.

Note : default data type is signed int.
Note : size of primitive data type in c depends upon the word length of the microprocessor. 
	In general we can say size of int is word length of microprocessor.
Note : Why range of signed char is -128 to 127 not -127 to 128?
Note : How to remember size of data type in c? ans : <limits.h>

variable is container of data.
Variable Attributes :
	. Name [identifier]
	. Value
	. Address

Name:
Note: In c any name is called identifier. 
This name can be variable name, function name, enum constant name, micro constant name, goto label name, 
any other data type name like structure, union, enum names or typedef name.

Value : 
Data which any variable keeps is known as value of variable.
Note : Name of variable always returns value of the variable.

Lvalue = Rvalue
LValue must be any variable in c it cannot be a constant, function or any other data type of c.

Note :
LValue cannot be a integer constant, macro contant, const variable, data type and enum const. 

Address:
Location in a memory where a variable stores its data or value is known as address of variable. 
To know address of any variable c has provided a special unary operator & which is known as deference operator or address operator. 
This operator is only used with variables not with the constant.

Note:
We cannot write: &&a, because:
&&a=& (&a) =& (address of variable a) =& (a constant number)
And we cannot use address operator with constant.

Note : it is not possible to have two variable with same name with same visibility. 
	But it is possible that two variable with same name but different visibility.
	In this case variable name can access only that variable which is more local. 
	In c there is not any way to access global variable if any local variable is present of same name.

Important points about address of variables in c:

1. Address of any variable in c is an unsigned integer. 
It cannot be a negative number. So in printf statement we should use %u instead of %d, to print the address of any variable.
%d: It is used to print signed decimal number.
%u: It is used to print unsigned decimal number.
Since, if the address of any variable will beyond the range of signed short int it will print a cyclic value.

2. A programmer cannot know at which address a variable will store the data. It is decided by compiler or operating system.
3. Any two variables in c cannot have same physical address.
4. Address of any variable in c is not integer type so to assign an address to a integral variable we have to type cast the address.

Address arithmetic in c:

1. We can subtract address of any two variables but cannot add, multiply, divide two addresses.
2. we can add or subtract a integer number with address.
3. Other operators which can be used with addresses are:
(a) Negation operator: !
(b) Size operator: sizeof
(c) Type casting operator: (Type)
(e) Deference operator: *
(f) Logical operator: &&, ||

Modifiers : which modify the meaning the basic data type in c.

	group		modifier
1. Size modifier	short, long
2. Signed modifier	signed, unsigned
3. Constant modifier	const , not const
4. Volatile modifier	volatole, non volatile
5. Storage class	auto, register, static, extern

Note :
1. Default modifier of storage class is auto when we declared the variable inside any function 
and default modifier of storage class is static when we declared variable outside of all functions. 
In other word we can say if variable has declared locally then default storage class is auto and if 
it has declared globally then default storage class of variable is extern.

2. Default storage class of function is extern.

Rules for using modifier in c:
1. We cannot use two modifiers of same groups in any particular data type of c.
2. We can write modifier either before the data type or after the data type.
3. Order of modifier including data type doesn\92t affect the meaning of declaration.
4. There is one exception in rule 3. POINTER, FUNCTION and INTERRUPT modifier must be written after the data type.

const modifier :
1. You can assign the value to the constant variables only at the time of declaration.
2. Uninitialized constant variable is not cause of any compilation error. But you cannot assign any value after the declaration.
Note : If you have declared the uninitialized variable globally then default initial value will be zero in case of integral data type 
	and null in case of non-integral data type. 
	If you have declared the uninitialized const variable locally then default initial value will be garbage.
3. Constant variables executes faster than not constant variables.
4. You can modify constant variable with the help of pointers.

https://stackoverflow.com/questions/1143262/what-is-the-difference-between-const-int-const-int-const-and-int-const

const char *ptr :
	ptr is a pointer to a char, where you can't change the value of the char (at least not through the pointer 
	(without casting the constness away)).
char * const ptr :
	ptr is a constant pointer to a char, where you can change the char, but you can't make the pointer point to a different char.
const char *const ptr:
	ptr is a constant pointer to a constant char, i.e. you can change neither where the pointer points nor the value of the pointee.

Now the first const can be on either side of the type so:

const int * == int const *
const int * const == int const * const

If you want to go really crazy you can do things like this:

int ** - pointer to pointer to int
int ** const - a const pointer to a pointer to an int
int * const * - a pointer to a const pointer to an int
int const ** - a pointer to a pointer to a const int
int * const * const - a const pointer to a const pointer to an int

volatile :
1. A volatile variable can be changed by the background routine of preprocessor. 
This background routine may be interrupt signals by microprocessor, threads, real times clocks etc.

2. In simple word we can say a value volatile variable which has stored in the memory can be by any external sources.

3. Whenever compiler encounter any reference of volatile variable is always load the value of variable from memory 
so that if any external source has modified the value in the memory complier will get its updated value.

4. Working principle of volatile variable is opposite to the register variable in c. 
Hence volatile variables take more execution time than non-volatile variables.

Question: What is meaning of following declaration in c?
const volatile float f;
register volatile char c;

storage class :

Storage class is modifier or qualifier of data types which decides:
1. In which area of memory a particular variable will be stored?  
2. What is scope of variable?
3. What is visibility of variable? 

Visibility :  means accessibility. Up to witch part or area of a program can be access.
Scope : Meaning of scope is to check either variable is alive or dead. Alive means data of a variable has not destroyed from memory.
	Up to which part or area of the program a variable is alive, that area or part is known as scope of a variable.

scope types:
1. Block scope.
2. Function scope.
3. File scope.
3. Program scope.

storage class Types:

storage class		declared	scope 		visibility
1. auto
			Globel		
			local		block		block
2. register		
			globel		
			local		block		block
3. static
			globel		program		file
			local		program		block
4. extern
			globel		program		program
			local		program		block

auto :
Automatic variables or auto variables are default storage class of local variable. An auto variable cannot be declared globally. (Why?)
Properties :
1. Default initial value of auto variable is garbage.
2. Visibility of auto variable is within the block where it has declared.
3. Scope of auto variable is within the block where it has declared.
4. auto variable initialize each time.
5. An auto variable gets memory at run time.

register :
All register variable in c stores in CPU not in the memory.

properties :
1. register int a; We are only requesting not forcing to compiler to store variable a in CPU.
2. A register variable execute faster than other variables because it is stored in CPU 
	so during the execution compiler has no extra burden to bring the variable from memory to CPU.
3. Since a CPU have limited number of register so it is programmer responsibility which variable should declared 
	as register variable i.e. variable which are using many times should declared as a register variable.
4. We cannot dereference register variable since it has not any memory address.
5. Default initial value of register variable is garbage.
6. Scope and visibility of register variable is block.

static :
properties :
1. It is not default storage class of global variables.
2. Default initial value of static integral type variables are zero otherwise null.
3. A same static variable can be declared many times but we can initialize at only one time.
4. We cannot write any assignment statement globally.
Note: Assigning any value to the variable at the time of declaration is known as initialization 
	while assigning any value to variable not at the time of declaration is known assignment.
5. A static variable initializes only one time in whole program.
6. If we declared static variable locally then its visibility will within a block where it has declared.
7. If declared a static variable or function globally then its visibility will only the file 
	in which it has declared not in the other files.

extern :
properties:
1. It is default storage class of all global variables as well all functions.
2. When we use extern modifier with any variables it is only declaration i.e. memory is not allocated for these variable.
3. If you will not use extern keyword with global variables then compiler will automatically 
	initialize with default value to extern variable.
4. Default initial value of extern integral type variable is zero otherwise null.
5. We cannot initialize extern variable locally i.e. within any block either at the time of declaration or separately. 
	We can only initialize extern variable globally.
6. If we declare any variable as extern variable then it searches that variable either it has been initialized or not. 
	If it has been initialized which may be either extern or static* then it is ok otherwise compiler will show an error.
7. A particular extern variable can be declared many times but we can initialize at only one time.
8. We cannot write any assignment statement globally.
9. If declared an extern variables or function globally then its visibility will whole the program 
	which may contain one file or many files.

switch case :

switch(expression) {

	case constant-expression  :
		statement(s);
      		break; /* optional */
	
   	case constant-expression  :
   	   	statement(s);
   	   	break; /* optional */
  
   	/* you can have any number of case statements */
   	default : /* Optional */
   		statement(s);
}

properties :

1. If we will not use break keyword in each case the program control will come in each case after the case
	witch satisfy the switch condition.
2. We can write case statement in any order including the default case. That default case may be first case, 
	last case or in between the any case in the switch case statement.
3. Case expression cannot be constant variable, string const.
4. Case expression can be enum constant, character constant, macro constant.
5. Case expression must be integral constant expression. If it is not integer then it is automatically type casted into integer value.
6. duplicate case is not possible.
7. switch expression must return an integer value. It cannot be float, double or long double
8. switch case statement program control always move from the case which satisfy the switch condition 
	and end with either break keyword, terminating} or any null character which will come first.
9. it is possible a switch case statement without any case but it is meaning less.
10. We cannot use continue keyword in switch case. It is part loop.
11. Nesting of switch case is possible in c.
12. It is possible to write label of goto statement in the case of switch case statement.
13. We can not declare any variable in any case of switch case statement.
14.  switch case will not affect the value of variable a.
	Also sizeof operator doesn't affect the value of the any variable
15. The expression used in a switch statement must have an integral or enumerated type, or be of a class type 
	in which the class has a single conversion function to an integral or enumerated type.


Loop :
Looping is the process of repeating of same code until a specific condition doesn\92t satisfy.

types :

1. while
2. do while
3. for

for (Expression 1; Expression 2; Expression 3) {
	Loop body
}

Expression 1:
It is called initialization expression. Task of this expression is to initialize the looping variables.

Properties of expression 1:
1. Expression1 can initialize the more than one variable.
2. Expression1 is optional.
3. we cannot declare the variable at the expression1.

Expression 2: 
It is called as conditional expression. Task of expression is to check the condition and if it is false then it terminates the loop.

Properties of expression2:
1.  Expression2 can have more than one checking condition and if any condition is false loop will terminate.
2. it is also optional.
3. It can perform task of expression1 as well as expression3. That is it can initialize the variables as well as increment the variables.
4. If expression2 is zero means condition is false and any non zero number means condition is true.

Expression 3:
It is called as instrumentation expression. Task of this expression is to increment the variable. 

Properties:
1. We can increment more than one variable at the same time in the expression3.
2. it is also optional.

Loop body:
Loop body contains the part of code which we have to execute multiple numbers of times.

Properties of loop body:
1. If loop body contain only one statement then brace is optional.
2. Loop without body is possible.
3. Braces of loop body behave as block.

While loop:
while (Expression) {
Loop body
}

Properties of while loop:
1. Task of the expression is to check the condition. Loop will execute until condition is true otherwise loop will terminate.  
2. If any expression returns zero then condition will false and if it returns any non- zero number then condition will true.
3. In while loop condition expression is compulsory.
4. While loop without any body is possible.
5. In while loop there can be more than one conditional expression.
6. If loop body contain only one statement the brace is optional.

do while :
It is also called as post tested loop. It is used when it is necessary to execute the loop at least one time. Syntax:

do {
	Loop body
} while (Expression);

break keyword in c:
It is keyword of c programming. Task of this keyword is to bring the control from out of the loop in the case of looping.
Another task of break keyword is to switch the control from one case to another case in case of switch case control statement.

continue:
It is keyword of c and task of this keyword is to transfer the control of program at the beginning of loop.

goto statement :
Transfers control to the labeled statement.

Array :
An array is derived data type in c programming language which can store similar type of data in continuous memory location. 
Data may be primitive type (int, char, float, double\85), address of union, structure, pointer, function or another array.

syntex :
data type arrayname [ arraysize ] = { elements };

Array is useful when:
1. We have to store large number of data of similar type. If we have large number of similar kind of variable 
	then it is very difficult to remember name of all variables and write the program.
2. We want to store large number of data in continuous memory location. Array always stores data in continuous memory location.
3. The number of values between braces { } cannot be larger than the number of elements that we declare for the array
	 between square brackets [ ].
4. Arrays have 0 as the first index not 1.
5. If the size of an array is n, to access the last element, (n-1)
6. Array name is constant pointer and we cannot assign any value in constant data type after declaration.
eg. 
char arr[10];
arr = "world";
7. Size of any character array cannot be less than the number of characters in any string which it has assigned. 
	Size of an array can be equal (excluding null character) or greater than but never less than.
8. Size of any array in c cannot be constantan variable but it can be enum const and macro const.
9. Member of an array cannot be address of auto variable because array gets memory at load time 
	while auto variable gets memory at run time.
10. If we initialize any array at the time of declaration the compiler will treat such array as static variable 
	and its default value of uninitialized member is zero.

Note: In any expression lower type data is always automatically type casted into the higher data type.

Advantage of using array:
1. An array provides singe name .So it easy to remember the name of all element of an array.
2. Array name gives base address of an array .So with the help increment operator we can visit one by one all the element of an array.
3. Array has many application data structure.

Array of pointers in c:
Array whose content is address of another variable is known as array pointers.

strings :
Strings are actually one-dimensional array of characters terminated by a null character '\0'. 
Thus a null-terminated string contains the characters that comprise the string followed by a null.

intilization of strings :

using array :

char c[] = "abcd";
     OR,
char c[50] = "abcd";
     OR,
char c[] = {'a', 'b', 'c', 'd', '\0'};
     OR,
char c[5] = {'a', 'b', 'c', 'd', '\0'};

using pointer :

char *c = "abcd";


structure :

struct [structure tag] {

   member definition;
   member definition;
   ...
   member definition;
} [one or more structure variables];  

Union :

union [union tag] {
   member definition;
   member definition;
   ...
   member definition;
} [one or more union variables];

Bit field :

struct < identifier > {
	type member_variable_name: size_in_bits;
};

identifier : the name of the bit field that is being declared. 
	The name is optional: nameless bitfields introduce the specified number of bits of padding
size_in_bits : an integral constant expression with a value greater or equal to zero. 
	When greater than zero, this is the number of bits that this bit field will occupy. 
	The value zero is only allowed for nameless bitfields and has special meaning: 
	it specifies that the next bit field in the class definition will begin at an allocation unit's boundary.

eg. 
struct S {
 // three-bit unsigned field,
 // allowed values are 0...7
 unsigned int b : 3;
};

enum :

enum identifier <optional> { const1, const2, ..., constN };

enumerator = constant-expression ;

identifier, enumerator 	- 	identifiers that are introduced by this declaration
constant-expression 	- 	integer constant expression whose value is representable as a value of type int

Here, name of the enumeration is identifier.
And, const1, const2,...., constN are values of type identfier.
By default, const1 is 0, const2  is 1 and so on. You can change default values of enum elements during declaration (if necessary).

typedef :
typedef is a keyword used in C language to assign alternative names to existing types. 
Its mostly used with user defined data types, when names of data types get slightly complicated.

typedef existing_name alias_name;

eg.
typedef struct member
{
  type member1;
  type member2;
  type member3;
} type_name ;

type_name v1, v2.


pointer :

opertor		precedence		associative
(), []		1			L -> R
*, identifier	2			R -> L
data type	3			

(): This operator behaves as bracket operator or function operator.
[]: This operator behaves as array subscription operator.
*: This operator behaves as pointer operator not as multiplication operator.

Identifier: It is not an operator but it is name of pointer variable. You will always find the first priority 
will be assigned to the name of pointer.

Data type: It is also not an operator. Data types also includes modifier (like signed int, long double etc.)

How to read complex pointer :

void (*ptr)( int (*)[2], int (*)[3]);
ptr is pointer to such function which first parameter is pointer to one dimensional array of size two 
which content int type data and second parameter is pointer to such function which parameter is void 
and return type is int data type and return type is void.

int ( * ( * ptr ) [ 5 ] ) ( );
ptr is pointer to such array of size five which content are pointer to such function 
which parameter is void and return type is int type data.

double*(*(*ptr)(int))(double **,char c);
ptr is pointer to function which parameter is int type data and return type is pointer to function 
which first parameter is pointer to pointer of double data type and second parameter is char type data type 
and return type is pointer to double data type.

Rule 1: Arithmetic operation with pointer :
Address + Number= Address
Address - Number= Address

Address++ = Address
Address-- = Address

++Address = Address
--Address = Address

New address = old address + number sizeof(data type) which ponter is pointing.
New address = old address - number * Size of data type to which pointer is pointing

Rule 2: Difference arithmetic with pointers
If two pointers are of same type then:
adr2 - addr1 = ( simple subtraction of two address) / size of data type which pointer points.

Rule 3: Illegal arithmetic with pointers:
Address + Address=Illegal
Address * Address=Illegal
Address / Address=Illegal
Address % Address=Illegal

Rule 4: Bit wise arithmetic with pointers
We can perform bit wise operation between two pointers like

Address & Address=Illegal
Address | Address=Illegal
Address ^ Address=Illegal
~Address=Illegal

Rule 5: We can find size of a pointer using sizeof operator.

tricks :
*array = *(array +0) = array[0];
arr[0] = &arr1;
p[i] = *(p+i) : P[0][0][0]=*(p[0][0]+0)=**p[0]=***p
*(p+i) = p[i]
*&i = i
-> = (*).
Rule: * and & always cancel to each other

Note: %s is used to print stream of characters up to null (\0) character.

Generic pointer:
void pointer in c is known as generic pointer. Literal meaning of generic pointer is a pointer which can point type of data.
Example:
void *ptr;
Here ptr is generic pointer.

1. We cannot dereference generic pointer.
2. We can find the size of generic pointer using sizeof operator.
3. Generic pointer can hold any type of pointers like char pointer, struct pointer, array of pointer etc without any typecasting.
4. Any type of pointer can hold generic pointer without any typecasting.
5. Generic pointers are used when we want to return such pointer which is applicable to all types of pointers. 
	For example return type of malloc function is generic pointer because it can dynamically allocate the memory space to stores 
	integer, float, structure etc. hence we type cast its return type to appropriate pointer type.

NULL pointer:
Literal meaning of NULL pointer is a pointer which is pointing to nothing. NULL pointer points the base address of segment.

Examples of NULL pointer:
1. int *ptr=(char *)0;
2. float *ptr=(float *)0;
3. char *ptr=(char *)0;
4. double *ptr=(double *)0;
5. char *ptr=\92\0\92;
6. int *ptr=NULL;

What is meaning of NULL?
NULL is macro constant which has been defined in the heard file stdio.h, alloc.h, mem.h, stddef.h and stdlib.h as
#define NULL 0

We cannot copy any thing in the NULL pointer.

Wild pointer:
A pointer in c which has not been initialized is known as wild pointer.

There is difference between the NULL pointer and wild pointer. Null pointer points the base address of 
segment while wild pointer doesn\92t point any specific memory location.

Dangling pointer:

If any pointer is pointing the memory address of any variable but after some variable has deleted from that memory location 
while pointer is still pointing such memory location. Such pointer is known as dangling pointer 
and this problem is known as dangling pointer problem.

Solution of this problem: Make the variable as static variable.

Note: In some compiler you may get warning message returning address of local variable or temporary.

Function :

Properties :
1. If function definition has written after the function call then it is necessary to declare the function 
	before the function call because function call statement has no idea about prototype of calling function.

2.If function definition has written before the function call statement then it is not necessary to write function declaration.
3.If return type of function is signed int data type then it not necessary to write function declaration 
	even though function definition has written after the function call.
4.Function\92s declaration doesn\92t reserve any memory space.
5.In declaration statement it is not necessary to write variable name in parameter of function.
6. C doesn't support function overloading. In c it is not possible to declare two function of same name 
	but different signatures like number of parameters, data type of parameters, order of parameter etc.

Main function : 
Properties of main function:
1. Any c program can have only one main function.
2. main function is called by operating system.
3. main is not keyword of c. So any variable name can be main.
4. Programmer can also call the main function.
5. Default return type of main function is int and default parameter is void.

Prototype of main function in c:
int main (int arg_counter, char *arg_vector[], char *env_vector[]);
1. Argument counter: 
	First parameter of main function is argument counter. It stores an integer number which is equal to number of parameters 
	passed including file name from the command prompt.
2. Argument vector: 
	Second parameter of main function is argument vector. It is array which is array of string. 
	This string array contains the actual parameters which have passed from the command prompt.
3. Environment vector :
	Third parameter of main function is environment variable. It is also array of string which contains 
	all the environments variables of the system.



function declarations : Declaration of function is also known as prototype of a function.

<return type > <function name> ( < parameters >, ...)

Function defination :

<return type > <function name > ( < parameters >, ...) {
	/* body */
	statement 1;
	statment 2;
	...
	return [ < expression >];
}

Parameter of function can be:
1. Primitive data type.
2. Derived data type.
3. User defined data type.
4. Ellipsis i.e. variable number of parameter.
5. We can use modifier with data type in return type.

Note : parameter cannot be intilized as parameter in function in c.

How to pass parameters in the function in C :

Pass by value: 
In this approach we pass copy of actual variables in function as a parameter. 
Hence any modification on parameters inside the function will not reflect in the actual variable.

Pass by reference: 
In this approach we pass memory address actual variables in function as a parameter. 
Hence any modification on parameters inside the function will reflect in the actual variable.

Return type of a function: 

1. Default return type of function is signed int data type.
2. Function can return only one value at a time.
3. Storage classes allowed with return type are static, extern, typedef i.e. we cannot use auto and register storage class 
	with the return type of any function.
4. Default storage class of return type of a function is extern.
5. In return type we can use modifier like short, long, signed, unsigned, extern, static, const, volatile etc.

Return type of function can be:
1. Primitive data type: Primitive data types are: char, int, float, double, void.
2. Derived data types are: array, function, pointer.
3. User defined data types are: structure, union, enum.

How to calculate size of a function in c? 
	Size of function = Size of all local variable which has declared in function + Size of those global variables which 
	has used in function + Size of all its parameter+ Size of returned value if it is an address.

Recursion function :
Calling of same function from its function body is known as function recursion.It is alternative of loop.
Any c program which is possible using loop it must be possible using function recursion.

http://www.cquestions.com/2009/06/function-recursion-in-c-programming.html
How to write function recursion program in easier way:
Step1: First of all write same program using while loop and function. (Except main function)
Step 2: In that function make all local variable static.
Step 3: Replace while keyword by if.
Step 4: The increment or decrement of variable which is used for condition checking, replace with function call 
	and pass the parameter of that incremented or decremented variable.

properties :
1. It is very slow process.
2. Nature of function recursion is infinite loop or stack over flow.
3. It follows LIFO data structure.
4. We can use break keyword in function recursion.
5. We can not use goto to move the control from one function to another function.


preprocessors :
There are two operators in c preprocessor:
1. # : This operator is called stringizing operator which convert any argument in the macro function in the string. 
	So we can say pound sign # is string maker.
2. ## : This operator is called token pasting operator. When we use a macro function with various argument 
	then we can merge the argument with the help of ## operator.

#if directive in c
There are total six conditional compilation directives. There are:
(a)#if
(b)#elif
(c)#else
(d)#endif
(e)ifdef
(f)ifndef

Syntax 1:

#if <Constant_expression>
    -------------
    -------------
#endif

If constant expression will return 0 then condition will ture if it will return any non zero number condition will true.

Syntax 2:

#if <Constant_expression>
    -----------------
    -----------------
#else
    -----------------
    -----------------
#endif

Note: Consonant expression in #if condition should not include any c programming variable since all 
	preprocessor directives execute just before the actual c code.
Note: Constant expression in #if directive cannot be string constant. 
	It can be character constant which returns its ASCII value to directive.
