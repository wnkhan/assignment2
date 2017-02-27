#include <stdio.h>

#ifndef __COMPARATOR_INCLUDED__
#define __COMPARATOR_INCLUDED__

typedef int (*Comparator)(void*,void*);

extern int intComparator(void *v1, void *v2);
extern int realComparator(void *v1, void *v2);
extern int stringComparator(void *v1, void *v2);

#endif