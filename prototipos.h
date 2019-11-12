#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

#define BUFFER_SIZE 256

 void menu(void);
 void menu_raices(void);
 void menu_integracion(void);
 void menu_sel(void);
 void ctrl_menu_raices ( void );
 void ctrl_menu_sel ( void );
 void ctrl_menu_integracion( void );
 void entrada_cerrados (int op_met, char *);
 void entrada_abiertos (int op_met, char *);
 double biseccion(double, double, double, double *, int, int *, int ,char *);
 double rfalsa(double xa, double xb, double es, double *ea, int imax, int *iter, int tabla,char *);
 double newtonrap(double x0, double es, double *ea, int imax, int *iter, int tabla, char *, char *);
 double pfijo(double x0, double es, double *ea, int imax, int *iter, int tabla, char *);
 double secante(double x0, double x1, double es, double *ea, int imax, int *iter, int tabla, char *);
 
 void entrada_integracion ( void );
 double TrapecioM ( double h, int n, double *f );

 void NewtonInt(double *pX, double *pY, int n, double xi, double *ptrYint, double *ptrEa );

 void grafica( void );

 void lee_expresion (char *);
 double f(double);
 double df(double);
 double gf(double);

 //Funciones para arreglos dinamicos

 double * crear_vector (int tam );
 void lee_vector ( double *v, int tam );
 void imprime_vector ( double *, int);
 void destruye_vector ( double *v );

 double ** crear_matriz (int filas, int columnas );
 void lee_matriz ( double **m, int filas, int columnas );
 void imprime_matriz ( double **m, int filas, int columnas );
 void destruye_matriz(double **m, int filas, int columnas);

 void imprime_matriz_aumentada ( double **a, double *b, int tam );

 void gauss_simple ( void );
 void gauss_jordan ( void );
 void eliminacion(double **a, double *x, int filas, int columnas, double *b);
 void sustitucion(double **a, double *x, int filas, int columnas, double *b);
 

 void ctrl_menu_sel ( void );
 
 void sustitucion_didactica(double **a, double *x, int filas, int columnas, double *b);
 void eliminacion_didactica(double **a, double *x, int filas, int columnas, double *b);

 void regresion_entrada ( void );

 void regresion_poli ( int m, int n, double *apX, double *apY );
 

 void entrada_difdivnewton(void);


#endif // PROTOTIPOS_H_INCLUDED
