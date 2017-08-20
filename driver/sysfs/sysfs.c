#include <linux/kernel.h>	 /* Need for KERN_INFO  */
#include <linux/module.h>	 /* Needed by all modules */
#include <linux/init.h> 	/* Need for macro module_init, exit etc */
#include <linux/moduleparam.h>	/* Need for module_param */

static short int param_number = 1;
static char *param_string = "sharma";

/* module_param(variable_name, data_type, permission_bits) */

module_param(param_number, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "A short integer");

module_param(param_string, charp, 0000);
MODULE_PARM_DESC(mystring, "A character string");


/*The __init macro causes the init function to be discarded and its memory freed once the init
* function finishes for built−in drivers, but not loadable module.
*/
static int __init sysfs_test_init(void)
{
	printk(KERN_ALERT ":%s\n", __func__);

	printk(KERN_INFO "param_number is a string: %d\n", param_number);	
	printk(KERN_INFO "param_string is a string: %s\n", param_string);	
	/* A non 0 return means init_module failed; module can't be load */
	return 0;
}

static void __exit sysfs_test_exit(void)
{

	printk(KERN_ALERT ":%s\n", __func__);
}

module_init(sysfs_test_init);
module_exit(sysfs_test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Dharmender Sharma");
MODULE_DESCRIPTION("test usecase of  sysfs dynamic filesystem");
