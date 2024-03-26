//
// Created by Luis on 26/03/2024.
//

#ifndef GESTOR_DE_CONTACOTS_REPORT_H
#define GESTOR_DE_CONTACOTS_REPORT_H
#include "string"

#include "../contact-manager/ContanctManager.h"

class Report {
public:
    Report();
    int cantidad;
    void cantidadDatosPorGrupo(std::string &nameGroup, ContanctManager contanctManager);
    void cantidadDatosDelSistema(ContanctManager contanctManager);
    void cantidadContactosPorGrupo(std::string &nameGroup, ContanctManager contanctManager);
};


#endif //GESTOR_DE_CONTACOTS_REPORT_H
