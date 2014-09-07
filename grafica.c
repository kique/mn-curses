/*
 * =====================================================================================
 *
 *       Archivo:  grafica_simple1.c
 *
 *    Descripcion:  ejemplo grafica simple
 *
 *        Version:  1.0
 *        Creado:  10/11/13 10:34:34
 *       Revision:  none
 *       Compilador: 
 *
 *         Autor:  YOUR NAME (), 
 *   COmpilacion: gcc grafica_simple1.c -lplplotd -lm -I/usr/include/plplot -o grafica_simple1.bin 
 *
 * =====================================================================================
 */

#include "plcdemos.h"
#include "header.h" 
#include "prototipos.h"

#define NSIZE    101
#define BUFFER_SIZE 256 

    void
grafica( void )
{

    PLFLT *x, *y, xtemp;
    PLFLT xmin, xmax, ymin = -1., ymax = 1.;
    PLINT space0 = 0, mark0 = 0, space1 = 1500, mark1 = 1500;
    
    int n,i,length;

    double xa, xb, inc;
    char buffer[BUFFER_SIZE]; //Buffer para almacenar la expresion matematica para matheval
   
    void *funcion;		/*  Evaluators for function and function derivative.  */
 
    
    printf("f(X) = ");
    scanf("%s",buffer);    
    //fgets (buffer, BUFFER_SIZE, stdin);
    length = strlen (buffer);
    if (length > 0 && buffer[length - 1] == '\n')
	buffer[length - 1] = '\0';
    
    /*  Create evaluator for function.  */
    funcion = evaluator_create(buffer);
    assert(funcion);




    printf("\nIngrese el límite inferior del intervalo: ");
    scanf("%lf",&xa);
    printf("\nIngrese el límite superior del intervalo: ");
    scanf("%lf",&xb);
    printf("\nIngrese el incremento: ");
    scanf("%lf",&inc);
    
    xmin = xa;
    xmax = xb;

    n=(int) (xb-xa)/inc+1;

    x = (PLFLT *) malloc(n*sizeof(PLFLT));
    y = (PLFLT *) malloc(n*sizeof(PLFLT));

    //Prepare data to be plotted.
	for ( i = 0; i < n ; i++ )
	{
	    x[i] = (PLFLT) ( xa );
	    xtemp = x[i];
	    y[i] = ymax * (PLFLT) evaluator_evaluate_x(funcion,xtemp);
	    xa=xa+inc;
	}

    // Parse and process command line arguments
    //plparseopts( &argc, argv, PL_PARSE_FULL );
    
    plsdev("xwin"); //Se elige el driver para salida grafica

    // Initialize plplot
    plinit();

    // Create a labelled box to hold the plot.
    plenv( xmin, xmax, ymin, ymax, 0, 0 );
    plcol0(2);
    pllab( "x", "f(x)", "Grafica de la Funcion" );

    plstyl( 1, &mark1, &space1 );
    plcol0( 2 );
    plbox( "g", 1.0, 0, "g", 0.5, 0 );
    plstyl( 0, &mark0, &space0 );

    // Plot the data that was prepared above.
    plcol0(3);//Establece el color verde para dibujar los datos
    plline( n, x, y );

    // Close PLplot library
    plend();
    free(x);
    free(y);

    evaluator_destroy(funcion);
    //exit( 0 );
}


