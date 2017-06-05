#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/mutex.h>

DEFINE_MUTEX(mymutex);

static int example_mutex_init(void)
{
    int ret;

    printk("example_mutex init\n");

    ret = mutex_trylock(&mymutex);
    if (ret != 0) {
        printk("mutex is locked\n");

        if (mutex_is_locked(&mymutex) == 0)
            printk("The mutex failed to lock!\n");

        mutex_unlock(&mymutex);
        printk("mutex is unlocked\n");
    }
    else
        printk("Failed to lock\n");

    return 0;
}

static void example_mutex_exit(void)
{
    printk("example_mutex exit\n");
}

module_init(example_mutex_init);
module_exit(example_mutex_exit);

MODULE_AUTHOR("Bob Mottram");
MODULE_DESCRIPTION("Mutex example");
MODULE_LICENSE("GPL");
