#include <linux/module.h>	/*Core header for loading LKMs into the kernel*/
#include <linux/moduleparam.h>
#include <linux/init.h>		/* Macros used to mark up functions e.g. __init __exit */
#include <linux/device.h>       /* Header to support the kernel Driver Model*/
#include <linux/kernel.h>       /* printk() Contains types, macros, functions for the kernel*/
#include <linux/slab.h>         /* kmalloc() */
#include <linux/fs.h>           /* everything... Header for the Linux file system support*/
#include <linux/errno.h>        /* error codes */
#include <linux/types.h>        /* size_t */
#include <linux/proc_fs.h>
#include <linux/fcntl.h>        /* O_ACCMODE */
#include <linux/seq_file.h>
#include <linux/cdev.h>

#include <linux/string.h>
#include <asm/uaccess.h>        /* Required for the copy to user function */

#include "chardev.h"              /* local definitions */

#define  DEVICE_NAME "chardev" /* The device will appear at /dev/ebbchar using this value*/
#define CLASS_NAME  "chardev"	/* The device class -- this is a character device driver */

/*
 * Our parameters which can be set at load time.
 */

int chardev_major =   CHARDEV_MAJOR;
int chardev_minor =   0;
int chardev_nr_devs = CHARDEV_NR_DEVS;      /* number of bare scull devices */

static char   message[256] = {0};           ///< Memory for the string that is passed from userspace
static short  size_of_message;              ///< Used to remember the size of the string stored
static int    count = 0;              ///< Counts the number of times the device is opened

module_param(chardev_major, int, S_IRUGO);
module_param(chardev_minor, int, S_IRUGO);
module_param(chardev_nr_devs, int, S_IRUGO);

struct chardev_dev *chardev_devices;        /* allocated in scull_init_module */

static struct class*  charclass  = NULL; ///< The device-driver class struct pointer
static struct device* chardevice = NULL; ///< The device-driver device struct pointer
 
// The prototype functions for the character driver -- must come before the struct definition
static int     dev_open(struct inode *, struct file *);
static int     dev_release(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char *, size_t, loff_t *);
static ssize_t dev_write(struct file *, const char *, size_t, loff_t *);

int string_rev(char *str)
{
	int len, i, j, swap = 0;

	printk(KERN_ALERT "Chardev: %s : %d\n", __FUNCTION__, __LINE__);
	len = strlen(str);
	for (i = 0, j = (len-1); i < (len/2); i++, j--) {
		swap = str[i];
		str[i] = str[j];
		str[j] = swap;
	}
	return 0;
}

/** The device open function that is called each time the device is opened
 *  This will only increment the numberOpens counter in this case.
 *  @param inode A pointer to an inode object (defined in linux/fs.h)
 *  @param file A pointer to a file object (defined in linux/fs.h)
 */
static int dev_open(struct inode *inode, struct file *file)
{
	printk(KERN_ALERT "Chardev: %s : %d\n", __FUNCTION__, __LINE__);
	count++;
	printk(KERN_INFO "Chardev: Device has been opened %d time(s)\n", count);
	return 0;
}
/** This function is called whenever device is being read from user space i.e. data is
 *  being sent from the device to the user. In this case is uses the copy_to_user() function to
 *  send the buffer string to the user and captures any errors.
 *  @param file A pointer to a file object (defined in linux/fs.h)
 *  @param buff The pointer to the buffer to which this function writes the data
 *  @param len The length of the b
 *  @param off The offset if required
 */
static ssize_t dev_read(struct file *file, char *buff, size_t len, loff_t *off)
{
	int error_count = 0;
	printk(KERN_ALERT "%s : %d\n", __FUNCTION__, __LINE__);
	/* copy_to_user has the format ( * to, *from, size) and returns 0 on success */
	error_count = copy_to_user(buff, message, len);
	if (error_count==0) {
		printk(KERN_INFO "Chardev: Sent %d characters to the user\n", size_of_message);
		/* clear the position to the start and return 0 */
		return (size_of_message=0);  
	}
	else {
		printk(KERN_INFO "Chardev: Failed to send %d characters to the user\n", error_count);
 		/* Failed -- return a bad address message (i.e. -14) */
		return -EFAULT;             
	}
}
/** This function is called whenever the device is being written to from user space i.e.
 *  data is sent to the device from the user. The data is copied to the message[] array in this
 *  LKM using the sprintf() function along with the length of the string.
 *  @param file A pointer to a file object
 *  @param buff The buffer to that contains the string to write to the device
 *  @param len The length of the array of data that is being passed in the const char buffer
 *  @param off The offset if required
 */
static ssize_t dev_write(struct file *file, const char *buff, size_t len, loff_t *off)
{
	
	printk(KERN_ALERT "Chardev: %s : %d\n", __FUNCTION__, __LINE__);
	
	sprintf(message, "Chardev: %s(%zu letters)", buff, len);   // appending received string with its length
	size_of_message = strlen(message);                 // store the length of the stored message
	printk(KERN_INFO "Chardev: Received %zu characters from the user\n", len);
	
	copy_from_user(message, buff, len);
	printk(KERN_ALERT "%s\n", message);
	return len;
}

/* called when 'ioctl' system call is done on device file */
static long dev_ioctl(struct file *fil, unsigned int cmd, unsigned long arg)
{
	char *tmp_ptr = NULL;
	static int buf_size = 0;
	static char *kern_buf = NULL;
	int rv;
	struct string tmp_s;

	printk(KERN_ALERT "Chardev: %s : %d\n", __FUNCTION__, __LINE__);
 
	switch (cmd) {
		case CD_IOC_ALLOC_BUF:
			buf_size = arg;
			kern_buf = (char *) kmalloc(buf_size, GFP_USER);            
			printk(KERN_ALERT "Chardev: buf_size %d kern_buf %p\n", buf_size, kern_buf);
			break;

		case CD_IOC_WRITE_STRING:
			tmp_ptr = (char *)arg;
			copy_from_user(kern_buf, tmp_ptr, buf_size);
			printk(KERN_ALERT "Chardev: CD_IOC_WRITE_STRING: kern_buf %s\n", kern_buf);
			break;

		case CD_IOC_REVERSE_STRING:
			rv = string_rev(kern_buf);
			printk(KERN_ALERT "Chardev: CD_IOC_REVERSE_STRING: kern_buf %s\n", kern_buf);
			break;

		case CD_IOC_READ_STRING:
			copy_to_user((char *) arg, kern_buf, buf_size);
			break;
			case CD_IOC_FREE_BUF:
			kfree(fil);
			break;

		case CD_IOC_READ_WRITE_REVERSE_STRING:
			copy_from_user(&tmp_s, (struct string *) arg, sizeof(tmp_s));
			printk(KERN_ALERT "Chardev: String from user space %s\n", tmp_s.original);
			rv = string_rev(tmp_s.original);
			printk(KERN_ALERT "Chardev: Reversed String %s\n", tmp_s.original);
			copy_to_user(&(((struct string *) arg)->reverse), tmp_s.original, sizeof(tmp_s.original));
			break;
	         
		default:
			return -1;
	}
	return 0;
}
/** The device release function that is called whenever the device is closed/released by
 *  the userspace program
 *  @param inode A pointer to an inode object (defined in linux/fs.h)
 *  @param file A pointer to a file object (defined in linux/fs.h)
 */
static int dev_release(struct inode *inode, struct file *file)
{
	printk(KERN_ALERT "Chardev: %s : %d\n", __FUNCTION__, __LINE__);
	return 0;
}

/*structure containing callbacks
	Devices are represented as file structure in the kernel. The file_operations structure from
	/linux/fs.h lists the callback functions that you wish to associated with your file operations
	using a C99 syntax structure. char devices usually implement open, read, write and release calls 
	dev_open(): Called each time the device is opened from user space.
	dev_read(): Called when data is sent from the device to user space.
	dev_write(): Called when data is sent from user space to the device.
	dev_release(): Called when the device is closed in user space.
*/
struct file_operations chardev_fops = {
        .owner =    THIS_MODULE,
        .open =     dev_open,
        .read =     dev_read,
        .write =    dev_write,
        .unlocked_ioctl = dev_ioctl,
        .release =  dev_release,
};
/*
 * Set up the char_dev structure for this device.
 */
static void chardev_setup_cdev(struct chardev_dev *dev, int index)
{
        int err, devno = MKDEV(chardev_major, chardev_minor + index);

	printk(KERN_ALERT "Chardev: %s : %d\n", __FUNCTION__, __LINE__);
        
	cdev_init(&dev->cdev, &chardev_fops);
        dev->cdev.owner = THIS_MODULE;
        dev->cdev.ops = &chardev_fops;
        err = cdev_add(&dev->cdev, devno, 1);
        /* Fail gracefully if need be. */
        if (err)
                printk(KERN_NOTICE "Chardev: Error %d adding scull%d", err, index);
}

/*
 * The cleanup function is used to handle initialization failures as well.
 * Thefore, it must be careful to work correctly even if some of the items
 * have not been initialized.
 * unregister or free the allocated resources in reverse order as allocated in init func.
 */
void chardev_cleanup_module(void)
{
        dev_t devno = MKDEV(chardev_major, chardev_minor);
	
	printk(KERN_ALERT "Chardev: %s : %d\n", __FUNCTION__, __LINE__);

	if (charclass) {
		/* unregister the device class */
		class_unregister(charclass);
		/* remove the device class */
		class_destroy(charclass);
	}
        /* Get rid of our char dev entries. */
        if (chardev_devices) {
		cdev_del(&chardev_devices->cdev);
        	kfree(chardev_devices);
        }

        /* cleanup_module is never called if registering failed. */
        unregister_chrdev_region(devno, chardev_nr_devs);
}
/** The LKM initialization function
 *  The static keyword restricts the visibility of the function to within this C file. The __init
 *  macro means that for a built-in driver (not a LKM) the function is only used at initialization
 *  time and that it can be discarded and its memory freed up after that point.
 *  @return returns 0 if successful
 */
int chardev_init_module(void) 
{
	int result = 0;
        dev_t dev = 0;

	printk(KERN_ALERT "Chardev: %s : %d\n", __FUNCTION__, __LINE__);
	
	#if 0
	/* Try to dynamically allocate a major number for the device -- more difficult but worth it*/
	chardev_major = register_chrdev(0, DEVICE_NAME, &chardev_fops);
	if (majorNumber<0){
		printk(KERN_ALERT "Chardev failed to register a major number\n");
		return chardev_major;
	}
	printk(KERN_INFO "Chardev: registered correctly with major number %d\n", chardev_major);
	#endif
        /*
         * Get a range of minor numbers to work with, asking for a dynamic major
         * unless directed otherwise at load time.
	 * MAJOR(dev_t dev) extracts the major number from dev
	 * MINOR(dev_t dev) extracts the minor number from dev
	 * MKDEV(int major, int minor) creates the dev from major and minor.
	 * dev_t contains both major and minor numbers.
         */
        if (chardev_major) {
                dev = MKDEV(chardev_major, chardev_minor);
                result = register_chrdev_region(dev, chardev_nr_devs, "chardev");
		printk(KERN_INFO "Chardev: register_chrdev_region: %d\n", result);
        } else {
                result = alloc_chrdev_region(&dev, chardev_minor, chardev_nr_devs, "chardev");
                chardev_major = MAJOR(dev);
		printk(KERN_INFO "Chardev: alloc_chrdev_region: %d : scull_major: %d\n", result, chardev_major);
        }
        if (result < 0) {
                printk(KERN_WARNING "Chardev: can't get major %d\n", chardev_major);
                return result;
        }
        
	/* 
         * Allocate the devices. This must be dynamic as the device number can
         * be specified at load time.
         */
        chardev_devices = kmalloc(chardev_nr_devs * sizeof(struct chardev_dev), GFP_KERNEL);
        if (!chardev_devices) {
                printk(KERN_WARNING "Chardev: chardev kamlloc failed\n");
                result = -ENOMEM;
                goto fail;
        }
        memset(chardev_devices, 0, chardev_nr_devs * sizeof(struct chardev_dev));

        /* Initialize each device */
	chardev_setup_cdev(chardev_devices, 0);
	
	/* Register the device class
	The PTR_ERR() is a function that is defined in linux/err.h that retrieves the error number from the pointer.
	*/
	charclass = class_create(THIS_MODULE, CLASS_NAME);
	if (IS_ERR(charclass)){
		printk(KERN_ALERT "Chardev: Failed to register device class\n");
		/* Correct way to return an error on a pointer */
		result = PTR_ERR(charclass);          
		goto fail;
	}
	printk(KERN_INFO "Chardev: device class registered correctly\n");

	chardevice = device_create(charclass, NULL, MKDEV(chardev_major, 0), NULL, DEVICE_NAME);
	if (IS_ERR(chardevice)) {
		printk(KERN_ALERT "Chardev: Failed to create the device\n");
		result = PTR_ERR(chardevice);
		goto fail;
	}
	printk(KERN_INFO "Chardev: device class created correctly\n");

        return 0; /* succeed */

  fail:
        chardev_cleanup_module();
        return result;
}

/** A module must use the module_init() module_exit() macros from linux/init.h, which
 *  identify the initialization function at insertion time and the cleanup function (as
 *  listed above)
 */
module_init(chardev_init_module);
module_exit(chardev_cleanup_module);

/*module attributes*/
MODULE_LICENSE("GPL"); /* This avoids kernel taint warning .The license type -- this affects available functionality*/
MODULE_AUTHOR("Dharmender Sharma"); /*The author -- visible when you use modinfo*/
MODULE_DESCRIPTION("Device Driver Demo"); /*modinfo */
MODULE_VERSION("0.1"); /*A version number to inform users*/
