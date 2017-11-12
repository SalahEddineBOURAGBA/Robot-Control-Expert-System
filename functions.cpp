#include "functions.h"
#include "rulesSuggest.h"
#include "rulesBigArticles.h"

using namespace std;

vector<Article*> suggest(vector<Article*> article)//,string actual_state)
{
    unsigned int i,j,minPriority(1000);
    bool conditionWhile(true);
    string electedRule,reasonningTrace;

    //Init Rules
    vector<RulesSuggest *> rule;
    rule.push_back(new RulesSuggest("suggestMilk",20));
    rule.push_back(new RulesSuggest("suggestBiscuit",30));
    rule.push_back(new RulesSuggest("moveToBigArticles",100));

    //test for while to stop
    for(i=0;i<rule.size();i++)
        if(rule[i]->getState() == true)
            conditionWhile=conditionWhile & rule[i]->getUsed();

    //primary program
    do
    {
        system("CLS");
        //Welcome Message
        cout <<"**********************************************" <<endl;
        cout <<"Welcome to the \"Suggest\" mini expert system:" <<endl;
        cout <<"**********************************************" <<endl;
        //Reinitialise the rules state
        for(i=0;i<rule.size();i++)
        {
            rule[i]->setState(false);
            rule[i]->setUsed(false);
        }

        //show articles
        cout <<endl;
        cout <<"The articles currently available : " <<endl;
        cout <<"-----------------------------------" <<endl;
        for(i=0;i<article.size();i++)
            cout <<article[i]->getArticleName() <<"   (" <<article[i]->getArticleSize() <<")." <<endl;

        //find applicable rules
        for(i=0;i<article.size();i++)
        {
            //rule suggestMilk
            if((rule[0]->getUsed()==false) && (article[i]->getArticleName()=="coffee"))
            {
                bool test=true;
                for(j=0;j<article.size();j++)
                    if(article[j]->getArticleName()=="milk")
                        test=false;
                if(test)
                    rule[0]->setState(true);
            }
            //rule suggestBiscuit
            if((rule[1]->getUsed()==false) && (article[i]->getArticleName()=="milk"))
            {
                bool test=true;
                for(j=0;j<article.size();j++)
                    if(article[j]->getArticleName()=="biscuit")
                        test=false;
                if(test)
                    rule[1]->setState(true);
            }
        }
        //rule moveToBigArticles
        rule[2]->setState(true);

        //show applicable rules
        cout <<endl;
        cout <<"Applicable rules are :" <<endl;
        cout <<"----------------------" <<endl;
        for(i=0;i<rule.size();i++)
            if(rule[i]->getState() == true)
                cout <<"rule : "<<rule[i]->getRuleName() <<endl;

        //initialise the priority
        minPriority=1000;
        //choose the elected rule
        for(i=0;i<rule.size();i++)
            if((rule[i]->getState()==true) && (rule[i]->getPriority()<minPriority))
            {
                minPriority=rule[i]->getPriority();
                electedRule=rule[i]->getRuleName();
            }

        //show elected rule
        cout <<"Elected rule : " <<electedRule <<endl <<endl;

        //add the elected rule to the reasonning trace
        reasonningTrace = reasonningTrace + electedRule + "\n" ;
        cout <<"Reasonning trace : " <<endl;
        cout <<"-------------------" <<endl <<reasonningTrace <<endl;

        //Apply the elected rule
        if(rule[0]->getRuleName()==electedRule)
        {
            cout <<"You have bought coffee but forgot to buy milk,do you want to buy it?" <<endl;
            article.push_back(new Article("milk","MEDIUM"));
            rule[0]->setUsed(true);
        }
        if(rule[1]->getRuleName()==electedRule)
        {
            cout <<"You have bought milk but forgot to buy biscuit,do you want to buy it?" <<endl;
            article.push_back(new Article("biscuit","MEDIUM"));
            rule[1]->setUsed(true);
        }
        if(rule[2]->getRuleName()==electedRule)
        {
            cout <<"You will now move to the \"Big Articles\" sub expert system." <<endl;
            rule[2]->setUsed(true);
        }

        cout <<endl;
        getchar();

        //initialise the condition
        conditionWhile=true;
        //test for while to stop
        for(i=0;i<rule.size();i++)
            if(rule[i]->getState() == true)
                conditionWhile=conditionWhile & rule[i]->getUsed();
    }
    while(conditionWhile == false);

    return article;
}

vector<Bag*> bigArticles(vector<Article*> article,vector<Bag*> bag)
{
    unsigned int i,j,minPriority(1000);
    bool conditionWhile(true);
    string electedRule,reasonningTrace;

    //Init Rules
    vector<RulesBigArticles *> rule;
    rule.push_back(new RulesBigArticles("moveBigArticleToBag",20));
    rule.push_back(new RulesBigArticles("changeBag",40));
    rule.push_back(new RulesBigArticles("moveToMediumArticles",80));
    rule.push_back(new RulesBigArticles("moveFish",15));

    vector<SpecialPackage *> specialPackage;
    //test for while to stop
    for(i=0;i<rule.size();i++)
        if(rule[i]->getState() == true)
            conditionWhile=conditionWhile & rule[i]->getUsed();

    //primary program
    do
    {
        system("CLS");
         //Welcome Message
        cout <<"**********************************************" <<endl;
        cout <<"Welcome to the \"Big Articles\" mini expert system:" <<endl;
        cout <<"**********************************************" <<endl;
        //show articles and bags
        cout <<endl;
        cout <<"The articles currently available : " <<endl;
        cout <<"-----------------------------------" <<endl;
        for(i=0;i<article.size();i++)
            cout <<article[i]->getArticleName() <<"   (" <<article[i]->getArticleSize() <<")." <<endl;
        cout <<endl;

        for(i=0;i<bag.size();i++)
        {
            cout <<"Bag N " <<i <<" contient " <<bag[i]->getNbrArticles() <<" articles" <<endl;
            if(bag[i]->getNbrArticles() > 0)
                cout <<"\tArticle 1: " <<bag[i]->getNameArticle1() <<endl;
            if(bag[i]->getNbrArticles() == 2)
                cout <<"\tArticle 2: " <<bag[i]->getNameArticle2() <<endl;
        }
        for(i=0;i<specialPackage.size();i++)
            cout <<"Special Package N " <<i <<" contient " <<specialPackage[i]->getNameArticle() <<endl;

        //Reinitialise the rules state and used
        for(i=0;i<rule.size();i++)
            {
                rule[i]->setState(false);
                rule[i]->setUsed(false);
            }

        //find applicable rules
        for(i=0;i<article.size();i++)
        {
            //rule moveBigArticleToBag
            if((article[i]->getArticleInBag() == false) && (article[i]->getArticleSize()=="BIG"))
            {
                bool test=false;
                for(j=0;j<bag.size();j++)
                    if(bag[j]->getNbrArticles() < 2)
                        test=true;
                if(test)
                    rule[0]->setState(true);
            }
            //rule moveFish
            if((article[i]->getArticleInBag() == false) && (article[i]->getArticleName()=="fish"))
            {
                rule[3]->setState(true);
            }
            //rule changeBag
            if((article[i]->getArticleInBag() == false) && (article[i]->getArticleSize()=="BIG"))
            {
                rule[1]->setState(true);
            }
        }
        //rule moveToBigArticles
        rule[2]->setState(true);

        //show applicable rules
        cout <<endl;
        cout <<"Aplicable rules are :" <<endl;
        cout <<"---------------------" <<endl;
        for(i=0;i<rule.size();i++)
            if(rule[i]->getState() == true)
                cout <<"rule : "<<rule[i]->getRuleName() <<endl;

        //initialise the priority
        minPriority=1000;
        //choose the elected rule
        for(i=0;i<rule.size();i++)
            if((rule[i]->getState()==true) && (rule[i]->getPriority()<minPriority))
            {
                minPriority=rule[i]->getPriority();
                electedRule=rule[i]->getRuleName();
            }

        //show elected rule
        cout<<"Elected rule : " <<electedRule <<endl;
        cout <<endl;

        //add the elected rule to the reasonning trace
        reasonningTrace = reasonningTrace + electedRule + "\n" ;
        cout <<"Reasonning trace : " <<endl;
        cout <<"-------------------" <<endl <<reasonningTrace <<endl;

        //Apply the elected rule
        if(rule[3]->getRuleName()==electedRule)
            for(i=0;i<article.size();i++)
                {
                    if((article[i]->getArticleName() == "fish") && (article[i]->getArticleInBag() == false))    //the article is Big and not in a bag
                    {
                        specialPackage.push_back(new SpecialPackage());
                        specialPackage[specialPackage.size()-1]->setNameArticle(article[i]->getArticleName());
                        specialPackage[specialPackage.size()-1]->setFull(true);
                        rule[3]->setUsed(true);
                        article[i]->setArticleInBag(true);
                    }
                }
        if(rule[0]->getRuleName()==electedRule)
        {
            for(i=0;i<article.size();i++)
            {
                if((article[i]->getArticleSize() == "BIG") && (article[i]->getArticleInBag() == false))    //the article is Big and not in a bag
                {
                    for(j=0;j<bag.size();j++)
                        if(bag[j]->getNbrArticles()<2)
                        {
                            if(bag[j]->getNbrArticles() == 0)
                                bag[j]->setNameArticle1(article[i]->getArticleName());
                            if(bag[j]->getNbrArticles() == 1)
                                bag[j]->setNameArticle2(article[i]->getArticleName());
                            bag[j]->setNbrArticles(bag[j]->getNbrArticles()+1);
                            article[i]->setArticleInBag(true);
                            cout <<"The article \'" <<article[i]->getArticleName() <<"\' will be moved to the bag N " <<j <<endl;
                            goto skip;
                        }
                }
            }
            skip:
            rule[0]->setUsed(true);
        }
        if(rule[1]->getRuleName()==electedRule)
        {
            bag.push_back(new Bag());
            cout <<"Bag N" <<(bag.size()-1) <<" has been created." <<endl;
            rule[1]->setUsed(true);
        }
        if(rule[2]->getRuleName()==electedRule)
        {
            cout <<"You will now move to the \"Medium Articles\" sub expert system." <<endl;
            rule[2]->setUsed(true);
        }
        cout <<endl;
        getchar();

        //initialise the condition
        conditionWhile=true;
        //test for while to stop
        for(i=0;i<rule.size();i++)
            if(rule[i]->getState() == true)
                conditionWhile=conditionWhile & rule[i]->getUsed();
    }
    while(conditionWhile == false);

    return bag;
}
