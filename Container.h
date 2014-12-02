/*
 * Container.h
 *
 *  Created on: Nov 16, 2014
 *      Author: Ben
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_

#include <vector>

#include "Trigger.h"
#include "Item.h"

using namespace std;

class Container
{
public:
	Container(char*,char*);
	virtual ~Container();
	void setStatus(char*);
	void setAccept(Item*);
	void setItem(Item*);
	void addTrigger(Trigger*);

	char* getName();
	char* getDescription();
	char* getStatus();
	Item* getAccept();
	Item* getItem();
	vector<Trigger*> getTriggers();
private:
	char* name;
	char* description;
	char* status;
	Item* accept;
	Item* item;
	vector<Trigger*> triggers;
};



#endif /* CONTAINER_H_ */
