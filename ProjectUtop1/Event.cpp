#include "Event.h"

bool Event::get_give_Item()
{
	return give_Item;
}

void Event::set_give_Item(bool Item_Reward)
{
	give_Item = Item_Reward;

}

std::string Event::get_Item_Message()
{
	return Item_Message;
}

void Event::set_Item_Message(std::string Item_Msg)
{
	Item_Message = Item_Msg;

}

std::string Event::get_No_Item_message()
{
	return No_Item_message;
}

void Event::set_No_Item_message(std::string NoItem)
{
	No_Item_message = NoItem;

}

std::string Event::get_Malveillance_Message()
{
	return Malveillance_Message;
}

void Event::set_Malveillance_Message(std::string Mal)
{

	Malveillance_Message = Mal;
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
