template<typename T>
class NoDeque
{
public:
    T dado;
    NoDeque<T> *prox;
    NoDeque<T> *ante;
};

template<typename T>
class DequeEnc
{
    
private:
    NoDeque<T> *inicio;           // frente da fila
    NoDeque<T> *fim;              // fundo da fila
    int N;

public:

    int tamanho()
    {
        return this->N;
    }

    void cria()
    {
        this->N = 0;              // zero elementos na fila
        this->inicio = 0;         // endereço zero de memória
        this->fim = 0;            // endereço zero de memória
    }

    void libera()
    {
        while (this->N > 0)
            removeInicio();       // limpa a fila
    }

    auto buscaInicio() {
        NoDeque<T> *p = inicio;   // ponteiro do inicio
        auto r = p->dado;         // conteudo do inicio
        return r;
    }

    auto buscaFim() {
        NoDeque<T> *p = fim;      // ponteiro do fim
        auto r = p->dado;         // conteudo do fim
        return r;
    }

    void insereInicio(T v)
    {
        NoDeque<T> *no = new NoDeque<T>{.dado = v, .prox = 0, .ante = 0};
        if (N == 0)
        {
            inicio = fim = no;
        }
        else
        {
            no->prox = inicio;
            inicio->ante = no;
            inicio = no;
        }
        N++;
    }

    void insereFim(T v)
    {
        NoDeque<T> *no = new NoDeque<T>{.dado = v, .prox = 0, .ante = 0};
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

    char removeInicio()
    {
        NoDeque<T> *p = inicio;   // ponteiro da frente
        inicio = inicio->prox;    // avança fila
        auto r = p->dado;         // conteudo da frente
        delete p;                 // apaga frente
        N--;
        return r;
    }

    auto removeFim()
    {
        NoDeque<T> *p = fim;      // ponteiro da frente
        fim = fim->ante;          // avança fila
        auto r = p->dado;         // conteudo da frente
        delete p;                 // apaga frente
        N--;
        return r;
    }
};

template <typename Agregado, typename Tipo>

// o intelliSense reclamou do 'concept bool' até eu 
// corrigir na configuração e compiar em c++20
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
static_assert(dequeTAD<DequeEnc<char>, char>, "Erro");