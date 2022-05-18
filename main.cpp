#include <iostream>
#include <algorithm>

using namespace std;

#include "exercicios.hpp"


int main()
{
    
    dequeSequencial deque;
    for (int i = 0; i<5; i++)
    {
        deque.insereFim(i);
    }
    for (int i = 5; i<10; i++)
    {
        deque.insereInicio(i);
    }
    for (int i = 0; i < 10; i++){
        cout << deque.removeFim() << " ";
        //deque.removeInicio();
    }
    cout << endl;
    
    /*
    char entrada[] = "((A+B)*(C-(F/D)))";
    int n = sizeof(entrada) / sizeof(entrada[0])-1;
    char saida[n];
    polonesa(entrada, n, &saida[0]);
    cout << n << ":" << saida << ":" << entrada << endl;
    std::string preced = "\*\/+-";
    std::sort(preced.begin(), preced.end());
    std::cout << preced << std::endl;
    cout << ('*'-41)%6 << ('+'-41)%6 << ('-'-41)%6 << ('/'-41)%6 << endl;
    */
    return 0;
}
