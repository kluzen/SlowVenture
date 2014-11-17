/*
 * Creature.h
 *
 *  Created on: Nov 16, 2014
 *      Author: Ben
 */

#ifndef CREATURE_H_
#define CREATURE_H_

class Creature
{
public:
	Creature(char*,char*);
	virtual ~Creature();
	void setStatus(char*);
	void addVulnerability(Item);
	void setAttack(Attack);
	void addTrigger(Trigger);

	char* getName();
	char* getDescription();
	char* getStatus();
	Item* getVulnerabilities();
	Attack getAttack();
	Trigger* getTriggers();
private:
	char* name;
	char* description;
	char* status;
	Item* vulnerabilities;
	Attack attack;
	Trigger* triggers;
};




#endif /* CREATURE_H_ */
