//
// Created by Luis on 22/03/2024.
//

#include "TableHashAttributes.h"
#include <iostream>

TableHashAttributes::TableHashAttributes() {
    size = 0;
    contadorId = 0;
}

void TableHashAttributes::push(std::string key, Tree *&tree) {
    auto *itemsAtt = new ItemHsAttributes();
    int index = funcionHash.getIndice(funcionHash.valueHash(key), size);

    contadorId++;

    if (itemsAttributes[index] != nullptr) {
        printf("hubo una colision de atributos\n");
        for (int i = 0; i < size; ++i) {
            if (itemsAttributes[i] == nullptr) {
                itemsAtt->key = key;
                itemsAtt->tree = tree;
                itemsAtt->id = contadorId;
                itemsAttributes[i] = itemsAtt;
                break;
            }
        }
    } else {
        itemsAtt->key = key;
        itemsAtt->tree = tree;
        itemsAtt->id = contadorId;
        itemsAttributes[index] = itemsAtt;
    }

}

void TableHashAttributes::inicializar(int &tam) {
    contadorId = 0;
    size = tam * 3;
    std::cout << "size inicial de TableHashAttributes: " << size << std::endl;
    itemsAttributes = new ItemHsAttributes *[size];
    for (int i = 0; i < size; ++i) {
        itemsAttributes[i] = nullptr;
    }
}

void TableHashAttributes::setSize(int &number) {
    size = size + number;
}

/**
 * Busca la referencia del arbol del atributo especificado
 * @param nameAttribute is the key
 * @return
 */
ItemHsAttributes *TableHashAttributes::getItemAttribute(std::string &nameAttribute) {
    int index = funcionHash.getIndice(funcionHash.valueHash(nameAttribute), size);
    //printf("index buscado: %d\n", index);
    ItemHsAttributes *itemHsAttributes = nullptr;
    if (itemsAttributes[index] != nullptr) {
        if (itemsAttributes[index]->key == nameAttribute) {
            itemHsAttributes = itemsAttributes[index];
            return itemHsAttributes;
        }
    }
    for (int i = 0; i < size; ++i) {
        if (itemsAttributes[i] != nullptr) {
            if (itemsAttributes[i]->key == nameAttribute) {
                itemHsAttributes = itemsAttributes[i];
                break;
            }
        }
    }
    return itemHsAttributes;
}

ItemHsAttributes *TableHashAttributes::getItemAttributeByID(int id) {
    printf("id: %d", id);
    for (int i = 0; i < size; ++i) {
        if(itemsAttributes[i]!= nullptr){
            if (itemsAttributes[i]->id == id) {
                std::cout << "key: " << itemsAttributes[i]->key << std::endl;
                return itemsAttributes[i];
            }
        }
    }
    printf("no encontramos nada \n");
    return nullptr;
}