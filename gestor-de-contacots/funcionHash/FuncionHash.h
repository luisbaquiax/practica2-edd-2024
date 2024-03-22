//
// Created by Luis on 21/03/2024.
//

#ifndef GESTOR_DE_CONTACTOS_FUNCIONHASH_H
#define GESTOR_DE_CONTACTOS_FUNCIONHASH_H
#include "string"

class FuncionHash {
public:
    int getIndice(int value, int capacity);
    int valueHash(std:: string &cadena);
};


#endif //GESTOR_DE_CONTACTOS_FUNCIONHASH_H
