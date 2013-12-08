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

    printf("\nLocalizacion de Raices");
    printf("\n\nB.- Metodo de la Biseccion");
    printf("\nC.- Metodo de la Regla Falsa");

    printf("\n\n---- Metodos de Abiertos");
    printf("\nD.- Metodo del Punto Fijo");
    printf("\nE.- Metodo de Newton-Raphson");
    printf("\nF.- Metodo de la Secante");

    printf("\n\n---- Metodos de Interpolacion");
    printf("\nG.-Metodo de Diferencias Divididas de Newton");
 
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
    printf("Programas para localizacion de Raices");
    printf("\n\nSeleccione una Opcion");

    printf("\nA.- Graficar la Funcion");

    printf("\n---- Metodos de Intevalo:");
    printf("\n\nB.- Metodo de la Biseccion");
    printf("\nC.- Metodo de la Regla Falsa");

    printf("\n\n---- Metodos de Abiertos");
    printf("\nD.- Metodo del Punto Fijo");
    printf("\nE.- Metodo de Newton-Raphson");
    printf("\nF.- Metodo de la Secante");

    printf("\n\n---- Metodos de Interpolacion");
    printf("\nG.-Metodo de Diferencias Divididas de Newton");
 
    printf("\n\nZ.- Salir\n\n");
}

}		/* -----  end of function menu_raices  ----- */
