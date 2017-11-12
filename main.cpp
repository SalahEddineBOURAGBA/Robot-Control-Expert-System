#include "Article.h"
#include "functions.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    string actualState("SUGGEST");
    system("mode con LINES=40 COLS=80");
    //init articles
    vector<Article *> article;
    article.push_back(new Article("soda","BIG"));
    article.push_back(new Article("ball","BIG"));
    article.push_back(new Article("toy","BIG"));
    article.push_back(new Article("coffee","MEDIUM"));
    article.push_back(new Article("biscuit","SMALL"));
    article.push_back(new Article("fish","BIG"));
    //init bags
    vector<Bag *> bag;
    bag.push_back(new Bag());
    //Subsytem1:Suggest
    article=suggest(article);
    //subsystem2:BigArticles
    bag=bigArticles(article,bag);


    return 0;
}


