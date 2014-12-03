/*
 * Attack.h
 *
 *  Created on: Nov 16, 2014
 *      Author: Ben
 */

#ifndef ATTACK_H_
#define ATTACK_H_

#include <vector>
#include <string>

#include "Trigger.h"

using namespace std;

class Attack
{
public:
	Attack();
	virtual ~Attack();
	void setPrint(string);
	void addAction(string);
	void addCondition(condition*);

	string getPrint();
	vector<string> getActions();
	vector<condition*> getConditions();
private:
	string print;
	vector<string> actions;
	vector<condition*> conditions;
};



#endif /* ATTACK_H_ */
