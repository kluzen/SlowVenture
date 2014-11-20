#include <iostream>
#include <fstream>
#include <string>
#include "rapidxml-1.13/rapidxml.hpp"
#include "Map.h"

using namespace std;
using namespace rapidxml;

void parseTrigger(Map* gameMap, xml_node<> *node, Trigger* trigger){}
void parseItem(Map* gameMap, xml_node<> *node, Item* Item){}
void parseContainer(Map* gameMap, xml_node<> *node, Container* container){}
void parseCreature(Map* gameMap, xml_node<> *node, Creature* creature){}

void parseRoom(Map* gameMap, xml_node<> *node, Room* room){

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
		cout << "New room: " << name << ", " << desc << endl;
	}else if(nodeName == "item"){
		gameMap->addItem(new Item(name, desc));
		cout << "New item: " << name << ", " << desc << endl;
	}else if(nodeName == "container"){
		gameMap->addContainer(new Container(name, desc));
		cout << "New container: " << name << ", " << desc << endl;
	}else if(nodeName == "creature"){
		gameMap->addCreature(new Creature(name, desc));
		cout << "New creature: " << name << ", " << desc << endl;
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

	vector<Room*> rooms = gameMap->getRooms();

	for(vector<Room*>::size_type i = 0; i != rooms.size(); i++){
		cout << rooms[i]->getName() << endl;
	}


//	cout << doc.first_node()->first_node()->name() << endl;
	return 0;
}

