#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/platform_device.h>
#include <linux/device.h>
#include <linux/delay.h>
#include <linux/slab.h>

/* Data structure for the platform data of "my device" */
struct my_device_platform_data {
	int reset_gpio;
	int power_on_gpio;
	void (*power_on)(struct my_device_platform_data* ppdata);
	void (*power_off)(struct my_device_platform_data* ppdata);
	void (*reset)(struct my_device_platform_data* pdata);
};

/* Power on the device. */
static void my_device_power_on(struct my_device_platform_data* pdata) {
	printk(KERN_INFO "SYSFS: %s\n", __func__);
	printk(KERN_INFO "reset_gpio: %d power_on_gpio: %d\n", pdata->reset_gpio, pdata->power_on_gpio);
}

/* Power Off the device. */
static void my_device_power_off(struct my_device_platform_data* pdata) {
	printk(KERN_INFO "SYSFS: %s\n", __func__);
	printk(KERN_INFO "reset_gpio: %d power_on_gpio: %d\n", pdata->reset_gpio, pdata->power_on_gpio);
}

/* Reset the device. */
static void my_device_reset(struct my_device_platform_data* pdata) {
	printk(KERN_INFO "SYSFS: %s\n", __func__);
	printk(KERN_INFO "reset_gpio: %d power_on_gpio: %d\n", pdata->reset_gpio, pdata->power_on_gpio);
}

/* "my device" platform data */
static struct my_device_platform_data my_device_pdata = {
	.reset_gpio	= 100,
	.power_on_gpio	= 101,
	.power_on	= my_device_power_on,
	.power_off	= my_device_power_off,
	.reset		= my_device_reset
};

/* Device driver data structure. */
struct my_driver_data {
	int data1;
	int data2;
};

/* Suspend the device. */
static int my_device_pm_suspend(struct device *dev)
{
	struct my_driver_data* driver_data = dev_get_drvdata(dev);

	printk(KERN_INFO "SYSFS: %s\n", __func__);

	
	/* Suspend the device here*/

	return 0;
}

/* Resume the device. */
static int my_device_pm_resume(struct device *dev)
{
	struct my_driver_data* driver_data = dev_get_drvdata(dev);

	printk(KERN_INFO "SYSFS: %s\n", __func__);
	
	/* Resume the device here*/
	return 0;
}

/* Probe driver function called by the OS when the device with the name
 * "my-platform-device" is found in the system. */
static int __init drivertest_probe(struct platform_device *pdev) {

	struct my_device_platform_data *my_device_pdata;
	struct my_driver_data* driver_data;

	printk(KERN_INFO "SYSFS: %s\n", __func__);
	
	my_device_pdata = dev_get_platdata(&pdev->dev);

	/* Power on the device. */
	if (my_device_pdata->power_on) {
		my_device_pdata->power_on(my_device_pdata);
	}

	/* wait for some time before we do the reset */
	mdelay(5);

	/* Reset the device. */
	if (my_device_pdata->reset) {
		my_device_pdata->reset(my_device_pdata);
	}

	/* Create the driver data here */
	driver_data = kzalloc(sizeof(struct my_driver_data), GFP_KERNEL);
	if(!driver_data)
		return -ENOMEM;
	driver_data->data1 = 25;
	driver_data->data2 = 30;
	/* Set this driver data in platform device structure */
	platform_set_drvdata(pdev, driver_data);
	return 0;
}

static int drivertest_remove(struct platform_device *pdev) {
	
	struct my_device_platform_data *my_device_pdata = dev_get_platdata(&pdev->dev);;
	struct my_driver_data *driver_data = platform_get_drvdata(pdev);

	printk(KERN_INFO "SYSFS: %s\n", __func__);
	printk(KERN_INFO "SYSFS: pdata : %d : %d\n", driver_data->data1, driver_data->data2 );

	/* do something with the driver */

	// Power Off the device
	if (my_device_pdata->power_off) {
		my_device_pdata->power_off(my_device_pdata);
	}

	return 0;
}

static void drivertest_device_release(struct device *dev) {
	printk(KERN_ALERT "device release\n");
}

static const struct dev_pm_ops my_device_pm_ops = {
        .suspend        = my_device_pm_suspend,
        .resume = my_device_pm_resume,
};

static struct platform_driver drivertest_driver = {
	.driver = {
		.name = "drivertest",
		.owner = THIS_MODULE,
		.pm	= &my_device_pm_ops,
	},
	.probe = drivertest_probe,
	.remove = drivertest_remove,
};

static struct platform_device my_device = {
	.name		= "drivertest",
	.id		= 0,
	.dev = {
		.release	= drivertest_device_release,
		.platform_data	= &my_device_pdata
	},
};

static int __init drivertest_init(void) {

	int ret = 0;

	printk(KERN_INFO "SYSFS: %s: %pS\n", __func__, __builtin_return_address(0));

	ret = platform_device_register(&my_device);
	if (ret) {
		printk(KERN_INFO "SYSFS: platform_device_register failed: %d\n", ret);
		return ret;
	}

	ret = platform_driver_register(&drivertest_driver);
	if (ret) {
		printk(KERN_INFO "SYSFS: platform_driver_register failed: %d\n", ret);
		return ret;
	}
	return 0;
}

static void __exit drivertest_exit(void) {
	
	printk(KERN_INFO "SYSFS: %s: %pS\n", __func__, __builtin_return_address(0));
	platform_driver_unregister(&drivertest_driver);
	platform_device_unregister(&my_device);
}

module_init(drivertest_init);
module_exit(drivertest_exit);
MODULE_LICENSE("GPL");
