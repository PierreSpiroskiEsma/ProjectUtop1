#pragma once
#include "Interactible.h"
#include<array> 
#include "Event.h"

using namespace std;

enum class Location_List {
	Home,
	City_Place,
	Museum,
	Park
};

class Location : public Interactible{

private :
	// -------------------- Variables de la classe Location ----------------

	bool is_unlock;
	int Location_Reach[2]{
		6,
		9
	};

public :

	// ------------- Methodes de la classe Location ---------------


	bool is_reacheable(int target);

	bool get_is_unlock();
	void set_is_unlock(bool unlock);
};

