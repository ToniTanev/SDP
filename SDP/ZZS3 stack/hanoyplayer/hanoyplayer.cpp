#include "hanoyplayer.h"

HanoyPlayer::HanoyPlayer() {}

HanoyPlayer::HanoyPlayer(std::stack<int>* _source, std::stack<int>* _dest, std::stack<int>* _temp, int _k)
{
    Configuration c;
    c.source = _source;
    c.dest = _dest;
    c.temp = _temp;
    c.k = _k;
    s.push(c);
}

bool HanoyPlayer::finished() const
{
    Configuration c = s.top();
    return c.source->empty();
}

void HanoyPlayer::makeMove()
{

    Configuration conf = s.top();
    if(conf.k == 1)
    {
      conf.dest->push(conf.source->top());
      conf.source->pop();
      return;
    }


    Configuration temp;

    temp.source = conf.source;
    temp.dest = conf.temp;
    temp.temp = conf.dest;
    temp.k = conf.k - 1;
    s.push(temp);

    temp.source = conf.source;
    temp.dest = conf.dest;
    temp.temp = conf.temp;
    temp.k = 1;
    s.push(temp);

    temp.source = conf.temp;
    temp.dest = conf.dest;
    temp.temp = conf.source;
    temp.k = conf.k - 1;
    s.push(temp);


}
