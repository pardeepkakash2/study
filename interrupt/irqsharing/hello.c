#include <linux/module.h>
#include <linux/kernel.h>

static int __devinit mykmod_init(void)
{
        pr_info("mykmod loaded\n");
        return 0;
}

static void __devexit mykmod_exit(void)
{
        pr_info("mykmod exit\n");
}

module_init(mykmod_init);
module_exit(mykmod_exit);

MODULE_DESCRIPTION("mykmod");
MODULE_LICENSE("GPL");
