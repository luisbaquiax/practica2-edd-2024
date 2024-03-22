#include <iostream>
#include <vector>
#include "funcionHash/FuncionHash.h"

using std::cout;
using std::endl;
using std::vector;

int main() {
    FuncionHash f;
    std::string hola = "hola";
    cout<<f.valueHash(hola)<< endl;

    return EXIT_SUCCESS;
}