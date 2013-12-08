#include "header.h"
#include "prototipos.h"

int main()
{
    char opc,rep;

    do{
	system("clear");
        menu();
	scanf("%c",&opc);

        switch(opc)
        {
            case '0':
                grafica();
                break;
            case '1':
                entrada_cerrados(1);
                break;
            case '2':
                entrada_cerrados(2);
                break;
            case '3':
                entrada_abiertos(0);
                break;
            case '4':
                entrada_abiertos(1);
                break;
            case '5':
                entrada_abiertos(2);
                break;
            case '6':
       		entrada_difdivnewton();
	        break;
            case '10':
                printf("\nAdios!");
                break;
 
	    default:
                printf("\nOpcion Invalida\n");
        }
        printf("\n\nDeseas realizar otro calculo?: (s/n)");
        scanf(" %c",&rep);
	getchar();
	
    }while(rep=='s');

    return 0;
}
