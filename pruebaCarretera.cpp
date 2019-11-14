/*
 * pruebaCarretera.cpp
 *
 *  Created on: 31/10/2019
 *      Authors:  Pedro Miguel Carmona Broncano
 *                Rubén Marín Lucas
 */


#include "pruebaCarretera.h"

const float ERROR = 0.01;


void pruebasCarreteras(){

      pruebaConstructor();
      pruebasSetGetV();
      pruebasCaminoMinimo();
      pruebasArreglarCarreteras();

}



void pruebaConstructor(){

  cout << "--------------------------- INICIO PRUEBA CONSTRUCTOR ---------------------------" << endl;

  Carretera c;

  //Comprobamos que en el constructor por defecto el numero de vertices se iniciliza a 0

  if(c.getNumVertices() != 0) cout << "ERROR en inicializacion de numVertices" << endl;

  cout << "--------------------------- FIN PRUEBA CONSTRUCTOR ---------------------------" << endl;

}

void pruebasSetGetV(){

  cout << "--------------------------- INICIO PRUEBA SET/GET ---------------------------" << endl;


    Carretera c;

    // insertamos los vertices en Carretera c
    c.setCiudad("Madrid");
    c.setCiudad("Barcelona");
    c.setCiudad("Valencia");
    c.setCiudad("Santander");
    c.setCiudad("Malaga");

    // comprobamos que se han insertado bien por la variable numVertices
    if(c.getNumVertices() != 5) cout << "ERROR numVertices diferente" << endl;

    // comprobamos uno ha uno que se han insertado bien y en su orden
    if(c.getCiudad(0) != "Madrid") cout << "ERROR ciudad Madrid no se encuentra disponible" << endl;
    if(c.getCiudad(1) != "Barcelona") cout << "ERROR ciudad Barcelona no se encuentra disponible" << endl;
    if(c.getCiudad(2) != "Valencia") cout << "ERROR ciudad Valencia no se encuentra disponible" << endl;
    if(c.getCiudad(3) != "Santander") cout << "ERROR ciudad Santander no se encuentra disponible" << endl;
    if(c.getCiudad(4) != "Malaga") cout << "ERROR ciudad Malaga no se encuentra disponible" << endl;

    // imprimimos el conjunto de los vertices para comprobar que efectivamente se han introducido
    c.imprimirVector();

    // introducimos las distancias (las aristas) entre las ciudades (los vertices)
    c.setDistancia("Madrid", "Barcelona", 620.96);
    c.setDistancia("Barcelona", "Valencia", 352.08);
    c.setDistancia("Santander", "Madrid", 455.32);
    c.setDistancia("Santander", "Barcelona", 709.54);
    c.setDistancia("Madrid", "Malaga", 530.3 );
    c.setDistancia("Malaga", "Valencia", 619.8);

    // ahora comprobamos uno a uno si se ha introducido bien
    if(c.getDistancia("Madrid", "Barcelona") - ERROR > 620.96) cout << "ERROR entre distancia Madrid-Barcelona " << endl;
    if(c.getDistancia("Barcelona", "Valencia") - ERROR >  352.08) cout << "ERROR entre distancia Barcelona-Valencia" << endl;
    if(c.getDistancia("Santander", "Madrid")  - ERROR > 455.32) cout << "ERROR entre distancia Santander-Madrid" << endl;
    if(c.getDistancia("Santander", "Barcelona")  - ERROR > 709.54) cout << "ERROR entre distancia Santander-Barcelona" << endl;
    if(c.getDistancia("Madrid", "Malaga")  - ERROR > 530.3) cout << "ERROR entre distancia Madrid-Malaga" << endl;
    if(c.getDistancia("Malaga", "Valencia")  - ERROR > 619.8) cout << "ERROR entre distancia Malaga-Valencia" << endl;

    // imprimimos la matriz de adyacencia para comprobar que efectivamente se han introducido
    c.imprimirMatriz();

    cout << "--------------------------- FIN PRUEBA SET/GET ---------------------------" << endl;




}


void pruebasCaminoMinimo(){

  cout << "--------------------------- INICIO PRUEBA CAMINO MINIMO ---------------------------" << endl;


  Carretera c;
  mFloat C;
  mString P;

  // insertamos los vertices en Carretera c
  c.setCiudad("Madrid");
  c.setCiudad("Barcelona");
  c.setCiudad("Valencia");
  c.setCiudad("Santander");
  c.setCiudad("Malaga");

  // introducimos las distancias (las aristas) entre las ciudades (los vertices)
  c.setDistancia("Madrid", "Barcelona", 620.96);
  c.setDistancia("Barcelona", "Valencia", 352.08);
  c.setDistancia("Santander", "Madrid", 455.32);
  c.setDistancia("Santander", "Barcelona", 709.54);
  c.setDistancia("Madrid", "Malaga", 530.3 );
  c.setDistancia("Malaga", "Valencia", 619.8);

  // realizamos Floyd para nuestro grafo
  c.caminoMinimo(C, P);

  for (int i = 0; i < c.getNumVertices(); i++) {
    for (int j = 0; j < c.getNumVertices(); j++) {
        cout << C[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl << endl;

  for (int i = 0; i < c.getNumVertices(); i++) {
    for (int j = 0; j < c.getNumVertices(); j++) {
        cout << P[i][j] << " ";
    }
    cout << endl;
  }

  cout << "--------------------------- FIN PRUEBA CAMINO MINIMO ---------------------------" << endl;

//HAY QUE COMENTAR Y PONER COMO QUEDAN LAS MATRICES

}


void pruebasArreglarCarreteras(){

  cout << "--------------------------- INICIO PRUEBA ARREGLAR CARRETERAS ---------------------------" << endl;

  Carretera c, cn;

  // insertamos los vertices en Carretera c
  c.setCiudad("Madrid");
  c.setCiudad("Barcelona");
  c.setCiudad("Valencia");
  c.setCiudad("Santander");
  c.setCiudad("Malaga");

  // introducimos las distancias (las aristas) entre las ciudades (los vertices)
  c.setDistancia("Madrid", "Barcelona", 620.96);
  c.setDistancia("Barcelona", "Valencia", 352.08);
  c.setDistancia("Santander", "Madrid", 455.32);
  c.setDistancia("Santander", "Barcelona", 709.54);
  c.setDistancia("Madrid", "Malaga", 530.3 );
  c.setDistancia("Malaga", "Valencia", 619.8);

  //realizamos Prim para nuestro grafo
  c.arreglarCarreteras(cn);

  // imprimimos la matriz del nuevo grafo para ver el arbol de coste minimo
  cn.imprimirMatriz();

  cout << "--------------------------- FIN PRUEBA ARREGLAR CARRETERAS ---------------------------" << endl;
//HABRA QUE PONER ALGUNA MATRIZ XD
}
