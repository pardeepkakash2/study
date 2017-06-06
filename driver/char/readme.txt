http://derekmolloy.ie/writing-a-linux-kernel-module-part-2-a-character-device/

sudo insmod /modules/chardev
mknod /dev/you_device c major_number minor_number
mknod /dev/chardev c  250 0
cat /dev/chardev
echo "dharm" > /dev/chardev
cat /proc/modules | grep char
cat /proc/devices | grep char
sudo strace ./chardev_test
sudo rmmod chardev
find . -name "chardev"
udevadm info -a -p /sys/class/chardev/chardev
