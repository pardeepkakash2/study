#include <linux/module.h>
#include <linux/string.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/slab.h>
#include "character_driver.h"

//module attributes
MODULE_LICENSE("GPL"); // This avoids kernel taint warning
MODULE_DESCRIPTION("Device Driver Demo");
MODULE_AUTHOR("Jeevitha");

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

//prototypes, else the structure initialization that follows fail
static int dev_open(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char *, size_t, loff_t *);
static ssize_t dev_write(struct file *, const char *, size_t, loff_t *);
static long dev_ioctl(struct file *, unsigned int, unsigned long);
static int dev_rls(struct inode *, struct file *);

//structure containing callbacks
static struct file_operations fops = 
{
    .unlocked_ioctl = dev_ioctl, // address of dev_ioctl
    .open = dev_open, // address of dev_open
    .read = dev_read, // address of dev_read
    .write = dev_write, // address of dev_write
    .release = dev_rls, // address of dev_rls
};

// called when module is loaded, similar to main()
int init_module(void)
{
    int t = register_chrdev(89,"myDev", &fops); //register driver with major : 89
    
    if (t < 0) printk(KERN_ALERT "Device registration failed..\n");
    else printk(KERN_ALERT "Device registered...\n");

    return t;
}

//called when module is unloaded, similar to destructor in OOP
void cleanup_module(void)
{
    unregister_chrdev(89,"myDev");
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
static int dev_rls(struct inode *inod, struct file *fil)
{
    printk(KERN_ALERT "%s : %d\n", __FUNCTION__, __LINE__);
    return 0;
}
