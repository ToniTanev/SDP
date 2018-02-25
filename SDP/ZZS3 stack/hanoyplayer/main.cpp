#include <iostream>
#include <stack>

#include "hanoyplayer.h"

void test1()
{
    std::stack<int> source, dest, temp;
    int k;
    for(int i = 10; i > 0; i++)
    {
      source.push(i);
    }
    HanoyPlayer player(&source, &dest, &temp, k);

    while(!player.finished())
    {
      player.makeMove();
    }
  /* while(player.s.top().dest->empty())
    {
      std::cout << player.s.top().dest->top() << std::cout;
      player.s.top().dest->pop();
    }*/

}

int main()
{
    test1();

    return 0;
}
