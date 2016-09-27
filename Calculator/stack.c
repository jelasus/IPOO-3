#include <stdio.h>
#include "cal.h"
#define MAXVAL 100

int sp=0;
double val[MAXVAL];

void push(double f)
{
    if (sp<MAXVAL)
        val[sp++] = f;
    else
        printf("Error: Pila llena, no se puede agregar %g\n", f);
}

double pop(void)
{
    if (sp>0)
        return val[--sp];
    else
    {
        printf("Error: Pila vacia\n");
        return 0.0;
    }
}

