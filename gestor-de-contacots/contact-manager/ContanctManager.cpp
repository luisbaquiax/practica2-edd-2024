//
// Created by Luis on 24/03/2024.
//

#include "ContanctManager.h"
#include <iostream>
#include "../list/List.h"
#include <chrono>
#include <ctime>

ContanctManager::ContanctManager() {
    cantidadContactos = 0;
    hashGruoup.iniciliarItems();
}

/**
 * nameGroup is the key of a Group
 * @param nameGruop
 * @param listAtributos
 */
void ContanctManager::createGruop(std::string &nameGruop, Atributo **&listAtributos, int tam) {
    Atributo **list = listAtributos;


    printf("\n");
    printf("Creando grupo... nombre: ");
    std::cout << nameGruop << std::endl;

    TableHashAttributes *table = getTableAttributes(list, tam);

    hashGruoup.push(nameGruop, table);

    ItemHsGroup *itemHsGroup = hashGruoup.getItemGroup(nameGruop);
    if (itemHsGroup != nullptr) {
        auto **listadoNombres = new std::string *[tam];
        itemHsGroup->tamNamesAttributes = tam;
        //agregamos el nombre de los atributos
        for (int i = 0; i < tam; ++i) {
            listadoNombres[i] = &listAtributos[i]->valor;
        }
        hashGruoup.getItemGroup(nameGruop)->setListNames(listadoNombres);
        printf("Nombre de los atributos que se ingresan \n");
        for (int i = 0; i < hashGruoup.getItemGroup(nameGruop)->tamNamesAttributes; ++i) {
            std::cout << *hashGruoup.getItemGroup(nameGruop)->listNameAttributes[i] << std::endl;
        }
        printf("\n");
        Log *log = new Log(getFechaHora(), "Creacion del grupo " + nameGruop);
        listLog.insert(log);
    }
}

TableHashAttributes *ContanctManager::getTableAttributes(Atributo **&listAttributes, int tam) {
    auto *tableHast = new TableHashAttributes();
    tableHast->inicializar(tam);
    for (int i = 0; i < tam; ++i) {
        Tree *tree = new Tree();
        tree->idNodo = 0;
        tableHast->push(listAttributes[i]->valor, tree);
    }
    return tableHast;
}

void ContanctManager::insertContact(std::string &nameGruop, Atributo **&listAtributos, int tam) {
    std::cout << "insertando en el grupo: " << nameGruop << std::endl;
    printf("\n");

    //enlazamos los nodos tanto su siguiente y su anterior
    for (int i = 0; i < tam - 1; ++i) {
        listAtributos[i]->next = listAtributos[i + 1];
        listAtributos[i + 1]->previous = listAtributos[i];
    }
    TableHashAttributes *tableAttribute = hashGruoup.getItemGroup(nameGruop)->tableAtributes;
    ItemHsGroup *itemHsGroup = hashGruoup.getItemGroup(nameGruop);

    if (tam == itemHsGroup->tamNamesAttributes) {

        printf("ingresando contacto... tamNamesAttributes: %d\n", itemHsGroup->tamNamesAttributes);
        for (int i = 0; i < tam; ++i) {
            //agregamos el grupo al que pertenece
            listAtributos[i]->nameGroup = nameGruop;

            //creamos un objeto Atributo para agregar al arbol correspondiente
            Atributo *nuevo = listAtributos[i];
            //imprimimos su informacion
            listAtributos[i]->printInfo();

            //agregamos los datos al arbol correspondiente
            controladorArbol.insertar(tableAttribute->getItemAttribute(listAtributos[i]->tipo)->tree, nuevo);
            cantidadContactos++;
        }
        Log *log = new Log(getFechaHora(),
                           "Insercion de contacto en el grupo " + nameGruop);
        listLog.insert(log);
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
            std::cout << "Contactos encontrados con "
                      << buscando->tipo << " = "
                      << buscando->valor
                      << " del grupo: " << nameGruop << std::endl;
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
            Log *log = new Log(getFechaHora(), "Busqueda de contacto en el grupo " + nameGruop);
            listLog.insert(log);
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
                searchContactRecursive(buscando, nodo->left, list);
            }
        }
        if (nodo->right != nullptr) {
            //Atributo *nuevo = nodo->right;
            if (nodo->right->valor == buscando->valor) {
                list->addFinal(nodo->right);
                searchContactRecursive(buscando, nodo->right, list);
            }
        }
    }
}

void ContanctManager::generateFileByGruop(std::string &nameGruop) {
    ItemHsGroup *itemHsGroup = hashGruoup.getItemGroup(nameGruop);
    if (itemHsGroup != nullptr) {

        Log *log = new Log(getFechaHora(), "Exportacion de contactos del grupo " + nameGruop);
        listLog.insert(log);

        auto *listaNames = itemHsGroup->listNameAttributes;
        Tree *arbol = itemHsGroup->tableAtributes->getItemAttribute(*listaNames[0])->tree;
        Atributo *auxi = arbol->raiz;

        controlArchivo.generarCarpeta(nameGruop);

        std::string content;
        std::string name;
        name += std::to_string(auxi->id) + " " + nameGruop + auxi->valor + ".txt";
        content = auxi->getInfoNextPrevious();

        controlArchivo.generarArchivos(nameGruop, name, content);

        generarFileRecursive(auxi, nameGruop);

    } else {
        std::cout << "No existe el grupo " << nameGruop << std::endl;
    }
}

void ContanctManager::generarFileRecursive(Atributo *nodo, std::string &nameGroup) {
    if (nodo != nullptr) {
        std::string content;
        std::string name;

        if (nodo->left != nullptr) {
            name += std::to_string(nodo->left->id) + " " + nameGroup + nodo->left->valor + ".txt";
            content = nodo->left->getInfoNextPrevious();
            controlArchivo.generarArchivos(nameGroup, name, content);

            generarFileRecursive(nodo->left, nameGroup);
        }
        content = "";
        name = "";
        if (nodo->right != nullptr) {
            name += std::to_string(nodo->right->id) + " " + nameGroup + nodo->right->valor + ".txt";
            content = nodo->right->getInfoNextPrevious();
            controlArchivo.generarArchivos(nameGroup, name, content);

            generarFileRecursive(nodo->right, nameGroup);
        }
    }
}

/**
 * grupo1[id="grupo1", label="grupo1"]
 * @param content
 */
void ContanctManager::generateLabelsGroups(std::string &content) {
    for (int i = 0; i < hashGruoup.tam; ++i) {
        if (hashGruoup.items[i] != nullptr) {
            content += hashGruoup.items[i]->key
                       + "[id=\"" + hashGruoup.items[i]->key + "\", label=\"" + hashGruoup.items[i]->key + "\"];\n";
        }
    }
}

/**
 * Crea un label de cada atributo de un grupo en especifico
 * grupo1NombreAtributo[id="grupo1NombreAtributo", label="NombreAtributo"]
 * @param content
 * @param nameGroup
 */
void ContanctManager::generateLabelsAttributes(std::string &content, std::string &nameGroup) {
    for (int i = 0; i < hashGruoup.getItemGroup(nameGroup)->tableAtributes->size; ++i) {
        if (hashGruoup.getItemGroup(nameGroup)->tableAtributes->itemsAttributes[i] != nullptr) {
            content.append(
                    nameGroup + hashGruoup.getItemGroup(nameGroup)->tableAtributes->itemsAttributes[i]->key);
            content.append(
                    "[id=\"" +
                    nameGroup + hashGruoup.getItemGroup(nameGroup)->tableAtributes->itemsAttributes[i]->key);
            content.append(
                    +"\", label=\"" +
                    hashGruoup.getItemGroup(nameGroup)->tableAtributes->itemsAttributes[i]->key);
            content.append(+"\"];\n");
        }
    }
}

/**
 * Crea enlaces de un grupo y sus atributos, ejemplo: grupo1 -> grupo1NombreAtributo
 * @param content
 * @param nameGroup
 */
void ContanctManager::generarEnlaceGruposAtributos(std::string &content, std::string &nameGroup) {
    for (int i = 0; i < hashGruoup.getItemGroup(nameGroup)->tableAtributes->size; ++i) {
        if (hashGruoup.getItemGroup(nameGroup)->tableAtributes->itemsAttributes[i] != nullptr) {
            content.append(nameGroup);
            content.append("->");
            content.append(nameGroup);
            content.append(hashGruoup.getItemGroup(nameGroup)->tableAtributes->itemsAttributes[i]->key);
            //content.append(std::to_string(i));
            content.append(";\n");
        }
    }
}

/**
 * Genera enlaces de todos los grupos con sus atributos
 * @param content
 */
void ContanctManager::generarEnlaceGruposAtributosAll(std::string &content) {
    for (int i = 0; i < hashGruoup.tam; ++i) {
        if (hashGruoup.items[i] != nullptr) {
            generarEnlaceGruposAtributos(content, hashGruoup.items[i]->key);
        }
    }
}

void ContanctManager::generarEnlaceArboles(std::string &content, std::string &nameGroup) {
    for (int i = 0; i < hashGruoup.getItemGroup(nameGroup)->tableAtributes->size; ++i) {
        if (hashGruoup.getItemGroup(nameGroup)->tableAtributes->itemsAttributes[i] != nullptr) {
            content.append(nameGroup);

            content.append(hashGruoup.getItemGroup(nameGroup)->tableAtributes->itemsAttributes[i]->key);
            content.append("->");
            Tree *arbol = hashGruoup.getItemGroup(nameGroup)->tableAtributes->getItemAttribute(
                    hashGruoup.getItemGroup(nameGroup)
                            ->tableAtributes->itemsAttributes[i]->key)->tree;
            Atributo *raiz = arbol->raiz;
            content.append(raiz->getIdString() + ";\n");
            content.append(controladorArbol.generarGrapvhiz(arbol));
        }
    }
}

std::string ContanctManager::generarGraphizUnGrupo(std::string &nameGrup) {
    std::string content;
    //content.append("digraph ArbolBinario {\n");
    std::string *key = hashGruoup.getItemGroup(nameGrup)->listNameAttributes[0];
    int size = hashGruoup.getItemGroup(nameGrup)->tableAtributes->getItemAttribute(*key)->tree->idNodo;
    if (size > 0) {
        generateLabelsAttributes(content, nameGrup);
        generarEnlaceGruposAtributos(content, nameGrup);
        generarEnlaceArboles(content, nameGrup);
    }
    //content.append("}\n");
    return content;
}

std::string ContanctManager::generarGraphizUnGrupoExceptoArboles(std::string &nameGroup) {
    std::string content;
    content.append("digraph ArbolBinario {\n");
    int size = hashGruoup.getItemGroup(nameGroup)->tableAtributes->size;
    if (size > 0) {
        generateLabelsAttributes(content, nameGroup);
        generarEnlaceGruposAtributos(content, nameGroup);
    }
    content.append("}\n");
    Log *log = new Log(getFechaHora(), "Crear grafica de estructura del grupo " + nameGroup);
    listLog.insert(log);
    return content;
}

std::string ContanctManager::generarGraphizTodosGrupos() {
    std::string contenido;
    contenido.append("digraph ArbolBinario {\n");
    contenido.append("GRUPOS[id=\"GRUPOS\"");
    contenido.append(", label=\"GRUPOS\"];\n");
    for (int i = 0; i < hashGruoup.tam; ++i) {
        if (hashGruoup.items[i] != nullptr) {
            std::string *key = hashGruoup.items[i]->listNameAttributes[0];
            int size = hashGruoup.items[i]->tableAtributes->getItemAttribute(*key)->tree->idNodo;
            generateLabelsAttributes(contenido, hashGruoup.items[i]->key);
            generarEnlaceGruposAtributos(contenido, hashGruoup.items[i]->key);
            if (size > 0) {
                generarEnlaceArboles(contenido, hashGruoup.items[i]->key);
            }
            contenido.append("GRUPOS->");
            contenido.append(hashGruoup.items[i]->key);
            contenido.append(";\n");
        }
    }
    contenido.append("}\n");
    Log *log = new Log(getFechaHora(), "Generar grafica de toda la estructura ");
    listLog.insert(log);
    return contenido;
}

std::string ContanctManager::getFechaHora() {
    auto now = std::chrono::system_clock::now();
    std::time_t endTime = std::chrono::system_clock::to_time_t(now);
    return ctime(&endTime);
}

void ContanctManager::printInfoGroup(std::string &nameGroup) {
    printf("Grupos: \n");
    for (int i = 0; i < hashGruoup.tam; ++i) {
        if (hashGruoup.items[i] != nullptr) {
            std::cout << "Grupo: " << hashGruoup.items[i]->key << std::endl;
            for (int j = 0; j < hashGruoup.getItemGroup(hashGruoup.items[i]->key)->tableAtributes->size; ++j) {
                //std::cout << "Atributo> " << *hashGruoup.items[i]->listNameAttributes[j] << std::endl;
                if (hashGruoup.getItemGroup(hashGruoup.items[i]->key)->tableAtributes->itemsAttributes[j] != nullptr) {
                    std::cout << "Atributo> "
                              << hashGruoup.getItemGroup(
                                      hashGruoup.items[i]->key)->tableAtributes->itemsAttributes[j]->key << std::endl;
                }
            }
        }
    }
    std::cout << "Grupo: " << nameGroup << std::endl;
    TableHashAttributes *t = hashGruoup.getItemGroup(nameGroup)->tableAtributes;
    for (int j = 0; j < t->size; ++j) {
        if (t->itemsAttributes[j] != nullptr) {
            std::cout << "key del arbol: "
                      << hashGruoup.getItemGroup(nameGroup)->tableAtributes->itemsAttributes[j]->key
                      << " indice: " << hashGruoup.getItemGroup(nameGroup)->tableAtributes->itemsAttributes[j]->id
                      << std::endl;
        }
    }
}