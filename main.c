#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "handlestring.h"
#include "integer.h"
#include "bst.h"

int main(){

	bst *a = newBST(displayInteger,compareInteger);
	insertBST(a, newInteger(10));
	insertBST(a, newInteger(2));
	insertBST(a, newInteger(5));
	insertBST(a, newInteger(3));
	insertBST(a, newInteger(6));
	insertBST(a, newInteger(4));
	insertBST(a, newInteger(11));
	insertBST(a, newInteger(12));
	displayBST(stdout,a);
	
	statisticsBST(a,stdout);



	
	return 0;
}
