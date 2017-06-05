#include <stdio.h>

int main()
{
	unsigned char ch;
	for (ch = 0; ch <=300; ch++)
	{
		/*infinite loop read signed and unsigned char consep
		signed : 0-127, -128-0, unsigned: 0-255.
		*/
		printf("ch = %d\n", ch);
	}
	return 0;
}
