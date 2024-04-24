#include <iostream>
#include <fstream>
#include <string>
#include <vector> 
#include "Event.h"
#include "Interactible.h"
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

bool afficher_Menu_Inventory(vector <Item*> target, Location* curent_location) {

	int MenuInvChoice = 0;
	int ItemPerLine = 0;
	vector <Item*> Item_Menu_list;

	system("cls");
	cout << "****************************************" << endl;
	cout << endl;

	for (int i = 0; i < target.size(); i++)
	{
		if (target[i]->get_is_Possesd())
		{
			if (target[i]->get_Is_Visible())
			{
				MenuInvChoice++;
				if (ItemPerLine == 3)
				{
					ItemPerLine = 1;
					
					cout << endl;
					cout << MenuInvChoice << "." << target[i]->get_Name()<<"  ";


				}
				else
				{
					ItemPerLine++;
					cout << MenuInvChoice << "." << target[i]->get_Name() << "      ";

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

	Item* Curently_Use_Item = Item_Menu_list[Choix_Joueur_Menu_Inventory - 1];
	cout << Curently_Use_Item->get_Name();

	cout << endl;
	cout << "****************************************" << endl;
	cout << "1.Regarder" << "        " << "2.utiliser" << endl << "3.Annuler" << endl << endl;
	cout << "****************************************" << endl;


	do {
		cin >> ChoixJoueurMenuInvAction;

		switch (ChoixJoueurMenuInvAction) {

			case 1:
				cout << "je regarde" << endl;
				Curently_Use_Item->Show_Description();
			break;

			case 2:
				cout << "J'utilise" << endl;
				
				if (Curently_Use_Item->get_Identification_ID() == 1) 
				{
					Curently_Use_Item->Use_Item(curent_location, target[target.size()-1]);
				}
				else 
				{
					Curently_Use_Item->Use_Item(curent_location);
				}
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
			CurrentLocation->get_Event_List()[ChoixJoueurMenuEvent - 1]->get_item_Reward()->set_is_Possesd(true);
			CurrentLocation->get_Event_List()[ChoixJoueurMenuEvent - 1]->set_Visited(true);
		}

	}

	CurrentEvent.next_screen();
	return false;
}




// **************************************************************
// Menu principal
//***************************************************************
bool afficher_Menu_pricipal(vector <Item*> UseMenu, vector <Location> GoMenu, Location* _curent_location, Location curent_location) {

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

			return afficher_Menu_Inventory(UseMenu, _curent_location);

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

	Item Codes_Nucléaires;

	Codes_Nucléaires.set_Name("Codes_Nucléaires");
	Codes_Nucléaires.set_Desctiption("C'est un vieux portefeuille en cuir noir");
	//Codes_Nucléaires.set_file_location("Ressource_Text/txt_Portefeuille_Description.txt");
	Codes_Nucléaires.set_Identification_ID(1);
	Codes_Nucléaires.set_is_Possesd(false);
	Codes_Nucléaires.set_Effect_id(7);
	Codes_Nucléaires.set_Place_Of_Use(8);

	Item Mouchoir_Sale;

	Mouchoir_Sale.set_Name("Mouchoir_Sale");
	Mouchoir_Sale.set_Desctiption("Un 3310 !!!!! une vrais relique d'un anciens monde !!");
	//Mouchoir_Sale.set_file_location("Ressource_Text/txt_Portefeuille_Description.txt");
	Mouchoir_Sale.set_Identification_ID(2);
	Mouchoir_Sale.set_is_Possesd(false);
	Mouchoir_Sale.set_Effect_id(3);
	Mouchoir_Sale.set_Place_Of_Use(11);
	
	Item Ticket_du_Musée;

	Ticket_du_Musée.set_Name("Ticket_du_Musée");
	Ticket_du_Musée.set_Desctiption("Un ticket pour le musée du vieux monde que vous avez acheté.");
	//Ticket_du_Musée.set_file_location("Ressource_Text/txt_Portefeuille_Description.txt");
	Ticket_du_Musée.set_Identification_ID(3);
	Ticket_du_Musée.set_is_Possesd(false);
	Ticket_du_Musée.set_Place_Of_Use(6);
	Ticket_du_Musée.set_Effect_id(2);
	Ticket_du_Musée.set_Place_Of_Use(6);// ?? pas sur//
	
	Item Morceau_de_Fromage;

	Morceau_de_Fromage.set_Name("Morceau_de_Fromage");
	Morceau_de_Fromage.set_Desctiption("Un ticket2 pour le musée du vieux monde que vous avez acheté.");
	//Morceau_de_Fromage.set_file_location("Ressource_Text/txt_Portefeuille_Description.txt");
	Morceau_de_Fromage.set_Identification_ID(4);
	Morceau_de_Fromage.set_is_Possesd(true);
	Morceau_de_Fromage.set_Effect_id(4);
	Morceau_de_Fromage.set_Place_Of_Use(10);

	Item Prospectus_de_la_Turbine;

	Prospectus_de_la_Turbine.set_Name("Prospectus_de_la_Turbine");
	Prospectus_de_la_Turbine.set_Identification_ID(5);
	//Prospectus_de_la_Turbine.set_file_location("Ressource_Text/txt_Portefeuille_Description.txt");
	Prospectus_de_la_Turbine.set_is_Possesd(false);
	Prospectus_de_la_Turbine.set_Effect_id(5);
	Prospectus_de_la_Turbine.set_Place_Of_Use(6); // ?? pas sur//

	Item Colère_Interieure;

	Colère_Interieure.set_Name("Colère_Interieure");
	Colère_Interieure.set_Identification_ID(6);
	//Colère_Interieure.set_file_location("Ressource_Text/txt_Portefeuille_Description.txt");
	Colère_Interieure.set_is_Possesd(false);
	Colère_Interieure.set_Effect_id(6);


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
	Fou_Du_Metro.set_item_reward(&Ticket_du_Musée);


	// ******************************************************************************
	// set up des Lieux du jeu 
	//*******************************************************************************

	Location Maison;

	Maison.set_Name("Maison");
	Maison.set_Identification_ID(15);
	Maison.Add_Reacheable_Location(6);



	Location Centre_Ville;

	Centre_Ville.set_Name("Centre_Ville");
	Centre_Ville.set_Identification_ID(6);
	Centre_Ville.Add_Event(&Fou_Du_Metro);
	Centre_Ville.Add_Reacheable_Location(11);
	Centre_Ville.Add_Reacheable_Location(9);
	Centre_Ville.Add_Reacheable_Location(15);
	Centre_Ville.Add_Reacheable_Location(16);



	Location Musee;

	Musee.set_Name("Musee");
	Musee.set_Identification_ID(7);
	Musee.Add_Reacheable_Location(6);	
	Musee.Add_Reacheable_Location(12);
	Musee.Add_Reacheable_Location(13);



	Location Exposition_de_Fromage;

	Exposition_de_Fromage.set_Name("Exposition_de_Fromage");
	Exposition_de_Fromage.set_Identification_ID(12);
	Exposition_de_Fromage.Add_Reacheable_Location(7);

	Location Exposition_de_la_Vielle_Guerre;

	Exposition_de_la_Vielle_Guerre.set_Name("Exposition_de_la_Vielle_Guerre");
	Exposition_de_la_Vielle_Guerre.set_Identification_ID(13);
	Exposition_de_la_Vielle_Guerre.Add_Reacheable_Location(7);



	Location Aire_de_jeu_de_Lancement;

	Aire_de_jeu_de_Lancement.set_Name("Aire_de_jeu_de_Lancement");
	Aire_de_jeu_de_Lancement.set_Identification_ID(8);
	Aire_de_jeu_de_Lancement.Add_Reacheable_Location(9);


	Location Park;

	Park.set_Name("Park");
	Park.set_Identification_ID(9);
	Park.Add_Reacheable_Location(6);
	Park.Add_Reacheable_Location(8);




	Location Le_Grand_Purificateur;

	Le_Grand_Purificateur.set_Name("Le_Grand_Purificateur");
	Le_Grand_Purificateur.set_Identification_ID(10);
	Le_Grand_Purificateur.Add_Reacheable_Location(6);



	Location Metro;

	Metro.set_Name("Metro");
	Metro.set_Identification_ID(11);
	Metro.Add_Reacheable_Location(6);
	Metro.Add_Reacheable_Location(14);


	Location Systeme_de_Ventilation_du_Metro;

	Systeme_de_Ventilation_du_Metro.set_Name("Systeme_de_Ventilation_du_Metro");
	Systeme_de_Ventilation_du_Metro.set_Identification_ID(14);
	Systeme_de_Ventilation_du_Metro.Add_Reacheable_Location(11);


	Location Antiquaire;

	Antiquaire.set_Name("Antiquaire");
	Antiquaire.set_Identification_ID(16);
	Antiquaire.Add_Reacheable_Location(6);



	// ******************************************************************************
	// Remplissage des tableau d'objet
	//*******************************************************************************

	vector <Location> Tableau_Lieux
	{
		Maison,
		Centre_Ville,
		Musee,
		Exposition_de_Fromage,
		Exposition_de_la_Vielle_Guerre,
		Aire_de_jeu_de_Lancement,
		Park,
		Le_Grand_Purificateur,
		Metro,
		Systeme_de_Ventilation_du_Metro,
		Antiquaire,

	};
	
	
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// La colère interieure doit obligatoirement être en dernière position !!!!!!!!!!!
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	vector <Item*> Tableau_Item
	{
		&Codes_Nucléaires,
		&Mouchoir_Sale,
		&Ticket_du_Musée,
		&Morceau_de_Fromage,
		&Prospectus_de_la_Turbine,

		&Colère_Interieure,
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




