#include <stdio.h>
#include <arpa/inet.h>

union endian {
	char c;
	int i;
};

void method3(union endian en)
{
	en.i = 1;

	if(en.c == 1) {
		printf("this is little endian\n");
	} else {
		printf("this is big endian\n");
	}
}

void method2(void)
{
	const long number=123;

	/*The htonl() function converts the unsigned integer hostlong from host byte order to network byte order.*/
	if(number == htonl(number)) {
		printf("This is big endian machine\n");
	} else {
		printf("This is little endian machine\n");
	}
}

void method1(char *ch)
{
	if (*ch) {
		printf("Little Endian\n");
	} else {
		printf("Big Endian\n");
	}
}

/* function to show bytes in memory, from location start to start+n*/
void show_mem_map(char *start, int n)
{

	int i = 0;
	for(i = 0; i < n; i++) {
		printf("%.2x", start[i]);
//		printf("%.2x", *(start+i));
	}
	printf("\n");
	
}

/*Main function to call above function for 0x01234567*/
int main()
{
	int var = 0x12345678;
	int ret = 0;
	char *ch = (char *)&var;

	show_mem_map(ch, sizeof(var));

	method1(ch);

	method2();

	union endian st;
	method3(st);
	return 0;
}
