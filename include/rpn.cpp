#include "rpn.h"
#include "pilhaDeque.h"

void operando(char *saida_polonesa, int *posicaoEscrita, char dado)
{
    saida_polonesa[*posicaoEscrita] = dado;
    std::cout << "Operando: "
              << saida_polonesa[*posicaoEscrita]
              << " posicao escrita: "
              << *posicaoEscrita
              << std::endl;
    *posicaoEscrita = *posicaoEscrita + 1;
}

void fechaParentese(PilhaDeque *operadores, char *saida_polonesa, int *posicaoEscrita)
{
    std::cout << "Fecha Parentese"
              << std::endl;
    while (operadores->buscaFim() not_eq '(')
    {
        desempilha(operadores, &saida_polonesa[0], posicaoEscrita);
    }
}

void limpa(PilhaDeque *operadores, char *saida_polonesa, int *posicaoEscrita)
{
    std::cout << "Limpa"
              << std::endl;
    while (operadores->tamanho() not_eq 0)
    {
        desempilha(operadores, &saida_polonesa[0], posicaoEscrita);
    }
    
    saida_polonesa[*posicaoEscrita] = '\0';
}
void desempilha(PilhaDeque *operadores, char *saida_polonesa, int *posicaoEscrita)
{
    char dado = operadores->removeFim();
    if (dado not_eq '(')
    {
        saida_polonesa[*posicaoEscrita] = dado;
        std::cout << "Desempilha: "
                  << saida_polonesa[*posicaoEscrita]
                  << " Tamanho: "
                  << operadores->tamanho()
                  << " posicao escrita: "
                  << *posicaoEscrita
                  << std::endl;
        *posicaoEscrita = *posicaoEscrita + 1;
    }
}

void empilha(PilhaDeque *operadores, char dado)
{
    operadores->insereFim(dado);
    std::cout << "Empilha: "
              << dado
              << " Tamanho: "
              << operadores->tamanho()
              << std::endl;
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

    std::cout << "Expressao: "
              << expressao
              << " = ABC*EF-/+ tamanho:"
              << sizeof(saida_polonesa)
              << std::endl;
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
            if (operadores->tamanho() == 0)
            {

                empilha(operadores, dado);
            }
            else
            {
                while (verificaPrecedencia(operadores->buscaFim()) >= 2)
                {
                    desempilha(operadores, &saida_polonesa[0], &posicaoEscrita);
                }
                empilha(operadores, dado);
            }
        }
        if ((dado == '*') or (dado == '/'))
        {
            if (operadores->tamanho() == 0)
            {
                empilha(operadores, dado);
            }
            else
            {
                while (verificaPrecedencia(operadores->buscaFim()) >= 3)
                {
                    desempilha(operadores, &saida_polonesa[0], &posicaoEscrita);
                }
                empilha(operadores, dado);
            }
        }
    }
    limpa(operadores, &saida_polonesa[0], &posicaoEscrita);
    delete operadores;
    std::cout << "Polonesa: "
              << saida_polonesa
              << std::endl;
}