#ifndef FUNCTIONS
#define FUNCTIONS

#include "Article.h"
#include "specialPackage.h"
#include "Bag.h"
#include <iostream>
#include <vector>
#include <windows.h>
#include <stdio.h>

std::vector<Article*> suggest(std::vector<Article*> article);
std::vector<Bag*> bigArticles(std::vector<Article*> article,std::vector<Bag*> bag);

#endif  //FUNCTIONS
