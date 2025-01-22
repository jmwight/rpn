#include "calc.h"
#include <stdio.h>
#include <stdlib.h> /* for atof() */
#include <math.h> // math functions like sin, sqrt, log etc.
#include <string.h> // for strlen

//#define CUSTVARMAX	26

int cust_var[CUSTVARMAX];

/* reverse Polish calculator */
int main()
{
    int type, type_prev;
    type_prev = -1;
    double op2;
    char s[MAXOP];

    while((type = getop(s)) != EOF)
    {
        switch(type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            op2 = pop();
            if(op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            push((int)pop() % (int)op2);
            break;
        case '\n':
            if(type_prev == type)
                printf("\t%.8g\n", pop());
                break;
        /** Stack operations. Key:
          * '?' = bringing up last thing on the stack,
          * '!' = clearing the stack
          *'@' = swapping last two operands on the stack **/
        case '?':
            ptop();
            break;
        case '!':
            clrstack();
            break;
        case '@':
            swaptop();
            break;
        /* mathematical functions */
        case SIN:
            push(sin(pop()));
            break;
        case COS:
            push(cos(pop()));
            break;
        case TAN:
            push(tan(pop()));
            break;
        case ASIN:
            push(asin(pop()));
            break;
        case ACOS:
            push(acos(pop()));
            break;
        case ATAN:
            push(atan(pop()));
            break;
        case EXP:
            push(exp(pop()));
            break;
        case LOG:
            if(stacksize() >= 2)
            {
                double b = pop();
                push(log(pop()) / log(b));
            }
            else
                printf("error: log function requires a number x and the log base b\n");
            break;
        case SQRT:
            push(sqrt(pop()));
            break;
        case CEIL:
            push(ceil(pop()));
            break;
        case FLOOR:
            push(floor(pop()));
            break;
        case ABS:
            push(fabs(pop()));
            break;
        /* set a custom variable */
        case VAR:
            /* the last character is the char, all characters are the double. atof ignores the last char which isn't a number */
            cust_var[s[strlen(s) - 1] - 'a'] = atof(s);
            break;
        /* replacing variables with numbers in the stack */
        case 'a':
            push(cust_var['a' - 'a']);
            break;
        case 'b':
            push(cust_var['b' - 'a']);
            break;
        case 'c':
            push(cust_var['c' - 'a']);
            break;
        case 'd':
            push(cust_var['d' - 'a']);
            break;
        case 'e':
            push(cust_var['e' - 'a']);
            break;
        case 'f':
            push(cust_var['f' - 'a']);
            break;
        case 'g':
            push(cust_var['g' - 'a']);
            break;
        case 'h':
            push(cust_var['h' - 'a']);
            break;
        case 'i':
            push(cust_var['i' - 'a']);
            break;
        case 'j':
            push(cust_var['j' - 'a']);
            break;
        case 'k':
            push(cust_var['k' - 'a']);
            break;
        case 'l':
            push(cust_var['l' - 'a']);
            break;
        case 'm':
            push(cust_var['m' - 'a']);
            break;
        case 'n':
            push(cust_var['n' - 'a']);
            break;
        case 'o':
            push(cust_var['o' - 'a']);
            break;
        case 'p':
            push(cust_var['p' - 'a']);
            break;
        case 'q':
            push(cust_var['q' - 'a']);
            break;
        case 'r':
            push(cust_var['r' - 'a']);
            break;
        case 's':
            push(cust_var['s' - 'a']);
            break;
        case 't':
            push(cust_var['t' - 'a']);
            break;
        case 'u':
            push(cust_var['u' - 'a']);
            break;
        case 'v':
            push(cust_var['v' - 'a']);
            break;
        case 'w':
            push(cust_var['w' - 'a']);
            break;
        case 'x':
            push(cust_var['x' - 'a']);
            break;
        case 'y':
            push(cust_var['y' - 'a']);
            break;
        case 'z':
            push(cust_var['z' - 'a']);
            break;

        default:
            printf("error: unknown command %s\n", s);
            break;
        }
        /* this is a variable to keep track if enter got hit twice so we only print calculated
         * value if it it gets hit twice */
        type_prev = type;
    }

    return 0;
}
