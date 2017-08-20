
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

