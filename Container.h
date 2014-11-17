/*
 * Container.h
 *
 *  Created on: Nov 16, 2014
 *      Author: Ben
 */

#ifndef CONTAINER_H_
#define CONTAINER_H_

class Container
{
public:
	Container(char*,char*);
	virtual ~Container();
	void setStatus(char*);
	void addAccept(Item);
	void addItem(Item);
	void addTrigger(Trigger);

	char* getName();
	char* getDescription();
	char* getStatus();
	Item* getAccept();
	Item* getItems();
	Trigger* getTriggers();
private:
	char* name;
	char* description;
	char* status;
	Item* accept;
	Item* items;
	Trigger* triggers;
};



#endif /* CONTAINER_H_ */
