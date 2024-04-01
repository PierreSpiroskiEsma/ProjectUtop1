#include <iostream>
#include <fstream>
#include <string>
#include "Event.h"
#include "Interactible.h"
#include "Inventory.h"
#include "Item.h"
#include "Location.h"

using namespace std;
string rien;


void afficher_Menu_pricipal(){

	/****************************************

		1.Aller		2.faire		3.Utiliser un objet

	/*****************************************/


}

void afficher_Menu_Localisation() {

	/****************************************
	
		1.ville		2.musée		3.park
		4.metro		5.termosta	6.annuler	
	
	/*****************************************/


	/****************************************

		1.ville		2.musée		3.metro
		4.annuler

	/*****************************************/

	/****************************************

		1.validée 	2.annuler

	/*****************************************/
}

void afficher_Menu_Inventory() {


	/****************************************

		1.livre		2.code nucleaire	3.telephone
		4.pass metro	6.annuler

	/*****************************************/

	/****************************************

		1.Regarder		2.utiliser		3.annuler			

	/*****************************************/


}


void AfficcherEvent(Event target)
{


	/********************************************
	
		text text textetext text textetext text texte
		text text textetext text textetext text texte
		text text textetext text textetext text texte

		appuyer sur Entrer pour continuer
	
	*********************************************/

	if (target.get_Visited())
	{
		system("cls");

		cout << target.get_No_Item_message() << endl;

		cout << "appuyer sur Entrer pour continuer :" << endl;
		cin >> rien;
		cout << endl;

	}
	else
	{
		system("cls");

		cout << target.get_Item_Message() << endl;

		cout << "appuyer sur Entrer pour continuer :" << endl;
		cin >> rien;
		cout << endl;

		if (target.get_give_Item())
		{
			system("cls");

			cout << "vous avez reçu un beau briquet tout neuf !" << endl;

			cout << "appuyer sur Entrer pour continuer :" << endl;
			cin >> rien;
			cout << endl;
		}

		target.set_Visited(true);

	}
}

int main() {

	//initialer les objet

	//deplace le joueur dans le premier lieux 01

	//on affiche les oprion disponible

		// *** Aller ***

			// liste les destination present dans le lieux

				//deplace le joueur dans le lieux selectioner 01

				//Revien au menue 02

		// *** Faire ***
		
			// liste les event present dans le lieux

				// lance l'event selectioner et met a jour l'inventaire

				//Revien au menue 02

		// *** Utiliser ***

			// liste les objet present dans l'inventaire

				// Lire la description

				// utiliser

				//Revien au menue 02

			//Revien au menue 02

	Event Fou_Du_Metro;

	Fou_Du_Metro.set_Name("Fou du Metro");
	Fou_Du_Metro.set_give_Item(true);
	Fou_Du_Metro.set_Item_Message("item message : Bonjour, belle journée n'est-ce pas ? puis-je vous être utile ? ");
	Fou_Du_Metro.set_No_Item_message("NoItem : Une seule aide par jour mon amis d'autres son dans le besoin de mon assistance !");
	Fou_Du_Metro.set_Malveillance_Message("Mal : Quel homme inspirant ! vous perdez un point de malveillance !");
	Fou_Du_Metro.set_Malveillance_Damage(true);

	cout << "test" << endl;


	AfficcherEvent(Fou_Du_Metro);
	
	return 0;
}




