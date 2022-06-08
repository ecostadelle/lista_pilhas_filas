#include "inverteP1P.hpp"

void inverteP1P(std::stack<char>* p) { 
    std::stack<char> p1; // uma pilha auxiliar 
    // mais espaço auxiliar constante 

    int size = p->size();
    char espacoAuxiliar;

    while(--size > 0) {
        espacoAuxiliar = p->top();
        p->pop();
        for (int i = 0; i < size; i++) {
            p1.push(p->top());
            p->pop();
        }
        p->push(espacoAuxiliar);
        while (!p1.empty()) {
            p->push(p1.top());
            p1.pop();
        }
    } 
} 