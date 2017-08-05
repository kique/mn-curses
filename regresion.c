#include "header.h"
#include "prototipos.h"
#include <gsl/gsl_linalg.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  regresion_entrada
 *  Description:  
 * =====================================================================================
 */
	void
regresion_entrada ( void )
{
	double *apX, *apY;
	int n, m;


	printf("Dar el numero de datos: ");
	scanf("%d",&n);


	apX = crear_vector(n);
	apY = crear_vector(n);

	printf("\nDar el grado del polinomio a ajustar: ");
	scanf("%d",&m);
	printf("\n\nDar los valores de las abcisas: ");
	lee_vector(apX,n);
	printf("\n\nDar los valores de las ordenadas: ");
	lee_vector(apY,n);


	regresion_poli(m,n,apX,apY);

	destruye_vector(apX);
	destruye_vector(apY);

}		/* -----  end of function regresion_entrada  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  regresion_poli
 *  Description:  
 * =====================================================================================
 */
	void
regresion_poli ( int m, int n, double *apX, double *apY )
{
	int i, j, k, l;

	double **apA, *apYReg, *apSol, sum;


	apA = crear_matriz(m+1,m+1);                /* Creamos la matriz cuadrada de nxn  */

	apYReg = crear_vector(m+1);               /* Creamos el vector para los terminos independientes */

	apSol = crear_vector(m+1);


	if ( n <= m+1 ) {
		printf("\nLa regresión no es posible");
		return;
	}


	for ( i=0; i < m+1 ; i++ )
	{

		for ( j=0; j <= i; j++ ) {

			k = i + j; // Ajuste en algoritmo de Chapra porque el indice comienza desde 0 y no es necesario restar 2 para generar exponentes
			sum = 0;


			for ( l = 0; l < n; l++ ) {

				sum = sum + pow( apX[l] , k );

			}

			apA[i][j] = sum;
			apA[j][i] = sum;

		}

		sum = 0;

		for ( l=0; l < n; l++ ) {

			sum = sum + apY[l]*pow(apX[l],i); // Ajuste del Algoritmo de Chapra, no se resta 1 para generar exponentes

		}

		apYReg[i] = sum;

	}


	/*-----------------------------------------------------------------------------
	 *  Una vez obtenidas las ecuaciones normales se procede a realizar el metodo de gauss
	 *  para la solucion del sistema de ecuaciones lineals para obtener el valor de los
	 *  coeficientes de la funcion
	 *-----------------------------------------------------------------------------*/
/* 
 * 	printf("\n\n");
 * 
 * 	imprime_matriz(apA,m+1,m+1);
 * 
 * 	printf("\n\n");
 * 
 * 	imprime_vector(apYReg,m+1);
 */

	/* 	eliminacion(apA,apSol,m,m,apYReg);
	 * 
	 * 	sustitucion(apA, apSol, m, m, apYReg);
	 * 
	 * 	imprime_vector(apSol, m+1);
	 * 
	 */

	double a_data[] = {  6,  15,  55, 
			    15,  55, 225, 
                      	    55, 225, 979 };

	int dim = m+1;

	gsl_matrix_view ma
		= gsl_matrix_view_array (a_data,dim, dim);

	gsl_vector_view b
		= gsl_vector_view_array (apYReg, dim);

	gsl_vector *x = gsl_vector_alloc (dim);

	int s;

	gsl_permutation * p = gsl_permutation_alloc (dim);

	gsl_linalg_LU_decomp (&ma.matrix, p, &s);

	gsl_linalg_LU_solve (&ma.matrix, p, &b.vector, x);

	printf ("x = \n");
	gsl_vector_fprintf (stdout, x, "%g");

	gsl_permutation_free (p);
	gsl_vector_free (x);


	destruye_matriz(apA,m+1,m+1);

	destruye_vector(apSol);

	destruye_vector(apYReg);

}		/* -----  end of function regresion_poli  ----- */
