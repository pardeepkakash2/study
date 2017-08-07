#include <stdio.h>
#include <sys/stat.h> 
#include <fcntl.h>    
#include <sys/types.h>

void main(void)
{
      int fd, num;
  
      fd = open("/dev/globalvar", O_RDWR, S_IRUSR | S_IWUSR); 
      if (fd != -1 ){

            read(fd, &num, sizeof(int));
            printf("The globalvar is %d\n", num);

            printf("Please input the num written to globalvar\n");
            scanf("%d", &num);
            write(fd, &num, sizeof(int));
     
            read(fd, &num, sizeof(int));
            printf("The globalvar is %d\n", num);
   
            close(fd);
      }else{
            printf("Device open failure\n");
      }
}
