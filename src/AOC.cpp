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

void Initialize_Array(std::vector< std::vector<float> > &puentes, int Num_Of_Nodes){
	vector<float> tmp(Num_Of_Nodes,0.0);
	for(int i=Num_Of_Nodes; i > 0; i--){
		puentes.push_back(tmp);
	}
}

int main() {
	vector< vector<float> > puentes;
	Initialize_Array(puentes,Numero_De_Nodos);
	cout << puentes.size()<<endl;
	return 0;
}
