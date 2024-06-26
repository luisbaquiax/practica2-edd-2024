//
// Created by Luis on 22/03/2024.
//

#ifndef GESTOR_DE_CONTACOTS_ITEMHSATTRIBUTES_H
#define GESTOR_DE_CONTACOTS_ITEMHSATTRIBUTES_H

#include "../atributo/Atributo.h"
#include "string"
#include "../tree/Tree.h"

class ItemHsAttributes {
public:
    std::string key;
    std::string typeName;
    int id;
    Tree *tree;

    void printKeyId();
};


#endif //GESTOR_DE_CONTACOTS_ITEMHSATTRIBUTES_H
