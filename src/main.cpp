#include <iostream>
#include <string>

#include "..\include\dequeEncadeado.h"
#include "..\include\rpn.hpp"

int main()
{
    char saida[17];
    polonesa((char *)"A+B*C/(E-F)-", 12, &saida[0]);
    std::cout << "A+B*C/(E-F) = ABC*EF-/+"
              << " executado "
              << saida
              << std::endl;
    return 0;
}
/*
template <typename Agregado, typename Tipo>
concept DequeTAD = requires(Agregado a, Tipo t) {
    // requer operação de consulta ao elemento 'inicio'
    {a.buscaInicio()};
    // requer operação de consulta ao elemento 'fim'
    {a.buscaFim()};
    // requer operação 'insereInicio' sobre tipo 't'
    {a.insereInicio(t)};
    // requer operação 'insereFim' sobre tipo 't'
    {a.insereFim(t)};
    // requer operação 'removeInicio' e retorna tipo 't'
    {a.removeInicio()};
    // requer operação 'removeFim' e retorna tipo 't'
    {a.removeFim()};
};

// testa se Deque está correto 
static_assert(DequeTAD<Deque<char>, char>); 

template <typename Agregado, typename Tipo>
concept PilhaTAD = requires(Agregado a, Tipo t) {
    // requer operação de consulta ao elemento 'fim'
    {a.buscaFim()};
    // requer operação 'insereFim' sobre tipo 't'
    {a.insereFim(t)};
    // requer operação 'removeFim' e retorna tipo 't'
    {a.removeFim()};
};

// testa se Pilha está correta
static_assert(PilhaTAD<PilhaDeque, char>); 

*/