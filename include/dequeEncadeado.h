#ifndef _DEQUE_SEQUENCIAL
#define _DEQUE_SEQUENCIAL

/*
   Utilizei um tipo genérico <TipoGenerico> pelo fato de que código pode ser reaproveitado
   nos exercícios de operações com pilhas e filas, apenas limitando as operações
   de inserção, consulta e remoção. Com realação à complexidade, exceto o método
   libera(), que tem crescimento linear, ou seja, complexidade O(N), todos os
   demais métodos possuem tempo constante, isto é, complexidade O(1).
*/

template<typename TipoGenerico>
class NoDeque // declaração dos nós que comporão o deque
{
public:
    TipoGenerico dado;
    NoDeque<TipoGenerico> *noSeguinte; // No caso do deque é neceesário que cada nó
    NoDeque<TipoGenerico> *noAnterior; // armazene tanto o endereço do nó anterior quanto
};                 // do posterior, para permitir que a consulta
                   // seja realizada em ambos os sentidos.

template <typename TipoGenerico>
class Deque // Classe do deque encadeado
{

private:             // as variáveis estão privadas e
                     // toda manipulação é por interface
                     // padrão.
    NoDeque<TipoGenerico> *inicio; // ponteiro de inicio do deque
    NoDeque<TipoGenerico> *fim;    // ponteiro de fim do deque
    int numeroElementos;

public:
    Deque();
    ~Deque();
    void insereInicio(TipoGenerico v);
    void insereFim(TipoGenerico v);
    int tamanho();
    TipoGenerico buscaInicio();
    TipoGenerico buscaFim();
    TipoGenerico removeInicio();
    TipoGenerico removeFim();
};

#include "dequeEncadeado.cpp"

#endif