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
//
//                                                                 #####
//                                                                #######
//                   #                                            ##O#O##
//  ######          ###                                           #VVVVV#
//    ##             #                                          ##  VVV  ##
//    ##         ###    ### ####   ###    ###  ##### #####     #          ##
//    ##        #  ##    ###    ##  ##     ##    ##   ##      #            ##
//    ##       #   ##    ##     ##  ##     ##      ###        #            ###
//    ##          ###    ##     ##  ##     ##      ###       QQ#           ##Q
//    ##       # ###     ##     ##  ##     ##     ## ##    QQQQQQ#       #QQQQQQ
//    ##      ## ### #   ##     ##  ###   ###    ##   ##   QQQQQQQ#     #QQQQQQQ
//  ############  ###   ####   ####   #### ### ##### #####   QQQQQ#######QQQQQ
// 


#include "header.h"
#include "prototipos.h"

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  eliminacion
 *  Description:  Eliminacion de Gauss Simple 
 * =====================================================================================
 */

void eliminacion(double **a, double *x, int filas, int columnas, double *b)
{
    int i,j,k,n;
    float factor;

    n=filas;

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
 *         Name:  eliminacion_didactica
 *  Description:  Eliminacion de Gauss Demostrativa 
 * =====================================================================================
 */

void eliminacion_didactica(double **a, double *x, int filas, int columnas, double *b)
{
    int i,j,k,n;
    float factor;

    n=filas;

    for(k=0;k<=n-2;k++)
    {
        for(i = k+1;i <= n-1;i++)
        {
            factor = a[i][k]/a[k][k];
            printf("\nFactor de eliminacion= %.6f/%.6f  por fila %d y restado a %d", a[i][k],a[k][k],i,i+1);
            for(j=k+1;j<=n-1;j++)
            {
                a[i][j] = a[i][j]-factor*a[k][j];
            }
            b[i] = b[i]-factor*b[k];
        }
        printf("\nMatriz con %d modificacion: \n",k+1);
        imprime_matriz_aumentada(a,b,n);
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
    int i,j,n;
    float sum;

    n=filas;

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
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  sustitucion_didactica
 *  Description:  Sustitucion hacia atras demostrativo
 * =====================================================================================
 */

void sustitucion_didactica(double **a, double *x, int filas, int columnas, double *b)
{
    int i,j,n;
    float sum;

    n=filas;

    x[n-1]=b[n-1]/a[n-1][n-1];
    printf("\nx[%d] = %.6lf",n,x[n-1]);

    for(i=n-2;i>=0;i--)
    {
        sum=b[i];
        printf("\nx[%d] = (%.6lf ",i+1,sum);
        for(j=i+1;j<=n-1;j++)
        {
            sum = sum - a[i][j]*x[j];
            printf("- (%.6lf * %.6lf)", a[i][j],x[j]);
        }
        x[i] = sum / a[i][i];
        printf(" = %.6lf", x[i]);
    }

}
