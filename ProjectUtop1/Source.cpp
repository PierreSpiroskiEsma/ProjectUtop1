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
int ChoixJoueurMenuPrinc;
int ChoixJoueurMenuLoc;
int ChoixJoueurMenuLocValidation;

// **************************************************************
// Menu Localisation
//***************************************************************

void afficher_Menu_Inventory(Item target[]) {

	int MenuChoice = 0;
	int ItemPerLine = 0;
	/****************************************

		1.ville		2.musée		3.park
		4.metro		5.termosta	6.annuler

	/*****************************************/

	system("cls");
	cout << "****************************************" << endl;
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		if (target[i].get_is_Possesd())
		{
			if (target[i].get_Is_Visible())
			{
				MenuChoice++;
				if (ItemPerLine == 3)
				{
					ItemPerLine = 1;
					
					cout << endl;
					cout << MenuChoice << "." << target[i].get_Name()<<"  ";


				}
				else
				{
					ItemPerLine++;
					cout << MenuChoice << "." << target[i].get_Name() << "      ";

				}

			}



		}

		
	};
	cout << endl << endl;
	cout << MenuChoice + 1 << ".Annuler";
	cout << endl << endl;
	cout << "*****************************************" << endl << endl;
	cin >> ChoixJoueurMenuLoc;//garder en mémoire quel objet est séléctionné
	cout << endl;
	cout << "****************************************" << endl;
	cout << "1.Valider" << "         " << "2.Annuler" << endl << endl;
	cout << "****************************************" << endl;
	cin >> ChoixJoueurMenuLocValidation;
	do
	{
		switch (ChoixJoueurMenuLocValidation)
		{
		case 1:
			
			cout << "je valide" << endl;
			break;
		case 2:
			
			cout << "j'annule" << endl;
			break;
		default:
			cout << "choix invalide";
			break;
		}

	} while (ChoixJoueurMenuLocValidation != 1 && ChoixJoueurMenuLocValidation != 2);

	/****************************************

		1.validée 	2.annuler

	/*****************************************/
}

// **************************************************************
// Menu principal
//***************************************************************
void afficher_Menu_pricipal(Item UseMenu[]){

	system("cls");
	cout << "****************************************" << endl;
	cout << endl;
	cout << "1.Aller	  2.faire	  3.Utiliser un objet" << endl;
	cout << endl;
	cout << "*****************************************" << endl << endl;
	cin >> ChoixJoueurMenuPrinc;
	cout << endl;
	
	do 
	{
		switch (ChoixJoueurMenuPrinc)
		{
		case 1:
			//afficher_Menu_Localisation(UseMenu);
			 cout << "je vais dans localisation" << endl;
			 break;
		case 2:
			//afficher_Menu_Event()
			  cout << "je vais dans Event" << endl;
			  break;
		case 3:
			afficher_Menu_Inventory(UseMenu);
			
			  break;
		default:
			cout << "choix invalide";
			break;
		}

	} while (ChoixJoueurMenuPrinc != 1 && ChoixJoueurMenuPrinc != 2 && ChoixJoueurMenuPrinc != 3);


}



// **************************************************************
// Menu Inventaire
//***************************************************************

void afficher_Menu_Localisation() {


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

	/*if (target.get_Visited())
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

	}*/
}

int main()
{

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

	



// ******************************************************************************
// set up des PNJ du jeu 
//*******************************************************************************

	Event Fou_Du_Metro;

	Fou_Du_Metro.set_Name("Fou du Metro");
	Fou_Du_Metro.set_give_Item(true);
	Fou_Du_Metro.set_Item_Message("item message : Bonjour, belle journée n'est-ce pas ? puis-je vous être utile ? ");
	Fou_Du_Metro.set_No_Item_message("NoItem : Une seule aide par jour mon amis d'autres son dans le besoin de mon assistance !");
	Fou_Du_Metro.set_Malveillance_Message("Mal : Quel homme inspirant ! vous perdez un point de malveillance !");
	Fou_Du_Metro.set_Malveillance_Damage(true);

// ******************************************************************************
// set up des objets du jeu 
//*******************************************************************************

	Item Portefeuille;

	Portefeuille.set_Name("Portefeuille");
	Portefeuille.set_Desctiption("C'est un vieux portefeuille en cuir noir");
	Portefeuille.set_Identification_ID(1);
	Portefeuille.set_Is_Visible(true);
	Portefeuille.set_is_Possesd(true);

	Item Telephone;

	Telephone.set_Name("Telephone");
	Telephone.set_Desctiption("Un 3310 !!!!! une vrais relique d'un anciens monde !!");
	Telephone.set_Identification_ID(2);
	Telephone.set_Is_Visible(true);
	Telephone.set_is_Possesd(true);
	
	Item Ticket;

	Ticket.set_Name("Ticket");
	Ticket.set_Desctiption("Un ticket pour le musée du vieux monde que vous avez acheté.");
	Ticket.set_Identification_ID(3);
	Ticket.set_Is_Visible(true);
	Ticket.set_is_Possesd(true);
	
	Item Ticket2;

	Ticket2.set_Name("Ticket2");
	Ticket2.set_Desctiption("Un ticket2 pour le musée du vieux monde que vous avez acheté.");
	Ticket2.set_Identification_ID(5);
	Ticket2.set_Is_Visible(true);
	Ticket2.set_is_Possesd(true);

	Item declencheur_Park;

	declencheur_Park.set_Identification_ID(4);
	declencheur_Park.set_Is_Visible(false);
	declencheur_Park.set_is_Possesd(true);


	Item Tableau_Item[5]
	{
		Portefeuille,
		declencheur_Park,
		Ticket,
		Ticket2,
		Telephone,
	};


	//cout << "test" << endl;


	//AfficcherEvent(Fou_Du_Metro);

	afficher_Menu_pricipal(Tableau_Item);


	return 0;
}




