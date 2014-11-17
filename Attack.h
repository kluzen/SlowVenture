/*
 * Attack.h
 *
 *  Created on: Nov 16, 2014
 *      Author: Ben
 */

#ifndef ATTACK_H_
#define ATTACK_H_

class Attack
{
public:
	Attack();
	virtual ~Attack();
	void setPrint(char*);
	void addAction(char*);
	void addCondition(Condition);

	char* getPrint();
	char** getActions();
	Condition* getConditions();
private:
	char* print;
	char** actions;
	Condition* conditions;
};



#endif /* ATTACK_H_ */
