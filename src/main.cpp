#include <iostream>
#include <string>

//#include "dequeSequencial.hpp"
#include "../include/dequeEncadeado.hpp"
#include "../include/rpn.hpp"

using namespace std;


int main()
{
    char saida[17];
    polonesa((char *)"A+B*C/(E-F)", 12, &saida[0]);
    cout << "A+B*C/(E-F) = ABC*EF-/+"
         << " executado " 
         << saida << endl;
    return 0;
}
