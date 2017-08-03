
#include "header.h"
#include "prototipos.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  entrada_integracion
 *  Description:  
 * =====================================================================================
 */
void
entrada_integracion ( void )
{
	double a,b,h,*fx;
	int n,i;

	printf("\nDar el valor inicial del intervalo: ");
	scanf("%lf",&a);
	printf("\nDar el valor final del intervalo: ");
	scanf("%lf",&b);
	printf("\nDar el numero de segmentos: ");
	scanf("%d",&n);

	fx = crear_vector(n);

	h = (b-a)/n;
	
		
	for ( i = 0; i < n; i++ ) {
		fx[i] = f(a + i*h); //Se incrementa h veces desde el valor inicial
	}

	printf("\nEl valor de la integral es: %lf", TrapecioM(h,n,fx));

}		/* -----  end of function entrada_integracion  ----- */
