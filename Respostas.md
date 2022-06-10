---
title: "Lista de Exercícios 4 (Pilhas e Filas)"
author: [Ewerton Luiz Costadelle]
date: "08/06/2022"
keywords: [Pilha Fila Deque RPN]
toc: true 
toc-own-page: true
lang: "pt-br"
book: true
...



# Introdução

Esta lista de exercícios foi proposta pelo Prof. Dr. Igor Machado Coelho, como atividade continuada do tópico Estruturas Lineares na disciplina de Estrutura de Dados e Algoritmos, do Programa de Pós-graduação em Ciência da Computação (PGC) da Universidade Federal Fluminense (UFF), Campus Niterói.

O autor é servidor público no Instituto Federal de Rondônia (IFRO) - _Campus_ Vilhena e atua como docente nas disciplinas da área de Engenharia Elétrica, também é aluno, em nível de doutorado, do PGC-UFF e participa do Projeto de Cooperação entre Instituições para Qualificação de Profissionais de Nível Superior (PCI), firmado entre o IFRO e a UFF.

Esta lista de exercícios serviu de oportunidade para que o autor tivesse uma introdução à orientação à objetos e estrutura de projeto utilizando boas práticas de programação. Foi um desafio sair do pensamento de programação estruturada, com o código em apenas um arquivo e passar a separar as funções em arquivos e subpastas. Tanto os arquivos de cabeçalho (.hpp) quanto as implementações (.cpp) foram separados na subpasta "include". 

Todos os arquivos de cabeçalho começam com diretivas ```#ifndef``` e ```#define``` que evitam referência cíclica, e finalizam com a diretiva ```#include```, que referencia o arquivo de implementação. A exemplo do arquivo _dequeEncadeado.hpp_, abaixo:

```cpp
#ifndef _DEQUE_ENCADEADO_HPP_
#define _DEQUE_ENCADEADO_HPP_

// [...]

#include "dequeEncadeado.cpp"
#endif
```

Seguindo as diretrizes da lista de exercícios, este documento foca mais na lógica do que em programação. É uma discussão da proposta do algoritmo, dos aprendizados do percurso e uma análise da complexidade assintótica dos métodos implementados. Porém, todas as implementações foram testadas e aprovados pelo autor, com código disponibilizado no GitHub [__https://github.com/ecostadelle/lista_pilhas_filas__].

A seguir, cada capítulo deste documento apresenta a resposta de um exercício.

# Exercício 1 {ex1}

A fim de responder essa questão implementei tanto o deque [__sequencial__](https://github.com/ecostadelle/lista_pilhas_filas/blob/main/include/dequeSequencial.hpp) quanto o [__encadeado__](https://github.com/ecostadelle/lista_pilhas_filas/blob/main/include/dequeEncadeado.hpp). Porém, me limitei a comentar apenas no deque [__encadeado__](https://github.com/ecostadelle/lista_pilhas_filas/blob/main/include/dequeEncadeado.hpp) porque foi o que trouxe maior aprendizado. Antes de implementá-lo, a alocação dinâmica era bem nebulosa para mim. Preferi utilizar o tipo genérico, de modo que a implementação pudesse ser reaproveitada em exercícios posteriores, a exemplo das alternativas dessa questão e do Exercício 7, que foi em ordem cronológica o 2º exercício a ser implementado.

Preferi, também, destinar apenas uma pasta para os arquivos Os arquivos de cabeçalho e foram A escolha pelo tipo genérico, associado à estrutura de diretórios

No arquivo de [__cabeçalho__](https://github.com/ecostadelle/lista_pilhas_filas/blob/main/include/dequeEncadeado.hpp), foram definidas as estruturas necessárias para implementar o Deque Encadeado. A primeira classe (```NoDeque```) foi o nó, que armazena um dado do tipo genérico e dois ponteiros que apontam para os nós anterior (```*noAnterior```) e posterior (```*noSeguinte```). 

```cpp
template<typename TipoGenerico>
class NoDeque 
{
public:
    TipoGenerico dado;
    NoDeque<TipoGenerico> *noSeguinte; 
    NoDeque<TipoGenerico> *noAnterior;
};                 
```

O tipo genérico do dado armazenado precisa ser definido na declaração da variável e é atribuída à classe em tempo de compilação. Inclusive tive muitos problemas quando escolhi esse método, porque eu estava compilando os objetos separados e vinculando-os posteriormente. 

Na segunda classe (```Deque```), foram declarados em modo privado os ponteiros que apontam apenas para dois nós, o inicial e o final. As interfaces padrão foram declaradas em modo público, de maneira que permitiam o acesso externo a classe.

``` cpp
template <typename TipoGenerico>
class Deque 
{
private:
    NoDeque<TipoGenerico> *inicio;
    NoDeque<TipoGenerico> *fim;
    int numeroElementos;

public:
    Deque();
    ~Deque();
    void insereInicio(TipoGenerico v);
    void insereFim(TipoGenerico v);
    int tamanho();
    TipoGenerico buscaInicio();
    TipoGenerico buscaFim();
    TipoGenerico removeInicio();
    TipoGenerico removeFim();
};
```

Os métodos tiveram seu próprio arquivo de [__implementação (dequeEncadeado.cpp)__](https://github.com/ecostadelle/lista_pilhas_filas/blob/main/include/dequeEncadeado.cpp). Além dos métodos solicitados através do ```staticassert```, foram implementados um construtor ```Deque()```, que inicia as variáveis em tempo constante $O(1)$, e um destrutor ```~Deque()```, que ao se invocado, percorre todos os elementos do deque, liberando a memória e evitando "vazamento de memória". A complexidade do método destrutor é linearmente depende do tamanho armazenado em ```numeroElementos``` (n), ou seja, $O(n)$ 

```cpp
#include "dequeEncadeado.hpp"

template <typename TipoGenerico>
Deque<TipoGenerico>::Deque()
{
    this->numeroElementos = 0;
    this->inicio = nullptr;
    this->fim = nullptr;
}

template <typename TipoGenerico>
Deque<TipoGenerico>::~Deque()
{
    while (this->numeroElementos > 0)
        removeInicio();
} 
```

No método ```insereInicio``` um nó é criado e alocado dinamicamente na memória, um ponteiro (```*no```) armazena o endereço e um dado é inserido. Caso o deque esteja vazio, os endereços de início e fim serão os mesmo do nó recém criado. Caso contrário, o campo ```noSeguinte``` do nó recém criado recebe o endereço daquele que era o início, e o campo ```noAnterior```, daquele que era o inicio, recebe o endereço do novo nó e o número de elementos no deque é incrementado. Este método opera em tempo constante, ou seja, $O(1)$.

```cpp
template <typename TipoGenerico>
void Deque<TipoGenerico>::insereInicio(TipoGenerico v)
{
    NoDeque<TipoGenerico> *no =
        new NoDeque
        {.dado = v,
         .noSeguinte = nullptr,
         .noAnterior = nullptr};
    if (numeroElementos == 0)
    {
        inicio = fim = no;
    }
    else 
    {
        no->noSeguinte = inicio;
        inicio->noAnterior = no;
        inicio = no;
    }
    numeroElementos++;
}



template <typename TipoGenerico>
void Deque<TipoGenerico>::insereFim(TipoGenerico v)
{
    NoDeque<TipoGenerico> *no =
        new NoDeque<TipoGenerico> 
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
int Deque<TipoGenerico>::tamanho()
{
    return this->numeroElementos;
}

template <typename TipoGenerico>
TipoGenerico Deque<TipoGenerico>::buscaInicio()
{
    return inicio->dado;
}

template <typename TipoGenerico>
TipoGenerico Deque<TipoGenerico>::buscaFim()
{ 
    return fim->dado;
}

template <typename TipoGenerico>
TipoGenerico Deque<TipoGenerico>::removeInicio()
{
    NoDeque<TipoGenerico> *p = inicio;
    inicio = inicio->noSeguinte;
    TipoGenerico r = p->dado;
    delete p;
    numeroElementos--;
    return r;
}

template <typename TipoGenerico>
TipoGenerico Deque<TipoGenerico>::removeFim() 
{                                             
    NoDeque<TipoGenerico> *p = fim;           
    fim = fim->noAnterior;              
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
```



# Exercício 2 {ex2}


# Exercício 3 {ex3}


# Exercício 4 {ex4}


# Exercício 5 {ex5}


# Exercício 6 {ex6}


# Exercício 7 {ex7}

Para resolver este exercício, uma pilha armazenou os operadores e um vetor, a saída. 

De modo que um laço percorre a entrada e armazena letras (variáveis) diretamente na saída e sinais (operações) na pilha até encontrar:
1. um parêntese fechado; ou 
2. um operador de precedência inferior ao último encontrado. 

Assim que uma das duas condições é satisfeita, duas coisas podem ocorrer, respectivamente: 
1. o último operador é desempilhado, inserido no vetor de saída, e o um parêntese aberto também é desempilhado;
2. o operador de maior precedência é desempilhado, inserido na saída e o novo operador é empilhado.

Ao chegar ao final do laço, todos os operadores são desempilhados e inseridos na saída.

Com o objetivo de determinar as precedências, utilizou-se o código ASCII do caractere subtraído de 41 em módulo 6. Esta transformação faz com que o caractere '*' (decimal 42), torne-se 1; '+' (decimal 43), torne-se 2; '-' (decimal 45), torne-se 4; e, por fim, o caractere '/' (decimal 47), torne-se 0. 
