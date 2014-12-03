/*
 * Attack.cpp
 *
 *  Created on: Nov 17, 2014
 *      Author: Ben
 */


#include "Attack.h"
#include <stdlib.h>

using namespace std;

Attack::Attack(){}

Attack::~Attack(){}

void Attack::setPrint(string c){
	print = c;
}
void Attack::addAction(string c){
	actions.push_back(c);
}
void Attack::addCondition(condition* c){
	conditions.push_back(c);
}

string Attack::getPrint(){
	return print;
}
vector<string> Attack::getActions(){
	return actions;
}
vector<condition*> Attack::getConditions(){
	return conditions;
}





