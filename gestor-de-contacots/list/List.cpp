//
// Created by Luis on 25/03/2024.
//

#include "List.h"

void List::addFinal(Atributo *&nuevo) {
    Atributo *agregando = new Atributo(nuevo->tipo, nuevo->valor);
    agregando->id = nuevo->id;
    agregando->next = nuevo->next;
    agregando->previous = nuevo->previous;
    if (isEmpity()) {
        initial = agregando;
        end = agregando;
        size++;
    } else {
        Atributo *temp = initial;
        while (temp->nextList != nullptr) {
            temp = temp->nextList;
        }
        temp->nextList = agregando;
        agregando->previousList = temp;
        end = agregando;
        //actualizamos el siguiente del nuevo.
        end->nextList = nullptr;
        size++;
    }
}

bool List::isEmpity() {
    return initial == nullptr;
}

Atributo *List::getByIndex(int index) {
    Atributo *temp = initial;
    int contador = 0;
    while (temp != nullptr) {
        if (contador == index) {
            break;
        }
        temp = temp->nextList;
        contador++;
    }
    return temp;
}

void List::vaciarLista() {
    size=0;
    Atributo *temp = initial;
    while (temp != nullptr) {
        delete temp;
        temp = temp->nextList;
    }
    initial = nullptr;
}

void List::printList() {
    Atributo *temp = initial;
    while (temp != nullptr) {
        temp->printInfo();
        temp = temp->nextList;
    }
}