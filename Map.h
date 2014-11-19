/*
 * Map.h
 *
 *  Created on: Nov 18, 2014
 *      Author: Ben
 */

#ifndef MAP_H_
#define MAP_H_


#include <vector>

#include "Room.h"
#include "Container.h"
#include "Creature.h"
#include "Item.h"

using namespace std;


class Map
{

public:
	Map();
	virtual ~Map();
	void addItem(Item*);
	void addContainer(Container*);
	void addCreature(Creature*);
	void addRoom(Room*);

	vector<Item*> getItems();
	vector<Container*> getContainers();
	vector<Creature*> getCreatures();
	vector<Room*> getRooms();
private:
	vector<Item*> items;
	vector<Container*> containers;
	vector<Creature*> creatures;
	vector<Room*> rooms;
};





#endif /* MAP_H_ */
