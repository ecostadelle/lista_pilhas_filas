#include <iostream>
#include "exercicios.hpp"

using namespace std;

int main()
{
    dequeSequencial deque;
    deque.insereInicio(5);
    deque.insereFim(7);
    deque.insereFim(9);
    cout << "ewerton1\n";
    cout << deque.buscaFim() << endl;
    cout << deque.buscaInicio() << endl;
    return 0;
}
