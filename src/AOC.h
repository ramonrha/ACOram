/*
 * AOC.h
 *
 *  Created on: 23 sept. 2018
 *      Author: ramon
 *
 *  Aquí se define el grafo en forma matricial:
 *  nodo, nodo-conectado1, nodo-conectado2…
 *  nodo2, nodo-conectado1,nodo-conectado2…
 *
 */

#ifndef AOC_H_
#define AOC_H_
#include <vector>
#include "Nodo.h"
#include "Bridge.h"
#include "Graph.h"

#define Numero_De_Nodos 5
#define Numero_De_Conexiones 10

const float Grafo[Numero_De_Nodos][Numero_De_Conexiones]={
	{1,1, 2,3, 4,2, 6,1, 0,0},
	{2,3, 1,1, 4,2, 5,4, 0,0},
	{4,2, 1,1, 2,3, 5,4, 6,1},
	{6,1, 1,1, 4,2, 5,4, 0,0},
	{5,4, 2,3, 4,2, 6,1, 0,0}
};





#endif /* AOC_H_ */
