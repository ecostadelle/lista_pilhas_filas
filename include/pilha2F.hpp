#ifndef _PILHA_2F_HPP_
#define _PILHA_2F_HPP_

#include <queue> // Fila genérica em C++

class Pilha2F {
public:
    std::queue<char> f1; // Fila para 'char'
    std::queue<char> f2; // Fila para 'char'
    // SOMENTE espaço auxiliar CONSTANTE aqui 
    // (nenhum vetor, lista, etc) 
    // implementar métodos do TAD Pilha
    Pilha2F();
    ~Pilha2F();
    bool empty();
    char top();
    void push(char t);
    char pop();
};

#include "pilha2F.cpp"

#endif