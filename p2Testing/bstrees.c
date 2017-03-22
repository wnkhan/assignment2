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
	char *out = argv[4];

	FILE *dataFile = NULL;	
	FILE *commandFile = NULL;
	FILE *outFile = NULL;

	if (argc < 4)
	{
		printf("Not enough command line arguments\n");
	}
	else if(argc == 5)
	{
		outFile = fopen(out,"w");
	}
	else
	{
		outFile = stdout;
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
				str *sword = newString(word);
				if (strcmp(word,"") != 0)
					{
						insertVBST(vt,sword);
					}
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
					str *sword = newString(word);
					if (strcmp(word,"") != 0)
					{
						insertVBST(vt,sword);
					}
				}
				else if(strcmp(word,"d")==0)
				{
					word = pullString(commandFile);
					str *sword = newString(word);
					if (findVBST(vt,sword))
					{
						deleteVBST(vt,sword);
					}
					else
					{
						fprintf(stderr, "Value %s not found.\n", getString(sword));
					}
				}
				
				else if (strcmp(word,"s")==0)
				{
					displayVBST(outFile,vt);
				}
				else if (strcmp(word,"f")==0)
				{
					word = pullString(commandFile);
					str *sword = newString(word);
	
					fprintf(outFile, "Frequency of ");

					displayString(outFile,sword);
					fprintf(outFile, ": %d\n", findVBST(vt,sword));
				}
				else
				{
					statisticsVBST(vt,outFile);
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
				str *sword = newString(word);
				if (strcmp(word,"") != 0)
					{
						insertRBT(rt,sword);
					}
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
					
					str *sword = newString(word);
					if (strcmp(word,"") != 0)
					{
						insertRBT(rt,sword);
					}


				}
				else if(strcmp(word,"d")==0)
				{
					word = pullString(commandFile);
					str *sword = newString(word);
					deleteRBT(rt,sword);
				}
				
				else if (strcmp(word,"s")==0)
				{
					displayRBT(outFile,rt);
				}
				else if (strcmp(word,"f")==0)
				{
					word = pullString(commandFile);
					str *sword = newString(word);
	
					fprintf(outFile, "Frequency of ");

					displayString(outFile,sword);
					fprintf(outFile, ": %d\n", findRBT(rt,sword));
				}
				else
				{
					statisticsRBT(rt,outFile);
				}
				word = pullString(commandFile);
			}

			fclose(commandFile);  

			//Ends command execution
			break;
		

		default:
			printf("Proper tree type not provided");
			break;
	}
	fclose(dataFile);
	if (argc == 5)
	{
		fclose(outFile);
	}


	
	return 0;
}
