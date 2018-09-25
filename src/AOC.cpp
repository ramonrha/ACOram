//============================================================================
// Name        : AOC.cpp
// Author      : Ramón García
// Version     : 0.01
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "AOC.h"
using namespace std;
void Initialize_Array(std::vector< std::vector<float> > &puentes, int Num_Of_Nodes);

int main() {
	std::vector< std::vector<float> > Bridge_Distance;
	std::vector< std::vector<float> > Bridge_Pheromone;
	Initialize_Array(Bridge_Distance,Numero_De_Nodos);
	Bridge_Distance.
	cout << Bridge_Distance.size()<<endl;
	return 0;
}

void Initialize_Array(std::vector< std::vector<float> > &puentes, int Num_Of_Nodes){
	vector<float> tmp(Num_Of_Nodes,0.0);
	for(int i=Num_Of_Nodes; i > 0; i--){
		puentes.push_back(tmp);
	}
}
