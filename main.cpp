#include <iostream>
#include <fstream>
#include <string>
#include "rapidxml-1.13/rapidxml.hpp"
#include "Map.h"

using namespace std;
using namespace rapidxml;

Map* gameMap;

void parseAttack(xml_node<> *node, Attack* attack){
	for(xml_node<> *child = node->first_node(); child; child = child->next_sibling()){
		string type = child->name();

		if(type == "print"){
			attack->setPrint(child->value());
		}else if(type == "action"){
			attack->addAction(child->value());
		}else if(type == "condition"){ // This may be an issue
			vector<Item*> v = gameMap->getItems();
			xml_node<> *testNode;
			string object;
			string status;
			string owner;
			string has;

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
			c->objectI = NULL;
			c->objectC = NULL;

			if(has == "yes")
				c->has = true;
			else
				c->has = false;

			for(vector<Item*>::size_type i = 0; i != v.size(); i++){
				if(object == v[i]->getName()){
					c->objectI = v[i];
					break;
				}
			}
			vector<Container*> vc = gameMap->getContainers();
			for(vector<Container*>::size_type i = 0; i != vc.size(); i++){
				if(object == vc[i]->getName()){
					c->objectC = vc[i];
					break;
				}
			}
			attack->addCondition(c);
		}

	}

}

void parseTrigger(xml_node<> *node, Trigger* trigger){
	for(xml_node<> *child = node->first_node(); child; child = child->next_sibling()){
		string type = child->name();

		if(type == "type"){
			trigger->setType(child->value());
		}else if(type == "status"){
			trigger->setStatus(child->value());
		}else if(type == "print"){
			trigger->setPrint(child->value());
		}else if(type == "action"){
			trigger->addAction(child->value());
		}else if(type == "owner"){
			trigger->setOwner(child->value());
		}else if(type == "command"){
			trigger->setCommand(child->value());
		}else if(type == "condition"){ // This may be an issue
			vector<Item*> v = gameMap->getItems();
			xml_node<> *testNode;
			string object;
			string status;
			string owner;
			string has;

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
			c->objectI = NULL;
			c->objectC = NULL;

			if(has == "yes")
				c->has = true;
			else
				c->has = false;

			for(vector<Item*>::size_type i = 0; i != v.size(); i++){
				if(object == v[i]->getName()){
					c->objectI = v[i];
					break;
				}
			}
			vector<Container*> vc = gameMap->getContainers();
			for(vector<Container*>::size_type i = 0; i != vc.size(); i++){
				if(object == vc[i]->getName()){
					c->objectC = vc[i];
					break;
				}
			}
			trigger->addCondition(c);
		}

	}
}

void parseItem(xml_node<> *node, Item* item){

	for(xml_node<> *child = node->first_node(); child; child = child->next_sibling()){
		string type = child->name();

		if(type == "writing"){
			item->setWriting(child->value());
		}else if(type == "status"){
			item->setStatus(child->value());
		}else if(type == "turnon"){
			string print = child->first_node("print", 5, false)->value();
			string action = child->first_node("action", 6, false)->value();
			turnon *t = new turnon();
			t->print = print;
			t->action = action;
			item->setTurnOn(t);
		}else if(type == "trigger"){
			Trigger *t = new Trigger();
			parseTrigger(child, t);
			item->addTrigger(t);
		}

	}
}

void parseContainer(xml_node<> *node, Container* container){

	for(xml_node<> *child = node->first_node(); child; child = child->next_sibling()){
		string type = child->name();

		if(type == "status"){
			container->setStatus(child->value());
		}else if(type == "accept"){
			vector<Item*> v = gameMap->getItems();
			for(vector<Item*>::size_type i = 0; i != v.size(); i++){
				if(child->value() == v[i]->getName()){
					container->addAccept(child->value());
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
			parseTrigger(child, t);
			container->addTrigger(t);
		}

	}
}

void parseCreature(xml_node<> *node, Creature* creature){

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
			parseAttack(child, a);
			creature->setAttack(a);
		}else if(type == "trigger"){
			Trigger *t = new Trigger();
			parseTrigger(child, t);
			creature->addTrigger(t);
		}

	}
}

void parseRoom(xml_node<> *node, Room* room){

	for(xml_node<> *child = node->first_node(); child; child = child->next_sibling()){
		string type = child->name();
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
			string name = child->first_node("name", 4, false)->value();
			string direction = child->first_node("direction", 9, false)->value();
			for(vector<Room*>::size_type i = 0; i != v.size(); i++){
				if(name == v[i]->getName()){
					border *b = new border();
					b->direction = direction[0];
					b->room = v[i];
					room->addBorder(b);
					break;
				}
			}
		}else if(type == "trigger"){
			Trigger *t = new Trigger();
			parseTrigger(child, t);
			room->addTrigger(t);
		}

	}
}


// Prepares the map with the rooms, items, containers, and creatures
void parseMapNode(xml_node<> *node){
	xml_node<> *testNode;
	string name;
	string desc;

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
void parseNode(xml_node<> *node){
	string name = node->first_node("name", 4, false)->value();
	string nodeName = node->name();

	if(nodeName == "room"){
		vector<Room*> v = gameMap->getRooms();
		for(vector<Room*>::size_type i = 0; i != v.size(); i++){
			if(name == v[i]->getName()){
				parseRoom(node, v[i]);
				break;
			}
		}
	}else if(nodeName == "item"){
		vector<Item*> v = gameMap->getItems();
		for(vector<Item*>::size_type i = 0; i != v.size(); i++){
			if(name == v[i]->getName()){
				parseItem(node, v[i]);
				break;
			}
		}
	}else if(nodeName == "container"){
		vector<Container*> v = gameMap->getContainers();
		for(vector<Container*>::size_type i = 0; i != v.size(); i++){
			if(name == v[i]->getName()){
				parseContainer(node, v[i]);
				break;
			}
		}
	}else if(nodeName == "creature"){
		vector<Creature*> v = gameMap->getCreatures();
		for(vector<Creature*>::size_type i = 0; i != v.size(); i++){
			if(name == v[i]->getName()){
				parseCreature(node, v[i]);
				break;
			}
		}
	}
}

// Splits a string into a vector of words in the string
vector<string> split(string s){
	vector<string> v;
	int size = s.size();
	int beg = 0;
	int end = 0;

	while(beg < size){
		while(end < size && s.at(end) != ' '){
			end++;
		}
		if(beg != end){
			v.push_back(s.substr(beg, end - beg));
		}
		beg = end + 1;
		end++;
	}
	return v;
}

bool analyzeInput(Room* &curRoom, vector<Item*> &inventory, string input);

bool triggerCheck(Room* &curRoom, Trigger* &t, vector<Item*> &inventory, string input){
	if(t->getType() == "disabled"){
		return false;
	}else if(t->getCommand().empty() || input == t->getCommand()){
		bool conditionMet = false;
		// Trigger is set off, check conditions
		vector<condition*> conditions = t->getConditions();
		for(vector<condition*>::size_type j = 0; j != conditions.size(); j++){
			condition* c = conditions[j];

			// Owner of an item check
			if(c->owner == "inventory"){
				conditionMet = !c->has;
				if(inventory.size() > 0){
					for(vector<Item*>::size_type k = 0; k != inventory.size(); k++){
						if(inventory[k]->getName() == c->objectI->getName()){
							conditionMet = !conditionMet;
							break;
						}
					}
				}
//				}else if(!c->owner.empty()){ // Maybe not needed
//					if(gameMap->isContainer(c->owner)){
//
//					}
			}else{ // status check on an object
				if(c->objectC != NULL && c->objectC->getStatus() == c->status){
					conditionMet = true;
				}else if(c->objectI != NULL && c->objectI->getStatus() == c->status){
					conditionMet = true;
				}

			}
			break;
		}
		if(conditionMet){
			cout << t->getPrint() << endl;
			if(t->getType() != "permanent"){
				t->setType("disabled");
			}
			vector<string> actions = t->getActions();
			bool nextRoomTemp = false;
			for(vector<string>::size_type m = 0; m != actions.size(); m++){
//				cout << "ANALYZE: " << actions[m] << endl;
				if(analyzeInput(curRoom, inventory, actions[m])){
					nextRoomTemp = true;
				}
			}
//			nextRoom = nextRoomTemp;
			return true;
		}
	}
	return false;
}

bool analyzeInput(Room* &curRoom, vector<Item*> &inventory, string input){
//	vector<Item*> inventory = *inventoryP;
	bool nextRoom = false;
	bool triggerMet = false;

	// Check triggers in the current room
	vector<Trigger*> triggers = curRoom->getTriggers();
	for(vector<Trigger*>::size_type i = 0; i != triggers.size(); i++){
		if(triggerCheck(curRoom, triggers[i], inventory, input)){
			triggerMet = true;
			break;
		}
	}
	if(triggerMet){
		return false; // Trigger is met, ask user for another input;
	}
	// Check triggers of creatures in the current room
	vector<Creature*> creatures = curRoom->getCreatures();
	for(vector<Creature*>::size_type i = 0; i != creatures.size(); i++){
		vector<Trigger*> triggers = creatures[i]->getTriggers();
		for(vector<Trigger*>::size_type j = 0; j != triggers.size(); j++){
			if(triggerCheck(curRoom, triggers[j], inventory, input)){
				triggerMet = true;
				break;
			}
		}
	}
	if(triggerMet){
		return false; // Trigger is met, ask user for another input;
	}
	if(input == "n" || input == "e" || input == "s" || input == "w"){
		// User attempting to move
		vector<border*> borders = curRoom->getBorders();
		bool moving = false;
		for(vector<border*>::size_type i = 0; i != borders.size(); i++){
			// Moving user to next room
//					cout << borders[i]->direction << endl;
			if(borders[i]->direction == input[0]){
				nextRoom = true;
				moving = true;
				curRoom = borders[i]->room;
				break;
			}
		}
		if(!moving){
			cout << "Can't go that way." << endl;
			return false;
		}
	}else if(input == "i"){
		// List inventory items
		cout << "Inventory: ";
		if(inventory.size() == 0){
			cout << "empty" << endl;
		}else{
			bool first = true;
			for(vector<Item*>::size_type i = 0; i != inventory.size(); i++){
				if(first){
					first = false;
					cout << inventory[i]->getName();
				}else{
					cout << ", " << inventory[i]->getName();
				}
			}
			cout << endl;
		}
	}else if(input == "Game Over"){
		cout << "Victory!" << endl;
		exit(0);
	}else if(input == "open exit"){
		if(curRoom->getType() == "exit"){
			cout << "Game Over" << endl;
			exit(0);
		}else{
			cout << "Error" << endl;
			return false;
		}
	}else{
		vector<string> v = split(input); // Splits input on spaces
		if(v.size() > 1){
			string command = v[0];
			string second = v[1];

			if(command == "take"){
				// Try to take something
				// Move item from room to inventory
				bool found = false;
				if(curRoom->hasItem(second)){
					inventory.push_back(curRoom->getItem(second));
					curRoom->removeItem(second);
					cout << "Item " << second << " added to inventory." << endl;
					found = true;
				}
				vector<Container*> containers = curRoom->getContainers();
				for(vector<Container*>::size_type i = 0; i != containers.size(); i++){
					if(containers[i]->isOpen()){
						if(containers[i]->hasItem(second)){
							inventory.push_back(containers[i]->getItem(second));
							containers[i]->removeItem(second);
							cout << "Item " << second << " added to inventory." << endl;
							found = true;
							break;
						}
					}
				}
				if(!found){
					cout << "Error" << endl;
					return false;
				}
			}else if(command == "open"){
				// Try to open something
				// Move items from container to room

				if(curRoom->hasContainer(second)){
					Container* c = curRoom->getContainer(second);
					c->setOpen(true);
					vector<Item*> items = c->getItems();
					if(items.size() == 0){
						cout << second << " is empty." << endl;
					}else{
						cout << second << " contains " << items[0]->getName();
						for(vector<Item*>::size_type i = 1; i != items.size(); i++){
							cout << ", " << items[i]->getName();
						}
						cout << "." << endl;
					}
				}else{
					cout << "Error" << endl;
					return false;
				}
			}else if(command == "read"){
				// Try to read something
				bool found = false;
				for(vector<Item*>::size_type i = 0; i != inventory.size(); i++){
					if(second == inventory[i]->getName()){
						if(inventory[i]->getWriting().empty()){
							cout << "Nothing written." << endl;
						}else{
							cout << inventory[i]->getWriting() << endl;
						}
						found = true;
						break;
					}
				}
				if(!found){
					cout << "Error" << endl;
					return false;
				}
			}else if(command == "drop"){
				// Try to drop seomthing
				// Move item from inventory to room
				bool found = false;
				for(vector<Item*>::size_type i = 0; i != inventory.size(); i++){
					if(second == inventory[i]->getName()){
						vector<Item*> items = curRoom->getItems();
						curRoom->addItem(inventory[i]);
						inventory.erase(inventory.begin() + i);
						cout << second << " dropped." << endl;
						found = true;
						break;
					}
				}
				if(!found){
					cout << "Error" << endl;
					return false;
				}
			}else if(command == "put" && v.size() >= 4){
				// Analyze put command
				// Move item from inventory to container
				bool found1 = false;
				vector<Item*>::size_type place = 0;
				for(vector<Item*>::size_type i = 0; i != inventory.size(); i++){
					if(second == inventory[i]->getName()){
						place = i;
						found1 = true;
						break;
					}
				}

				if(found1){ // Item is in inventory
					if(curRoom->hasContainer(v[3])){
						Container* c = curRoom->getContainer(v[3]);
						Item* i = inventory[place];

						if(c->doesAccept(i->getName())){
							c->addItem(i);
							inventory.erase(inventory.begin() + place);
							cout << "Item " << second << " added to " << v[3] << "." << endl;

							// Trigger check for container
							vector<Trigger*> triggers = c->getTriggers();
							for(vector<Trigger*>::size_type j = 0; j != triggers.size(); j++){
								bool conditionMet = false;
								vector<condition*> conditions = triggers[j]->getConditions();
								for(vector<condition*>::size_type k = 0; k != conditions.size(); k++){
									if(conditions[k]->owner == c->getName()){
										bool b = ~((conditions[k]->has) ^ (c->hasItem(conditions[k]->objectI->getName())));//  conditions[k]->objectI == containers[i]->getItem()));
										if(b){
											conditionMet = true;
											break;
										}
									}
								}
								if(conditionMet){
									cout << triggers[j]->getPrint() << endl;

									vector<string> actions = triggers[j]->getActions();
									bool nextRoomTemp = false;
									for(vector<string>::size_type m = 0; m != actions.size(); m++){
										if(analyzeInput(curRoom, inventory, actions[m])){
											nextRoomTemp = true;
										}
									}
									nextRoom = nextRoomTemp;
								}
							}
						}else{
							cout << "Error" << endl;
							return false;
						}
					}else{
						cout << "Error" << endl;
						return false;
					}
				}else{
					cout << "Error" << endl;
					return false;
				}
			}else if(command == "turn" && second == "on" && v.size() >= 3){
				// Try to turn something on
				bool found = false;
				for(vector<Item*>::size_type i = 0; i != inventory.size(); i++){
					if(v[2] == inventory[i]->getName() && inventory[i]->getTurnOn() != NULL){
						cout << "You activate the " << v[2] << "." << endl;
						cout << inventory[i]->getTurnOn()->print << endl;
						nextRoom = analyzeInput(curRoom, inventory, inventory[i]->getTurnOn()->action);
						found = true;
						break;
					}
				}
				if(!found){
					cout << "Error" << endl;
					return false;
				}
			}else if(command == "attack" && v.size() >= 4){
				// Analyze attack command
				bool match = false;
				vector<Creature*> creatures = curRoom->getCreatures();
				for(vector<Creature*>::size_type i = 0; i != creatures.size(); i++){
					if(second == creatures[i]->getName()){
						// Creature found
						for(vector<Item*>::size_type j = 0; j != inventory.size(); j++){
							if(v[3] == inventory[j]->getName()){
								// Player has attacking item
								vector<Item*> vulnerabilities = creatures[i]->getVulnerabilities();
								for(vector<Item*>::size_type k = 0; k != vulnerabilities.size(); k++){
									if(v[3] == vulnerabilities[k]->getName()){
										// Item used is a vulnerability

										Attack* a = creatures[i]->getAttack();
										if(a == NULL){
											match = true;
											cout << "You assault the " << second << " with the " << v[3] << "." << endl;
											break;
										}
										// Analyze attack conditions
										bool conditionMet = false;

										vector<condition*> conditions = a->getConditions();
										for(vector<condition*>::size_type l = 0; l != conditions.size(); l++){
											if(conditions[l]->status == inventory[j]->getStatus()){
												conditionMet = true;
												break;
											}
										}

										if(conditions.size() == 0 || conditionMet){
											match = true;
											cout << "You assault the " << second << " with the " << v[3] << "." << endl;
											if(!a->getPrint().empty()){
												cout << a->getPrint() << endl;
											}
											vector<string> actions = a->getActions();
											bool nextRoomTemp = false;
											for(vector<string>::size_type m = 0; m != actions.size(); m++){
												if(analyzeInput(curRoom, inventory, actions[m])){
													nextRoomTemp = true;
												}
											}
											nextRoom = nextRoomTemp;
										}
									}
								}
							}
						}
					}
				}
				if(!match){
					cout << "Error" << endl;
					return false;
				}
			// Commands not really used by users
			}else if(command == "Update"){
				// Updates status of some item
				vector<Item*> items = gameMap->getItems();
				for(vector<Item*>::size_type i = 0; i != items.size(); i++){
					if(items[i]->getName() == second){
						items[i]->setStatus(v[3]);
//						cout << "DEBUG::UPDATED " << second << " TO " << v[3] << endl;
						break;
					}
				}
				vector<Container*> containers = gameMap->getContainers();
				for(vector<Container*>::size_type i = 0; i != containers.size(); i++){
					if(containers[i]->getName() == second){
						containers[i]->setStatus(v[3]);
//						cout << "DEBUG::UPDATED " << second << " TO " << v[3] << endl;
						break;
					}
				}
			}else if(command == "Add"){
				// Adds an item or creature to room or container
				vector<Room*> rooms = gameMap->getRooms();
				vector<Item*> items = gameMap->getItems();
				vector<Creature*> creatures = gameMap->getCreatures();
				Item* item = NULL;
				Creature* creature = NULL;
				bool found = false;

				// Find item
				for(vector<Item*>::size_type i = 0; i != items.size(); i++){
					if(items[i]->getName() == second){
						item = items[i];
						break;
					}
				}
				if(item == NULL){
					// Item not found, Find creature
					for(vector<Creature*>::size_type i = 0; i != creatures.size(); i++){
						if(creatures[i]->getName() == second){
							creature = creatures[i];
							break;
						}
					}
				}

				// Find room
				for(vector<Room*>::size_type i = 0; i != rooms.size(); i++){
					if(rooms[i]->getName() == v[3]){
						found = true;
						if(creature != NULL){
							rooms[i]->addCreature(creature);
//							cout << "DEBUG::ADDED " << second << " TO " << v[3] << endl;
						}else if(item != NULL){
							rooms[i]->addItem(item);
//							cout << "DEBUG::ADDED " << second << " TO " << v[3] << endl;
						}
						break;
					}
				}
				if(!found){
					// Room not found, look for container
					vector<Container*> containers = gameMap->getContainers();
					for(vector<Container*>::size_type i = 0; i != containers.size(); i++){
						if(containers[i]->getName() == v[3] && item != NULL){
							containers[i]->addItem(item);
//							cout << "DEBUG::ADDED " << second << " TO " << v[3] << endl;
							break;
						}
					}
				}
			}else if(command == "Delete"){
				// Removes creature
				vector<Room*> rooms = gameMap->getRooms();
				for(vector<Room*>::size_type i = 0; i != rooms.size(); i++){
					if(rooms[i]->hasCreature(second)){
						rooms[i]->removeCreature(second);
//						cout << "DEBUG::DELETED " << second << endl;
						break;
					}
				}
			}else{
				cout << "Error" << endl;
				return false;
			}
		}else{
			cout << "Error" << endl;
			return false;
		}
	}

	// See if that triggers something for a creature
	creatures = curRoom->getCreatures();
	for(vector<Creature*>::size_type i = 0; i != creatures.size(); i++){
		vector<Trigger*> triggers = creatures[i]->getTriggers();
		for(vector<Trigger*>::size_type j = 0; j != triggers.size(); j++){
			triggerCheck(curRoom, triggers[j], inventory, "NULL");
//			if(triggers[j]->getStatus() != "disabled"){
//				bool conditionMet = false;
//				vector<condition*> conditions = triggers[j]->getConditions();
//				for(vector<condition*>::size_type k = 0; k != conditions.size(); k++){
//					condition* c = conditions[k];
//					if(c->objectI != NULL && c->objectI->getStatus() == c->status){
//						conditionMet = true;
//						break;
//					}
//				}
//				if(conditionMet){
//					cout << triggers[j]->getPrint() << endl;
//					if(triggers[j]->getType() != "permanent"){
//						triggers[j]->setStatus("disabled");
//					}
//				}
//			}
		}
	}

	return nextRoom;
}


int main (int argc, char* argv[]) {
	if(argc < 2){
		cerr << "Usage: " << argv[0] << " input_file.xml" << endl;
		return 1;
	}


	string line;
	string content;
	ifstream myfile;
	myfile.open (argv[1]);
	if(!myfile.good()){
		cerr << "Invalid file" << endl;
		return 1;
	}

	if(myfile.is_open()){
	  while(getline(myfile, line)){
		  content += line + '\n';
	  }
	  myfile.close();
	}

	xml_document<> doc;
	doc.parse<0>((char*)content.c_str());

	gameMap = new Map();

	// Prepares the map with the rooms, items, containers, and creatures
	for(xml_node<> *child = doc.first_node()->first_node(); child; child = child->next_sibling()){
		parseMapNode(child);
	}

	// Fully parses the nodes and links them together
	for(xml_node<> *child = doc.first_node()->first_node(); child; child = child->next_sibling()){
		parseNode(child);
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
			getline(cin, input);

			nextRoom = analyzeInput(curRoom, inventory, input);
		}
	}

	return 0;
}

