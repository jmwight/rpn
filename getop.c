#include "calc.h" // project header
#include <ctype.h>
#include <string.h> // for strcmp which is required to see if typed letters matches a function (i.e. sin, cos, log, etc)
#include <stdio.h> // for EOF definition

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    static int c; /* to preserve the current character thus eliminating the need for 8 */
    int i, c_nxt, is_cust_var;
    is_cust_var = 0;
    char var;

    /* skip all the empty space */
    while((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0'; // to end the string if necessary
    i = 0;

    /* find if it's not a digit or a decimal */
    if(!isdigit(c) && c != '.')
    {
        /* first check if '\n'. If it is we have reached the end of the input buffer and running getch will open another buffer */
        if(c == '\n')
            return c;
        else
            c_nxt = getch();

        /* there is no next character it's just a statement such as 2 3 + */
        if(c_nxt == EOF || c_nxt == '\n' || c_nxt == ' ')
        {
            char c_cur = c;
            c = c_nxt;
            //ungetch(c_nxt);
            return c_cur;
        }
        /* see if its a postive or negative sign followed by a number or decimal */
        if((c == '-' || c == '+') && isdigit(c_nxt))
        {
            s[++i] = c_nxt;
            c = c_nxt;
        }
        /* to detect if letters for functions */
        else if(isalpha(c) && isalpha(c_nxt))
        {
            char func[6]; // to store name of mathematical function i.e. sin, log, etc.
            func[0] = tolower(c);
            func[1] = tolower(c_nxt);
            int j = 2;
            while(isalpha(c = getch())) // get the rest of the letters
                func[j++] = tolower(c);
            //ungetch(c);
            func[j] = '\0';

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
        /* we are setting a variable */
        else if(isalpha(c) && c_nxt == '=')
        {
            if(c >= 'a' && c <= 'z')
            {
                var = c;
                is_cust_var = 1; // boolean for we have a custom variable
                if((c = getch()) == EOF || c == '\n' || c == ' ')
                {
                    //ungetch(c);
                }
                else
                {
                    s[0] = c;
                }
            }
            else
            {
                printf("error: variable must be a-z (no capitals)\n");
                is_cust_var = 0;
            }
        }
        else
        {
            return c; /* not a number hopefully an operand which we will test for in the big switch in main */
        }
    }

    /* collects number */
    if(isdigit(c)) /* collect integer part */
        while(isdigit(c = getch()))
            s[++i] = c;
    if(c == '.')
        while(isdigit(c = getch()))
            s[++i] = c;

    /* we append the character at the end of the number string if we are setting a variable. We will unpack
     * this in main */
    if(is_cust_var)
    {
        s[++i] = var;
        s[++i] = '\0';
        return VAR;
    }

    s[++i] = '\0';

    //if(c != EOF)
        //ungetch(c); // we went too far rewind by adding it to the separate memory buffer we check first
    return NUMBER; // success that we found a number and not something else like operand for instance
}
