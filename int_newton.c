/*
 * int_newton.c
 *
 *  Created on: Nov 20, 2012
 *      Author: enrique
 */

#include <stdlib.h>

void NewtonInt(double *pX, double *pY, int n, double xi, double *ptrYint, double *ptrEa)
{
	int i,j,orden;
	double **fdd, xterm, yint2;

	fdd = (double **) malloc(n*sizeof(double));

	for(i=0;i<n;i++)
	{
		fdd[i] = (double *) malloc (n * sizeof(double));
	}

	for(i=0; i<n; i++)
	{
		fdd[i][0] = pY[i];
	}

	for(j=1;j<n;j++)
	{
		for(i=0;i<n-j;i++)
		{
			fdd[i][j]=(fdd[i+1][j-1] - fdd[i][j-1])/(pX[i+j]-pX[i]);
		}
	}
	xterm = 1;
	ptrYint[0] = fdd[0][0];

	for(orden=1;orden<=n;orden++)
	{
		xterm = xterm * (xi - pX[orden-1]);
		yint2 = ptrYint[orden-1] + fdd[0][orden]*xterm;
		ptrEa[orden-1] = yint2 - ptrYint[orden-1];
		ptrYint[orden] = yint2;
	}

	for(i=0;i<n;i++)
	{
		free(fdd[i]);
	}
	free(fdd);
}
