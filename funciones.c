#include "header.h"

double f(double x)
{
<<<<<<< HEAD
    return log(x)-sin(x);
=======
    return x*x*x-2*x*x-3;
>>>>>>> a705b1ae12d41ed72b2e1d571dc4170ce86f2e5b
}

double df(double x)
{
<<<<<<< HEAD
    return 12*x*x+3;
=======
    return 3*x*x-4*x;
>>>>>>> a705b1ae12d41ed72b2e1d571dc4170ce86f2e5b
}

double gf(double x)
{
    return 3*x*x+x-30;
}
