/*
 * Container.h
 *
 *  Created on: Nov 16, 2014
 *      Author: Ben
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_

#include <vector>
#include <string>

#include "Trigger.h"
#include "Item.h"

using namespace std;

class Container
{
public:
	Container(string,string);
	virtual ~Container();
	void setStatus(string);
	void setAccept(Item*);
	void setItem(Item*);
	void addTrigger(Trigger*);

	string getName();
	string getDescription();
	string getStatus();
	Item* getAccept();
	Item* getItem();
	vector<Trigger*> getTriggers();
private:
	string name;
	string description;
	string status;
	Item* accept;
	Item* item;
	vector<Trigger*> triggers;
};



#endif /* CONTAINER_H_ */
