#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rbt.h"
#include "bst.h"

typedef struct rbtVal
{
	void *value;
	int freq;
	char color;
	void (*display)(FILE *, void *);
    int (*comp)(void *, void *);
} rbtVal;

static void displayRBTVal(FILE *fp, void *val)
{
	rbtVal *v = val;
	v->display(fp,v->value);
	if (v->freq >1)
	{
		fprintf(fp," -%d",v->freq);
	}
	fprintf(fp, "-%c", v->color);
}

static int compareRBTVal(void *a, void *b)
{
	rbtVal *A = a;
	rbtVal *B = b;
	return A->comp(A->value,B->value);
}

rbtVal *newRBTVal(void (*d)(FILE *,void *),int (*c)(void *,void *))
{
	rbtVal *nodeVal= malloc(sizeof(rbtVal));
	nodeVal->value = NULL;
	nodeVal->freq = 1;
	nodeVal->color = 'B';
	nodeVal->display = d;
	nodeVal->comp = c;
	return nodeVal;
}

rbt *newRBT(void (*d)(FILE *,void *),int (*c)(void *,void *))
{
	rbt *redtree = malloc(sizeof(rbt));

	redtree->tree = newBST(displayRBTVal, compareRBTVal);
	redtree->display = d;
	redtree->compare = c;
	redtree->size = 0;
	redtree->words = 0;
	return redtree;
}

void insertRBT(rbt *redtree,void *v)
{
	rbtVal *newVal = newRBTVal(redtree->display,redtree->compare);
	newVal->value = v;
	bstNode *temp = findBSTNode(redtree->tree,newVal);

	if (findBST(redtree->tree,newVal))
	{
		((rbtVal *)(temp->value))->freq++;
		redtree->words++;
	}
	else
	{
		insertBST(redtree->tree,newVal);
		redtree->size++;
	}

}