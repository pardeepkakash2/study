#include <linux/module.h>
#include <linux/init.h>
#include <linux/kmod.h>
#include <linux/err.h>
#include <linux/irqnr.h>
#include <linux/irq.h>
#include <linux/irqdesc.h>
#include<linux/slab.h>
#include<linux/sched.h>
#include <linux/proc_fs.h>
 
MODULE_LICENSE( "GPL" );

static void dump_top_info( void )
{
	int ret;
	char *envp[] = { "HOME=/", "TERM=linux", "PATH=/sbin:/bin:/usr/sbin:/usr/bin", NULL };

	/* set up arguments */
	char *argv[] = { "/bin/sh", "-c", "/usr/bin/top -bn 1 >> /home/dus5cob/top", NULL};

	printk(KERN_EMERG "dump_top_info:  '%s' \n", argv[2]);

	ret = call_usermodehelper(argv[0], argv, envp, UMH_WAIT_PROC);
	if (ret < 0) {
		printk(KERN_EMERG
		       "dump_top_info: Error %d -  running user helper '/usr/bin/top' \n",
		       ret);
	}
}

static void dump_process_info( void )
{
	int ret;
	char *envp[] = { "HOME=/", "TERM=linux", "PATH=/sbin:/bin:/usr/sbin:/usr/bin", NULL };
	char *argv [] = { "/bin/sh", "-c", "/bin/ps -o  pid,tid,comm:20,state,cls,pri,nice,rtprio, \
			pcpu,wchan:25,cmd:50,time axH --sort=-pcpu >> /home/dus5cob/ps", NULL};
 
	printk(KERN_EMERG "dump_process_info:  '%s' \n", argv[2]);

	ret = call_usermodehelper(argv[0], argv, envp, UMH_WAIT_PROC);
	if (ret < 0) {
		printk(KERN_EMERG "dump_process_info: Error %d -  running user helper '/bin/ps' \n", ret);
	} 
}

static void dump_tasks_info( void )
{
	struct task_struct *tsk, *thread;

	/* write task list into error memory */
	printk(KERN_EMERG "dump_task_info: start -dumping task list\n");
	rcu_read_lock();
	/* iterate over the entire circuler double task linklist */
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
	printk(KERN_DEBUG "dump_debug_info: end - dumping task list\n");
}

#if 0
static void dump_interrupts_info( void )
{
	unsigned int irq;
	struct irq_desc *desc;

	/* write interrupt list into error memory */
	printk(KERN_DEBUG "dump_debug_info: start - dumping interrupt list \n");
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
	printk(KERN_DEBUG "dump_debug_info: end - dumping interrupt list \n");
}
#endif
static void dump_debug_info(char* cFuncName )
{
	char *pathname = NULL,*p = NULL;
	struct mm_struct *mm;

	printk("%s : Caller is %pS\n", __func__, __builtin_return_address(0));

	#if 0
	struct task_struct *task = current; // getting global current pointer
	printk(KERN_NOTICE "assignment: current process: %s, PID: %d", task->comm, task->pid);
	do
	{
		task = task->parent;
		printk(KERN_NOTICE "assignment: parent process: %s, PID: %d", task->comm, task->pid);
	} while (task->pid != 0); 
	#endif
	/* current is a global pointer which points to the current task*/
	if(current && current->mm)
	{
		mm = current->mm;
		down_read(&mm->mmap_sem);
		if (mm->exe_file) {
			pathname = kmalloc(PATH_MAX, GFP_ATOMIC);
			if (pathname) {
				/*Now you have the path name of exe in p*/
				p = d_path(&mm->exe_file->f_path, pathname, PATH_MAX);
				printk(KERN_EMERG "%s : - Process command: '%s', Process name :'%s', (pid: %d), \
					State: '%ld' \n", (cFuncName ? cFuncName : "---unknown---"), p, current->comm, current->pid, current->state) ;
			}
		}
		up_read(&mm->mmap_sem);
	}
	else {
		printk(KERN_EMERG "%s - Invalid current_struct\n", (cFuncName ? cFuncName : "---unknown---"));
	}

	dump_process_info();
	dump_top_info();
	dump_tasks_info();
} 
static int __init mod_entry_func( void )
{
	printk("%s : Caller is %pS\n", __func__, __builtin_return_address(0));
	dump_debug_info("wdt_interrupt");
	return 0;
}
 
 
static void __exit mod_exit_func( void )
{
	return;
}
 
module_init( mod_entry_func );
module_exit( mod_exit_func );
