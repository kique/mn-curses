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
  printf("\nC.- Metodo del Punto Fijo");
  printf("\nD.- Metodo de Newton-Raphson");
  printf("\nE.- Metodo de la Secante");

  printf("\n\nZ.- Salir\n\n");
}

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  menu_sel
 *  Description:  
 * =====================================================================================
 */
  void
menu_sel ( void )
{
  printf("Metodos de Eliminacion");
  printf("\n\nA.- Eliminacionn de Gauss simple");
  printf("\n\nB.- Eliminacin de Gauss-Jordan");
  printf("\n\n");


  return ;
}		/* -----  end of function menu_sel  ----- */
