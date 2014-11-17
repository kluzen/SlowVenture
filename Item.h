/*
 * Item.h
 *
 *  Created on: Nov 16, 2014
 *      Author: Ben
 */

#ifndef ITEM_H_
#define ITEM_H_

#include <vector>

class Trigger; // Not sure if will work.

#include "Trigger.h"

using namespace std;

struct turnon {
	char* print;
	char* action;
};

class Item
{
public:
	Item(char*,char*);
	virtual ~Item();
	void setStatus(char*);
	void setWritting(char*);
	void setTurnOn(turnon*);
	void addTrigger(Trigger*);

	char* getName();
	char* getDescription();
	char* getStatus();
	char* getWritting();
	turnon* getTurnOn();
	vector<Trigger*> getTriggers();
private:
	char* name;
	char* description;
	char* status;
	char* writting;
	turnon* turnOn;
	vector<Trigger*> triggers;
};



#endif /* ITEM_H_ */
