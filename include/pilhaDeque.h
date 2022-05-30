#ifndef _PILHA_DEQUE
#define _PILHA_DEQUE

#include "dequeEncadeado.h"

class PilhaDeque
{
public:
    Deque<char> d; 

    PilhaDeque();
    ~PilhaDeque();
    bool empty();
    char top();
    void push(char t);
    char pop();
}; 

#include "pilhaDeque.cpp"

#endif