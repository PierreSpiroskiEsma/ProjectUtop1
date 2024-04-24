#pragma once
#include <iostream>
#include "Interactible.h"
#include "Item.h"

using namespace std;

class Event : public Interactible
{
private:
	// -------------------- Variables de la classe Event ----------------
	bool give_Item = false;
	Item* Item_Reward;
	string Item_Message, No_Item_message, Malveillance_Message, AllReadyTalk_location;
	bool Malveillance_Damage = false;
	bool Visited = false;


public:

	// ------------- Methodes de la classe Event ---------------

	bool get_give_Item();
	void set_give_Item(bool Is_Item);

	Item* get_item_Reward();
	void set_item_reward(Item* _Item);

	string get_Malveillance_Message();
	void set_Malveillance_Message(string Mal);

	string get_AllReadyTalk_location();
	void set_AllReadyTalk_location(string set);

	bool get_Malveillance_Damage();
	void set_Malveillance_Damage(bool Mal_Dmg);

	bool get_Visited();
	void set_Visited(bool visited);

	void DescriptionFromFile(string String_File_Location);
};


	