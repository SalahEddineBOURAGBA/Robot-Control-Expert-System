#include "Article.h"

using namespace std;


//Constructeur surchargé
Article::Article(string articleName,string articleSize)
{
    _articleName = articleName;
    _articleSize = articleSize;
    _articleInBag = false;
}

bool Article::getArticleInBag()
{
    return _articleInBag;
}

//return the name of the Article
string Article::getArticleName()
{
    return _articleName;
}

//return the sier of the Article
string Article::getArticleSize()
{
    return _articleSize;
}

void Article::setArticleInBag(bool state)
{
    _articleInBag = state;
}
