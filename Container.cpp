/*
 * Container.cpp
 *
 *  Created on: Nov 17, 2014
 *      Author: Ben
 */

#include "Container.h"
#include <stdlib.h>

using namespace std;

Container::Container(string n, string d): name(n), description(d){
	open = false;
}

Container::~Container(){}

void Container::setStatus(string c){
	status = c;
}
void Container::setOpen(bool b){
	open = b;
}
void Container::addAccept(string s){
	accepts.push_back(s);
}
void Container::addItem(Item* i){
	items.push_back(i);
}
void Container::addTrigger(Trigger* t){
	triggers.push_back(t);
}

bool Container::doesAccept(string s){
	if(accepts.size() == 0)
		return true;

	for(vector<Item*>::size_type i = 0; i != accepts.size(); i++){
		if(accepts[i] == s){
			return true;
		}
	}
	return false;
}
bool Container::hasItem(string s){
	for(vector<Item*>::size_type i = 0; i != items.size(); i++){
		if(items[i]->getName() == s){
			return true;
		}
	}
	return false;
}
void Container::removeItem(string s){
	for(vector<Item*>::size_type i = 0; i != items.size(); i++){
		if(items[i]->getName() == s){
			items.erase(items.begin() + i);
			return;
		}
	}
}
Item* Container::getItem(string s){
	for(vector<Item*>::size_type i = 0; i != items.size(); i++){
		if(items[i]->getName() == s){
			return items[i];
		}
	}
	return NULL;
}

string Container::getName(){
	return name;
}
string Container::getDescription(){
	return description;
}
string Container::getStatus(){
	return status;
}
bool Container::isOpen(){
	return open;
}
vector<Item*> Container::getItems(){
	return items;
}
vector<Trigger*> Container::getTriggers(){
	return triggers;
}


