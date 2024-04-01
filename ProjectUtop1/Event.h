#pragma once
#include <iostream>
#include "Interactible.h"
#include "Item.h"

class Event : public Interactible
{
private :
	// -------------------- Variables de la classe Event ----------------
	bool give_Item;
	Item Item_Reward;
	string Item_Message, No_Item_message, Malveillance_Message;
	bool Malveillance_Damage;
	bool Visited = false;


public :

	// ------------- Methodes de la classe Event ---------------

	bool get_give_Item();
	void set_give_Item(bool Item_Reward);

	std::string get_Item_Message();
	void set_Item_Message(std::string Item_Msg);

	std::string get_No_Item_message();
	void set_No_Item_message(std::string NoItem);

	std::string get_Malveillance_Message();
	void set_Malveillance_Message(std::string Mal);

	bool get_Malveillance_Damage();
	void set_Malveillance_Damage(bool Mal_Dmg);

	bool get_Visited();
	void set_Visited(bool visited);

}


	