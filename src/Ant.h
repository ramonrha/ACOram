/*
 * ty.h
 *
 *  Created on: 25 sept. 2018
 *      Author: ramon
 */

#ifndef ANT_H_
#define ANT_H_
#include <vector>
#include "Graph.h"

class Ant {
public:
	int Num_Of_Cities;
	int Actual_City;
	int Next_Cyti;
	std::vector<int> Visited_Cities;
	std::vector< std::vector<float> > Probabilities;
	Graph *graph;
	float Sumatory_Of_Pheromones;
	float Probability_ij;
	float Traveled_Distance;
	float Delta_T;
	Ant();
	Ant(Graph *Graph_Input, int Actual_City);
	bool Do_I_know_City(int City_Number);
	float Probability_For_Next_Move(int Next_City);//La hormiga se cuestiona a donde ir
	void Move_To_The_Next_City(void);
	void Sumatory_Of_Pheromones_Distances(void);
	void Compute_Traveled_Distance(void);
	bool Already_Visited(int City);
	void Increment_Bridge_Pheromone(void);
	virtual ~Ant();
};

#endif /* ANT_H_ */
