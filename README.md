Métodos Numéricos con Ncurses en lenguaje C
===========================================

El objetivo de este proyecto es tener un programa con los principales Métodos Numéricos que se enseñan en cursos de 
nivel licenciatura con el fin de permitir al docente ejemplificar la implementacion y la diferencias entre cada uno de ellos
al tener diferentes algoritmos que comparar.

La idea es obtener un programa codificado en lenguaje ANSI C, con el uso de diferentes bibliotecas libres de diverso propósito
que complementen la funcionalidad del programa con fines académicos, por ejemplo:

|Biblioteca      |  Uso                               |
|----------------|------------------------------------|
|Matheval        | Análisis de Expresiones Matemáticas|
|Matplotlib      | Graficación de funciones           |
|CDK             | Manejo de pantalla con Ncurses     |
|GSL             | Biblioteca científica GNU          |
                          


Los métodos numéricos a implementar son los siguientes


| Método                                       | Avance % |
|----------------------------------------------|----------|
|* Localización de Raíces                      |          |
|  * Métodos Cerrados                          |          |
|    * Bisección                               |   100%   |
|    * Regla Falsa                             |   100%   |
|  * Métodos Abiertos                          |          |
|    * Punto Fijo                              |   100%   |
|    * Newton-Raphson                          |   100%   |
|    * Secante                                 |   100%   |
|* Solución de Sistemas de Ecuaciones Lineales |          |
|  * Método de Gauss Simple                    |   100%   |
|  * Método de Gauss Seidel                    |   100%   |
|* Métodos de Interpolación                    |          |
|  * Diferencias Divididas de Newton           |   100%   |


También se han implementado la lectura de funciones matemáticas leidas por teclado ygraficacion de funciones leidas del mismo modo.
