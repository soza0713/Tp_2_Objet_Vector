#pragma once
#include "Article.h"
#include <vector>


class Gestion
{
	vector<Article*> *lesArticles;


public:
	Gestion();
	~Gestion();
	
	int getNombreArticles();
	
	void AjouteArticle(Article* art);
	Article* LireUnArticle(int index);
	
	void SupprimerUnArticle(int index);


};

