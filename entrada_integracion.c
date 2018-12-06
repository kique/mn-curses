
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
	char expresion[BUFFER_SIZE];
	int n,i;

	void *f2;  /*  Evaluators for function and function derivative.  */
	

	printf("\nDar el valor inicial del intervalo: ");
	scanf("%lf",&a);
	printf("\nDar el valor final del intervalo: ");
	scanf("%lf",&b);
	printf("\nDar el numero de segmentos: ");
	scanf("%d",&n);
	printf ( "\nEscriba la expresion a integrar:" );
	lee_expresion(expresion);
 
  	/*  Create evaluator for function.  */
    	f2 = evaluator_create (expresion);
    	assert (f2);

	fx = crear_vector(n);

	h = (b-a)/n;
	
		
	for ( i = 0; i < n; i++ ) {
		fx[i] = evaluator_evaluate_x(f2,a + i*h); //Se incrementa h veces desde el valor inicial
	}

	

	printf("\nEl valor de la integral es: %lf", TrapecioM(h,n,fx));
  	
	/*  Destroy evaluators.  */
  	evaluator_destroy (f2);

	A
}		/* -----  end of function entrada_integracion  ----- */
