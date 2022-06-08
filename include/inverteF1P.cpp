#include <stack>
#include <queue>
#include "inverteF1P.hpp"  

void inverteF1P(std::queue<char>* f) { 
    // somente essa pilha e mais espaço auxiliar constante
    std::stack<char> p;

    while (!f->empty()) {
        p.push(f->front());
        f->pop();
    }
    while (!p.empty()) {
        f->push(p.top());
        p.pop();
    }
}