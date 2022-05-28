#ifndef _PILHA_DEQUE
#define _PILHA_DEQUE

#include "dequeEncadeado.h"

class PilhaDeque
{
public:
    Deque<char> d; 

    PilhaDeque();
    ~PilhaDeque();
    int tamanho();
    char buscaFim();
    void insereFim(char t);
    char removeFim();
}; 

#include "pilhaDeque.cpp"

#endif