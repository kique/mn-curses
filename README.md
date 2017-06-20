  1 Métodos Numéricos con Ncurses en lenguaje C
  2 ===========================================
  3 
  4 El objetivo de este proyecto es tener un programa con los principales Métodos Numéricos que se enseñan en cursos de
  5 nivel licenciatura con el fin de permitir al docente ejemplificar la implementacion y la diferencias entre cada uno de ellos
  6 al tener diferentes algoritmos que comparar.
  7 
  8 La idea es obtener un programa codificado en lenguaje ANSI C, con el uso de diferentes bibliotecas libres de diverso propósito
  9 que complementen la funcionalidad del programa con fines académicos, por ejemplo:
 10 
 11 |Biblioteca      |  Uso                               |
 12 |----------------|------------------------------------|
 13 |Matheval        | Análisis de Expresiones Matemáticas|
 14 |Matplotlib      | Graficación de funciones           |
 15 |CDK             | Manejo de pantalla con Ncurses     |
 16 |GSL             | Biblioteca científica GNU          |
 17 
 18 
 19 
 20 Los métodos numéricos a implementar son los siguientes
 21 
 22 
 23 | Método                                       | Avance % |
 24 |----------------------------------------------|----------|
 25 |* Localización de Raíces                      |          |
 26 |  * Métodos Cerrados                          |          |
 27 |    * Bisección                               |   100%   |
 28 |    * Regla Falsa                             |   100%   |
 29 |  * Métodos Abiertos                          |          |
 30 |    * Punto Fijo                              |   100%   |
 31 |    * Newton-Raphson                          |   100%   |
 32 |    * Secante                                 |   100%   |
 33 |* Solución de Sistemas de Ecuaciones Lineales |          |
 34 |  * Método de Gauss Simple                    |   100%   |
 35 |  * Método de Gauss Seidel                    |   100%   |
 36 |* Métodos de Interpolación                    |          |
 37 |  * Diferencias Divididas de Newton           |   100%   |
 38 
 39 
 40 También se han implementado la lectura de funciones matemáticas leidas por teclado ygraficacion de funciones leidas del mismo modo.
