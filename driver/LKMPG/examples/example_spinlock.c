#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/spinlock.h>
#include <linux/interrupt.h>

DEFINE_SPINLOCK(sl_static);
spinlock_t sl_dynamic;

static void example_spinlock_static(void)
{
    unsigned long flags;

    spin_lock_irqsave(&sl_static, flags);
    printk("Locked static spinlock\n");

    /* Do something or other safely.
       Because this uses 100% CPU time this
       code should take no more than a few
       milliseconds to run */

    spin_unlock_irqrestore(&sl_static, flags);
    printk("Unlocked static spinlock\n");
}

static void example_spinlock_dynamic(void)
{
    unsigned long flags;

    spin_lock_init(&sl_dynamic);
    spin_lock_irqsave(&sl_dynamic, flags);
    printk("Locked dynamic spinlock\n");

    /* Do something or other safely.
       Because this uses 100% CPU time this
       code should take no more than a few
       milliseconds to run */

    spin_unlock_irqrestore(&sl_dynamic, flags);
    printk("Unlocked dynamic spinlock\n");
}

static int example_spinlock_init(void)
{
    printk("example spinlock started\n");

    example_spinlock_static();
    example_spinlock_dynamic();

    return 0;
}

static void example_spinlock_exit(void)
{
    printk("example spinlock exit\n");
}

module_init(example_spinlock_init);
module_exit(example_spinlock_exit);

MODULE_AUTHOR("Bob Mottram");
MODULE_DESCRIPTION("Spinlock example");
MODULE_LICENSE("GPL");
