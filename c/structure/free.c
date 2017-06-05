#include <stdio.h>
#include <stdlib.h>

int main()
{

	#if 0
	/*warning: assignment makes pointer from integer without 
	a cast [enabled by default]
	int *a = malloc(10);*/
	
	int value = 20;
	int *a = ( int* )malloc(10);
	a = &value;
	printf("value : %d a : %d\n", value, *a);

	/*how free will know that how many no. of bytes need to free*/
	free(p);
	#endif

	int *ptr = NULL;
	free(ptr);
	
	/*free(): invalid pointer*/
	int value = 20;
	ptr = (int *)malloc(10);
	ptr = &value;
	free(ptr);
	printf("value : %d a : %d\n", value, *ptr);

		
	return 0;
}
