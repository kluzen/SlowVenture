/*
 * Item.cpp
 *
 *  Created on: Nov 17, 2014
 *      Author: Ben
 */


#include "Item.h"
#include <stdlib.h>

using namespace std;

Item::Item(char* n, char* d): name(n), description(d){
	status = NULL;
	writting = NULL;
	turnOn = NULL;
}

Item::~Item(){}

void Item::setStatus(char* c){
	status = c;
}
void Item::setWriting(char* c){
	writting = c;
}
void Item::setTurnOn(turnon* t){
	turnOn = t;
}
void Item::addTrigger(Trigger* t){
	triggers.push_back(t);
}

char* Item::getName(){
	return name;
}
char* Item::getDescription(){
	return description;
}
char* Item::getStatus(){
	return status;
}
char* Item::getWriting(){
	return writting;
}
turnon* Item::getTurnOn(){
	return turnOn;
}
vector<Trigger*> Item::getTriggers(){
	return triggers;
}

