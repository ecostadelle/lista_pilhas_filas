#include <iostream>
#include "filaDeque.hpp"

FilaDeque::FilaDeque()
{
    std::cout << "Construtor chamado" << std::endl;
}

FilaDeque::~FilaDeque()
{
    d.~Deque();
    std::cout << "Destrutor chamado" << std::endl;
}

bool FilaDeque::empty()
{
    return (d.tamanho() == 0);
}

char FilaDeque::front()
{
    return d.buscaInicio();
}

void FilaDeque::push(char t)
{
    d.insereFim(t);
}

char FilaDeque::pop()
{
    return d.removeInicio();
}

template <typename Agregado, typename Tipo>
concept FilaTAD = requires(Agregado c, Tipo t)
{
    // requer operação de consulta ao elemento 'inicio'
    {c.front()};
    // requer operação 'insereFim' sobre tipo 't'
    {c.push(t)};
    // requer operação 'removeInicio' e retorna tipo 't'
    {c.pop()};
};
// testa se Fila está correta
static_assert(FilaTAD<FilaDeque, char>);