//
// Created by Luis on 25/03/2024.
//

#ifndef GESTOR_DE_CONTACOTS_LIST_H
#define GESTOR_DE_CONTACOTS_LIST_H

#include <iostream>
#include "../atributo/Atributo.h"
class List {
public:
    Atributo *initial;
    Atributo *end;

    List() : size(0), initial(nullptr), end(nullptr) {}

    int size;

    void addFinal(Atributo *&nuevo);

    bool isEmpity();

    void printList();

};


#endif //GESTOR_DE_CONTACOTS_LIST_H
