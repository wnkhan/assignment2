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
	insertVBST(a, newInteger(3));
	insertVBST(a, newInteger(2));
	insertVBST(a, newInteger(4));
	displayVBST(stdout,a);
	printf("%d size \n", wordsVBST(a));
	return 0;
}
