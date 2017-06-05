#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "character_driver.h"

int main()
{
    int num, fd, rv;
    struct string s = { "jeevitha", " "};

    printf("Do you want to open: 1 - Yes, 0 - No : ");
    scanf("%d", &num);
    fd = open("/dev/myDev", O_RDWR);

    printf("Do you want to ioctl: 1 - Yes, 0 - No : ");
    scanf("%d", &num);
    rv = ioctl(fd, CD_IOC_READ_WRITE_REVERSE_STRING, &s);
    if(rv < 0) {
        printf("Error in CD_IOC_READ_WRITE_REVERSE_STRING\n");
    }
    printf("Original string %s\n", s.original);
    printf("Reversed string %s\n", s.reverse);
    
    printf("Do you want to close: 1 - Yes, 0 - No : ");
    scanf("%d", &num);
    close(fd);

    return 0;
} 
