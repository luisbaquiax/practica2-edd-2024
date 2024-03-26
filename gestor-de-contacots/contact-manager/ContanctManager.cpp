//
// Created by Luis on 24/03/2024.
//

#include "ContanctManager.h"
#include <iostream>
#include "../list/List.h"

ContanctManager::ContanctManager() {
    cantidadContactos = 0;
}

/**
 * nameGroup is the key of a Group
 * @param nameGruop
 * @param listAtributos
 */
void ContanctManager::createGruop(std::string &nameGruop, Atributo **&listAtributos, int tam) {
    Atributo **list = listAtributos;

    printf("Creando grupo... nombre: ");
    std::cout << nameGruop << std::endl;

    TableHashAttributes *table = getTableAttributes(list, tam);
    hashGruoup.push(nameGruop, table);

    ItemHsGroup *itemHsGroup = hashGruoup.getItemGroup(nameGruop);
    itemHsGroup->listNameAttributes = new std::string *[tam];
    itemHsGroup->tamNamesAttributes = tam;
    //agregamos el nombre
    for (int i = 0; i < tam; ++i) {
        itemHsGroup->listNameAttributes[i] = &listAtributos[i]->valor;
    }
}

TableHashAttributes *ContanctManager::getTableAttributes(Atributo **&listAttributes, int tam) {
    auto *tableHast = new TableHashAttributes();
    tableHast->inicializar(tam);
    for (int i = 0; i < tam; ++i) {
        Tree *tree = new Tree();
        tableHast->push(listAttributes[i]->valor, tree);
    }
    return tableHast;
}

void ContanctManager::insertContact(std::string &nameGruop, Atributo **&listAtributos, int tam) {
    std::cout << "insertando en el grupo: " << nameGruop << std::endl;
    //enlazamos los nodos tanto su siguiente y su anterior
    for (int i = 0; i < tam - 1; ++i) {
        listAtributos[i]->next = listAtributos[i + 1];
        listAtributos[i + 1]->previous = listAtributos[i];
    }
    TableHashAttributes *table = hashGruoup.getItemGroup(nameGruop)->tableAtributes;
    ItemHsGroup *itemHsGroup = hashGruoup.getItemGroup(nameGruop);

    if (tam == itemHsGroup->tamNamesAttributes) {
        printf("ingresando contacto... tamNamesAttributes: %d\n", itemHsGroup->tamNamesAttributes);
        for (int i = 0; i < tam; ++i) {
            Atributo *nuevo = listAtributos[i];
            //agreamos los datos al arbol correspondiente
            controladorArbol.insertar(table->getItemAttribute(listAtributos[i]->tipo)->tree, nuevo);
            cantidadContactos++;
        }
    } else {
        printf("No se puede ingresar el contacto.\n");
        printf("La lista de atributos nuevos no conicide con el tamanio del listado de atributos\n");
    }

}

void ContanctManager::searchContact(std::string &nameGruop, Atributo *&buscando) {
    List *listado = new List();

    ItemHsGroup *group = hashGruoup.getItemGroup(nameGruop);

    if (group != nullptr) {
        ItemHsAttributes *tabAttri = group->tableAtributes->getItemAttribute(buscando->tipo);
        if (tabAttri != nullptr) {
            std::cout << "Contactos encontrados del grupo: " << nameGruop << std::endl;
            Atributo *auxi = tabAttri->tree->raiz;
            if (auxi->valor == buscando->valor) {
                listado->addFinal(auxi);
            }
            searchContactRecursive(buscando, auxi, listado);
            Atributo *tem = listado->initial;
            while (tem != nullptr) {
                std::cout << tem->getInfoNextPrevious() << std::endl;
                tem = tem->nextList;
            }
        } else {
            std::cout << "No existe datos con el parametro: "
                      << buscando->tipo << " = "
                      << buscando->valor << std::endl;
        }
    } else {
        std::cout << "No existe el grupo " << nameGruop << std::endl;
    }
}

void ContanctManager::searchContactRecursive(Atributo *buscando, Atributo *nodo, List *&list) {
    if (nodo != nullptr) {
        if (nodo->left != nullptr) {
            if (nodo->left->valor == buscando->valor) {
                //Atributo *nuevo = nodo->left;
                list->addFinal(nodo->left);
            }
        }
        if (nodo->right != nullptr) {
            //Atributo *nuevo = nodo->right;
            if (nodo->right->valor == buscando->valor) {
                list->addFinal(nodo->right);
            }
        }
    }
}