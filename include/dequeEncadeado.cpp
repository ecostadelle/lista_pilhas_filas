#include "dequeEncadeado.h"

template <typename T>
void Deque<T>::cria()          // Método 'construtor', não propriamente
{                           // dito, porém, inicia as variáveis
    this->N = 0;            // com zero elementos na fila,
    this->inicio = nullptr; // endereço zero de memória para início e
    this->fim = nullptr;    // endereço zero de memória para fim.
} // Esse método tem complexidade O(1).

template <typename T>
void Deque<T>::libera()    // Método para evitar o vazamento
{                       // de memória provocado pelas
    while (this->N > 0) // inúmeras alocações dinâmicas.
        removeInicio(); // limpa o deque a partir do início
} // porém também poderia começar pelo fim.
  // Esse laço tem complexidade O(N).

template <typename T>
void Deque<T>::insereInicio(T v) // método para inserir elementos
{
    NoDeque<T> *no =   // alocação dinâmica de um novo nó
        new NoDeque // com inicialização das variáveis
        {.dado = v,
         .prox = nullptr,
         .ante = nullptr};
    if (N == 0)            // caso seja o primiero nó do deque,
    {                      // os ponterios de inicio e fim
        inicio = fim = no; // apontarão para o mesmo nó.
    }
    else                   // caso já exista pelo menos um nó no
    {                      // deque, o ponteiro de 'próximo' do nó
        no->prox = inicio; // inserido recebe o endereço daquele
        inicio->ante = no; // que era o primeiro nó do deque.
        inicio = no;       // Esse 'ex-primeiro nó', também recebe o
    }                      // endereço do nó inserido no campo
    N++;                   // 'anterior' e o tamanho é incrementado.
} // Esse método tem complexidade O(1).

template <typename T>
void Deque<T>::insereFim(T v) // A operação deste método é muito
{                          // semelhante à anterior, difere apenas
    NoDeque<T> *no =       // na extremidade em que é realizada.
        new NoDeque<T>     // Esse método tem complexidade O(1).
        {.dado = v,
         .prox = nullptr,
         .ante = nullptr};
    if (N == 0)
    {
        inicio = fim = no;
    }
    else
    {
        no->ante = fim;
        fim->prox = no;
        fim = no;
    }
    N++;
}

template <typename T>
int Deque<T>::tamanho() // método para obter o tamanho atual
{                    // Esse método tem complexidade O(1).
    return this->N;
}

template <typename T>
T Deque<T>::buscaInicio()
{                        // método que retorna o primeiro elemento
    return inicio->dado; // retorno do método
} // Esse método tem complexidade O(1).

template <typename T>
T Deque<T>::buscaFim()
{                     // método que retorna o último elemento
    return fim->dado; // retorno do método
} // Esse método tem complexidade O(1).

template <typename T>
T Deque<T>::removeInicio()
{
    NoDeque<T> *p = inicio; // Ponteiro temporário que indica o
    inicio = inicio->prox;  // um novo início que é determinado avançando
    T r = p->dado;       // para o 'próximo', o conteudo do antigo
    delete p;               // início é armazenado, porque a memória é
    N--;                    // desalocada. O tamanho é decremntado e,
    return r;               // diferente do deque da STL, o conteúdo
} // é retornado.
  // Esse método tem complexidade O(1).

template <typename T>
T Deque<T>::removeFim()  // A operaçaão deste método é muito
{                        // semelhante à anterior, difere apenas
    NoDeque<T> *p = fim; // na extremidade em que é realizada.
    fim = fim->ante;     // Esse método tem complexidade O(1).
    T r = p->dado;
    delete p;
    N--;
    return r;
}