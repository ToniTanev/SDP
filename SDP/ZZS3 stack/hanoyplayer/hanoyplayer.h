#ifndef __HANOYPLAYER_H
#define __HANOYPLAYER_H

#include <stack>

struct Configuration
{
    std::stack<int>* source;
    std::stack<int>* dest;
    std::stack<int>* temp;
    int k;
};

class HanoyPlayer
{
public: //private:
    std::stack<Configuration> s;
public:
    HanoyPlayer();
    HanoyPlayer(std::stack<int>* _source, std::stack<int>* _dest, std::stack<int>* _temp, int _k);
    bool finished() const;
    void makeMove();
};

#endif // __HANOYPLAYER_H
