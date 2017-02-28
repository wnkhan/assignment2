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
		if(tree->compare(x->value,Value)==0)
		{	
			return 1;
		}
		else if(tree->compare(Value,x->value) > 0 )
		{
			x = x->right;
		}
		else
		{
			x = x->left;
		}
	}
	return 0;
}

bstNode *findBSTNode(bst *tree,void *Value)
{

	bstNode *x = tree->root;
	
	while(x != NULL)
	{
		if(tree->compare(x->value,Value)==0)
		{	
			return x;
		}
		else if(tree->compare(Value,x->value) > 0 )
		{
			x = x->right;
		}
		else
		{
			x = x->left;
		}
	}
	return 0;
}

bstNode *swapToLeafBSTNode(bstNode *swap)
{
	void *temp = NULL;
	bstNode *current = swap;

	if(swap->left == NULL && swap->right == NULL)
	{
		return swap;
	}
	else if(swap->right != NULL)
	{
		current = swap->right;
		while(current->left != NULL)
		{
			current = current ->left;
		}
		temp = current->value;
		current->value = swap->value;
		swap->value = temp;
		return current;
	}
	else
	{
		current = swap->left;
		while(current->right != NULL)
		{
			current = current ->right;
		}
		temp = current->value;
		current->value = swap->value;
		swap->value = temp;
		return current;
	}
}

void pruneBSTNode(bstNode *n)
{
	if(n->right == NULL && n->left == NULL)
	{
		if (n->parent->right == n)
		{
			n->parent->right = NULL;
		}
		else
		{
			n->parent->left = NULL;
		}
	}
	else
	{
		n = swapToLeafBSTNode(n);
		pruneBSTNode(n);
	}	
}

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