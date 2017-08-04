#include "header.h"
#include "prototipos.h"



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

	double **apA, *apYReg, sum;


	apA = crear_matriz(m+1,m+1);                /* Creamos la matriz cuadrada de nxn  */

	apYReg = crear_vector(m+1);               /* Creamos el vector para los terminos independientes */


	if ( n <= m+1 ) {
		printf("\nLa regresión no es posible");
		return;
	}

	
	for ( i=0; i <= m+1 ; i++ )
	{

		for ( j=0; j <= i; j++ ) {
			k = i + j - 2;
			sum = 0;


			for ( l = 0; l <= n; l++ ) {
				sum = sum + pow( apX[l] , k );
			}
			apA[i][j] = sum;
			apA[j][i] = sum;
		}

		sum = 0;
		
		for ( l=0; l <= n; l++ ) {
			sum = sum + apY[l]*pow(apX[l],i-1);
		}
		apYReg[i] = sum;
	}


	/*-----------------------------------------------------------------------------
	 *  Una vez obtenidas las ecuaciones normales se procede a realizar el metodo de gauss
	 *  para la solucion del sistema de ecuaciones lineals para obtener el valor de los
	 *  coeficientes de la funcion
	 *-----------------------------------------------------------------------------*/
	
	imprime_matriz_aumentada(apA, apYReg,n);

	destruye_matriz(apA,m+1,m+1);

	destruye_vector(apYReg);



}		/* -----  end of function regresion_poli  ----- */
