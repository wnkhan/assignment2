#include <stdio.h>


#ifndef __STRING_INCLUDED__
#define __STRING_INCLUDED__

typedef struct str
    {
    char* value;
    } str;

extern str *newString(char*);
extern char* getString(str *);
extern char* setString(str *,char*);
extern void displayString(FILE *,void *);


#endif