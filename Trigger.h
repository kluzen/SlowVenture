/*
 * Trigger.h
 *
 *  Created on: Nov 16, 2014
 *      Author: Ben
 */

#ifndef TRIGGER_H_
#define TRIGGER_H_

#include <vector>

class Item; // Not sure if will work;

#include "Item.h"

struct condition {
	bool has;
	char* status;
	Item* object;
};

using namespace std;

class Trigger
{
public:
	Trigger();
	virtual ~Trigger();
	void setType(char*);
	void setPrint(char*);
	void setAction(char*);
	void setOwner(char*);
	void setStatus(char*);
	void setCommand(char*);
	void addCondition(condition*);

	char* getType();
	char* getPrint();
	char* getAction();
	char* getOwner();
	char* getStatus();
	char* getCommand();
	vector<condition*> getConditions();
private:
	char* type;
	char* print;
	char* action;
	char* owner;
	char* status;
	char* command;
	vector<condition*> conditions;
};


#endif /* TRIGGER_H_ */
