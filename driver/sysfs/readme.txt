https://stackoverflow.com/questions/37237835/how-to-attach-file-operations-to-sysfs-attribute-in-platform-driver
http://opensourceforu.com/2015/05/talking-to-the-kernel-through-sysfs/
https://stackoverflow.com/questions/16245100/how-to-create-a-simple-sysfs-class-attribute-in-linux-kernel-v3-2
https://jeshwanth.wordpress.com/2012/06/21/my-first-kernel-module-with-sysfs-class-attribute/
http://kroah.com/log/blog/2013/06/26/how-to-create-a-sysfs-file-correctly/
https://coherentmusings.wordpress.com/2014/02/19/adding-sysfs-support-to-a-driver/

Targets like --- modules / modules_install
Options like --- -C $KDIR / M=$PWD

Command Syntax ---

$ make -C <path_to_kernel_src> M=$PWD
$ make -C /lib/modules/uname -r/build M=$PWD
$ make -C /lib/modules/uname -r/build M=$PWD modules_install

Loadable module goals --- obj-m

clean your kernel source tree.
make clean
make dist clean
make menuconfig
make modules_prepare

if your module has dependencies to other modules, then:
make modules to build modules
make modules_install to install them
modprobe temp.ko to load temp module and it's dependencies

if your module is simple and has no dependencies, then:
make modules to build modules
cd /path/to/module
insmod temp.ko

testing module:

sudo insmod sysfs.ko
sudo -i
cd /sys/kernel/sysfs_kernel_kobject/
echo 12345 > sysfs_test
cat sysfs_test
dd if=sysfs_test bs=1 count=2 skip=1 status=none
dd if=sysfs_test bs=1 count=3 skip=1 status=none

platfrom driver and devices:
https://www.codeproject.com/Tips/1080177/Linux-Platform-Device-Driver
https://coherentmusings.wordpress.com/2013/12/13/how-to-write-a-platform-devicedriver-adc-driver-using-wm97xx-codec/
https://www.kernel.org/doc/Documentation/driver-model/platform.txt
https://github.com/jeyaramvrp/kernel-module-programming/blob/master/sample-platform-driver/preparedrv.c
http://www.cs.columbia.edu/~sedwards/classes/2014/4840/device-drivers.pdf
