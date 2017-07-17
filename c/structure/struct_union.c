#include <stdio.h>
 
int main()
{
    struct ex_struct {
        char element1;  // 1 byte
        int element2;   // 4 bytes
        long element3;  // 8 bytes
    };
    union ex_union {
        char element1;
        int element2;
        long element3;
    };
 
    struct ex_struct a;
    union ex_union b;
 
    printf("Size of structure: %d\n", sizeof(a));
    printf("Size of union: %d\n", sizeof(b));
 
    a.element1 = 'D';
    a.element2 = 59;
 
    b.element1 = 'D';
    b.element2 = 59;
 
    printf("a.element1 = %c\n", a.element1);
    printf("a.element2 = %d\n", a.element2);
    printf("b.element1 = %c\n", b.element1);
    printf("b.element2 = %d\n\n", b.element2);
 
    b.element3 = 0x333333333;
    b.element1 = 0x11;
    printf("b.element3 = 0x%x\n", b.element3);
    printf("b.element1 = 0x%x\n", b.element1);
 
    return 0;
}
