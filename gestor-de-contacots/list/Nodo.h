//
// Created by Luis on 25/03/2024.
//

#ifndef GESTOR_DE_CONTACOTS_NODO_H
#define GESTOR_DE_CONTACOTS_NODO_H

#include <iostream>

template<typename T>
class Nodo {
public:
    T dato;

    Nodo(T dato) : next(nullptr), previous(nullptr) {}

    Nodo *next;
    Nodo *previous;

};


#endif //GESTOR_DE_CONTACOTS_NODO_H
