#include "Location.h"


using namespace std;

bool Location::is_reacheable(int target)
{
	for (int i = 0; i < Reacheable_Location.size(); i++)
	{
		if (Reacheable_Location[i] == target) {
			return true;
		}	
	}

	return false;
}

void Location::Add_Reacheable_Location(int set)
{
	Reacheable_Location.push_back(set);
}

void Location::clear_reacheable_location()
{
	Reacheable_Location.clear();
}

