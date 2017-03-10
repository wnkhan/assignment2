#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "integer.h"
#include "rbt.h"
#include "bst.h"


int color(bstNode *n);
bstNode *uncle(bstNode *n);
int LinearOrNah(bstNode *n);
void Rotate(bst *, bstNode *);
void insertionFixUp(bst *tree, bstNode *n);


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
		temp = insertBST(redtree->tree,newVal);
		newVal->color = 'R';
		redtree->size++;
	}
	 insertionFixUp(redtree->tree, temp);
}

int sizeRBT(rbt *rtree)
{
	return rtree->size;
}

void displayRBT(FILE *fp,rbt *redtree)
{
	displayBST(fp,redtree->tree);
}

void insertionFixUp(bst *tree, bstNode *n)
{	
	while(1)
	{

		if (n==tree->root)
		{
			return;
		}
		if (color(n->parent)==1)
		{
			return;
		}
		if (uncle(n) && color(uncle(n))==-1) //uncle is red
		{
			((rbtVal *)(n->parent->value))->color = 'B';
			((rbtVal *)(uncle(n)->value))->color = 'B';
			((rbtVal *)(n->parent->parent->value))->color = 'B';
			n = n->parent->parent;
		}
		else
		{
			if (!LinearOrNah(n))
			{
				Rotate(tree,n);
			}
			((rbtVal *)(n->parent->value))->color = 'B';
			((rbtVal *)(n->parent->parent->value))->color = 'R';
			Rotate(tree,n->parent);
			return;
		}
	}
	((rbtVal *)(tree->root))->color = 'B';
}

bstNode *uncle(bstNode *n)
{		
	if (n->parent == n)
	{
		return NULL;
	}
	else if (n->parent == n->parent->parent)
	{
		return NULL;
	}
	else if (n->parent == n->parent->parent->left)
	{
		return n->parent->parent->right;
	}
	else
	{
		return n->parent->parent->left;
	}
}

int color(bstNode *n)  //Color is not working on root
{
	if (n == 0) //No node
	{
		return 0;
	}

	if (((rbtVal *)(n->value))->color == 'B')  //Black
	{
		return 1;
	}
	else  //Red node
	{
		return -1;
	}
}

int LinearOrNah(bstNode *n)
{
	if (n==n->parent->left && n->parent == n->parent->parent->left)
	{
		return 1;
	}
	else if(n==n->parent->right && n->parent == n->parent->parent->right)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

void Rotate(bst *tree, bstNode *n)
{
	if (n == n->parent->right)
	{
		//This rotates left
		n->parent->right = n->left;
		if (n->left)
		{
			n->left->parent = n->parent;
		}
		n->left = n->parent;
		//When parent was the root
		if (n->parent == tree->root) //Made changes
		{
			n->parent = n;
			tree->root = n;
		}
		//when parent is not the root
		else
		{
			n->parent = n->left->parent;
			n->left->parent = n;
			if (n->parent->left==n->left)
			{
				n->parent->left = n;
			}
			else
			{
				n->parent->right = n;
			}
		}
	}
	else
	{
		//This rotates right
		n->parent->left = n->right;
		if (n->right)
		{
			n->right->parent = n->parent;
		}
		n->right = n->parent;
		//When parent was the root
		if (n->parent == tree->root)  //Made changes
		{
			n->parent = n;
			tree->root =n;
		}
		//when parent is not the root
		else
		{
			n->parent = n->right->parent;
			n->right->parent = n;
			if (n->parent->left==n->right)
			{
				n->parent->left = n;
			}
			else
			{
				n->parent->right = n;
			}
		}
	}
}