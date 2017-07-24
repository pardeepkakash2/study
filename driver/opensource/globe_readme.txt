#include <linux/moduleparam.h>

EXPORT_SYMBOL(sym)
EXPORT_SYMBOL_GPL(sym)
EXPORT_SYMBOL_GPL_FUTURE(sym)
module_param(name, type, perm)	

cat /proc/kallsyms


steps :


    Building the driver (module_param.ko file) using the usual driver Makefile
    Loading the driver using insmod (with and without parameters)
    Various experiments through the corresponding /sys entries
    And finally, unloading the driver using rmmod.

Note the following:

    Initial value (3) of cfg_value becomes its default value when insmod is done without any parameters.
    Permission 0764 gives rwx to the user, rw- to the group, and r-- for the others on the file cfg_value under the parameters of module_param under /sys/module/.

Check for yourself:

    The output of dmesg/tail on every insmod and rmmod, for the printk outputs.
    Try writing into the /sys/module/module_param/parameters/cfg_value file as a normal (non-root) user.

commands
	sudo insmod module_param.ko
	ls -l /sys/module/module_param
	ls -l /sys/module/module_param/parameters
	cat /sys/module/module_param/parameters/cfg_value
	udo rmmod module_param

	
	sudo insmod module_param.ko cfg_value=-10
	cat /sys/module/module_param/parameters/cfg_value
	ls -l /sys/module/module_param/parameters/cfg_value
	cat /sys/module/module_param/parameters/cfg_value
	cd /sys/module/module_param/parameters/
	echo $(('cat cfg_value' -9)) > cfg_value

	
