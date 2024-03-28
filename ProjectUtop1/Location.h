#pragma once
#include "Interactible.h"
#include "Event.h"

using namespace std;

enum class Location_List {
	Home,
	City_Place,
	Museum,
	Park
};

class Location : public Interactible{

	Event Event_List[];

};

