#ifndef _DEQUE_SEQUENCIAL
#define _DEQUE_SEQUENCIAL

/*
   Utilizei um tipo genérico <T> pelo fato de que código pode ser reaproveitado
   nos exercícios de operações com pilhas e filas, apenas limitando as operações
   de inserção, consulta e remoção. Com realação à complexidade, exceto o método
   libera(), que tem crescimento linear, ou seja, complexidade O(N), todos os
   demais métodos possuem tempo constante, isto é, complexidade O(1).
*/

template<typename T>
class NoDeque // declaração dos nós que comporão o deque
{
public:
    T dado;
    NoDeque<T> *prox; // No caso do deque é neceesário que cada nó
    NoDeque<T> *ante; // armazene tanto o endereço do nó anterior quanto
};                 // do posterior, para permitir que a consulta
                   // seja realizada em ambos os sentidos.

template <typename T>
class Deque // Classe do deque encadeado
{

private:             // as variáveis estão privadas e
                     // toda manipulação é por interface
                     // padrão.
    NoDeque<T> *inicio; // ponteiro de inicio do deque
    NoDeque<T> *fim;    // ponteiro de fim do deque
    int N;

public:
    void cria();
    void libera();
    void insereInicio(T v);
    void insereFim(T v);
    int tamanho();
    T buscaInicio();
    T buscaFim();
    T removeInicio();
    T removeFim();
};

#include "dequeEncadeado.cpp"

#endif