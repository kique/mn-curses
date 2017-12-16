/*
 * =====================================================================================
 *
 *       Filename:  raices-abiertos.c
 *
 *    Description:  Funciones de los metodos cerrados para ocalizar raices 
 *
 *        Version:  0.2.1
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


double biseccion(double xa, double xb, double es, double *ea, int imax, int *iter, int tabla, char buffer[])
{
  double  xr,xrold,test;
  
    void *f;		/*  Evaluators for function and function derivative.  */
 
  /*  Create evaluator for function.  */
    f = evaluator_create (buffer);
    assert (f);

printf("Metodo de Biseccion");

  //Se imprime la cabecera de la tabla solo si lo desea el usuario tabla == 1
  if(tabla == 1)
  {

      printf ("\n\n|  i |      xa      |      xb      |      xr      |      ea      |     f(xr)    | \n");
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
      
      //Se imprimen los datos de la tabla si el usuario lo desea, tabla == 1
      if ( tabla == 1 ) {
           printf ("| %2d | %12.8lf | %12.8lf | %12.8lf | %12.8lf | %12.8lf\n", *iter, xa, xb, xr, *ea, evaluator_evaluate_x(f,xr) );
	    }

      //test = f(xa)*f(xr);
      test = evaluator_evaluate_x (f,xa) * evaluator_evaluate_x(f,xr);  
      if (test < 0)
          xb = xr;
      else if(test > 0)
          xa = xr;
      else
          *ea = 0;

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

double rfalsa(double xa, double xb, double es, double *ea, int imax, int *iter, int tabla, char buffer[])
{
  double  xr,xrold,test;
  
    void *f;		/*  Evaluators for function and function derivative.  */
 
  /*  Create evaluator for function.  */
    f = evaluator_create (buffer);
    assert (f);

printf("Metodo la Regla Falsa");

  //Se imprime la cabecera de la tabla solo si lo desea el usuario tabla == 1
  if(tabla == 1)
  {

      printf ("\n\n|  i |      xa      |      xb      |      xr      |      ea      |     f(xr)    | \n");
      printf ("____________________________________________________________________________________\n");
 
  }

 *iter= 0;
  //xr = (xa + xb)/2.0;
  xr=0;
  do{
      xrold = xr;

      xr = xb - (evaluator_evaluate_x(f,xb)*(xa - xb))/(evaluator_evaluate_x(f,xa) - evaluator_evaluate_x(f,xb));
      
      *iter = *iter + 1;
      
      if (xr != 0)
      {
          *ea = fabs((xr-xrold)/xr)*100;
      }    
      
      //Se imprimen los datos de la tabla si el usuario lo desea, tabla == 1
      if ( tabla == 1 ) {
           printf ("| %2d | %12.8lf | %12.8lf | %12.8lf | %12.8lf | %12.8lf\n", *iter, xa, xb, xr, *ea, evaluator_evaluate_x(f,xr) );
	    }

      //test = f(xa)*f(xr);
      test = evaluator_evaluate_x (f,xa) * evaluator_evaluate_x(f,xr);  
      if (test < 0)
          xb = xr;
      else if(test > 0)
          xa = xr;
      else
          *ea = 0;

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

