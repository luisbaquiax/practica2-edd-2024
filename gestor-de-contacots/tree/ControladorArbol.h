//
// Created by Luis on 23/03/2024.
//

#ifndef GESTOR_DE_CONTACOTS_CONTROLADORARBOL_H
#define GESTOR_DE_CONTACOTS_CONTROLADORARBOL_H
#include <string>

#include "../atributo/Atributo.h"
#include "../tree/Tree.h"
#include "../funcionHash/FuncionHash.h"


class ControladorArbol {
public:
    FuncionHash f;

    void insertar(Tree *arbol, Atributo *&nuevoAtributo);

    void balancear(Tree *arbol, Atributo *nodo);

    bool isEmpaty();

    int aluturaDeUnNodo(Atributo *nodo);


    int factorDeBalaceo(Atributo *nodo);

    void rotacionIzquierda(Tree *arbol, Atributo *nodo);

    void rotacionDerecha(Tree *arbol, Atributo *nodo);

    void rotacionIzquierdaIzquierda(Tree *arbol, Atributo *nodo);

    void rotacionDerechaDerecha(Tree *arbol, Atributo *nodo);

    void generRecursivo(Atributo *nodo, std::string &conent);

    std::string generarGrapvhiz(Tree *a);

    void liberarMemrorira(Tree *arbol);

    void liberarMemoriaNodos(Atributo *nodo);

};


#endif //GESTOR_DE_CONTACOTS_CONTROLADORARBOL_H
