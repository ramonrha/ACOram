/*
 * Nodo.cpp
 *
 *  Created on: 23 sept. 2018
 *      Author: ramon
 */

#include "Nodo.h"

Nodo::Nodo() {
	this->Location_X = 0.0;
	this->Location_Y = 0.0;
}

Nodo::Nodo(float Location_X, float Location_Y) {
	this->Location_X = Location_X;
	this->Location_Y = Location_Y;
}

void Nodo::Set_Location(float Location_X, float Location_Y) {
	this->Location_X = Location_X;
	this->Location_Y = Location_Y;
}

Nodo::~Nodo() {
	//NO Operation
}

