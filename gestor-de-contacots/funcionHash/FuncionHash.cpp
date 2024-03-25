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
    /*char chars[cadena.length() + 1];
    cadena.copy(chars, cadena.length() + 1);
    for (const char &number : chars) {
        auxi += number;
    }
    return auxi;*/
    const char *caracters = cadena.c_str();
    for (int i = 0; i < cadena.length(); ++i) {
        auxi += (int) (caracters[i]);
    }
    return auxi;
}