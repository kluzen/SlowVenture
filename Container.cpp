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
	item = NULL;
	accept = NULL;
}

Container::~Container(){}

void Container::setStatus(string c){
	status = c;
}
void Container::setAccept(Item* i){
	accept = i;
}
void Container::setItem(Item* i){
	item = i;
}
void Container::addTrigger(Trigger* t){
	triggers.push_back(t);
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
Item* Container::getAccept(){
	return accept;
}
Item* Container::getItem(){
	return item;
}
vector<Trigger*> Container::getTriggers(){
	return triggers;
}


