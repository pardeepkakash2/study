sudo insmod /modules/chardev
mknod /dev/chardev c  250 0
cat /dev/chardev
echo "dharm" > /dev/chardev
cat /proc/modules | grep char
cat /proc/devices | grep char
sudo ./char_test
sudo rmmod chardev
