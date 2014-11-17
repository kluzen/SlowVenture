/*
 * Creature.h
 *
 *  Created on: Nov 16, 2014
 *      Author: Ben
 */

#ifndef CREATURE_H_
#define CREATURE_H_

#include <vector>

#include "Item.h"
#include "Attack.h"
#include "Trigger.h"

using namespace std;

class Creature
{
public:
	Creature(char*,char*);
	virtual ~Creature();
	void setStatus(char*);
	void addVulnerability(Item*);
	void setAttack(Attack*);
	void addTrigger(Trigger*);

	char* getName();
	char* getDescription();
	char* getStatus();
	vector<Item*> getVulnerabilities();
	Attack* getAttack();
	vector<Trigger*> getTriggers();
private:
	char* name;
	char* description;
	char* status;
	vector<Item*> vulnerabilities;
	Attack* attack;
	vector<Trigger*> triggers;
};




#endif /* CREATURE_H_ */
