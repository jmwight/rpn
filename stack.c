#include "calc.h" // project header
#include <stdio.h>
#define MAXVAL  100     // maximum depth of val stack

static int sp = 0;             // next free stack position
static double val[MAXVAL];     // value stack

/* push: push f onto value stack */
void push(double f)
{
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if(sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* ptop: print top element of stack without removing. Returns top value */
double ptop(void)
{
    if(sp > 0)
    {
        printf("%.8g\n", val[sp - 1]);
        return val[sp - 1];
    }
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* swaptop: swaps top elements of stack */
void swaptop(void)
{
    if(sp > 1)
    {
        double tmp;
        tmp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = tmp;
    }
}

/* stacksize: returns the number of elements in the stack */
int stacksize(void)
{
    return sp;
}

/* clrstack: clears the stack completely. Analagous to pressing clear all button on a calculator */
void clrstack(void)
{
    sp = 0;
}
