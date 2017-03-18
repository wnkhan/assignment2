#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"
#include "handlestring.h"
#include "integer.h"
#include "bst.h"
#include "vbst.h"
#include "rbt.h"
#include "max_min.h"

int main(int argc,char *argv[])
{
	char *type = argv[1];
	char *data = argv[2];
	char *commandName = argv[3];

	FILE *dataFile;
	FILE *commandFile;

	enum treeType{vanilla,red_black} kind;

	printf("%s\n", argv[1]);

	if (strcmp(type,"-v")==0)
	{
		kind = vanilla;
	}

	else
	{
		kind = red_black;
	}

	dataFile = fopen(data,"r");
	char *read = NULL;
	char *quote = "\"";
	switch(kind)
	{
		case 0: printf("Do vanilla stuff\n");
				int count = 0;
				while(read = readToken(dataFile))
				{
					
				
				}
				break;

		case 1: printf("Do red black stuff\n");

				break;
	}
	fclose(dataFile);

	return 0;
}
