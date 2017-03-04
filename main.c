#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "handlestring.h"
#include "integer.h"
#include "bst.h"
#include "vbst.h"
#include "max_min.h"

int main(){

	bst *a = newBST(displayInteger,compareInteger);
	insertBST(a, newInteger(5));
	insertBST(a, newInteger(4));
	insertBST(a, newInteger(2));
	insertBST(a, newInteger(3));
	insertBST(a, newInteger(1));
	insertBST(a, newInteger(18));

	bstNode *temp = findBSTNode(a,newInteger(4));
	temp = swapToLeafBSTNode(temp);
	pruneBSTNode(a,temp);

	displayBST(stdout,a);
	statisticsBST(a,stdout);
	
	
	return 0;
}
