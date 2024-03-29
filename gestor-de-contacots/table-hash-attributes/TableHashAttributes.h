//
// Created by Luis on 22/03/2024.
//

#ifndef GESTOR_DE_CONTACOTS_TABLEHASHATTRIBUTES_H
#define GESTOR_DE_CONTACOTS_TABLEHASHATTRIBUTES_H

#include "../item-hash-table/ItemHsAttributes.h"
#include "../funcionHash/FuncionHash.h"
#include "../tree/Tree.h"

class TableHashAttributes {
public:
    TableHashAttributes();

    FuncionHash funcionHash;
    ItemHsAttributes **itemsAttributes;

    int size;
    int contadorId;

    void push(std::string key, Tree *&tree);

    void setSize(int &number);

    void inicializar(int &tam);

    ItemHsAttributes *getItemAttribute(std::string &nameAttribute);

    ItemHsAttributes *getItemAttributeByID(int id);

};


#endif //GESTOR_DE_CONTACOTS_TABLEHASHATTRIBUTES_H
