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
	void setOpen(bool);
	void addAccept(string);
	void addItem(Item*);
	void addTrigger(Trigger*);

	bool doesAccept(string);
	bool hasItem(string);
	void removeItem(string);
	Item* getItem(string);

	string getName();
	string getDescription();
	string getStatus();
	bool isOpen();
	vector<Item*> getItems();
	vector<Trigger*> getTriggers();
private:
	string name;
	string description;
	string status;
	bool open;
	vector<string> accepts;
	vector<Item*> items;
	vector<Trigger*> triggers;
};



#endif /* CONTAINER_H_ */
