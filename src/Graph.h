/*
 * Graph.h
 *
 *  Created on: 25 sept. 2018
 *      Author: ramon
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include <vector>

class Graph {
public:
	int Num_Of_Nodes;
	std::vector<float> Location_X;
	std::vector<float> Location_Y;
	std::vector< std::vector<float> > Bridge_Distance;
	std::vector< std::vector<float> > Bridge_Pheromone;
	std::vector< std::vector<float> > n_matrix;
	std::vector< std::vector<float> > Talpha_nBeta_matrix;
	float alpha;
	float beta;
	Graph();
	void Set_Num_Of_Nodes();
	void Initialize_Arrays();
	void Compute_Distances();
	virtual ~Graph();
};

#endif /* GRAPH_H_ */
