#include "Item.h"


int Item::get_Place_Of_Use(){

	return Place_Of_Use;
}

void Item::set_Place_Of_Use(int set){

	Place_Of_Use = set;
}

int Item::get_Effect_id(){

	return Effect_id;
}

void Item::set_Effect_id(int set){

	Effect_id = set;
}

bool Item::get_Is_Visible()
{
	return Is_Visible;
}

void Item::set_Is_Visible(bool visible)
{

	Is_Visible = visible;
}

bool* Item::get_is_Possesd()
{
	return &is_Possesd;
}

void Item::set_is_Possesd(bool possess)
{
	is_Possesd = possess;
}

void Item::DescriptionFromFile(string String_File_Location)
{
	ifstream infile(String_File_Location);

	if (infile.is_open()) {

		string line;

		while (getline(infile, line)) {

			cout << line << endl;

		}
	}
}

void Item::Show_Description() {
	system("cls");

	//Afficher image

	DescriptionFromFile(get_file_location());

	next_screen();
}

void Item::Effect_library(int choice, Interactible* Place) {

	switch (choice) {

	case 8:
		Place->Add_Reacheable_Location(7);
		DescriptionFromFile("Ressource_Text/txt_Ticket_Effect.txt");
		break;

	case 1:
		DescriptionFromFile("Ressource_Text/txt_This_Code_Is_Already_Used.txt");
		break;

	case 0:
		DescriptionFromFile("Ressource_Text/txt_Not_Here.txt");
		break;
	}

	next_screen();

}

void Item::Use_Item(Interactible* place) {

	if (place->get_Identification_ID() == Place_Of_Use) {

		if (!*_Was_Used) {

			Effect_library(Effect_id, place);
			*_Was_Used = true;

		}
		else {

			Effect_library(1, place);
		}

	}
	else {
		Effect_library(0, place);
	}

}
