https://kernel.readthedocs.io/en/sphinx-samples/writing_usb_driver.html#linux-usb-basics
http://matthias.vallentin.net/blog/2007/04/writing-a-linux-kernel-driver-for-an-unknown-usb-device/

USB class devices (standard types of devices like keyboards, mice, modems, printers and speakers) 
and an ever-growing number of vendor-specific devices 
(such as USB to serial converters, digital cameras, Ethernet devices and MP3 players).

USB:
	simple driver for LED, SSD, LCD
	USB Mass Storage (MMC) driver
	USB to Serial converter
	Various Serial character drivers
	Complex matrix keypad driver using interrupts and synchronization
	USB Input drivers
	USB audio

steps:

    Build the driver (usbdev_driver.ko file) by running make.
   
    Load the driver using insmod chardev_driver.ko.

    Plug-in the pen drive (after making sure that usb-storage driver is not already loaded).

    Check for the dynamic creation of /dev/usbdev0. (0 being the minor number obtained – check dmesg logs for the value on your system)

    Possibly try some write/read on /dev/usbdev0. (Though you may mostly get connection timeout and/or
    broken pipe errors because of non-conformant SCSI commands)

    Unplug-out the pen drive and look out for gone /dev/usbdev0.

    Unload the driver using rmmod usbdev_driver.

[ 8608.040085] usb 3-1: new SuperSpeed USB device number 2 using xhci_hcd
[ 8608.056843] usb 3-1: New USB device found, idVendor=0bc2, idProduct=ab24
[ 8608.056850] usb 3-1: New USB device strings: Mfr=2, Product=3, SerialNumber=1
[ 8608.056853] usb 3-1: Product: BUP Slim BK
[ 8608.056856] usb 3-1: Manufacturer: Seagate
[ 8608.056859] usb 3-1: SerialNumber: NA7N0FVC
[ 8608.647609] usbcore: registered new interface driver usb-storage

   testing commands:
   # insmod usb-skeleton.ko
   # ls /dev/skel0
   /dev/skel0
   # dd if=/dev/urandom of=/dev/skel0 bs=1024 count=1
   dd closing output file `/dev/ask0': Input/Output error

Notes:

    Make sure that you replace the vendor id & device id in the above code examples by the ones of your usbdev drive. 
    Also, make sure that the endpoint numbers used in the above code examples match the endpoint numbers of your pen drive. 
    Otherwise, you may get an error like “… bulk message returned error 22 – Invalid argument …”, while reading from pen device.

    Also, make sure that the driver from the previous article is unloaded, i.e. pen_info is not loaded. Otherwise, it may give 
    an error message “insmod: error inserting ‘usbdev_driver.ko’: -1 Device or resource busy”, while doing insmod usbdev_driver.ko.

    One may wonder, as how does the usb-storage get autoloaded. The answer lies in the module autoload rules written down in the file
    /lib/modules/<kernel_version>/modules.usbmap. If you are an expert, you may comment out the corresponding line,
    for it to not get autoloaded. And uncomment it back, once you are done with your experiments.

    In latest distros, you may not find the detailed description of the USB devices using cat /proc/bus/usb/devices, 
    as the /proc/bus/usb/ itself has been deprecated. You can find the same detailed info using cat /sys/kernel/debug/usb/devices 
    – though you may need root permissions for the same. Also, if you do not see any file under /sys/kernel/debug (even as root), 
    then you may have to first mount the debug filesystem, as follows: mount -t debugfs none /sys/kernel/debug.

sudo modprobe -w -r usb_storage; sudo modprobe usb_storage
echo "blacklist usb-storage" | sudo tee -a /etc/modprobe.d/blacklist.conf
rmmod --help
