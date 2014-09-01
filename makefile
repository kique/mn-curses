#
## Makefile
#

CC = gcc # Compiler to use
OPTIONS = -O2 -g -Wall -lm -lncurses -lplplotd -lmatheval -lcdk -lgsl -lgslcblas# -g for debug, -O2 for optimise and -Wall additional messages
INCLUDES = -I/usr/include/plplot -I/usr/local/include -I/usr/local/lib # Directory for header file
FUENTES=\
		main.c \
		funciones.c \
		menus.c \
		raices-cerrados.c \
		entrada_raices.c \
		raices-abiertos.c \
		grafica.c\
		interpolacion.c\
		func_menus.c\
		io_matriz.c\
		gauss.c\
		op_matrices.c\


#FUENTES=%.c
OBJS = ${FUENTES:.c=.o} # List of objects to be build
.PHONY: all clean # To declare all, clean are not files
 
all: ${OBJS} 
	@echo "Building.." # To print "Building.." message
	${CC} ${INCLUDES} ${OBJS} -o metodos_bin ${OPTIONS} 

%.o: %.c  # % pattern wildcard matching
	${CC}  -c $*.c ${INCLUDES} ${OPTIONS} 
list:
	@echo $(shell ls) # To print output of command 'ls'
     
clean:
	@echo "Cleaning up.."
	-rm -rf *.o # - prefix for ignoring errors and continue execution
	-rm metodos_bin
