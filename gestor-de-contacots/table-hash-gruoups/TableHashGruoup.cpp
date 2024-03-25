//
// Created by Luis on 21/03/2024.
//

#include "TableHashGruoup.h"
#include <iostream>

TableHashGruoup::TableHashGruoup() {
    iniciliarItems();
}

void TableHashGruoup::push(std::string key, TableHashAttributes *&tableHashAtributes) {
    int index = f.getIndice(f.valueHash(key), this->tam);
    items[index] = new ItemHsGroup();
    items[index]->key = key;
    items[index]->tableAtributes = tableHashAtributes;
}

void TableHashGruoup::redimensionar(int &longitud) {
    printf("redimensionando\n");
    int size = 10;
    setTam(size);
    printf("longitud nueva: %d\n", tam);
    ItemHsGroup **auxiItems = new ItemHsGroup *[tam];
    for (int i = 0; i < longitud - 10; ++i) {
        auxiItems[i] = items[i];
    }
    delete[] items;
    items = auxiItems;
}

void TableHashGruoup::validarDimension() {
    int contador = 0;

    for (int i = 0; i < this->tam; ++i) {
        if (items[i] != nullptr) {
            contador++;
        }
    }
    if ((contador) > (0.6 * this->tam)) {
        printf("Al 60%, espacio disponible %d\n", (this->tam - contador));
        //redimnesionar
        redimensionar(tam);
    } else {
        printf("Hay suficiente espacio, espacios disponibles %d\n", (this->tam - contador));
    }
}

void TableHashGruoup::iniciliarItems() {
    tam = 5;
    items = new ItemHsGroup *[tam];
    std::cout << "Longitud inicial: " << tam << std::endl;
    for (int i = 0; i < tam; ++i) {
        items[i] = nullptr;
    }
}

int TableHashGruoup::getSizeItems() {
    return this->tam;
}

void TableHashGruoup::setTam(int &number) {
    tam = tam + number;
}

ItemHsGroup *TableHashGruoup::getItemGroup(std::string key) {
    return items[f.getIndice(f.valueHash(key), this->tam)];
}