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


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  crea_matriz
 *  Description:  crea matrices de tamanio variable
 * =====================================================================================
 */
    double
crear_matriz (int filas, int columnas )
{
    double **m;
    int j;

    m = (double **⁾ malloc(filas * sizeof(float *));
    for(j=0;j< filas; j++)
        m[j]=(double)malloc(columnas * sizeof(double));

    return m;
}		/* -----  end of function crear_matriz  ----- */

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  destruye__matriz
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
            printf("Dar el elemento [%d,%d]: ",i,j);
            scanf("%f", &dato);
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
            printf("[ %e ] \t: ",m[i][j]);
        }
        printf("\n");
    }
}		/* -----  end of function imprime_matriz  ----- */



