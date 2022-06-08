#include <iostream>
#include "../include/pilha2F.hpp"
#include "../include/fila2P.hpp"
#include "../include/rpn.hpp"
#include "../include/obterMinimo.hpp"

int exercicio6()
{
    PilhaMin f;
    f.empilha(6);
    f.empilha(4);
    f.empilha(5);
    f.empilha(3);
    f.empilha(1);
    f.empilha(2);
    while (f.vazio())
    {
        std::cout << "Minimo: "
                  << f.obterMinimo()
                  << " Removendo: "
                  << f.desempilha()
                  << std::endl;
    }
    return 0;
}
/*
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
*/
int main()
{
    exercicio6();
    // exercicio7();
    // int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    return 0;
}
