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
	char *commands = argv[3];

	FILE *dataFile;	
	FILE *commandFile;

	if (argc != 4)
	{
		printf("Not enough command line arguments\n");
	}

	enum treeType{vanilla,red_black} kind;

	vbst *vt = newVBST(displayString,stringComparator);
	rbt *rt = newRBT(displayString,stringComparator);
	char *word = NULL;

	if (strcmp(type,"-v")==0)
	{
		kind = vanilla;
		free(rt);
	}

	else
	{
		kind = red_black;
		free(vt);
	}

	dataFile = fopen(data,"r");
	switch(kind)  
	{
		case vanilla: 
		

			// printf("Do vanilla stuff\n"); 
			//Builds tree
			word = pullString(dataFile);
			while(word != NULL)
			{
				modifystring(word);
				str *sword = newString(word);
				
				insertVBST(vt,sword);
				// printf("%s\n", word);
				word = pullString(dataFile);
			}
			//Stops building tree

			//Executes commands

			commandFile = fopen(commands,"r");

			word = pullString(commandFile);
			while(word != NULL)
			{
				if (strcmp(word,"i")==0)
				{
					word = pullString(commandFile);
					modifystring(word);
					str *sword = newString(word);
					insertVBST(vt,sword);

				}
				else if(strcmp(word,"d")==0)
				{
					word = pullString(commandFile);
					str *sword = newString(word);
					deleteVBST(vt,sword);
				}
				
				else if (strcmp(word,"s")==0)
				{
					displayVBST(stdout,vt);
				}
				// else if (strcmp(word,"f")==0)
				// {
				// 	//Need to do this
				// }
				else
				{
					statisticsVBST(vt,stdout);
				}
				word = pullString(commandFile);
			}

			fclose(commandFile);  

			//Ends command execution
			break;
		

		case red_black: 
		

			// printf("Do red black stuff\n");
			//Builds tree
			word = pullString(dataFile);
			while(word != NULL)
			{
				modifystring(word);
				str *sword = newString(word);
				
				insertRBT(rt,sword);
				// printf("%s\n", word);
				word = pullString(dataFile);
			}
			//Stops building tree
			
			break;
		

		default:
			printf("Proper tree type not provided");
			break;
	}
	fclose(dataFile);


	
	return 0;
}
