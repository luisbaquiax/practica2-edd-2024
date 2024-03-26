//
// Created by Luis on 21/03/2024.
//

#include "FuncionHash.h"
#include <iostream>

int FuncionHash::getIndice(int value, int capacity) {
    return value % capacity;
}

int FuncionHash::valueHash(std::string &cadena) {
    int auxi = 0;

    const char *caracters = cadena.c_str();
    for (int i = 0; i < cadena.length(); ++i) {
        auxi += (int) (caracters[i]);
    }
    return auxi;
}