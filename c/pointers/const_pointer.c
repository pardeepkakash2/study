#include <stdio.h>
 
int main (){
 
    int v[] = {5, 20};
    int *p = v;
    printf("p: %d, ", (*p)++); // increments data pointed
    printf("p: %d, ", *p++);   // increments pointer. Equivalent to *(p++) because '++' has higher priority
    printf("p: %d\n", *p);
     
    /* pointer to constant data (can't modified data pointed) */
    const int *p2 = v;
    //int const *p2 = v; // same as above
    //printf("const ptr: %d, ", (*p2)++); // error: increment of read-only location
    printf("const ptr: %d, ", *p2++);   // '++' has priority, so incrementing pointer
    //printf("const ptr: %d, ", *(p2++)); // same as above 
    printf("const ptr: %d\n", *p2);
     
    /* constant pointer (can't modified pointer). Same as 'int p3[] = v' */
    int * const p3 = v;
    //int * p3 const = v;    // error: expected ‘=’,..., before ‘const’
    printf("ptr to const data: %d, ", (*p3)++); // incrementing data refered by pointer
    //printf("ptr to const data: %d, ", *p3++); // error: increment of read-only variable ‘p3’
    printf("ptr to const data: %d\n", *p3);
     
    /* constant pointer to constant data */
    const int * const p4 = v;
    // int const * const p4; // same as above
    //printf("const ptr to const data: %d, ", (*p4)++); // error: increment of read-only location ‘*p4’
    //printf("const ptr to const data: %d, ", *p4++);   // error: increment of read-only variable ‘p4’
    printf("const ptr to const data: p4: %d\n", *p4);
     
    /* array definition is equivalent to constant pointer. Same as 'int * const v' */
    printf("ptr from array: %d, ", (*v)++);
    //printf("ptr from array: %d, ", *v++); // error: lvalue required as increment operand
    printf("ptr from array: %d\n", *v);
     
    return 1;
}
