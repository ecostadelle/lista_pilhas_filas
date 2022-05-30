#ifndef _FILA_DEQUE
#define _FILA_DEQUE

#include "dequeEncadeado.h"

class FilaDeque
{
public:
    Deque<char> d; 

    FilaDeque();
    ~FilaDeque();
    bool empty();
    char front();
    void push(char t);
    char pop();
}; 

#include "FilaDeque.cpp"

#endif