#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "handlestring.h"
#include "integer.h"
#include "bst.h"
#include "vbst.h"
#include "rbt.h"
#include "max_min.h"

int main(){

	bst *a = newBST(displayInteger,compareInteger);
	insertBST(a, newInteger(1));
	insertBST(a, newInteger(0));
	insertBST(a, newInteger(2));
	insertBST(a, newInteger(3));
	insertBST(a, newInteger(2));
	displayBST(stdout,a);
	bstNode *b = findBSTNode(a,newInteger(1));
	b = swapToLeafBSTNode(b);
	pruneBSTNode(a,b);

	printf("\n");
	displayBST(stdout,a);

	
	
	return 0;
}
