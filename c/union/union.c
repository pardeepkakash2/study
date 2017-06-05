#include <stdio.h>

int main()
{
    union a
    {
        int i;
        char ch[2];
    };
    union a u;
    u.ch[0]=3;
    u.ch[1]=2;
    printf("%d, %d, %d\n", u.ch[0], u.ch[1], u.i);
    
    union var
    {
        int a, b;
    };
    union var v;
    v.a=10;
    v.b=20;
    printf("%d\n", v.a);
    
return 0;
	
}
