#include <stdio.h>

#ifndef __REAL_INCLUDED__
#define __REAL_INCLUDED__

typedef struct real
    {
    double value;
    } real;

extern real *newReal(double);
extern double getReal(real *);
extern double setReal(real *,double);
extern void displayReal(FILE *,void *);


#endif
