/*
 * Map.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: Ben
 */


#include "Map.h"
#include <stdlib.h>

using namespace std;

Map::Map(){}

Map::~Map(){}

void Map::addItem(Item* i){
	items.push_back(i);
}
void Map::addContainer(Container* c){
	containers.push_back(c);
}
void Map::addCreature(Creature* c){
	creatures.push_back(c);
}
void Map::addRoom(Room* r){
	rooms.push_back(r);
}

vector<Item*> Map::getItems(){
	return items;
}
vector<Container*> Map::getContainers(){
	return containers;
}
vector<Creature*> Map::getCreatures(){
	return creatures;
}
vector<Room*> Map::getRooms(){
	return rooms;
}


