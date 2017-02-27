#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "strings.h"
#include "comparator.h"
#include "integer.h"
#include "real.h"

int intComparator(void *v1, void *v2)
{
	int a = getInteger(v1);
	int b = getInteger(v2);

	//printf("a = %d, b = %d\n", a,b);

	if(a > b)
	{
		return 1; 
	}
	else if(a < b)
	{
		return -1;
	}
	else if(a == b)
	{
		return 0;
	}
	return 0;
}

int realComparator(void *v1, void *v2)
{
	double a = getReal(v1);
	double b = getReal(v2);

	//printf("a = %1f, b = %1f\n", a,b);

	if(a > b)
	{
		return 1; 
	}
	else if(a < b)
	{
		return -1;
	}
	else if(a == b)
	{
		return 0;
	}
	return 0;
}

int stringComparator(void *v1, void *v2)
{
	char *a = getString(v1);
	char *b = getString(v2);

	//printf("%s \t %s\n", a,b);

	int val = strcmp(a,b);
	
	return val;
}