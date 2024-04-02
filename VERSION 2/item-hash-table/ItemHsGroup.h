//
// Created by Luis on 22/03/2024.
//

#ifndef GESTOR_DE_CONTACOTS_ITEMHSGROUP_H
#define GESTOR_DE_CONTACOTS_ITEMHSGROUP_H

#include "string"
#include "../table-hash-attributes/TableHashAttributes.h"

class ItemHsGroup {
public:
    ItemHsGroup() : tamNamesAttributes(0), tableAtributes(nullptr), listNameAttributes(nullptr) {
        key = "";
    };

    std::string key;
    int tamNamesAttributes;
    std::string **listNameAttributes;
    TableHashAttributes *tableAtributes;

    void setListNames(std::string **listNames) {
        listNameAttributes = listNames;
    };
};


#endif //GESTOR_DE_CONTACOTS_ITEMHSGROUP_H
