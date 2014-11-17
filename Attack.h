/*
 * Attack.h
 *
 *  Created on: Nov 16, 2014
 *      Author: Ben
 */

#ifndef ATTACK_H_
#define ATTACK_H_

#include <vector>

#include "Trigger.h"

using namespace std;

class Attack
{
public:
	Attack();
	virtual ~Attack();
	void setPrint(char*);
	void addAction(char*);
	void addCondition(condition*);

	char* getPrint();
	vector<char*> getActions();
	vector<condition*> getConditions();
private:
	char* print;
	vector<char*> actions;
	vector<condition*> conditions;
};



#endif /* ATTACK_H_ */
