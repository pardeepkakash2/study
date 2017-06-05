gcc -c sub.c
gcc -c add.c 
ar rcs libheymath.a add.o sub.o 
gcc -I . -c addDemo.c
gcc -o addDemo addDemo.o libheymath.a
gcc -o addDemo -L . addDemo.o -lheymath
./addDemo

Note:
gcc -Wall -I/sourcepath/ -L/opt/lib sourcefile -llibrary -o outputfile
-I sourcespath.
-l heymath which tells the linker to link the object files contained in lib<library>.a
-L option tells the linker to search path for libraries
