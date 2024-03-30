//
// Created by Luis on 21/03/2024.
//

#include "TableHashGruoup.h"
#include <iostream>

TableHashGruoup::TableHashGruoup() {
    iniciliarItems();
}

void TableHashGruoup::push(std::string &key, TableHashAttributes *&tableHashAtributes) {
    validarDimension();
    int index = f.getIndice(f.valueHash(key), this->tam);
    if (items[index] != nullptr) {
        printf("hubo una colision de grupo\n");
        if (items[index]->key == key) {
            std::cout << "El grupo " << key << " ya existe." << std::endl;
            return;
        } else {
            for (int i = 0; i < tam; ++i) {
                if (items[i] == nullptr) {
                    items[i] = new ItemHsGroup();
                    items[i]->key = key;
                    items[i]->tableAtributes = tableHashAtributes;
                    return;
                }
            }
        }

    }
    items[index] = new ItemHsGroup();
    items[index]->key = key;
    items[index]->tableAtributes = tableHashAtributes;

}

void TableHashGruoup::addColision(std::string &key, TableHashAttributes *&tableHashAtributes) {
    for (int i = 0; i < tam; ++i) {
        if (items[i] == nullptr) {
            items[i] = new ItemHsGroup();
            items[i]->key = key;
            items[i]->tableAtributes = tableHashAtributes;
            return;
        }
    }
}

void TableHashGruoup::redimensionar(int &longitud) {
    int size = 10;
    setTam(size);
    printf("Longitud nueva: %d\n", tam);
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

ItemHsGroup *TableHashGruoup::getItemGroup(std::string &nameGruoup) {
    int index = f.getIndice(f.valueHash(nameGruoup), this->tam);
    ItemHsGroup *itemHsGroup = nullptr;
    if (items[index] != nullptr) {
        if (items[index]->key == nameGruoup) {
            return items[index];
        }
    }
    for (int i = 0; i < tam; ++i) {
        if (items[i] != nullptr) {
            if (items[i]->key == nameGruoup) {
                itemHsGroup = items[i];
                break;
            }
        }
    }
    return itemHsGroup;
}