//
// Created by Luis on 21/03/2024.
//

#ifndef GESTOR_DE_CONTACTOS_TABLEHASH_H
#define GESTOR_DE_CONTACTOS_TABLEHASH_H

#include "string"
#include "../table-hash-attributes/TableHashAttributes.h"
#include "../item-hash-table/ItemHsGroup.h"
#include "../funcionHash/FuncionHash.h"

class TableHashGruoup {
public:
    ItemHsGroup **items;
    FuncionHash f;
    int tam;

    //constructor
    TableHashGruoup();

    //functions
    void push(std::string &key, TableHashAttributes *&tableHashAtributes);

    void addColision(std::string &key, TableHashAttributes *&tableHashAtributes);

    void redimensionar(int &longitud);

    void validarDimension();

    void iniciliarItems();

    int getSizeItems();

    void setTam(int &number);

    ItemHsGroup *getItemGroup(std::string &nameGruoup);
};


#endif //GESTOR_DE_CONTACTOS_TABLEHASH_H
