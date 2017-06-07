#include <linux/ioctl.h>
/*
 * Macros to help with debugging. Set SCULL_DEBUG to 1 enable
 * debugging (which you can do from the Makefile); these macros work
 * in both kernelspace and userspace.
 */

#undef PDEBUG /* undef it, just in case someone else defined it. */
#ifdef SCULL_DEBUG
#  ifdef __KERNEL__
     /* Debugging is on and we are in kernelspace. */
#    define PDEBUG(fmt, args...) printk(KERN_DEBUG "scull: " fmt, ## args)
#  else
     /* Debugging is on and we are in userspace. */
#    define PDEBUG(fmt, args...) fprintf(stderr, fmt, ## args)
#  endif
#else
#  define PDEBUG(fmt, args...) /* Not debugging: do nothing. */
#endif

/* PDEBUGG is a placeholder that makes it easy to "comment out" the debugging
   statements without deleting them. */
#undef PDEBUGG
#define PDEBUGG(fmt, args...)

#ifndef CHARDEV_MAJOR
#define CHARDEV_MAJOR     0 /* dynamic major by default */
#endif

#ifndef CHARDEV_NR_DEVS
#define CHARDEV_NR_DEVS   1 /* scull0 through scull3 */
#endif

/*
 * Representation of scull quantum sets.
 */

struct chardev_dev {
	char pdata[20];
	int count;
	struct mutex mutex;       /* Mutual exclusion semaphore. */
        struct cdev cdev;         /* Char device structure. */
};

struct string {
    char original[20];
    char reverse[20];
};

#define CD_MAGIC 89
#define CD_IOC_ALLOC_BUF _IOW(CD_MAGIC, 0, int)
#define CD_IOC_WRITE_STRING _IOW(CD_MAGIC, 1, int)
#define CD_IOC_REVERSE_STRING _IO(CD_MAGIC, 2)
#define CD_IOC_READ_STRING _IOR(CD_MAGIC, 3, int)
#define CD_IOC_FREE_BUF _IO(CD_MAGIC, 4)
#define CD_IOC_READ_WRITE_REVERSE_STRING _IOWR(CD_MAGIC, 5, int)

/*
 * The different configurable parameters
 */
extern int chardev_major;     /* char.c */
extern int chardev_nr_devs;

