/*
 * =====================================================================================
 *
 *       Filename:  interpolacion.c
 *
 *    Description:  Funciones con los métodos de Interpolación
 *
 *        Version:  1.0
 *        Created:  03/12/13 18:48:07
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enrique Martínez Roldán (), 
 *   Organization:  IPN ESIME Zacatenco
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include <ncurses.h>

void NewtonInt(double *pX, double *pY, int n, double xi, double *ptrYint, double *ptrEa );

void entrada_difdivnewton()
{
	double *px, *py, xi, *yint, *ea;
	int n,i;

	initscr();
	move(1,5);
	printw("\nCuantos puntos desea trabajar: ");
	scanw("%d",&n);



	px = (double *) malloc(n*sizeof(double));
	py = (double *) malloc(n*sizeof(double));
	yint = (double *) malloc(n*sizeof(double));
	ea = (double *) malloc(n*sizeof(double));

	move(3,5);
	for (i=0; i<n; i++)
	{
		printw("Dar el punto %d (x y): ",i);
		scanw("%lf %lf",&px[i],&py[i]);
	}

	for(i=0;i<n;i++)
	{
		printw("\n(%9.5lf , %9.5lf)",px[i],py[i]);
	}

	printw("\nQue valor de x deseas interpolar?");
	scanw("%lf",&xi);

	NewtonInt(px,py,n,xi,yint,ea);

	printw("\n\nLa interpolacion en x = %lf es:",xi);
	printw("\n\nGrado |   f(x)   |   Error");

	for(i=0;i<n;i++)
	{
		printw("\n%3d   |%9.6lf | %9.6lf ",i,yint[i],ea[i]);
	}

	free(px);
	free(py);
	free(yint);
	free(ea);

	getch();

	endwin();

	return 0;
}

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
}
}
}
}
}
}
}
