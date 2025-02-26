#include "calc.h"
#include <stdio.h>
#include <math.h> // math functions like sin, sqrt, log etc.
#include <string.h> // for strlen

/* reverse Polish calculator */
int main(int argc, char *argv[])
{
    int type;
    double num, op2;

    while(--argc > 0)
    {
	type = getop(*++argv, &num);
        switch(type)
        {
        case NUMBER:
            push(num);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
	/* can't use '*' because bash shell expands this as wildcard character annoyingly */
        case 'x':
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
    	}
    }
    //TODO: PRINT THE RESULT AND EXIT 
    printf("%f\n", pop());
    if(stacksize() > 0)
    {
	    printf("Warning: stack still has elements left!\n");
	    return -1;
    }
    return 0;
}
