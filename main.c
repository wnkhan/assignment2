#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "handlestring.h"
#include "integer.h"
#include "bst.h"
#include "vbst.h"

int main(){

	vbst *a = newVBST(displayInteger,compareInteger);
	insertVBST(a, newInteger(10));
	
	displayVBST(stdout,a);

	return 0;
}
