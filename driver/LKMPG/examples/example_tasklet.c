#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/interrupt.h>

static void tasklet_fn(unsigned long data)
{
    printk("Example tasklet starts\n");
    mdelay(5000);
    printk("Example tasklet ends\n");
}

DECLARE_TASKLET(mytask, tasklet_fn, 0L);

static int example_tasklet_init(void)
{
    printk("tasklet example init\n");
    tasklet_schedule(&mytask);
    mdelay(200);
    printk("Example tasklet init continues...\n");
    return 0;
}

static void example_tasklet_exit(void)
{
    printk("tasklet example exit\n");
    tasklet_kill(&mytask);
}

module_init(example_tasklet_init);
module_exit(example_tasklet_exit);

MODULE_AUTHOR("Bob Mottram");
MODULE_DESCRIPTION("Tasklet example");
MODULE_LICENSE("GPL");
