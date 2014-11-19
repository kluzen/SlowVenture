/*
 * Room.h
 *
 *  Created on: Nov 16, 2014
 *      Author: Ben
 */

#ifndef ROOM_H_
#define ROOM_H_

#include <vector>

#include "Item.h"
#include "Container.h"
#include "Creature.h"
#include "Trigger.h"

using namespace std;

class Room; // Not sure if will work;

struct border {
	char* direction;
	Room* room;
};

class Room
{

public:
	Room(char*,char*);
	virtual ~Room();
	void setStatus(char*);
	void setType(char*);
	void addItem(Item*);
	void addContainer(Container*);
	void addCreature(Creature*);
	void addBorder(border*);
	void addTrigger(Trigger*);

	char* getName();
	char* getDescription();
	char* getStatus();
	char* getType();
	vector<Item*> getItems();
	vector<Container*> getContainers();
	vector<Creature*> getCreatures();
//	vector<Border*> getBorders();
	vector<border*> getBorders();
	vector<Trigger*> getTriggers();
private:
	char* name;
	char* description;
	char* status;
	char* type;
	vector<Item*> items;
	vector<Container*> containers;
	vector<Creature*> creatures;
//	vector<Border*> borders;
	vector<border*> borders;
	vector<Trigger*> triggers;
};



#endif /* ROOM_H_ */
