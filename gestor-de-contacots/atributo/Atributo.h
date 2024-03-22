//
// Created by Luis on 21/03/2024.
//

#ifndef GESTOR_DE_CONTACTOS_ATRIBUTO_H
#define GESTOR_DE_CONTACTOS_ATRIBUTO_H

#include "string"

class Atributo {
public:
    //para ver su siguiente dato
    Atributo *next;
    Atributo *previous;
    //para el arbol
    Atributo *left;
    Atributo *right;

    std::string tipo;
    std::string valor;

    Atributo(const std::string &tipo,
             const std::string &valor) :
            left(nullptr),
            right(nullptr) {}

    std::string getString();
};


#endif //GESTOR_DE_CONTACTOS_ATRIBUTO_H
