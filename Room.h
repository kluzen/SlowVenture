/*
 * Room.h
 *
 *  Created on: Nov 16, 2014
 *      Author: Ben
 */

#ifndef ROOM_H_
#define ROOM_H_

class Room
{
public:
	Room(char*,char*);
	virtual ~Room();
	void setStatus(char*);
	void setType(char*);
	void addItem(Item);
	void addContainer(Container);
	void addCreature(Creature);
	void addBorder(border);
	void addTrigger(Trigger);

	char* getName();
	char* getDescription();
	char* getStatus();
	char* getType();
	Item* getItems();
	Container* getContainers();
	Creature* getCreatures();
	border* getBorders();
	Trigger* getTriggers();
private:
	char* name;
	char* description;
	char* status;
	char* type;
	Item* items;
	Container* containers;
	Creature* creatures;
	border* borders;
	Trigger* triggers;
};

struct border {
	char* direction;
	Room room;
};


#endif /* ROOM_H_ */
