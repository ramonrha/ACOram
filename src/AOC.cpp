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
	//variables para el hormiguero y hormigas
	Graph grafo;
	vector<Ant> hormiguero;
	float Coordenate_X, Coordenate_Y = 0;
	char c=0;
	float Best_Solution_Distance;
	int Best_Solution;

	//Eco del archivo donde se obtienen los datos
	cout << argv[1] << endl;

	//Obtención de datos
	std::ifstream infile(argv[1]);
	cout << "Leyendo archivo" << endl;
	while(infile >> Coordenate_X >> c >> Coordenate_Y){
		cout << Coordenate_X << c << Coordenate_Y << endl;
		grafo.Location_X.push_back(Coordenate_X);
		grafo.Location_Y.push_back(Coordenate_Y);
	}

	//Generar grafo
	grafo.Set_Num_Of_Nodes();
	grafo.Initialize_Arrays();
	grafo.Compute_Distances();

	//Intanciación de hormigas
	for(int i = 0; i < (int)grafo.Num_Of_Nodes;i++){
		hormiguero.push_back(Ant(&grafo,i));
	}

	//Hacer caminar a todas las hormigas :)
	for(int i = 0; i < (int)grafo.Num_Of_Nodes;i++){
		for(int j = 0; j < (int)grafo.Num_Of_Nodes;j++){
			hormiguero.at(i).Move_To_The_Next_City();
		}
	}

	//Obtener distancias de cada hormiga para elegir la mejor solución
	for(int i = 0; i < (int)grafo.Num_Of_Nodes; i++){
		hormiguero.at(i).Compute_Traveled_Distance();
		cout<<"Distancia recorrida: "<< hormiguero.at(i).Traveled_Distance << endl;
		if(i == 0){
			Best_Solution_Distance = hormiguero.at(i).Traveled_Distance;
			Best_Solution = i;
		}else{
			if(hormiguero.at(i).Traveled_Distance < Best_Solution_Distance){
				Best_Solution_Distance = hormiguero.at(i).Traveled_Distance;
				Best_Solution = i;
			}else{
				//no operation
			}
		}
	}

	//incremento de feromonas en la ruta de la mejor hormiga
	for(int j = 0; j < (int)grafo.Num_Of_Nodes;j++){
		cout<<"hormiga "<<j<<" Delta_T = "<<hormiguero.at(j).Delta_T<<endl;
		hormiguero.at(j).Increment_Bridge_Pheromone();
	}
	//tes: Delete when no testing.....
	cout<<"la major solución es"<<endl;
	cout<<"hormiga " << Best_Solution <<" con Distancia = "<<Best_Solution_Distance<< endl;
	for(int i = 0; i < (int)grafo.Num_Of_Nodes;i++){
		for(int j = 0; j < (int)grafo.Num_Of_Nodes;j++){
			cout<<"feromona en ij = ["<<i<<", "<<j<<"] = "<<grafo.Bridge_Pheromone.at(i).at(j)<<endl;
		}
	}

	//evaporación de feromonas en todo el mapa
	grafo.ro = 0.02;
	grafo.Evaporate_Pheromones();
	for(int i = 0; i < (int)grafo.Num_Of_Nodes;i++){
		for(int j = 0; j < (int)grafo.Num_Of_Nodes;j++){
			cout<<"feromona en ij = ["<<i<<", "<<j<<"] = "<<grafo.Bridge_Pheromone.at(i).at(j)<<endl;
		}
	}

	return 0;
}
