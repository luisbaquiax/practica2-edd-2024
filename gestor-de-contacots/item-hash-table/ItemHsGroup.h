//
// Created by Luis on 22/03/2024.
//

#ifndef GESTOR_DE_CONTACOTS_ITEMHSGROUP_H
#define GESTOR_DE_CONTACOTS_ITEMHSGROUP_H

#include "string"
#include "../table-hash-attributes/TableHashAttributes.h"

class ItemHsGroup {
public:
    std::string key;
    int tamNamesAttributes;
    std::string **listNameAttributes;
    TableHashAttributes *tableAtributes;
};


#endif //GESTOR_DE_CONTACOTS_ITEMHSGROUP_H
