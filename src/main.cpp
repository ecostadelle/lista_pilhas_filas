#include <iostream>
#include "../include/pilha2F.hpp"
#include "../include/fila2P.hpp"
#include "../include/rpn.hpp"
#include "../include/inverteF2F.hpp"

int exercicio5()
{
    std::queue <char> f;
    f.push('a');
    f.push('b');
    f.push('c');
    f.push('d');
    f.push('e');
    f.push('f');
    inverteF2F(&f);
    while (!f.empty())
    {
        std::cout << "Removendo: "
                  << f.front()
                  << std::endl;
        f.pop();
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
    exercicio5();
    //exercicio7();
    //int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    return 0;
}
