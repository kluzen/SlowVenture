/*
 * Trigger.h
 *
 *  Created on: Nov 16, 2014
 *      Author: Ben
 */

#ifndef TRIGGER_H_
#define TRIGGER_H_


class Trigger
{
public:
	Trigger();
	virtual ~Trigger();
	void setType(char*);
	void setPrint(char*);
	void setAction(char*);
	void setOwner(char*);
	void setStatus(char*);
	void setCommand(char*);
	void addCondition(Condition);

	char* getType();
	char* getPrint();
	char* getAction();
	char* getOwner();
	char* getStatus();
	char* getCommand();
	Condition* getConditions();
private:
	char* type;
	char* print;
	char* action;
	char* owner;
	char* status;
	char* command;
	Condition* conditions;
};


#endif /* TRIGGER_H_ */
