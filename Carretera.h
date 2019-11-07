/*
 * Carretera.h
 *
 *  Created on: 30/10/2019
 *      Author: Pedro Miguel Carmona Broncano
 *              Rubén Marín Lucas
 */


 #ifndef CARRETERA_H_
 #define CARRETERA_H_

 #include <fstream>
 #include <iostream>

 using namespace std;


 const int MAX = 20;//Como mucho hay 20 ciudades

 typedef float mFloat [MAX][MAX];
 typedef string mString [MAX][MAX];

 typedef string vString [MAX];
 typedef float vFloat [MAX];

 class Carretera{
   vString cVertices;
   mFloat mAdyacencia;
   int numVertices;
   int numAristas;

  public:
    /*
  	 * PRE: {  }
  	 * POST:{  }
  	 * COMPLEJIDAD:O(n²)
  	 */
    Carretera();

    /*
  	 * PRE: {  }
  	 * POST:{  }
  	 * COMPLEJIDAD:O(1)
  	 */
    void setCiudad(string v);

    /*
  	 * PRE: {  }
  	 * POST:{  }
  	 * COMPLEJIDAD:O(1)
  	 */
    void setDistancia(string v1, string v2, float distancia);

    /*
     * PRE: {  }
     * POST:{  }
     * COMPLEJIDAD:O()
     */
    int buscarCiudad(string ciudad);

    /*
     * PRE: {  }
     * POST:{  }
     * COMPLEJIDAD:O()
     */
    string obtenerCiudad(int indice);

    /*
     * PRE: {  }
     * POST:{  }
     * COMPLEJIDAD:O(n²)
     */
    void imprimirMatriz();

    /*
     * PRE: {  }
     * POST:{  }
     * COMPLEJIDAD:O(n²)
     */
    void caminoMinimo(mFloat &C, mString &P);

    /*
     * PRE: {  }
     * POST:{  }
     * COMPLEJIDAD:O(n²)
     */
    void arreglarCarreteras(Carretera &gs);


    ~Carretera();
 };


 #endif /* CARRETERA_H_ */
