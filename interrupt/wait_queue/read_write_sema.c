#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h> 
#include <linux/cdev.h>
#include <linux/device.h>
#include <asm/uaccess.h>
#include <linux/semaphore.h>
#include <linux/sched.h>
#include <linux/delay.h>

#define FIRST_MINOR 0
#define MINOR_CNT 1

static dev_t dev;
static struct cdev c_dev;
static struct class *cl;
static struct task_struct *task;
static struct rw_semaphore rwsem;

int open(struct inode *inode, struct file *filp)
{
    printk(KERN_INFO "Inside open\n");
    task = current;
    return 0;
}

int release(struct inode *inode, struct file *filp)
{
    printk(KERN_INFO "Inside close\n");
    return 0;
}

ssize_t read(struct file *filp, char *buff, size_t count, loff_t *offp)
{
    printk("Inside read\n");
    down_read(&rwsem);
    printk(KERN_INFO "Got the Semaphore in Read\n");
    printk("Going to Sleep\n");
    ssleep(30);
    up_read(&rwsem);
    return 0;
}

ssize_t write(struct file *filp, const char *buff, size_t count, loff_t *offp)
{
    printk(KERN_INFO "Inside write. Waiting for Semaphore...\n");
    down_write(&rwsem);
    printk(KERN_INFO "Got the Semaphore in Write\n");
    up_write(&rwsem);
    return count;
}

struct file_operations fops =
{
    read:    read,
    write:   write,
    open:    open,
    release: release
};

int rw_sem_init(void)
{
    int ret;
    struct device *dev_ret;

    if ((ret = alloc_chrdev_region(&dev, FIRST_MINOR, MINOR_CNT, "rws")) < 0)
    {
        return ret;
    }
    printk("Major Nr: %d\n", MAJOR(dev));

    cdev_init(&c_dev, &fops);

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

    init_rwsem(&rwsem);

    return 0;
}

void rw_sem_cleanup(void)
{
    printk(KERN_INFO "Inside cleanup_module\n");
    device_destroy(cl, dev);
    class_destroy(cl);
    cdev_del(&c_dev);
    unregister_chrdev_region(dev, MINOR_CNT);
}

module_init(rw_sem_init);
module_exit(rw_sem_cleanup);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("SysPlay Workshops <workshop@sysplay.in>");
MODULE_DESCRIPTION("Reader Writer Semaphore Demo");
