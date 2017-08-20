/*
 *  Copyright (C) Nagaraj Krishnamurthy
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
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
static void my_device_power_on(struct my_device_platform_data* pdata)
{
	printk(KERN_ALERT " %s\n", __FUNCTION__);
}

/* Power Off the device. */
static void my_device_power_off(struct my_device_platform_data* pdata)
{
	printk(KERN_ALERT " %s\n", __FUNCTION__);
}

/* Reset the device. */
static void my_device_reset(struct my_device_platform_data* pdata)
{
	printk(KERN_ALERT " %s\n", __FUNCTION__);
}

/* "my device" platform data */
static struct my_device_platform_data my_device_pdata = {
	.reset_gpio         = 100,
	.power_on_gpio      = 101,
	.power_on		= my_device_power_on,
	.power_off		= my_device_power_off,
	.reset		= my_device_reset
};


static struct platform_device my_device = {
	.name		= "my-platform-device",
	.id			= PLATFORM_DEVID_NONE,
	.dev.platform_data	= &my_device_pdata
};

void __init my_device_init_pdata(void)
{
	printk(KERN_ALERT " %s\n", __FUNCTION__);

	/* Register "my-platform-device" with the OS. */
	platform_device_register(&my_device);
}

/***********************************************************************
 * Platform device driver code here......
 ***********************************************************************/

/* Device driver data structure. */
struct my_driver_data {
	int data1;
	int data2;
};

/* Suspend the device. */
static int my_device_pm_suspend(struct device *dev)
{
	struct my_driver_data* driver_data = dev_get_drvdata(dev);

	printk(KERN_INFO "SYSFS: %s: %pS\n", __func__, __builtin_return_address(0));
	printk(KERN_INFO "SYSFS: pdata : %d : %d\n", driver_data->data1, driver_data->data2 );

	
	/* Suspend the device here*/

	return 0;
}

/* Resume the device. */
static int my_device_pm_resume(struct device *dev)
{
	struct my_driver_data* driver_data = dev_get_drvdata(dev);

	printk(KERN_INFO "SYSFS: %s: %pS\n", __func__, __builtin_return_address(0));
	printk(KERN_INFO "SYSFS: pdata : %d : %d\n", driver_data->data1, driver_data->data2 );
	
	/* Resume the device here*/
	return 0;
}



/* Probe driver function called by the OS when the device with the name
 * "my-platform-device" is found in the system. */
static int my_driver_probe(struct platform_device *pdev)
{
	struct my_device_platform_data *my_device_pdata;
	struct my_driver_data* driver_data;

	printk(KERN_INFO "SYSFS: %s: %pS\n", __func__, __builtin_return_address(0));

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

static int my_driver_remove(struct platform_device *pdev)
{
	struct my_device_platform_data *my_device_pdata = dev_get_platdata(&pdev->dev);;
	//struct my_driver_data *driver_data = platform_get_drvdata(pdev);

	printk(KERN_INFO "SYSFS: %s: %pS\n", __func__, __builtin_return_address(0));

	/* do something with the driver */

	// Power Off the device
	if (my_device_pdata->power_off) {
		my_device_pdata->power_off(my_device_pdata);
	}

	return 0;
}


static const struct dev_pm_ops my_device_pm_ops = {
	.suspend	= my_device_pm_suspend,
	.resume	= my_device_pm_resume,
};

static struct platform_driver my_driver = {
	.probe      = my_driver_probe,
	.remove     = my_driver_remove,
	.driver     = {
		.name	= "my-platform-device",
		.owner	= THIS_MODULE,
		.pm	= &my_device_pm_ops,
		},
};

/* Entry point for loading this module */
static int __init my_driver_init_module(void)
{
	int ret;
	printk(KERN_INFO "SYSFS: %s: %pS\n", __func__, __builtin_return_address(0));
    
	/* Add the device to the platform.
	This has to be done by the platform specific code.
	*/
	my_device_init_pdata();

	/* We will use this when we know for sure that this device is not
	hot-pluggable and is sure to be present in the system.
	*/
	ret = platform_driver_probe(&my_driver, my_driver_probe);

	/* We will use this when we are not sure if this device is present in the
	system. The driver probe will be called by the OS if the device is 
	present in the system.
	*/
	//return platform_driver_register(&ineda_femac_driver);
	return ret;
}

/* entry point for unloading the module */
static void __exit my_driver_cleanup_module(void)
{
	printk(KERN_INFO "SYSFS: %s: %pS\n", __func__, __builtin_return_address(0));
	platform_driver_unregister(&my_driver);
}

module_init(my_driver_init_module);
module_exit(my_driver_cleanup_module);

