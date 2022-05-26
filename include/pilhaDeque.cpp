#include "pilhaDeque.hpp"

PilhaDeque::PilhaDeque()
{
    d.cria();
}

PilhaDeque::~PilhaDeque()
{
    d.libera();
}

char PilhaDeque::buscaFim()
{
    return d.buscaFim();
}

void PilhaDeque::insereFim(char t)
{
    d.insereFim(t);
}

char PilhaDeque::removeFim()
{
    return d.removeFim();
}