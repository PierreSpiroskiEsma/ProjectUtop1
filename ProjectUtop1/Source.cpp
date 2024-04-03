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
//**********************************************
//variables menu principal
//**********************************************
int ChoixJoueurMenuPrinc;


//**********************************************
//variables menu Inventaire
//**********************************************
int ChoixJoueurMenuInv;
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

void afficher_Menu_Inventory(Item target1[]) {

	int MenuInvChoice = 0;
	int ItemPerLine = 0;

	system("cls");
	cout << "****************************************" << endl;
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		if (target1[i].get_is_Possesd())
		{
			if (target1[i].get_Is_Visible())
			{
				MenuInvChoice++;
				if (ItemPerLine == 3)
				{
					ItemPerLine = 1;
					
					cout << endl;
					cout << MenuInvChoice << "." << target1[i].get_Name()<<"  ";


				}
				else
				{
					ItemPerLine++;
					cout << MenuInvChoice << "." << target1[i].get_Name() << "      ";

				}

			}



		}

		
	};
	cout << endl << endl;
	cout << MenuInvChoice + 1 << ".Annuler";
	cout << endl << endl;
	cout << "*****************************************" << endl << endl;
	cin >> ChoixJoueurMenuInv;;//garder en mémoire quel objet est séléctionné
	cout << endl;
	cout << "****************************************" << endl;
	cout << "1.Regarder" << "        " << "2.utiliser" << endl << "3.Annuler" << endl << endl;
	cout << "****************************************" << endl;
	do
	{
		cin >> ChoixJoueurMenuInvAction;

		switch (ChoixJoueurMenuInvAction)
		{
		case 1:

			cout << "je regarde" << endl;
			break;
		case 2:

			cout << "J'utilise" << endl;
			break;
		case 3:
			cout << "j'annule" << endl;
			break;
		default:
			cout << "choix invalide"<<endl;
			
			break;
		}

	} while (ChoixJoueurMenuInvAction != 1 && ChoixJoueurMenuInvAction != 2 && ChoixJoueurMenuInvAction != 3);

	cout << endl;
	cout << "****************************************" << endl;
	cout << "1.Valider" << "         " << "2.Annuler" << endl << endl;
	cout << "****************************************" << endl;
	do
	{
		cin >> ChoixJoueurMenuInvValidation;
		switch (ChoixJoueurMenuInvValidation)
		{
		case 1:
			
			cout << "je valide" << endl;
			break;
		case 2:
			
			cout << "j'annule" << endl;
			break;
		default:
			cout << "choix invalide"<<endl;

			break;
		}

	} while (ChoixJoueurMenuInvValidation != 1 && ChoixJoueurMenuInvValidation != 2);


}



// **************************************************************
// Menu Localisation
//***************************************************************

void afficher_Menu_Localisation(Location target2[]) {
	int MenuLocChoice = 0;
	int LocPerLine = 0;
	/****************************************

		1.ville		2.musée		3.park
		4.metro		5.termosta	6.annuler

	/*****************************************/

	system("cls");
	cout << "****************************************" << endl;
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		if (target2[i].get_is_unlock())
		{
			MenuLocChoice++;
			if (LocPerLine == 3)
			{
				LocPerLine = 1;

				cout << endl;
				cout << MenuLocChoice << "." << target2[i].get_Name() << "  ";


			}
			else
			{
				LocPerLine++;
				cout << MenuLocChoice << "." << target2[i].get_Name() << "      ";

			}


		}


	};
	cout << endl << endl;
	cout << MenuLocChoice + 1 << ".Annuler";
	cout << endl << endl;
	cout << "*****************************************" << endl << endl;
	cin >> ChoixJoueurMenuLoc;
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

			cout << "je valide" << endl;
			break;
		case 2:

			cout << "j'annule" << endl;
			break;
		default:
			cout << "choix invalide"<<endl;

			break;
		}

	} while (ChoixJoueurMenuLocValidation != 1 && ChoixJoueurMenuLocValidation != 2);



}


// **************************************************************
// Menu principal
//***************************************************************
void afficher_Menu_pricipal(Item UseMenu[], Location GoMenu[]) {

	system("cls");
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
			afficher_Menu_Localisation(GoMenu);
		
			 break;
		case 2:
			//afficher_Menu_Event()
			  cout << "je vais dans Event" << endl;
			  break;
		case 3:
			afficher_Menu_Inventory(UseMenu);
			
			  break;
		default:
			cout << "choix invalide"<<endl;
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
// set up des Event du jeu 
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

	// ******************************************************************************
	// set up des Lieux du jeu 
	//*******************************************************************************

	Location Maison;

	Maison.set_Name("Maison");
	Maison.set_Identification_ID(9);
	Maison.set_is_unlock(true);



	Location Centre_Ville;

	Centre_Ville.set_Name("Centre_Ville");
	Centre_Ville.set_Identification_ID(6);
	Centre_Ville.set_is_unlock(true);



	Location Musee;

	Musee.set_Name("Musee");
	Musee.set_Identification_ID(7);
	Musee.set_is_unlock(true);



	Location Salle_de_la_Bombe;

	Salle_de_la_Bombe.set_Name("Salle_de_la_Bombe");
	Salle_de_la_Bombe.set_Identification_ID(8);
	Salle_de_la_Bombe.set_is_unlock(false);

	Location Park;

	Park.set_Name("Park");
	Park.set_Identification_ID(9);
	Park.set_is_unlock(true);







	Location Tableau_Lieux[5]
	{
		Maison,
		Centre_Ville,
		Musee,
		Salle_de_la_Bombe,
		Park,

	};

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

	afficher_Menu_pricipal(Tableau_Item, Tableau_Lieux);


	return 0;
}




