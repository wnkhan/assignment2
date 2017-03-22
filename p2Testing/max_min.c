#include <stdio.h>
#include "bst.h"

int maxDepth(bstNode *node)
{
	if(node == NULL)
	{
		return 0;
	}
	else
	{
		int ld = maxDepth(node->left);
		int rd = maxDepth(node->right);

		if (ld > rd)
		{
			return (ld+1);
		}
		else 
		{
			return (rd+1);
		}
	}
}

int minDepth(bstNode *node)
{
	if(node == NULL)
	{
		return 0;
	}
	else
	{
		int ld = minDepth(node->left);
		int rd = minDepth(node->right);

		if (ld < rd)
		{
			return (ld+1);
		}
		else 
		{
			return (rd+1);
		}
	}
}

int numberOfChildrenToParent(bstNode *n)
{
	if (n == n->parent) //Node is root
	{
		return -1;
	}
	else if(n == n->parent->left) // Node is left child
	{
		if (n->parent->right == NULL)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	else
	{
		if(n->parent->left == NULL)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
}

int numberOfChildren(bstNode *n)
{
	if (n->left != NULL && n->right != NULL)
	{
		return 2;
	}
	else if (n->left != NULL)
	{
		return 1;
	}
	else if (n->right != NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}