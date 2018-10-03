/*
 * AntColony.cpp
 *
 *  Created on: 30 sept. 2018
 *      Author: ramon
 */

#include "AntColony.h"
#include <iostream>
using namespace std;

AntColony::AntColony() {
	this->Best_Solution = 0;
	this->Best_Solution_Distance = 0.0;
	this->vervose = false;
}

AntColony::~AntColony() {}

void AntColony::Retreive_Datos_From_File(char* argv) {
	float Coordenate_X, Coordenate_Y = 0;
	char c=0;
	std::ifstream infile(argv);
	cout << "Leyendo archivo" << endl;
	while(infile >> Coordenate_X >> c >> Coordenate_Y){
		this->grafo.Location_X.push_back(Coordenate_X);
		this->grafo.Location_Y.push_back(Coordenate_Y);
	}
	infile.close();
}

void AntColony::Generate_Graph() {
	//Generar grafo
	this->grafo.Set_Num_Of_Nodes();
	this->grafo.Initialize_Arrays();
	this->grafo.Compute_Distances();
}

void AntColony::Generate_Ants() {
	//Genera una hormiga por cada nodo
	for(int i = 0; i < (int)grafo.Num_Of_Nodes;i++){
		this->hormiguero.push_back(Ant(&grafo,i));
	}
}

void AntColony::Walk_Ants() {
	/* camina todas las hormigas contra todos los nodos
	 * 'i' representa a la hormiga k
	 * 'j' representa a la cantidad de nodos que debe recorrer la hormiga
	 *     para completar el trayecto*/
	if(this->vervose)
		this->grafo.Display_Pheromones();
	for(int i = 0; i < (int)this->grafo.Num_Of_Nodes;i++){
		for(int j = 0; j < (int)this->grafo.Num_Of_Nodes;j++){
			this->hormiguero.at(i).Move_To_The_Next_City();

		}
	}
}

void AntColony::Compute_Distances() {
	//Obtener distancias de cada hormiga para elegir la mejor solución
	for(int i = 0; i < (int)this->grafo.Num_Of_Nodes; i++){
		this->hormiguero.at(i).Compute_Traveled_Distance();
		if(this->vervose)
			cout<<"Distancia recorrida: "<< this->hormiguero.at(i).Traveled_Distance << endl;
		if(i == 0){
			this->Best_Solution_Distance = this->hormiguero.at(i).Traveled_Distance;
			this->Best_Solution = i;
		}else{
			if(this->hormiguero.at(i).Traveled_Distance < this->Best_Solution_Distance){
				this->Best_Solution_Distance = this->hormiguero.at(i).Traveled_Distance;
				this->Best_Solution = i;
			}else{
				//no operation
			}
		}
	}
		if(this->vervose)
			cout<<endl;
}

void AntColony::Increment_Pheromones() {
	for(int j = 0; j < (int)this->grafo.Num_Of_Nodes;j++){
		this->hormiguero.at(j).Increment_Bridge_Pheromone();
	}

}

void AntColony::Evaporate_Pheromones() {
	//evaporación de feromonas en todo el mapa
	this->grafo.Evaporate_Pheromones();
}

void AntColony::Initialize_Colony() {
	this->Generate_Graph();
	this->Generate_Ants();
}

void AntColony::Execute_Cycle() {
	this->Restart_Ants();
	this->Walk_Ants();
	this->Compute_Distances();
	this->Increment_Pheromones();
	this->Evaporate_Pheromones();
}

void AntColony::Restart_Ants() {
	//Reboot Ants, to reuse all again
	for(int i = 0; i<(int)this->hormiguero.size() ; i++){
		this->hormiguero.at(i).Reboot(&this->grafo, i);
	}
}
