#include <iostream>
#include "../include/pilha2F.hpp"
#include "../include/fila2P.hpp"
#include "../include/rpn.hpp"
#include "../include/inverte1F.hpp"

int exercicio3()
{
    Fila2P p;
    for (int i = 0x41; i < 0x4B; i++)
    {
        std::cout << "Inserindo: "
                  << (char)i
                  << std::endl;
        p.push(i);
    }
    //inverte1F(p);
    while (!p.empty())
    {
        std::cout << "Removendo: "
                  << p.pop()
                  << std::endl;
    }
    return 0;
}

int exercicio4()
{
    std::stack <char> p;
    p.push('a');
    p.push('b');
    p.push('c');
    p.push('d');
    p.push('e');
    p.push('f');
    //inverte1F(&p);
    while (!p.empty())
    {
        std::cout << "Removendo: "
                  << p.top()
                  << std::endl;
        p.pop();
    }
    return 0;
}
int exercicio7()
{
    char entrada[] = "(A+B)*(C-F/D)";
    int tamanho = sizeof(entrada);
    char saida[tamanho];
    polonesa(entrada, tamanho, &saida[0]);
    std::cout << entrada
              << " executado "
              << saida
              << std::endl;
    return 0;
}

int main()
{
    exercicio4();
    //exercicio7();
    //int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
}
