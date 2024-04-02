//
// Created by Luis on 26/03/2024.
//

#ifndef GESTOR_DE_CONTACOTS_LOG_H
#define GESTOR_DE_CONTACOTS_LOG_H

#include "string"

class Log {
public:

    Log(const std::string &fechaHora,
        const std::string &tipoAccion) :
            fechaHora(fechaHora), tipoAccion(tipoAccion), next(nullptr), previous(nullptr) {};
    Log *next;
    Log *previous;


    std::string fechaHora;
    std::string tipoAccion;

    std::string getInfo();
};


#endif //GESTOR_DE_CONTACOTS_LOG_H
