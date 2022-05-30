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