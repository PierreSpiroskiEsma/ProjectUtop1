#pragma once
#include "Interactible.h"
#include<array>
#include<vector> 
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
	vector <int> Reacheable_Location;

public :

	// ------------- Methodes de la classe Location ---------------


	bool is_reacheable(int target);

	void Add_Reacheable_Location(int set);
	void clear_reacheable_location();
};

