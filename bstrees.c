#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "bst.h"
#include "vbst.h"
#include "rbt.h"
#include "integer.h"
#include "string.h"
#include "comparator.h"
#include "handlestring.h"
#include "scanner.h"


#include "max_min.h"

int main(int argc,char *argv[])
{
	char *type = argv[1];
	char *data = argv[2];
//	char *commandName = argv[3];

	FILE *dataFile;	
//	FILE *commandFile;

	if (argc != 4)
	{
		printf("Not enough command line arguments\n");
	}

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
	
	switch(kind)
	{
		case vanilla: printf("Do vanilla stuff\n");
					vbst *vt = newVBST(displayString,stringComparator);
					char *word = pullString(dataFile);
					while(word != NULL)
					{
						modifystring(word);
						str *sword = newString(word);
						
						insertVBST(vt,sword);
						printf("%s\n", word);
						word = pullString(dataFile);
					}
					displayVBST(stdout,vt);
				break;

		case red_black: printf("Do red black stuff\n");
					rbt *rt = newRBT(displayString,stringComparator);
					word = pullString(dataFile);
					while(word != NULL)
					{
						modifystring(word);
						str *sword = newString(word);
						
						insertRBT(rt,sword);
						printf("%s\n", word);
						word = pullString(dataFile);
					}
					displayRBT(stdout,rt);
				break;
	}
	fclose(dataFile);

	return 0;
}
