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

  public:
    /*
  	 * PRE: {  }
  	 * POST:{ Constructor por defecto: Inicia los valores de -cVertices- a " "
     *        y los valores de -mAdyacencia- a 0 en la diagonal y a -1 en el
     *        resto de casillas }
  	 * COMPLEJIDAD:O(n²)
  	 */
    Carretera();

    /*
  	 * PRE: { La variable "v" debe estar inicializada correctamente }
  	 * POST:{ Inserta el contenido de la variable "v" en el vector -cVertices-
     *        en la posicion indicada por el valor actual de -numVertices- }
  	 * COMPLEJIDAD:O(1)
  	 */
    void setCiudad(string v);

    /*
     * PRE: { La variable "ciudad" debe estar inicializada correctamente }
     * POST:{ Retorna string con valor el nombre de la ciudad qeu ocupa la
     *        posicion indicada por la variable "indice" en -cVertices- }
     * COMPLEJIDAD:O(1)
     */
    string getCiudad(int indice);

    /*
  	 * PRE: { Las distintas variables "v1", "v2" y "distancia" deberian
     *        estar correctamente inicializadas, ademas el valor de la variable
     *        "distancia" > 0}
  	 * POST:{ Halla la posicion que ocupan  las aristas de las ciudades por su
     *        nombre recogido en "v1" y "v2" y en esas posiciones de -mAdyacencia-
     *        inserta la "distancia" }
  	 * COMPLEJIDAD:O(n)
  	 */
    void setDistancia(string v1, string v2, float distancia);

    /*
     * PRE: { Las distintas variables "v1", "v2" deberian
     *        estar correctamente inicializadas }
     * POST:{ Devuelve la distancia entre la ciudad cuyo nombre está almacenado en "v1"
     *        y la ciudad con nombre el valor de "v2" }
     * COMPLEJIDAD:O(n)
     */
    float getDistancia(string v1, string v2);

    /*
     * PRE: { }
     * POST:{ Devuelve el contenido de -numVertices-}
     * COMPLEJIDAD:O(1)
     */
    int getNumVertices();

    /*
     * PRE: { La variable "ciudad" debe estar inicializada correctamente }
     * POST:{ Retorna int con valor de la posicion que ocupa la ciduad recogida
     *        por su nombre en la variable "ciudad" en -cVertices-, en caso de que
     *        no exista la ciudad devuelve un -1 }
     * COMPLEJIDAD:O(n)
     */
    int buscarCiudad(string ciudad);

    /*
     * PRE: {  }
     * POST:{ Imprime por pantalla los elementos de -mAdyacencia- }
     * COMPLEJIDAD:O(n²)
     */
    void imprimirMatriz();

    /*
     * PRE: {  }
     * POST:{ Imprime por pantalla los elementos de -cVertices- }
     * COMPLEJIDAD:O(n)
     */
    void imprimirVector();

    /*
     * PRE: { }
     * POST:{ A partir de la matriz de adyacencia halla dos matrices en las que quedan reflejados
     *        los caminos minimos de cualquier ciudad a cualquier otra:
     *        - En la matriz "P" se representa null en caso de que el camino sea directo,
     *          si hay nombre de alguna ciudad significa que tienes que pasar por esa ciudad para
     *          llegar al destino
     *        -En la matriz "C" se representan las distancias entre las ciudades }
     * COMPLEJIDAD:O(n³)
     */
    void caminoMinimo(mFloat &C, mString &P);


    /*
     * PRE: {  }
     * POST:{ Halla el arbol de recubrimiento de coste minimo del sistema de carreteras
     *        existente. Este nuevo sistema de carreteras, qeu serán las que se tienen
     *        que arreglar quedarán insertadas en nuestro nuevo grafo "gs"}
     * COMPLEJIDAD:O(n³)
     */
    void arreglarCarreteras(Carretera &gs);

    /*
     * PRE: {  }
     * POST:{ Cuenta la distancia minima que hay en el grafo, recorriendo su matriz de
     *        adyacencia y acumulando los valores de esta, solo hasta la mitad, por que
     *        de no ser así saldría el doblo de longitud que deberia salir }
     * COMPLEJIDAD:O(n)
     */
    float longitudTotal();


    ~Carretera();
 };


 #endif /* CARRETERA_H_ */
