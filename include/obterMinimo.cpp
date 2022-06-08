#include "obterMinimo.hpp"

int PilhaMin::topo()
{
    return pilhaPrincipal.top();
}
int PilhaMin::desempilha()
{
    int topo = pilhaPrincipal.top();
    pilhaPrincipal.pop();
    pilhaAuxiliar.pop();
    return topo;
}
void PilhaMin::empilha(int t)
{
    if (pilhaPrincipal.empty())
    {
        pilhaPrincipal.push(t);
        pilhaAuxiliar.push(t);
    }
    else
    {
        pilhaPrincipal.push(t);
        if (t < pilhaAuxiliar.top())
        {
            pilhaAuxiliar.push(t);
        }
        else
        {
            pilhaAuxiliar.push(pilhaAuxiliar.top());
        }
    }
}
int PilhaMin::obterMinimo()
{
    return pilhaAuxiliar.top();
}

// mais métodos auxiliares
bool PilhaMin::PilhaMin::vazio(){
    return (pilhaPrincipal.size()>0);
}

template <typename Agregado, typename Tipo>
concept PilhaMinimoTAD = requires(Agregado c, Tipo t)
{
    // requer operação de consulta ao elemento 'fim'
    {c.topo()};
    // requer operação 'insereFim' sobre tipo 't'
    {c.empilha(t)};
    // requer operação 'removeFim' e retorna tipo 't'
    {c.desempilha()};
};
// testa de PilhaMin está de acordocomoTAD
static_assert(PilhaMinimoTAD<PilhaMin, int>);