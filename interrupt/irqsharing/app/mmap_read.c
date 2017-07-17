#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>


const char *files[] = {
        "/usr/share/dict/american-english",
        "/usr/share/dict/british-english",
};


int main(int argc, char *argv[])
{
#if USE_READ
        int loop = 0;
        int fd;
        struct stat st;
        char *p, *dst;
        off_t len;
        ssize_t nr;

        for (loop = 0; loop < 100; loop++) {
                fd = open(files[loop%2], O_RDONLY);
                if (fd == -1) {
                        perror("open");
                        return 1;
                }
                if (fstat(fd, &st) == -1) {
                        perror("fstat");
                        return 1;
                }
                p = (char *)malloc(st.st_size);
                nr = read(fd, p, st.st_size);
                if (nr == -1) {
                        perror("read");
                        return 1;
                }
                dst = (char *)malloc(st.st_size + 1);
                for (len = 0; len < st.st_size; len++) {
                        dst[len] = p[len];
                }
                dst[len+1] = 0;
                free(dst);
        }

        return 0;
#else
        int loop = 0;
        int fd;
        struct stat st;
        char *p, *dst;
        off_t len;

        for (loop = 0; loop < 100; loop++) {
                fd = open(files[loop%2], O_RDONLY);
                if (fd == -1) {
                        perror("open");
                        return 1;
                }
                if (fstat(fd, &st) == -1) {
                        perror("fstat");
                        return 1;
                }
                p = mmap(0, st.st_size, PROT_READ, MAP_SHARED, fd, 0);
                if (p == MAP_FAILED) {
                        perror("mmap");
                        return 1;
                }
                if (close(fd) == -1) {
                        perror("close");
                        return 1;
                }
                dst = (char *)malloc(st.st_size + 1);
                for (len = 0; len < st.st_size; len++) {
                        dst[len] = p[len];
                }
                dst[len+1] = 0;
                if (munmap(p, st.st_size) == -1) {
                        perror("munmap");
                        return 1;
                }
                free(dst);
        }

        return 0;
#endif
}
