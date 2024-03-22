//
// Created by Luis on 21/03/2024.
//

#include "FuncionHash.h"

int FuncionHash::getIndice(int value, int capacity) {
    return value % capacity;
}

int FuncionHash::valueHash(std::string &cadena) {
    int auxi = 0;
    char chars[cadena.length() + 1];
    cadena.copy(chars, cadena.length() + 1);
    for (const int &number : chars) {
        auxi += number;
    }
    return auxi;
}