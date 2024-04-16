#include "Item.h"

bool Item::get_Is_Visible()
{
	return Is_Visible;
}

void Item::set_Is_Visible(bool visible)
{

	Is_Visible = visible;
}

bool Item::get_is_Possesd()
{
	return is_Possesd;
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

void Item::Show_Description()
{
	system("cls");

	//Afficher image

	DescriptionFromFile(get_file_location());

	next_screen();
}

void Item::Use_Item()
{



}
