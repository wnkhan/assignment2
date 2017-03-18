#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdarg.h>
#include <string.h>
#include "strings.h"


str 
*newString(char *x)
    {
    str *p = malloc(sizeof(str));
    p->value = malloc(sizeof(strlen(x)));
    strcpy(p->value, x);
    return p;
    }

char 
*getString(str *v)
    {
    return v->value;
    }

char 
*setString(str *v,char *x)
    {
    char *old = malloc(sizeof(strlen(v->value)));
    strcpy(old,v->value);
    free(v->value);
    v->value = malloc(sizeof(strlen(x)));
    strcpy(v->value,x);
    return old;
    }

void 
displayString(FILE *fp,void *v)
    {
    fprintf(fp,"\"%s\"",getString((str *)v));
    }

