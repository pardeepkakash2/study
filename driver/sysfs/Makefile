#obj−m += sysfs.o
#obj−m += startstop.o
#startstop−objs := start.o stop.o

obj-m += sysfs.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
