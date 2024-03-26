//
// Created by Luis on 26/03/2024.
//

#include "Report.h"
#include <iostream>

Report::Report() {
    cantidad = 0;
}

void Report::cantidadDatosPorGrupo(std::string &nameGroup, ContanctManager contanctManager) {
    TableHashGruoup grupos = contanctManager.hashGruoup;
    //verificamos el contenido de la lista de grupos
    if (grupos.getItemGroup(nameGroup) != nullptr) {
        auto listado = grupos.getItemGroup(nameGroup)->listNameAttributes;
        for (int j = 0; j < grupos.getItemGroup(nameGroup)->tamNamesAttributes; ++j) {
            std::string tipo = *listado[j];
            auto itemAtributes = grupos.getItemGroup(nameGroup)->tableAtributes->getItemAttribute(tipo);
            Tree *auxi = itemAtributes->tree;
            cantidad += auxi->idNodo;
        }
    }
}

void Report::cantidadDatosDelSistema(ContanctManager contanctManager) {
    TableHashGruoup grupos = contanctManager.hashGruoup;
    for (int i = 0; i < grupos.tam; ++i) {
        if (grupos.items[i] != nullptr) {
            cantidadDatosPorGrupo(grupos.items[i]->key, contanctManager);
        }
    }
}

void Report::cantidadContactosPorGrupo(std::string &nameGroup, ContanctManager contanctManager) {
    TableHashGruoup grupos = contanctManager.hashGruoup;
    //verificamos el contenido de la lista de grupos
    if (grupos.getItemGroup(nameGroup) != nullptr) {
        auto listado = grupos.getItemGroup(nameGroup)->listNameAttributes;
        for (int j = 0; j < grupos.getItemGroup(nameGroup)->tamNamesAttributes; ++j) {
            std::string tipo = *listado[j];
            auto itemAtributes = grupos.getItemGroup(nameGroup)->tableAtributes->getItemAttribute(tipo);
            Tree *auxi = itemAtributes->tree;
            cantidad = auxi->idNodo;
        }
    }
    std::cout << "Cantidad de contactos del grupo " << nameGroup << ": " << cantidad << std::endl;
    cantidad = 0;
}