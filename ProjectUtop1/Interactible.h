#include <iostream>
#pragma once

using namespace std;


class Interactible {

	string name, description;
	int Identification_ID;
	bool is_unlock;

	string get_Name();
	void set_Name(string set);

	string get_Desctiption();
	void set_Desctiption(string set);
};

