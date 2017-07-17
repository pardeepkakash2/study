#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{
    /* variables */
    int    a = 25;
    float  b = 3.142;
    double c = 1.73217;
    char   d[]="Hello, C Programmer"; /* array of characters, which is equivalent to a string */
    char   e = 'x';
 
    /* pointers to variables */
    int    *pa = &a; /* points to variable a */
    float  *pb = &b; /* points to variable b */
    double *pc = &c; /* points to variable c */
    char   *pd = d;  /* points to first element of array d*/
    char   *pe = &e; /* points to variable e */
 
    /* pointer to pointer */
    int    **ppa;
    ppa = &pa;    /* double pointer points to pointer pa */
 
    /* value of the variables */
    printf("Value of integer variable a: %d\n", a);
    printf("Value of floating variable b: %f\n", b);
    printf("Value of the double variable c: %f\n", c);
    printf("Value of string d: %s\n", d);
    printf("Value of character e: %c\n", e);
    printf("\n");
 
    /* value of variables pointers point to */
    /* prints the value of the variables pointed by the pointers */
    printf("Value of variable that pa points to: %d\n", *pa);
    printf("Value of variable that pb points to: %f\n", *pb);
    printf("Value of variable that pc points to: %f\n", *pc);
    printf("Value of variable that pd points to: %c\n", *pd);
    printf("Value of variable that pe points to: %c\n", *pe);
    printf("Value of variable that ppa points to points to: %d\n", **ppa);
    printf("Value of variable that ppa points to: %u\n", *ppa);
    printf("\n");
 
    /* addresses of variables */
    /* gets the addresses of the variables by deferencing the variables */
    printf("Address of a: %u\n", &a);
    printf("Address of b: %u\n", &b);
    printf("Address of c: %u\n", &c);
    printf("Address of d: %u\n", d);
    printf("Address of e: %u\n", &e);
    printf("\n");
 
    /* addresses of pointers */
    /* gets the address of the pointers (where the pointers are in memory) by deferencing */
    printf("Address of pointer pa: %u\n", &pa);
    printf("Address of pointer pb: %u\n", &pb);
    printf("Address of pointer pc: %u\n", &pc);
    printf("Address of pointer pd: %u\n", &pd);
    printf("Address of pointer pe: %u\n", &pe);
    printf("Address of pointer ppa: %u\n", &ppa);
    printf("\n");
 
    /* addresses pf variables pointed by pointers */
    /* this should give the same result as the section 'addresses of variables' */
    printf("Address of variable pointed by pa: %u\n", &*pa);
    printf("Address of variable pointed by pb: %u\n", &*pb);
    printf("Address of variable pointed by pc: %u\n", &*pc);
    printf("Address of variable pointed by pd: %u\n", &*pd);
    printf("Address of variable pointed by pe: %u\n", &*pe);
    printf("Address of variable pointed by pointer pointed by ppa: %u\n", &**ppa);
    printf("Address of pointer pointed by ppa: %u\n", &*ppa);
    printf("\n");
 
    return 0;
}
