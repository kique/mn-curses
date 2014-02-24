/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  menu
 *  Description:  Menu General de todos los metodos numericos
 * =====================================================================================
 */
 

#include "header.h"

void menu(void)
{
    printf("Metodos Numericos");
    printf("\n\nSeleccione una Opcion");

    printf("\nA.- Graficar una Funcion");
    printf("\nB.-Localizacion de Raices");
    printf("\nC.-Solucion de SEL");
    printf("\nD.-Ajuste de Funciones");
    printf("\nE.-Interpolacion");
    printf("\nF.-Diferenciacion");
    printf("\nG.-Integracion");
    printf("\nH.-Solucion de EDO");
    printf("\n");
    printf("\n");
 
    printf("\n\nZ.- Salir\n\n");
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  menu_raices
 *  Description:  Menu de metodos para localizacion de raices 
 * =====================================================================================
 */
    void
menu_raices ( void )
{
    printf("Metodos para localizacion de Raices");
    printf("\n\nSeleccione una Opcion");

    printf("\n\n---- Metodos de Intervalo");

    printf("\nA.-Metodo de Biseccion");
    printf("\nB.-Metodo de Regla Falsa");

    printf("\n\n---- Metodos de Abiertos");
    printf("\nD.- Metodo del Punto Fijo");
    printf("\nE.- Metodo de Newton-Raphson");
    printf("\nF.- Metodo de la Secante");

    printf("\n\n---- Metodos de Interpolacion");
    printf("\nG.-Metodo de Diferencias Divididas de Newton");
 
    printf("\n\nZ.- Salir\n\n");
}

		/* -----  end of function menu_raices  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  menu_sel
 *  Description:  Menu para Solucion de Sitemas de Ecuaciones Lineales 
 * =====================================================================================
 */
    void
menu_sel ( void )
{
    printf("Metodos para la Solucion de Ecuaciones Lineales");
    printf("\n\nSeleccione una Opcion");

    printf("\nA.-Metodo de Gauss");
    printf("\nB.-Metodo de Gauss Modificado");
    printf("\nC.-Metodo de Gauss-Jordan");


    printf("\n\n---- Metodos Iterativos");
    printf("\nD.- Metodo Gauss-Seidel");
 
    printf("\n\nZ.- Salir\n\n");
   
}		/* -----  end of function menu_sel  ----- */


