#
## Makefile
#

FUENTES.c=main.c int_newton.c funciones.c menu.c raices-cerrados.c entrada_raices.c raices-abiertos.c grafica.c
INCLUDES=/usr/include/plplot 
CFLAGS=-ggdb
LIBS= -lm -lncurses -lplplotd 
PROGRAMA=main

OBJETOS=$(FUENTES.c:.c=.o)

# Destino (target) especial (inicia con .)
.KEEP_STATE:

debug := CFLAGS=-ggdb

all debug: $(PROGRAMA)

$(PROGRAMA): $(INCLUDES) $(OBJETOS)
	$(LINK.c) -o $@ $(OBJETOS) $(LIBS)

clean:
	rm -f $(PROGRAMA) $(OBJETOS)
