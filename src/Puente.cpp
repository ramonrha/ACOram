/*
 * Puente.cpp
 *
 *  Created on: 23 sept. 2018
 *      Author: ramon
 */

#include "Puente.h"

Puente::Puente() {
	Bridge_Weight = 0;
	Nodo_At_Terminal_1 = nullptr;
	Nodo_At_Terminal_2 = nullptr;
}

Puente::~Puente() {
	// TODO Auto-generated destructor stub
}

void Puente::Set_Peso_Del_Puente(float New_Weight) {
	this->Bridge_Weight = New_Weight;
}

int Puente::Do_you_know_This_Node(void* Wanted_Nodo) {
	if(Wanted_Nodo == this->Nodo_At_Terminal_1){
		return 1; //Means connected to the first end of the Bridge
	}
	else{
		if(Wanted_Nodo == this->Nodo_At_Terminal_2)
			return 2; //Means connected to the second end of the Bridge
		else
			return 0; //Means no connected
	}
}

int Puente::Add_Nodo_To_Bridge(void* Nodo_To_Be_Added) {
	if (this->Nodo_At_Terminal_1 == nullptr){
		this->Nodo_At_Terminal_1 == Nodo_To_Be_Added;
	}else{
		if(this->Nodo_At_Terminal_2 == nullptr){
			this->Nodo_At_Terminal_2 == Nodo_To_Be_Added;
			return 2;
		}else{
			return -1;
		}
	}
	return 1;
}
