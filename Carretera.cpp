/*
 * Carretera.cpp
 *
 *  Created on: 31/10/2019
 *      Author: Pedro Miguel Carmona Broncano
 *              Rubén Marín Lucas
 */

#include "Carretera.h"

Carretera::Carretera(){

  numVertices = 0;
  numAristas = 0;

  for(int i = 0; i < 20; i++){
        cVertices[i] = " ";
    for (int j = 0; j < 20; j++) {
      if(i == j)  mAdyacencia[i][j] = 0.0;
      else mAdyacencia[i][j] = -1.0;
    }
  }

}


void Carretera::setCiudad(string v){
      cVertices[numVertices] = v;
      numVertices++;

}



void Carretera::setDistancia(string v1, string v2, float distancia){

      int i = buscarCiudad(v1);
      int j = buscarCiudad(v2);
      mAdyacencia[i][j] = distancia;
      mAdyacencia[j][i] = distancia;

}



int Carretera::buscarCiudad(string ciudad){

    int i = 0;
    bool enc = false;

    while(i < numVertices && !enc){
      if(cVertices[i] == ciudad)
        enc = true;
      else{
        i++;
      }
    }

    return i;

}

string Carretera::obtenerCiudad(int indice){
    return cVertices[indice];
}



void Carretera::imprimirMatriz(){

  for(int i = 0; i < numVertices; i++){
    for(int j = 0; j < numVertices; j++){
      cout << mAdyacencia[i][j] << " ";
    }
    cout << endl;
  }

}



void Carretera::imprimirVector(){

  for (int i = 0; i < numVertices; i++) {
        cout << cVertices[i] << " " << i << endl;
  }

  cout << endl;


}



void Carretera::caminoMinimo(mFloat &C, mString &P){

  float suma;

  for(int i = 0; i < numVertices; i++){
    for(int j = 0; j < numVertices; j++){
      if(mAdyacencia[i][j] < 0) C[i][j] = 10000000.0;
      else C[i][j] = mAdyacencia[i][j];
        P[i][j] = "null";
    }
  }

  for (int k = 0; k < numVertices; k++) {
    for (int i = 0; i < numVertices; i++) {
      for (int j = 0; j < numVertices; j++) {
          suma = C[i][k] + C[k][j];
          if(suma < C[i][j]){
            C[i][j] = suma;
            P[i][j] = obtenerCiudad(k);
          }
      }
    }
  }

}



void Carretera::arreglarCarreteras(Carretera &gs){

    bool visitados[numVertices]; bool enc = false;
    int cont = 1; int x = 0; int y = 0; int numFila;
    float menor;

    for (int i = 0; i < numVertices; i++){
        visitados[i] = false;
        gs.setCiudad(obtenerCiudad(i));
    }

    visitados[0] = true;

    while (cont < numVertices) {

        menor = 10000000.0;

        for(int i = 0; i < numVertices; i++){
          if(visitados[i]){
            for (int j = 0; j < numVertices; j++) {
              if(!visitados[j] && mAdyacencia[i][j] > 0){
                  if(menor > mAdyacencia[i][j]){
                    menor = mAdyacencia[i][j];
                    x = i;
                    y = j;
                  }
              }
            }
          }
        }

      gs.setDistancia(obtenerCiudad(x), obtenerCiudad(y), menor);
      visitados[y] = true;
      cont++;

  }



}

float Carretera::longitudTotal(){

    float distancia = 0;
    bool saltar = false;
    int i = 0;
    int j = 0;

    while (i < numVertices) {
      while (!saltar) {
        if(i == j)
          saltar = true;
        else{
          if(mAdyacencia[i][j] > 0)
            distancia += mAdyacencia[i][j];
          j++;
        }
      }
      i++;
      j = 0;
      saltar = false;
    }

    return distancia;

}


Carretera::~Carretera(){

}
