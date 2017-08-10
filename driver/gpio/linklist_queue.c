#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/string.h>
#include <linux/spinlock.h>
#include <linux/slab.h>
#include <linux/list.h>

typedef struct list_test_struct {
        int num;
        struct list_head list;
}test;

struct list_head head_list;
rwlock_t list_lock;   //The definition of read and write lock, lock before operation, after operation.

void creat_list(void)
{
        test *s = NULL;
        int  i = 0;
        for (i = 0; i <10; i++) 
        {
                s = (test *)kmalloc(sizeof(test), GFP_ATOMIC);
                if (!s) 
			return ;
                s->num = i;
                write_lock(&list_lock);
                list_add_tail(&(s->list), &head_list);   //Add nodes
                write_unlock(&list_lock);
        }
}

void del_data(void)
{
        test *s;
        struct list_head *p;

        write_lock(&list_lock);
        list_for_each(p, &head_list)          //Traversing the list
        {
                s = list_entry(p, test, list);
                if (s->num == 4) 
                {
                        list_del(p);          //Delete node
                        write_unlock(&list_lock);
                        return ;
                }
        }
        write_unlock(&list_lock);
}

void print_list(void)
{
        test *s;
        struct list_head *p;
        read_lock(&list_lock);
        list_for_each(p, &head_list) 
        {
                s = list_entry(p, test, list);
                printk(KERN_INFO"%d\n", s->num);
        }
        read_unlock(&list_lock);
}

int list_test_init(void)
{
        INIT_LIST_HEAD(&head_list);
        creat_list();
        print_list();
        del_data();
        print_list();
        return 0;
}

void list_test_exit(void)
{
	return;
}

MODULE_LICENSE("GPL");
module_init(list_test_init);
module_exit(list_test_exit);
