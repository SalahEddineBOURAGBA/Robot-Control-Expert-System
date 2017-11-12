#ifndef DEF_ARTICLE
#define DEF_ARTICLE

#include <string>

class Article
{
public:
    Article(std::string articleName,std::string articleSize);  //Surcharged Constructor
    bool getArticleInBag();     //return state of articles in bag
    std::string getArticleName();   //return the name of the article
    std::string getArticleSize();   //return the size of the article
    void setArticleInBag(bool state);   //set article in bag

private:
    bool _articleInBag;
    std::string _articleName;
    std::string _articleSize;
};

#endif  //ARTICLE
