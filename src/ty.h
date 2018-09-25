/*
 * ty.h
 *
 *  Created on: 25 sept. 2018
 *      Author: ramon
 */

#ifndef TY_H_
#define TY_H_
#include <vector>

class ty {
public:
	std::vector<int> Visited_Cities;
	ty();
	bool Do_I_know_City(int City_Number);

	virtual ~ty();
};

#endif /* TY_H_ */
