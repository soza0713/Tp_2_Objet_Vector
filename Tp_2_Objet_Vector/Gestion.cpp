#include "Gestion.h"

Gestion::Gestion()
{
	lesArticles = new vector<Article*>();
}

Gestion::~Gestion()
{
	while (getNombreArticles() > 0)
	{
		SupprimerUnArticle(0);
	}
	delete lesArticles;
}

void Gestion::AjouteArticle(Article* art)
{
	lesArticles->push_back(art);
}

Article* Gestion::LireUnArticle(int index)
{
	if ((index >= 0) && (index < getNombreArticles()))
	{
		return lesArticles->at(index);
	}
	return nullptr;
}

void Gestion::SupprimerUnArticle(int index)
{
	if ((index >= 0) && (index < getNombreArticles()))
	{
		Article* temp = LireUnArticle(index);
		delete temp;
		lesArticles->erase(lesArticles->begin() + index);
	}
}

int Gestion::getNombreArticles()
{
	return lesArticles->size();
}
