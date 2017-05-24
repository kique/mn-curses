#include "header.h"

double f(double x)
{
    return exp(-x)-sin(x);
//    return x*x*x-2*x*x-3;
}

double df(double x)
{
    return 12*x*x+3;
//    return 3*x*x-4*x;
}

double gf(double x)
{
    return 3*x*x+x-30;
}
