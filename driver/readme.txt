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
	
	Storage Technologies
	Linux Block I/O Layer
	I/O Schedulers
	Block Driver Data Structures and Methods
	Block/Storage Device Example
	Advanced Topics
	Debugging
	Writing a sample Block Device Driver


USB:
	simple driver for LED, SSD, LCD
	USB Mass Storage (MMC) driver
	USB to Serial converter
	Various Serial character drivers
	Complex matrix keypad driver using interrupts and synchronization
	USB Input drivers
	USB audio

	USB Architecture
	Linux-USB Subsystem
	Driver Data Structures
	Enumeration
	USB Device Example
	Class Drivers
	Debugging Aspects
	Writing a sample USB Device Driver

	i2c:
	What’s I2C/SMBus?
	I2C Core
	Bus Transactions
	Device Examples
	I2C-dev
	Debugging Aspects
	Writing a sample I2C Device Driver

	Audio :
	Audio Architecture
	Linux-Sound Subsystem
	Device Example
	Debugging Aspects
	Writing a sample Audio Device Driver

	video:
	Display Architecture
	Linux-Video Subsystem
	Display Parameters
	The Frame Buffer API
	Frame Buffer Drivers
	Console Drivers
	Debugging Aspects
	Writing a sample Video Device Driver

Network:

	Networking Driver Data Structures
	Communicating with Protocol Layers
	Buffer Management and Concurrency Control
	Network Device Example
	Network Throughput
	Debugging Aspects
	Writing a sample Network Device Driver

