#include <linux/module.h>
#include <linux/version.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <asm/io.h>
 
#include <linux/serial_reg.h>
 
#define SERIAL_PORT_BASE 0x3F8
 
int __init init_module()
{
    int i;
    u8 data;
 
    data = inb(SERIAL_PORT_BASE + UART_LCR);
    for (i = 0; i < 5; i++)
    {
        /* Pulling the Tx line low */
        data |= UART_LCR_SBC;
        outb(data, SERIAL_PORT_BASE + UART_LCR);
        msleep(500);
        /* Defaulting the Tx line high */
        data &= ~UART_LCR_SBC;
        outb(data, SERIAL_PORT_BASE + UART_LCR);
        msleep(500);
    }
    return 0;
}
 
void __exit cleanup_module()
{
}
 
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Blinking LED Hack");
