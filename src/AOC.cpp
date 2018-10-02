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
#include <string>
#include "AOC.h"
#include "Graph.h"
#include "Ant.h"
#include "AntColony.h"
using namespace std;

int main(int argc, char *argv[]) {
	//variables para el hormiguero y hormigas
	int ciclos = 0;
	std::string string1 ("-v");
	AntColony colonia;
	vector<Ant> hormigas_campeonas;

	//recopilando datos adicionales
	if(argc == 6){
		ciclos = atoi(argv[2]);
		colonia.grafo.alpha = std::stof(argv[2]);
		colonia.grafo.beta = std::stof(argv[3]);
		colonia.grafo.ro = std::stof(argv[4]);
		cout<<"Alpha = "<<colonia.grafo.alpha<< endl;
		cout<<"Beta = "<<colonia.grafo.beta<< endl;
		cout<<"Ro = "<<colonia.grafo.ro<< endl;
		cout<<"Ver = False"<< endl;
	}else{
		if(argc == 7){
			ciclos = atoi(argv[2]);
			colonia.grafo.alpha = std::stof(argv[2]);
			colonia.grafo.beta = std::stof(argv[3]);
			colonia.grafo.ro = std::stof(argv[4]);
			if(atoi(argv[6]) == 1){
				cout<<"vervose"<<endl;
				colonia.vervose = true;
			}
			cout<<"Alpha = "<<colonia.grafo.alpha<< endl;
			cout<<"Beta = "<<colonia.grafo.beta<< endl;
			cout<<"Ro = "<<colonia.grafo.ro<< endl;
			cout<<"ver = TRUE ("<<argv[6]<<")"<< endl;
		}
		else{
			cout<<"   ¡Sugerencia!    "<<endl;
			cout<<"inputs.csv 3 5.0 0.0 0.05"<<endl;
			cout<<"3 = numero de ciclos"<<endl;
			cout<<"5.0 0.0 7 0.05 son Alpha, Beta y Ro"<<endl;
			cout<<"un 1 adicional inmprimirá resultados de todas las hormigas <1 = true, 0 = false> (Ver)"<<endl;
		}
	}

	colonia.Retreive_Datos_From_File(argv[1]);
	colonia.Initialize_Colony();
	for(int i= 0; i < ciclos; i++){
		colonia.Execute_Cycle();
		hormigas_campeonas.push_back(colonia.hormiguero.at(colonia.Best_Solution));
	}
	cout <<endl<< "Drop de hormigas campeonas:" << endl;
	while(!hormigas_campeonas.empty()){
		cout<<"Distancia = "<<colonia.Best_Solution_Distance << endl;
		while(!hormigas_campeonas.back().Visited_Cities.empty()){
			//cout<<"Ciudad "<<hormigas_campeonas.back().Visited_Cities.back() << endl;
			hormigas_campeonas.back().Visited_Cities.pop_back();
		}
		hormigas_campeonas.pop_back();
	}
	return 0;
}
