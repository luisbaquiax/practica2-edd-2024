//
// Created by Luis on 21/03/2024.
//

#include "Atributo.h"
#include <iostream>

std::string Atributo::getString() {
    return std::to_string(id) + " Tipo: " + tipo + " Valor: " + valor
           + " Factor equilibrio: " + std::to_string(factorEquilibrio);
}

void Atributo::printInfo() {
    std::cout << getString() << std::endl;
}