http://opensourceforu.com/2011/06/generic-hardware-access-in-linux/

video ram driver :

#include <asm/io.h>
unsigned int ioread8(void *virt_addr);
unsigned int ioread16(void *virt_addr);
unsigned int ioread32(void *virt_addr);
unsigned int iowrite8(u8 value, void *virt_addr);
unsigned int iowrite16(u16 value, void *virt_addr);
unsigned int iowrite32(u32 value, void *virt_addr);

sudo apt-get install hardinfo
sudo apt-get install sysinfo
lshw

video RAM address : cat /proc/iomem or vmstat -s

steps:

1. Build the “vram” driver (video_ram.ko file) by running make with a changed Makefile.
2. Load the driver using insmod video_ram.ko.
3. Write into /dev/vram, say, using echo -n "0123456789" > /dev/vram.
4. Read the /dev/vram contents using od -t x1 -v /dev/vram | less. (The usual cat /dev/vram can also be used, but that would give all the binary content. od -t x1 shows it as hexadecimal. 
	For more details, run man od.)
5. Unload the driver using rmmod video_ram.

lspci :  It is a utility for displaying information about all PCI buses in the system and all devices connected to them.

00:00.0 Host bridge: Intel Corporation 440FX - 82441FX PMC [Natoma] (rev 02)
00:01.0 ISA bridge: Intel Corporation 82371SB PIIX3 ISA [Natoma/Triton II]
00:01.1 IDE interface: Intel Corporation 82371AB/EB/MB PIIX4 IDE (rev 01)
00:02.0 VGA compatible controller: InnoTek Systemberatung GmbH VirtualBox Graphics Adapter
00:03.0 Ethernet controller: Intel Corporation 82540EM Gigabit Ethernet Controller (rev 02)
00:04.0 System peripheral: InnoTek Systemberatung GmbH VirtualBox Guest Service
00:05.0 Multimedia audio controller: Intel Corporation 82801AA AC'97 Audio Controller (rev 01)
00:06.0 USB controller: Apple Inc. KeyLargo/Intrepid USB
00:07.0 Bridge: Intel Corporation 82371AB/EB/MB PIIX4 ACPI (rev 08)
00:08.0 Ethernet controller: Intel Corporation 82540EM Gigabit Ethernet Controller (rev 02)
00:0b.0 USB controller: Intel Corporation 82801FB/FBM/FR/FW/FRW (ICH6 Family) USB2 EHCI Controller
00:0d.0 SATA controller: Intel Corporation 82801HM/HEM (ICH8M/ICH8M-E) SATA Controller [AHCI mode] (rev 02)

lpci -v | less or pci -v -s 00:02.0 :

00:02.0 VGA compatible controller: InnoTek Systemberatung GmbH VirtualBox Graphics Adapter (prog-if 00 [VGA controller])
	Flags: bus master, fast devsel, latency 0, IRQ 18
	Memory at e0000000 (32-bit, prefetchable) [size=16M]
	Expansion ROM at <unassigned> [disabled]
	Kernel driver in use: vboxvideo
	Kernel modules: vboxvideo

Innotek video card with 16 MB of video RAM.

cat /var/log/Xorg.0.log | less or grep -i memory /var/log/Xorg.0.log

sudo dmesg | grep drm
[   21.063213] [drm] Initialized drm 1.1.0 20060810
[   21.138231] [drm] VRAM 00c00000
[   21.139891] fbcon: vboxdrmfb (fb0) is primary device
[   21.148401] vboxvideo 0000:00:02.0: fb0: vboxdrmfb frame buffer device
[   21.167325] [drm] Initialized vboxvideo 1.0.0 20130823 for 0000:00:02.0 on minor 0

LC_ALL=C lspci -v | grep -EA10 "3D|VGA" | grep 'prefetchable'

	Memory at e0000000 (32-bit, prefetchable) [size=16M]
	Memory at f0000000 (32-bit, non-prefetchable) [size=128K]

Which means it has 128K of memory dedicated to the integrated video card.

http://opensourceforu.com/2011/07/accessing-x86-specific-io-mapped-hardware-in-linux/
Accessing x86-Specific I/O-Mapped Hardware driver:

which devices are I/O mapped and what the port addresses of these devices are :
cat /proc/ioports

0000-0cf7 : PCI Bus 0000:00
  0000-001f : dma1
  0020-0021 : pic1
  0040-0043 : timer0
  0050-0053 : timer1
  0060-0060 : keyboard
  0064-0064 : keyboard
  0070-0071 : rtc_cmos
    0070-0071 : rtc0
  0080-008f : dma page reg
  00a0-00a1 : pic2
  00c0-00df : dma2
  00f0-00ff : fpu
  0170-0177 : 0000:00:01.1
    0170-0177 : ata_piix
  01f0-01f7 : 0000:00:01.1
    01f0-01f7 : ata_piix
  0376-0376 : 0000:00:01.1
    0376-0376 : ata_piix
  03c0-03df : vga+
  03f6-03f6 : 0000:00:01.1
    03f6-03f6 : ata_piix
0cf8-0cff : PCI conf1
0d00-ffff : PCI Bus 0000:00
  4000-4003 : ACPI PM1a_EVT_BLK
  4004-4005 : ACPI PM1a_CNT_BLK
  4008-400b : ACPI PM_TMR
  4020-4021 : ACPI GPE0_BLK
  d000-d00f : 0000:00:01.1
    d000-d00f : ata_piix
  d010-d017 : 0000:00:03.0
    d010-d017 : e1000
  d020-d03f : 0000:00:04.0
  d100-d1ff : 0000:00:05.0
    d100-d1ff : Intel 82801AA-ICH
  d200-d23f : 0000:00:05.0
    d200-d23f : Intel 82801AA-ICH
  d240-d247 : 0000:00:08.0
    d240-d247 : e1000
  d248-d24f : 0000:00:0d.0
    d248-d24f : ahci
  d258-d25f : 0000:00:0d.0
    d258-d25f : ahci
  d270-d27f : 0000:00:0d.0
    d270-d27f : ahci

Kernel APIs:
#include <asm/io.h>

u8 inb(unsigned long port);
u16 inw(unsigned long port);
u32 inl(unsigned long port);
void outb(u8 value, unsigned long port);
void outw(u16 value, unsigned long port);
void outl(u32 value, unsigned long port);

The first serial port is always I/O mapped from 0x3F8 to 0x3FF. But what does this mapping mean? What do we do with this? 
How does it help us to use the serial port? That is where a data-sheet of the corresponding device needs to be looked up.

A serial port is controlled by the serial controller device, commonly known as an UART (Universal Asynchronous Receiver/Transmitter) 
or at times a USART (Universal Synchronous/Asynchronous Receiver/Transmitter). On PCs, the typical UART used is the PC16550D. 
The data-sheet for this [PDF] can be downloaded as part of the self-extracting package [BIN file] used for the Linux device driver kit, available at lddk.esrijan.com.

How, does one get these device number and its data sheets?

Device driver writers need to understand the details of the registers of the device, as it is these registers that writers need to program, to use the device.
Each of the eight rows corresponds to the respective bit of the registers. Also, note that the register addresses start from 0 and goes up to 7. 
The interesting thing about this is that a data sheet always gives the register offsets, which then needs to be added to the base address of the device, to get the actual register addresses.

Who decides the base address and where is it obtained from? Base addresses are typically board/platform specific, 
unless they are dynamically configurable like in the case of PCI devices. In this case, i.e., a serial device on x86, it is dictated by the x86 architecture—and 
that precisely was the starting serial port address mentioned above—0x3F8.

Thus, the eight register offsets, 0 to 7, exactly map to the eight port addresses 0x3F8 to 0x3FF. 
So, these are the actual addresses to be read or written, for reading or writing the corresponding serial registers, to achieve the desired serial operations, as per the register descriptions.

All the serial register offsets and the register bit masks are defined in the header <linux/serial_reg.h>. 
So, rather than hard-coding these values from the data sheet, the corresponding macros could be used instead. All the following code uses these macros, along with the following:
#define SERIAL_PORT_BASE 0x3F8

Operating on the device registers
To summarise the decoding of the PC16550D UART data sheet, here are a few examples of how to do read and write operations of the serial registers and their bits.

Reading and writing the ‘Line Control Register (LCR)’:
u8 val;
 
val = inb(SERIAL_PORT_BASE + UART_LCR /* 3 */);
outb(val, SERIAL_PORT_BASE + UART_LCR /* 3 */);

Setting and clearing the ‘Divisor Latch Access Bit (DLAB)’ in LCR:
u8 val;
 
val = inb(SERIAL_PORT_BASE + UART_LCR /* 3 */);
 
/* Setting DLAB */
val |= UART_LCR_DLAB /* 0x80 */;
outb(val, SERIAL_PORT_BASE + UART_LCR /* 3 */);
 
/* Clearing DLAB */
val &= ~UART_LCR_DLAB /* 0x80 */;
outb(val, SERIAL_PORT_BASE + UART_LCR /* 3 */);

Reading and writing the ‘Divisor Latch’:
u8 dlab;
u16 val;
dlab = inb(SERIAL_PORT_BASE + UART_LCR);
dlab |= UART_LCR_DLAB; // Setting DLAB to access Divisor Latch
outb(dlab, SERIAL_PORT_BASE + UART_LCR);
 
val = inw(SERIAL_PORT_BASE + UART_DLL /* 0 */);
outw(val, SERIAL_PORT_BASE + UART_DLL /* 0 */);

Blinking an LED

To get a real experience of low-level hardware access and Linux device drivers, the best way would be to play with the Linux device driver kit (LDDK) mentioned above.
However, just for a feel of low-level hardware access, a blinking light emitting diode (LED) may be tried, as follows:

Connect a light-emitting diode (LED) with a 330 ohm resistor in series across Pin 3 (Tx) and Pin 5 (Gnd) of the DB9 connector of your PC.

Pull up and down the transmit (Tx) line with a 500 ms delay, by loading and unloading the blink_led driver, using insmod blink_led.ko and rmmod blink_led, respectively.
Driver file blink_led.ko can be created from its source file blink_led.c by running make with the usual driver Makefile.

I/O Control in Linux :

Talk about the typical ioctl() implementation and usage in Linux.

Introducing ioctl():

Input/Output Control (ioctl, in short) is a common operation, or system call, available in most driver categories. 
It is a one-bill-fits-all kind of system call. If there is no other system call that meets a particular requirement, then ioctl() is the one to use.

Practical examples include volume control for an audio device, display configuration for a video device, reading device registers, and so on — basically, 
anything to do with device input/output, or device-specific operations, yet versatile enough for any kind of operation 
(for example, for debugging a driver by querying driver data structures).

The question is: how can all this be achieved by a single function prototype? The trick lies in using its two key parameters: command and argument. 
The command is a number representing an operation. The argument command is the corresponding parameter for the operation. 
The ioctl() function implementation does a switch … case over the commmand to implement the corresponding functionality. 
The following has been its prototype in the Linux kernel for quite some time:

long ioctl(struct file *f, unsigned int cmd, unsigned long arg);

If there is a need for more arguments, all of them are put in a structure, and a pointer to the structure becomes the ‘one’ command argument. 
Whether integer or pointer, the argument is taken as a long integer in kernel-space, and accordingly type-cast and processed.

ioctl() is typically implemented as part of the corresponding driver, and then an appropriate function pointer is initialised with it,
 exactly as in other system calls like open(), read(), etc. For example, in character drivers, it is the ioctl or unlocked_ioctl (since kernel 2.6.35) function pointer 
field in the struct file_operations that is to be initialised.

Again, like other system calls, it can be equivalently invoked from user-space using the ioctl() system call, prototyped in <sys/ioctl.h> as:

int ioctl(int fd, int cmd, ...);

Here, cmd is the same as what is implemented in the driver’s ioctl(), and the variable argument construct (...) is a hack to be able to pass 
any type of argument (though only one) to the driver’s ioctl(). Other parameters will be ignored.

Note: that both the command and command argument type definitions need to be shared across the driver (in kernel-space) and the application (in user-space). 
Thus, these definitions are commonly put into header files for each space.

Querying driver-internal variables:

To better understand the boring theory explained above, here’s the code set for the “debugging a driver” example mentioned earlier. This driver has three static global variables:
status, dignity, and egowhich need to be queried and possibly operated from an application. 
The header file query_ioctl.h defines the corresponding commands and command argument type. 

Defining the ioctl() commands:

The standard talks about the 32-bit command numbers, formed of four components embedded into the [31:0] bits:

The direction of command operation [bits 31:30] — read, write, both, or none — filled by the corresponding macro (_IOR, _IOW, _IOWR, _IO).
The size of the command argument [bits 29:16] — computed using sizeof() with the command argument’s type — the third argument to these macros.
The 8-bit magic number [bits 15:8] — to render the commands unique enough — typically an ASCII character (the first argument to these macros).
The original command number [bits 7:0] — the actual command number (1, 2, 3, …), defined as per our requirement — the second argument to these macros.

Check out the header <asm-generic/ioctl.h> for implementation details.

steps :

1. Build the query_ioctl driver (query_ioctl.ko file) and the application (query_app file) by running make, using the following Makefile.

2. Load the driver using insmod query_ioctl.ko.

3. With appropriate privileges and command-line arguments, run the application query_app:

./query_app — to display the driver variables
./query_app -c — to clear the driver variables
./query_app -g — to display the driver variables
./query_app -s — to set the driver variables (not mentioned above)



