#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/init.h>

#include <linux/kernel.h>       /* printk() */
#include <linux/slab.h>         /* kmalloc() */
#include <linux/fs.h>           /* everything... */
#include <linux/errno.h>        /* error codes */
#include <linux/types.h>        /* size_t */
#include <linux/proc_fs.h>
#include <linux/fcntl.h>        /* O_ACCMODE */
#include <linux/seq_file.h>
#include <linux/cdev.h>

#include <linux/string.h>
#include <asm/uaccess.h>        /* copy_*_user */

#include "chardev.h"              /* local definitions */

/*
 * Our parameters which can be set at load time.
 */

int scull_major =   SCULL_MAJOR;
int scull_minor =   0;
int scull_nr_devs = SCULL_NR_DEVS;      /* number of bare scull devices */

module_param(scull_major, int, S_IRUGO);
module_param(scull_minor, int, S_IRUGO);
module_param(scull_nr_devs, int, S_IRUGO);

struct scull_dev *scull_devices;        /* allocated in scull_init_module */

static char tmp[100] = {0};

int string_rev(char *str)
{
    int len, i, j, swap = 0;
    len = strlen(str);

    for (i = 0, j = (len-1); i < (len/2); i++, j--) {
        swap = str[i];
        str[i] = str[j];
        str[j] = swap;
    }

    return 0;
}

//called when 'open' system call is done on device file
static int dev_open(struct inode *inod, struct file *fil)
{
    printk(KERN_ALERT "%s : %d\n", __FUNCTION__, __LINE__);
    return 0;
}

//called when 'read' system call is done on device file
 static ssize_t dev_read(struct file *filp, char *buff, size_t len, loff_t *off)
{
    printk(KERN_ALERT "%s : %d\n", __FUNCTION__, __LINE__);
    copy_to_user(buff, tmp, len);
    return len;
}

//called when 'write' system call is done on device file
static ssize_t dev_write(struct file *filp, const char *buff, size_t len, loff_t *off)
{
    int rv;
    printk(KERN_ALERT "%s : %d\n", __FUNCTION__, __LINE__);
    copy_from_user(tmp, buff, len);
    printk(KERN_ALERT "%s\n", tmp);
    rv = string_rev(tmp);
    return len;
}

//called when 'ioctl' system call is done on device file
static long dev_ioctl(struct file *fil, unsigned int cmd, unsigned long arg)
{
    char *tmp_ptr = NULL;
    static int buf_size = 0;
    static char *kern_buf = NULL;
    int rv;
    struct string tmp_s;

    printk(KERN_ALERT "%s : %d\n", __FUNCTION__, __LINE__);
 
    switch (cmd) {
        case CD_IOC_ALLOC_BUF:
            buf_size = arg;
            kern_buf = (char *) kmalloc(buf_size, GFP_USER);            
            printk(KERN_ALERT " buf_size %d kern_buf %p\n", buf_size, kern_buf);
            break;

        case CD_IOC_WRITE_STRING:
            tmp_ptr = (char *)arg;
            copy_from_user(kern_buf, tmp_ptr, buf_size);
            printk(KERN_ALERT "CD_IOC_WRITE_STRING: kern_buf %s\n", kern_buf);
            break;

        case CD_IOC_REVERSE_STRING:
            rv = string_rev(kern_buf);
            printk(KERN_ALERT "CD_IOC_REVERSE_STRING: kern_buf %s\n", kern_buf);
            break;

        case CD_IOC_READ_STRING:
            copy_to_user((char *) arg, kern_buf, buf_size);
            break;

        case CD_IOC_FREE_BUF:
            kfree(fil);
            break;

        case CD_IOC_READ_WRITE_REVERSE_STRING:
            copy_from_user(&tmp_s, (struct string *) arg, sizeof(tmp_s));
            printk(KERN_ALERT "String from user space %s\n", tmp_s.original);
            rv = string_rev(tmp_s.original);
            printk(KERN_ALERT "Reversed String %s\n", tmp_s.original);
            copy_to_user(&(((struct string *) arg)->reverse), tmp_s.original, sizeof(tmp_s.original));
            break;
         
        default:
            return -1;
    }
    return 0;
}

//called when 'close' system call is done on device file
static int dev_release(struct inode *inod, struct file *fil)
{
    printk(KERN_ALERT "%s : %d\n", __FUNCTION__, __LINE__);
    return 0;
}

/*structure containing callbacks*/
struct file_operations scull_fops = {
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
static void scull_setup_cdev(struct scull_dev *dev, int index)
{
        int err, devno = MKDEV(scull_major, scull_minor + index);

	printk(KERN_ALERT "%s : %d\n", __FUNCTION__, __LINE__);
        
	cdev_init(&dev->cdev, &scull_fops);
        dev->cdev.owner = THIS_MODULE;
        dev->cdev.ops = &scull_fops;
        err = cdev_add(&dev->cdev, devno, 1);
        /* Fail gracefully if need be. */
        if (err)
                printk(KERN_NOTICE "Error %d adding scull%d", err, index);
}

/*
 * The cleanup function is used to handle initialization failures as well.
 * Thefore, it must be careful to work correctly even if some of the items
 * have not been initialized.
 */
void scull_cleanup_module(void)
{
        dev_t devno = MKDEV(scull_major, scull_minor);
	
	printk(KERN_ALERT "%s : %d\n", __FUNCTION__, __LINE__);

        /* Get rid of our char dev entries. */
        if (scull_devices) {
		cdev_del(&scull_devices->cdev);
        	kfree(scull_devices);
        }

        /* cleanup_module is never called if registering failed. */
        unregister_chrdev_region(devno, scull_nr_devs);
}

// called when module is loaded, similar to main()
int scull_init_module(void)
{
	int result = 0;
        dev_t dev = 0;

	printk(KERN_ALERT "%s : %d\n", __FUNCTION__, __LINE__);
        /*
         * Get a range of minor numbers to work with, asking for a dynamic major
         * unless directed otherwise at load time.
         */
        if (scull_major) {
                dev = MKDEV(scull_major, scull_minor);
                result = register_chrdev_region(dev, scull_nr_devs, "chardev");
		printk(KERN_INFO "register_chrdev_region: %d\n", result);
        } else {
                result = alloc_chrdev_region(&dev, scull_minor, scull_nr_devs, "chardev");
                scull_major = MAJOR(dev);
		printk(KERN_INFO "alloc_chrdev_region: %d : scull_major: %d\n", result, scull_major);
        }
        if (result < 0) {
                printk(KERN_WARNING "chardev: can't get major %d\n", scull_major);
                return result;
        }

        /* 
         * Allocate the devices. This must be dynamic as the device number can
         * be specified at load time.
         */
        scull_devices = kmalloc(scull_nr_devs * sizeof(struct scull_dev), GFP_KERNEL);
        if (!scull_devices) {
                printk(KERN_WARNING "chardev kamlloc failed\n");
                result = -ENOMEM;
                goto fail;
        }
        memset(scull_devices, 0, scull_nr_devs * sizeof(struct scull_dev));

        /* Initialize each device. */
	scull_setup_cdev(scull_devices, 0);

        return 0; /* succeed */

  fail:
        scull_cleanup_module();
        return result;
}

module_init(scull_init_module);
module_exit(scull_cleanup_module);

/*module attributes*/
MODULE_LICENSE("GPL"); /* This avoids kernel taint warning*/
MODULE_DESCRIPTION("Device Driver Demo");
MODULE_AUTHOR("Dharmender Sharma");
