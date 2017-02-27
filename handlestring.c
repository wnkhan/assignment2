#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "handlestring.h"


void modifystring(char *s)
{
	int size = strlen(s);
	int i = 0;
	
	for (i=0; i < size; ++i)
	{
		if(isupper(s[i]))
		{
			s[i] = s[i] + 32;
		}
		else if(isspace(s[i]))
		{
			memmove(s+i,s+(i+1),size-i);
			i--;
		}
		else if(ispunct(s[i]))
		{
			memmove(s+i,s+(i+1),size-i);
			i--;
		}
	}
}

char* modifyphrase(char *s)
{
	int size = strlen(s);
	int i = 0;
	char *temp = NULL;
	char *temp1 = NULL;
	char *space = " ";
	
	
	for (i=0; i < size; ++i)
	{
		if(isupper(s[i]))
		{
			s[i] = s[i] + 32;
		}
		else if(isspace(s[i]))
		{
			
			int count = i;
			while(isspace(s[count]))
			{
				count++;
			}
			temp = malloc(sizeof(strlen(s)-strlen(s+i)));
			strncpy(temp, s, i);

			temp1 = malloc(sizeof(strlen(s+count)));
			strncpy(temp1, s+count, strlen(s+count));

			s = malloc(sizeof(strlen(temp1)+strlen(temp)));
			strcpy(s,temp);
			strcat(s,space);
			strcat(s,temp1);

		}
		else if(ispunct(s[i]))
		{
			memmove(s+i,s+(i+1),size-i);
			i--;
		}
		size = strlen(s);
	}
	return s;
}

