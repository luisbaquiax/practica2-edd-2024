//
// Created by Luis on 26/03/2024.
//

#ifndef GESTOR_DE_CONTACOTS_MENU_H
#define GESTOR_DE_CONTACOTS_MENU_H

#include "../contact-manager/ContanctManager.h"
#include "../report/Report.h"
#include "../control-data/ControlDataInput.h"
class Menu {
public:
    ContanctManager contanctManager;
    Report report;
    ControlDataInput dataInput;

    void menuPrincipapl();

    void createGruoup();

    void insertContact();

    void searchContact();

    void menuReports();

    void graficas();

    void exportContacts();

    void verCantidadDatosPorGrupo();

    void verCantidadDatosDelSistema();

    void verCantidadContactosPorGrupo();

    void verExportarArchivoLog();

    void printGroups();

    void generarGraficaUnGrupo();

    void generarGraficaUnGrupoArboles();

    void generarGraficaGrupos();
};


#endif //GESTOR_DE_CONTACOTS_MENU_H
