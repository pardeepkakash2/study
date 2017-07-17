#include <stdio.h>
 
int main()
{
    int Arr[16];
    Arr[0] = 9;
    Arr[3] = 5;
    printf("Arr[3]:      \t%d\n",Arr[3]);
    printf("*(Arr + 3):  \t%d\n",*(Arr + 3));
    printf("*(3 + Arr):  \t%d\n",*(3 + Arr));
    printf("*(&Arr[0] + 3):\t%d\n",*(&Arr[0] + 3)); // &Arr[0] is the same as Arr
    printf("3[Arr]:      \t%d\n",3[Arr]); // gets converted by compiler to *(3 + Arr)
    printf("\n");
 
    // showing how + operation behaves when used with addresses of pointers or arrays
    printf("Arr:         \t%u\n", Arr);
    printf("&Arr[0]:     \t%u\n", &Arr[0]);
    printf("&Arr[0] + 1: \t%u\n", &Arr[0] + 1);
    printf("&*(&Arr[0] + 1):%u\n", &*(&Arr[0] + 1));
    printf("sizeof(Arr): \t%d\n", sizeof(Arr));
    printf("sizeof(Arr[0]):\t%d\n", sizeof(Arr[0]));
    printf("sizeof(int):\t%d\n", sizeof(int));
    printf("\n");
 
    printf("sizeof(&Arr[0]):%d\n", sizeof(&Arr[0]));
    printf("sizeof(unsigned long):%d\n", sizeof(unsigned long));
    printf("\n");
 
 
    unsigned long ArrAddr = (unsigned long)&Arr[0];
    printf("ArrAddr: %u\n", ArrAddr);
    int *p;
    p = ArrAddr;
    printf("*p: %d\n", *p);
    printf("*(p+3): %d\n", *(p+3));
    printf("\n");
 
    // breaking operator overloading of +
    unsigned long ArrAddr3 = ArrAddr + 3;
    p = ArrAddr3;
    printf("ArrAddr3: %u\n", ArrAddr3);
    printf("*p: %d\n", *p);
    printf("\n");
 
    // doing manually what overloading of + does automatically
    ArrAddr3 = ArrAddr + 3*sizeof(Arr[0]);
    p = ArrAddr3;
    printf("ArrAddr3: %u\n", ArrAddr3);
    printf("*p: %d\n", *p);
    printf("\n");
 
 
 
    return 0;
 
}
