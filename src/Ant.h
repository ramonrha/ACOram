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
	int Num_Of_Nodes;
	std::vector<int> Visited_Cities;
	std::vector< std::vector<float> > Probabilities;
	Graph *graph;
	Ant();
	Ant(Graph *Graph_Input);
	bool Do_I_know_City(int City_Number);

	virtual ~Ant();
};

#endif /* ANT_H_ */
