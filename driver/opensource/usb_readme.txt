http://opensourceforu.com/2011/11/usb-drivers-in-linux-2/

USB endpoints and their types

Depending on the type and attributes of information to be transferred, a USB device may have one or more endpoints, each belonging to one of the following four categories:

    Control — to transfer control information. Examples include resetting the device, querying information about the device, etc. 
		All USB devices always have the default control endpoint point as zero.
    Interrupt — for small and fast data transfers, typically of up to 8 bytes. Examples include data transfer for serial ports, human interface devices (HIDs) like keyboards, mouse, etc.
    Bulk — for big but comparatively slower data transfers. A typical example is data transfers for mass-storage devices.
    Isochronous — for big data transfers with a bandwidth guarantee, though data integrity may not be guaranteed. 
		Typical practical usage examples include transfers of time-sensitive data like audio, video, etc.

Additionally, all but control endpoints could be “in” or “out”, indicating the direction of data transfer; “in” indicates data flow from the USB device to the host machine, and “out”, the other way.

Technically, an endpoint is identified using an 8-bit number, the most significant bit (MSB) of which indicates the direction — 0 means “out”, and 1 means “in”. 
Control endpoints are bi-directional, and the MSB is ignored.

pendrive info :

    Build the driver (pen_info.ko file) by running make.
    Load the driver using insmod pen_info.ko.
    Plug in the pen drive (after making sure that the usb-storage driver is not already loaded).
    Unplug the pen drive.
    Check the output of dmesg for the logs.
    Unload the driver using rmmod pen_info.

pedriver data tranfer:

    Build the driver (pen_driver.ko) by running make.
    Load the driver using insmod pen_driver.ko.
    Plug in the pen drive (after making sure that the usb-storage driver is not already loaded).
    Check for the dynamic creation of /dev/pen0 (0 being the minor number obtained — check dmesg logs for the value on your system).
    Possibly try some write/read on /dev/pen0 (you most likely will get a connection timeout and/or broken pipe errors, because of non-conforming SCSI commands).
    Unplug the pen drive and look for /dev/pen0 to be gone.
    Unload the driver using rmmod pen_driver.

