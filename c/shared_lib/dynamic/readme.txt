gcc -Wall -fPIC -c add.c
gcc -Wall -fPIC -c sub.c
#ldconfig
gcc -shared -o libheymath.so add.o sub.o
gcc -c addDemo.c
gcc -o addDemo addDemo.o libheymath.so
export LD_LIBRARY_PATH=/home/dus5cob/test/lkd/c/shared_lib/dynamic/
./addDemo

#ldd
dus5cob@KOR1064342VM:~/test/lkd/c/shared_lib/dynamic$ ldd libheymath.so 
	linux-vdso.so.1 =>  (0x00007ffc1967c000)
	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007faadd012000)
	/lib64/ld-linux-x86-64.so.2 (0x00007faadd5dc000

Dynamic loader tries to find all the libraries by using:

    DT_RPATH dynamic section of ELF file.
    DT_RUNPATH section of the executable.
    LD_LIBRARY_PATH environment variable.
    /etc/ld.so.cache - own cache file which contains a compiled list of candidate libraries previously found in the augmented library path.
    Default paths: In the default path /lib, and then /usr/lib. If the binary was linked with -z nodeflib linker option, this step is skipped.

