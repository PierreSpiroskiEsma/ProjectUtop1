#include "Event.h"


Event::Event()
{
	set_give_Item(Item_Reward);
	set_Item_Message(Item_Msg);
	set_No_Item_message(NoItem);
	set_Malveillance_Message(Mal);
	set_Malveillance_Damage(Mal_Dmg);

}

bool Event::get_give_Item()
{
	return false;
}

void Event::set_give_Item(bool Item_Reward)
{
	give_Item = Item_Reward;

}

std::string Event::get_Item_Message()
{
	return std::string();
}

void Event::set_Item_Message(std::string Item_Msg)
{
	Item_Message = Item

}

std::string Event::get_No_Item_message()
{
	return std::string();
}

void Event::set_No_Item_message(std::string NoItem)
{
	No_Item_message = NoItem

}

std::string Event::get_Malveillance_Message()
{
	return std::string();
}

void Event::set_Malveillance_Message(std::string Mal)
{

	Malveillance_Message = Mal
}

bool Event::get_Malveillance_Damage()
{
	return false;
}

void Event::set_Malveillance_Damage(bool Mal_Dmg)
{
	Malveillance_Damage = Mal_Dmg

}

bool Event::get_Visited()
{
	return true;
}

void Event::set_Visited(bool visited)
{

	Visited = visited
}
