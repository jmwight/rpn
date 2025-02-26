#include "calc.h" // project header
#include <ctype.h>
#include <string.h> // for strcmp which is required to see if typed letters matches a function (i.e. sin, cos, log, etc)
#include <stdio.h> // for EOF definition
#include <stdlib.h> // for atof

#define MAXNUMLEN	30 //TODO: DETERMINE IF THIS IS A GOOD NUMBER OF NOT
#define FUNCNAMEMAXLEN	4

/* getop: returns next operator type or numeric operand. If it's numeric number will be added to *num pointer */
int getop(char *arg, double *num)
{
    char numstr[MAXNUMLEN];
    char *numstr_pos = numstr;

    /* find if it's not a digit or a decimal */
    if(!isdigit(*arg) && *arg != '.')
    {
        if((*arg == '-' || *arg == '+') && isdigit(arg[1]))
        {
            *numstr_pos = *arg;
	    	++arg;
	    	++numstr_pos;
        }
        /* to detect if letters for functions */
        else if(isalpha(arg[0]) && isalpha(arg[1]))
        {
            char func[FUNCNAMEMAXLEN + 1]; // to store name of mathematical function i.e. sin, log, etc.
			int fi = 0;
            while(isalpha(*arg)) // get the rest of the letters
	    	{
				*(func+fi++) = *arg; //REDFLAG
				//func[fi++] = *arg;
				++arg;
	    	}
            func[fi] = '\0';

            /* go through and see if the letters match up to one of the functions */
            if(strcmp(func, "sin") == 0) // strcmp = 0 when the strings are equal
                return SIN;
            else if(strcmp(func, "cos") == 0)
                return COS;
            else if(strcmp(func, "tan") == 0)
                return TAN;
            else if(strcmp(func, "asin") == 0)
                return ASIN;
            else if(strcmp(func, "acos") == 0)
                return ACOS;
            else if(strcmp(func, "atan") == 0)
                return ATAN;
            else if(strcmp(func, "exp") == 0)
                return EXP;
            else if(strcmp(func, "log") == 0)
                return LOG;
            else if(strcmp(func, "sqrt") == 0)
                return SQRT;
            else if(strcmp(func, "ceil") == 0)
                return CEIL;
            else if(strcmp(func, "flr") == 0 || strcmp(func, "floor"))
                return FLOOR;
            else if(strcmp(func, "abs") == 0)
                return ABS;
            else
                printf("error: unrecognized function.\n");
        } 
        else
        {
            return *arg; /* not a number hopefully an operand which we will test for in the big switch in main */
        }
    }

    /* collects number */
    /* collect integer part */
    while(isdigit(*arg))
	{
		*numstr_pos = *arg;
		++arg;
		++numstr_pos;
	}	
    if(*arg == '.')
		while(isdigit(*++arg))
		{
            *numstr_pos = *arg;
			++numstr_pos;
		}
    *numstr_pos = '\0';

    *num = atof(numstr);

    return NUMBER; // success that we found a number and not something else like operand for instance
}
