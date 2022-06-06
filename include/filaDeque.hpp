#ifndef _FILA_DEQUE_HPP_
#define _FILA_DEQUE_HPP_

#include "dequeEncadeado.hpp"

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