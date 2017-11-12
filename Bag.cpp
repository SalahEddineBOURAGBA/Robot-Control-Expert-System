#include "Bag.h"

using namespace std;

//default constructor
Bag::Bag() : _nbrArticles(0)
{

}

int Bag::getNbrArticles()
{
    return _nbrArticles;
}

string Bag::getNameArticle1()
{
    return _nameArticle1;
}

string Bag::getNameArticle2()
{
    return _nameArticle2;
}

void Bag::setNbrArticles(int nbrArticles)
{
    _nbrArticles = nbrArticles;
}

void Bag::setNameArticle1(string name)
{
    _nameArticle1 = name;
}

void Bag::setNameArticle2(string name)
{
    _nameArticle2 = name;
}

