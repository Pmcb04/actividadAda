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

/*Se crea una via por constructor parametrizado y
se comprueba, que todos los parametros se inician correctamente */
void pruebasParametrizadoV();

/*Se crea una via por constructor por defecto y
se introducen los parametros por los metodos set y se comprueban de que
todos los parametros se inician correctamente*/
void pruebasSetGetV();

//Distintos algoritmos a probar

// llamada a todos los modulos de prueba de esta clase
void pruebasVias();


#endif /* PRUEBACARRETERA_H_ */
