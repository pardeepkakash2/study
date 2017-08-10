struct data {
    int something;
};

struct container {
    int something_before;
    struct data data_item;
    int something_after;
};

Assume you have a pointer to a struct data value:

struct data *data_ptr;

The list_entry() macro helps you to convert data_ptr to a pointer to the struct container value that holds the struct data value, pointed to by ptr:

struct container *cont_ptr = list_entry(data_ptr, struct container, data_item);

The macro works by computing the offset of data_item inside the struct container, and subtracting that many bytes from the data_ptr pointer. This, when cast to struct container *, gives a valid pointer to the struct container that holds this particular struct data "inside".

The macro can also be simplified a bit by using the builtin offsetof() macro:

#define list_entry(ptr, type, member) \
    ((type *)((char *)(ptr) – offsetof(type, member)))
