#include <linux/module.h>
#include <linux/kernel.h>
 
static int cfg_value = 3;
module_param(cfg_value, int, 0764);
 
static int __init mod_par_init(void)
{
    printk(KERN_INFO "Loaded with %d\n", cfg_value);
    return 0;
}
 
static void __exit mod_par_exit(void)
{
    printk(KERN_INFO "Unloaded cfg value: %d\n", cfg_value);
}
 
module_init(mod_par_init);
module_exit(mod_par_exit);
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Module Parameter demonstration Driver");
