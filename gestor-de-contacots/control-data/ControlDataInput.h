//
// Created by Luis on 24/03/2024.
//

#ifndef GESTOR_DE_CONTACOTS_CONTROLDATAINPUT_H
#define GESTOR_DE_CONTACOTS_CONTROLDATAINPUT_H

#include <string>
#include "../list/List.h"

class ControlDataInput {
public:
    ControlDataInput();

    List lista;
    List listaAtributos;
    Atributo *atributo;
    std::string tipos[4];
    std::string acciones[3];
    std::string tipoAccion;
    std::string nameGruop;
    int i;

    void analizarContenido(std::string content);

    void analizarCadena(std::string content);

    void establecerAcciones();

};


#endif //GESTOR_DE_CONTACOTS_CONTROLDATAINPUT_H
