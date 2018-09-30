/*
 * Graph.cpp
 *
 *  Created on: 25 sept. 2018
 *      Author: ramon
 */

#include "Graph.h"
#include <iostream>
#include <math.h>

Graph::Graph() {
	this->Num_Of_Nodes = 0;
	this->alpha = 0.5;
	this->beta = 0.5;
}

void Graph::Set_Num_Of_Nodes() {
	this->Num_Of_Nodes = this->Location_X.size();
}

void Graph::Compute_Distances(){
	float Distance = 0.0;
	float tau,n_dist = 0.0;
	int Contador_J = 0;
	float Y1,Y2,X1,X2=0;
	if(this->Location_X.size()==0 && this->Location_Y.size()==0)
		return;
	else{
		if(this->Location_X.size()!=this->Location_Y.size()){
			return;
		}else{
			for(int i = 0; i<(int)this->Location_X.size(); i++){
				Contador_J++;
				for(int j=Contador_J; j<(int)this->Location_X.size(); j++){
					Y2 = Location_Y.at(j);
					Y1 = Location_Y.at(i);
					X2 = Location_X.at(j);
					X1 = Location_X.at(i);
					Distance = pow((Y2 - Y1),2);
					Distance += pow((X2 - X1),2);
					Distance = sqrt(Distance);
					std::cout<<"Distance when i="<<i<<", j="<<j<<", "<<Distance<< std::endl;
					this->Bridge_Distance.at(i).at(j) = Distance;
					this->Bridge_Distance.at(j).at(i) = Distance;
					try{
						n_dist = 1.0/Distance;
					}catch(...){
						n_dist = 0;
					}
					this->n_matrix.at(i).at(j) = n_dist;
					this->n_matrix.at(j).at(i) = n_dist;
					n_dist = pow(n_dist,this->beta);
					tau = pow(this->Bridge_Pheromone.at(i).at(j), this->alpha); //T_ij x n_ij
					tau = tau * n_dist;
					this->Talpha_nBeta_matrix.at(i).at(j) = tau;
					this->Talpha_nBeta_matrix.at(j).at(i) = tau;
				}
			}
		}
	}
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

void Graph::Initialize_Arrays(){
	std::vector<float> tmp(this->Num_Of_Nodes,1.0);
	for(int i=this->Num_Of_Nodes; i > 0; i--){
		this->Bridge_Distance.push_back(tmp);
		this->Bridge_Pheromone.push_back(tmp);
		this->n_matrix.push_back(tmp);
		this->Talpha_nBeta_matrix.push_back(tmp);
	}
}

