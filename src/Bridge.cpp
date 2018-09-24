/*
 * Bridge.cpp
 *
 *  Created on: 23 sept. 2018
 *      Author: ramon
 */

#include "Bridge.h"
#include "Nodo.h"

Bridge::Bridge() {
	this->Bridge_Distance = 0.0;
	this->Bridge_Weight = 0.0;
	this->Connected_Node1 = nullptr;
	this->Connected_Node2 = nullptr;
}

void Bridge::Set_Bridge_Distance(float New_Distance) {
	this->Bridge_Distance = New_Distance;
}

void Bridge::Set_Node_Connection1(Nodo* Nodo_To_Be_Connected) {
	this->Connected_Node1 = Nodo_To_Be_Connected;
}

void Bridge::Set_Node_Connection2(Nodo* Nodo_To_Be_Connected) {
	this->Connected_Node2 = Nodo_To_Be_Connected;
}

float Bridge::Get_Bridge_Distance() {
	return this->Bridge_Distance;
}

float Bridge::Get_Bridge_Weight() {
	return this->Bridge_Weight;
}

Nodo* Bridge::Get_Bridge_Connection1() {
	return this->Connected_Node1;
}

Nodo* Bridge::Get_Bridge_Connection2() {
	return this->Connected_Node2;
}

void Bridge::Set_Bridge_Weight(float New_Weight) {
	this->Bridge_Weight = New_Weight;
}

void Bridge::Set_Node_In_Available_Connection(Nodo* Nodo_To_Be_Connected) {
	if(this->Connected_Node1 == nullptr){
		this->Connected_Node1 = Nodo_To_Be_Connected;
	}else{
		if(this->Connected_Node2 == nullptr){
			this->Connected_Node2 = Nodo_To_Be_Connected;
		}
	}
}

bool Bridge::Have_One_Connection_Available() {
	if(this->Connected_Node1 == nullptr)
		return true;
	else
		if(this->Connected_Node2 == nullptr)
			return true;
		else
			return false;
	return false;
}

Bridge::Bridge(Nodo* Node_Address) {
	this->Bridge_Distance = 0.0;
	this->Bridge_Weight = 0.0;
	this->Connected_Node1 = Node_Address;
	this->Connected_Node2 = nullptr;
}

Bridge::Bridge(Nodo* Node_Address1, Nodo* Node_Address2) {
	this->Bridge_Distance = 0.0;
	this->Bridge_Weight = 0.0;
	this->Connected_Node1 = Node_Address1;
	this->Connected_Node2 = Node_Address2;
}

Bridge::~Bridge() {
	// TODO Auto-generated destructor stub
}

