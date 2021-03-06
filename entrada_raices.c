/*
 * =====================================================================================
 *
 *       Filename:  entrada_raices.c
 *
 *    Description:  Funciones para enviar datos iniciales a los metodos de localizacion 
 *                  de raices.
 *
 *        Version:  0.1
 *        Created:  03/11/13 11:51:26
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


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  entrada_cerrados
 *  Description:  Funcion para enviar datos de entrada a los metodos cerrados para 
 *                localizacion de raices.
 * =====================================================================================
 */
  void
entrada_cerrados (int op_met, char *buffer)
{

  int imax,iter=0,tabla;
  double xa,xb,ea=100,es,raiz;
  char id_metodo[20];

  system("clear");

  printf("Programa para calcular la raiz de %s \n\nUsando el Método de %s\n",buffer, (op_met == 1)? strcpy(id_metodo,"Biseccion"):strcpy(id_metodo,"Falsa Posicion"));

  printf ("\n\tDar el valor del limite izquierdo xa: ");
  scanf("%lf",&xa);
  printf ("\n\tDar el valor del limite derecho xb: ");
  scanf("%lf",&xb);
  printf ("\n\tDar el valor del error relativo porcentual deseado es: ");
  scanf("%lf",&es);
  printf ("\n\tDar el numero maximo de iteraciones: ");
  scanf("%d",&imax);
  printf ("\n\tDesea imprimir tabla de resultados o solamente la raiz? (1=tabla / 0=raiz ): ");
  scanf("%d",&tabla);

  if(op_met == 1)
  {
    if(tabla == 1)
      biseccion(xa, xb, es, &ea, imax, &iter, 1 ,  buffer);
    else if(tabla == 0)
    {
      raiz =  biseccion(xa, xb, es, &ea, imax, &iter, 0 , buffer);
      printf("\nLa raiz es %lf con un error rel porc de %lf encontrado en %d iteraciones.",raiz,ea,iter);
    }
    else
      printf("\nOpcion invalida, vuelva a intentar");
  }
  else
  {
    if(tabla == 1)
      rfalsa(xa, xb, es, &ea, imax, &iter, 1, buffer);
    else if(tabla == 0)
    {
      raiz =  rfalsa(xa, xb, es, &ea, imax, &iter, 0, buffer);
      printf("\nLa raiz es %lf con un error rel porc de %lf encontrado en %d iteraciones.",raiz,ea,iter);
    }
    else
      printf("\nOpcion invalida, vuelva a intentar");
  }

  return;
}		/* -----  end of function entrada_cerrados  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  entrada_abiertos
 *  Description:  Funcion para enviar datos de entrada a los metodos cerrados para 
 *                localizacion de raices.
 * =====================================================================================
 */
  void
entrada_abiertos(int op_met, char *buffer)
{

  int imax,iter=0,tabla;

  char buffer2[BUFFER_SIZE];

  double x0,x1,ea=100,es,raiz;

  system("clear");

  enum raiz_abiertos
  {
    punto_fijo,
    newton,
    rsecante
  } metodo;

  metodo = op_met;


  switch ( metodo ) {
    case punto_fijo:	 
      printf("Programa para calcular una raiz por el Metodo de Punto Fijo");
      printf ("\nDe el valor inicial x0: ");
      scanf("%lf",&x0);
      printf ("\nDe el valor del error relativo porcentual deseado es: ");
      scanf("%lf",&es);
      printf ("\nDe el numero maximo de iteraciones: ");
      scanf("%d",&imax);
      printf ("\nDesea imprimir tabla de resultados o solamente la raiz? (1=tabla / 0=raiz ): ");
      scanf("%d",&tabla);

      if(op_met == 0)
      {
        if(tabla == 1)
          pfijo(x0, es, &ea, imax, &iter, tabla, buffer);
        else if(tabla == 0)
        {
          raiz = pfijo(x0, es, &ea, imax, &iter, tabla, buffer);
          printf("\nLa raiz es %lf con un error rel porc de %lf encontrado en %d iteraciones.",raiz,ea,iter);
        }
        else
          printf("\nOpcion invalida, vuelva a intentar");
      }

      break;

    case newton:	
      printf("Programa para calcular una raiz por el Metodo de Newton-Raphson");
      printf ("\nDe el valor inicial x0: ");
      scanf("%lf",&x0);
      printf ("\nDe el valor del error relativo porcentual deseado es: ");
      scanf("%lf",&es);
      printf ("\nDe el numero maximo de iteraciones: ");
      scanf("%d",&imax);
      printf ("\nDesea imprimir tabla de resultados o solamente la raiz? (1=tabla / 0=raiz ): ");
      scanf("%d",&tabla);
      
      printf("\nEscriba la derivada de la funcion: ");

      lee_expresion(buffer2);

      if(op_met == 1)
      {
        if(tabla == 1)
          newtonrap(x0, es, &ea, imax, &iter, tabla, buffer, buffer2);
        else if(tabla == 0)
        {
          raiz=newtonrap(x0, es, &ea, imax, &iter, tabla, buffer, buffer2);
          printf("\nLa raiz es %lf con un error rel porc de %lf encontrado en %d iteraciones.",raiz,ea,iter);
        }
        else
          printf("\nOpcion invalida, vuelva a intentar");
      }

      break;

    case rsecante:	          
      printf("Programa para calcular una raiz por el Metodo de la Secante");
      printf ("\nDe el valor inicial x0: ");
      scanf("%lf",&x0);
      printf ("\nDe el valor inicial x1: ");
      scanf("%lf",&x1);
      printf ("\nDe el valor del error relativo porcentual deseado es: ");
      scanf("%lf",&es);
      printf ("\nDe el numero maximo de iteraciones: ");
      scanf("%d",&imax);
      printf ("\nDesea imprimir tabla de resultados o solamente la raiz? (1=tabla / 0=raiz ): ");
      scanf("%d",&tabla);

      if(op_met == 2)
      {
        if(tabla == 1)
          secante(x0, x1, es, &ea, imax, &iter, tabla, buffer);
        else if(tabla == 0)
        {
          raiz = secante(x0, x1, es, &ea, imax, &iter, tabla, buffer);
          printf("\nLa raiz es %lf con un error rel porc de %lf encontrado en %d iteraciones.",raiz ,ea,iter);
        }
        else
          printf("\nOpcion invalida, vuelva a intentar");
      }

      break;

    default:	
      break;
  }				/* -----  end switch  ----- */

  return;
}		/* -----  end of function entrada_cerrados  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  lee_expresion
 *  Description:  
 * =====================================================================================
 */
	void 
lee_expresion ( char *buffer  )
{
  int length;			/*  Length of above buffer. */

  /* Se lee la expresion matematica */
  printf ("Introduzca la función a analizar f(x)= ");
  scanf("%s",buffer);

  //    fgets (buffer, BUFFER_SIZE, stdin);
  length = strlen (buffer);

  if (length > 0 && buffer[length - 1] == '\n')
    buffer[length - 1] = '\0';
  
}		/* -----  end of function lee_expresion  ----- */
