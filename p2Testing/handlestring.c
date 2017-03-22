#include "handlestring.h"

//Was having trouble with modifying the strings
//and was directed to a link for a stack overflow
//webpage that helped with modifying strings.
//The modifystring() function is a result of
//that code.
void modifystring(char *p)
{
    char *src = p, *dst = p;

    while (*src)
    {
    	if (isspace((unsigned char)*src))
    	{
    		while(isspace((unsigned char)*src))
    		{
    			src++;
    		}
    		*dst++ = ' ';
    	}
       else if (!isalpha((unsigned char)*src) )
       {
          /* Skip this character */
          src++;
       }
       else if (isupper((unsigned char)*src))
       {
          /* Make it lowercase */
          *dst++ = tolower((unsigned char)*src);
          src++;
       }
       else if (src == dst)
       {
          /* Increment both pointers without copying */
          src++;
          dst++;
       }
       else
       {
          /* Copy character */
          *dst++ = *src++;
       }
    }

    *dst = 0;
}



char *pullString(FILE *fp)
{
	char *read=NULL;
	if (stringPending(fp))
	{

		read = readString(fp);
 
		modifystring(read);

	}
	else
	{
		
		read = readToken(fp);

		if (read!=NULL)
		{
			modifystring(read);
		}
		
		
	}
	return read;
}