const int MAXDEQUE = 100;

// implementação do TAD deque
template <typename D>
class DequeTAD
{
private:
    int inicio=0, fim=1;
    D dado[MAXDEQUE];
    void incrementa(int * a){
        if ( (tamanho < MAXDEQUE) && (tamanho >= 0) ) {
            // rotinas para incrmentar e manter a variável dentro do ciclo
            *a += MAXDEQUE + 1;
            *a %= MAXDEQUE;
        }
    }
    void decrementa(int * a){
        if ( (tamanho < MAXDEQUE) && (tamanho >= 0) ) {
            // rotinas para decrementar e manter a variável dentro do ciclo
            *a += MAXDEQUE - 1;
            *a %= MAXDEQUE;
        }
    }
public:
    int tamanho=0;
    void insereInicio(D x){
        dado[inicio] = x;
        decrementa(&inicio);
        tamanho += 1;
    }
    void insereFim(D x){
        dado[fim] = x;
        incrementa(&fim);
        tamanho += 1;
    }
    auto buscaInicio(){
        int posAnterior = (inicio+1+MAXDEQUE)%MAXDEQUE;
        return dado[posAnterior];
    }
    auto buscaFim(){
        int posAnterior = (fim-1+MAXDEQUE)%MAXDEQUE;
        return dado[posAnterior];
    }

    auto removeInicio(){
        D buffer = buscaInicio();
        tamanho -= 1;
        incrementa(&inicio);
        return buffer;
    }
    auto removeFim(){
        D buffer = buscaFim();
        tamanho -= 1;
        decrementa(&fim);
        return buffer;

    }
};
