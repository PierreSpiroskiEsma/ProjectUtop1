#pragma once
#include "Interactible.h"


class Item : public Interactible
{
private :
	// -------------------- Variables de la classe Item ----------------



	bool Is_Visible, is_Possesd;
	int Place_Of_Use, Effect_id;
	bool Was_Used = false;
	bool* _Was_Used = &Was_Used;
	// présence dans l'inventaire

public :

	// ------------- Methodes de la classe Item ---------------

	int get_Place_Of_Use();
	void set_Place_Of_Use(int set);

	int get_Effect_id();
	void set_Effect_id(int set);

	bool get_Is_Visible();
	void set_Is_Visible(bool visible);

	bool* get_is_Possesd();
	void set_is_Possesd(bool possess);

	void DescriptionFromFile(string String_File_Location);

	void Show_Description();

	void Effect_library(int choice, Interactible* Place);
	void Use_Item(Interactible* place);

	//Surchage for adding Item
	void Use_Item(Interactible* place, Interactible* Item);
	void Effect_library(int choice, Interactible* Place, Interactible* Item);
};

