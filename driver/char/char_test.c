#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "char_test.h"

char write_buff[100] = "Dharmender sharma";

int main()
{
    int num, fd, read_bytes, written_bytes, rv;
    char read_data[100];

    printf("Do you want to open: 1 - Yes, 0 - No : ");
    scanf("%d", &num);
    fd = open("/dev/chardev", O_RDWR);
	if (fd < 0)
		printf("opening device failed :%d\n", fd);
	else
		printf("opening device success :%d\n", fd);
		
    printf("Do you want to write: 1 - Yes, 0 - No : ");
    scanf("%d", &num);
    written_bytes = write(fd, write_buff, 10);
    if(written_bytes < 0) {
        printf("Error in writting\n");
    }

    printf("Do you want to read: 1 - Yes, 0 - No : ");
    scanf("%d", &num);
    read_bytes = read(fd, read_data, 10);
    printf("%d\n", read_bytes);
    printf("%s\n", read_data);
    if(read_bytes < 0) {
        printf("Error in reading\n");
    }

    printf("Do you want to ioctl: 1 - Yes, 0 - No : ");
    scanf("%d", &num);
    rv = ioctl(fd, CD_IOC_ALLOC_BUF, sizeof(write_buff));
    if(rv < 0) {
        printf("Error in CD_IOC_ALLOC_BUF\n");
    }

    rv = ioctl(fd, CD_IOC_WRITE_STRING, write_buff);
    if(rv < 0) {
        printf("Error in CD_IOC_WRITE_STRING\n");
    }

    rv = ioctl(fd, CD_IOC_REVERSE_STRING);
    if(rv < 0) {
        printf("Error in CD_IOC_REVERSE_STRING\n");
    }

    rv = ioctl(fd, CD_IOC_READ_STRING, read_data);
    if(rv < 0) {
        printf("Error in CD_IOC_READ_STRING\n");
    }

    ioctl(fd);

    printf("Do you want to close: 1 - Yes, 0 - No : ");
    scanf("%d", &num);
    close(fd);

    return 0;
} 
