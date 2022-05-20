#include <iostream>
#include <stack>

using namespace std;

void polonesa(char *expressao, int N, char *saida_polonesa)
// 'expressao' eh um string terminado em '\0',
// com tamanho N (sem contar o '\0')
// 'saida_polonesa' eh um string com capacidade máxima N
{
    // escreva o resultado no string 'saida_polonesa'

    // pilha para armazenar os operadores
    // foi utilizado o deque sequencial porém 
    // restringiu-se a executar operações 
    // apenas em uma extremidade.
    DequeTAD<char> operadores;
    // posicao para escrever no vetor de saida
    int posicao = 0;

    // alterar para 'range based for'
    for (int i = 0; i < N; i++)
    {
        auto dado = expressao[i];
        // condicional para detectar se é uma letra maiúscula
        if ((dado >= 'A') and (dado <= 'Z'))
        {
            cout << "Add :"
                 << dado
                 << endl;

            saida_polonesa[posicao++] = dado;
        }
        // caso o operador seja um parentese fechando, é recuperado o último operador aritmético da pilha
        else if (dado == ')')
        {
            while (operadores.buscaFim() not_eq '(') 
            {
                auto buffer = operadores.removeFim();
                saida_polonesa[posicao++] = buffer;
                cout << "Desempilha :"
                     << buffer
                     << " Tamanho: "
                     << operadores.tamanho
                     << endl;
            }
            // ao sair do laço remove o '('
            auto buffer = operadores.removeFim();
            cout << "Remove :"
                     << buffer
                     << " Tamanho: "
                     << operadores.tamanho
                     << endl;
        }
        else if (dado == 0)
        {
            while (operadores.tamanho not_eq 0)
            {
                auto buffer = operadores.removeFim();
                saida_polonesa[posicao++] = buffer;
                cout << "Limpa :"
                     << buffer
                     << " Tamanho: "
                     << operadores.tamanho
                     << endl;
            }
            
        }
        // caso o operador seja aritmético, é empilhado
        else
        {
            operadores.insereFim(dado);
            cout << "Empilha :"
                 << dado
                 << " Tamanho: "
                 << operadores.tamanho
                 << endl;
        }
    }
    // saida_polonesa[++posicao] = 0;
}