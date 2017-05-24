
#include "header.h"
#include "prototipos.h"


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  TrapecioM
 *  Description:  
 * =====================================================================================
 */
	double
TrapecioM ( double h, int n, double *f )
{
	double sum;

	sum = f[0];

	
	for ( i=1; i< n-1; i++ ) {
		sum = sum + 2*f[i];
	}

	sum = sum + f[n];
	
	return h*sum/2;
}		/* -----  end of function TrapecioM  ----- */
