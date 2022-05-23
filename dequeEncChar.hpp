class NoDeque
{
public:
    char dado;
    NoDeque *prox;
    NoDeque *ante;
};

class DequeEnc
{
    
private:
    NoDeque *inicio;           // frente da fila
    NoDeque *fim;              // fundo da fila
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
        NoDeque *p = inicio;   // ponteiro do inicio
        auto r = p->dado;         // conteudo do inicio
        return r;
    }

    auto buscaFim() {
        NoDeque *p = fim;      // ponteiro do fim
        auto r = p->dado;         // conteudo do fim
        return r;
    }

    void insereInicio(char v)
    {
        NoDeque *no = new NoDeque{.dado = v, .prox = 0, .ante = 0};
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

    void insereFim(char v)
    {
        NoDeque *no = new NoDeque{.dado = v, .prox = 0, .ante = 0};
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
        NoDeque *p = inicio;   // ponteiro da frente
        inicio = inicio->prox;    // avança fila
        auto r = p->dado;         // conteudo da frente
        delete p;                 // apaga frente
        N--;
        return r;
    }

    auto removeFim()
    {
        NoDeque *p = fim;      // ponteiro da frente
        fim = fim->ante;          // avança fila
        auto r = p->dado;         // conteudo da frente
        delete p;                 // apaga frente
        N--;
        return r;
    }
};

template <typename Agregado, typename Tipo>
concept bool dequeTAD = requires(Agregado a, Tipo t) {
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
static_assert(dequeTAD<DequeEnc, char>);