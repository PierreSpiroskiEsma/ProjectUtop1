#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include "Event.h"
#include "Interactible.h"
#include "Inventory.h"
#include "Item.h"
#include "Location.h"

using namespace std;

string rien;
//**********************************************
//variables menu principal
//**********************************************
int ChoixJoueurMenuPrinc;


//**********************************************
//variables menu Inventaire
//**********************************************

int Choix_Joueur_Menu_Inventory;
int ChoixJoueurMenuInvAction;
int ChoixJoueurMenuInvValidation;

//**********************************************
//variables menu Localisation
//**********************************************

int ChoixJoueurMenuLocValidation;
int ChoixJoueurMenuLoc;

// **************************************************************
// Menu Inventaire
//***************************************************************

bool afficher_Menu_Inventory(vector <Item> target) {

	int MenuInvChoice = 0;
	int ItemPerLine = 0;
	vector <Item> Item_Menu_list;

	system("cls");
	cout << "****************************************" << endl;
	cout << endl;

	for (int i = 0; i < target.size(); i++)
	{
		if (target[i].get_is_Possesd())
		{
			if (target[i].get_Is_Visible())
			{
				MenuInvChoice++;
				if (ItemPerLine == 3)
				{
					ItemPerLine = 1;
					
					cout << endl;
					cout << MenuInvChoice << "." << target[i].get_Name()<<"  ";


				}
				else
				{
					ItemPerLine++;
					cout << MenuInvChoice << "." << target[i].get_Name() << "      ";

				}

				Item_Menu_list.push_back(target[i]);
			}
		}		
	};

	cout << endl << endl;
	cout << MenuInvChoice + 1 << ".Annuler";
	cout << endl << endl;
	cout << "*****************************************" << endl << endl;


	do
	{
		cin >> Choix_Joueur_Menu_Inventory;

		if (Choix_Joueur_Menu_Inventory < 1 || Choix_Joueur_Menu_Inventory > Item_Menu_list.size()+2) {

			cout << "choix invalide" << endl;

		} else if (Choix_Joueur_Menu_Inventory == Item_Menu_list.size() + 1) {

			return false;
		}

	} while (Choix_Joueur_Menu_Inventory < 1 || Choix_Joueur_Menu_Inventory > Item_Menu_list.size() + 2);

	Item Curently_Use_Item = Item_Menu_list[Choix_Joueur_Menu_Inventory - 1];
	cout << Curently_Use_Item.get_Name();

	cout << endl;
	cout << "****************************************" << endl;
	cout << "1.Regarder" << "        " << "2.utiliser" << endl << "3.Annuler" << endl << endl;
	cout << "****************************************" << endl;


	do {
		cin >> ChoixJoueurMenuInvAction;

		switch (ChoixJoueurMenuInvAction) {

			case 1:
				cout << "je regarde" << endl;
				Curently_Use_Item.Show_Description();
			break;

			case 2:
				cout << "J'utilise" << endl;
				Curently_Use_Item.Use_Item();
			break;

			case 3:
				cout << "j'annule" << endl;
				return false;
			break;

			default:
				cout << "choix invalide"<<endl;
			break;
		}

	} while (ChoixJoueurMenuInvAction < 1 || ChoixJoueurMenuInvAction > 3);

	return false;
}



// **************************************************************
// Menu Localisation
//***************************************************************

bool afficher_Menu_Localisation(vector <Location> target, Location* _curent_location, Location curent_location) {
	int MenuLocChoice = 0;
	int LocPerLine = 0;

	system("cls");
	cout << "****************************************" << endl;
	cout << endl;
	for (int i = 0; i < target.size(); i++)
	{
		if ( curent_location.is_reacheable(target[i].get_Identification_ID()))
		{
			MenuLocChoice++;
			if (LocPerLine == 3)
			{
				LocPerLine = 1;

				cout << endl;
				cout << MenuLocChoice << "." << target[i].get_Name() << "  ";


			}
			else
			{
				LocPerLine++;
				cout << MenuLocChoice << "." << target[i].get_Name() << "      ";

			}
		}



	};
	cout << endl << endl;
	cout << MenuLocChoice + 1 << ".Annuler";
	cout << endl << endl;
	cout << "*****************************************" << endl << endl;
	do 
	{
		cin >> ChoixJoueurMenuLoc;
		if (ChoixJoueurMenuLoc != 1 && ChoixJoueurMenuLoc != 2 && ChoixJoueurMenuLoc != 3 && ChoixJoueurMenuLoc != 4 && ChoixJoueurMenuLoc != 5) 
		{
			cout << "choix invalide" << endl;
		}

	} while (ChoixJoueurMenuLoc != 1 && ChoixJoueurMenuLoc != 2 && ChoixJoueurMenuLoc != 3 && ChoixJoueurMenuLoc != 4 && ChoixJoueurMenuLoc != 5);

	
	cout << endl;
	cout << "****************************************" << endl;
	cout << "1.Valider" << "         " << "2.Annuler" << endl << endl;
	cout << "****************************************" << endl;
	do
	{
		cin >> ChoixJoueurMenuLocValidation;
		switch (ChoixJoueurMenuLocValidation)
		{
		case 1:

			cout << "mouve to " << target[ChoixJoueurMenuLoc].get_Name() << endl;
			*_curent_location = target[ChoixJoueurMenuLoc];
			return false;

		case 2:

			cout << "j'annule" << endl;
			return false;

		default:
			cout << "choix invalide"<<endl;
			break;
		}

	} while (ChoixJoueurMenuLocValidation != 1 && ChoixJoueurMenuLocValidation != 2);



}


// **************************************************************
// Menu principal
//***************************************************************
bool afficher_Menu_pricipal(vector <Item> UseMenu, vector <Location> GoMenu, Location* _curent_location, Location curent_location) {

	system("cls");
	cout << curent_location.get_Name() << endl;
	cout << "****************************************" << endl;
	cout << endl;
	cout << "1.Aller	  2.faire	  3.Utiliser un objet" << endl;
	cout << endl;
	cout << "*****************************************" << endl << endl;
	cout << endl;

	do
	{
		cin >> ChoixJoueurMenuPrinc;

		switch (ChoixJoueurMenuPrinc)
		{
		case 1:

			return afficher_Menu_Localisation(GoMenu, _curent_location, curent_location);

		case 2:
			//afficher_Menu_Event()
			cout << "je vais dans Event" << endl;
			break;
		case 3:

			return afficher_Menu_Inventory(UseMenu);

		default:
			cout << "choix invalide" << endl;
			break;
		}

	} while (ChoixJoueurMenuPrinc != 1 && ChoixJoueurMenuPrinc != 2 && ChoixJoueurMenuPrinc != 3);


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
// ******************************************************************************
// set up des Event du jeu 
//*******************************************************************************

	Event Fou_Du_Metro;

	Fou_Du_Metro.set_Name("Fou du Metro");
	Fou_Du_Metro.set_give_Item(true);
	Fou_Du_Metro.set_file_location("Ressource_Text/txt_City_FouDuMetro_description.txt");
	Fou_Du_Metro.set_AllReadyTalk_location("Ressource_Text/txt_City_FouDuMetro_AllReadyTalk.txt");
	Fou_Du_Metro.set_image_location("Ressource_Images/img_Remi.txt");
	Fou_Du_Metro.set_Malveillance_Message("Mal : Quel homme inspirant ! vous perdez un point de malveillance !");
	Fou_Du_Metro.set_Malveillance_Damage(true);

// ******************************************************************************
// set up des objets du jeu 
//*******************************************************************************

	Item Portefeuille;

	Portefeuille.set_Name("Portefeuille");
	Portefeuille.set_Desctiption("C'est un vieux portefeuille en cuir noir");
	Portefeuille.set_file_location("Ressource_Text/txt_Portefeuille_Description.txt");
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

	// ******************************************************************************
	// set up des Lieux du jeu 
	//*******************************************************************************

	Location Maison;

	Maison.set_Name("Maison");
	Maison.set_Identification_ID(9);
	Maison.Add_Reacheable_Location(6);
	Maison.Add_Reacheable_Location(9);


	Location Centre_Ville;

	Centre_Ville.set_Name("Centre_Ville");
	Centre_Ville.set_Identification_ID(6);
	Centre_Ville.Add_Event(Fou_Du_Metro);



	Location Musee;

	Musee.set_Name("Musee");
	Musee.set_Identification_ID(7);



	Location Salle_de_la_Bombe;

	Salle_de_la_Bombe.set_Name("Salle_de_la_Bombe");
	Salle_de_la_Bombe.set_Identification_ID(8);


	Location Park;

	Park.set_Name("Park");
	Park.set_Identification_ID(9);


	// ******************************************************************************
	// Remplissage des tableau d'objet
	//*******************************************************************************

	vector <Location> Tableau_Lieux
	{
		Maison,
		Centre_Ville,
		Musee,
		Salle_de_la_Bombe,
		Park,

	};

	vector <Item> Tableau_Item
	{
		Portefeuille,
		declencheur_Park,
		Ticket,
		Ticket2,
		Telephone,
	};

	vector <Event> Tableau_Event
	{
		Fou_Du_Metro
	};


	// ******************************************************************************
	// Declaration des variable de jeux
	//*******************************************************************************

	Location curent_location = Maison;

	// ******************************************************************************
	// Deroulement du jeux
	//*******************************************************************************

	bool inifinito_le_menu = afficher_Menu_pricipal(Tableau_Item, Tableau_Lieux, &curent_location, curent_location);

	while (!inifinito_le_menu) {
		inifinito_le_menu = afficher_Menu_pricipal(Tableau_Item, Tableau_Lieux, &curent_location, curent_location);
	}


	return 0;
}




