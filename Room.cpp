/*
 * Room.cpp
 *
 *  Created on: Nov 16, 2014
 *      Author: Ben
 */

#include "Room.h"
#include <stdlib.h>

using namespace std;

Room::Room(char* n, char* d): name(n), description(d){
	status = NULL;
	type = NULL;
}

Room::~Room(){}

void Room::setType(char* c){
	type = c;
}
void Room::setStatus(char* c){
	status = c;
}
void Room::addItem(Item* i){
	items.push_back(i);
}
void Room::removeItem(Item* item){
	for(vector<Item*>::size_type i = 0; i != items.size(); i++){
		if(item == items[i]){
			items.erase(items.begin() + i);
			return;
		}
	}
}
void Room::addContainer(Container* c){
	containers.push_back(c);
}
void Room::addCreature(Creature* c){
	creatures.push_back(c);
}
void Room::addBorder(border* b){
	borders.push_back(b);
}
void Room::addTrigger(Trigger* t){
	triggers.push_back(t);
}

char* Room::getName(){
	return name;
}
char* Room::getDescription(){
	return description;
}
char* Room::getStatus(){
	return status;
}
char* Room::getType(){
	return type;
}
vector<Item*> Room::getItems(){
	return items;
}
vector<Container*> Room::getContainers(){
	return containers;
}
vector<Creature*> Room::getCreatures(){
	return creatures;
}
vector<border*> Room::getBorders(){
	return borders;
}
vector<Trigger*> Room::getTriggers(){
	return triggers;
}
