#ifndef CALC_H
#define CALC_H  1

/* defined constants */
#define MAXOP   100     /* max size of operand or operator */
#define NUMBER  '0'     /* signal that a number was found */
#define SIN     256
#define COS     257
#define TAN     258
#define ASIN    259
#define ACOS    260
#define ATAN    261
#define EXP     262
#define LOG     263
#define SQRT    264
#define CEIL    265
#define FLOOR   266
#define ABS     267

/* function definitions */
extern int getop(char *arg, double *num);
extern void push(double);
extern double pop(void);
extern double ptop(void);
extern void swaptop(void);
extern void clrstack(void);
extern int stacksize(void);
extern int getch(void);
extern void ungetch(int);
extern void ungets(char*);

#endif // CALC_H
