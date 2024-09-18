#include "Ihm.h"
#include <iostream>
#include "Article.h"
using namespace std;

Ihm::Ihm()
{
	magasin = new Gestion();
}

Ihm::~Ihm()
{
	delete magasin;
}

void Ihm::AfficheLeMenu()
{
	int choix = 0;
	do
	{
		cout << "---==========---" << endl;
		cout << "Articles :" << magasin->getNombreArticles() << endl;
		cout << "---==========---" << endl;
		cout << "---== Menu ==---" << endl;

		cout << "1: Affiche les articles" << endl;
		cout << "2: Ajoute un Article" << endl;
		cout << "3: Modifier " << endl;
		cout << "4: Supprimer" << endl;
		cout << " Quels est ton choix mon vieux :";
		cin >> choix;
		//
		switch (choix)
		{
		case 1:
			ListeLesArticles();
			break;
		case 2:
			AjouteUnArticle();
			break;
		case 3:
			ModifierUnArticle();
			break;
		case 4:
			Supprimer();
			break;
		default:
			break;
		}

	} while (choix != 0);
	cout << "---==========---" << endl;
	cout << "Appuyez sur Entree pour terminer" << endl;
	cin >> choix;
}

void Ihm::AjouteUnArticle()
{
	string nomArticle;
	double prixht;
	int qte;
	//
	cout << "---==========---" << endl;
	cout << "Nom    :";
	cin >> nomArticle;
	cout << "PrixHT :";
	cin >> prixht;
	cout << "Combien:";
	cin >> qte;
	//
	Article* nouveau = new Article(nomArticle);
	nouveau->prixHT = prixht;
	nouveau->stock = qte;
	magasin->AjouteArticle(nouveau);
}

void Ihm::ListeLesArticles()
{
	int max = magasin->getNombreArticles();
	for (int i = 0; i < max; i++)
	{
		Article* temp = magasin->LireUnArticle(i);
		cout << "---====" << i << "====---" << endl;
		cout << "Nom    :";
		cout << temp->getNom() << endl;
		cout << "PrixHT :";
		cout << temp->prixHT << endl;
		cout << "Stock  :";
		cout << temp->stock << endl;
		cout << "---==========---" << endl;

	}
}

void Ihm::ModifierUnArticle()
{
	if (magasin->getNombreArticles() == 0)
		return;
	cout << "---==========---" << endl;
	ListeLesArticles();
	cout << "---==========---" << endl;
	cout << "Quel article voulez vous modifier ? (0/" << magasin->getNombreArticles() - 1 << "):";
	int choix;
	cin >> choix;
	if ((choix >= 0) && (choix < magasin->getNombreArticles()))
	{
		Article* temp = magasin->LireUnArticle(choix);
		cout << "Nouveau PrixHT :";
		cin >> temp->prixHT;
		cout << "Nouveau Stock  :";
		cin >> temp->stock;
		cout << "---==========---" << endl;
	}
}
  
void Ihm::Supprimer()
{
	if (magasin->getNombreArticles() == 0)
		return;
	cout << "---==========---" << endl;
	ListeLesArticles();
	cout << "---==========---" << endl;
	cout << "Quel article voulez vous supprimer ? (0/" << magasin->getNombreArticles() - 1 << "):";
	int choix;
	cin >> choix;
	if ((choix >= 0) && (choix < magasin->getNombreArticles()))
	{
		magasin->SupprimerUnArticle(choix);
	}
}