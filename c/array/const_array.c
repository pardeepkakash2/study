#include <stdio.h>

int main()
{
	char test[] = "abcd";
	printf("test :%s\n", test);
	test[0] = 'b';	
	printf("test :%s\n", test);

	#if 0
	/*error: incompatible types when assigning to type ‘char[1]’ 
	from type ‘char *’*/	
	
	char ch[] = {'a','b','c','d'};
	ch = "efgh";
	printf("ch :%s\n", ch);
	#endif

	char *arr[3] = {"sona", "vinod", "sanga"};
	printf("arr : %s %s %s\n", arr[1], arr[0], arr[2]);
	return 0;
}
