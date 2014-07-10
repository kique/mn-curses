/*
 * =====================================================================================
 *
 *       Filename:  func_menus.c
 *
 *    Description:  Funciones para el funcionamiento de los menus
 *
 *        Version:  1.0
 *        Created:  10/12/13 10:52:46
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

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  menu_raices
 *  Description:  Selectiva para l menu de raices
 * =====================================================================================
 */
    void
ctrl_menu_raices ( void )
{
    char opc,resp;
    
    do{
    system("clear");

    menu_raices();
    scanf(" %c",&opc);

        switch(toupper(opc))
	{
	    case 'A':
		//Entrada Metodo de Biseccion
                entrada_cerrados(1);
                break;
            case 'B':
		//Entrada metodo de Regla Falsa
                entrada_cerrados(2);
                break;
            case 'C':
		//Entrada Metodo Punto Fijo
                entrada_abiertos(0);
                break;
            case 'D':
		//Entrada Metodo Newton - Raphson
                entrada_abiertos(1);
                break;
            case 'E':
		//Entrada Metodo Secante
                entrada_abiertos(2);
                break;
	    case 'Z':
		break;

	    default:
                printf("\nOpcion Invalida\n");
        }
        printf("\n\nDeseas realizar otro calculo?: (s/n)");
        scanf(" %c",&resp);
    }while(resp=='s');

}		/* -----  end of function menu_raices  ----- */


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ctrl_menu_sel
 *  Description:  Control del menu de SEL
 * =====================================================================================
 */
    void
ctrl_menu_sel ( void )
{
    char opc,resp;
    
    do{
    system("clear");

    menu_sel();
    scanf(" %c",&opc);

        switch(toupper(opc))
	{
	    case 'A':
		//Metodo de Gauss Simple
                gauss_simple();
                break;
            case 'B':
		//Entrada metodo de 
		gauss_jordan();
                break;
            case 'C':
		//
                break;
            case 'D':
		//
                break;
            case 'E':
		//
                break;
	    case 'Z':
		break;

	    default:
                printf("\nOpcion Invalida\n");
        }
        printf("\n\nDeseas realizar otro calculo?: (s/n)");
        scanf(" %c",&resp);
    }while(resp=='s');

}		/* -----  end of function menu_sel  ----- */
