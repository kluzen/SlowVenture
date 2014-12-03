/*
 * Trigger.h
 *
 *  Created on: Nov 16, 2014
 *      Author: Ben
 */

#ifndef TRIGGER_H_
#define TRIGGER_H_

#include <vector>
#include <string>

class Item; // Not sure if will work;
class Container;

#include "Item.h"
#include "Container.h"

struct condition {
	bool has;
	string status;
	string owner;
	Item* objectI;
	Container* objectC;
};

using namespace std;

class Trigger
{
public:
	Trigger();
	virtual ~Trigger();
	void setType(string);
	void setPrint(string);
	void setAction(string);
	void setOwner(string);
	void setStatus(string);
	void setCommand(string);
	void addCondition(condition*);

	string getType();
	string getPrint();
	string getAction();
	string getOwner();
	string getStatus();
	string getCommand();
	vector<condition*> getConditions();
private:
	string type;
	string print;
	string action;
	string owner;
	string status;
	string command;
	vector<condition*> conditions;
};


#endif /* TRIGGER_H_ */
