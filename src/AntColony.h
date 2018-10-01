/*
 * AntColony.h
 *
 *  Created on: 30 sept. 2018
 *      Author: ramon
 */

#ifndef ANTCOLONY_H_
#define ANTCOLONY_H_
#include <iostream>
#include <vector>
#include <fstream>
#include "Ant.h"
#include "Graph.h"

class AntColony {
public:
	Graph grafo;
	std::vector<Ant> hormiguero;
	float Best_Solution_Distance;
	int Best_Solution;

	AntColony();
	virtual ~AntColony();
	void Retreive_Datos_From_File(char *argv);
	void Generate_Graph();
	void Generate_Ants();
	void Walk_Ants();
	void Compute_Distances();
	void Increment_Pheromones();
	void Evaporate_Pheromones();
	void Initialize_Colony();
	void Execute_Cycle();
	void Restart_Ants();
};

#endif /* ANTCOLONY_H_ */
