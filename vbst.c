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

static void displayVal(FILE *fp, void *val)
{
	vbstVal *v = val;
	v->freq;
	v->display(fp,v->value);
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

void insertVBST(vbst *vtree,void *value)
{
	insertBST(vtree->tree,value);
}

void displayVBST(FILE *fp, vbst *vtree)
{
	displayBST(fp,vtree->tree);
}