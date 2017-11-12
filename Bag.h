#ifndef BAG
#define BAG

#include <string>

class Bag
{
public:
    Bag();  //default constructor
    int getNbrArticles();
    std::string getNameArticle1();
    std::string getNameArticle2();
    void setNbrArticles(int nbrArticles);
    void setNameArticle1(std::string name);
    void setNameArticle2(std::string name);

private:
    int _nbrArticles;
    std::string _nameArticle1;
    std::string _nameArticle2;
};

#endif  //BAG
