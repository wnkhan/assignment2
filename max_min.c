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