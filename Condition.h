/*
 * Condition.h
 *
 *  Created on: Nov 16, 2014
 *      Author: Ben
 */

#ifndef CONDITION_H_
#define CONDITION_H_


class Condition
{
public:
	Condition();
	virtual ~Condition();
	void setHas(bool);
	void setStatus(char*);
	void setObject(Item);

	bool getHas();
	char* getStatus();
	Item getObject();
private:
	bool has;
	char* status;
	Item object;
};



#endif /* CONDITION_H_ */
