/*
 * =====================================================================================
 *
 *       Filename:  raices-abiertos.c
 *
 *    Description:  Funciones de los metodos abiertos para ocalizar raices 
 *
 *        Version:  0.2
 *        Created:  03/11/13 10:39:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enrique Martínez Roldán
 *   Organization:  IPN - ESIME - Zacatenco
 *
 * =====================================================================================
 */

#include "header.h"
#include "prototipos.h"


double biseccion(double xa, double xb, double es, double *ea, int imax, int *iter, int tabla, /*char buffer[]*/)
{
  double  xr,xrold,test;
  void *f;

  
  char buffer[BUFFER_SIZE];	/*  Input buffer.  */
    int length;			/*  Length of above buffer. */
    void *f, *f_prim;		/*  Evaluators for function and function derivative.  */
    char **names;		/*  Function variables names. */
    int count;			/*  Number of function variables. */
 
    printf ("f(x) = ");
    fgets (buffer, BUFFER_SIZE, stdin);
    length = strlen (buffer);
    if (length > 0 && buffer[length - 1] == '\n')
	buffer[length - 1] = '\0';

 

  /*  Create evaluator for function.  */
    f = evaluator_create (buffer);
    assert (f);



  //Se imprime la cabecera de la tabla solo si lo desea el usuario tabla == 1
  if(tabla == 1)
  {

      printf ("\n\n|  i |      xa      |      xr      |      xb      |      ea      |     f(xr)    | \n");
      printf ("____________________________________________________________________________________\n");
 
  }

 *iter= 0;
  //xr = (xa + xb)/2.0;
  xr=0;
  do{
      xrold = xr;
      xr = (xa + xb)/2.0;
      *iter = *iter + 1;
      if (xr != 0)
      {
          *ea = fabs((xr-xrold)/xr)*100;
      }    
      
      //test = f(xa)*f(xr);
      test = evaluator_evaluate_x (f,xa) * evaluator_evaluate_x(f,xr);  
      if (test < 0)
          xb = xr;
      else if(test > 0)
          xa = xr;
      else
          *ea = 0;

      //Se imprimen los datos de la tabla si el usuario lo desea, tabla == 1
      if ( tabla == 1 ) {
           printf ("| %2d | %12.8lf | %12.8lf | %12.8lf | %12.8lf | %12.8lf\n", *iter, xa, xr, xb, *ea, evaluator_evaluate_x(f,xr) );
	    }
  }while((*ea > es ) && (*iter <= imax));

  /*  Destroy evaluators.  */
  evaluator_destroy (f);

  if ( tabla == 1 ) {
      printf ("\n\nLa Raiz es %6.4lf\n",xr);
      return 0;
  }
  else
      return xr;

}

double rfalsa(double xa, double xb, double es, double *ea, int imax, int *iter, int tabla)
{
  double xr=xa, xrold;
  
  if ( tabla == 1 )
  {
      printf ("\n\n|  i  |    xa    |    xr    |    xb    |     ea     |    f(xr)   | \n");
      printf ("________________________________________________________________________\n");
  }

  *iter = 0;

  if (f(xa)*f(xb) < 0)
  {

    while( *iter < imax )
	{
        
        xrold=xr;
        xr = xb - (f(xb)*(xa - xb))/(f(xa) - f(xb));
       
        if (xr != 0)
        {
             *ea = fabs((xr-xrold)/xr)*100;
        }      
 
        if (f(xa)*f(xr)<0)
          {
            xb = xr;
          }
        else
          {
            xa = xr;
          }
        *iter = *iter + 1;
        
        if ( tabla == 1 ) {
            printf ("| %3d | %8.4f | %8.4f | %8.4f | %8.4f | %8.4f |\n",*iter,xa, xr, xb, *ea, f(xr) );
	    }

        if ( fabs(*ea) <= es )
        {
          break;
        }
	}
    if ( tabla == 1 ) {
        printf ("\n\nLa Raiz es %6.4lf\n",xr);
        return 0;
    }
    else
       return xr;
  }
  return 0;
}

