/* Standard in kernel modules: https://notes.shichao.io/lkd/ch8 */

#include <linux/kernel.h>               /* We're doing kernel work */
#include <linux/module.h>               /* Specifically, a module */
#include <linux/sched.h>
/* We want an interrupt */
#include <linux/interrupt.h>
#include <asm/io.h>
#include <linux/workqueue.h>
#include <linux/slab.h>

#define KIRQ 1
#define DRIVER_NAME "test_keyboard_irq_handler"

#define printd() \
    printk(KERN_ALERT "irq_tasklet_test: %s: %d: caller: %pS\n", __func__, __LINE__, __builtin_return_address(0)); 

struct kboard_data {
	unsigned char scancode;
	unsigned char status;
};
static struct kboard_data data;

#if 0
struct workqueue_struct *wq;
struct work_data {
	struct work_struct work;
	int data;
	unsigned char scancode;
	unsigned char status;
};

/* This will get called by the kernel as soon as it's safe to do everything normally allowed by kernel modules. */
static void workq_handler(struct work_struct *work)
{
	struct work_data * data = (struct work_data *)work;

	printd();
	printk(KERN_INFO "Scan Code %x %s.\n", data->scancode, data->scancode ? "Released" : "Pressed");
	kfree(data);
}
#endif

int count = 0;
/* Bottom Half - this will get called by the kernel as soon as it's safe
 * to do everything normally allowed by kernel modules.
 */
static void short_do_tasklet(unsigned long scancode)
{
	/*container_of(work_struct_ptr, struct your_original_struct, work_struct_fieldname);*/
	printd();
}

DECLARE_TASKLET(short_tasklet, short_do_tasklet, 0);

/* This function services keyboard interrupts. It reads the relevant
 * information from the keyboard and then scheduales the bottom half
 * to run when the kernel considers it safe.
 */
static irqreturn_t irq_handler( int irq, void *dev_id )
{
	struct kboard_data *data = dev_id;

	printd();

	/* Read keyboard status */
	data->status = inb(0x64);
	data->scancode = inb(0x60);
	
	
	printk("Scan Code %c %c.\n", data->scancode, data->status);

	/* Scheduale bottom half to run DECLARE_TASKLET(name, function, data);
	* name is the name to be given to the tasklet, function is the function that is called to execute 
	* the tasklet (it takes one unsigned long argument and returns void),
	* and data is an unsigned long value to be passed to the tasklet function
	*/
	
	tasklet_schedule(&short_tasklet);
	count++; /* record that an interrupt arrived */
	printk(KERN_INFO "count: %d\n", count);

	#if 0	
	struct work_data * wqdata;
	wq = create_workqueue("wq_test");
	wqdata = kmalloc(sizeof(struct work_data), GFP_KERNEL);
	
	/*only for workqueue*/
	wqdata->status = inb(0x64);
	wqdata->scancode = inb(0x60);
	
	INIT_WORK(&wqdata->work, workq_handler);
	queue_work(wq, &wqdata->work);
	#endif

	return IRQ_HANDLED;
}

/* Initialize the module - register the IRQ handler */
static int __init kboard_init(void)
{

	int ret = 0;

	/* Since the keyboard handler won't co-exist with another handler,
	 * we have to disable it (free its IRQ) before we do anything.
	*/
	free_irq(KIRQ, NULL);

	/* Request Keyboard IRQ 1 : cat /proc/interrupts.*/
	ret = request_irq(KIRQ, irq_handler, IRQF_SHARED, DRIVER_NAME, &data);
	if (ret) {
		printk(KERN_NOTICE DRIVER_NAME ": IRQ request failed\n");
		return ret;
	}
	return 0;
}

/* Deinitialize the module - unregister the IRQ handler */
static void __exit kboard_exit(void)
{
	free_irq(KIRQ, &data);
}

module_init(kboard_init);
module_exit(kboard_exit);
MODULE_LICENSE("GPL");
