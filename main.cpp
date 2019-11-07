
//============================================================================
// Name        : Carreteras.cpp
// Author      : Rubén Marín Lucas & Pedro Miguel Carmona Broncano
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#include "IList.h"
#include "Carretera.h"

struct nodo{
    string ciudadInicio;
    string ciudadFinal;
};


void cargarDatos(Carretera &c, IList<nodo*> *&caminos){

   fstream flujoEntrada;
   int numVertices, numAristas, numCaminos; int i = 0;
   string linea; string campo[3];
   nodo *n;

   flujoEntrada.open("datos.in");
   getline(flujoEntrada, linea);
   numVertices = atoi(linea.c_str());

     for(int i = 0; i < numVertices; i++){
          getline(flujoEntrada, linea);
          c.setCiudad(linea);
     }

    getline(flujoEntrada, linea); //salto linea
    getline(flujoEntrada, linea);
    numAristas = atoi(linea.c_str());

     for(int i = 0; i < numAristas; i++){
          getline(flujoEntrada, campo[0], ' ');//primer vertice
          getline(flujoEntrada, campo[1], ' ');//segundo vertice
          getline(flujoEntrada, campo[2], '\n');//etiqueta
          c.setDistancia(campo[0], campo[1], atof(campo[2].c_str()));
     }

     getline(flujoEntrada, linea); //salto linea
     getline(flujoEntrada, linea);
     numCaminos = atoi(linea.c_str());


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

     flujoEntrada.close();

}

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



void Algoritmo2(Carretera c, IList<nodo*> *caminos, ofstream &flujoSalida){
  nodo *n;
  int i, j;
  Carretera gs;
  mString P;
  mFloat C;
  float distancia;

  c.arreglarCarreteras(gs);

  cout << "------------------ PRIM -----------------" << endl;
  gs.imprimirMatriz();
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


void Algoritmo1(Carretera c, IList<nodo*> *caminos, mString &P, mFloat &C, ofstream &flujoSalida){

  nodo *n;
  int i, j;
  float distancia = 0.0;

  c.caminoMinimo(C, P);

  for (size_t i = 0; i < 7; i++) {
    for (size_t j = 0; j < 7; j++) {

       cout << P[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;

  for (size_t i = 0; i < 7; i++) {
    for (size_t j = 0; j < 7; j++) {

       cout << C[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;;

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

  cout << "--------------- MATRIZ -------------------" << endl;
  c.imprimirMatriz();
  //llamadaFuncion(caminos);

  cout << "--------------- CAMINOS -------------------" << endl;
    caminos->moverInicio();
    while(!caminos->finLista()){
     caminos->consultar(n);
     cout << n->ciudadInicio << "     " << n->ciudadFinal << endl;
     caminos->avanzar();
   }

   cout << endl;

   Algoritmo1(c, caminos, P, C, flujoSalida);
   flujoSalida << "\n" ; //Linea en blanco
   Algoritmo2(c, caminos, flujoSalida);
   flujoSalida.close();

  return 0;

}
