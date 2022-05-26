#ifndef _PILHA_DEQUE
#define _PILHA_DEQUE

#include "dequeEncadeado.h"

class PilhaDeque
{
public:
    // Deque para 'char' (veja exercício anterior) 
    Deque d; 
    // SOMENTE espaço auxiliar CONSTANTE aqui 
    // (nenhum vetor, lista, etc) 
    // implementar métodos do TAD Pilha 

    PilhaDeque();
    ~PilhaDeque();
    char buscaFim();
    void insereFim(char t);
    char removeFim();

}; 

#endif