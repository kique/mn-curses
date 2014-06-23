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
#include "prototipos.h"

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
    //A[][]={{3,-0.1,-0.2},{0.1,7,3},{0.3,-0.2,10,}};
    B=crear_vector(tam);
    //B[]={7.85,-19.3,71.4};
    X=crear_vector(tam);
    printf("\nIntroduzca los coeficientes de la matriz A[][]\n");
    lee_matriz(A,tam,tam);
    printf("\nIntroduzca los terminos independientes B[]\n ");
    lee_vector(B,tam);
    printf("\nMatriz aumentada original:\n");
    imprime_matriz_aumentada(A,B,tam);
    printf("\nEliminacion hacia adelante:\n\n");
    eliminacion_didactica(A,X,tam,tam,B);
    printf("\n\nSustitucion hacia atras:\n");
    sustitucion_didactica(A,X,tam,tam,B);
    printf("\n\nLa solucion a el sistema es:\n");
    imprime_vector(X,tam);
    destruye_matriz(A,tam,tam);
    destruye_vector(B);
    destruye_vector(X);

}		/* -----  end of function gauss_simple  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  gauss_jordan
 *  Description:  
 * =====================================================================================
 */
    void
gauss_jordan ( void )
{
    double **A, *B, *X, termino;
    int tam,i,j,k;

    printf("Metodo de Eliminacion de Gauss Jordan");
    printf("\n\nIndique el numero de  variables: ");
    scanf("%d", &tam);
    A=crear_matriz(tam,tam);
    //A[][]={{3,-0.1,-0.2},{0.1,7,3},{0.3,-0.2,10,}};
    B=crear_vector(tam);
    //B[]={7.85,-19.3,71.4};
    X=crear_vector(tam);
    printf("\nIntroduzca los coeficientes de la matriz A[][]\n");
    lee_matriz(A,tam,tam);
    printf("\nIntroduzca los terminos independientes B[]\n ");
    lee_vector(B,tam);
    printf("\nMatriz aumentada original:\n");
    imprime_matriz_aumentada(A,B,tam);
    
     
    for ( i=0; i<tam; i++ ) {

	if ( A[i][i] == 0.0 ) {
	    fprintf(stderr, "Error: Division entre cero.\n\n");
	    break;
	}

	for ( k=0; k<tam; k++ ) {

	    if ( k!=i ) {
		termino = A[k][i] / A[i][i];
		for ( j=0; j<tam; j++ ) {
			A[k][j] -= termino * A[i][j];
		}
		
	    }
	}
    }

    printf("solucion:\n\n");
    
    for ( i=0; i<tam; i++ ) {
	termino = A[i][tam] / A[i][i];
	printf("x%d = %g\n",i+1,termino);
    }

    destruye_matriz(A,tam,tam);
    destruye_vector(B);
    destruye_vector(X);

    return ;
}		/* -----  end of function gauss_jordan  ----- */
