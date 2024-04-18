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

void Location::Add_Event(Event* set)
{
	Event_List.push_back(set);
}

void Location::clear_Event_List()
{
	Event_List.clear();
}

vector<Event*> Location::get_Event_List()
{
	return Event_List;
}

void Location::DescriptionFromFile(string String_File_Location)
{
	ifstream infile(String_File_Location);

	if (infile.is_open()) {

		string line;

		while (getline(infile, line)) {

			cout << line << endl;

		}
	}
}



