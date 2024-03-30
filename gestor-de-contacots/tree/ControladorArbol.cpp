//
// Created by Luis on 23/03/2024.
//

#include "ControladorArbol.h"
#include <iostream>

void ControladorArbol::insertar(Tree *arbol, Atributo *&nuevoAtributo) {
    Atributo *auxi;
    Atributo *anterior;

    if (arbol->raiz == nullptr) {
        arbol->raiz = nuevoAtributo;
        arbol->idNodo++;
        nuevoAtributo->id = arbol->idNodo;
    } else {
        arbol->idNodo++;
        nuevoAtributo->id = arbol->idNodo;
        auxi = arbol->raiz;
        while (auxi != nullptr) {
            anterior = auxi;
            if (nuevoAtributo->valor.compare(auxi->valor) > 0) {
                auxi = auxi->right;
            } else {
                auxi = auxi->left;
            }
        }
        nuevoAtributo->father = anterior;
        if (nuevoAtributo->valor.compare(anterior->valor) > 0) {
            anterior->right = nuevoAtributo;
        } else {
            anterior->left = nuevoAtributo;
        }
        balancear(arbol, anterior);
    }
}

void ControladorArbol::balancear(Tree *arbol, Atributo *nodo) {
    Atributo *padre;
    if (nodo != nullptr) {
        padre = nodo->father;
        nodo->factorEquilibrio = factorDeBalaceo(nodo);
        //cuano existe un desequilibrio por la derecha
        if (nodo->factorEquilibrio > 1) {
            if (factorDeBalaceo(nodo->right) < 0) {
                rotacionIzquierdaIzquierda(arbol, nodo);
            } else {
                rotacionIzquierda(arbol, nodo);
            }
        } else if (nodo->factorEquilibrio < -1) {
            if (factorDeBalaceo(nodo->left) > 0) {
                rotacionDerechaDerecha(arbol, nodo);
            } else {
                rotacionDerecha(arbol, nodo);
            }
        }
        balancear(arbol, padre);
    }
}

bool ControladorArbol::isEmpaty() {
    return true;
}

int ControladorArbol::aluturaDeUnNodo(Atributo *nodo) {
    if (nodo != nullptr) {
        int hDerecho = aluturaDeUnNodo(nodo->right);
        int hIzquierdo = aluturaDeUnNodo(nodo->left);
        if (hDerecho > hIzquierdo) {
            return hDerecho + 1;
        } else {
            return hIzquierdo + 1;
        }
    } else {
        return 0;
    }
}

/**
 * FB = Altura subárbol derecho - Altura subárbol izquierdo
 * @param nodo
 * @return
 */
int ControladorArbol::factorDeBalaceo(Atributo *nodo) {
    if (nodo != nullptr) {
        return aluturaDeUnNodo(nodo->right) - aluturaDeUnNodo(nodo->left);
    } else {
        return 0;
    }
}

void ControladorArbol::rotacionIzquierda(Tree *arbol, Atributo *nodo) {
    Atributo *auxi;
    Atributo *izquierdaAuxi;
    Atributo *padreNodo;

    auxi = nodo->right;
    izquierdaAuxi = auxi->left;
    padreNodo = nodo->father;

    nodo->right = izquierdaAuxi;
    auxi->left = nodo;

    if (izquierdaAuxi != nullptr) {
        izquierdaAuxi->father = nodo;
    }
    nodo->father = auxi;
    auxi->father = padreNodo;

    if (padreNodo == nullptr) {
        arbol->raiz = auxi;
    } else {
        if (auxi->valor.compare(padreNodo->valor) > 0) {
            padreNodo->right = auxi;
        } else {
            padreNodo->left = auxi;
        }
    }
    auxi->factorEquilibrio = factorDeBalaceo(auxi);
    nodo->factorEquilibrio = factorDeBalaceo(nodo);
}

void ControladorArbol::rotacionDerecha(Tree *arbol, Atributo *nodo) {
    Atributo *auxi;
    Atributo *derechaAuxi;
    Atributo *padreNodo;

    auxi = nodo->left;
    derechaAuxi = auxi->right;
    padreNodo = nodo->father;

    if (derechaAuxi != nullptr) {
        derechaAuxi->father = nodo;
    }
    nodo->father = auxi;
    auxi->father = padreNodo;

    if (padreNodo == nullptr) {
        arbol->raiz = auxi;
    } else {
        if (auxi->valor.compare(padreNodo->valor) > 0) {
            padreNodo->right = auxi;
        } else {
            padreNodo->left = auxi;
        }
    }
    auxi->factorEquilibrio = factorDeBalaceo(auxi);
    nodo->factorEquilibrio = factorDeBalaceo(nodo);
}

void ControladorArbol::rotacionIzquierdaIzquierda(Tree *arbol, Atributo *nodo) {
    rotacionDerecha(arbol, nodo->right);
    rotacionIzquierda(arbol, nodo);
}

void ControladorArbol::rotacionDerechaDerecha(Tree *arbol, Atributo *nodo) {
    rotacionIzquierda(arbol, nodo->left);
    rotacionDerecha(arbol, nodo);
}

/**
 * Metodo para gener el contendio que necesita Graphiz en formato string
 * @param nodo
 * @param conent
 */
void ControladorArbol::generRecursivo(Atributo *nodo, std::string &conent) {

    if (nodo != nullptr) {
        nodo->printInfo();
        if (nodo->left != nullptr) {
            conent += nodo->getIdString() + "->" + nodo->left->getIdString() + ";\n";
            generRecursivo(nodo->left, conent);
        }
        if (nodo->right != nullptr) {
            conent += nodo->getIdString() + "->" + nodo->right->getIdString() + ";\n";
            generRecursivo(nodo->right, conent);
        }
    }
}

void ControladorArbol::generarCadenaRecursivo(Atributo *nodo, std::string &conent) {
    if (nodo != nullptr) {
        if (nodo->left != nullptr) {
            conent += nodo->left->getIdString()
                      + "[id=\"" + nodo->left->getIdString() + "\", label=\"" + nodo->left->valor + "\"];\n";
            generarCadenaRecursivo(nodo->left, conent);
        }
        if (nodo->right != nullptr) {
            conent += nodo->right->getIdString()
                      + "[id=\"" + nodo->right->getIdString() + "\", label=\"" + nodo->right->valor + "\"];\n";
            generarCadenaRecursivo(nodo->right, conent);
        }
    }
}

std::string ControladorArbol::generarGrapvhiz(Tree *a) {
    std::string content;
    Atributo *aux = a->raiz;
    //content += "digraph ArbolBinario {\n";
    content += aux->getIdString()
               + "[id=\"" + aux->getIdString() + "\", label=\"" + aux->valor + "\"];\n";
    //content += aux->getIdString() + ";\n";
    generarCadenaRecursivo(aux, content);
    generRecursivo(aux, content);
    //content += "}";
    return content;
}

void ControladorArbol::liberarMemrorira(Tree *arbol) {

}

void ControladorArbol::liberarMemoriaNodos(Atributo *nodo) {

}

void ControladorArbol::printInformacion(Tree *arbol) {
    Atributo *auxi = arbol->raiz;
    std::cout << auxi->getInfoNextPrevious() << std::endl;
    printInformacionRecursivo(auxi);
}

void ControladorArbol::printInformacionRecursivo(Atributo *nodo) {
    if (nodo != nullptr) {
        if (nodo->left != nullptr) {
            std::cout << nodo->left->getInfoNextPrevious() << std::endl;
        }
        if (nodo->right != nullptr) {
            std::cout << nodo->right->getInfoNextPrevious() << std::endl;
        }
    }
}