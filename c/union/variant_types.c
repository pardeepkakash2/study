#include <stdio.h>

typedef enum { DOUBLE, INTEGER, UNKNOWN } type_t;
typedef struct {
	type_t type;
	union {
		double d;
		int    i;
	} value;
} value_t;

void display(const value_t *val)
{
	switch (val->type) {
		case DOUBLE:  printf("%f\n", val->value.d); break;
		case INTEGER: printf("%d\n", val->value.i); break;
		default: fputs("Unrecognized type\n", stderr); break;
		}
}
int main(void)
{
	value_t val = {DOUBLE, {1.2}};
        
	display(&val);
        
	val.type = INTEGER;
	val.value.i = 22;
        
	display(&val);
        
        return 0;
}
