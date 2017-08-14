#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/errno.h>
#include <asm/uaccess.h>
#include <linux/wait.h>
#include <linux/sched.h>
#include <linux/delay.h>

#define FIRST_MINOR 0
#define MINOR_CNT 1

static char flag = 'n';
static dev_t dev;
static struct cdev c_dev;
static struct class *cl;
static DECLARE_WAIT_QUEUE_HEAD(wq);

int open(struct inode *inode, struct file *filp)
{
	printk(KERN_INFO "Inside open\n");
	return 0;
}

int release(struct inode *inode, struct file *filp) 
{
	printk (KERN_INFO "Inside close\n");
	return 0;
}

ssize_t read(struct file *filp, char *buff, size_t count, loff_t *offp) 
{
	printk(KERN_INFO "Inside read\n");
	printk(KERN_INFO "Scheduling Out\n");
	wait_event_interruptible(wq, flag == 'y');
	flag = 'n';
	printk(KERN_INFO "Woken Up\n");
	return 0;
}

ssize_t write(struct file *filp, const char *buff, size_t count, loff_t *offp) 
{   
	printk(KERN_INFO "Inside write\n");
	if (copy_from_user(&flag, buff, 1))
	{
		return -EFAULT;
	}
	printk(KERN_INFO "%c", flag);
	wake_up_interruptible(&wq);
	return count;
}

struct file_operations pra_fops = {
	read:        read,
	write:       write,
	open:        open,
	release:     release
};

int wq_init (void)
{
	int ret;
	struct device *dev_ret;

	if ((ret = alloc_chrdev_region(&dev, FIRST_MINOR, MINOR_CNT, "SCD")) < 0)
	{
		return ret;
	}
	printk("Major Nr: %d\n", MAJOR(dev));

	cdev_init(&c_dev, &pra_fops);

	if ((ret = cdev_add(&c_dev, dev, MINOR_CNT)) < 0)
	{
		unregister_chrdev_region(dev, MINOR_CNT);
		return ret;
	}

	if (IS_ERR(cl = class_create(THIS_MODULE, "chardrv")))
	{
		cdev_del(&c_dev);
		unregister_chrdev_region(dev, MINOR_CNT);
		return PTR_ERR(cl);
	}
	if (IS_ERR(dev_ret = device_create(cl, NULL, dev, NULL, "mychar%d", 0)))
	{
		class_destroy(cl);
		cdev_del(&c_dev);
		unregister_chrdev_region(dev, MINOR_CNT);
		return PTR_ERR(dev_ret);
	}
	return 0;
}

void wq_cleanup(void)
{
	printk(KERN_INFO "Inside cleanup_module\n");
	device_destroy(cl, dev);
	class_destroy(cl);
	cdev_del(&c_dev);
	unregister_chrdev_region(dev, MINOR_CNT);
}

module_init(wq_init);
module_exit(wq_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Dharmender Sharma");
MODULE_DESCRIPTION("Waiting Process Demo");
