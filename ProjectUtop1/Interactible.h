#include <iostream>
#include <fstream>
#include <string>

#pragma once

using namespace std;


class Interactible {

	string name, description, file_location;
	int Identification_ID;
	bool is_unlock;

	string get_Name();
	void set_Name(string set);

	string get_Desctiption();
	void set_Desctiption(string set);

	string get_file_location();
	void set_file_location(string set);

	void DescriptionFromFile(string String_File_Location, string* Target);
};


