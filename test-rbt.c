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
	insertRBT(a, newInteger(1));
	insertRBT(a, newInteger(2));
	insertRBT(a, newInteger(3));
	insertRBT(a, newInteger(-1));
	insertRBT(a, newInteger(-2));
	insertRBT(a, newInteger(-3));
	insertRBT(a, newInteger(6));
	
	displayRBT(stdout,a);


	return 0;
}
