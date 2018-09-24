//============================================================================
// Name        : AOC.cpp
// Author      : Ramón García
// Version     : 0.01
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "AOC.h"
using namespace std;

int main() {
	Graph c_grafo;
	float **arreglo;

	arreglo = new float*[Numero_De_Nodos];
	for(int i = 0; i < Numero_De_Nodos; i++){
			arreglo[i] = new float[Numero_De_Conexiones];
	}

	for(int i = 0; i < Numero_De_Nodos; i++){
		for(int j = 0; j < Numero_De_Conexiones; j++){
			arreglo[i][j] = Grafo[i][j];
		}
	}

	c_grafo.Fill_Graph(arreglo,Numero_De_Nodos, Numero_De_Conexiones);

	return 0;
}
