#ifndef OUR_GLOB_SYMS_H
#define OUR_GLOB_SYMS_H
 
#ifdef __KERNEL__
#include <linux/device.h>
 
extern struct class *cool_cl;
extern struct class *get_cool_cl(void);
#endif
 
#endif
