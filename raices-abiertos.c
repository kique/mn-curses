
#include "header.h"
#include "prototipos.h"

double pfijo(double x0, double es, double *ea, int imax, int *iter, int tabla, char *buffer)
{
    double xr=x0, xrold;

    void *f;		/*  Evaluators for function and function derivative.  */
 
  /*  Create evaluator for function.  */
    f = evaluator_create (buffer);
    assert (f);

    if(tabla == 1)
    {
 
        printf ("\n\n|  i |      Raiz      |      ea      |     f(xr)    | \n");
        printf ("______________________________________________________\n");
    }

    *iter = 0;
    do{
        xrold = xr;
        xr = evaluator_evaluate_x(f,xrold);
        *iter=*iter+1;
        if(xr!=0)
        {
            *ea=fabs((xr-xrold)/xr)*100;
        }
        if ( tabla == 1 ) {
            printf ("| %2d | %12.8f | %12.8f | %12.8f |\n", *iter, xr, *ea, evaluator_evaluate_x(f,xr) );
	    }

    }while(es < *ea && *iter <= imax);

    evaluator_destroy(f);

    if ( tabla == 1 ) {
        printf ("\n\nLa Raiz es %6.4lf en %d iteraciones\n",xr,*iter);
        printf ("\n\nEl error relativo aproximado es %6.4lf\n",*ea);
        return 0;
    }
    else
        return xr;
}

double newtonrap(double x0, double es, double *ea, int imax, int *iter, int tabla, char *buffer, char *buffer2)
{
    double x1=x0;

    void *f, *f2;		/*  Evaluators for function and function derivative.  */
 
  /*  Create evaluator for function.  */
    f = evaluator_create (buffer);
    f2 = evaluator_create (buffer2);
    assert (f);
    assert (f2);
    
    if(tabla == 1)
    {
 
        printf ("\n\n|  i |      Raiz      |      ea      |     f(xr)    | \n");
        printf ("______________________________________________________\n");
    }

    *iter = 0;
    do{
        x0 = x1;
        x1 = x0-(evaluator_evaluate_x(f,x0)/evaluator_evaluate_x(f2,x0));
        *iter=*iter+1;
        if(x1!=0)
        {
            *ea=fabs((x1-x0)/x1)*100;
        }
        if ( tabla == 1 ) {
            printf ("| %2d | %12.8f | %12.8f | %12.8f |\n", *iter, x1, *ea, evaluator_evaluate_x(f,x1) );
	    }
    }while(es < *ea && *iter <= imax);

    evaluator_destroy(f);
    evaluator_destroy(f2);

    if ( tabla == 1 ) {
        printf ("\n\nLa Raiz es %6.4lf en %d iteraciones\n",x1,*iter);
        printf ("\n\nEl error relativo aproximado es %6.4lf\n",*ea);
        return 0;
    }
    else
        return x1;
}

double secante(double x0, double x1, double es, double *ea, int imax, int *iter, int tabla, char *buffer)
{
    double x2=x0;

    void *f;		/*  Evaluators for function and function derivative.  */
 
  /*  Create evaluator for function.  */
    f = evaluator_create (buffer);
    assert (f);

    if(tabla == 1)
    {
 
        printf ("\n\n|  i |      Raiz      |      ea      |     f(xr)    | \n");
        printf ("______________________________________________________\n");
    }

    *iter = 0;
    do{
        x0 = x1;
        x1 = x2;
        x2 = x1 - (evaluator_evaluate_x(f,x1) * (x0-x1)) / (evaluator_evaluate_x(f,x0)-evaluator_evaluate_x(f,x1));
        *iter=*iter+1;
        if(x1!=0)
        {
            *ea=fabs((x1-x0)/x1)*100;
        }
        if ( tabla == 1 ) {
            printf ("| %2d | %12.8f | %12.8f | %12.8f |\n", *iter, x2, *ea,evaluator_evaluate_x(f,x2) );
	    }

    }while(es < *ea && *iter <= imax);

    evaluator_destroy(f);

    if ( tabla == 1 ) {
        printf ("\n\nLa Raiz es %6.4lf en %d iteraciones\n",x2,*iter);
        printf ("\n\nEl error relativo aproximado es %6.4lf\n",*ea);
        return 0;
    }
    else
        return x2;
}

