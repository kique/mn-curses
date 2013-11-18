#include "header.h"

double f(double z)
{
    return tan(0.2*z)+0.5;
}

double df(double z)
{
    return 2.85*z*z-11.8*z+10.9;
}

double gf(double z)
{
    return z + tan(0.2*z)+0.5;
}
