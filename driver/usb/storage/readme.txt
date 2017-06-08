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

cd /sys$ find . -name skel*
./bus/usb/drivers/skeleton
./devices/pci0000:00/0000:00:0b.0/usb1/1-1/1-1:1.0/usbmisc/skel0
./class/usbmisc/skel0
find: `./kernel/debug': Permission denied
dus5cob@KOR1064342VM:/sys$ cd class/usbmisc/

   testing commands:
   sudo rmmod usb_storage
   sudo insmod usb-skeleton.ko
   ls /dev/skel0
   sudo cat /dev/skel0
   sudo dd if=/dev/urandom of=/dev/skel0 bs=1024 count=1
   	1+0 records in
  	 1+0 records out
  	 1024 bytes (1.0 kB) copied, 0.0222637 s, 46.0 kB/s
   sudo rmmod usb_skeleton
   sudo modprobe usb_storage

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

dus5cob@KOR1064342VM:/sys/class/usbmisc/skel0$ dmesg 
[81093.817641] usbcore: registered new interface driver usb-storage
[81108.151931] usbcore: deregistering interface driver usb-storage
[81126.496241] usbcore: registered new interface driver skeleton
[81145.652092] usb 1-1: new high-speed USB device number 4 using ehci-pci
[81146.018037] usb 1-1: New USB device found, idVendor=8564, idProduct=1000
[81146.018041] usb 1-1: New USB device strings: Mfr=1, Product=2, SerialNumber=3
[81146.018043] usb 1-1: Product: Mass Storage Device
[81146.018046] usb 1-1: Manufacturer: JetFlash
[81146.018048] usb 1-1: SerialNumber: 003ZUZDUF12WVF78
[81146.050228] USBDEV: skel_probe : caller: usb_probe_interface+0x1c4/0x2f0
[81146.050363] skeleton 1-1:1.0: USB Skeleton device now attached to USBSkel-0
[81146.070118] usbcore: registered new interface driver usb-storage
[83150.280002] USBDEV: skel_open : caller: usb_open+0x84/0xc0
[83150.280083] USBDEV: skel_read : caller: vfs_read+0x95/0x160
[83150.280088] USBDEV: skel_do_read_io : caller: skel_read+0x16a/0x270 [usb_dev_4_11]
[83152.503063] USBDEV: skel_flush : caller: filp_close+0x2f/0x70
[83152.503070] USBDEV: skel_draw_down : caller: skel_flush+0x5d/0xf0 [usb_dev_4_11]
[83152.503172] USBDEV: skel_read_bulk_callback : caller: __usb_hcd_giveback_urb+0x77/0x100
[83152.503248] USBDEV: skel_release : caller: __fput+0xe4/0x260
[83438.169075] USBDEV: skel_open : caller: usb_open+0x84/0xc0
[83438.169086] USBDEV: skel_flush : caller: filp_close+0x2f/0x70
[83438.169090] USBDEV: skel_draw_down : caller: skel_flush+0x5d/0xf0 [usb_dev_4_11]
[83438.169155] USBDEV: skel_write : caller: vfs_write+0xb4/0x1f0
[83438.169177] USBDEV: skel_flush : caller: filp_close+0x2f/0x70
[83438.169179] USBDEV: skel_draw_down : caller: skel_flush+0x5d/0xf0 [usb_dev_4_11]
[83438.191120] USBDEV: skel_write_bulk_callback : caller: __usb_hcd_giveback_urb+0x77/0x100
[83438.191189] USBDEV: skel_release : caller: __fput+0xe4/0x260
[83492.143856] USBDEV: skel_open : caller: usb_open+0x84/0xc0
[83492.143872] USBDEV: skel_read : caller: vfs_read+0x95/0x160
[83492.143876] USBDEV: skel_do_read_io : caller: skel_read+0x16a/0x270 [usb_dev_4_11]
[83493.936628] USBDEV: skel_flush : caller: filp_close+0x2f/0x70
[83493.936635] USBDEV: skel_draw_down : caller: skel_flush+0x5d/0xf0 [usb_dev_4_11]
[83493.936755] USBDEV: skel_read_bulk_callback : caller: __usb_hcd_giveback_urb+0x77/0x100
[83493.936830] USBDEV: skel_release : caller: __fput+0xe4/0x260
[83525.321009] usbcore: deregistering interface driver skeleton
[83525.321025] USBDEV: skel_disconnect : caller: usb_unbind_interface+0x64/0x1c0
[83525.321155] USBDEV: skel_delete : caller: skel_disconnect+0xb5/0xc0 [usb_dev_4_11]
[83525.321160] skeleton 1-1:1.0: USB Skeleton #0 now disconnected


