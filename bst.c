#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "integer.h"
#include "bst.h"
#include "max_min.h"

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
	tree->size++;

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
	return NULL;
}

bstNode *swapToLeafBSTNode(bstNode *swap) 
{
	void *temp = NULL;
	bstNode *current = swap;

	if(swap->left == NULL && swap->right == NULL)
	{
		return swap;
	}
	else if (numberOfChildren(swap) == 2)
	{
	
		if(swap->left != NULL)
		{
			current = swap->left;
			while(current->right != NULL)
			{
				current = current ->right;
			}
			temp = current->value;
			current->value = swap->value;
			swap->value = temp;
			return swapToLeafBSTNode(current);
		}
		else
		{
			current = swap->right;
			while(current->left != NULL)
			{
				current = current ->left;
			}
			temp = current->value;
			current->value = swap->value;
			swap->value = temp;
			return swapToLeafBSTNode(current);
		}
	}	
	else
	{
		return swap;
	}	
}

void pruneBSTNode(bst *tree,bstNode *n)
{
	tree->size--;
	if (n->parent == NULL && n->right == NULL && n->left == NULL)
	{
		n = NULL;
	}
	else if (tree->root->right == NULL && tree->root->left == NULL && n == tree->root)  // n is a leaf
	{
		tree->root = tree->root->parent = NULL;
	}
	else if (n->left == NULL && n->right == NULL)
	{
		if (n->parent->right == n)
		{
			n->parent->right = NULL;
		}
		else if (n->parent->left == n)
		{
			n->parent->left = NULL;
		}
	}
	else
	{
		if (n->right != NULL)  //n has a right child
		{
			if (n == n->parent->right)  //n is a right child
			{
				n->parent->right = n->right;
				n->right = NULL;
			}
			else						//n is a left child
			{
				n->parent->left = n->right;
				n->right = NULL;
			}
		}
		else  //n has a left child
		{
			if (n == n->parent->right)  //n is a right child
			{
				n->parent->right = n->left;
				n->left = NULL;
			}
			else						//n is a left child
			{
				n->parent->left = n->left;
				n->left = NULL;
			}
		}
		
	}
}

int sizeBST(bst *tree) 
{ 
	return tree->size;
}

void statisticsBST(bst *tree,FILE *fp)
{
	bstNode *n = tree->root;

	int min = minDepth(n);
	int max = maxDepth(n);
	
	fprintf(fp, "Min depth = %d\n", min);
	fprintf(fp, "Max depth = %d\n", max);
	
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
				fprintf(fp, "=");
			}
//			else
//			{
//				fprintf(fp, "\"");
//			}

			tree->display(fp,n->value);

			if(n != tree->root)
			{
				fprintf(fp, "(");
				tree->display(fp,n->parent->value);

				if(tree->compare(n->value, n->parent->value)<0)
				{
					fprintf(fp, ")-l\t");
				}
				else
				{
					fprintf(fp, ")-r\t");
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

