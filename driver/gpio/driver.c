#include <linux/module.h>
#include <linux/device.h>
#include <linux/cdev.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
 
MODULE_LICENSE("GPL");

#define MAJOR_NUM 1024  
#define MINOR_NUM 0    
 
dev_t dev = 0;

struct cdev cdev;

struct class *my_class;

static ssize_t globalvar_read(struct file *, char *, size_t, loff_t*);
static ssize_t globalvar_write(struct file *, const char *, size_t, loff_t*);
 
struct file_operations globalvar_fops =
{
 read: globalvar_read, write: globalvar_write,
};
static int global_var = 0;

static void char_reg_setup_cdev (void)
{
   int error, devno = MKDEV (MAJOR_NUM, MINOR_NUM);
   cdev_init (&cdev, &globalvar_fops);
   cdev.owner = THIS_MODULE;
   cdev.ops = &globalvar_fops;
   error = cdev_add (&cdev, devno , 1);
   if (error)
       printk (KERN_NOTICE "Error %d adding char_reg_setup_cdev", error);

}

static int __init globalvar_init(void)
{
 int ret;
 ret = register_chrdev(MAJOR_NUM, "globalvar", &globalvar_fops);
 if (ret)
 {
    printk("globalvar register failure");
 }
 else
 {
    printk("globalvar register success");
    return ret;
 }
 
 char_reg_setup_cdev();
 
 /* create your own class under /sysfs */
     my_class = class_create(THIS_MODULE, "my_class");
     if(IS_ERR(my_class)) 
     {
          printk("Err: failed in creating class.\n");
          return -1; 
      }

  /* register your own device in sysfs, and this will cause udev to create corresponding device node */
      device_create( my_class, NULL, MKDEV(MAJOR_NUM, 0), "hello" "%d", 0 );
      
 return ret;
}
 
static void __exit globalvar_exit(void)
{
	 dev_t devno = MKDEV (MAJOR_NUM, MINOR_NUM);
   cdev_del (&cdev);

   device_destroy(my_class, devno);         //delete device node under /dev
   class_destroy(my_class);                               //delete class created by us
 
   unregister_chrdev(MAJOR_NUM, "globalvar");

}
 
static ssize_t globalvar_read(struct file *filp, char *buf, size_t len, loff_t *off)
{
 if (copy_to_user(buf, &global_var, sizeof(int)))
 {
    return - EFAULT;
 }
 return sizeof(int);
}
 
static ssize_t globalvar_write(struct file *filp, const char *buf, size_t len, loff_t
 *off)
{
 if (copy_from_user(&global_var, buf, sizeof(int)))
 {
    return - EFAULT;
 }
 return sizeof(int);
}
 
module_init(globalvar_init);
module_exit(globalvar_exit);
