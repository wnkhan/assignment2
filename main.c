#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "handlestring.h"
#include "integer.h"
#include "bst.h"

int main(){

	bst *a = newBST(displayInteger,compareInteger);
	insertBST(a, newInteger(20));
	insertBST(a, newInteger(7));
	insertBST(a, newInteger(5));
	insertBST(a, newInteger(15));
	insertBST(a, newInteger(3));
	insertBST(a, newInteger(6));
	insertBST(a, newInteger(12));
	insertBST(a, newInteger(17));
	insertBST(a, newInteger(40));
	insertBST(a, newInteger(30));
	insertBST(a, newInteger(50));
	insertBST(a, newInteger(25));
	insertBST(a, newInteger(35));
	insertBST(a, newInteger(45));
	insertBST(a, newInteger(55));
	
	
	displayBST(stdout,a);
	printf("Size is %d\n", sizeBST(a));
	printf("\n");
	
	bstNode *b = findBSTNode(a,newInteger(20));
	b = swapToLeafBSTNode(b);
	pruneBSTNode(a,b);

	b = findBSTNode(a,newInteger(7));
	b = swapToLeafBSTNode(b);
	pruneBSTNode(a,b);

	b = findBSTNode(a,newInteger(5));
	b = swapToLeafBSTNode(b);
	pruneBSTNode(a,b);

	printf("Node to be removed ");
	a->display(stdout,b->value);
	printf("\nNew root: ");
	a->display(stdout,a->root->value);
	printf("\n\n");

	displayBST(stdout,a);
	printf("Size is %d\n", sizeBST(a));
	statisticsBST(a,stdout);

	
	return 0;
}
