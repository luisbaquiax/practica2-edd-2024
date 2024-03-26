//
// Created by Luis on 25/03/2024.
//

#ifndef GESTOR_DE_CONTACOTS_LIST_H
#define GESTOR_DE_CONTACOTS_LIST_H

#include "Nodo.h"
#include <iostream>

template<typename T>
class List {
public:
    Nodo<T> *initial;
    Nodo<T> *end;

    List() : size(0), initial(nullptr), end(nullptr) {}

    int size;

    void addFinal(T *&nuevo);

    bool isEmpity();

};


#endif //GESTOR_DE_CONTACOTS_LIST_H
