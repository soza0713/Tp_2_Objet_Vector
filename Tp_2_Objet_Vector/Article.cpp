#include "Article.h"
using namespace std;

Article::Article(string n)
{
	nom = n;
}

string Article::getNom()
{
	return nom;
}
