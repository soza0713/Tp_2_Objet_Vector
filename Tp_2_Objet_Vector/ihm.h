#pragma once
#include "Gestion.h"
class Ihm
{

public:
	Ihm();
	~Ihm();

	Gestion* magasin;


	void AfficheLeMenu();
	void AjouteUnArticle();
	void ListeLesArticles();
	void ModifierUnArticle();
	void Supprimer();

};

