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

	rbt *a = newRBT(displayInteger,compareInteger);
	insertRBT(a, newInteger(0));
	insertRBT(a, newInteger(1));
	insertRBT(a, newInteger(0));
	insertRBT(a, newInteger(8));
	insertRBT(a, newInteger(7));
	insertRBT(a, newInteger(9));
	insertRBT(a, newInteger(2));
	insertRBT(a, newInteger(4));
	insertRBT(a, newInteger(3));
	insertRBT(a, newInteger(5));
	insertRBT(a, newInteger(6));
	
	displayRBT(stdout,a);


	return 0;
}
