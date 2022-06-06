#include "pilha2F.hpp"

Pilha2F::Pilha2F()
{
    // Inicialização das filas
    f1 = std::queue<char>{};
    f2 = std::queue<char>{};
}
Pilha2F::~Pilha2F()
{
    while (this->empty() == false)
    {
        this->pop();
    }
}
bool Pilha2F::empty()
{
    return f1.empty() && f2.empty();
}
char Pilha2F::top()
{
    return f1.front();
}
void Pilha2F::push(char t)
{
    while (!f1.empty())
    {
        f2.push(f1.front());
        f1.pop();
    }

    f1.push(t);

    while (!f2.empty())
    {
        f1.push(f2.front());
        f2.pop();
    }
}
char Pilha2F::pop()
{
    char t = f1.front();
    f1.pop();
    return t;
}
template <typename Agregado, typename Tipo>
concept PilhaTAD = requires(Agregado a, Tipo t)
{
    {a.empty()};
    {a.top()};
    {a.push(t)};
    {a.pop()};
};
// testa se Pilha está correta
static_assert(PilhaTAD<Pilha2F, char>);