#ifndef _DEQUE_SEQUENCIAL
#define _DEQUE_SEQUENCIAL

/*
   Utilizei um tipo genérico <T> pelo fato de que código pode ser reaproveitado 
   nos exercícios de operações com pilhas e filas, apenas limitando as operações 
   de inserção, consulta e remoção.
*/

template<typename T>              // tipo genérico, que pode receber um char
class NoDeque                     // declaração dos nós que comporão o deque
{
public:
    T dado;
    NoDeque<T> *prox;             // no caso do deque é neceesário vincular
    NoDeque<T> *ante;             // tanto o nó anterior quanto o posterior
};

template<typename T>              // tipo genérico
class DequeEnc                    // Classe do deque encadeado
{
    
private:                          // as variáveis estão privadas e
                                  // toda manipulação é por interface
                                  // padrão.

    NoDeque<T> *inicio;           // ponteiro de inicio do deque
    NoDeque<T> *fim;              // ponteiro de fim do deque
    int N;

public:
    int tamanho()                 // método para obter o tamanho atual
    {
        return this->N;
    }

    void cria()                   // método 'construtor'
    {                             // inicia as variáveis
        this->N = 0;              // zero elementos na fila
        this->inicio = nullptr;   // endereço zero de memória
        this->fim = nullptr;      // endereço zero de memória
    }

    void libera()                 // método para evitar o vazamento 
    {                             // de memória provocado pelos 
        while (this->N > 0)       // inúmeras alocações dinâmicas.
            removeInicio();       // limpa o deque a partir do início
    }                             // porém também poderia começar pelo fim

    auto buscaInicio() {          // método que retorna o primeiro elemento
        return inicio->dado;      // retorno do método
    }

    auto buscaFim() {             // método que retorna o último elemento
        return fim->dado;         // retorno do método
    }

    void insereInicio(T v)        // método para inserir elementos
    {
        NoDeque<T> *no =          // alocação dinâmica de um novo nó
            new NoDeque<T>        // com inicialização das variáveis
                {.dado = v, 
                 .prox = nullptr, 
                 .ante = nullptr};
        if (N == 0)               // caso seja o primiero nó do deque,
        {                         // os ponterios de inicio e fim 
            inicio = fim = no;    // apontarão para o mesmo nó.
        }
        else                      // caso já exista pelo menos um nó no
        {                         // deque, o ponteiro de 'próximo' do nó 
            no->prox = inicio;    // inserido recebe o endereço daquele
            inicio->ante = no;    // que era o primeiro nó do deque. 
            inicio = no;          // Esse ex-primeiro nó, também recebe o 
        }                         // endereço do nó inserido no campo 
        N++;                      // 'anterior' e o tamanho é incrementado.
    }

    void insereFim(T v)           // A operaçaão deste método é muito 
    {                             // semelhante à anterior, difere apenas 
        NoDeque<T> *no =          // na extremidade em que é realizada.
            new NoDeque<T>
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

    auto removeInicio()
    {
        NoDeque<T> *p = inicio;   // Ponteiro temporário que indica o 
        inicio = inicio->prox;    // um novo início que é determinado avançando 
        auto r = p->dado;         // para o 'próximo', o conteudo do antigo 
        delete p;                 // início é armazenado, porque a memória é 
        N--;                      // desalocada. O tamanho é decremntado e,
        return r;                 // diferente do deque da STL, o conteúdo 
    }                             // é retornado.

    auto removeFim()              // A operaçaão deste método é muito 
    {                             // semelhante à anterior, difere apenas 
        NoDeque<T> *p = fim;      // na extremidade em que é realizada.
        fim = fim->ante;
        auto r = p->dado;
        delete p;
        N--;
        return r;
    }
};

/*
    No VSCode (conectado ao git), utilizando MSys2 (GCC v11.3) e extensões 
    recomendadas (um pacotão que tem diponível e assinado pela Microsoft), 
    a extensão 'IntelliSense' sempre reclamava do 'concept bool'. 
    
    Quase tive um 'stackoverflow' (de tanto buscar no site homônimo). 
    Mas o GCC compilava, suave, era só o IntelliSense que não curtia 
    o tal do 'concept bool'.

    Resolvi alterando 'C++ standard' de 'c++17' para 'c++20' em 'C/C++: Edit 
    Configurations (UI)' e mudando o 'std' no makefile, também para 'c++20',
    removi o "bool" (já que isso mudou no c++20). Engraçado que se no makefile 
    estriver '--std=c++17' o IntelliSense reclama.

    Com o conjunto de ações acima o IntelliSense parou de reclamar do 'concept'.
*/

template <typename Agregado, typename Tipo>

concept dequeTAD = requires(Agregado a, Tipo t) {
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

// verifica agregado DequeEnc
static_assert(dequeTAD<DequeEnc<char>, char>);

#endif