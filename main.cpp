#include <iostream>
#include <fstream>
#include <string>
#include "rapidxml-1.13/rapidxml.hpp"
#include "Map.h"

using namespace std;
using namespace rapidxml;

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

	for(xml_node<> *child = doc.first_node()->first_node(); child; child = child->next_sibling()){
		xml_node<> *testNode;
		char* name = "";
		char* desc = "";

		testNode = child->first_node("name", 4, false);
		if(testNode != 0)
			name = testNode->value();
		testNode = child->first_node("description", 11, false);
		if(testNode != 0)
			desc = testNode->value();

		string nodeName = child->name();

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
			cout << child->name() << " does not match anything" << endl;
		}
	}


//	cout << doc.first_node()->first_node()->name() << endl;
	return 0;
}
