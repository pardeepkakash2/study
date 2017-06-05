/*
 procfs1.c
*/

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <asm/uaccess.h>

#define procfs_name "helloworld"

struct proc_dir_entry *Our_Proc_File;


ssize_t procfile_read(struct file *filePointer,char *buffer,
                      size_t buffer_length, loff_t * offset)
{
    int ret=0;
    if(strlen(buffer) ==0) {
        printk(KERN_INFO "procfile read %s\n",filePointer->f_path.dentry->d_name.name);
        ret=copy_to_user(buffer,"HelloWorld!\n",sizeof("HelloWorld!\n"));
        ret=sizeof("HelloWorld!\n");
    }
    return ret;

}

static const struct file_operations proc_file_fops = {
    .owner = THIS_MODULE,
    .read  = procfile_read,
};

int init_module()
{
    Our_Proc_File = proc_create(procfs_name,0644,NULL,&proc_file_fops);
    if(NULL==Our_Proc_File) {
        proc_remove(Our_Proc_File);
        printk(KERN_ALERT "Error:Could not initialize /proc/%s\n",procfs_name);
        return -ENOMEM;
    }

    printk(KERN_INFO "/proc/%s created\n", procfs_name);
    return 0;
}

void cleanup_module()
{
    proc_remove(Our_Proc_File);
    printk(KERN_INFO "/proc/%s removed\n", procfs_name);
}
