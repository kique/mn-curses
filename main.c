/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Programa principal de Metodos Numericos
 *
 *        Version:  0.01
 *        Created:  09/12/13 23:40:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Enrique Martinez Roldan (emr), enrique.roldan@gmail.com
 *   Organization:  IPN ESIME Zacatenco
 *
 * =====================================================================================
 */

#include "header.h"
#include "prototipos.h"

/**
 * @brief 
 *
 * Esta es la funcion principal donde se ejecuta el menu con las opciones generales
 * para llevar a los respectivos sub menus, los cuales se desplegan llamando a sus 
 * respectivas funciones
 *
 * @return 0
 */
int main()
{
  char opc,rep;

  do{
    system("clear");
    menu();
    scanf(" %c",&opc);

    switch(toupper(opc))
    {
      case 'A':
        grafica();
        break;
      case 'B':
        menu_raices();
        ctrl_menu_raices();
        break;
      case 'C':                
//        menu_sel();
        ctrl_menu_sel();
        break;
      case 'D':
        break;
      case 'E':
        entrada_difdivnewton();
	break;
      case 'F':
//        menu_integracion();
	break;
      case 'G':
        break;
      case 'H':
        break;
      case 'Z':
        printf("\nAdios!\n\n");
        break;

      default:
        printf("\nOpcion Invalida\n");
    }

    if(opc != 'z')
    {
      printf("\n\nDeseas realizar otro calculo?: (s/n)");
      scanf(" %c",&rep);
    }
    //getchar();

  }while(rep=='s');

  return 0;
}
