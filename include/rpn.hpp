#include <iostream>
#include <stack>

#include "dequeEncadeado.h"
//#include "pilhaDeque.hpp"


void polonesa(char *expressao, int N, char *saida_polonesa)
// 'expressao' eh um string terminado em '\0',
// com tamanho N (sem contar o '\0')
// 'saida_polonesa' eh um string com capacidade máxima N
{
    // escreva o resultado no string 'saida_polonesa'

    // pilha para armazenar os operadores
    // (DequeSeq ou DeqEnc, ambos funcionam). 
    // Porém, restringiu-se a executar operações 
    // apenas em uma extremidade.
    Deque<char> operadores;
    operadores.cria();
    // posicao para escrever no vetor de saida
    int posicao = 0;

    // alterar para 'range based for'
    for (int i = 0; i < N; i++)
    {
        auto dado = expressao[i];
        // condicional para detectar se é uma letra maiúscula
        if ((dado >= 'A') and (dado <= 'Z'))
        {
            std::cout << "Add :"
                 << dado
                 << std::endl;

            saida_polonesa[posicao++] = dado;
        }
        // caso o operador seja um parentese fechando, é recuperado o último operador aritmético da pilha
        else if (dado == ')')
        {
            while (operadores.buscaFim() not_eq '(') 
            {
                auto buffer = operadores.removeFim();
                saida_polonesa[posicao++] = buffer;
                std::cout << "Desempilha :"
                     << buffer
                     << " Tamanho: "
                     << operadores.tamanho()
                     << std::endl;
            }
            // ao sair do laço remove o '('
            auto buffer = operadores.removeFim();
            std::cout << "Remove :"
                     << buffer
                     << " Tamanho: "
                     << operadores.tamanho()
                     << std::endl;
        }
        else if (dado == 0)
        {
            while (operadores.tamanho() not_eq 0)
            {
                auto buffer = operadores.removeFim();
                saida_polonesa[posicao++] = buffer;
                std::cout << "Limpa :"
                     << buffer
                     << " Tamanho: "
                     << operadores.tamanho()
                     << std::endl;
            }
            
        }
        // caso o operador seja aritmético, é empilhado
        else
        {
            operadores.insereFim(dado);
            std::cout << "Empilha :"
                 << dado
                 << " Tamanho: "
                 << operadores.tamanho()
                 << std::endl;
        }
    }
    operadores.libera();
}