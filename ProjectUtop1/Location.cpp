#include "Location.h"


using namespace std;

bool Location::is_reacheable(int target)
{
	for (int i = 0; i < end(Location_Reach)-begin(Location_Reach); i++)
	{
		if (Location_Reach[i] == target) {
			return true;
		}

		return false;
	}
}

bool Location::get_is_unlock()
{
	return is_unlock;
}

void Location::set_is_unlock(bool unlock)
{
	is_unlock = unlock;
}
