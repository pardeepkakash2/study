
http://www.embeddedlinux.org.cn/essentiallinuxdevicedrivers/final/ch03lev1sec2.html
http://www.roman10.net/2011/07/28/linux-kernel-programminglinked-list/
https://kernelnewbies.org/FAQ/LinkedLists

Function		Purpose
INIT_LIST_HEAD()	Initializes the list head
list_add()		Adds an element after the list head
list_add_tail()		Adds an element to the tail of the list
list_del()		Deletes an element from the list
list_replace()		Replaces an element in the list with another
list_entry()		Loops through all nodes in the list

list_for_each_entry()/
list_for_each_entry_safe()


Simpler list iteration interfaces:
list_empty()		Checks whether there are any elements in the list
list_splice()		Joins one list with another
