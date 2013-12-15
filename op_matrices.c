/*
 * =====================================================================================
 *
 *       Filename:  op_matrices.c
 *
 *    Description:  Funciones de Operaciones con Matrices
 *
 *        Version:  1.0
 *        Created:  07/12/13 21:08:00
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
 *         Name:  Eliminacion hacia adelante simple
 *  Description:  Suma dos matrices de tamanio variable
 * =====================================================================================
 */

void eliminacion(double **a, double *x, int filas, int columnas, double *b)
{
    int i,j,k;
    float factor;
    for(k=0;k<=n-2;k++)
    {
	for(i = k+1;i <= n-1;i++)
	{
	    factor = a[i][k]/a[k][k];
	    for(j=k+1;j<=n-1;j++)
	    {
		a[i][j] = a[i][j]-factor*a[k][j];
	    }
	    b[i] = b[i]-factor*b[k];
	}
    }
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  sustitucion
 *  Description:  Sustitucion hacia atras
 * =====================================================================================
 */

void sustitucion(double **a, double *x, int filas, int columnas, double *b)
{
    int i,j;
    float sum;

    x[n-1]=b[n-1]/a[n-1][n-1];

    for(i=n-2;i>=0;i--)
    {
	sum=b[i];
	for(j=i+1;j<=n-1;j++)
	{
	    sum = sum - a[i][j]*x[j];
	}
	x[i] = sum / a[i][i];
    }

}
