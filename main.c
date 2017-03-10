#include <stdio.h>
#include "handlestring.h"

int main()
{

	char dog[] = "d123o   ^&^   3452g";

	modifystring(dog);

	printf("%s\n",dog);
	
	return 0;
}