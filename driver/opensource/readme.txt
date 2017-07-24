http://opensourceforu.com/2011/06/generic-hardware-access-in-linux/

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

