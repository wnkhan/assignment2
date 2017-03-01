#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "handlestring.h"
#include "integer.h"
#include "bst.h"

int main(){

	bst *a = newBST(displayInteger,compareInteger);
	insertBST(a, newInteger(1));
	insertBST(a, newInteger(0));
	insertBST(a, newInteger(8));
	insertBST(a, newInteger(7));
	insertBST(a, newInteger(9));
	insertBST(a, newInteger(2));
	insertBST(a, newInteger(4));
	insertBST(a, newInteger(3));
	insertBST(a, newInteger(5));
	insertBST(a, newInteger(6));
	displayBST(stdout,a);
	statisticsBST(a,stdout);
	bstNode *b = findBSTNode(a,newInteger(4));
	swapToLeafBSTNode(b);
	pruneBSTNode(b);
	displayBST(stdout,a);
	statisticsBST(a,stdout);

	
	return 0;
}
