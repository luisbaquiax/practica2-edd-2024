//
// Created by Luis on 22/03/2024.
//

#include "TableHashAttributes.h"
#include <iostream>

void TableHashAttributes::push(std::string key, Tree *&tree) {
    auto *itemsAtt = new ItemHsAttributes();
    itemsAttributes[funcionHash.getIndice(funcionHash.valueHash(key),size)]= itemsAtt;
    itemsAtt->key = key;
    itemsAtt->tree = tree;
}

void TableHashAttributes::inicializar(int &tam) {
    int tamanio = tam;
    size = tamanio * 2;
    std::cout << "tamaño inicial: " + size << std::endl;
    itemsAttributes = new ItemHsAttributes *[size];
    for (int i = 0; i < size; ++i) {
        itemsAttributes[i] = nullptr;
    }
}

void TableHashAttributes::setSize(int &number) {
    size = size + number;
}

ItemHsAttributes *TableHashAttributes::getItemAttribute(std::string &key) {
    return itemsAttributes[funcionHash.getIndice(funcionHash.valueHash(key), size)];
}