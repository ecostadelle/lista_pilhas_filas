#include "fila2P.hpp"

Fila2P::Fila2P()
{
}

Fila2P::~Fila2P()
{
    while (!p1.empty())
    {
        p1.pop();
    }
    
}

void Fila2P::push(char c)
{
    p1.push(c);
}

char Fila2P::pop()
{
    while (!p1.empty())
    {
        p2.push(p1.top());
        p1.pop();
    }
    char c = p2.top();
    p2.pop();
    while (!p2.empty())
    {
        p1.push(p2.top());
        p2.pop();
    }
    return c;
}

char Fila2P::front()
{
    while (!p1.empty())
    {
        p2.push(p1.top());
        p1.pop();
    }
    char c = p2.top();
    while (!p1.empty())
    {
        p1.push(p2.top());
    }
    return c;
}

bool Fila2P::empty()
{
    return p1.empty() && p2.empty();
}