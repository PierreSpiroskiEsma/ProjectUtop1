#include <iostream>
#include "Interactible.h"


using namespace std;

string Interactible::get_Name() {


	return name;
}

void Interactible::set_Name(string set) {

	name = set;
}

string Interactible::get_Desctiption() {


	return description;
}

void Interactible::set_Desctiption(string set) {

	description = set;
}

string Interactible::get_file_location() {

	return file_location;
}

void Interactible::set_file_location(string set) {

	file_location = set;
}

void Interactible::DescriptionFromFile(string String_File_Location, string* Target) {

	ifstream infile(String_File_Location);

	if (infile.is_open()) {

		string line;

		while (getline(infile, line)) {

			*Target = *Target + line + "\n";

		}
	}

}

