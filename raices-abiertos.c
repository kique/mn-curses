
#include "header.h"
#include "prototipos.h"

double pfijo(double x0, double es, double *ea, int imax, int *iter, int tabla)
{
    double xr=x0, xrold;

    if(tabla == 1)
    {
 
        printf ("\n\n|  i |      Raiz      |      ea      |     f(xr)    | \n");
        printf ("______________________________________________________\n");
    }

    *iter = 0;
    do{
        xrold = xr;
        xr = gf(xrold);
        *iter++;
        if(xr!=0)
        {
            *ea=fabs((xr-xrold)/xr)*100;
        }
        if ( tabla == 1 ) {
            printf ("| %2d | %12.8f | %12.8f | %12.8f |\n", *iter, xr, *ea, f(xr) );
	    }

    }while(es > *ea && *iter <= imax);

    if ( tabla == 1 ) {
        printf ("\n\nLa Raiz es %6.4lf en %d iteraciones\n",xr);
        printf ("\n\nEl error relativo aproximado es %6.4lf\n",ea);
        return;
    }
    else
        return xr;
}

double newtonrap(double x0, double es, double *ea, int imax, int *iter, int tabla)
{
    double x1;

    if(tabla == 1)
    {
 
        printf ("\n\n|  i |      Raiz      |      ea      |     f(xr)    | \n");
        printf ("______________________________________________________\n");
    }

    *iter = 0;
    do{
        x0 = x1;
        x1 = x0-(f(x0)/df(x0));
        *iter++;
        if(x1!=0)
        {
            *ea=fabs((x1-x0)/x1)*100;
        }
        if ( tabla == 1 ) {
            printf ("| %2d | %12.8f | %12.8f | %12.8f |\n", *iter, x1, *ea, f(x1) );
	    }
    }while(es > *ea && *iter <= imax);
    if ( tabla == 1 ) {
        printf ("\n\nLa Raiz es %6.4lf en %d iteraciones\n",x1);
        printf ("\n\nEl error relativo aproximado es %6.4lf\n",ea);
        return;
    }
    else
        return x1;
}

double secante(double x0, double x1, double es, double *ea, int imax, int *iter, int tabla)
{
    double x2;

    if(tabla == 1)
    {
 
        printf ("\n\n|  i |      Raiz      |      ea      |     f(xr)    | \n");
        printf ("______________________________________________________\n");
    }

    *iter = 0;
    do{
        x0 = x1;
        x1 = x2;
        x2 = x1 - (f(x1)*(x0-x1))/(f(x0)-f(x1));
        *iter++;
        if(x1!=0)
        {
            *ea=fabs((x1-x0)/x1)*100;
        }
        if ( tabla == 1 ) {
            printf ("| %2d | %12.8f | %12.8f | %12.8f |\n", *iter, x2, *ea, f(x2) );
	    }

    }while(es > *ea && *iter <= imax);

    if ( tabla == 1 ) {
        printf ("\n\nLa Raiz es %6.4lf en %d iteraciones\n",x2);
        printf ("\n\nEl error relativo aproximado es %6.4lf\n",ea);
        return;
    }
    else
        return x2;
}

