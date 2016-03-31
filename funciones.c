#include "header.h"

double f(double x)
{
    return log(x)-sin(x);
}

double df(double x)
{
    return 12*x*x+3;
}

double gf(double x)
{
    return 3*x*x+x-30;
}
