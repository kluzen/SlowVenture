/*
 * Room.h
 *
 *  Created on: Nov 16, 2014
 *      Author: Ben
 */

#ifndef ROOM_H_
#define ROOM_H_

#include <vector>
#include <string>

#include "Item.h"
#include "Container.h"
#include "Creature.h"
#include "Trigger.h"

using namespace std;

class Room; // Not sure if will work;

struct border {
	char direction;
	Room* room;
};

class Room
{

public:
	Room(string,string);
	virtual ~Room();
	void setStatus(string);
	void setType(string);
	void addItem(Item*);
	void addContainer(Container*);
	void addCreature(Creature*);
	void addBorder(border*);
	void addTrigger(Trigger*);

	void removeItem(string);
	bool hasItem(string);
	Item* getItem(string);
	bool hasContainer(string);
	Container* getContainer(string);
//	bool hasCreature(Creature*);

	string getName();
	string getDescription();
	string getStatus();
	string getType();
	vector<Item*> getItems();
	vector<Container*> getContainers();
	vector<Creature*> getCreatures();
	vector<border*> getBorders();
	vector<Trigger*> getTriggers();
private:
	string name;
	string description;
	string status;
	string type;
	vector<Item*> items;
	vector<Container*> containers;
	vector<Creature*> creatures;
	vector<border*> borders;
	vector<Trigger*> triggers;
};



#endif /* ROOM_H_ */
