#ifndef SPECIALPACKAGE
#define SPECIALPACKAGE

#include <string>

class SpecialPackage
{
public:
    SpecialPackage();  //default constructor
    std::string getNameArticle();
    void setNbrArticles(int nbrArticles);
    void setNameArticle(std::string name);
    bool getFull() const;
    void setFull(bool state);

private:
    bool _full;
    std::string _nameArticle;
};

#endif  //SPECIALPACKAGE


