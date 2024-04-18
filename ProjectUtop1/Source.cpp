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
//variables menu Event
//**********************************************

int ChoixJoueurMenuEvent;
int ChoixJoueurMenuEventAction;
int ChoixJoueurMenuEventValidation;

//**********************************************
//variables menu Localisation
//**********************************************

int ChoixJoueurMenuLocValidation;
int Choix_Joueur_Menu_Location;

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

bool afficher_Menu_Localisation(vector <Location> target, Location* curent_location) {
	int Menu_Location_Choice = 0;
	int Location_Per_Line = 0;
	vector <Location> Location_Menu_list;

	system("cls");
	cout << "****************************************" << endl;
	cout << endl;
	for (int i = 0; i < target.size(); i++)
	{
		if (curent_location->is_reacheable(target[i].get_Identification_ID()))
		{
			Menu_Location_Choice++;
			if (Location_Per_Line == 3)
			{
				Location_Per_Line = 1;

				cout << endl;
				cout << Menu_Location_Choice << "." << target[i].get_Name() << "  ";


			}
			else
			{
				Location_Per_Line++;
				cout << Menu_Location_Choice << "." << target[i].get_Name() << "      ";

			}

			Location_Menu_list.push_back(target[i]);
		}



	};
	cout << endl << endl;
	cout << Menu_Location_Choice + 1 << ".Annuler";
	cout << endl << endl;
	cout << "*****************************************" << endl << endl;
	do 
	{
		cin >> Choix_Joueur_Menu_Location;
		if (Choix_Joueur_Menu_Location < 1 || Choix_Joueur_Menu_Location > Location_Menu_list.size() + 2)
		{
			cout << "choix invalide" << endl;
		}
		else if (Choix_Joueur_Menu_Location == Location_Menu_list.size() + 1)
		{
			return false;

		}

	} while (Choix_Joueur_Menu_Location < 1 || Choix_Joueur_Menu_Location > Location_Menu_list.size() + 2);

	Location CurrentLocation = Location_Menu_list[Choix_Joueur_Menu_Location - 1];
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

			cout << "mouve to " << CurrentLocation.get_Name() << endl;
			*curent_location = CurrentLocation;
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



// ******************************************************************
// 
// Menu Event
// 
//******************************************************************

bool AfficherEvent(Location* CurrentLocation)
{
	//cout << 0 << "." << CurrentLocation.get_Event_List()[0].get_Name() << "      ";
	int MenuEventChoice = 0;
	int EventPerLine = 0;

	system("cls");
	cout << "****************************************" << endl;
	cout << endl;
	for (int i = 0; i < CurrentLocation->get_Event_List().size(); i++)
	{
		
		if (EventPerLine == 3)
		{
			EventPerLine = 1;

			cout << endl;
			cout << i+1 << "." << CurrentLocation->get_Event_List()[i]->get_Name() << "  ";


		}
		else
		{
			EventPerLine++;
			cout << i+1 << "." << CurrentLocation->get_Event_List()[i]->get_Name() << "      ";

		}
		

	}

	cout << endl << endl;
	cout << CurrentLocation->get_Event_List().size() + 1 << ".Annuler";
	cout << endl << endl;
	cout << "*****************************************" << endl << endl;
	
	do
	{
		cin >> ChoixJoueurMenuEvent;
		if (ChoixJoueurMenuEvent < 1 || ChoixJoueurMenuEvent > CurrentLocation->get_Event_List().size() + 2)
		{
			cout << "choix invalide" << endl;
		}
		else if (ChoixJoueurMenuEvent == CurrentLocation->get_Event_List().size() + 1)
		{
			return false;

		}

	} while (ChoixJoueurMenuEvent < 1 || ChoixJoueurMenuEvent > CurrentLocation->get_Event_List().size() + 2);
	
	Event CurrentEvent = *CurrentLocation->get_Event_List()[ChoixJoueurMenuEvent - 1];
	
	 CurrentEvent.DescriptionFromFile(CurrentEvent.get_image_location());
	
	
	if (CurrentEvent.get_Visited())
	{
	
		CurrentEvent.DescriptionFromFile(CurrentEvent.get_AllReadyTalk_location());
	
	
	}
	else
	{

		CurrentEvent.DescriptionFromFile(CurrentEvent.get_file_location());
		if (CurrentEvent.get_give_Item()) 
		{
			CurrentLocation->get_Event_List()[ChoixJoueurMenuEvent - 1]->get_item_Reward().set_is_Possesd(true);
			CurrentLocation->get_Event_List()[ChoixJoueurMenuEvent - 1]->set_Visited(true);
		}

	}

	CurrentEvent.next_screen();
	return false;

	

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

			return afficher_Menu_Localisation(GoMenu, _curent_location);

		case 2:
			return AfficherEvent(_curent_location);
			
		case 3:

			return afficher_Menu_Inventory(UseMenu);

		default:
			cout << "choix invalide" << endl;
			break;
		}

	} while (ChoixJoueurMenuPrinc != 1 && ChoixJoueurMenuPrinc != 2 && ChoixJoueurMenuPrinc != 3);


}


int main()
{

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
	Ticket.set_Desctiption("Un ticket pour le mus�e du vieux monde que vous avez achet�.");
	Ticket.set_Identification_ID(3);
	Ticket.set_Is_Visible(true);
	Ticket.set_is_Possesd(false);
	
	Item Ticket2;

	Ticket2.set_Name("Ticket2");
	Ticket2.set_Desctiption("Un ticket2 pour le mus�e du vieux monde que vous avez achet�.");
	Ticket2.set_Identification_ID(5);
	Ticket2.set_Is_Visible(true);
	Ticket2.set_is_Possesd(true);

	Item declencheur_Park;

	declencheur_Park.set_Identification_ID(4);
	declencheur_Park.set_Is_Visible(false);
	declencheur_Park.set_is_Possesd(true);


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
	Fou_Du_Metro.set_item_reward(Ticket);


	// ******************************************************************************
	// set up des Lieux du jeu 
	//*******************************************************************************

	Location Maison;

	Maison.set_Name("Maison");
	Maison.set_Identification_ID(9);
	Maison.Add_Reacheable_Location(6);
	Maison.Add_Reacheable_Location(7);
	Maison.Add_Reacheable_Location(8);
	Maison.Add_Reacheable_Location(9);


	Location Centre_Ville;

	Centre_Ville.set_Name("Centre_Ville");
	Centre_Ville.set_Identification_ID(6);
	Centre_Ville.Add_Event(&Fou_Du_Metro);



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




