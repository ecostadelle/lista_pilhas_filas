#include "dequeEncadeado.hpp"

template <typename TipoGenerico>
Deque<TipoGenerico>::Deque() // Método construtor, inicia as variáveis
{
    this->numeroElementos = 0; // com zero elementos na fila,
    this->inicio = nullptr;    // endereço zero de memória para início e
    this->fim = nullptr;       // endereço zero de memória para fim.
} // Esse método tem complexidade O(1).

template <typename TipoGenerico>
Deque<TipoGenerico>::~Deque()         // Método para evitar o vazamento
{                                     // de memória provocado pelas
    while (this->numeroElementos > 0) // inúmeras alocações dinâmicas.
        removeInicio();               // limpa o deque a partir do início
} // porém também poderia começar pelo fim.
  // Esse laço tem complexidade O(N).

template <typename TipoGenerico>
void Deque<TipoGenerico>::insereInicio(TipoGenerico v) // método para inserir elementos
{
    NoDeque<TipoGenerico> *no = // alocação dinâmica de um novo nó
        new NoDeque             // com inicialização das variáveis
        {.dado = v,
         .noSeguinte = nullptr,
         .noAnterior = nullptr};
    if (numeroElementos == 0) // caso seja o primiero nó do deque,
    {                         // os ponterios de inicio e fim
        inicio = fim = no;    // apontarão para o mesmo nó.
    }
    else                         // caso já exista pelo menos um nó no
    {                            // deque, o ponteiro de 'próximo' do nó
        no->noSeguinte = inicio; // inserido recebe o endereço daquele
        inicio->noAnterior = no; // que era o primeiro nó do deque.
        inicio = no;             // Esse 'ex-primeiro nó', também recebe o
    }                            // endereço do nó inserido no campo
    numeroElementos++;           // 'anterior' e o tamanho é incrementado.
} // Esse método tem complexidade O(1).

template <typename TipoGenerico>
void Deque<TipoGenerico>::insereFim(TipoGenerico v) // A operação deste método é muito
{                                                   // semelhante à anterior, difere apenas
    NoDeque<TipoGenerico> *no =                     // na extremidade em que é realizada.
        new NoDeque<TipoGenerico>                   // Esse método tem complexidade O(1).
        {.dado = v,
         .noSeguinte = nullptr,
         .noAnterior = nullptr};
    if (numeroElementos == 0)
    {
        inicio = fim = no;
    }
    else
    {
        no->noAnterior = fim;
        fim->noSeguinte = no;
        fim = no;
    }
    numeroElementos++;
}

template <typename TipoGenerico>
int Deque<TipoGenerico>::tamanho() // método para obter o tamanho atual
{                                  // Esse método tem complexidade O(1).
    return this->numeroElementos;
}

template <typename TipoGenerico>
TipoGenerico Deque<TipoGenerico>::buscaInicio()
{                        // método que retorna o primeiro elemento
    return inicio->dado; // retorno do método
} // Esse método tem complexidade O(1).

template <typename TipoGenerico>
TipoGenerico Deque<TipoGenerico>::buscaFim()
{                     // método que retorna o último elemento
    return fim->dado; // retorno do método
} // Esse método tem complexidade O(1).

template <typename TipoGenerico>
TipoGenerico Deque<TipoGenerico>::removeInicio()
{
    NoDeque<TipoGenerico> *p = inicio; // Ponteiro temporário que indica o
    inicio = inicio->noSeguinte;       // um novo início que é determinado avançando
    TipoGenerico r = p->dado;          // para o 'próximo', o conteudo do antigo
    delete p;                          // início é armazenado, porque a memória é
    numeroElementos--;                 // desalocada. O tamanho é decremntado e,
    return r;                          // diferente do deque da STL, o conteúdo
} // é retornado.
  // Esse método tem complexidade O(1).

template <typename TipoGenerico>
TipoGenerico Deque<TipoGenerico>::removeFim() // A operaçaão deste método é muito
{                                             // semelhante à anterior, difere apenas
    NoDeque<TipoGenerico> *p = fim;           // na extremidade em que é realizada.
    fim = fim->noAnterior;                    // Esse método tem complexidade O(1).
    TipoGenerico r = p->dado;
    delete p;
    numeroElementos--;
    return r;
}

template <typename Agregado, typename Tipo>
concept DequeTAD = requires(Agregado a, Tipo t)
{
    // requer operação de consulta ao elemento 'inicio'
    {a.buscaInicio()};
    // requer operação de consulta ao elemento 'fim'
    {a.buscaFim()};
    // requer operação 'insereInicio' sobre tipo 't'
    {a.insereInicio(t)};
    // requer operação 'insereFim' sobre tipo 't'
    {a.insereFim(t)};
    // requer operação 'removeInicio' e retorna tipo 't'
    {a.removeInicio()};
    // requer operação 'removeFim' e retorna tipo 't'
    {a.removeFim()};
};
// testa se Deque está correto
static_assert(DequeTAD<Deque<char>, char>);