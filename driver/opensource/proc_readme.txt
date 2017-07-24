/proc virtual filesystem :

    /proc/modules — dynamically loaded modules
    /proc/devices — registered character and block major numbers
    /proc/iomem — on-system physical RAM and bus device addresses
    /proc/ioports — on-system I/O port addresses (especially for x86 systems)
    /proc/interrupts — registered interrupt request numbers
    /proc/softirqs — registered soft IRQs
    /proc/kallsyms — running kernel symbols, including from loaded modules
    /proc/partitions — currently connected block devices and their partitions
    /proc/filesystems — currently active filesystem drivers
    /proc/swaps — currently active swaps
    /proc/cpuinfo — information about the CPU(s) on the system
    /proc/meminfo — information about the memory on the system, viz., RAM, swap, …

steps:

    Built the driver file (proc_window.ko) using the usual driver’s Makefile.
    Loaded the driver using insmod.
    Showed various experiments using the newly created proc windows. (Refer to Figure 1.)
    And finally, unloaded the driver using rmmod.

Peeping through /proc

Demystifying the details

Starting from the constructor proc_win_init(), three proc entries have been created:

    Directory anil under /proc (i.e., NULL parent) with default permissions 0755, using proc_mkdir()
    Regular file rel_time in the above directory, with permissions 0666, using create_proc_entry()
    Soft link rel_time_l to the file rel_time, in the same directory, using proc_symlink()

The corresponding removal of these is done with remove_proc_entry() in the destructor, proc_win_exit(), in chronological reverse order.

For every entry created under /proc, a corresponding struct proc_dir_entry is created. For each, many of its fields could be further updated as needed:

    mode — Permissions of the file
    uid — User ID of the file
    gid — Group ID of the file

Additionally, for a regular file, the following two function pointers for reading and writing over the file could be provided, respectively:

    int (*read_proc)(char *page, char **start, off_t off, int count, int *eof, void *data)
    int (*write_proc)(struct file *file, const char __user *buffer, unsigned long count, void *data

write_proc() is very similar to the character driver’s file operation write(). The above implementation lets the user write a digit from 0 to 9, 
and accordingly sets the internal state. read_proc() in the above implementation provides the current state, and the time since the system 
has been booted up — in different units, based on the current state. These are jiffies in state 0; milliseconds in state 1; 
seconds and milliseconds in state 2; hours, minutes and seconds in state 3; and <not implemented> in other states.

And to check the computation accuracy, Figure 2 highlights the system uptime in the output of top. 
read_proc‘s page parameter is a page-sized buffer, typically to be filled up with count bytes from offset off. 
But more often than not (because of less content), just the page is filled up, ignoring all other parameters.
Comparison with top’s output

Figure 2: Comparison with top’s output:

All the /proc-related structure definitions and function declarations are available through <linux/proc_fs.h>. 
The jiffies-related function declarations and macro definitions are in <linux/jiffies.h>. As a special note, the actual jiffies are calculated 
by subtracting INITIAL_JIFFIES, since on boot-up, jiffies is initialised to INITIAL_JIFFIES instead of zero.



