/*
 * Creature.h
 *
 *  Created on: Nov 16, 2014
 *      Author: Ben
 */

#ifndef CREATURE_H_
#define CREATURE_H_

#include <vector>
#include <string>

#include "Item.h"
#include "Attack.h"
#include "Trigger.h"

using namespace std;

class Creature
{
public:
	Creature(string,string);
	virtual ~Creature();
	void setStatus(string);
	void addVulnerability(Item*);
	void setAttack(Attack*);
	void addTrigger(Trigger*);

	string getName();
	string getDescription();
	string getStatus();
	vector<Item*> getVulnerabilities();
	Attack* getAttack();
	vector<Trigger*> getTriggers();
private:
	string name;
	string description;
	string status;
	vector<Item*> vulnerabilities;
	Attack* attack;
	vector<Trigger*> triggers;
};




#endif /* CREATURE_H_ */
