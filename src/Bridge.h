/*
 * Bridge.h
 *
 *  Created on: 23 sept. 2018
 *      Author: ramon
 */

#ifndef BRIDGE_H_
#define BRIDGE_H_
#include "Nodo.h"

class Bridge {
private:
	float Bridge_Distance;
	float Bridge_Weight;
	Nodo *Connected_Node1;
	Nodo *Connected_Node2;
public:
	Bridge();
	Bridge(Nodo *Node_Address);
	Bridge(Nodo *Node_Address1, Nodo *Node_Address2);
	void Set_Bridge_Distance(float New_Distance);
	void Set_Bridge_Weight(float New_Weight);
	void Set_Node_Connection1(Nodo *Nodo_To_Be_Connected);
	void Set_Node_Connection2(Nodo *Nodo_To_Be_Connected);
	void Set_Node_In_Available_Connection(Nodo *Nodo_To_Be_Connected);
	void Set_Node_In_Available_Connection_with_Reference(Nodo *Nodo_To_Be_Connected
										, Nodo *Reference_Node);
	bool Have_One_Connection_Available();
	float Get_Bridge_Distance();
	float Get_Bridge_Weight();
	Nodo *Get_Bridge_Connection1();
	Nodo *Get_Bridge_Connection2();
	virtual ~Bridge();
};

#endif /* BRIDGE_H_ */
