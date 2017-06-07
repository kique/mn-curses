<<<<<<< HEAD

#include "header.h"
#include "prototipos.h"
=======
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
>>>>>>> c30c26b28c20d0c0a86dee8566a09720d27f001f


/* 
 * ===  FUNCTION  ======================================================================
<<<<<<< HEAD
 *         Name:  TrapecioM
=======
 *         Name:  Trapeciom
>>>>>>> c30c26b28c20d0c0a86dee8566a09720d27f001f
 *  Description:  
 * =====================================================================================
 */
	double
<<<<<<< HEAD
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
=======
Trapeciom ( double a, double b, int n )
{
	
	return ;
}		/* -----  end of function Trapeciom  ----- */

>>>>>>> c30c26b28c20d0c0a86dee8566a09720d27f001f
