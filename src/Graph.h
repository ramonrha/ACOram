/*
 * Graph.h
 *
 *  Created on: 23 sept. 2018
 *      Author: ramon
 */

#ifndef GRAPH_H_
#define GRAPH_H_
#include "Nodo.h"
#include "Bridge.h"
#include <vector>
class Graph {
public:
	std::vector<Nodo> Nodes;
	std::vector<Bridge> Bridges;
	Graph();
	void Fill_Graph(float **Graph_Array, int i_size, int j_size);
	void Fill_Graph_With_Nodes(float **Graph_Array, int i_size, int j_size);
	void Fill_Graph_With_Bridges(float **Graph_Array, int i_size, int j_size);
	Nodo *Find_Node(float Location_X, float Location_Y);
	Bridge *Find_Available_Bridge_With_A_Node(Nodo *Local_Node_Address);
	virtual ~Graph();
};

#endif /* GRAPH_H_ */
