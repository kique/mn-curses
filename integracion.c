/*
 * =====================================================================================
 *
 *       Filename:  integracion.c
 *
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  22/05/17 12:15:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include "header.h"
#include "prototipos.h"


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
Trapeciom ( double a, double b, int n )
{
	
	return ;
}		/* -----  end of function Trapeciom  ----- */


