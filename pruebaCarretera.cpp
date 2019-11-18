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
      pruebasLongitudTotal();
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

  // metemos el resultado en la matriz C esperada (Ce) y en la matriz P esperada (Pe)
  mFloat Ce;
  mString Pe;

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

  // rellenamos las matrices esperadas para
  // posteriormente mostrarlas y comparar con la resultante

  Ce[0][0] = 0;
  Ce[0][1] = 620.96;
  Ce[0][2] = 973.04;
  Ce[0][3] = 455.32;
  Ce[0][4] = 530.3;

  Ce[1][0] = 620.96;
  Ce[1][1] = 0;
  Ce[1][2] = 352.08;
  Ce[1][3] = 709.54;
  Ce[1][4] = 971.88;

  Ce[2][0] = 973.04;
  Ce[2][1] = 352.08;
  Ce[2][2] = 0;
  Ce[2][3] = 1061.62;
  Ce[2][4] = 619.8;

  Ce[3][0] = 455.32;
  Ce[3][1] = 709.54;
  Ce[3][2] = 1061.62;
  Ce[3][3] = 0;
  Ce[3][4] = 985.62;

  Ce[4][0] = 530.3;
  Ce[4][1] = 971.88;
  Ce[4][2] = 619.8;
  Ce[4][3] = 985.62;
  Ce[4][4] = 0;

  Pe[0][0] = "null";
  Pe[0][1] = "null";
  Pe[0][2] = "Barcelona";
  Pe[0][3] = "null";
  Pe[0][4] = "null";

  Pe[1][0] = "null";
  Pe[1][1] = "null";
  Pe[1][2] = "null";
  Pe[1][3] = "null";
  Pe[1][4] = "Valecia";

  Pe[2][0] = "Barcelona";
  Pe[2][1] = "null";
  Pe[2][2] = "null";
  Pe[2][3] = "Barcelona";
  Pe[2][4] = "null";

  Pe[3][0] = "null";
  Pe[3][1] = "null";
  Pe[3][2] = "Barcelona";
  Pe[3][3] = "null";
  Pe[3][4] = "Madrid";

  Pe[4][0] = "null";
  Pe[4][1] = "Valencia";
  Pe[4][2] = "null";
  Pe[4][3] = "Madrid";
  Pe[4][4] = "null";

  cout << "Matriz esperada C" << endl;
  for (int i = 0; i < c.getNumVertices(); i++) {
    for (int j = 0; j < c.getNumVertices(); j++) {
        cout << Ce[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl << endl;

  cout << "Matriz resultante C" << endl;
  for (int i = 0; i < c.getNumVertices(); i++) {
    for (int j = 0; j < c.getNumVertices(); j++) {
        cout << C[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl << endl;

  cout << "Matriz esperada de P" << endl;
  for (int i = 0; i < c.getNumVertices(); i++) {
    for (int j = 0; j < c.getNumVertices(); j++) {
        cout << Pe[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl << endl;

  cout << "Matriz resultante P" << endl;
  for (int i = 0; i < c.getNumVertices(); i++) {
    for (int j = 0; j < c.getNumVertices(); j++) {
        cout << P[i][j] << " ";
    }
    cout << endl;
  }

  cout << "--------------------------- FIN PRUEBA CAMINO MINIMO ---------------------------" << endl;


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
  cout << "Matriz resultante" << endl;
  cn.imprimirMatriz();

  cout << endl << endl;

  // metemos los resultados esperados en otro grafo
  Carretera resultado;

  // insertamos los vertices en Carretera resultado
  resultado.setCiudad("Madrid");
  resultado.setCiudad("Barcelona");
  resultado.setCiudad("Valencia");
  resultado.setCiudad("Santander");
  resultado.setCiudad("Malaga");


  resultado.setDistancia("Madrid", "Santander", 455.32);
  resultado.setDistancia("Madrid", "Malaga", 530.3);
  resultado.setDistancia("Malaga", "Valencia", 619.8);
  resultado.setDistancia("Valencia", "Barcelona", 352.08);

  // imprimimos la matriz de adyacencia que contiene el resultado
  //esperado para comprobar si se ha realizado bien el procedimiento
  cout << "Matriz esperada" << endl;
  resultado.imprimirMatriz();

  cout << "--------------------------- FIN PRUEBA ARREGLAR CARRETERAS ---------------------------" << endl;
}

void pruebasLongitudTotal(){

  cout << "--------------------------- INICIO PRUEBA LONGITUD TOTAL ---------------------------" << endl;

  Carretera c, cs;

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
  c.arreglarCarreteras(cs);

  if(cs.longitudTotal() != 1957.5) cout << "ERROR en longitud total" << endl;

  cout << "--------------------------- FIN PRUEBA LONGITUD TOTAL ---------------------------" << endl;

}
