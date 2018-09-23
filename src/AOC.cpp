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
	Nodo *nodoDePrueba = nullptr;
	for(int i = 0; i < Numero_De_Nodos; i++){
		for(int j = 0; j < Numero_De_Conexiones; j+=2){
			if(Grafo[i,j] > 0 && Grafo [i][j+1] > 0){
				nodo.Set_Location( Grafo[i][j] , Grafo[i][j+1]);
				arbol.push_back(nodo);
				nodoDePrueba = &arbol.back();
			}
		}
	}
	while(!arbol.empty()){
		cout <<"Nodo ID" << &arbol.back() << endl;
		cout <<"Location x = "<< arbol.back().Location_X << endl;
		cout <<"Location Y = "<< arbol.back().Location_Y << endl;
		arbol.pop_back();
	}
	cout << "Dirección de nodo = " << &nodo << endl;
	cout << "Dirección de nodoDePrueba = " << nodoDePrueba << endl;
	return 0;
}
