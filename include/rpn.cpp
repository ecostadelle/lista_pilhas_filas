#include "rpn.hpp"
#include "pilhaDeque.hpp"

void operando(char *saida_polonesa, int *posicaoEscrita, char dado)
{
    saida_polonesa[*posicaoEscrita] = dado;
    *posicaoEscrita = *posicaoEscrita + 1;
}

void fechaParentese(PilhaDeque *operadores, char *saida_polonesa, int *posicaoEscrita)
{
    while (operadores->top() not_eq '(')
    {
        desempilha(operadores, &saida_polonesa[0], posicaoEscrita);
    }
}

void limpa(PilhaDeque *operadores, char *saida_polonesa, int *posicaoEscrita)
{
    while (!operadores->empty())
    {
        desempilha(operadores, &saida_polonesa[0], posicaoEscrita);
    }
    
    saida_polonesa[*posicaoEscrita] = '\0';
}
void desempilha(PilhaDeque *operadores, char *saida_polonesa, int *posicaoEscrita)
{
    char dado = operadores->pop();
    if (dado not_eq '(')
    {
        saida_polonesa[*posicaoEscrita] = dado;
        *posicaoEscrita = *posicaoEscrita + 1;
    }
}

void empilha(PilhaDeque *operadores, char dado)
{
    operadores->push(dado);
}

int verificaPrecedencia(char dado)
{
    if ((dado == '+') or (dado == '-'))
    {
        return 2;
    }

    if ((dado == '*') or (dado == '/'))
    {
        return 3;
    }
    else
    {
        return 0;
    }
}

void polonesa(char *expressao, int N, char *saida_polonesa)
{
    PilhaDeque *operadores = new PilhaDeque;
    int posicaoEscrita = 0;
    int i = 0;
    while (expressao[i] not_eq '\0')
    {
        char dado = expressao[i++];
        if (dado == '(')
        {
            empilha(operadores, dado);
        }
        if (dado == ')')
        {
            fechaParentese(operadores, &saida_polonesa[0], &posicaoEscrita);
        }
        if ((dado >= 'A') and (dado <= 'Z'))
        {
            operando(&saida_polonesa[0], &posicaoEscrita, dado);
        }
        if ((dado == '+') or (dado == '-'))
        {
            if (operadores->empty())
            {

                empilha(operadores, dado);
            }
            else
            {
                while (verificaPrecedencia(operadores->top()) >= 2)
                {
                    desempilha(operadores, &saida_polonesa[0], &posicaoEscrita);
                }
                empilha(operadores, dado);
            }
        }
        if ((dado == '*') or (dado == '/'))
        {
            if (operadores->empty())
            {
                empilha(operadores, dado);
            }
            else
            {
                while (verificaPrecedencia(operadores->top()) >= 3)
                {
                    desempilha(operadores, &saida_polonesa[0], &posicaoEscrita);
                }
                empilha(operadores, dado);
            }
        }
    }
    limpa(operadores, &saida_polonesa[0], &posicaoEscrita);
    delete operadores;
}