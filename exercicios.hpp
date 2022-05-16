const int MAXDEQUE = 100;

// implementação do TAD deque
class dequeSequencial
{
private:
    int inicio=0, fim=0, tamanho=0;
    int dado[MAXDEQUE];
public:
    void incrementa(int * a){
        if ( (tamanho < MAXDEQUE) && (tamanho >= 0) ) {
            // rotinas para incrmentar e manter a variável dentro do ciclo
            *a++; 
            *a %= MAXDEQUE;
        }
    }
    void decrementa(int * a){
        if ( (tamanho < MAXDEQUE) && (tamanho >= 0) ) {
            // rotinas para decrementar e manter a variável dentro do ciclo
            *a--; 
            *a += MAXDEQUE;
            *a %= MAXDEQUE;
        }
    }
    void insereInicio(int x){
        decrementa(&inicio);
        tamanho++;
        dado[inicio] = x;
    }
    void insereFim(int x){
        incrementa(&fim);
        tamanho++;
        dado[fim] = x;
    }
    auto buscaInicio(){
        return dado[inicio];
    }
    auto buscaFim(){
        return dado[fim];
    }

    auto removeInicio(){
        int buffer = buscaInicio();
        tamanho--;
        incrementa(&inicio);
        return buffer;
    }
    auto removeFim(){
        int buffer = buscaFim();
        tamanho--;
        decrementa(&fim);
        return buffer;

    }
};