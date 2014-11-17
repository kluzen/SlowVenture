/*
 * Creature.cpp
 *
 *  Created on: Nov 17, 2014
 *      Author: Ben
 */


#include "Creature.h"
#include <stdlib.h>

using namespace std;

Creature::Creature(char* n, char* d): name(n), description(d){
	status = NULL;
	attack = NULL;
}

Creature::~Creature(){}

void Creature::setStatus(char* c){
	status = c;
}
void Creature::addVulnerability(Item* i){
	vulnerabilities.push_back(i);
}
void Creature::setAttack(Attack* a){
	attack = a;
}
void Creature::addTrigger(Trigger* t){
	triggers.push_back(t);
}

char* Creature::getName(){
	return name;
}
char* Creature::getDescription(){
	return description;
}
char* Creature::getStatus(){
	return status;
}
vector<Item*> Creature::getVulnerabilities(){
	return vulnerabilities;
}
Attack* Creature::getAttack(){
	return attack;
}
vector<Trigger*> Creature::getTriggers(){
	return triggers;
}



