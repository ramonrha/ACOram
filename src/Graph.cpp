/*
 * Graph.cpp
 *
 *  Created on: 23 sept. 2018
 *      Author: ramon
 */

#include "Graph.h"

Graph::Graph() {
	// TODO Auto-generated constructor stub

}

void Graph::Fill_Graph_With_Nodes(float** Graph_Array, int i_size, int j_size) {
	Nodo mula;
	for (int i = 0; i< i_size; i++){
		mula.Set_Location(Graph_Array[i][0],Graph_Array[i][0]);
		this->Nodes.push_back(mula);
	}
}

void Graph::Fill_Graph_With_Bridges(float** Graph_Array,int i_size,int j_size) {
	float Location_X,Location_Y = 0.0;
	Nodo *Seed_Node;
	Nodo *Key_Node;
	int j_index = 0;

	for(int i = 0; i < i_size-1; i++){

		Location_X = Graph_Array[i][j_index];
		Location_Y = Graph_Array[i][j_index+1];
		Seed_Node = this->Find_Node(Location_X,Location_Y);
		j_index+=2;//reducir la busqueda de nodos cada pasada

		for(int j = j_index; j < j_size; j+=2){
			Location_X = Graph_Array[i][j_index];
			Location_Y = Graph_Array[i][j_index+1];
			Key_Node = this->Find_Node(Location_X,Location_Y);
			this->Bridges.push_back(Bridge(Seed_Node,Key_Node));
		}
	}
}

Nodo *Graph::Find_Node(float Location_X, float Location_Y) {
	int limite = Nodes.size();
	for(int i =0; i<limite;i++){
		if(Nodes.at(i).Location_X == Location_X && Nodes.at(i).Location_Y == Location_Y){
			return &Nodes.at(i);
		}
	}
	//quizás no se use esto
	return nullptr;
}

Bridge* Graph::Find_Available_Bridge_With_A_Node(Nodo* Local_Node_Address) {
	int limite = Bridges.size();
	for(int i =0; i<limite;i++){
			if(Bridges.at(i).Get_Bridge_Connection1() == Local_Node_Address){
				return &Bridges.at(i);
			}else{
				if(Bridges.at(i).Get_Bridge_Connection2() == Local_Node_Address){
					return &Bridges.at(i);
				}
				else{
					return nullptr;
				}
			}
		}
		return nullptr;
}

void Graph::Fill_Graph(float** Graph_Array, int i_size, int j_size) {
	this->Fill_Graph_With_Nodes(Graph_Array,i_size,j_size);
	this->Fill_Graph_With_Bridges(Graph_Array,i_size,j_size);
}

Graph::~Graph() {
	// TODO Auto-generated destructor stub
}

