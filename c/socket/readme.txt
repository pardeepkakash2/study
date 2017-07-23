https://www.softlab.ntua.gr/facilities/documentation/unix/unix-socket-faq/unix-socket-faq.html

Networking :

	TCP/IP Protocol Stacks
	Intro to Network Programming
	Sockets : Port Numbers + IP address
	Common Port Numbers
	Common Protocol Numbers
	Internet Domain Socket
	Socket Functions
	Socket System Calls
	Byte Ordering Requirements
	Concurrent Server Design
	Iterative Server Design
	Socket Debugging Techniques
	Advanced Socket Options
	Changing Socket Buffer Sizes
	Reusing Socket Addresses
	Keeping the Connections Alive
	TCP Socket Options
	Setting Max Segment Size
	Setting TCP No-Delay
	Advanced I/O Functions
	Socket Timeouts
	Vectored Read/Writes
	Netstat – Network Stat Utility
	Tcpdump – Packet Dump Utility 

MultiThread :
    Introduction to Threads
    Parallelism
    Multi-cores
    Introduction to Thread
    Threads – Application
    User Level Threads (ULT)
    Advantage of ULT
    Disadvantage of ULT
    Kernel Level Threads (KLT)
    Advantage of KLT
    Disadvantage of KLT
    Threads Vs Processes
    Process Memory Layout
    Child Process Memory
    Threads Inside Processes
    Thread Memory Layout

    Thread Programming – I
    Introduction to Pthreads (POSIX Threads)
    Thread Creation
    Thread Termination
    Thread Id & Attributes
    Thread Joining & Detaching
    Thread Priorities
    Thread Cancellations
    Thread Cleanup Handling
    Passing Info to Threads

    Thread Programming – II
    Thread Synchronizations
    Mutual Exclusions
    Condition Variables
    Thread Safe Operations
    Thread Signal Handling
    Thread Signal Masking
    Issues @ Threads
    Races & Deadlocks
    Threads  & Process Resources
    Threads – File Handling
    Threads – IPC Handling

Questions regarding both Clients and Servers (TCP/SOCK_STREAM)

    2.1 How can I tell when a socket is closed on the other end?
    2.3 How do I get the port number for a given service?
    2.6 When should I use shutdown()?
    2.7 Please explain the TIME_WAIT state.
    2.8 Why does it take so long to detect that the peer died?
    2.9 What are the pros/cons of select(), non-blocking I/O and SIGIO?
    2.10 Why do I get EPROTO from read()?
    2.11 How can I force a socket to send the data in it's buffer?
    2.12 Where can a get a library for programming sockets?
    2.13 How come select says there is data, but read returns zero?
    2.14 Whats the difference between select() and poll()?
    2.16 How do I use TCP_NODELAY?
    2.17 What exactly does the Nagle algorithm do?
    2.18 What is the difference between read() and recv()?
    2.19 I see that send()/write() can generate SIGPIPE. Is there any advantage to handling the signal, rather than just ignoring it and checking for the EPIPE error? Are there any useful parameters passed to the signal catching function?
    2.20 After the chroot(), calls to socket() are failing. Why?
    2.21 Why do I keep getting EINTR from the socket calls?
    2.22 When will my application receive SIGPIPE?
    2.23 What are socket exceptions? What is out-of-band data?
    2.24 How can I find the full hostname (FQDN) of the system I'm 

3. Writing Client Applications (TCP/SOCK_STREAM)

    3.1 How do I convert a string into an internet address?
    3.2 How can my client work through a firewall/proxy server?
    3.3 Why does connect() succeed even before my server did an accept()?
    3.4 Why do I sometimes loose a server's address when using more than one server?
    3.5 How can I set the timeout for the connect() system call?
    3.6 Should I bind() a port number in my client program, or let the
    3.7 Why do I get "connection refused" when the server isn't running?
    3.8 What does one do when one does not know how much information is comming 

4. Writing Server Applications (TCP/SOCK_STREAM)

    4.1 How come I get "address already in use" from bind()?
    4.2 Why don't my sockets close?
    4.3 How can I make my server a daemon?
    4.4 How can I listen on more than one port at a time?
    4.5 What exactly does SO_REUSEADDR do?
    4.6 What exactly does SO_LINGER do?
    4.7 What exactly does SO_KEEPALIVE do?
    4.8 How can I bind() to a port number < 1024?
    4.9 How do I get my server to find out the client's address / hostname?
    4.10 How do I use the gethostbyaddr() function?
    4.11 How should I choose a port number for my server?
    4.12 What is the difference between SO_REUSEADDR and SO_REUSEPORT?
    4.13 How can I write a multi-homed server?
    4.14 How can I read only one character at a time? 

5. Writing UDP/SOCK_DGRAM applications

    5.1 When should I use UDP instead of TCP?
    5.2 What is the difference between "connected" and "unconnected" sockets?
    5.3 Does doing a connect() call affect the receive behaviour
    5.4 How can I read ICMP errors from "connected" UDP sockets?
    5.5 How can I be sure that a UDP message is received?
    5.6 How can I be sure that UDP messages are received in order?
    5.7 How often should I re-transmit un-acknowleged messages?
    5.8 How come only the first part of my datagram is getting through? 



Socket Programming

    Difference between UDP and TCP.
    Difference between asynchronous and synchronous sockets.
    What is a packet.
    How'd you determine if packet didn't arrive malformed.
    How'd you determine where one packet ends and where another one starts.
    What is a port.
    How would you connect to www.google.com asynchronously?

Multi-Threading

    What synchronization primitives do you know, tell difference between them.
    What is a deadlock and what is a livelock and how to avoid it.
    What is a race condition.
    What does the term 'lock-free' mean.
    What is the best way to terminate a thread.
    Why you shouldn't use TerminateThread-esque functions.
	
    What is a thread and how is it different from a process?
    When might you choose to use threads on a single CPU system?
    How would you measure the context switch overhead between threads?
    How would you make a MT-safe hash table, while allowing for maximal concurrency?

What is a socket? What is it used for?
How are IP addresses resolved? What is the difference between an IP4 and IP6 address? How does that affect the socket calls?
How do you determine what port to connect to? What are some of the common ones? What ports wouldn't you use?
What is the difference between a TCP socket and a UDP socket? Why would you use one or the other?
What list of calls are used to establish a TCP and/or UDP socket connection? What information is needed?
How are the socket calls different if you are establishing a server side socket?
How do you test whether a socket is ready to be read or written?
If a socket closes unexpectedly, how would you know and how would you handle it?
What happens to the connection, thread, process if a socket is not closed out properly?
How long does a socket connection stay open when idle? How would you change that behavior?
How would you set a socket to non-blocking mode? In what situations would you do that?
How would you handle writing a multi-process and/or multi-threaded socket application? 
What considerations are there? Is there more than one way to handle it?
