#include "header.h"

double f(double x)
{
    return tan(0.2*x)+0.5;
}

double df(double x)
{
    return 6*x;
}

double gf(double x)
{
    return 3*x*x+x-30;
}
