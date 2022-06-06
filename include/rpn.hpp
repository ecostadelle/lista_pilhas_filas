#ifndef _RPN_HPP_
#define _RPN_HPP_

#include "pilhaDeque.hpp"

int verificaPrecedencia(char);
void operando(char *, int *, char);
void fechaParentese(PilhaDeque *, char *, int *);
void limpa(PilhaDeque *, char *, int *);
void polonesa(char *, int, char *);
void desempilha(PilhaDeque *, char *, int *);
void empilha(PilhaDeque *, char);

#include "rpn.cpp"

#endif