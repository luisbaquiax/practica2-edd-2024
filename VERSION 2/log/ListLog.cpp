//
// Created by Luis on 27/03/2024.
//

#include "ListLog.h"

void ListLog::insert(Log *&nuevo) {
    Log *log = new Log(nuevo->fechaHora, nuevo->tipoAccion);
    log->next = nuevo->next;
    log->previous = nuevo->previous;
    if (initial == nullptr) {
        initial = end = nuevo;
        size++;
    } else {
        Log *temp = initial;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = nuevo;
        nuevo->previous = temp;
        end = nuevo;
        end->next = nullptr;
        size++;
    }
}

std::string ListLog::getAllData() {
    std::string content;
    Log *temp = initial;
    while (temp != nullptr) {
        content.append(temp->getInfo());
        temp = temp->next;
    }
    return content;
}