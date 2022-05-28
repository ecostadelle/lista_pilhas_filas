#ifndef _RPN_H
#define _RPN_H

#include "pilhaDeque.h"

void operando(char *, int *, char);
int verificaPrecedencia(char);
void fechaParentese(PilhaDeque *, char *, int *);
void limpa(PilhaDeque *, char *, int *);
void polonesa(char *, int, char *);
void desempilha(PilhaDeque *, char *, int *);
void empilha(PilhaDeque *, char);

#include "rpn.cpp"

#endif