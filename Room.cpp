/*
 * Room.cpp
 *
 *  Created on: Nov 16, 2014
 *      Author: Ben
 */

#include "Room.h"
#include <stdlib.h>

using namespace std;

Room::Room(string n, string d): name(n), description(d){}

Room::~Room(){}

void Room::setType(string c){
	type = c;
}
void Room::setStatus(string c){
	status = c;
}
void Room::addItem(Item* i){
	items.push_back(i);
}

bool Room::hasItem(string s){
	for(vector<Item*>::size_type i = 0; i != items.size(); i++){
		if(items[i]->getName() == s){
			return true;
		}
	}
	return false;
}
void Room::removeItem(string s){
	for(vector<Item*>::size_type i = 0; i != items.size(); i++){
		if(items[i]->getName() == s){
			items.erase(items.begin() + i);
			return;
		}
	}
}
Item* Room::getItem(string s){
	for(vector<Item*>::size_type i = 0; i != items.size(); i++){
		if(items[i]->getName() == s){
			return items[i];
		}
	}
	return NULL;
}
bool Room::hasContainer(string s){
	for(vector<Item*>::size_type i = 0; i != containers.size(); i++){
		if(containers[i]->getName() == s){
			return true;
		}
	}
	return false;
}
Container* Room::getContainer(string s){
	for(vector<Item*>::size_type i = 0; i != containers.size(); i++){
		if(containers[i]->getName() == s){
			return containers[i];
		}
	}
	return NULL;
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

string Room::getName(){
	return name;
}
string Room::getDescription(){
	return description;
}
string Room::getStatus(){
	return status;
}
string Room::getType(){
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
