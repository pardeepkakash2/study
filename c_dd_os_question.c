Operating System Interview Questions :

Kernel Synchronization :
What are the differences between mutex and semaphore?
What is a race condition and How to avoid a race conditon?
What are atomic operations?
What is priority inversion and how to solve that problem?
what is difference between process and thread.
what is task_struct thread_info?
difference betwen fork() and vfork()
what is zombie and orphan process?how parent less process is handles in linux.
How context switching is handled in linux.
what is user preemption and kernel preemption
how system calls are implemented in linux.

 
Interrupts and interrupt handlers
what is interrupt and Types of interrupts e.g Software interrupts, Hardware interrupts, Edge Triggering and Level triggering ?
what is top halves and bottom halves [tasklets , softirq and workqueus].
what are the considerations needs to taken care while writing interrupt handler.
what are shared handlers.
what is interrupt context.
how to disable and enable interrupts.
what is ksoftirqd.
How do you register an interrupt handler on a shared IRQ line?
What is request_threaded_irq()
If same interrupts occurs in two cpu how are they handled?
How to synchronize data between 'two interrupts' and 'interrupts and process'.
How are nested interrupts handled?
Explain about the concurrent work queues.
diff b/w interrupt, signal,isr and callback ?
What happens if interrupt handler goes to sleep?
What happens if interrupt handler uses semaphores
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
What is a user thread and a kernel thread?
Number of kernel threads = cores?
Maximum number of threads per process in Linux?
	cat /proc/sys/kernel/threads-max
	There is also a limit on the number of processes (an hence threads) that a single user may create, see ulimit/getrlimit
	Linux implements max number of threads per process indirectly!!
	number of threads = total virtual memory / (stack size*1024*1024)
	ulimit -s
Which are the synchronization technoques you use 'between processes', 'between processe and interrupt' and 'between interrupts'; why and how ?
what is race condition and deadlock and hung task.
What are the differences between spinlock and mutex?
what is atomic operations.
what is preemption disabling and what is the use of this.
Which synchronization mechanism is safe to use in interrupt context and why?
Explain about the implementation of spinlock in case of ARM architecture.
Explain about the implementation of mutex in case of ARM architecture.
Explain about the notifier chains.
Explain about RCU locks and when are they used?
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
What is virtual memory and what are the advanatages of using virtual memory?
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
difference between insmod and modprobe.
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
zombiee and orphon process and How parent less process is handles in linux ?
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

What are good ways to debug memory corruption in C under Linux?
How do I debug a kernel module in which a NULL pointer appears?
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


Linux Kernel Debugging
What is Oops and kernel panic and how to understand the panic stack?
Does all Oops result in kernel panic?
What are the tools that you have used for debugging the Linux kernel?
What are the log levels in printk?
Can printk's be used in interrupt context?
How to print a stack trace from a particular function?
What's the use of early_printk( )?
Explan about the various gdb commands and features of gdb ?

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

What is the need of volatile constant in embedded systems?
What is difference  between inline function and macro?
Why can't we go for sleep while handling interrupt?
How nested interrupts are handled in ARM?
What are the benefits using FIQ?
What is reset vector
What is the significance of spinlock on uniprocessor system?
Difference between Monolithic kernel, Micro kernel and Hybrid kernel ?
What is priority inversion ?
What are the solutions for priority inversion ?
What is priority inheritance ?
What is priority ceiling ?
What is deadlock ?

What is the use of the method of temporarily masking / disabling interrupts ? When is it used ? What should be taken care while doing this method ?
Since, disabling/masking of interrupts can be done whent the critical section is ONLY SHORT,What method can be used if the critical section is longer than few source lines or if it involves few lengthy loopings ?
Even if we never enables interrupts in the code, the processor automatically disables them often during hardware access - True/False ? In this case how to reduce interrupt latency ?
When should we re-enable the interrupts in an ISR and why ?
How do you measure the latency of your system ?
What is data race ?
What is Indefinite Postponement / Indefinite blocking or starvation ?
How Many Processes or Threads Are Enough for an application ?

Networking & Telecom - I
Hey guys, few questions that can keep us discussing for sometime...

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
Why is the design of TCP servers mostly such that whenever it accepts a connection, a new process is invoked to handle it . But, why in the case of UDP servers, mostly there is only a single process that handles all client requests ?
Why does the client end of a connection use high port number(ephemeral ports) whereas the applications listen on typically small port numbers ?
When should you use UDP and When should you use TCP ? Also, give some realtime examples of applications that use TCP or UDP .
What is the difference between symbol rate and bit rate ?
What is BER (Bit error Rate / Bit Error Ratio)?
How will you Access userspace memory from kernel ? What are the various methods ?
What is the use of ioctl(inode,file,cmd,arg) ApI ?
What is the use of the poll(file, polltable) API ?
What is the use of file->private_data in a device driver structure ?
Difference between Timer Softirq and Tasklet Softirq ?

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

TODO :
Normal OS vs RTOS ? What is the difference between hard real-time and soft real-time OS? What type of scheduling is there in RTOS?
	RTOS: http://careerride.com/embedded-systems-interview-questions.aspx
	In an operating system, there is a module called the scheduler, which schedules different tasks and determines when a process will execute on the processor. This way, the multi-tasking is achieved. 
	The scheduler in a Real Time Operating System (RTOS) is designed to provide a predictable execution pattern. In an embedded system, a certain event must be entertained in strictly defined time.
	To meet real time requirements, the behaviour of the scheduler must be predictable. This type of OS which have a scheduler with predictable execution pattern is called Real Time OS(RTOS). The features of an RTOS are

    Context switching latency should be short.
    Interrupt latency should be short.
    Interrupt dispatch latency should be short.
    Reliable and time bound inter process mechanisms.
    Should support kernel preemption.
	Compatibility with several plugin devices.
	Deterministic operating system having guaranteed worst-case interrupt latency and context-switch times.
	Documentation providing for the minimum, average, and maximum number of clock cycles required by each system call.
	Overall it should be very reliable.

	A Hard real-time system strictly adheres to the deadline associated with the task. If the system fails to meet the deadline, even once, the system is considered to have failed. 
	In case of a soft real-time system, missing a deadline is acceptable. In this type of system, a critical real-time task gets priority over other tasks and retains that priority until it completes
	
	RTOS uses pre-emptive scheduling

Is it necessary to start the execution of a program from the main() in C?*.
Explain why cannot arrays be passed by values to functions?
Advantages and disadvantagesof using macro and inline functions?
	inline :A: 
	The ARM compilers support inline functions with the keyword __inline. This results ineach call to an inline function being substituted by its body, instead of a normal call. This
	results in faster code, but it adversely affects code size, particularly if theinline function islarge and used often.

How is function itoa() written in c ?
What is difference between micro processor & micro controller?
Explain Order of constructor and destructor call in case of multiple inheritance?
Explain Can structures be passed to the functions by value?

what is qualifiers? 
	Qualifiers defines the property of the variable. Two qualifiers are const and volatile. 

Can static variables be declared in a header file?
	you can’t declare a static variable without defining it as well (this isbecause the storage class modifiers static and extern are mutuallyexclusive). 
	A static variable can be defined in a header file, but thiswould cause each source file that included the header file to have its  own private copy of the variable, which is probably not what wasintended.
	
Can a static variable accessed from outside of the file?

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

Difference between syntax vs logical error?
	Syntax Error
	These involves validation of syntax of language.
	compiler prints diagnostic message.
	Logical Error
	logical error are caused by an incorrect algorithm or by a statement mistyped in such a way that it doesn’t violet syntax of language.difficult to find.

What is difference between Structure and Unions?
	(i)    In structure every member has its own memory whereas in union its members share the same member space.
	(ii)  In structure, it is possible to initialize all the members at the same time which is not possible in case of union.
	(iii) A structure requires more space than union(for the same type of members).
	(iv) In union different interpretations of the same memory space are possible which is not so in case of structures.
	
	advantages of using Unions?
	(i) Efficient use of memory as it it does not demand memory space for its all members rather it require memory space for its largest member only.
	(ii) Same memory space can be interpreted differently for different members of the union.
	
Using the #define statement, how would you declare a manifest contact that return the number of seconds in year? Disregard leap years in your answer?
	#define SECONDS_IN_YEAR (60UL * 60UL * 24UL * 365UL)
	
Write the “standard” MIN macro. That is, a macro that takes two arguments and returns the smaller of the two arguments

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

Compilation How to reduce a final size of executable?
What does static variable and function mean?
Can a static variable accessed from outside of the file?
Macro vs inline; Explain each of them; and which one is better why?


What does the keyword const mean? 
Const vs static vs #define?
	const char *ptr 		: ptr is a pointer to a char, where you can't change the value of the char (at least not through the pointer(without casting the constness away)).
	char * const ptr 		: ptr is a constant pointer to a char, where you can change the char, but you can't make the pointer point to a different char.
	const char *const ptr	: ptr is a constant pointer to a constant char, i.e. you can change neither where the pointer points nor the value of the pointee.
	
What is the difference between strings and character arrays?
	A major difference is: string will have static storage duration, whereasas a character array will not, unless it is explicity specified by using thestatic keyword.
	Actually, a string is a character array with following properties: 
	the multibyte character sequence, to which we generally call string,is used to initialize an array of static storage duration. 
		The size of thisarray is just sufficient to contain these characters plus the terminatingNUL character.
	it not specified what happens if this array, i.e., string, is modified.
	Two strings of same value[1] may share same memory area. Forexample, 
	
		in the following declarations:
		char *s1 = “Calvin and Hobbes”;
		char *s2 = “Calvin and Hobbes”;
		the strings pointed by s1 and s2 may reside in the same memorylocation. 
		But, it is not true for the following:
		char ca1[] = “Calvin and Hobbes”;
		char ca2[] = “Calvin and Hobbes”;
		The value of a string is the sequence of the values of the containedcharacters, in order.

Which bit wise operator is suitable for checking whether a particular bit is on or off?
	The bitwise AND operator. Here is an example:
	enum {
		KBit0 = 1,
		KBit1,
		…
		KBit31,
	};
	if ( some_int & KBit24 )
		printf ( “Bit number 24 is ON\n” );
	else
		printf ( “Bit number 24 is OFF\n” );

Which bit wise operator is suitable for turning off a particular bit in a number?
	The bitwise AND operator, again. In the following code snippet, the bit number 24 is reset to zero.
	some_int = some_int & ~KBit24;

Which bit wise operator is suitable for putting on a particular bit in a number?
	The bitwise OR operator. In the following code snippet, the bit number 24 is turned ON:
	some_int = some_int | KBit24;

What is hashing?
memmove vs memcpy vs memset
what is free()? how does free know how much memory to de-allocate?
What is recursion? What actually happens during recursion? does the memory get stored on stack? what gets called and how does the program know from where to call? how does unwinding happen? explain with example?

How code optimization does not happen when it comes to VOLATILE? Explain?
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

Can include files be nested?

NULL vs wild vs dangling vs generic pointer ? Why NULL pointer is required?
	
	NULL pointer:
	Literal meaning of NULL pointer is a pointer which is pointing to nothing. NULL pointer points the base address of segment.
	Note: We cannot copy any thing in the NULL pointer.
	
	Examples of NULL pointer:
	1. int *ptr=(char *)0;
	2. float *ptr=(float *)0;
	3. char *ptr=(char *)0;
	4. double *ptr=(double *)0;
	5. char *ptr=’\0’;
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

	Note: There is difference between the NULL pointer and wild pointer. Null pointer points the base address of segment while wild pointer doesn’t point any specific memory location.
	
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
	…
	}
	
	int* fun1()
	{
		int a = 10;
		return(&a); /*in this line we are returning the pointer of variable ‘a’ which is out scope.*/
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
		printf(“%d\n”, *((int*)b));

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

What is the benefit of using #define to declare a constant?
	Using the #define method of declaring a constant enables you to declare a constant in one place and use it throughout your program. This helps make your programs more maintainable, 
	because you need to maintain only the #define statement and not several instances of individual constants throughout your program.
	For instance, if your program used the value of pi (approximately 3.14159) several times, you might want to declare a constant for pi as follows:  #define PI 3.14159
	Using the #define method of declaring a constant is probably the most familiar way of declaring constants to traditional C programmers. Besides being the most common method of declaring constants, 
	it also takes up the least memory.
	Constants defined in this manner are simply placed directly into your source code, with no variable space allocated in memory. Unfortunately, this is one reason why most debuggers cannot 
	inspect constants created using the #define method

What is the purpose of main( ) function ?
	The function main( ) invokes other functions within it.It is the first function to be called when the program starts execution.
	· It is the starting function
	· It returns an int value to the environment that called the program
	· Recursive call is allowed for main( ) also.
	· It is a user-defined function
	· Program execution ends when the closing brace of the function main( ) is reached.
	· It has two arguments 1)argument count and 2) argument vector (represents strings passed).
	· Any user-defined name can also be used as parameters for main( ) instead of argc and argv

Why should we assign NULL to the elements (pointer) after freeing them?
	This is paranoia based on long experience. After a pointer has been freed, you can no longer use the pointed-to data. The pointer is said to dangle; it doesn’t point at anything useful.
	If you NULL out or zero out a pointer immediately after freeing it, your program can no longer get in trouble by using that pointer. True, you might go indirect on the null pointer instead, 
	but that’s something your debugger might be able to help you with immediately.
	Also, there still might be copies of the pointer that refer to the memory that has been deallocated; that’s the nature of C. Zeroing out pointers after freeing them won’t solve all problems.

What is a null pointer assignment error? What are bus errors, memory faults, and core dumps?
	These are all serious errors, symptoms of a wild pointer or subscript. Null pointer assignment is a message you might get when an MS-DOS program finishes executing. 
	Some such programs can arrange for a small amount of memory to be available “where the NULL pointer points to (so to speak). If the program tries to write to that area, it will overwrite the data put there by the compiler.
	When the program is done, code generated by the compiler examines that area. If that data has been changed, the compiler-generated code complains with null pointer assignment. 
	This message carries only enough information to get you worried. There’s no way to tell, just from a null pointer assignment message, what part of your program is responsible for the error. 
	Some debuggers, and some compilers, can give you more help in finding the problem.
	Bus error: core dumped and Memory fault: core dumped are messages you might see from a program running under UNIX. They’re more programmer friendly. Both mean that a pointer or an array subscript was wildly out of bounds.
	You can get these messages on a read or on a write. They aren’t restricted to null pointer problems. The core dumped part of the message is telling you about a file, called core, 
	that has just been written in your current directory. This is a dump of everything on the stack and in the heap at the time the program was running. 
	With the help of a debugger, you can use the core dump to find where the bad pointer was used.  That might not tell you why the pointer was bad, but it’s a step in the right direction. 
	If you don’t have write permission in the current directory, you won’t get a core file, or the core dumped message

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
		char Padding1[1]; /* 1 byte for the following 'short' to be aligned on a 2 byte boundary assuming that the address where structure begins is an even number */
		short Data2; /* 2 bytes */
		int Data3;  /* 4 bytes - largest structure member */
		char Data4; /* 1 byte */
		char Padding2[3]; /* 3 bytes to make total size of the structure 12 bytes */
	};

	The compiled size of the structure is now 12 bytes. It is important to note that the last member is padded with the number of bytes required 
	so that the total size of the structure should be a multiple of the largest alignment of any structure member (alignment(int) in this case, which = 4 on linux-32bit/gcc)
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

What is the difference between declaring a variable and defining a variable?
	 Declaring a variable means describing its type to the compiler but notallocating any space for it. Defining a variable means declaring it andalso allocating space to hold the variable.
	 You can also initialize avariable at the time it is defined.
	 
Why is sizeof(‘a’) not 1? what this mean sizeof(a++) ?

write your own sizeof operator?
	#define   size_of(x)   ((char *)(&x+1) – (char *)&x)

why n++ executes faster than n+1? 
	The expression n++ requires a single machine instruction such as INR to carry out the increment operation whereas, n+1 requires more instructions to carry out this operation.
What is the difference between #include "..." and #include <...>?
		The difference lies in where the preprocessor looks for the file to be included. For the include directive with a double quoted filename, 
		the preprocessor limits its search for the file to the same directory where the current source file resides. On the other hand, 
		when the directive uses angle brackets, the preprocessor searches for the file in directories pre-designated by the compiler - usually directories where standard library header files reside.
		
What is static memory allocation and dynamic memory allocation?
	Static memory allocation: The compiler allocates the required memoryspace for a declared variable. By using the address of operator,thereserved address is obtained and this address may be assigned to apointer variable.
	Since most of the declared variable have staticmemory,this way of assigning pointer value to a pointer variable isknown as static memory allocation. 
	memory is assigned duringcompilation time.Dynamic memory allocation: It uses functions such as malloc( ) orcalloc( ) to get memory dynamically.
	If these functions are used to getmemory dynamically and the values returned by these functions areassingned to pointer variables, such assignments are known asdynamic memory allocation.
	memory is assined during run time.

Is using exit() the same as using return?
	 No. The exit() function is used to exit your program and return controlto the operating system. The return statement is used to return from afunction and return control to the calling function. 
	 If you issue a returnfrom the main() function, you are essentially returning control to thecalling function, which is the operating system. In this case, the returnstatement and exit() function are similar.

What is the output of printf("%d") ?
	When we write printf("%d",x); this means compiler will print the value of x. But as here, there is nothing after %d so compiler will show in output window garbage value.
	 
malloc vs calloc vs realloc ?
Is realloc() uses the same memory location which was used by malloc()?
Difference between arrays and pointers?
Is using exit() the same as using return?
declaring a variable vs defining a variable
Differentiate between an internal static and external static variable?
string vs array?
	Merits:
	(a) We can easily access each element of array.
	(b) Not necessity to declare too many variables.
	(c) Array elements are stored in continuous memory location.
	Demerits:
	(a) Wastage of memory space. We cannot change size of array at the run time.
	(b) It can store only similar type of data

What are advantages and disadvantages of external storage class?

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
	
Array vs Linked list?
	Major differences between arrays and linked lists are: 
	(i)  In array consecutive elements are stored in consecutive memory locations whereas in linked list it not so. 
	(ii)  In array address of next element is consecutive and whereas in linked list it is specified in the address part of each node.
	(iii) Linked List makes better use of memory than arrays.(iv) Insertion or deletion of an element in array is difficult than insertion or deletion in linked list.

Write a code for String reverse, strlen,reverse words in a string, find duplicates in an array etc. ?
create a custom malloc and free function using linked lists ?
write a function that determines if a given variable is a power of 2 or not?
write a function that determines if a given variable is even or odd?
What is atomic programming/non-locking operation?
What is concurrency and multithreading?

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
			printf (“BIG ENDIAN”);
		else
			printf (“LITTLE ENDIAN”);
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
			printf (“BIG ENDIAN”);
		else
			printf (“LITTLE ENDIAN”);
	}

How to reduce function call overhead in ARM based systems?
	Try to ensure that small functions take four or fewer arguments. These will not usethe stack for argument passing. It will copied into registers.· 
	If a function needs more than four arguments, try to ensure that it does asignificant amount of work, so that the cost of passing the stacked arguments isoutweighed.
	Pass pointers to structures instead of passing the structure itself.
	Put related arguments in a structure, and pass a pointer to the structure tofunctions. This will reduce the number of parameters and increase readability.
	Minimize the number of long long parameters, as these take two argument words.This also applies to doubles if software floating-point is enabled.
	Avoid functions with a parameter that is passed partially in a register and partiallyon the stack (split-argument). This is not handled efficiently by the currentcompilers: all register arguments are pushed on the stack.
	Avoid functions with a variable number of parameters. Varargs functions

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

Write a C program to encode bits in a 32-bit number such  that, most significant 16 bits should be reversed but lower 16 bits should be untouched. Then asked to generalize this to any number of bits?
	reverse the entire 32-bits first and then left shift the resulting number by 16 bits so that the upper 16 bits are now reversed. 
	In the second phase, with the help of a mask zero out the most significant 16 bits. Now XOR the two number to get the desired encoded number ?

Write a C Program to reverse the words in a sentence?
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
	
What is the difference between a string copy (strcpy) and a memory copy (memcpy)? When should each be used? when we should strncpy()?
	The strcpy() function is designed to work exclusively with strings. It copies each byte of the source string to the destination string and stops when the terminating null character (\0) has been moved. 
	On the other hand, the memcpy() function is designed to work with any type of data.
	Because not all data ends with a null character, you must provide the memcpy() function with the number of bytes you want to copy from the source to the destination.
	strncpy()= to copy a portion of a string.

How can I convert a number to a string and vice versa?
	itoa(); atoi();
	
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
		printf(“nArea = %f”, area);
		return area;
	}

	This function has so much wrong with it, it’s almost tough to know where to start.
	(a) Interrupt service routines cannot return a value. If you don’t understand this, then you aren’t hired.
	(b) ISR’s cannot be passed parameters. See item (a) for your employment prospects if you missed this.
	(c) On many processors / compilers, floating point operations are not necessarily re-entrant. In some cases one needs to stack additional registers, in other cases,
		one simply cannot do floating point in an ISR. Furthermore, given that a general rule of thumb is that ISRs should be short and sweet, one wonders about the wisdom of doing floating point math here.
	(d) In a similar vein to point (c), printf() often has problems with reentrancy and performance.

what are Static and Dynamic Libraries? advantage and disadvantages of both?

What is the difference between static linking and dynamic linking ?
	In static linking, all the library modules used in the program are placed in the final executable file making it larger in size. This is done by the linker. 
	If the modules used in the program are modified after linking, then re-compilation is needed. 
	The advantage of static linking is that the modules are present in an executable file. We don't want to worry about compatibility issues.

	In case of dynamic linking, only the names of the module used are present in the executable file and the actual linking is done at run time when the program and the library modules both are present in the memory.
	That is why, the executables are smaller in size. Modification of the library modules used does not force re-compilation. But dynamic linking may face compatibility issues with the library modules used.

What is a memory leak? What is a segmentation fault?*
what is stack  overflow and heap overflow?
what is a core dump?
	A core dump is the recorded state of the working memory of a computer program at a specific time, generally when the program has terminated abnormally includes the program counter and stack pointer, 
	memory management information, and other processor and operating system flags and information a fatal error usually triggers the core dump, often buffer overflows, 
	where a programmer allocates too little memory for incoming or computed data, or access to null pointers, a common coding error when an unassigned memory reference variable is accessed.
What is a stack frame, stack pointer & frame pointer ?
what is a non re­entrant code?
write a code  to check whether a stack  grows upwards or downwards?
Tell the role of brk() in malloc / Tell the relation between heap and brk?
Tell the relation between Malloc and MMAP

What does the following code fragment output and why?
	char *ptr;
	if ((ptr = (char *)malloc(0)) == NULL) {
		puts(“Got a null pointer”);
	}
	else {
		puts(“Got a valid pointer”);
	}
	
	Note: malloc(0) gives a valid pointer but allocate zero bytes.
	
RTOS:
What is priority inversion ? solution : priority inheritance, priority ceiling.
What is deadlock ? how to deteatc and remove deadlock?
What is data race ?
What is Indefinite Postponement / Indefinite blocking or starvation ?
what are the syncronization technique and which one we should in which scenerio?
semaphore vs mutex vs spinlock?
what are the IPC and which one we should in which scenerio?
    Pipes
    Named pipes or FIFO 
    Shared memory
    Message queue
    Socket
	Semaphores

what is callback function? signal vs callback ?
What happens when recursive functions are declared inline?

Can structures be passed to the functions , structure and array by value?
thread vs process?
How do you measure the latency of your system ?
What are the possible scenarios in which context switching of threads can occur ?
What will happen if there are more threads requesting for CPU resource such as time ?
While writing interrupt handlers(ISR), which are points needed to be considered?
Explain what is interrupt latency? How can we reduce it?

Explain interrupt latency and how can we decrease it?
	1. Interrupt latency basically refers to the time span an interrupt is generated and it being serviced by an appropriate routine defined, usually the interrupt handler.
	2. External signals, some condition in the program or by the occurrence of some event, these could be the reasons for generation of an interrupt.
	3. Interrupts can also be masked so as to ignore them even if an event occurs for which a routine has to be executed.
	4. Following steps could be followed to reduce the latency
	- ISRs being simple and short.
	- Interrupts being serviced immediately
	- Avoiding those instructions that increase the latency period.
	- Also by prioritizing interrupts over threads.
	- Avoiding use of inappropriate APIs.

Can we use semaphore or mutex or spin lock in interrupt context in linux kernel? and why?

What is the function of DMA controller in embedded system?
	DMA stands for Direct Memory Access controller as the name suggest it does not involve processor to transfer memory between two devices that handles the allocation of the memory 
	dynamically to the components and allows the data to be transferred between the devices.
	
	The interrupt can be used to complete the data transfer between the devices. It is used to give the high quality performance as, the input/output device can perform the operations 
	that are in parallel with the code that are in execution.

	- Direct memory access is mainly used to overcome the disadvantages of interrupt and progam controlled I/O.
	- DMA modules usually take the control over from the processor and perform the memory operations and this is mainly because to counteract the mismatch in the processing speeds of I/O units and the procesor. 
		This is comparatively faster.
	- It is an important part of any embedded systems,and the reason for their use is that they can be used for bursty data transfers instead of single byte approaches.
	- It has to wait for the systems resources such as the system bus in case it is already in control of it.

What is preemption ?
What do you mean by atomic operations ?

What is ISR? Can they be passed any parameter and can they return a value? can we use printf, break point, function call or any blocking or sleep call or floating operation in ISR?
How CPUs find the ISR and distinguish between the various devices ?
Is it possible for two devices to share an interrupt request line but have different ISR for those two devices ?
What is Top half & bottom half of a kernel?

What is difference between binary semaphore and mutex?
What is the use of file->private_data in a device driver structure ?
poll vs epoll ?
Difference between Timer Softirq and Tasklet Softirq ?
What are tasklets ? How are they activated ? when and How are they initialized ?
What is task_struct and how are task states maintained ?
What is rwlock and spinlock ? Briefly explain about both of them ?
Tell about the Memory Layout and compilation steps of a Process in Linux ?
How will you trace the system calls made into the kernel of lInux ?
What is a stack frame, stack pointer & frame pointer ?
What happens as soon as a packet arrives from the network in Linux ?
What is Kmalloc and how does it differ from normal malloc ? or Why can’t we use malloc in kernel code ?
what is a watchdog timer? what is the sinificance of it?

The watchdog timer is a timing device with a predefined time interval. During that interval, some event may occur or else the device generates a time out signal. 
	It is used to reset to the original state whenever some inappropriate events take place which can result in system malfunction. It is usually operated by counter devices
	How are variables mapped across to the various memories by the C compiler?
	
	- Watchdog timer is basically a timing device that is set for predefined time interval and some event should occur during that time interval else the device generates a time out signal.
	- One application where it is most widely used is when the mobile phone hangs and no activity takes place, in those cases watchdog timer performs a restart of the system and comes to the rescue of the users.
	- It is used to reset to the original state whenever some inappropriate events take place such as too many commands being given at the same time or other activities that result in malfunctioning of the GUI. 
		It i	s usually operated by counter devices.
	
Qualcom :

Whats is Stack overflow attack??...then he gave me a scenario where there was a open source code at a server and you have your piece of code at that server.
You as a client are allowed to invoke a method which takes in a array as a parameter which is not checked for overflow validation. 
I had to induce a buffer overflow attack and make the method to pass control… 

When does the control passes from user mode to kernel mode in a Linux System? 
	System calls ,H/w Interrupts and last which I did not mention was Exceptions
	
write a shortest string copy function?
while (*str++ = *dst++) {}i

find sturcture address given an element of the structure
long discussion on kernel in 3-4 interviews : Paging, segmentation, Priorities, scheduling, Concurrency

How are signals hanled in OS ?
Page Fault exception - what happens  ?
implement your own sizeof ?

	return (char *)(&x + 1) - (char *)&x;
	
Question: Why does this fail when x is an array? Say int x[]={1, 2, 3, 4, 5};
Answer: Because x is a pointer to the very first value in the array, which is 1. Hence the sizeof x will return the size of the pointer, which is 4 or 8 bytes depending on the system.

linklist and array, which one is fatser an why ?
	Array Elements are stored in contiguous memory locations. Hence they will be faster to retrieve.
	What do you mean by contiguous memory locations? Physical or Virtual ?
	First, there is no requirement for random access, only iterate one by one.

	In this case, continuous memory does not matter so much.
	It really depends on the Link List implementation and the size.
	If it is a normal size data, array will be a little faster.
	But if it is a really big size, link list may be faster because it does not need allocate the big continuous memory block for data loading.

Can you tell me how to check whether a linked list is circular or not and delte the circulerity?

Compilation How to reduce a final size of executable?
how you can tell whether system is little or big indian ?
best synchronization tecqnique ?

for simple counter variables or for bitwise ------->atomic operations are best methods.
atomic_t count=ATOMIC_INIT(0); or atomic_set(&count,0);
atomic_read(&count);
atomic_inc(&count);
atomic_dec(&count);
atomic_add(&count,10);
atomic_sub(&count,10);

spinlocks are used to hold critical section for short time and can use from interrupt context and locks can not sleep,also called busy wait loops.
fully spinlocks and reader/writer spin locks are available.
spinlock_t my_spinlock;
spin_lock_init( &my_spinlock );

spin_lock( &my_spinlock );
// critical section
spin_unlock( &my_spinlock );

Spinlock variant with local CPU interrupt disable :
spin_lock_irqsave( &my_spinlock, flags );
// critical section
spin_unlock_irqrestore( &my_spinlock, flags );

if your kernel thread shares data with a bottom half :
spin_lock_bh( &my_spinlock );
// critical section
spin_unlock_bh( &my_spinlock );

if you have more readers than writers for your shared resource :
Reader/writer spinlock can be used
rwlock_t my_rwlock;
rwlock_init( &my_rwlock );
write_lock( &my_rwlock );
// critical section -- can read and write
write_unlock( &my_rwlock );

read_lock( &my_rwlock );
// critical section -- can read only
read_unlock( &my_rwlock );

mutexs are used when you hold lock for longer time and if you use from process context.
DEFINE_MUTEX( my_mutex );
mutex_lock( &my_mutex );
mutex_unlock( &my_mutex );

How function poiner are shared between different process ?
	two processes can not share function pointers.
	if you want to use functions in two processes make library for that functions and use that library in your processes.

is linux kernel a thread, process or something else?
how sysctrl work ?
how a func from one user process can be called in other user process ?	

write a program using two thread . one thread should print odd number and other should even number in sequesnce? how you can make it SMP safe ?
how to make it SMP safe in user space?
in kthread context we could have used spin_lock(), but in user space what is the method to do SMP safe when we run pthread?

explain device tree concept ?
	Device tree is a data structure that describes the hardware and is passed to the kernel at boot time.
	different boards can be supported without recompiling the kernel only by writing the dtbs.
	
differance b/w kill -9 and kill -3 ?
	kill -3: Terminates with coredump. eg SIGQUIT (QUIT) : Quit : Terminate with core dump; can be trapped
	kill -9: Forcible termination. eg SIGKILL (KILL) : Kill : Forced termination; cannot be trapped
differance b/w process and thread ?
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

Suggest an efficient method to count the no. of 1’s in a 32 bit no. Remember without using loop & testing each bit?
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

find the middle element in link list ?
		Maintain two pointers slow and fast.
		Iterate thru the list by moving slow pointer once and fast pointer twice. When fast pointer will point to null, slow pointer will be pointing to middle element.

count the number of set bits in integer ?
implemet your own string system call ? 
find the size of structure without sizeof ?
differance b/w array and pointer and const strings ?

check whether a number is power of 2 or not ?
	void main ()
	{
		int n;
		printf (“\n Enter any no:”);
		scanf (“%d”, & n);
		if (n & & ((n & n-1) = = 0))
			printf (“It is power of 2”);
		else
			printf (“It is not power of 2”);
	}
	Note: The logic says that if a no. is power of 2, then in the binary representation, only one bit of the no. can be ‘1’ & rest are must be ‘0’.
	
Swapping integers without using additional space?
	a= a(xor)b, b= a(xor)b, a=a(xor)b
	a = a + b; b = a - b; a = a - b;
	Doesn't work if a and b are 32 bit integer. We might have over flow in a+b. a(xor)b will not have any overflow.

Write a program in C to add two numbers without using any maths operator (+, -, /, *).

	int sum(int x, int y) 
	{ 
		if( x == y) 
			return (x << 1); 
		else 
			return (x ^ y); } see complete program at http://www.ssiddique.info/add-two-numbers-without-using.html
	}
	
	c = a – (-b);
	as a+b is equivalent to a – (-b), binary ‘+’ operator is replaced by one unary ‘-‘ & one binary ‘-‘ operator.

How to print number from 1 to 100 without using conditional operators.
	void main ()
	{
		int  i=0;
		while (100 – i++)
		printf (“ %d”, i);
	}

WAP to print 100 times “Hello” without using loop & goto statement.
	void main()
	{
		show (1, 100);
	}
	show (int x, int y)
	{
		if (x>=y)
			return;
		printf (“\n Hello”);
		show (x+1, y);
	}
	i.e. Recursive function

Why is it usually a bad idea to use gets()? Suggest a workaround?
	The function gets() reads characters from the stdin and stores them at the provided input buffer. However, gets() will keep reading until it encounters a newline character. 
	Unless the buffer is large enough, or the length of the line being read is known ahead of time, gets() can potentially overflow the input buffer and start overwriting memory it is not supposed to,
	wreaking havoc or opening security vulnerabilities.

	One way to work around this issue is to use fgets(). It allows you to put a limit on the maximum number of characters to read:
	fgets(b, 124, stdin);


How can you access global static variables from other files?
	global static variables have file scope and cant be accessed outside the file. That's the difference between global static and global.
	we can use a function to access the variable or its pointer.
How would you obtain n bits from position p in an integer?
	First left shift 32-p bits followed by 32-n bits right shift.
	/* getbits: get n bits from position p */ unsigned getbits(unsigned x, int p, int n) { return (x >> (p+1-n)) & ~(~0 >(p+1-n) moves the desired field to the right end of the word. ~0 is all 1 bits; 
	shifting it left n bit positions with ~0 << n places zeros in the rightmost n bits; complementing that with ~ makes a mask with ones in the rightmost n bits. Directly from K&R.
What is setup hold time?
	Setup time is the time the data should be held constant before the arrival of the clock edge.
	Set Up time is Minimum Amount of time During which Data Signal Should be Stable Before the Clock made a Valid[Low-to-High] Transition. 
	Hold time is the Minimum Amount of time After the Clock Made a Valid Transition During which Data Signal Should Stable.
find length of circular linked list given a pointer to some node of linkedlist?


c basic :
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
3. Order of modifier including data type doesn’t affect the meaning of declaration.
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
Looping is the process of repeating of same code until a specific condition doesn’t satisfy.

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
Data may be primitive type (int, char, float, double…), address of union, structure, pointer, function or another array.

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
5. char *ptr=’\0’;
6. int *ptr=NULL;

What is meaning of NULL?
NULL is macro constant which has been defined in the heard file stdio.h, alloc.h, mem.h, stddef.h and stdlib.h as
#define NULL 0

We cannot copy any thing in the NULL pointer.

Wild pointer:
A pointer in c which has not been initialized is known as wild pointer.

There is difference between the NULL pointer and wild pointer. Null pointer points the base address of 
segment while wild pointer doesn’t point any specific memory location.

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
4.Function’s declaration doesn’t reserve any memory space.
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
