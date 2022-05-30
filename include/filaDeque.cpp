#include <iostream>
#include "FilaDeque.h"

FilaDeque::FilaDeque()
{
    std::cout << "Construtor chamado" << std::endl;
}

FilaDeque::~FilaDeque()
{
    d.~Deque();
    std::cout << "Destrutor chamado" << std::endl;
}

int FilaDeque::tamanho()
{
    return d.tamanho();
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