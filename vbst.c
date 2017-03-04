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

static void displayVal(FILE *fp, void *val)
{
	vbstVal *v = val;
	v->display(fp,v->value);
	if (v->freq >1)
	{
		fprintf(stdout," -%d",v->freq);
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

	vtree->tree = newBST(displayVal,vbstCompare);
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
	
	if (findBST(vtree->tree,newVal))
	{
		((vbstVal *)(temp->value))->freq++;
		vtree->words++;
	}
	else
	{
		insertBST(vtree->tree,newVal);
		vtree->size++;
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
	temp = swapToLeafBSTNode(temp);
	pruneBSTNode(vtree->tree, temp);
	free(temp);
	free(newVal);
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
	statisticsBST(vtree->tree, fp);
}

void displayVBST(FILE *fp, vbst *vtree)
{
	displayBST(fp,vtree->tree);
}