//
// Created by Luis on 24/03/2024.
//

#include "ContanctManager.h"
#include <iostream>

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
    for (int i = tam - 1; i >= 1; --i) {
        listAtributos[i]->previous = listAtributos[i - 1];
        listAtributos[i-1]->next = listAtributos[i];
    }
    printf("atributos... tamNamesAttributes: %d\n", tam);

    for (int i = 0; i < tam; ++i) {
        std::cout << listAtributos[i]->getString() << std::endl;
    }
    TableHashAttributes *table = hashGruoup.getItemGroup(nameGruop)->tableAtributes;

    printf("ingresando contacto... tamNamesAttributes: %d\n", table->size);
    for (int i = 0; i < tam; ++i) {
        Atributo *nuevo = listAtributos[i];
        nuevo->next = listAtributos[i]->next;
        nuevo->previous = listAtributos[i]->previous;
        //agreamos los datos al arbol correspondiente
        controladorArbol.insertar(table->getItemAttribute(listAtributos[i]->tipo)->tree, nuevo);
        cantidadContactos++;
        /*for (int j = 0; j < table->size; ++j) {
            if (table->itemsAttributes[j] != nullptr) {
                printf("pos: %d ", j);
                std::cout << table->itemsAttributes[j]->key << std::endl;
                if (listAtributos[i]->tipo == table->itemsAttributes[j]->key) {
                    controladorArbol.insertar(table->itemsAttributes[j]->tree, nuevo);
                    break;
                }
            }
        }*/
    }
}