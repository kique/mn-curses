#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

 void menu(void);
 void menu_raices(void);
 void menu_sel(void);
 void ctrl_menu_raices ( void );
 void ctrl_menu_sel ( void );
 void entrada_cerrados (int op_met);
 void entrada_abiertos (int op_met);
 void entrada_cerrados (int);
 double biseccion(double, double, double, double *, int, int *, int ,char *);
 double rfalsa(double xa, double xb, double es, double *ea, int imax, int *iter, int tabla,char buffer[]);
 double newtonrap(double x0, double es, double *ea, int imax, int *iter, int tabla);
 double pfijo(double x0, double es, double *ea, int imax, int *iter, int tabla);
 double secante(double x0, double x1, double es, double *ea, int imax, int *iter, int tabla);
 void grafica( void );
 double f(double);
 double df(double);
 double gf(double);

 void gauss_simple ( void );
 void gauss_jordan ( void );
 void eliminacion(double **a, double *x, int filas, int columnas, double *b);
 void sustitucion(double **a, double *x, int filas, int columnas, double *b);
 double ** crear_matriz (int filas, int columnas );
 double * crear_vector (int tam );
 void destruye_matriz(double **m, int filas, int columnas);
 void lee_matriz ( double **m, int filas, int columnas );
 void lee_vector ( double *v, int tam );
 void imprime_matriz ( double **m, int filas, int columnas );
 void imprime_vector ( double *, int);
 void destruye_vector ( double *v );
 void ctrl_menu_sel ( void );
 void imprime_matriz_aumentada ( double **a, double *b, int tam );

 
 void sustitucion_didactica(double **a, double *x, int filas, int columnas, double *b);
 void eliminacion_didactica(double **a, double *x, int filas, int columnas, double *b);

 void entrada_difdivnewton(void);


#endif // PROTOTIPOS_H_INCLUDED
