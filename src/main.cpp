#include <iostream>
#include "../include/rpn.hpp"

int exercicio2(){
    return 0;
}

int exercicio7()
{
    char entrada[]="(A+B)*(C-F/D)";
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
    exercicio7();
}
