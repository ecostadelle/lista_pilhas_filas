#ifndef _DEQUE_SEQUENCIAL
#define _DEQUE_SEQUENCIAL

const int MAXDEQUE = 100;

// implementação do TAD deque
template <typename T>
class DequeSeq
{
private:
    int inicio, fim, N;
    T dado[MAXDEQUE];
    void incrementa(int * a){
        if ( (N < MAXDEQUE) && (N >= 0) ) {
            // rotinas para incrmentar e manter a variável dentro do ciclo
            *a += MAXDEQUE + 1;
            *a %= MAXDEQUE;
        }
    }
    void decrementa(int * a){
        if ( (N < MAXDEQUE) && (N >= 0) ) {
            // rotinas para decrementar e manter a variável dentro do ciclo
            *a += MAXDEQUE - 1;
            *a %= MAXDEQUE;
        }
    }
public:
    void cria(){
        this->N=0;
        this->inicio=0;
        this->fim=1;

    }
    void libera(){}

    void insereInicio(T x){
        dado[inicio] = x;
        decrementa(&inicio);
        N += 1;
    }

    int tamanho(){
        return this->N;
    }

    void insereFim(T x){
        dado[fim] = x;
        incrementa(&fim);
        N += 1;
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
        T buffer = buscaInicio();
        N -= 1;
        incrementa(&inicio);
        return buffer;
    }

    auto removeFim(){
        T buffer = buscaFim();
        N -= 1;
        decrementa(&fim);
        return buffer;
    }
};

#endif