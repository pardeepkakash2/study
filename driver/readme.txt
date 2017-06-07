Core technologies:

    Multilayer hardware design
    Multicore processor programming
    FPGA Design
    FPGA Emulator Board Design
    BSP, Device Drivers
    Audio Video CODECs

Board Support Package:

    Board Bring up
    Boot Loaders
    Real Time Operating Systems
    File Systems
    Device Drivers
    Middleware Applications


Device Programming:

    Camera
    Audio
    Video
    Magnetic Sensors
    Orientation Sensors
    Wifi
    Bluetooth Programming
    Android wearable gadgets


Device Type: 		Device Drivers:

Networking 		Ethernet MAC (10/100/1000 Mbps), Ethernet Switch (10 /100/ 1000 Mbps), VLYNQ, 
			Wireless Ethernet MAC (802.11b/g), GPS, ToE (TCP offload Engine), Gigabit Ethernet (GE) device driver
Wireless 		802.11bg, 802.11b, 802.11g, Bluetooth
Storage 		NAND (large page, small page), NOR, OneNAND, Compact Flash,MMC/SD, IDE-HDD, USB 1.1, 2.0 (High-speed, OTG), 
			NVSRAM
Audio / Video 		Audio DAC, VPSS (VPBE, VPFE, Resizer, OSD, Previewer)
Buses 			PCI, I2C, SPI
Off-Chip Peripherals 	I2C supported ICs, SPI supported ICs and EEPROMs, UART, RS485, LCD, 
			Touch screen LCD, Keypad, IR, GPIO, PCMCIA, RFID, Barcode, PWM
On-Chip Peripherals 	Timers (including WatchDog Timer), DMA Engines, Interrupt Controllers, PLL/Clock
Hardware Accelerators  	Crypto Accelerator, Resizer, OSD, Previewer, H3A


character:
	RS232 interface (i/o)
	innterrupt handling
	i/o control
	timeres(LED control)
	synchronization
	sysfs and procfs
	debugs

Block:

	SD/MMC card driver
	SCSI implementation
	USB protocol
	SCSI over usb

USB:
	simple driver for LED, SSD, LCD
	USB Mass Storage (MMC) driver
	USB to Serial converter
	Various Serial character drivers
	Complex matrix keypad driver using interrupts and synchronization
	USB Input drivers
	USB audio

Network:
