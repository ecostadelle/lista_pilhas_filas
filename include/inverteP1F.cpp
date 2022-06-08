#include <queue>
#include "inverteP1F.hpp"

void inverteP1F(std::stack<char> *p)
{
    std::queue<char> f;
    while (!p->empty())
    {
        f.push(p->top());
        p->pop();
    }
    while (!f.empty())
    {
        p->push(f.front());
        f.pop();
    }
}
    