#include <iostream>
#include "Interactible.h"
#include "Location.h"


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

int Interactible::get_Identification_ID()
{
	return Identification_ID;
}

void Interactible::set_Identification_ID(int Id)
{
	Identification_ID = Id;
}

string Interactible::get_file_location() {

	return file_location;
}

void Interactible::set_file_location(string set) {

	file_location = set;
}

string Interactible::get_image_location() {

	return image_location;
}

void Interactible::set_image_location(string set) {

	image_location = set;
}

void Interactible::next_screen()
{
	string Rine;

	cout << "Passer a la Suite (oui/non)" << endl;
	cin >> Rine;
	system("cls");
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

void Interactible::Add_Reacheable_Location(int set){}

void Interactible::set_is_Possesd(bool set){}


