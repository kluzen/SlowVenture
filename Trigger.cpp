/*
 * Trigger.cpp
 *
 *  Created on: Nov 17, 2014
 *      Author: Ben
 */

#include "Trigger.h"
#include <stdlib.h>

using namespace std;

Trigger::Trigger(){}

Trigger::~Trigger(){}

void Trigger::setType(string c){
	type = c;
}
void Trigger::setPrint(string c){
	print = c;
}
void Trigger::addAction(string c){
	actions.push_back(c);
}
void Trigger::setOwner(string c){
	owner = c;
}
void Trigger::setStatus(string c){
	status = c;
}
void Trigger::setCommand(string c){
	command = c;
}
void Trigger::addCondition(condition* c){
	conditions.push_back(c);
}

string Trigger::getType(){
	return type;
}
string Trigger::getPrint(){
	return print;
}
vector<string> Trigger::getActions(){
	return actions;
}
string Trigger::getOwner(){
	return owner;
}
string Trigger::getStatus(){
	return status;
}
string Trigger::getCommand(){
	return command;
}
vector<condition*> Trigger::getConditions(){
	return conditions;
}

