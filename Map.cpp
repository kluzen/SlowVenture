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

bool Map::isItem(string s){
	for(vector<Item*>::size_type i = 0; i != items.size(); i++){
		if(items[i]->getName() == s){
			return true;
		}
	}
	return false;
}
bool Map::isContainer(string s){
	for(vector<Container*>::size_type i = 0; i != containers.size(); i++){
		if(containers[i]->getName() == s){
			return true;
		}
	}
	return false;
}
bool Map::isCreature(string s){
	for(vector<Creature*>::size_type i = 0; i != creatures.size(); i++){
		if(creatures[i]->getName() == s){
			return true;
		}
	}
	return false;
}
bool Map::isRoom(string s){
	for(vector<Room*>::size_type i = 0; i != rooms.size(); i++){
		if(rooms[i]->getName() == s){
			return true;
		}
	}
	return false;
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


