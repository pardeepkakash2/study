#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

#define MAX 100
#define my_sizeof(type) (char *)(&type+1)-(char*)(&type)

struct core {
	unsigned int status;
	char arr[MAX];
};

struct device {
	struct core ptr;
	unsigned int  easy;
	unsigned int  hard;
};


static inline struct device *core_to_device_typecasting(const struct core *core)
{
	return (struct device *)core;
}

int main()
{
	int len = 0;
	char *str = "inter node communication testing";
	struct core *t1 = (struct core *) malloc(sizeof(struct core));
	
	t1->status = 99;
	len = strlen(str);
	strncpy(t1->arr, str, len);

	printf("%ld: %ld :%p\n", sizeof(*t1), sizeof(struct core), t1);	
	struct device *t2 = core_to_device_typecasting(t1);

	printf("my_sizeof:%ld\n", my_sizeof(*t2));
	printf("%ld: %ld: %p\n", sizeof(*t2), sizeof(struct device), t2);	
	printf("%d\n", t2->ptr.status);
	printf("%s\n", t2->ptr.arr);

	t2->easy = 1;
	t2->hard = 10;
	printf("%d\n", t2->easy);
	printf("%d\n", t2->hard);
	
	return 0;
}
