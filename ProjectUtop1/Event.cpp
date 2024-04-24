#include "Event.h"

using namespace std;

bool Event::get_give_Item()
{
	return give_Item;
}

void Event::set_give_Item(bool Is_Item)
{
	give_Item = Is_Item;

}

Item* Event::get_item_Reward()
{
	return Item_Reward;
}

void Event::set_item_reward(Item* _Item)
{
	Item_Reward = _Item;
}

string Event::get_Malveillance_Message()
{
	return Malveillance_Message;
}

void Event::set_Malveillance_Message(string Mal)
{

	Malveillance_Message = Mal;
}

string Event::get_AllReadyTalk_location()
{
	return AllReadyTalk_location;
}

void Event::set_AllReadyTalk_location(string set)
{

	AllReadyTalk_location = set;
}

bool Event::get_Malveillance_Damage()
{
	return Malveillance_Damage;
}

void Event::set_Malveillance_Damage(bool Mal_Dmg)
{
	Malveillance_Damage = Mal_Dmg;

}

bool Event::get_Visited()
{
	return Visited;
}

void Event::set_Visited(bool visited)
{

	Visited = visited;
}

void Event::DescriptionFromFile(string String_File_Location)
{
	ifstream infile(String_File_Location);

	if (infile.is_open()) {

		string line;

		while (getline(infile, line)) {

			cout << line << endl;

		}
	}
}

