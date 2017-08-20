#include <linux/kernel.h>	 /* Need for KERN_INFO  */
#include <linux/module.h>	 /* Needed by all modules */
#include <linux/init.h> 	/* Need for macro module_init, exit etc */
#include <linux/moduleparam.h>	/* Need for module_param */
#include <linux/kobject.h>
#include <linux/sysfs.h> 
#include <linux/init.h> 
#include <linux/fs.h> 
#include <linux/string.h>
#include <linux/stat.h>		/* S_IRUSR, S_IWUSR */

static int param_number = 1;
static char *param_string = "sharma";

/* module_param(variable_name, data_type, permission_bits) */

module_param(param_number, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "A short integer");

module_param(param_string, charp, 0000);
MODULE_PARM_DESC(mystring, "A character string");

enum { SYSFS_SIZE_MAX = 4 };
static int sysfs_size;
static char sysfs_tmp[SYSFS_SIZE_MAX];

static struct kobject *sysfs_kernel_kobject;

/**
ssize_t (*show)(struct kobject * kobj, struct attribute * attr, char * buff);
where,
kobj: This is the pointer to the kobject of the directory which was passed when the file was created.
attr: This is the attribute pointer of the file which was passed when file was created.
buff: This is the buffer in which the output should be written, which will be displayed as the result in user space. 
The value written should not exceed the size defined by the PAGE_SIZE macro.
*/
static ssize_t sysfs_test_show(struct kobject *kobj, struct kobj_attribute *attr, char *buf)
{
	printk(KERN_INFO "SYSFS: %s: %pS\n", __func__, __builtin_return_address(0));
        dump_stack();
	//return sprintf(buf, "%d\n", param_number);
        strncpy(buf, sysfs_tmp, sysfs_size);
	return sysfs_size;
}
/*
ssize_t (*store)(struct kobject * kobj, struct attribute * attr, const char * buff, size_t size);
where, kobject and attr are as described above.
buff: This buffer contains the value that was written to the file from user space.
size: This is the size of the data written to the file through user space.
*/
static ssize_t sysfs_test_store(struct kobject *kobj, struct kobj_attribute *attr, char *buf, size_t count)
{
	printk(KERN_INFO "SYSFS: %s: %pS\n", __func__, __builtin_return_address(0));
        dump_stack();
	sysfs_size = min(count, (size_t)SYSFS_SIZE_MAX);
	strncpy(sysfs_tmp, buf, sysfs_size);

       // sscanf(buf, "%du", &param_number);
        return count;
}

/*
__ATTR(name, permission, show_ptr, store_ptr)
where, name is the name with which the attribute is to be created, 
permission is file permission where 0666 is read and write permission, 
show_ptr is the function pointer called when the file is read,
store_ptr is the function pointer called when the file is written.
static struct kobj_attribute sysfs_test_attribute = { 
	.attr = { 
		.name = "foo", 
		.mode = S_IWUSR | S_IRUGO, 
	}, 
	.show = foo_show, 
	.store = foo_store, 
};
*/
static struct kobj_attribute sysfs_test_attribute = __ATTR(sysfs_test, S_IRUGO | S_IWUSR, sysfs_test_show, sysfs_test_store);
//static DEVICE_ATTR(sysfs_test, 0660, sysfs_test_show, sysfs_test_store, NULL);

#if 0
static struct attribute *attrs[] = {
    &sysfs_test_attribute.attr,
    NULL,
};
#endif

/*The __init macro causes the init function to be discarded and its memory freed once the init
* function finishes for built−in drivers, but not loadable module.
*/
static int __init sysfs_test_init(void)
{
	int err = 0;

	printk(KERN_INFO "SYSFS: %s: %pS\n", __func__, __builtin_return_address(0));
        dump_stack();
	
	printk(KERN_INFO "param_number : %d\n", param_number);	
	printk(KERN_INFO "param_string : %s\n", param_string);

	/*
	struct kobject * kobject_create_and_add(const char *name, struct kobject *parent);
	where,
	name: is the name of the directory to be created in sysfs
	parent: is the kobject of the parent directory in which the current directory is to be created.
	The return value is the kobject pointer of the created directory, and if it fails then return a NULL pointer.
	*/
        sysfs_kernel_kobject = kobject_create_and_add("sysfs_kernel_kobject", kernel_kobj);
        if(!sysfs_kernel_kobject)
                return -ENOMEM;

        err = sysfs_create_file(sysfs_kernel_kobject, &sysfs_test_attribute.attr);
        if (err) {
                pr_debug("failed to create syfs file: /sys/kernel/sysfs_kernel_kobject\n");
		kobject_put(sysfs_kernel_kobject);
		return err;
        }
	pr_info("created the sysfs file: /sys/kernel/sysfs_kernel_kobject\n");
	
	/* A non 0 return means init_module failed; module can't be load */
	return 0;
}

static void __exit sysfs_test_exit(void)
{
	printk(KERN_INFO "SYSFS: %s: %pS\n", __func__, __builtin_return_address(0));
        dump_stack();
	pr_debug ("Module uninitialized successfully \n");

	/*remove the kobject from the sysfs*/	
	kobject_put(sysfs_kernel_kobject);

}

module_init(sysfs_test_init);
module_exit(sysfs_test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Dharmender Sharma");
MODULE_DESCRIPTION("test usecase of  sysfs dynamic filesystem");
