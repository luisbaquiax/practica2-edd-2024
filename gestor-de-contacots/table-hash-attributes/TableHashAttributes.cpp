//
// Created by Luis on 22/03/2024.
//

#include "TableHashAttributes.h"
#include <iostream>

TableHashAttributes::TableHashAttributes() {
}

void TableHashAttributes::push(std::string key, Tree *&tree) {
    auto *itemsAtt = new ItemHsAttributes();
    int index = funcionHash.getIndice(funcionHash.valueHash(key), size);
    if (itemsAttributes[index] != nullptr) {
        printf("hubo una colision de atributos\n");
        for (int i = 0; i < size; ++i) {
            if (itemsAttributes[i] == nullptr) {
                itemsAtt->key = key;
                itemsAtt->tree = tree;
                itemsAttributes[i] = itemsAtt;
                break;
            }
        }
    } else {
        itemsAtt->key = key;
        itemsAtt->tree = tree;
        itemsAttributes[index] = itemsAtt;
    }

}

void TableHashAttributes::inicializar(int &tam) {
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
 * @param key
 * @return
 */
ItemHsAttributes *TableHashAttributes::getItemAttribute(std::string &key) {
    int index = funcionHash.getIndice(funcionHash.valueHash(key), size);
    //printf("index buscado: %d\n", index);
    ItemHsAttributes *itemHsAttributes = nullptr;
    if (itemsAttributes[index] != nullptr) {
        if (itemsAttributes[index]->key == key) {
            itemHsAttributes = itemsAttributes[index];
            return  itemHsAttributes;
        }
    }
    for (int i = 0; i < size; ++i) {
        if (itemsAttributes[i] != nullptr) {
            if (itemsAttributes[i]->key == key) {
                itemHsAttributes = itemsAttributes[i];
                break;
            }
        }
    }
    return itemHsAttributes;
}