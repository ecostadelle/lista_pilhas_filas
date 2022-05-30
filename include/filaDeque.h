#ifndef _FILA_DEQUE
#define _FILA_DEQUE

#include "dequeEncadeado.h"

class FilaDeque
{
public:
    Deque<char> d; 

    FilaDeque();
    ~FilaDeque();
    int tamanho();
    char front();
    void push(char t);
    char pop();
}; 

#include "FilaDeque.cpp"

#endif