# Lista de Exercícios

## Curso de Estruturas de Dados I (em C/C++) 

### Prof. Igor Machado Coelho - Tópico: Estruturas Lineares ####

Observação: os exercícios devem ser feitos em C/C++ (ou similar!). Foque mais na lógica do que em erros básicos de programação e SEMPRE discuta a proposta do algoritmo (não quero apenas código!). Sempre analise a complexidade assintótica dos métodos implementados.

---

1. Considere um tipo chamado Deque, que inclui manipulação de dois extremos em uma estrutura linear (como se operasse como Pilha e Fila simultaneamente). 

    ```cpp
    template <typename Agregado, typename Tipo>
    concept bool DequeTAD = requires(Agregado a, Tipo t) {
        // requer operação de consulta ao elemento 'inicio'
        {a.inicio()};
        // requer operação de consulta ao elemento 'fim'
        {a.fim()};
        // requer operação 'insereInicio' sobre tipo 't'
        {a.insereInicio(t)};
        // requer operação 'insereFim' sobre tipo 't'
        {a.insereFim(t)};
        // requer operação 'removeInicio' e retorna tipo 't'
        {a.removeInicio()};
        // requer operação 'removeFim' e retorna tipo 't'
        {a.removeFim()};
    };
    ```

    a. Satisfaça as seguintes operações de um DequeTAD para o tipo 'char', utilizando uma estrutura Sequencial OU uma estrutura encadeada: 

    ```cpp
    class Deque {
    public: 
    // implementar métodos propostos no TAD Deque 
    }; 
    // testa se Deque está correto 
    static_assert(DequeTAD<Deque, char>); 
    ```

    b. Implemente uma estrutura PilhaDeque para tipo 'char', utilizando somente um Deque como armazenamento interno e mais espaço auxiliar constante:

    ```cpp
    class PilhaDeque { 
    public: 
        // Deque para 'char' (veja exercício anterior) 
        Deque d; 
        // SOMENTE espaço auxiliar CONSTANTE aqui 
        // (nenhum vetor, lista, etc) 
        // implementar métodos do TAD Pilha 
    }; 
    // testa se Deque está correto 
    static_assert(DequeTAD<Deque, char>); 
    // testa se Pilha está correta
    static_assert(PilhaTAD<PilhaDeque, char>); 
    ```

    c) Implemente uma estrutura FilaDeque para tipo 'char', utilizando somente um Deque como armazenamento interno e mais espaço auxiliar constante: 

    ```cpp
    class FilaDeque { 
    public: 
        Deque d; // Deque para 'char' (veja exercício anterior) 
        // SOMENTE espaço auxiliar CONSTANTE aqui 
        // (nenhum vetor, lista, etc) 
        // implementar métodos do TAD Fila 
    }; 
    // testa se Deque está correto 
    static_assert(DequeTAD<Deque, char>);
    // testa se Fila está correta
    static_assert(FilaTAD<FilaDeque, char>); 
    ```
---

2. Implemente uma estrutura que satisfaz o TAD Pilha para o tipo 'char' e somente utiliza duas Filas como armazenamento interno (mais espaço constante): 

    ```cpp
    #include <queue> // Fila genérica em C++
    class Pilha2F {
    public:
        std::queue<char> f1; // Fila para 'char'
        std::queue<char> f2; // Fila para 'char'
        // SOMENTE espaço auxiliar CONSTANTE aqui 
        // (nenhum vetor, lista, etc) 
        // implementar métodos do TAD Pilha
    };
    // testa se Pilha está correta
    static_assert(PilhaTAD<Pilha2F, char>); 
    ```

---

3. Implemente uma estrutura que satisfaz o TAD Fila para o tipo 'char' e somente utiliza duas Pilhas comoarmazenamento interno (mais espaço constante): 

    ```cpp
    #include <stack> // Pilha genérica em C++ 
    class Fila2P{ 
    public: 
        std::stack<char> p1; // Pilha para 'char' 
        std::stack<char> p2; // Pilha para 'char' 
        // SOMENTE espaço auxiliar CONSTANTE aqui 
        // (nenhum vetor, lista, etc) 
        // implementar métodos do TAD Fila 
    }; 
    // testa se Fila está correta 
    static_assert(FilaTAD<Fila2P, char>); 
    ```

---

4. Escreva um algoritmo que dada uma pilha padrão P externa passada como parâmetro, inverte oconteúdode P. Somente utilize as estruturas extras permitidas como armazenamento externo(mais espaço constante)

    a. Uma Fila 

    ```cpp
    void inverte(std::stack<char>* p) { 
        // somente essa fila e mais espaço auxiliar constante
        std::queue<char> f; 
    } 
    ```

    b. Duas Pilhas 

    ```cpp
    void inverte(std::stack<char>* p) { 
        std::stack<char> p1; // primeira pilha auxiliar 
        std::stack<char> p2; // segunda pilha auxiliar 
        // mais espaço auxiliar constante 
    } 
    ```

    c. Uma Pilha 

    ```cpp
    void inverte(std::stack<char>* p) { 
        std::stack<char> p1; // uma pilha auxiliar 
        // mais espaço auxiliar constante 
    } 
    ```

---

5. Escreva um algoritmo que dada uma fila padrão F externa passada como parâmetro, inverte o conteúdo de F. Somente utilize as estruturas extras permitidas como armazenamento externo (mais espaço constante)

    a. Uma Pilha:

    ```cpp
    void inverte(std::queue<char>* f) { 
        // somente essa pilha e mais espaço auxiliar constante
        std::stack<char> p;
    }
    ```

    b. Duas Filas 

    ```cpp
    void inverte(std::queue<char>* f) { 
        std::queue<char> f1; // primeira fila auxiliar 
        std::queue<char> f2; // segunda fila auxiliar 
        // mais espaço auxiliar constante 
    } 
    ```

---

6. Criar uma implementação do TAD Pilha para o tipo 'int', chamada PilhaMin, que oferece os métodos do TAD e também o método `obterMinimo()`, que retorna o menor elemento da pilha. O método `obterMinimo()` deve operar em tempo constante. 

    ```cpp
    class PilhaMin { 
    public: 
    // incluir variáveis necessárias 
        int topo(); 
        int desempilha(); 
        void empilha(int t); 
        int obterMinimo(); 
        // mais métodos auxiliares 
    };
    // testa de PilhaMin está de acordocomoTAD
    static_assert(PilhaTAD<PilhaMin, int>); 
    ```

---

7. Escreva um algoritmo que converte uma expressão aritmética parentizada usando as 4 operações para a expressão correspondente em notação polonesa reversa. Exemplo:
    Entrada: `((A+B)*(C-(F/D)))` 
    Saída:  `AB+CFD/-*` 


    ```cpp
    void polonesa(char* expressao, int N, char* saida_polonesa) 
    // 'expressao' eh um string terminado em '\0', 
    // com tamanho N (sem contar o '\0')
    // 'saida_polonesa' eh um string com capacidade máxima N 
    { 
        // escreva o resultado no string 'saida_polonesa' 
    }
    ```
    > Para resolver este exercício, uma pilha armazenou os operadores e um vetor, a saída. 
    >
    > De modo que um laço percorre a entrada e armazena letras (variáveis) diretamente na saída e sinais (operações) na pilha até encontrar:
    >   1. um parentese fechado; ou 
    >   2. um operador de precedência inferior ao último encontrado. 
    >
    > Assim que uma das duas condições é satisfeita, duas coisas podem ocorrer, respectivamente: 
    >   1. o último operador é desemplinhado, inserido no vetor de saída, e o um parentese aberto também é desempilhado;
    >   2. o operador de maior precedência é desempilhado, inserido na saída e o novo operador é empilhado.
    >
    > Ao chegar ao final do laço, todos os operadores são desempilhados e inseridos na saída.