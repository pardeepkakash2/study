#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/usb.h>

#define MIN(a,b) (((a) <= (b)) ? (a) : (b))
#define BULK_EP_OUT 0x01
#define BULK_EP_IN 0x82
#define MAX_PKT_SIZE 512

static struct usb_device *device;
static struct usb_class_driver class;
static unsigned char bulk_buf[MAX_PKT_SIZE];

/* open syscall */
static int usbdev_open(struct inode *i, struct file *f)
{
	printk(KERN_ALERT "USBDEV: %s : caller: %pS\n",__func__, __builtin_return_address(0));
	return 0;
}

/* close syscall */
static int usbdev_close(struct inode *i, struct file *f)
{
	return 0;
}

/* read syscall */
static ssize_t usbdev_read(struct file *f, char __user *buf, size_t cnt, loff_t *off)
{
	int retval;
	int read_cnt;

	printk(KERN_ALERT "USBDEV: %s : caller: %pS\n",__func__, __builtin_return_address(0));
	/* Read the data from the bulk endpoint */
	retval = usb_bulk_msg(device, usb_rcvbulkpipe(device, BULK_EP_IN),
			bulk_buf, MAX_PKT_SIZE, &read_cnt, 5000);
	if (retval)
	{
		printk(KERN_ERR "Bulk message returned %d\n", retval);
		return retval;
	}
	if (copy_to_user(buf, bulk_buf, MIN(cnt, read_cnt)))
	{
		return -EFAULT;
	}

	return MIN(cnt, read_cnt);
}

/* write syscall */
static ssize_t usbdev_write(struct file *f, const char __user *buf, size_t cnt,
									loff_t *off)
{
	int retval;
	int wrote_cnt = MIN(cnt, MAX_PKT_SIZE);

	printk(KERN_ALERT "USBDEV: %s : caller: %pS\n",__func__, __builtin_return_address(0));
	if (copy_from_user(bulk_buf, buf, MIN(cnt, MAX_PKT_SIZE)))
	{
		return -EFAULT;
	}

	/* Write the data into the bulk endpoint */
	retval = usb_bulk_msg(device, usb_sndbulkpipe(device, BULK_EP_OUT),
			bulk_buf, MIN(cnt, MAX_PKT_SIZE), &wrote_cnt, 5000);
	if (retval)
	{
		printk(KERN_ERR "Bulk message returned %d\n", retval);
		return retval;
	}

	return wrote_cnt;
}

static struct file_operations fops =
{
	.owner = THIS_MODULE,
	.open = usbdev_open,
	.release = usbdev_close,
	.read = usbdev_read,
	.write = usbdev_write,
};

/* called when a USB device is connected to the computer. */
static int usbdev_probe(struct usb_interface *interface, const struct usb_device_id *id)
{
	int retval;

	printk(KERN_ALERT "USBDEV: %s : caller: %pS\n",__func__, __builtin_return_address(0));
	device = interface_to_usbdev(interface);

	class.name = "usb/usbdev%d";
	class.fops = &fops;
	if ((retval = usb_register_dev(interface, &class)) < 0)
	{
		/* Something prevented us from registering this driver */
		printk(KERN_ERR "Not able to get a minor for this device.");
	}
	else
	{
		printk(KERN_INFO "Minor obtained: %d\n", interface->minor);
	}

	return retval;
}

/* called when unplugging a USB device. */
static void usbdev_disconnect(struct usb_interface *interface)
{
	printk(KERN_ALERT "USBDEV: %s : caller: %pS\n",__func__, __builtin_return_address(0));
	usb_deregister_dev(interface, &class);
}

/* Table of devices that work with this driver */
static struct usb_device_id usbdev_table[] =
{
	{ USB_DEVICE(0x058F, 0x6387) },
	{ USB_DEVICE(0x0BC2, 0xAB24) },
	{} /* Terminating entry */
};
MODULE_DEVICE_TABLE (usb, usbdev_table);

static struct usb_driver usbdev_driver =
{
	.name = "usbdev_driver",
	.probe = usbdev_probe,
	.disconnect = usbdev_disconnect,
	.id_table = usbdev_table,
};

/* called on module loading */
static int __init usbdev_init(void)
{
	int result;

	printk(KERN_ALERT "USBDEV: %s : caller: %pS\n",__func__, __builtin_return_address(0));
	/* Register this driver with the USB subsystem */
	if ((result = usb_register(&usbdev_driver)))
	{
		printk(KERN_ERR "usb_register failed. Error number %d", result);
	}
	return result;
}

/* called on module unloading */
static void __exit usbdev_exit(void)
{
	printk(KERN_ALERT "USBDEV: %s : caller: %pS\n",__func__, __builtin_return_address(0));
	/* Deregister this driver with the USB subsystem */
	usb_deregister(&usbdev_driver);
}

module_init(usbdev_init);
module_exit(usbdev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Dharmender Sharma");
MODULE_DESCRIPTION("USB Device Driver");
