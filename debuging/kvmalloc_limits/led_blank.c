/*http://naveengopala-embeddedlinux.blogspot.in/2012/01/reading-physical-mapped-memory-using.html*/
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LED_ADDR 0x80840020

extern int errno;

int main()
{
        int i;
        unsigned char *leds;
        unsigned char val;

        int fd = open("/dev/mem",O_RDWR|O_SYNC);
        if(fd < 0)
        {
                printf("Can't open /dev/mem\n"winking smiley;
                return 1;
        }
        leds = (unsigned char *) mmap(0, getpagesize(), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0x80840000);
        if(leds == NULL)
        {
                printf("Can't mmap\n"winking smiley;
                return 1;
        }
        else
                printf("leds=%x\n",leds);

        for(i = 0; i < 256; i++)
        {
                val = i % 4;
                leds[0x20] = val;

                sleep(1);
        }

        return 0;
}
