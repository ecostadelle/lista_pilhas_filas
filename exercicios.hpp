#include <stack>

const int MAXDEQUE = 100;

// implementação do TAD deque
class dequeSequencial
{
public:
    int inicio=0, fim=0, tamanho=0;
    int dado[MAXDEQUE];
    void incrementa(int * a){
        if ( (tamanho < MAXDEQUE) && (tamanho >= 0) ) {
            // rotinas para incrmentar e manter a variável dentro do ciclo
            *a += 1; 
            *a %= MAXDEQUE;
        }
    }
    void decrementa(int * a){
        if ( (tamanho < MAXDEQUE) && (tamanho >= 0) ) {
            // rotinas para decrementar e manter a variável dentro do ciclo
            *a -= 1; 
            *a += MAXDEQUE;
            *a %= MAXDEQUE;
        }
    }
    void insereInicio(int x){
        decrementa(&inicio);
        tamanho += 1;
        dado[inicio] = x;
        cout << x << " inserido no inicio, tamanho: " << tamanho;
        cout << " inicio: " << inicio << endl;
    }
    void insereFim(int x){
        incrementa(&fim);
        tamanho += 1;
        dado[fim] = x;
        cout << x << " inserido no fim, tamanho: " << tamanho;
        cout << " fim: " << fim << endl;
    }
    auto buscaInicio(){
        return dado[inicio];
    }
    auto buscaFim(){
        return dado[fim];
    }

    auto removeInicio(){
        int buffer = inicio;
        tamanho -= 1;
        incrementa(&inicio);
        return buffer;
    }
    auto removeFim(){
        int buffer = fim;
        tamanho -= 1;
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
    char precedencia[] = "*/+-";
    // posicao para escrever no vetor de saida
    int posicao = 0;

    // alterar para 'range based for'
    for (int i=0; i<N; i++){

        // condicional para detectar se é uma letra maiúscula
        if ( (expressao[i] >= 'A') && (expressao[i] <= 'Z') ) {
            saida_polonesa[posicao++] = expressao[i];
        }
        // caso o operador seja um parentese fechando, é recuperado o último operador aritmético da pilha
        if (expressao[i] == ')') {
            saida_polonesa[posicao++] = operadores.top();
            operadores.pop();
        }
        // caso o operador seja aritmético, é empilhado
        if ( (expressao[i] >= '*') && (expressao[i] <= '/') ){
            operadores.push(expressao[i]);
        }
    }
    saida_polonesa[++posicao] = 0;
}