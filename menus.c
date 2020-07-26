/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  menu
 *  Description:  Menu General de todos los metodos numericos
 * =====================================================================================
 */
 

#include "header.h"
#include "prototipos.h"

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
    printf("\nC.- Metodo del Punto Fijo");
    printf("\nD.- Metodo de Newton-Raphson");
    printf("\nE.- Metodo de la Secante");

    printf("\n\n---- Metodos de Interpolacion");
    printf("\nG.-Metodo de Diferencias Divididas de Newton");
 
    printf("\n\nZ.- Salir\n\n");

}		/* -----  end of function menu_raices  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  menu_integracion
 *  Description:  Menu que imprime las opciones de los metodos de integración
 * =====================================================================================
 */
	void
menu_integracion ( void )
{
	printf ( "Metodos de integracion numerica" );
	printf ( "\n\nSeleccione una Opcion:" );
	printf ( "\nA.- Metodo del Trapecio - Multiple" );
	printf ( "\n" );
	printf ( "\n" );
	printf ( "\n" );
	printf ( "\n" );
	printf ( "\n" );
	printf ( "\n" );
	return ;
}		/* -----  end of function menu_integracion  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  menu_sel
 *  Description:  Menu que imprime las opciones de los metodos de SEL
 * =====================================================================================
 */
	void
menu_sel ( void )
{
	printf ( "Metodos de SEL" );
	printf ( "\n\nSeleccione una Opcion:" );
	printf ( "\nA.- Metodo de Gauss Simple" );
	printf ( "\nB.- Metodo de Gauss Jordan" );
	printf ( "\n" );
	printf ( "\n" );
	printf ( "\n" );
	printf ( "\n" );
	printf ( "\n" );
	return ;
}		/* -----  end of function menu_integracion  ----- */
