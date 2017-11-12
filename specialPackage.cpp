#include "specialPackage.h"

using namespace std;

//default constructor
SpecialPackage::SpecialPackage() : _full(false)
{

}
string SpecialPackage::getNameArticle()
{
    return _nameArticle;
}

void SpecialPackage::setNameArticle(string name)
{
    _nameArticle = name;
}

bool SpecialPackage::getFull() const
{
    return _full;
}

void SpecialPackage::setFull(bool state)
{
    _full = state;
}

