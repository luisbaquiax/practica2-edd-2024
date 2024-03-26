//
// Created by Luis on 25/03/2024.
//

#include "List.h"
#include <iostream>

template<typename T>

void List<T>::addFinal(T *&nuevo) {
    Nodo<T> *nodo = new Nodo<T>(nuevo);
    if(isEmpity()){
        initial = nodo;
        end = nodo;
        size++;
    }else{
        end->next = nodo;
        nodo->previous = end;
        end = nodo;
        size++;
    }
}

template<typename T>
bool List<T>::isEmpity() {
    return initial == nullptr;
}