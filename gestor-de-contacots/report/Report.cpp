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
        for (int j = 0; j < grupos.getItemGroup(nameGroup)->tableAtributes->size; ++j) {
            if (grupos.getItemGroup(nameGroup)->tableAtributes->itemsAttributes[j] != nullptr) {
                Tree *auxi = grupos.getItemGroup(nameGroup)->tableAtributes->itemsAttributes[j]->tree;
                cantidad += auxi->idNodo;
            }
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
        for (int j = 0; j < grupos.getItemGroup(nameGroup)->tableAtributes->size; ++j) {
            if (grupos.getItemGroup(nameGroup)->tableAtributes->itemsAttributes[j] != nullptr) {
                Tree *auxi = grupos.getItemGroup(nameGroup)->tableAtributes->itemsAttributes[j]->tree;
                cantidad = auxi->idNodo;
            }
        }
    }
    std::cout << "Cantidad de contactos del grupo " << nameGroup << ": " << cantidad << std::endl;
    cantidad = 0;
}

void Report::generarArchivoLog(ContanctManager contanctManager) {
    contanctManager.controlArchivo.generarCarpeta("log-sistema");
    std::string content = contanctManager.listLog.getAllData();
    printf("//----------------------HISTORIAL DEL SISTEMA//----------------------\n");
    std::cout << content << std::endl;
    contanctManager.controlArchivo.generarArchivos("log-sistema", "log.txt", content);
}