//
// Created by Luis on 21/03/2024.
//

#include "Atributo.h"
#include <iostream>

std::string Atributo::getString() {
    return "id: "+std::to_string(id) + " Tipo: " + tipo + " Valor: " + valor
           + " Factor equilibrio: " + std::to_string(factorEquilibrio);
}

void Atributo::printInfo() {
    std::cout << getString() << std::endl;
}

std::string Atributo::getInfoNextPrevious() {
    std::string content;
    Atributo *tem = this;
    while (tem != nullptr) {
        content += tem->tipo + ": " + tem->valor + ", ";
        tem = tem->next;
    }
    Atributo *aux2 = this;
    aux2 = aux2->previous;
    while (aux2 != nullptr) {
        content += aux2->tipo + ": " + aux2->valor + ", ";
        aux2 = aux2->previous;
    }
    return content;
}