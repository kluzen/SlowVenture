/*
 * Container.cpp
 *
 *  Created on: Nov 17, 2014
 *      Author: Ben
 */

#include "Container.h"
#include <stdlib.h>

using namespace std;

Container::Container(char* n, char* d): name(n), description(d){
	status = NULL;
}

Container::~Container(){}

void Container::setStatus(char* c){
	status = c;
}
void Container::addAccept(Item* i){
	accept.push_back(i);
}
void Container::addItem(Item* i){
	items.push_back(i);
}
void Container::addTrigger(Trigger* t){
	triggers.push_back(t);
}

char* Container::getName(){
	return name;
}
char* Container::getDescription(){
	return description;
}
char* Container::getStatus(){
	return status;
}
vector<Item*> Container::getAccept(){
	return accept;
}
vector<Item*> Container::getItems(){
	return items;
}
vector<Trigger*> Container::getTriggers(){
	return triggers;
}


