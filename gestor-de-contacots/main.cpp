#include <iostream>
#include "string"
#include <vector>
#include "funcionHash/FuncionHash.h"
#include "table-hash-gruoups/TableHashGruoup.h"
#include "tree/Tree.h"
#include "tree/ControladorArbol.h"
#include "control-archivo/ControlArchivo.h"

using std::cout;
using std::endl;
using std::vector;

int main() {
    FuncionHash f;

    TableHashGruoup t;
    Tree *ar = new Tree();
    ControladorArbol a;

    Atributo *nodo1 = new Atributo("DATE", "1");

    Atributo *nodo2 = new Atributo("CADENA", "b");

    Atributo *nodo3 = new Atributo("STRING", "c");
    Atributo *nodo4 = new Atributo("NUMBER", "fcc");
    Atributo *nodo5 = new Atributo("DATE", "g");

     a.insertar(ar, nodo1);
     a.insertar(ar, nodo2);
     a.insertar(ar, nodo3);
     a.insertar(ar, nodo4);
     a.insertar(ar, nodo5);
     cout<<a.generarGrapvhiz(ar)<<endl;
     ControlArchivo archivo;
     std::string  content = a.generarGrapvhiz(ar);
     archivo.generarImagen(content);

    return EXIT_SUCCESS;
}