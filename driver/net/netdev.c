#include <linux/module.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

#include <linux/sched.h>
#include <linux/kernel.h> 	/* printk() */
#include <linux/slab.h> 	/* kmalloc() */
#include <linux/errno.h>  	/* error codes */
#include <linux/types.h>  	/* size_t */
#include <linux/interrupt.h> 	/* mark_bh */

#include <linux/in.h>
#include <linux/netdevice.h>   	/* struct device, and other headers */
#include <linux/etherdevice.h> 	/* eth_type_trans */
#include <linux/ip.h>          	/* struct iphdr */
#include <linux/tcp.h>         	/* struct tcphdr */
#include <linux/skbuff.h>
#include <linux/in6.h>
#include <asm/checksum.h>


#define DEVINC_DEVICE_NUM	2

/* Do we run in NAPI mode? */
static int use_napi;
module_param(use_napi, int, 0);

/* This structure is private to each device. It is used to pass
 * packets in and out, so there is place for a packet
 */
struct netdev_priv {
	unsigned int status;
	struct sk_buff *skb;
	spinlock_t lock;	/* spinlock to protect netdev data */
	struct net_device *dev;
	struct napi_struct napi;
};

/* The devices */
static struct net_device *netdev_devs[DEVINC_DEVICE_NUM];
static void (*netdev_interrupt)(struct net_device *);

/* Open and close */
static int netdev_open(struct net_device *dev)
{
	printk("netdev: %s\n", __func__);
	netif_start_queue(dev);
	return 0;
}

static int netdev_release(struct net_device *dev)
{
	printk("netdev: %s\n", __func__);
	netif_stop_queue(dev); /* can't transmit any more */
	return 0;
}

/* Configuration changes (passed on by ifconfig) */
static int netdev_config(struct net_device *dev, struct ifmap *map)
{
	printk("netdev: %s\n", __func__);
	if (dev->flags & IFF_UP) /* can't act on a running interface */
		return -EBUSY;

	/* Don't allow changing the I/O address */
	if (map->base_addr != dev->base_addr) {
		netdev_warn(dev, "devinc: Can't change I/O address\n");
		return -EOPNOTSUPP;
	}

	/* Allow changing the IRQ */
	if (map->irq != dev->irq)
		dev->irq = map->irq;

	/* ignore other fields */
	return 0;
}

/* The poll implementation. */
static int netdev_poll(struct napi_struct *napi, int budget)
{
	printk("netdev: %s\n", __func__);
	napi_complete(napi);
	return 0;
}

/* The typical interrupt entry point */
static void netdev_regular_interrupt(struct net_device *dev)
{

	printk("netdev: %s\n", __func__);
	return;	
}

/* A NAPI interrupt handler. */
static void netdev_napi_interrupt(struct net_device *dev)
{
	struct netdev_priv *priv = netdev_priv(dev);
	
	printk("netdev: %s\n", __func__);	
	/* Lock the device */
	spin_lock(&priv->lock);
	
	napi_schedule(&priv->napi);
	
	/* Unlock the device and we are done */
	spin_unlock(&priv->lock);
	return;
}

/* Transmit a packet (called by the kernel) */
static int netdev_tx(struct sk_buff *skb, struct net_device *dev)
{
	printk("netdev: %s\n", __func__);	
	return 0; /* Our simple device can not fail */
}

/*
 * Ioctl commands 
 */
int netdev_ioctl(struct net_device *dev, struct ifreq *rq, int cmd)
{
	printk("netdev: %s\n", __func__);	
	return 0;
}

static const struct net_device_ops netdev_netdev_ops = {
	.ndo_open            = netdev_open,
	.ndo_stop            = netdev_release,
	.ndo_start_xmit      = netdev_tx,
	.ndo_set_config      = netdev_config,
	.ndo_do_ioctl 	     = netdev_ioctl,
	.ndo_change_mtu      = eth_change_mtu,
};

/* The init function (sometimes called probe).
 * It is invoked by register_netdev()
 */
static void netdev_init(struct net_device *dev)
{
	/**
	 * initialize the priv field. This encloses the statistics
	 * and a few private fields.
	 */
	struct netdev_priv *priv = netdev_priv(dev);

	printk("netdev: %s\n", __func__);	
	/**
	 * Then, assign other fields in dev, some
	 * hand assignments
	 */
	dev->netdev_ops = &netdev_netdev_ops;
	/* keep the default flags, just add NOARP */
	dev->flags           |= IFF_NOARP;
	dev->features 	     |= NETIF_F_HW_CSUM;

	memset(priv, 0, sizeof(*priv));
	if (use_napi)
		netif_napi_add(dev, &priv->napi, netdev_poll, 2);

	spin_lock_init(&priv->lock);
}

/* Finally, the module stuff */
static void netdev_cleanup(void)
{
	int i;

	printk("netdev: %s\n", __func__);	
	for (i = 0; i < DEVINC_DEVICE_NUM; i++) {
		if (netdev_devs[i]) {
			if (netdev_devs[i]->ifindex)
				unregister_netdev(netdev_devs[i]);

			free_netdev(netdev_devs[i]);
		}
	}
}

static int netdev_init_module(void)
{
	int i, ret;

	netdev_interrupt = use_napi ?
		netdev_napi_interrupt : netdev_regular_interrupt;

	printk("netdev: %s\n", __func__);	
	for (i = 0; i < DEVINC_DEVICE_NUM; i++) {
		/* Allocate the devices */
		netdev_devs[i] = alloc_netdev(sizeof(struct netdev_priv),
					      "netdev%d", netdev_init);
		if (!netdev_devs[i]) {
			ret = -ENOMEM;
			break;
		}

		ret = register_netdev(netdev_devs[i]);
		if (ret) {
			netdev_err(netdev_devs[i],
				   "netdev: error %i registering device \"%s\"\n",
				    ret, netdev_devs[i]->name);
			/* Make forcibly ifindex zero */
			if (netdev_devs[i]->ifindex)
				netdev_devs[i]->ifindex = 0;
			break;
		}
	}

	if (ret)
		netdev_cleanup();
	return ret;
}

module_init(netdev_init_module);
module_exit(netdev_cleanup);

MODULE_AUTHOR("Dharmender sharma");
MODULE_LICENSE("GPL");
