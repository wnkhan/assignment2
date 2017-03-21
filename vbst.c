#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "integer.h"
#include "bst.h"
#include "vbst.h"
#include "max_min.h"

typedef struct vbstVal
    {
        void *value;
        int freq;
        void (*display)(FILE *, void *);
        int (*comp)(void *, void *);
    } vbstVal;

vbstVal *newVBSTVal(void (*d)(FILE *,void *),int (*c)(void *,void *))
{
	vbstVal *nodeVal= malloc(sizeof(vbstVal));
	nodeVal->value = NULL;
	nodeVal->freq = 1;
	nodeVal->display = d;
	nodeVal->comp = c;
	return nodeVal;
}

static void vbstDisplay(FILE *fp, void *val)
{
	vbstVal *v = val;
	// fprintf(fp, "\"");
	v->display(fp,v->value);
	// fprintf(fp, "\"");
	if (v->freq >1)
	{
		fprintf(fp,"-%d",v->freq);
	}

}

static int vbstCompare(void *a, void *b)
{
	vbstVal *A = a;
	vbstVal *B = b;
	return A->comp(A->value,B->value);
}

vbst *newVBST(void (*d)(FILE *,void *),int (*c)(void *,void *))
{
	vbst *vtree = malloc(sizeof(vbst));

	vtree->tree = newBST(vbstDisplay,vbstCompare);
	vtree->display = d;
	vtree->compare = c;
	vtree->size = 0;
	vtree->words = 0;
	return vtree;
}

void insertVBST(vbst *vtree,void *v)
{
	vbstVal *newVal = newVBSTVal(vtree->display,vtree->compare);
	newVal->value = v;
	bstNode *temp = findBSTNode(vtree->tree, newVal);
	
	if (temp!=NULL)
	{
		((vbstVal *)(temp->value))->freq++;
		vtree->words++;
	}
	else
	{
		insertBST(vtree->tree,newVal);
		vtree->size++;
		vtree->words++;
	}
}

int findVBST(vbst *vtree,void *v)
{
	vbstVal *sought = newVBSTVal(vtree->display,vtree->compare);
	sought->value = v;
	if (findBSTNode(vtree->tree,sought))
	{
		free(sought);
		return 1;
	}
	else
	{
		free(sought);
		return 0;
	}
}

void deleteVBST(vbst *vtree, void *v)
{
	vbstVal *newVal = newVBSTVal(vtree->display,vtree->compare);
	newVal->value = v;
	bstNode *temp = findBSTNode(vtree->tree, newVal);

	if (temp == NULL)
	{
		printf("Value \"");	
		vbstDisplay(stdout,newVal->value);
		printf("\"");
		printf(" not found\n");
	}
	else if (((vbstVal *)(temp->value))->freq>1)
	{
		((vbstVal *)(temp->value))->freq--;
		vtree->words--;
	}
	else
	{
		temp = swapToLeafBSTNode(temp);
		pruneBSTNode(vtree->tree, temp);
		// free(temp);
		// free(newVal);
		vtree->words--;
		vtree->size--;
	}
}

int sizeVBST(vbst *vtree)
{
	return vtree->size;
}

int wordsVBST(vbst *vtree)  //Fix Me!!!!
{
	return vtree->words;
}
void statisticsVBST(vbst *vtree, FILE *fp)
{
	fprintf(fp,"Words/Phrases: %d\n", vtree->words);
	fprintf(fp,"Nodes: %d\n", vtree->size);
	statisticsBST(vtree->tree,fp);

}

void displayVBST(FILE *fp, vbst *vtree)
{
	displayBST(fp,vtree->tree);
}