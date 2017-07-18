/* Standard in kernel modules: https://notes.shichao.io/lkd/ch8 */

#include <linux/kernel.h>               /* We're doing kernel work */
#include <linux/module.h>               /* Specifically, a module */
#include <linux/sched.h>
/* We want an interrupt */
#include <linux/interrupt.h>
#include <asm/io.h>
#include <linux/workqueue.h>
#include <linux/slab.h>
#include <linux/err.h>
#include <linux/irqnr.h>
#include <linux/irq.h>

#define KIRQ 1
#define DRIVER_NAME "test_keyboard_irq_handler"

#define printd() \
    printk(KERN_ALERT "irq_tasklet_test: %s: %d: caller: %pS\n", __func__, __LINE__, __builtin_return_address(0)); 
#define PATH_MAX        4096    /* # chars in a path name including nul */

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

static void kboard_dump_process_info( void )
{
	int ret;
	char *envp[] = { "HOME=/", "TERM=linux", "PATH=/sbin:/bin:/usr/sbin:/usr/bin", NULL };

	/* set up arguments */
	char *argv[] = { "/bin/sh", "-c", "/bin/ps -o  pid,tid,comm:20,state,cls,pri,nice,rtprio,pcpu,wchan:25,cmd:50,time axH --sort=-pcpu >> /dev/errmem", NULL};

	printk(KERN_EMERG "imx2_wdt_dump_process_info:  '%s' \n", argv[2]);

	ret = call_usermodehelper(argv[0], argv, envp, UMH_WAIT_PROC);
	if (ret < 0) {
		printk(KERN_EMERG
		       "imx2_wdt_dump_process_info: Error %d -  running user helper '/bin/ps' \n",
		       ret);
	}
}

static void kboard_dump_top_info( void )
{
	int ret;
	char *envp[] = { "HOME=/", "TERM=linux", "PATH=/sbin:/bin:/usr/sbin:/usr/bin", NULL };

	/* set up arguments */
	char *argv[] = { "/bin/sh", "-c", "/usr/bin/top -bn 1 >> /dev/errmem", NULL};

	printk(KERN_EMERG "imx2_wdt_dump_top_info:  '%s' \n", argv[2]);

	ret = call_usermodehelper(argv[0], argv, envp, UMH_WAIT_PROC);
	if (ret < 0) {
		printk(KERN_EMERG
		       "imx2_wdt_dump_top_info: Error %d -  running user helper '/usr/bin/top' \n",
		       ret);
	}
}

static void kboard_dump_interrupts_info( void )
{
	int ret;
	char *envp[] = { "HOME=/", "TERM=linux", "PATH=/sbin:/bin:/usr/sbin:/usr/bin", NULL };

	/* set up arguments */
	char *argv[] = { "/bin/sh", "-c", "cat /proc/interrupts >> /dev/errmem", NULL};

	printk(KERN_EMERG "imx2_wdt_dump_interrupts_info:  '%s' \n", argv[2]);

	ret = call_usermodehelper(argv[0], argv, envp, UMH_WAIT_PROC);
	if (ret < 0) {
		printk(KERN_EMERG
		       "imx2_wdt_dump_interrupts_info: Error %d -  running user helper 'cat /proc/interrupts' \n",
		       ret);
	}
}

#if 0
static void kboard_dump_tasks_info( void )
{
	struct task_struct *tsk, *thread;

	/* write task list into error memory */
	printk(KERN_EMERG "imx2_wdt_dump_debug_info: start -dumping task list\n");
	rcu_read_lock();
	for_each_process(tsk) {
		thread = tsk;
		do {
			printk(KERN_DEBUG "proc: %d - task: %d - name: %s , state: %ld ( on CPU '%d' )\n",
					task_tgid_vnr(thread),
					task_pid_vnr(thread),
					thread->comm,
					thread->state,
					thread->on_cpu);
		} while_each_thread(tsk, thread);
	};
	rcu_read_unlock();
	printk(KERN_DEBUG "imx2_wdt_dump_debug_info: end - dumping task list\n");
}

static void kboard_dump_interrupts_info( void )
{
	unsigned int irq;
	struct irq_desc *desc;

	/* write interrupt list into error memory */
	printk(KERN_DEBUG "imx2_wdt_dump_debug_info: start - dumping interrupt list \n");
	for_each_irq_desc(irq, desc) {
		if (!desc)
			continue;
		if (!desc->action)
			continue;
		printk(KERN_EMERG "interrupt: %u - name: %s\n",
			desc->irq_data.irq,
			desc->action->name ?
			desc->action->name : "---unknown---");
	}
	printk(KERN_DEBUG "imx2_wdt_dump_debug_info: end - dumping interrupt list \n");
}
#endif

static void kboard_dump_debug_info(char* cFuncName )
{
	#if 0
	char *pathname = NULL,*p = NULL;
	struct mm_struct *mm;

	if(current && current->mm)
	{
		mm = current->mm;
		down_read(&mm->mmap_sem);
		if (mm->exe_file) {
			pathname = kmalloc(PATH_MAX, GFP_ATOMIC);
			if (pathname) {
				p = d_path(&mm->exe_file->f_path, pathname, PATH_MAX);
				printk(KERN_EMERG "%s : - Process command: '%s', Process name :'%s', (pid: %d), State: '%ld' \n", 
					(cFuncName ? cFuncName : "---unknown---"), p, current->comm, current->pid, current->state) ;
			}
		}
		up_read(&mm->mmap_sem);
	}
	else {
		printk(KERN_EMERG "%s - Invalid current_struct\n", (cFuncName ? cFuncName : "---unknown---"));
	}
	#endif
	
	printk(KERN_DEBUG "process: pid: %i name:(%s) state: %ld\n", current->pid, current->comm, current->state);
	
	kboard_dump_process_info();
	kboard_dump_interrupts_info();
	kboard_dump_top_info();
}
/* Bottom Half - this will get called by the kernel as soon as it's safe
 * to do everything normally allowed by kernel modules.
 */
static void short_do_tasklet(unsigned long scancode)
{
	/*container_of(work_struct_ptr, struct your_original_struct, work_struct_fieldname);*/
	printd();
	kboard_dump_debug_info("Kboard_interrupt");
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
