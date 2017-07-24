#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/jiffies.h>
 
static struct proc_dir_entry *parent, *file, *link;
static int state = 0;
 
int time_read(char *page, char **start, off_t off, int count, int *eof, void *data) {
    int len, val;
    unsigned long act_jiffies;
 
    len = sprintf(page, "state = %d\n", state);
    act_jiffies = jiffies - INITIAL_JIFFIES;
    val = jiffies_to_msecs(act_jiffies);
    switch (state) {   
        case 0:
            len += sprintf(page + len, "time = %ld jiffies\n", act_jiffies);
            break;
        case 1:
            len += sprintf(page + len, "time = %d msecs\n", val);
            break;
        case 2:
            len += sprintf(page + len, "time = %ds %dms\n",
                    val / 1000, val % 1000);
            break;
        case 3:
            val /= 1000;
            len += sprintf(page + len, "time = %02d:%02d:%02d\n",
                    val / 3600, (val / 60) % 60, val % 60);
            break;
        default:
            len += sprintf(page + len, "<not implemented>\n");
            break;
    }
    len += sprintf(page + len, "{offset = %ld; count = %d;}\n", off, count);
 
    return len;
}
int time_write(struct file *file, const char __user *buffer, unsigned long count, void *data) {
    if (count > 2)
        return count;
    if ((count == 2) && (buffer[1] != '\n'))
        return count;
    if ((buffer[0] < '0') || ('9' < buffer[0]))
        return count;
    state = buffer[0] - '0';
    return count;
}
 
static int __init proc_win_init(void) {
    if ((parent = proc_mkdir("anil", NULL)) == NULL) {
        return -1;
    }
    if ((file = create_proc_entry("rel_time", 0666, parent)) == NULL) {
        remove_proc_entry("anil", NULL);
        return -1;
    }
    file->read_proc = time_read;
    file->write_proc = time_write;
    if ((link = proc_symlink("rel_time_l", parent, "rel_time")) == NULL) {
        remove_proc_entry("rel_time", parent);
        remove_proc_entry("anil", NULL);
        return -1;
    }
    link->uid = 0;
    link->gid = 100;
    return 0;
}
 
static void __exit proc_win_exit(void) {
    remove_proc_entry("rel_time_l", parent);
    remove_proc_entry("rel_time", parent);
    remove_proc_entry("anil", NULL);
}
 
module_init(proc_win_init);
module_exit(proc_win_exit);
 
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Kernel window /proc Demonstration Driver");
