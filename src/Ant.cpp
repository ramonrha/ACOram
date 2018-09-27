/*
 * ty.cpp
 *
 *  Created on: 25 sept. 2018
 *      Author: ramon
 */

#include "Ant.h"


Ant::Ant() {
	this->Num_Of_Nodes = 0;
	this->graph = 0;
}

Ant::~Ant() {
	// TODO Auto-generated destructor stub
}

Ant::Ant(Graph *Graph_Input) {
	this->graph = Graph_Input;
	this->Num_Of_Nodes = this->graph->Location_X.size();
}
