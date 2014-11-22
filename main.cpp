#include <iostream>
#include <fstream>
#include <string>
#include "rapidxml-1.13/rapidxml.hpp"
#include "Map.h"

using namespace std;
using namespace rapidxml;

void parseAttack(Map* gameMap, xml_node<> *node, Attack* attack){
	for(xml_node<> *child = node->first_node(); child; child = child->next_sibling()){
		string type = child->name();

		if(type == "print"){
			attack->setPrint(child->value());
		}else if(type == "action"){
			attack->addAction(child->value());
		}else if(type == "condition"){ // This may be an issue
			vector<Item*> v = gameMap->getItems();
			xml_node<> *testNode;
			char* object;
			char* status;
			char* owner;
			char* has;

			testNode = child->first_node("object", 6, false);
			if(testNode != 0)
				object = testNode->value();
			testNode = child->first_node("status", 6, false);
			if(testNode != 0)
				status = testNode->value();
			testNode = child->first_node("owner", 5, false);
			if(testNode != 0)
				owner = testNode->value();
			testNode = child->first_node("has", 3, false);
			if(testNode != 0)
				has = testNode->value();

			condition *c = new condition();
			c->status = status;
			c->owner = owner;
			if((string)has == "yes")
				c->has = true;
			else
				c->has = false;

			for(vector<Item*>::size_type i = 0; i != v.size(); i++){
				if(object == v[i]->getName()){
					c->object = v[i];
					break;
				}
			}
			attack->addCondition(c);
		}

	}

}

void parseTrigger(Map* gameMap, xml_node<> *node, Trigger* trigger){
	for(xml_node<> *child = node->first_node(); child; child = child->next_sibling()){
		string type = child->name();

		if(type == "type"){
			trigger->setType(child->value());
		}else if(type == "status"){
			trigger->setStatus(child->value());
		}else if(type == "print"){
			trigger->setPrint(child->value());
		}else if(type == "action"){
			trigger->setAction(child->value());
		}else if(type == "owner"){
			trigger->setOwner(child->value());
		}else if(type == "command"){
			trigger->setCommand(child->value());
		}else if(type == "condition"){ // This may be an issue
			vector<Item*> v = gameMap->getItems();
			xml_node<> *testNode;
			char* object;
			char* status;
			char* owner;
			char* has;

			testNode = child->first_node("object", 6, false);
			if(testNode != 0)
				object = testNode->value();
			testNode = child->first_node("status", 6, false);
			if(testNode != 0)
				status = testNode->value();
			testNode = child->first_node("owner", 5, false);
			if(testNode != 0)
				owner = testNode->value();
			testNode = child->first_node("has", 3, false);
			if(testNode != 0)
				has = testNode->value();

			condition *c = new condition();
			c->status = status;
			c->owner = owner;
			if((string)has == "yes")
				c->has = true;
			else
				c->has = false;

			for(vector<Item*>::size_type i = 0; i != v.size(); i++){
				if(object == v[i]->getName()){
					c->object = v[i];
					break;
				}
			}
			trigger->addCondition(c);
		}

	}
}

void parseItem(Map* gameMap, xml_node<> *node, Item* item){

	for(xml_node<> *child = node->first_node(); child; child = child->next_sibling()){
		string type = child->name();

		if(type == "writing"){
			item->setWriting(child->value());
		}else if(type == "status"){
			item->setStatus(child->value());
		}else if(type == "turnon"){
			char* print = child->first_node("print", 5, false)->value();
			char* action = child->first_node("action", 6, false)->value();
			turnon *t = new turnon();
			t->print = print;
			t->action = action;
			item->setTurnOn(t);
		}else if(type == "trigger"){
			Trigger *t = new Trigger();
			parseTrigger(gameMap, child, t);
			item->addTrigger(t);
		}

	}
}

void parseContainer(Map* gameMap, xml_node<> *node, Container* container){

	for(xml_node<> *child = node->first_node(); child; child = child->next_sibling()){
		string type = child->name();

		if(type == "status"){
			container->setStatus(child->value());
		}else if(type == "accept"){
			vector<Item*> v = gameMap->getItems();
			for(vector<Item*>::size_type i = 0; i != v.size(); i++){
				if(child->value() == v[i]->getName()){
					container->addAccept(v[i]);
					break;
				}
			}
		}else if(type == "item"){
			vector<Item*> v = gameMap->getItems();
			for(vector<Item*>::size_type i = 0; i != v.size(); i++){
				if(child->value() == v[i]->getName()){
					container->addItem(v[i]);
					break;
				}
			}
		}else if(type == "trigger"){
			Trigger *t = new Trigger();
			parseTrigger(gameMap, child, t);
			container->addTrigger(t);
		}

	}
}

void parseCreature(Map* gameMap, xml_node<> *node, Creature* creature){

	for(xml_node<> *child = node->first_node(); child; child = child->next_sibling()){
		string type = child->name();

		if(type == "status"){
			creature->setStatus(child->value());
		}else if(type == "vulnerability"){
			vector<Item*> v = gameMap->getItems();
			for(vector<Item*>::size_type i = 0; i != v.size(); i++){
				if(child->value() == v[i]->getName()){
					creature->addVulnerability(v[i]);
					break;
				}
			}
		}else if(type == "attack"){
			Attack *a = new Attack();
			parseAttack(gameMap, child, a);
			creature->setAttack(a);
		}else if(type == "trigger"){
			Trigger *t = new Trigger();
			parseTrigger(gameMap, child, t);
			creature->addTrigger(t);
		}

	}
}

void parseRoom(Map* gameMap, xml_node<> *node, Room* room){

	for(xml_node<> *child = node->first_node(); child; child = child->next_sibling()){
		string type = child->name();
		cout << type << endl;
		if(type == "type"){
			room->setType(child->value());
		}else if(type == "status"){
			room->setStatus(child->value());
		}else if(type == "item"){
			vector<Item*> v = gameMap->getItems();
			for(vector<Item*>::size_type i = 0; i != v.size(); i++){
				if(child->value() == v[i]->getName()){
					room->addItem(v[i]);
					break;
				}
			}
		}else if(type == "container"){
			vector<Container*> v = gameMap->getContainers();
			for(vector<Container*>::size_type i = 0; i != v.size(); i++){
				if(child->value() == v[i]->getName()){
					room->addContainer(v[i]);
					break;
				}
			}
		}else if(type == "creature"){
			vector<Creature*> v = gameMap->getCreatures();
			for(vector<Creature*>::size_type i = 0; i != v.size(); i++){
				if(child->value() == v[i]->getName()){
					room->addCreature(v[i]);
					break;
				}
			}
		}else if(type == "border"){
			vector<Room*> v = gameMap->getRooms();
			char* name = child->first_node("name", 4, false)->value();
			char* direction = child->first_node("direction", 9, false)->value();
			for(vector<Room*>::size_type i = 0; i != v.size(); i++){
				if(name == v[i]->getName()){
					border *b = new border();
					b->direction = direction;
					b->room = v[i];
					room->addBorder(b);
					break;
				}
			}
		}else if(type == "trigger"){
			Trigger *t = new Trigger();
			parseTrigger(gameMap, child, t);
			room->addTrigger(t);
		}

	}
}


// Prepares the map with the rooms, items, containers, and creatures
void parseMapNode(Map* gameMap, xml_node<> *node){
	xml_node<> *testNode;
	char* name = "";
	char* desc = "";

	testNode = node->first_node("name", 4, false);
	if(testNode != 0)
		name = testNode->value();
	testNode = node->first_node("description", 11, false);
	if(testNode != 0)
		desc = testNode->value();

	string nodeName = node->name();

	if(nodeName == "room"){
		gameMap->addRoom(new Room(name, desc));
//		cout << "New room: " << name << ", " << desc << endl;
	}else if(nodeName == "item"){
		gameMap->addItem(new Item(name, desc));
//		cout << "New item: " << name << ", " << desc << endl;
	}else if(nodeName == "container"){
		gameMap->addContainer(new Container(name, desc));
//		cout << "New container: " << name << ", " << desc << endl;
	}else if(nodeName == "creature"){
		gameMap->addCreature(new Creature(name, desc));
//		cout << "New creature: " << name << ", " << desc << endl;
	}else{
		cout << node->name() << " does not match anything" << endl;
	}
}

// Fully parses the nodes and links them together
void parseNode(Map* gameMap, xml_node<> *node){
	char* name = node->first_node("name", 4, false)->name();
	string nodeName = node->name();

	if(nodeName == "room"){
		vector<Room*> v = gameMap->getRooms();
		cout << v.size();
		for(vector<Room*>::size_type i = 0; i != v.size(); i++){
			if(name == v[i]->getName()){
				parseRoom(gameMap, node, v[i]);
				break;
			}
		}
	}else if(nodeName == "item"){
		vector<Item*> v = gameMap->getItems();
		for(vector<Item*>::size_type i = 0; i != v.size(); i++){
			if(name == v[i]->getName()){
				parseItem(gameMap, node, v[i]);
				break;
			}
		}
	}else if(nodeName == "container"){
		vector<Container*> v = gameMap->getContainers();
		for(vector<Container*>::size_type i = 0; i != v.size(); i++){
			if(name == v[i]->getName()){
				parseContainer(gameMap, node, v[i]);
				break;
			}
		}
	}else if(nodeName == "creature"){
		vector<Creature*> v = gameMap->getCreatures();
		for(vector<Creature*>::size_type i = 0; i != v.size(); i++){
			if(name == v[i]->getName()){
				parseCreature(gameMap, node, v[i]);
				break;
			}
		}
	}
}

int main () {
	string line;
	string content;
	ifstream myfile;
	myfile.open ("samples/sample.txt.xml");
	if(myfile.is_open()){
	  while(getline(myfile, line)){
		  content += line + '\n';
	  }
	  myfile.close();
	}

	xml_document<> doc;
	doc.parse<0>((char*)content.c_str());

	Map* gameMap = new Map();

	// Prepares the map with the rooms, items, containers, and creatures
	for(xml_node<> *child = doc.first_node()->first_node(); child; child = child->next_sibling()){
		parseMapNode(gameMap, child);
	}

	// Fully parses the nodes and links them together
	for(xml_node<> *child = doc.first_node()->first_node(); child; child = child->next_sibling()){
		parseNode(gameMap, child);
	}

	// User's inventory starting empty
	vector<Item*> inventory;

	// List of rooms on map
	vector<Room*> rooms = gameMap->getRooms();

	Room* curRoom = rooms[0];
	bool gameRunning = true;
	bool nextRoom = false;
	string input;

	while(gameRunning){
		cout << curRoom->getDescription() << endl;
		nextRoom = false;

		while(!nextRoom){
			cin >> input;

			// Check triggers
			bool triggerMet = false;
			vector<Trigger*> triggers = curRoom->getTriggers();
			cout << triggers.size() << endl;
			for(vector<Trigger*>::size_type i = 0; i != triggers.size(); i++){
				Trigger* t = triggers[i];
				cout << t->getCommand() << endl;
				if(input == t->getCommand()){
					cout << "match" << endl;
//					bool conditionMet = false;
//					// Trigger met, check conditions
//					vector<condition*> conditions = t->getConditions();
//					for(vector<condition*>::size_type j = 0; j != conditions.size(); j++){
//						condition* c = conditions[j];
//						conditionMet = true;
//						break;
//					}
//					if(conditionMet){
//						cout << t->getPrint() << endl;
//						triggerMet = true;
//						break;
//					}
				}
			}
			if(triggerMet){
				continue; // Trigger is met, ask user for another input;
			}

			if(input == "n" || input == "e" || input == "s" || input == "w"){
				// User attempting to move
				vector<border*> borders = curRoom->getBorders();
				cout << "moving" << endl;
			}
		}

	}


//	cout << doc.first_node()->first_node()->name() << endl;
	return 0;
}

