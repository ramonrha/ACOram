/*
 * Nodo.h
 *
 *  Created on: 23 sept. 2018
 *      Author: ramon
 */

#ifndef NODO_H_
#define NODO_H_
#include <vector>

class Nodo {
public:
	float Location_X;
	float Location_Y;
	std::vector<Nodo*> Bridges_To_Ohter_Nodes;
	Nodo();
	Nodo(float Location_X, float Location_Y);
	void Set_Location(float Location_X, float Location_Y);
	virtual ~Nodo();
};

#endif /* NODO_H_ */
