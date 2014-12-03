/*
 * Item.cpp
 *
 *  Created on: Nov 17, 2014
 *      Author: Ben
 */


#include "Item.h"
#include <stdlib.h>

using namespace std;

Item::Item(string n, string d): name(n), description(d){
	turnOn = NULL;
}

Item::~Item(){}

void Item::setStatus(string c){
	status = c;
}
void Item::setWriting(string c){
	writting = c;
}
void Item::setTurnOn(turnon* t){
	turnOn = t;
}
void Item::addTrigger(Trigger* t){
	triggers.push_back(t);
}

string Item::getName(){
	return name;
}
string Item::getDescription(){
	return description;
}
string Item::getStatus(){
	return status;
}
string Item::getWriting(){
	return writting;
}
turnon* Item::getTurnOn(){
	return turnOn;
}
vector<Trigger*> Item::getTriggers(){
	return triggers;
}

