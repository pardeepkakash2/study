opensourceforu.com/2012/02/device-drivers-disk-on-ram-block-drivers/:

commands:
	insmod for.ko
	ls -al /dev/rb
	dd if=/dev/rb of=dor
	dd if=/dev/zero of=/dev/rb1 count=1
	cat > /dev/rb1
	xxd /dev/rb1 | less
	fdisk -l /dev/rb
	mkfs.vfat /dev/rb3
	mount -t vfat /dev/rb3 /mnt/
	df

Please note that all these need to be executed with root privileges:

1. Load the driver dor.ko using insmod. This would create the block device files representing the disk on 512 KiB of RAM, with three primary and three logical partitions.
2. Check out the automatically created block device files (/dev/rb*). /dev/rb is the entire disk, which is 512 KiB in size. rb1, rb2 and rb3 are the primary partitions, 
	with rb2 being the extended partition and containing three logical partitions rb5, rb6 and rb7.
3. Read the entire disk (/dev/rb) using the disk dump utility dd.
4. Zero out the first sector of the disk’s first partition (/dev/rb1), again using dd.
5. Write some text into the disk’s first partition (/dev/rb1) using cat.
6. Display the initial contents of the first partition (/dev/rb1) using the xxd utility. See Figure 2 for xxd output.
7. Display the partition information for the disk using fdisk. See Figure 3 for fdisk output.
8. Quick-format the third primary partition (/dev/rb3) as a vfat filesystem (like your pen drive), using mkfs.vfat (Figure 3).
9. Mount the newly formatted partition using mount, say at /mnt (Figure 3).
10. The disk usage utility df would now show this partition mounted at /mnt (Figure 3). You may go ahead and store files there, but remember that this is a disk on RAM, and so is non-persistent.
11. Unload the driver using rmmod dor after unmounting the partition using umount /mnt. All data on the disk will be lost.

Now let’s learn the rules

We have just played around with the disk on RAM (DOR), but without actually knowing the rules, i.e., the internal details of the game. 
So, let’s dig into the nitty-gritty to decode the rules. Each of the three .c files represent a specific part of the driver; 
ram_device.c and ram_device.h abstract the underlying RAM operations like vmalloc/vfree, memcpy, etc., providing disk operation APIs like init/cleanup, read/write, etc.

partition.c and partition.h provide the functionality to emulate the various partition tables on the DOR. 
Recall the pre-lunch session (i.e., the previous article) to understand the details of partitioning.

The code in this is responsible for the partition information like the number, type, size, etc., that is shown using fdisk. 
The ram_block.c file is the core block driver implementation, exposing the DOR as the block device files (/dev/rb*) to user-space. 
In other words, four of the five files ram_device.* and partition.* form the horizontal layer of the device driver, and ram_block.c forms the vertical (block) layer of the device driver. 
So, let’s understand that in detail.

The block driver basics :

Conceptually, the block drivers are very similar to character drivers, especially with regards to the following:

    Usage of device files
    Major and minor numbers
    Device file operations
    Concept of device registration

So, if you already know character driver implementation, it would be easy to understand block drivers.

However, they are definitely not identical. The key differences are as follows:

    Abstraction for block-oriented versus byte-oriented devices.
    Block drivers are designed to be used by I/O schedulers, for optimal performance. Compare that with character drivers that are to be used by VFS.
    Block drivers are designed to be integrated with the Linux buffer cache mechanism for efficient data access. Character drivers are pass-through drivers, accessing the hardware directly.

And these cause the implementation differences. Let’s analyse the key code snippets from ram_block.c, starting at the driver’s constructor rb_init().

The first step is to register for an 8-bit (block) major number (which implicitly means registering for all 256 8-bit minor numbers associated with it). The function for that is as follows:
int register_blkdev(unsigned int major, const char *name);

Here, major is the major number to be registered, and name is a registration label displayed under the kernel window /proc/devices. 
Interestingly, register_blkdev() tries to allocate and register a freely available major number, when 0 is passed for its first parameter major; 
on success, the allocated major number is returned. The corresponding de-registration function is as follows:

void unregister_blkdev(unsigned int major, const char *name);

Both these are prototyped in <linux/fs.h>.

The second step is to provide the device file operations, through the struct block_device_operations (prototyped in <linux/blkdev.h>) for the registered major number device files.

However, these operations are too few compared to the character device file operations, and mostly insignificant. 
To elaborate, there are no operations even to read and write, which is surprising. But as we already know that block drivers need to integrate with the I/O schedulers, 
the read-write implementation is achieved through something called request queues. So, along with providing the device file operations, the following need to be provided:

    The request queue for queuing the read/write requests
    The spin lock associated with the request queue to protect its concurrent access
    The request function to process the requests in the request queue

Also, there is no separate interface for block device file creations, so the following are also provided:

    The device file name prefix, commonly referred to as disk_name (rb in the dor driver)
    The starting minor number for the device files, commonly referred to as first_minor.

Finally, two block-device-specific things are also provided, namely:

    The maximum number of partitions supported for this block device, by specifying the total minors.
    The underlying device size in units of 512-byte sectors, for the logical block access abstraction.

All these are registered through the struct gendisk using the following function:
void add_disk(struct gendisk *disk);

The corresponding delete function is as follows:
void del_gendisk(struct gendisk *disk);

Prior to add_disk(), the various fields of struct gendisk need to initialised, either directly or using various macros/functions like set_capacity(). 
major, first_minor, fops, queue, disk_name are the minimal fields to be initialised directly. And even before the initialisation of these fields, 
the struct gendisk needs to be allocated, using the function given below:

struct gendisk *alloc_disk(int minors);

Here, minors is the total number of partitions supported for this disk. And the corresponding inverse function would be:
void put_disk(struct gendisk *disk);

All these are prototyped in <linux/genhd.h>.
Request queue and the request function

The request queue also needs to be initialised and set up into the struct gendisk, before add_disk(). The request queue is initialised by calling:
struct request_queue *blk_init_queue(request_fn_proc *, spinlock_t *);

We provide the request-processing function and the initialised concurrency protection spin-lock as parameters. The corresponding queue clean-up function is given below:
void blk_cleanup_queue(struct request_queue *);

The request (processing) function should be defined with the following prototype:
void request_fn(struct request_queue *q);

It should be coded to fetch a request from its parameter q, for instance, by using the following:
struct request *blk_fetch_request(struct request_queue *q);

Then it should either process it, or initiate processing. Whatever it does should be non-blocking, as this request function is called from a non-process context, 
and also after taking the queue’s spin-lock. Moreover, only functions not releasing or taking the queue’s spin-lock should be used within the request function.

A typical example of request processing, as demonstrated by the function rb_request() in ram_block.c is given below:
while ((req = blk_fetch_request(q)) != NULL) /* Fetching a request */
{
        /* Processing the request: the actual data transfer */
        ret = rb_transfer(req); /* Our custom function */
         /* Informing that the request has been processed with return of ret */
        __blk_end_request_all(req, ret);
}
Requests and their processing

Our key function is rb_transfer(), which parses a struct request and accordingly does the actual data transfer. 
The struct request primarily contains the direction of data transfer, the starting sector for the data transfer, the total number of sectors for the data transfer,
and the scatter-gather buffer for the data transfer. The various macros to extract these from the struct request are as follows:

rq_data_dir(req); /* Operation type: 0 - read from device; otherwise - write to device */
blk_req_pos(req); /* Starting sector to process */
blk_req_sectors(req); /* Total sectors to process */
rq_for_each_segment(bv, req, iter) /* Iterator to extract individual buffers */

rq_for_each_segment() is the special one which iterates over the struct request (req) using iter, 
and extracting the individual buffer information into the struct bio_vec (bv: basic input/output vector) on each iteration. 
And then, on each extraction, the appropriate data transfer is done, based on the operation type, invoking one of the following APIs from ram_device.c:

void ramdevice_write(sector_t sector_off, u8 *buffer, unsigned int sectors);
void ramdevice_read(sector_t sector_off, u8 *buffer, unsigned int sectors);

Check out the complete code of rb_transfer() in ram_block.c.


