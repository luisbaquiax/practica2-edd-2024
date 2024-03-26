#include <iostream>
#include "string"
#include <vector>
#include "funcionHash/FuncionHash.h"
#include "table-hash-gruoups/TableHashGruoup.h"
#include "tree/Tree.h"
#include "tree/ControladorArbol.h"
#include "control-archivo/ControlArchivo.h"
#include "contact-manager/ContanctManager.h"
#include "list/List.h"
#include "list/Nodo.h"
#include "report/Report.h"

using std::cout;
using std::endl;
using std::vector;

int main() {
    FuncionHash f;

    TableHashGruoup t;
    Tree *ar = new Tree();
    ControladorArbol a;

    Atributo *nodo1 = new Atributo("DATE", "fecha");

    Atributo *nodo2 = new Atributo("STRING", "nombre");

    Atributo *nodo3 = new Atributo("STRING", "apellido");
    Atributo *nodo4 = new Atributo("NUMBER", "edad");
    Atributo *nodo5 = new Atributo("DATE", "otra-fecha");

    int tam = 5;


    ContanctManager c;
    Atributo **list = new Atributo *[tam];
    list[0] = nodo1;
    list[1] = nodo2;
    list[2] = nodo3;
    list[3] = nodo4;
    list[4] = nodo5;


    std::string key = "amigos";
    c.createGruop(key, list, tam);
    std::cout << "nombre del grupo creado: " << c.hashGruoup.getItemGroup(key)->key << std::endl;

    Atributo **contactos = new Atributo *[tam];
    contactos[0] = new Atributo("fecha", "12-12-12");
    contactos[1] = new Atributo("nombre", "luis");
    contactos[2] = new Atributo("apellido", "baquiax");
    contactos[3] = new Atributo("edad", "27");
    contactos[4] = new Atributo("otra-fecha", "12-12-12");

    /*printf("datos a ingresar...\n");
    for (int i = 0; i < tamNamesAttributes; ++i) {
        std::cout << *&contactos[i]->valor << std::endl;
    }
    printf("datos a ingresar...\n");
    */

    TableHashAttributes *table = c.hashGruoup.getItemGroup(key)->tableAtributes;

    c.insertContact(key, contactos, tam);
    Atributo **contactos2 = new Atributo *[tam];
    contactos2[0] = new Atributo("fecha", "12-12-12");
    contactos2[1] = new Atributo("nombre", "luis");
    contactos2[2] = new Atributo("apellido", "baquiax");
    contactos2[3] = new Atributo("edad", "27");
    contactos2[4] = new Atributo("otra-fecha", "12-12-12");

    c.insertContact(key, contactos2, tam);

    //std::cout << "tipo atributo: " << table->getItemAttribute(contactos[1]->tipo)->key << std::endl;

    Tree *arbol = c.hashGruoup.getItemGroup(key)->tableAtributes->getItemAttribute(contactos[0]->tipo)->tree;
    Tree *arbol1 = c.hashGruoup.getItemGroup(key)->tableAtributes->getItemAttribute(contactos[1]->tipo)->tree;
    Tree *arbol2 = c.hashGruoup.getItemGroup(key)->tableAtributes->getItemAttribute(contactos[2]->tipo)->tree;
    std::cout << a.generarGrapvhiz(arbol) << std::endl;
    std::cout << a.generarGrapvhiz(arbol1) << std::endl;
    std::cout << a.generarGrapvhiz(arbol2) << std::endl;

    /* Atributo *auxi = arbol2->raiz;
     std::string datos;
     while (auxi != nullptr) {
         datos += auxi->tipo + ": " + auxi->valor + ", ";
         auxi = auxi->next;
     }
     datos += " ";
     Atributo *aux2 = arbol2->raiz;
     while (aux2->previous != nullptr) {
         datos += aux2->tipo + ": " + aux2->valor + ",";
         aux2 = aux2->previous;
     }
     std::cout << datos << endl;
     */

    /*Report report;
    report.cantidadDatosPorGrupo(key, c);
    std::cout << "Cantidad de datos en el grupo " << key << ": " << report.cantidad << std::endl;
    report.cantidad = 0;

    report.cantidadDatosDelSistema(c);
    std::cout << "Cantidad de datos del sistema: " << report.cantidad << std::endl;
    report.cantidad = 0;
    report.cantidadContactosPorGrupo(key,c);*/
    return EXIT_SUCCESS;
}