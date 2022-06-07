#ifndef _FILA_2P_HPP_
#define _FILA_2P_HPP_

#include <stack>

class Fila2P
{
public:
    std::stack<char> p1; // Pilha para 'char'
    std::stack<char> p2; // Pilha para 'char'
    Fila2P();
    ~Fila2P();
    void push(char c);
    char pop();
    char front();
    bool empty();
};

#include "fila2P.cpp"

#endif