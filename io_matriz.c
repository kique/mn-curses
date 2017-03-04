/*
 * =====================================================================================
 *
 *       Filename:  io_matriz.c
 *
 *    Description: Lectura y escritura de matrices 
 *
 *        Version:  1.0
 *        Created:  07/12/13 19:22:05
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
 *         Name:  crear_vector
 *  Description:  Funcion que crea un vector dinamico
 * =====================================================================================
 */
double *
crear_vector (int tam )
{
    double *v;
    v = (double *) malloc(tam * sizeof(double));	
    return v;
}		/* -----  end of function crea_vector  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  lee_vector
 *  Description:  Lee vectores de tamanio dinamico
 * =====================================================================================
 */
    void
lee_vector ( double *v, int tam )
{
    int i;
    for (i = 0; i < tam; i++) {
        printf("\nDar el elemento [%d] = ",i+1);
        scanf("%lf",&v[i]);
    }

}		/* -----  end of function lee_vector  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  imprime_vector
 *  Description:  Imprime un vector dinámico
 * =====================================================================================
 */
    void
imprime_vector ( double *v, int tam )
{
    int i;

    for (i = 0; i < tam; i++) {
        printf("x[%d] = [ %11.6lf ] \n",i+1,v[i]);
    }
}		/* -----  end of function imprime_vector  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  destruye_vector
 *  Description:  Elimina vectores dinamicos
 * =====================================================================================
 */
    void
destruye_vector ( double *v )
{
    free(v);
}		/* -----  end of function destuye_vector  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  crea_matriz
 *  Description:  crea matrices de tamanio variable
 * =====================================================================================
 */
    double **
crear_matriz (int filas, int columnas )
{
    double **m;
    int j;

    m = (double **) malloc(filas * sizeof(double *));
    for(j=0;j< filas; j++)
        m[j]=(double *)malloc(columnas * sizeof(double));

    return m;
}		/* -----  end of function crear_matriz  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  destruye_matriz
 *  Description:  Destruye matrices de tamanio variable
 * =====================================================================================
 */
 
void destruye_matriz(double **m, int filas, int columnas)
{
    int j;

    for(j=0; j<filas; j++)
        free(m[j]);

    free(m);
    return;
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  lee_matriz
 *  Description:  Lee una matriz de tamanio variable
 * =====================================================================================
 */
    void
lee_matriz ( double **m, int filas, int columnas )
{
    int i,j;
    double dato;

    for ( i=0; i < filas; i++ ) {

        for ( j=0; j < columnas; j++ ) {
            printf("Dar el elemento [%d,%d]: ",i+1,j+1);
            scanf("%lf", &dato);
            m[i][j]=dato;
        }
        printf("\n");
    }
}/* -----  end of function lee_matriz  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  imprime_matriz
 *  Description:  Imprime una matriz de tamaño variable
 * =====================================================================================
 */
    void
imprime_matriz ( double **m, int filas, int columnas )
{
    int i,j;
    
    for ( i=0; i < filas; i++ ) {

        for ( j=0; j < columnas; j++ ) {
            printf("[ %11.6lf ] ",m[i][j]);
        }
        printf("\n");
    }
}		/* -----  end of function imprime_matriz  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  imprime_matriz_aumentada
 *  Description:  Funcion para imprimir la matriz aumentada
 * =====================================================================================
 */
    void
imprime_matriz_aumentada ( double **a, double *b, int tam )
{
    int i,j;
    
    for ( i=0; i < tam; i++ ) {

        for ( j=0; j < tam; j++ ) {
            printf("[ %11.6lf ] ",a[i][j]);
        }
        printf(" = [ %11.6lf ]",b[i]);
        printf("\n");
    }
}		/* -----  end of function imprime_matriz_aumentada  ----- */

