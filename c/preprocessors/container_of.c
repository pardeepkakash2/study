#include <stdio.h>
#include <stdlib.h>

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({ \
const typeof( ((type *)0)->member ) *__mptr = (ptr); \
(type *)( (char *)__mptr - offsetof(type,member) ); })

struct test1 {
	int a;
};

struct test2 {
	int b;
	struct test1 z;
	int c;
};

int main()
{
	/* existing structure */
	struct test2 *obj;
	obj = malloc(sizeof(struct test2));
	if(obj == NULL){
		printf("Error: Memory not allocated...!\n");
	}
	printf("Malloc: %p\n", obj);
	obj->z.a = 51;
	obj->b = 43;
	obj->c = 53;
 
	/* pointer to existing entry */    
	struct test1 *obj1 = &obj->z;
	struct test2 *obj2 = container_of(obj1, struct test2, z);
	printf("container_of:%p : obj2->b = %d\n", obj2, obj2->b);
	printf("ofset of c: %ld\n",offsetof(struct test2, c));
	printf("ofset of a: %ld\n",offsetof(struct test1, a));
	return EXIT_SUCCESS;
}
