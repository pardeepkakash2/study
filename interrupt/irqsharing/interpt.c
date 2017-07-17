/* Standard in kernel modules https://kerneltweaks.wordpress.com/tag/bottom-halves/
* https://notes.shichao.io/lkd/ch8/
* http://wiki.dreamrunner.org/public_html/BooksReview/Linux%20DeviceDrivers/LinuxDeviceDriversNotes.html
* http://learnlinuxconcepts.blogspot.in/2014/01/bottom-halves.html
* http://www.xml.com/ldd/chapter/book/ch09.html
* http://www.linuxquestions.org/questions/linux-kernel-70/porting-old-kernel-module-to-kernel-2-6-35-36-a-840599/
* http://cs.smith.edu/~nhowe/262/oldlabs/keyboard.html
*/
#include <linux/kernel.h>               /* We're doing kernel work */
#include <linux/module.h>               /* Specifically, a module */
#include <linux/sched.h>
/* We want an interrupt */
#include <linux/interrupt.h>
#include <asm/io.h>

int short_wq_count;

#if 0
irqreturn_t short_wq_interrupt(int irq, void *dev_id, struct pt_regs *regs)
{
	/* Grab the current time information. */
	do_gettimeofday((struct timeval *) tv_head);
	short_incr_tv(&tv_head);

	/* Queue the bh. Don't worry about multiple enqueueing */
	schedule_work(&short_wq);

	short_wq_count++; /* record that an interrupt arrived */
	return IRQ_HANDLED;
}
#endif

/* Bottom Half - this will get called by the kernel as soon as it's safe
 * to do everything normally allowed by kernel modules.
 */
static void short_do_tasklet(unsigned long scancode)
{
	
	printk("%s : Caller is %pS\n", __func__, __builtin_return_address(0));
	
	short_wq_count++; /* we have already been removed from the queue */

	printk("Scan Code %x %s.\n",
		(int) *((char *) scancode) & 0x7F,
		*((char *) scancode) & 0x80 ? "Released" : "Pressed");
}

void short_do_tasklet (unsigned long);
DECLARE_TASKLET(short_tasklet, short_do_tasklet, 0);

/* This function services keyboard interrupts. It reads the relevant
 * information from the keyboard and then scheduales the bottom half
 * to run when the kernel considers it safe.
 */
static irq_handler_t irq_handler(int irq, void *dev_id)
{
	/* This variables are static because they need to be 
	* accessible (through pointers) to the bottom half routine.
	*/
	static unsigned char scancode;
	unsigned char status;
	
	printk("%s : Caller is %pS\n", __func__, __builtin_return_address(0));

	/* Read keyboard status */
	status = inb(0x64);
	scancode = inb(0x60);

	/* Scheduale bottom half to run DECLARE_TASKLET(name, function, data);
	* name is the name to be given to the tasklet, function is the function that is called to execute 
	* the tasklet (it takes one unsigned long argument and returns void),
	* and data is an unsigned long value to be passed to the tasklet function
	*/
	
	tasklet_schedule(&short_tasklet);
	short_wq_count++; /* record that an interrupt arrived */
	return IRQ_HANDLED;
}

/* Initialize the module - register the IRQ handler */
int init_module()
{

	int ret = 0;

	printk("%s : Caller is %pS\n", __func__, __builtin_return_address(0));

	/*
	int request_irq(unsigned int irq,
			void (*handler)(int, void *, struct pt_regs *),
			unsigned long flags, const char *dev_name, void *dev_id);

	void free_irq(unsigned int irq, void *dev_id);
	*/

	/* Since the keyboard handler won't co-exist with another handler,
	* such as us, we have to disable it (free its IRQ) before we do
	* anything.  Since we don't know where it is, there's no way to
	*reinstate it later - so the computer will have to be rebooted
	* when we're done.
	*/
	free_irq(1, NULL);

	/* Request IRQ 1, the keyboard IRQ, to go to our irq_handler.
	* SA_SHIRQ means we're willing to have othe handlers on this IRQ.
	* SA_INTERRUPT can be used to make the handler into a fast interrupt. 
	* request_irq(unsigned int irq, irq_handler_t handler, unsigned long flags,
	    const char *name, void *dev)
	 what is happening after request_irq()?
	 How a particular handler is getting called on receiving interrupt?
	*/
	ret =  request_irq(1,   /* The number of the keyboard IRQ on PCs */ 
		irq_handler, /* our handler */
		IRQF_SHARED | IRQF_NO_SUSPEND, 
		"test_keyboard_irq_handler", NULL);

	if (ret) {
		printk(KERN_INFO "short: can't get assigned irq : 1 \n");
	}
	return ret;
}

/* Cleanup */
void cleanup_module()
{

	printk("%s : Caller is %pS\n", __func__, __builtin_return_address(0));

	/* This is only here for completeness. It's totally irrelevant, since
	 * we don't have a way to restore the normal keyboard interrupt so the
	 * computer is completely useless and has to be rebooted.
	*/
	free_irq(1, NULL);
}
