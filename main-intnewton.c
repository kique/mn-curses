/*
 ============================================================================
 Name        : inter-newton.c
 Author      : EMR
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>
#include <ncurses.h>

void NewtonInt(double *pX, double *pY, int n, double xi, double *ptrYint, double *ptrEa );

int main()
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

