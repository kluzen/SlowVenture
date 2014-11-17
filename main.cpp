#include <iostream>
#include <fstream>
#include <string>
#include "rapidxml-1.13/rapidxml.hpp"
#include "Room.h"

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



	cout << doc.first_node()->first_node()->name() << endl;
	return 0;
}
