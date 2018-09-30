/*
 * ty.cpp
 *
 *  Created on: 25 sept. 2018
 *      Author: ramon
 */

#include "Ant.h"
#include "math.h"

Ant::Ant() {
	this->Num_Of_Cities = 0;
	this->Actual_City = -1;// -1 significa que no es una ciudad o que no está disponible.
	this->graph = 0;
	this->Sumatory_Of_Pheromones = 0.0;
	this->Next_Cyti = 0;
	this->Probability_ij = 0.0;
	this->Traveled_Distance = 0.0;
}

float Ant::Probability_For_Next_Move(int Next_City) {
	float Probability_ij = 0.0;
	float numerador1,numerador2 = 0.0;
	float denominador = 0.0;
	numerador1 = this->graph->Bridge_Pheromone.at(this->Actual_City).at(Next_City);
	numerador1 = pow(numerador1,0.5);
	numerador2 = this->graph->n_matrix.at(this->Actual_City).at(Next_City);
	numerador2 = pow(numerador2, 0.5);
	numerador1 = numerador1 * numerador2;
	this->Sumatory_Of_Pheromones_Distances();
	denominador = this->Sumatory_Of_Pheromones;
	Probability_ij = numerador1 / denominador;
	return Probability_ij;
}

void Ant::Sumatory_Of_Pheromones_Distances(void) {
	this->Sumatory_Of_Pheromones = 0.0;
	for(int j = 0; j<this->Num_Of_Cities; j++){
		if(j == this->Actual_City)
			continue;
		else
			if(Already_Visited(j))
				continue;
			else{//sumar ciudad no visitada
				this->Sumatory_Of_Pheromones += this->graph->Talpha_nBeta_matrix.at(this->Actual_City).at(j);
			}
	}
}

bool Ant::Already_Visited(int City) {
	for(int j=0; j < (int)this->Visited_Cities.size(); j++){
		if(this->Visited_Cities.at(j) == City){
			return true;
		}
	}
	return false;
}

void Ant::Move_To_The_Next_City(void) {
	float Probability_ij = 0.0;
	this->Probability_ij = 0.0;
	for(int i = 0; i < this->Num_Of_Cities; i++){
		if(this->Already_Visited(i)){
			continue;
		}else{
			Probability_ij = this->Probability_For_Next_Move(i);
			if(Probability_ij >= this->Probability_ij){
				this->Next_Cyti = i;
				this->Probability_ij = Probability_ij;

			}

		}
	}
	//beggin travel to the next city
	if(this->Actual_City != this->Next_Cyti)
		this->Visited_Cities.push_back(this->Next_Cyti);
	this->Actual_City = this->Next_Cyti;
}

void Ant::Compute_Traveled_Distance(void) {
	int Actual_City = 0;
	int Previous_City = 0;
	for(int i = 0; i < (int)this->Visited_Cities.size();i++){
		Previous_City = Actual_City;
		Actual_City = this->Visited_Cities.at(i);
		if(i == 0){
			continue;//No operation because Ant hasn't moved.
		}else{
		this->Traveled_Distance += this->graph->Bridge_Distance.at(Previous_City).at(Actual_City);
		}
	}
}

Ant::~Ant() {
	// TODO Auto-generated destructor stub
}

Ant::Ant(Graph *Graph_Input,int Actual_City) {
	this->Actual_City = Actual_City;
	this->Next_Cyti = 0;
	this->graph = Graph_Input;
	this->Num_Of_Cities = this->graph->Location_X.size();
	this->Sumatory_Of_Pheromones = 0.0;
	this->Probability_ij = 0.0;
	this->Visited_Cities.push_back(this->Actual_City);
	this->Traveled_Distance = 0.0;
}
