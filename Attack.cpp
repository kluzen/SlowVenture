/*
 * Attack.cpp
 *
 *  Created on: Nov 17, 2014
 *      Author: Ben
 */


#include "Attack.h"
#include <stdlib.h>

using namespace std;

Attack::Attack(){
	print = NULL;
}

Attack::~Attack(){}

void Attack::setPrint(char* c){
	print = c;
}
void Attack::addAction(char* c){
	actions.push_back(c);
}
void Attack::addCondition(condition* c){
	conditions.push_back(c);
}

char* Attack::getPrint(){
	return print;
}
vector<char*> Attack::getActions(){
	return actions;
}
vector<condition*> Attack::getConditions(){
	return conditions;
}





