/*
 * pruebaCarretera.h
 *
 *  Created on: 31/10/2019
 *      Authors:  - Pedro Miguel Carmona Broncano
 									- Ruben Marin Lucas
 */

#ifndef PRUEBACARRETERA_H_
#define PRUEBACARRETERA_H_

#include "Carretera.h"

/*Se crea una Carretera por constructor por defecto y
se comprueba , que todos los parametros se inician correctamente*/
void pruebaConstructor();

/*Se crea un sistema de carreteras(Carretera) en el que se insertan distintas ciudades
y las distancias entre algunas de ellas y a partir de ahi se comprueban los diferentes
métodos de set y get*/
void pruebasSetGetV();

/*Se crea un sistema de carreteras(Carretera) en el que se insertan distintas ciudades
y las distancias entre algunas de ellas. A partir de ahi se comprueba la funcionalidad del
algoritmo de Floyd(caminoMinimo)*/
void pruebasCaminoMinimo();

/*Se crea un sistema de carreteras(Carretera) en el que se insertan distintas ciudades
y las distancias entre algunas de ellas. A partir de ahi se comprueba la funcionalidad del
algoritmo de Prim(arreglarCarreteras)*/
void pruebasArreglarCarreteras();

//prueba longitudtotal()

// llamada a todos los modulos de prueba de esta clase
void pruebasCarreteras();


#endif /* PRUEBACARRETERA_H_ */
