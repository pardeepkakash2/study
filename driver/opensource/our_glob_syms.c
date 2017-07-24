#include <linux/module.h>
#include <linux/device.h>
 
static struct class *cool_cl;
static struct class *get_cool_cl(void)
{
    return cool_cl;
}
EXPORT_SYMBOL(cool_cl);
EXPORT_SYMBOL_GPL(get_cool_cl);
 
static int __init glob_sym_init(void)
{
    if (IS_ERR(cool_cl = class_create(THIS_MODULE, "cool")))
    /* Creates /sys/class/cool/ */
    {
        return PTR_ERR(cool_cl);
    }
    return 0;
}
 
static void __exit glob_sym_exit(void)
{
    /* Removes /sys/class/cool/ */
    class_destroy(cool_cl);
}
 
module_init(glob_sym_init);
module_exit(glob_sym_exit);
 
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Global Symbols exporting Driver");
