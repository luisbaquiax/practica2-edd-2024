//
// Created by Luis on 27/03/2024.
//

#ifndef GESTOR_DE_CONTACOTS_LISTLOG_H
#define GESTOR_DE_CONTACOTS_LISTLOG_H

#include "Log.h"

class ListLog {
public:
    ListLog() : size(0), initial(nullptr), end(nullptr) {};

    Log *initial;
    Log *end;
    int size;

    void insert(Log *&nuevo);

    std::string getAllData();

};


#endif //GESTOR_DE_CONTACOTS_LISTLOG_H
