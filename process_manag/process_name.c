#include <linux/init.h>
#include <linux/module.h> 
#include<linux/sched.h>
#include <linux/rcupdate.h>
#include <linux/fdtable.h>
#include <linux/fs.h> 
#include <linux/fs_struct.h>
#include <linux/dcache.h>
#include <linux/slab.h>

MODULE_LICENSE("Dual BSD/GPL");

static int current_init(void)
{ 

	struct files_struct *current_files; 
	struct fdtable *files_table;
	int i=0;
	struct path files_path;
	char *cwd;
	char *buf = (char *)kmalloc(GFP_KERNEL,100*sizeof(char));

	current_files = current->files;
	files_table = files_fdtable(current_files);

	while(files_table->fd[i] != NULL) { 
		files_path = files_table->fd[i]->f_path;
		cwd = d_path(&files_path,buf,100*sizeof(char));
		printk(KERN_ALERT "Open file with fd %d  %s", i,cwd);
		i++;
	}
	
	printk(KERN_DEBUG "process pid: %i name: (%s) state: %ld\n", current->pid, current->comm, current->state);
	return 0; 
}

static void current_exit(void) 
{ 
	printk(KERN_ALERT "Goodbye cruel world"); 
} 

module_init(current_init);
module_exit(current_exit);

