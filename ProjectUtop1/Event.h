#pragma once
#include <iostream>
#include "Interactible.h"
#include "Item.h"

class Event : public Interactible {

	bool give_Item;
	Item Item_Reward;
	string Item_Message, No_Item_message, Malveillance_Message;
	bool Malveillance_Damage;


};

