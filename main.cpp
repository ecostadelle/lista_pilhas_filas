#include <iostream>
#include <string>

using namespace std;

#include "dequeSequencial.hpp"
#include "dequeEncadeado.hpp"
#include "rpn.hpp"
/*
template <typename Agregado, typename Tipo>
concept bool dequeTAD = requires(Agregado a, Tipo t) {
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
*/

int main()
{
    char saida[17];
    polonesa((char *)"A+B*C/(E-F)", 12, &saida[0]);
    cout << "A+B*C/(E-F) = ABC*EF-/+"
         << " executado " 
         << saida << endl;
    return 0;
}

// write a function that calcule a factorial
