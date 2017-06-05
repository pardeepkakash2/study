#include <stdio.h>

int main()
{
	/*C program to find given number even or odd without 
	using if condition?*/
	int n = 5;
	(n & 0x01) && printf("odd\n") || printf("even\n");
	return 0;
}
