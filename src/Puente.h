/*
 * Puente.h
 *
 *  Created on: 23 sept. 2018
 *      Author: ramon
 */

#ifndef PUENTE_H_
#define PUENTE_H_

#include "Nodo.h"

class Puente {
public:
	float Bridge_Weight;
	void* Nodo_At_Terminal_1;
	void* Nodo_At_Terminal_2;
	void Set_Peso_Del_Puente(float New_Weight);

	//returns 1 if connected to 1, 2 when connected to 2, 0 if no connected.
	int Do_you_know_This_Node(void* Wanted_Nodo);

	//Add node to available end of the Bridge
	int Add_Nodo_To_Bridge(void* Nodo_To_Be_Added);

	Puente();
	virtual ~Puente();
};

#endif /* PUENTE_H_ */
