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

void create_stack(void) {
        test *tmp = NULL;
        int  i = 1;
        for (i = 1; i <=10; i++) 
        {
                tmp = (test *)kzalloc(sizeof(test), GFP_ATOMIC);
                if (!tmp) 
			return ;
                tmp->num = i;
                write_lock(&list_lock);
		/*This is useful for implementing queues.
		void list_add_tail(struct list_head *new, struct list_head *head);
		This is good for implementing stacks.
		void list_add(struct list_head *new, struct list_head *head);
		*/
                list_add(&(tmp->list), &head_list);   //Add nodes
                write_unlock(&list_lock);
        }
	printk("created the stack having nodes: %d using kzalloc->list_add_tail()\n", i-1);
}

void stack_data(void)
{
        test *tmp;
        struct list_head *pos, *n;

	/*int list_empty(const struct list_head *head) to tests whether a list is empty*/
	if(!list_empty(&head_list)) {
		printk("list is not empty so go for deletion of node\n");
		#if 0
	        write_lock(&list_lock);
		/*traverse the list*/
	        list_for_each(pos, &head_list) {
			/*
			* #define list_entry(ptr, type, member) \
		         * list_entry - get the struct for this entry
			 * @ptr:	the &struct list_head pointer.
			 * @type:	the type of the struct this is embedded in.
			 * @member:	the name of the list_struct within the struct.
			* container_of(ptr, type, member)
			* #define container_of(ptr, type, member) ({ \
	        	* const typeof( ((type *)0)->member ) *__mptr = (ptr); \
		        * (type *)( (char *)__mptr - offsetof(type,member) );})
			*/
        	        s = list_entry(pos, test, list);
        	        if (tmp->num == 4) {
				/*void list_del(struct list_head *entry);*/
        	                list_del(pos);          //Delete node
				printk("node : %d deleted successfully\n", tmp->num);
        	                write_unlock(&list_lock);
        	                return ;
        	        }
		}
		#endif

		/* now let's be good and free the kool_list items. since we will be removing items
		 * off the list using list_del() we need to use a safer version of the list_for_each() 
		 * macro aptly named list_for_each_safe(). Note that you MUST use this macro if the loop 
		 * involves deletions of items (or moving items from one list to another).
		 * #define	 list_for_each_safe(pos, n, head)..for loop.
		 * @pos:	the &struct list_head to use as a loop cursor.
 		 * @n:		another &struct list_head to use as temporary storage
		 * @head:	the head for your list.

		 */
	        write_lock(&list_lock);
		printk("deleting the node having data==5 using list_for_each_safe()\n");
		list_for_each_safe(pos, n, &head_list) {
			tmp= list_entry(pos, test, list);
        	        if (tmp->num == 5) 
        	        {
        	                list_del(pos);          //Delete node
				printk("node : %d deleted successfully\n", tmp->num);
        	                write_unlock(&list_lock);
        	                return ;
        	        }
		}
        	write_unlock(&list_lock);
	}

}

void print_stack(void)
{
        test *tmp;
        struct list_head *pos;
        read_lock(&list_lock);
	
	#if 0
	printk("traversing the list using list_for_each()\n");
        list_for_each(pos, &head_list) {
                tmp = list_entry(pos, test, list);
                printk(KERN_INFO"%d\n", tmp->num);
        }
	#endif

	/* since this is a circularly linked list. you can traverse the list in reverse order
	 * as well. all you need to do is replace 'list_for_each' with 'list_for_each_prev'
	 * everything else remain the same!
	 *
	 * Also you can traverse the list using list_for_each_entry() to iterate over a given
	 * type of entries. For example:
	 */
	printk("traversing the stack using list_for_each_entry()\n");
	list_for_each_entry(tmp, &head_list, list)
                printk(KERN_INFO"%d\n", tmp->num);

        read_unlock(&list_lock);
}

int list_test_init(void)
{
        INIT_LIST_HEAD(&head_list);
        create_stack();
        print_stack();
        stack_data();
        print_stack();
        return 0;
}

void list_test_exit(void)
{
	return;
}

MODULE_LICENSE("GPL");
module_init(list_test_init);
module_exit(list_test_exit);
