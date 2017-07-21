#include <stdio.h>

/* Function to get no of set bits in binary representation of passed binary no. */
int count_setbits(int n)
{
	unsigned int count = 0;

	/*Loop through all bits*/
	while(n) {
		count = count + (n & 1);
		n = n >> 1;
	}
	return count;
}
int main()
{
	int num = 9;

	printf("setbits: %d\n", count_setbits(num));
	return 0;
}

