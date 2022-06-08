#include "inverteF2F.hpp"

void inverteF2F(std::queue<char>* f) { 
    std::queue<char> f1; // primeira fila auxiliar 
    std::queue<char> f2; // segunda fila auxiliar 
    // mais espaço auxiliar constante 

    int size = f->size();

    while (--size > 0){
        for (int i = 0; i < size; i++) {
            f2.push(f->front());
            f->pop();
        }
        f1.push(f->front());
        f->pop();
        while (!f2.empty()) {
            f->push(f2.front());
            f2.pop();
        }
    }
    f1.push(f->front());
    f->pop();
    while (!f1.empty()) {
        f->push(f1.front());
        f1.pop();
    }
}