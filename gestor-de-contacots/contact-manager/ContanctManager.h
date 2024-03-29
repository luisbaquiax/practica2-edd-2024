//
// Created by Luis on 24/03/2024.
//

#ifndef GESTOR_DE_CONTACOTS_CONTANCTMANAGER_H
#define GESTOR_DE_CONTACOTS_CONTANCTMANAGER_H

#include <string>

#include "../table-hash-gruoups/TableHashGruoup.h"
#include "../item-hash-table/ItemHsGroup.h"
#include "../tree/ControladorArbol.h"
#include "../list/List.h"
#include "../control-archivo/ControlArchivo.h"
#include "../log/ListLog.h"
#include "../log/Log.h"

class ContanctManager {
private:
    TableHashAttributes *getTableAttributes(Atributo **&listAttributes, int tam);

public:
    ContanctManager();

    int cantidadContactos;
    TableHashGruoup hashGruoup;
    ControladorArbol controladorArbol;

    ControlArchivo controlArchivo;
    ListLog listLog;

    void createGruop(std::string &nameGruop, Atributo **&listAtributos, int tam);

    void insertContact(std::string &nameGruop, Atributo **&listAtributos, int tam);

    void searchContact(std::string &nameGruop, Atributo *&buscando);

    void searchContactRecursive(Atributo *buscando, Atributo *nodo, List *&list);

    void generateFileByGruop(std::string &nameGruop);

    void generarFileRecursive(Atributo *nodo, std::string &nameGroup);

    void generateLabelsGroups(std::string &content);

    void generateLabelsAttributes(std::string &content, std::string &nameGroup);

    void generarEnlaceGruposAtributos(std::string &content, std::string &nameGroup);

    void generarEnlaceGruposAtributosAll(std::string &content);

    void generarEnlaceArboles(std::string &content, std::string &nameGroup);

    std::string generarGraphizUnGrupo(std::string &nameGroup);

    std:: string generarGraphizUnGrupoExceptoArboles(std::string &nameGroup);

    std::string generarGraphizTodosGrupos();

    std::string getFechaHora();
};


#endif //GESTOR_DE_CONTACOTS_CONTANCTMANAGER_H
