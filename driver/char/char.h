#include <linux/ioctl.h>

struct string {
    char original[20];
    char reverse[20];
};

#define CD_MAGIC 89
#define CD_IOC_ALLOC_BUF _IOW(CD_MAGIC, 0, int)
#define CD_IOC_WRITE_STRING _IOW(CD_MAGIC, 1, int)
#define CD_IOC_REVERSE_STRING _IO(CD_MAGIC, 2)
#define CD_IOC_READ_STRING _IOR(CD_MAGIC, 3, int)
#define CD_IOC_FREE_BUF _IO(CD_MAGIC, 4)
#define CD_IOC_READ_WRITE_REVERSE_STRING _IOWR(CD_MAGIC, 5, int)
