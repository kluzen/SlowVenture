/*
 * Trigger.cpp
 *
 *  Created on: Nov 17, 2014
 *      Author: Ben
 */

#include "Trigger.h"
#include <stdlib.h>

using namespace std;

Trigger::Trigger(){
	type = NULL;
	print = NULL;
	action = NULL;
	owner = NULL;
	status = NULL;
	command = NULL;
}

Trigger::~Trigger(){}

void Trigger::setType(char* c){
	type = c;
}
void Trigger::setPrint(char* c){
	print = c;
}
void Trigger::setAction(char* c){
	action = c;
}
void Trigger::setOwner(char* c){
	owner = c;
}
void Trigger::setStatus(char* c){
	status = c;
}
void Trigger::setCommand(char* c){
	command = c;
}
void Trigger::addCondition(condition* c){
	conditions.push_back(c);
}

char* Trigger::getType(){
	return type;
}
char* Trigger::getPrint(){
	return print;
}
char* Trigger::getAction(){
	return action;
}
char* Trigger::getOwner(){
	return owner;
}
char* Trigger::getStatus(){
	return status;
}
char* Trigger::getCommand(){
	return command;
}
vector<condition*> Trigger::getConditions(){
	return conditions;
}

