#include "inverte2P.hpp"

void inverte2P(std::stack<char> *p)
{
    std::stack<char> p1; // primeira pilha auxiliar
    std::stack<char> p2; // segunda pilha auxiliar
    // mais espaço auxiliar constante

    while (!p->empty())
    {
        p1.push(p->top());
        p->pop();
    }
    while (!p1.empty())
    {
        p2.push(p1.top());
        p1.pop();
    }
    while (!p2.empty())
    {
        p->push(p2.top());
        p2.pop();
    }
}