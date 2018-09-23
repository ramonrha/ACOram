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
	//Crear Arbol de los nodos del grafo, incluyendo los puentes
	Nodo nodo;

	//Crear todos los nodos a partir de la matriz grafo
	for(int i = 0; i < Numero_De_Nodos; i++){
		nodo.Set_Location(Grafo[i][0], Grafo[i][1]);
		arbol.push_back(nodo);
	}

	while(!arbol.empty()){
		cout <<"Nodo ID" << &arbol.back() << endl;
		cout <<"Location x = "<< arbol.back().Location_X << endl;
		cout <<"Location Y = "<< arbol.back().Location_Y << endl;
		arbol.pop_back();
	}
	cout << "Dirección de nodo = " << &nodo << endl;
	return 0;
}
