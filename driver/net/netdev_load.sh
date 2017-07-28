#!/bin/sh

export PATH=/sbin:/bin

# Use a pathname, as new modutils don't look in the current dir by default
insmod modules/netdev.ko
ifconfig netdev0 172.17.0.22 up
ifconfig netdev1 172.17.0.23 up
