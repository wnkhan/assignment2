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

	vbst *a = newVBST(displayInteger,compareInteger);
	insertVBST(a, newInteger(1));
	insertVBST(a, newInteger(0));
	insertVBST(a, newInteger(2));
	insertVBST(a, newInteger(3));
	insertVBST(a, newInteger(2));
	
	statisticsVBST(a,stdout);
	printf("\n");
	displayVBST(stdout,a);

	
	
	return 0;
}
