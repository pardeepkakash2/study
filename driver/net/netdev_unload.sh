#!/bin/sh

/sbin/ifconfig netdev0 down
/sbin/ifconfig netdev1 down
/sbin/rmmod netdev
