#ifndef RULESBIGARTICLES
#define RULESBIGARTICLES

#include <string>

class RulesBigArticles
{
public:
    RulesBigArticles(std::string ruleName, int priority);    //Surcharged Constructor
    unsigned int getPriority() const;
    bool getState() const;
    bool getUsed() const;
    std::string getRuleName() const;
    void setPriority(int priority);
    void setState(bool state);
    void setUsed(bool used);

private:
    std::string _ruleName;
    unsigned int _priority;
    bool _state;
    bool _used;
};

#endif  //RULESBIGARTICLES

