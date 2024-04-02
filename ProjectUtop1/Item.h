#pragma once
#include "Interactible.h"

class Item : public Interactible
{
private :
	// -------------------- Variables de la classe Item ----------------



	bool Is_Visible, is_Possesd;
	// présence dans l'inventaire

public :

	// ------------- Methodes de la classe Item ---------------

	bool get_Is_Visible();
	void set_Is_Visible(bool visible);

	bool get_is_Possesd();
	void set_is_Possesd(bool possess);

};

