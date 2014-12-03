/*
 * Item.h
 *
 *  Created on: Nov 16, 2014
 *      Author: Ben
 */

#ifndef ITEM_H_
#define ITEM_H_

#include <vector>
#include <string>

class Trigger; // Not sure if will work.

#include "Trigger.h"

using namespace std;

struct turnon {
	string print;
	string action;
};

class Item
{
public:
	Item(string,string);
	virtual ~Item();
	void setStatus(string);
	void setWriting(string);
	void setTurnOn(turnon*);
	void addTrigger(Trigger*);

	string getName();
	string getDescription();
	string getStatus();
	string getWriting();
	turnon* getTurnOn();
	vector<Trigger*> getTriggers();
private:
	string name;
	string description;
	string status;
	string writting;
	turnon* turnOn;
	vector<Trigger*> triggers;
};



#endif /* ITEM_H_ */
