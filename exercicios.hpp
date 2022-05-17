#include <stack>

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
        this->tamanho++;
        this->dado[inicio] = x;
        std::cout << x << " inserido no inicio: " << inicio << endl;
    }
    void insereFim(int x){
        incrementa(&fim);
        this->tamanho++;
        this->dado[fim] = x;
        std::cout << x << " inserido no fim: " << fim << endl;
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

void polonesa(char* expressao, int N, char* saida_polonesa) 
// 'expressao' eh um string terminado em '\0', 
// com tamanho N (sem contar o '\0')
// 'saida_polonesa' eh um string com capacidade máxima N 
{ 
    // escreva o resultado no string 'saida_polonesa' 

    // pilha para armazenar os operadores
    std::stack<char> operadores;

    //vetor para armazenar a saida
    char saida[N];

    // posicao para escrever no vetor de saida
    int posicao = 0;
    for (int i=0; i<N; ++i){
        // condicional para detectar se é uma letra maiúscula
        if ( (expressao[i] >= 'A') && (expressao[i] <= 'Z') ) {
            saida[posicao] = expressao[i];
        } else if (expressao[i] == ')') {
            saida[posicao] = operadores.top();
            operadores.pop();
            operadores.pop();
        }
    }
}