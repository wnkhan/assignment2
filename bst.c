#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "integer.h"
#include "bst.h"

bst *newBST(void (*d)(FILE *,void *),int (*c)(void *,void *))
{
	bst *tree = malloc(sizeof(bst));

	tree -> display = d;
	tree -> compare = c;
	tree -> root = NULL;

	return tree;
}

bstNode *insertBST(bst *tree, void *Value)
{
	//New Node
	bstNode *z = malloc(sizeof(bstNode));
	z->value = Value;
	z->left = z->right = NULL;

	//Nodes for traversal of tree
	bstNode *x = tree -> root;  //X is current node
	bstNode *y = NULL;			//Y is parent node 

	while(x != NULL)
	{
		y = x;
		if(tree->compare(x->value, z->value)>0)
		{
			x = x->left;
		}
		else
		{
			x = x -> right;
		}
	}
	z->parent = y;
	if (y==NULL)
	{
		tree->root = z;
		z->parent = z;
	}
	else if (tree->compare(y->value,z->value) > 0)
	{
		y->left = z;
	}
	else
	{
		y->right = z;
	}

	return z;
}

int findBST(bst *tree,void *Value)
{

	bstNode *x = tree->root;
	
	while(x != NULL)
	{
		tree->display(stdout,x->value);
		printf(" ");
		tree->display(stdout,Value);
		printf("\n");
		if(x->value == Value)
		{
			printf("I'm in\n");
			return 1;
		}
		else if(tree->compare(Value,x->value) > 0 )
		{
			x = x->right;
			printf("Going right\n");
			tree->display(stdout,x->value);
			printf("\n");
		}
		else
		{
			printf("Going left\n");
			x = x->left;
		}
	}
	return 0;
}

// void pruneBSTNode(bstNode *n)
// {
// 	if(tree->compare(n->value,n->parent->value) > 0 )
// 	{
// 		n->parent->right == NULL;
// 		free(n);
// 	}
// 	else
// 	{
// 		n->parent->left == NULL;
// 		free(n);
// 	}
// }

void displayBST(FILE *fp,bst *tree) { //displays tree, calls display function to display node value
	if(tree->root == NULL) return;

	bstNode *n = malloc(sizeof(bstNode));
	queue *q = newQueue(tree->display);
	int level = 0, begin = 0;
	enqueue(q,tree->root);
	enqueue(q,NULL);

	fprintf(fp, "%d: ", level);

	while(sizeQueue(q) != 0) {
		n = dequeue(q);
		if(sizeQueue(q) == 0) {
			fprintf(fp, "\n");
			break;
		}
		else if(n == NULL) {
			fprintf(fp, "\n");
			enqueue(q,NULL);
			level++;
			begin = 1;
		}
		else {
			if(begin >0)
			{
				fprintf(fp, "%d: ", level);
			}
			if(n->right==NULL && n->left==NULL)
			{
				fprintf(fp, "=\"");
			}
			else
			{
				fprintf(fp, "\"");
			}
			tree->display(fp,n->value);
			fprintf(fp, "\"");
			if(n != tree->root)
			{
				fprintf(fp, "(\"");
				tree->display(fp,n->parent->value);

				if(tree->compare(n->value, n->parent->value)<0)
				{
					fprintf(fp, "\")-l\t");
				}
				else
				{
					fprintf(fp, "\")-r\t");
				}
			}
			else
			{
				fprintf(fp, "(");
				tree->display(fp,n->parent->value);
				fprintf(fp, ")-\t");
			}
			
			if(n->left != NULL) enqueue(q,n->left);
			if(n->right != NULL) enqueue(q,n->right);
			begin = 0;
		}
	}
}