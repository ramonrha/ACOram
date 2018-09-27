//============================================================================
// Name        : AOC.cpp
// Author      : Ramón García
// Version     : 0.01
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <fstream>
#include "AOC.h"
#include "Graph.h"
#include "Ant.h"
using namespace std;

int main(int argc, char *argv[]) {
	Graph grafo;
	float Coordenate_X, Coordenate_Y = 0;
	char c=0;
	cout << argv[1] << endl;
	std::ifstream infile(argv[1]);
	cout << "Leyendo archivo" << endl;
	while(infile >> Coordenate_X >> c >> Coordenate_Y){
		cout << Coordenate_X << c << Coordenate_Y << endl;
		grafo.Location_X.push_back(Coordenate_X);
		grafo.Location_Y.push_back(Coordenate_Y);
	}
	grafo.Set_Num_Of_Nodes();
	grafo.Initialize_Arrays();
	grafo.Compute_Distances();
	cout << "0,1 ="<<grafo.Bridge_Distance.at(0).at(1) << endl;
	cout << "1,0 ="<<grafo.Bridge_Distance.at(1).at(0) << endl;
	Ant hormiga(&grafo,0);
	cout<<"la dirección de grafo es: "<< hex<<&grafo<< endl;
	cout<<"la dirección en la hormiga del grafo es: "<<hex<<hormiga.graph << endl;
	return 0;
}
