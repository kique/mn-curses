/*
 * =====================================================================================
 *
 *       Filename:  gauss.c
 *
 *    Description: Funciones para los metodos de Gauss 
 *
 *        Version:  1.0
 *        Created:  15/12/13 09:52:03
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enrique Martinez Roldan (emr), enrique.roldan@gmail.com
 *   Organization:  IPN ESIME Zacatenco
 *
 * =====================================================================================
 */
#include "header.h"
#include "prototipos.h";

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  gauss_simple
 *  Description:  
 * =====================================================================================
 */
    void
gauss_simple ( void )
{
    double **A, *B, *X;
    int tam;

    printf("Metodo de Eliminacion de Gauss Simple");
    printf("\n\nIndique el numero de  variables: ");
    scanf("%d", &tam);
    A=crear_matriz(tam,tam);
    B=crear_vector(tam);
    X=crear_vector(tam);
    printf("\nIntroduzca los coeficientes de la matriz A[][]");
    lee_matriz(A,tam,tam);
    printf("\nIntroduzca los terminos independientes B[] ");
    lee_vector(B,tam);
    eliminacion(A,X,tam,tam,B);
    sustitucion(A,X,tam,tam,B);
    printf("\nLa solucion a el sistema es:\n");
    imprime_vector(X,tam);

}		/* -----  end of function gauss_simple  ----- */
