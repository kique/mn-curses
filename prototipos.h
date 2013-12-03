#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

 void menu(void); 
 void entrada_cerrados (int op_met);
 void entrada_abiertos (int op_met);
 void entrada_cerrados (int);
 double biseccion(double, double, double, double *, int, int *, int );
 double rfalsa(double xa, double xb, double es, double *ea, int imax, int *iter, int tabla);
 double newtonrap(double x0, double es, double *ea, int imax, int *iter, int tabla);
 double pfijo(double x0, double es, double *ea, int imax, int *iter, int tabla);
 double secante(double x0, double x1, double es, double *ea, int imax, int *iter, int tabla);
 void grafica( void );
 double f(double);
 double df(double);
 double gf(double);


#endif // PROTOTIPOS_H_INCLUDED
