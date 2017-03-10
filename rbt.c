#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "integer.h"
#include "rbt.h"
#include "bst.h"


int color(bstNode *n);
int LeftChild( bstNode *);
int RightChild(bstNode *);
bstNode *uncle(bstNode *n);
int LinearOrNah(bstNode *n);
void Rotate(bst *, bstNode *);
void insertionFixUp(bst *tree, bstNode *n);


typedef struct rbtVal
{
	void *value;
	int freq;
	int color;                              //0 for no color, 1 for black, and 2 for red
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
	fprintf(fp, "-%d", v->color);
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
	nodeVal->color = 1;
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

	if (redtree->tree->root == temp)
	{
		temp = insertBST(redtree->tree,newVal);
		redtree->size++;
		
		return;
	}

	if(findBST(redtree->tree,newVal))
	{
	
		((rbtVal *)(temp->value))->freq++;
	}
	else
	{
		newVal->color = 2;
		redtree->size++;
		temp = insertBST(redtree->tree,newVal);
		printf("going into insertion fix up\n");
		insertionFixUp(redtree->tree,temp);
	}
	redtree->words++;

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
	bstNode *p = NULL, *u = NULL, *g = NULL;
	bstNode *oldParent = NULL, *oldNode = NULL;
	while(1)
	{
		if (n==tree->root)
		{
			break;
		}
		p = n->parent;
		if (color(p)==1)
		{
			break;
		}
		u = uncle(n);
		g = n->parent->parent;

		if (color(u)==2) //uncle is red
		{
			((rbtVal *)(p->value))->color = 1;
			((rbtVal *)(u->value))->color = 1;
			((rbtVal *)(g->value))->color = 2;
			n = g;
		}
		else
		{
			if (!LinearOrNah(n))
			{
				oldParent = p;
				oldNode = n;
				printf("FIRST rotate\n");
				Rotate(tree,n);
				printf("FIRST rotate\n");
				n = oldParent;
				p = oldNode;
			}
			((rbtVal *)(p->value))->color = 1;
			((rbtVal *)(g->value))->color = 2;
			printf("SECOND rotate\n");
			Rotate(tree,p);
			printf("SECOND rotate finished\n");
			break;
		}
	}
	((rbtVal *)(tree->root->value))->color = 1;
}

int LeftChild(bstNode* n)
{
	bstNode *p = n->parent;
	if (p->left == n) return 1;
	else return 0;
}
int RightChild(bstNode* n)
{
	bstNode *p = n->parent;
	if (p->right == n) return 1;
	else return 0;
}

bstNode *uncle(bstNode *n)
{		

	if (n->parent == n->parent->parent->left)
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
	if (n == NULL) //No node
	{
		return 0;
	}

	if (((rbtVal *)(n->value))->color == 1)  //Black
	{
		return 1;
	}
	else  //Red node
	{
		return 2;
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
	bstNode *p = n->parent, *g = n->parent->parent;
	bstNode *nleft = n->left, *nright = n->right;

	if (n == p->right)
	{
		printf("rotate left\n");
		//This rotates left
		p->right = nleft;
		if (nleft != NULL)
		{
			nleft->parent = p;
		}
		n->left = p;
		//When parent was the root
		if (p == tree->root) //Made changes
		{
			n->parent = n;
			tree->root = n;
			p->parent = n;
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
		printf("end rotate left\n");
	}
	else
	{
		printf("rotate right\n");
		//This rotates right
		p->left = nright;
		if (nright != NULL)
		{
			nright->parent = p;
		}
		n->right = p;
		//When parent was the root
		if (p == tree->root)  //Made changes
		{
			n->parent = n;
			tree->root = n;
			p->parent = n;
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
		printf("end rotate right\n");
	}
}