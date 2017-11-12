#include "rulesBigArticles.h"

using namespace std;

RulesBigArticles::RulesBigArticles(string name, int priority) : _ruleName(name) ,_priority(priority) ,_state(false) ,_used(false)
{

}

unsigned int RulesBigArticles::getPriority() const
{
    return _priority;
}

string RulesBigArticles::getRuleName() const
{
    return _ruleName;
}

bool RulesBigArticles::getState() const
{
    return _state;
}

bool RulesBigArticles::getUsed() const
{
    return _used;
}

void RulesBigArticles::setPriority(int priority)
{
    _priority = priority;
}

void RulesBigArticles::setState(bool state)
{
    _state = state;
}

void RulesBigArticles::setUsed(bool used)
{
    _used = used;
}

