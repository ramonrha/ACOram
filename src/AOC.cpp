//============================================================================
// Name        : AOC.cpp
// Author      : Ramón García
// Version     : 0.01
// Copyright   : Your copyright notice
// Description : ACO in C++
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
	int ciclos = 3;
	std::string string1 ("-v");
	AntColony colonia;
	vector<Ant> hormigas_campeonas;

	ofstream myfile;
	myfile.open ("outputs.csv");


	//recopilando datos adicionales
	if(argc == 6){
		ciclos = atoi(argv[2]);
		colonia.grafo.alpha = std::stof(argv[3]);
		colonia.grafo.beta = std::stof(argv[4]);
		colonia.grafo.ro = std::stof(argv[5]);
		cout<<"Alpha = "<<colonia.grafo.alpha<< endl;
		cout<<"Beta = "<<colonia.grafo.beta<< endl;
		cout<<"Ro = "<<colonia.grafo.ro<< endl;
		cout<<"Ver = False"<< endl;
	}else{
		if(argc == 7){
			ciclos = atoi(argv[2]);
			colonia.grafo.alpha = std::stof(argv[3]);
			colonia.grafo.beta = std::stof(argv[4]);
			colonia.grafo.ro = std::stof(argv[5]);
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
	if(colonia.vervose)
		cout <<endl<< "Drop de hormigas campeonas:" << endl;
	while(!hormigas_campeonas.empty()){
		if(colonia.vervose)
			cout<<"Distancia = "<<colonia.Best_Solution_Distance << endl;
		while(!hormigas_campeonas.back().Visited_Cities.empty()){
			hormigas_campeonas.back().Visited_Cities.pop_back();
		}
		hormigas_campeonas.pop_back();
	}
	if(!colonia.vervose){
		colonia.grafo.Display_Pheromones();
		cout<<"Distancia = "<<colonia.Best_Solution_Distance << endl;
	}
	cout<<"coudades visitadas por la ultima hormiga"<<endl;
	while(!colonia.hormiguero.at(colonia.Best_Solution).Visited_Cities.empty()){
		cout<<"Ciudad "<< colonia.hormiguero.at(colonia.Best_Solution).Visited_Cities.back()<<endl;

		myfile << colonia.grafo.Location_X.at(colonia.hormiguero.at(colonia.Best_Solution).Visited_Cities.back());
		myfile <<",";
		myfile << colonia.grafo.Location_Y.at(colonia.hormiguero.at(colonia.Best_Solution).Visited_Cities.back());
		myfile <<"\n";

		colonia.hormiguero.at(colonia.Best_Solution).Visited_Cities.pop_back();
	}
	myfile.close();
	system("gnuplot ploting && sleep 1 && display plotting_data.png &");
	return 0;
}
