//
// Created by Luis on 24/03/2024.
//

#include "ControlDataInput.h"
#include <iostream>
#include "string"

using namespace std;

ControlDataInput::ControlDataInput() {
    tipos[0] = "INTEGER";
    tipos[0] = "STRING";
    tipos[0] = "CHAR";
    tipos[0] = "DATE";

    acciones[0] = "ADD NEW-GROUP";
    acciones[1] = "ADD NEW-CONTACT";
    acciones[2] = "SEARCH CONTACT";

    i = 0;
    tipoAccion = "";
    nameGruop = "";
    atributo = new Atributo();
}

void ControlDataInput::analizarContenido(std::string content) {
    i = 0;
    std::cout << content << endl;
    while (i < content.length()) {
        analizarCadena(content);
        i++;
    }
    i = 0;
}

void ControlDataInput::analizarCadena(std::string content) {
    string word;
    while (i < content.length()) {
        if (isspace(content[i]) || content[i] == '(' || content[i] == ')' || content[i] == ','
            || content[i] == ';' || content[i] == '=') {
            break;
        }
        word += content[i];
        i++;
    }
    //std::cout << "word " << word << " " << word.length() << endl;
    if (!word.empty()) {
        Atributo *a = new Atributo("", word);
        lista.addFinal(a);
    }
    word = "";
}

void ControlDataInput::establecerAcciones() {
    int index = 0;
    if (lista.getByIndex(0)->valor == "ADD" && lista.getByIndex(1)->valor == "NEW-GROUP") {
        tipoAccion = acciones[0];
        nameGruop = lista.getByIndex(2)->valor;
        index += 4;
        while (index < lista.size - 1) {
            Atributo *a = new Atributo();
            a->valor = lista.getByIndex(index)->valor;
            index++;
            a->tipo = lista.getByIndex(index)->valor;
            listaAtributos.addFinal(a);
            index++;
        }
    } else if (lista.getByIndex(0)->valor == "ADD" && lista.getByIndex(1)->valor == "CONTACT") {
        tipoAccion = acciones[1];
        nameGruop = lista.getByIndex(3)->valor;
        index += 5;
        while (index < lista.size) {
            Atributo *a = new Atributo();
            a->valor = lista.getByIndex(index)->valor;
            listaAtributos.addFinal(a);
            index++;
        }
    } else if (lista.getByIndex(0)->valor == "FIND" && lista.getByIndex(1)->valor == "CONTACT") {

        tipoAccion = acciones[2];
        atributo = new Atributo();
        nameGruop = lista.getByIndex(3)->valor;
        atributo->tipo = lista.getByIndex(5)->valor;
        atributo->valor = lista.getByIndex(6)->valor;
    }
    /* printf("imprimiento lista....\n");
     lista.printList();
     printf("imprimiento listaAtributos....\n");
     listaAtributos.printList();
     printf("...\n");*/
}



