#include "rulesSuggest.h"

using namespace std;

RulesSuggest::RulesSuggest(string name, int priority) : _ruleName(name) ,_priority(priority) ,_state(false) ,_used(false)
{

}

unsigned int RulesSuggest::getPriority() const
{
    return _priority;
}

string RulesSuggest::getRuleName() const
{
    return _ruleName;
}

bool RulesSuggest::getState() const
{
    return _state;
}

bool RulesSuggest::getUsed() const
{
    return _used;
}

void RulesSuggest::setPriority(int priority)
{
    _priority = priority;
}

void RulesSuggest::setState(bool state)
{
    _state = state;
}

void RulesSuggest::setUsed(bool used)
{
    _used = used;
}
