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
    Atributo *father;
    int id;
    int hijosDerecho;
    int hijosIzquierdo;
    int factorEquilibrio;

    std::string tipo;
    std::string valor;

    Atributo(const std::string &tipo,
             const std::string &valor) :
            valor(valor),
            tipo(tipo),
            left(nullptr),
            right(nullptr),
            next(nullptr),
            previous(nullptr),
            father(nullptr) {
        hijosDerecho = 0;
        hijosIzquierdo = 0;
        factorEquilibrio = 0;
        id = 0;
    }

    std::string getString();

    void printInfo();
};


#endif //GESTOR_DE_CONTACTOS_ATRIBUTO_H
