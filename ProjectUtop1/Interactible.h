#include <iostream>
#include <fstream>
#include <string>

#pragma once

using namespace std;


class Interactible {

	private : 
		// -------------------- Variables de la classe Interactible ----------------
		string name, description, file_location, image_location;
		int Identification_ID;

	public :

		// ------------- Methodes de la classe Interactible ---------------

		string get_Name();
		void set_Name(string set);


		string get_Desctiption();
		void set_Desctiption(string set);

		int get_Identification_ID();
		void set_Identification_ID(int Id);

		string get_file_location();
		void set_file_location(string set);

		string get_image_location();
		void set_image_location(string set);

		void next_screen();

		virtual void DescriptionFromFile(string String_File_Location, string* Target);

		virtual void Add_Reacheable_Location(int set);

		virtual void set_is_Possesd(bool set);

};


