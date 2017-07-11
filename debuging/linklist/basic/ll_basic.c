#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/list.h>
#include <linux/slab.h>

struct  person {
        int     	id;
	char		name[30];
	unsigned int	weight;
	unsigned char	gender;
        struct 		list_head list;	/* kernel's list structure */
};
/* We now need a variable to represent the start (head) of our list, 
 * initialize it as an empty linked list to start off with
*/
//LIST_HEAD(obj_context);

struct person personlist;

static int __init my_init(void)
{
	struct person *anewperson, *aperson;	
	unsigned int i;
	
	printk(KERN_INFO "initialize kernel module\n");
	
	INIT_LIST_HEAD(&personlist.list);    //or LIST_HEAD(mylist);

	/* adding elements to mylist */
	for (i = 0; i < 5; i++) {
        	anewperson = kmalloc(sizeof(struct person), GFP_KERNEL);
        	anewperson->id = i;

		#if 0
		/** list_add - add a new entry
 		* @new: new entry to be added
 		* @head: list head to add it after
 		* Insert a new entry after the specified head.This is good for implementing stacks.
 		* static inline void list_add(struct list_head *new, struct list_head *head)
		*/
        	list_add(&obj->list, &obj_context);
		#endif
		strcpy(anewperson->name, "roman10");
		anewperson->weight = 130*i;
		anewperson->gender = 1;
		INIT_LIST_HEAD(&anewperson->list);

		/* add the new node to mylist */
		list_add_tail(&(anewperson->list), &(personlist.list));
	}
	/**
	 * list_for_each_entry  -       iterate over list of given type
	 * #define list_for_each_entry(pos, head, member)
	 * @pos:        the type * to use as a loop cursor.
	 * @head:       the head for your list.
	 * @member:     the name of the list_struct within the struct.
	 */
	list_for_each_entry(aperson, &personlist.list, list) {
		//access the member from aperson
		printk(KERN_INFO "Person: %s; weight: %d; gender: %s; id: %d\n", aperson->name, aperson->weight, aperson->gender==0?"Female":"Male", aperson->id);
	}

        return (0);
}

static void __exit my_fini(void)
{
	struct person *aperson, *tmp;

	printk(KERN_INFO "kernel module unloaded\n");
	printk(KERN_INFO "deleting the list using list_for_each_entry_safe()\n");

	/**
 	* list_for_each_entry_safe - iterate over list of given type safe against removal of list entry
 	* @pos:        the type * to use as a loop cursor.
 	* @n:          another type * to use as temporary storage
 	* @head:       the head for your list.
 	* @member:     the name of the list_struct within the struct.
 	* #define list_for_each_entry_safe(pos, n, head, member)
	*/
	list_for_each_entry_safe(aperson, tmp, &personlist.list, list) {
		printk(KERN_INFO "freeing node %s\nn", aperson->name);
		list_del(&aperson->list);
		kfree(aperson);
	}	
	#if 0
        struct  list_head *pos, *q;
	/**
	 * list_for_each_safe - iterate over a list safe against removal of list entry
	 * @pos:        the &struct list_head to use as a loop cursor.
	 * @n:          another &struct list_head to use as temporary storage
	 * @head:       the head for your list.
	 * #define list_for_each_safe(pos, n, head)
	 */
        list_for_each_safe(pos, q, &obj_context) {
                struct object_list *obj = NULL;
		/**
		 * list_entry - get the struct for this entry
		 * @ptr:        the &struct list_head pointer.
		 * @type:       the type of the struct this is embedded in.
		 * @member:     the name of the list_struct within the struct.
		 * #define list_entry(ptr, type, member) container_of(ptr, type, member)
		 */
                obj = list_entry(pos, struct object_list, list);
		/**
		 * list_del - deletes entry from list.
		 * @entry: the element to delete from the list.
		*/
                list_del(pos);
                kfree(obj);
        }
	#endif

        return;
}

module_init(my_init);
module_exit(my_fini);

MODULE_DESCRIPTION("Sample Code");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Dharmender Sharma");
