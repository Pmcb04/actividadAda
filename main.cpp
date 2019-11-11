/*
 * main.cpp
 *
 *  Created on: 31/10/2019
 *      Author: Pedro Miguel Carmona Broncano
 *              Rubén Marín Lucas
 */

#include <fstream>
#include "IList.h"
#include "Carretera.h"

struct nodo{
    string ciudadInicio;
    string ciudadFinal;
};



/*
 * PRE: {  }
 * POST:{  }
 * COMPLEJIDAD:O()
 */
void cargarDatos(Carretera &c, IList<nodo*> *&caminos){

   fstream flujoEntrada;
   int numVertices, numAristas, numCaminos, comprobar; int i = 0;
   string linea; string campo[3];
   nodo *n;

   flujoEntrada.open("datos.in");
   getline(flujoEntrada, linea);
   numVertices = atoi(linea.c_str());

   if(numVertices > 1 && numVertices < 21){ //control del numero de cidudades

       for(int i = 0; i < numVertices; i++){
            getline(flujoEntrada, linea);
            c.setCiudad(linea);
       }

      getline(flujoEntrada, linea); //salto linea
      getline(flujoEntrada, linea);
      numAristas = atoi(linea.c_str());

      comprobar = numVertices * numVertices;

      if(numAristas < comprobar){

         for(int i = 0; i < numAristas; i++){
              getline(flujoEntrada, campo[0], ' ');//primer vertice
              getline(flujoEntrada, campo[1], ' ');//segundo vertice
              getline(flujoEntrada, campo[2], '\n');//etiqueta
              c.setDistancia(campo[0], campo[1], atof(campo[2].c_str()));
         }

         getline(flujoEntrada, linea); //salto linea
         getline(flujoEntrada, linea);
         numCaminos = atoi(linea.c_str());

        if(numCaminos < comprobar){

           caminos->moverInicio();
           while(i < numCaminos){
             n = new nodo;
             getline(flujoEntrada, linea, ' ');
             n->ciudadInicio = linea;
             getline(flujoEntrada, linea, '\n');
             n->ciudadFinal = linea;
             caminos->insertar(n);
             caminos->avanzar();
             i++;
           }

       }else{

         cout << "ERROR:  -El número sobre preguntas de caminos es incorrecto" << endl;

       }


      }else{

        cout << "ERROR:  -El número de carreteras es incorrecto" << endl;

      }

  }else{

    cout << "ERROR:  -El número de ciudades es incorrecto" << endl;

  }

     flujoEntrada.close();

}


/*
 * PRE: {  }
 * POST:{  }
 * COMPLEJIDAD:O()
 */
void Camino(Carretera c, int i, int j, mString &P, ofstream &flujoSalida){

  string k;
  int q;

  k = P[i][j];
  q = c.buscarCiudad(k);

    if(k != "null"){
      Camino(c, i, q, P, flujoSalida);
      flujoSalida << k << " ";
      Camino(c, q, j, P, flujoSalida);
    }
}


/*
 * PRE: {  }
 * POST:{  }
 * COMPLEJIDAD:O()
 */
void Algoritmo2(Carretera c, IList<nodo*> *caminos, ofstream &flujoSalida){
  nodo *n;
  int i, j;
  Carretera gs;
  mString P;
  mFloat C;
  float distancia;

  c.arreglarCarreteras(gs);

  flujoSalida << gs.longitudTotal() << endl;
  gs.caminoMinimo(C, P);

  caminos->moverInicio();
  while(!caminos->finLista()){
    caminos->consultar(n);
    i = c.buscarCiudad(n->ciudadInicio);
    j = c.buscarCiudad(n->ciudadFinal);

    distancia = C[i][j]; //Si fuera 0 signifca que el grafo no es conexo y desde ese vertice no se puede llegar al destino

    flujoSalida << n->ciudadInicio << " ";
    Camino(gs,i,j,P, flujoSalida);
    flujoSalida << n->ciudadFinal << " ";
    flujoSalida << distancia;
    flujoSalida << endl;

    caminos->avanzar();

  }
}

/*
 * PRE: {  }
 * POST:{  }
 * COMPLEJIDAD:O()
 */
void Algoritmo1(Carretera c, IList<nodo*> *caminos, mString &P, mFloat &C, ofstream &flujoSalida){

  nodo *n;
  int i, j;
  float distancia = 0.0;

  c.caminoMinimo(C, P);

  caminos->moverInicio();
  while(!caminos->finLista()){
    caminos->consultar(n);
    i = c.buscarCiudad(n->ciudadInicio);
    j = c.buscarCiudad(n->ciudadFinal);

    distancia = C[i][j]; //Si fuera 0 signifca que el grafo no es conexo y desde ese vertice no se puede llegar al destino

    flujoSalida << n->ciudadInicio << " ";
    Camino(c,i,j,P, flujoSalida);
    flujoSalida << n->ciudadFinal << " ";
    flujoSalida << distancia;
    flujoSalida << endl;

    caminos->avanzar();
  }




}


int main(){

  Carretera c;
  ofstream flujoSalida;
  flujoSalida.open("datos.out");
  IList<nodo*> *caminos = new IList<nodo*>();
  nodo *n;
  mString P;
  mFloat C;

  cargarDatos(c, caminos);

  Algoritmo1(c, caminos, P, C, flujoSalida);
  flujoSalida << "\n" ; //Linea en blanco
  Algoritmo2(c, caminos, flujoSalida);
  flujoSalida.close();

//destructor de la lista
  caminos->moverInicio();
  while(!caminos->finLista()){
    caminos->consultar(n);
    delete n;
    caminos->borrar();
  }
  delete caminos;

  return 0;

}
