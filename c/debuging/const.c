/*
const char *ptr :
        ptr is a pointer to a char, where you can't change the value of the char (at least not through the pointer
        (without casting the constness away)).
char * const ptr :
        ptr is a constant pointer to a char, where you can change the char, but you can't make the pointer point to a different char.
const char *const ptr:
        ptr is a constant pointer to a constant char, i.e. you can change neither where the pointer points nor the value of the pointee.
Now the first const can be on either side of the type so:

const int * == int const *
const int * const == int const * const

If you want to go really crazy you can do things like this:

int ** - pointer to pointer to int
int ** const - a const pointer to a pointer to an int
int * const * - a pointer to a const pointer to an int
int const ** - a pointer to a pointer to a const int
int * const * const - a const pointer to a const pointer to an int

*/
#include <stdio.h>

/*pointer to a const*/
void f1()
{
    int i = 100;
    const int* pi = &i;
    //*pi = 200; <- won't compile
    pi++;
}

/*const pointer*/
void f2()
{
    int i = 100;
    int* const pi = &i;
    *pi = 200;
    //pi++; <- won't compile
}

/*const pointer to a const*/
void f3()
{
    int i = 100;
    const int* const pi = &i;
    //*pi = 200; <- won't compile
    //pi++; <- won't compile

}

int main ()
{
	f1();
	f2();
	f3();
	return 0;
}
