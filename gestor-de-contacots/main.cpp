#include <iostream>
#include <string>
#include <vector>
#include "funcionHash/FuncionHash.h"
#include "table-hash-gruoups/TableHashGruoup.h"
#include "tree/Tree.h"
#include "tree/ControladorArbol.h"
#include "control-archivo/ControlArchivo.h"
#include "contact-manager/ContanctManager.h"
#include "list/List.h"
#include "report/Report.h"
#include "control-archivo/ControlArchivo.h"

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

    Atributo **list2 = new Atributo *[tam];
    list2[0]= new Atributo("DATE", "fecha");
    list2[1]= new Atributo("STRING", "fecha");
    list2[2]= new Atributo("NUMBER", "fecha");
    list2[3]= new Atributo("NUMBER", "fecha");
    list2[4]= new Atributo("DATE", "fecha");
    std::string key = "amigos";
    std::string key2 = "doctores";
    c.createGruop(key, list, tam);
    c.createGruop(key2,list2,tam);

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
    Tree *arbol2 = c.hashGruoup.getItemGroup(key)->tableAtributes->getItemAttribute(contactos[4]->tipo)->tree;
    std::cout << a.generarGrapvhiz(arbol) << std::endl;
    std::cout << a.generarGrapvhiz(arbol1) << std::endl;
    std::cout << a.generarGrapvhiz(arbol2) << std::endl;

     Atributo *auxi = arbol1->raiz;
     /*auxi->printInfo();
     if(auxi->previous!= nullptr){
         auxi->previous->printInfo();
     }else{
         printf("es nulo\n");
     }*/

    /*Report report;
    report.cantidadDatosPorGrupo(key, c);
    std::cout << "Cantidad de datos en el grupo " << key << ": " << report.cantidad << std::endl;
    report.cantidad = 0;

    report.cantidadDatosDelSistema(c);
    std::cout << "Cantidad de datos del sistema: " << report.cantidad << std::endl;
    report.cantidad = 0;
    report.cantidadContactosPorGrupo(key,c);*/


  /*  List listado;
    Atributo *atributo = new Atributo  ("hola","hola");
    Atributo *atributo1 = new Atributo  ("hola","hola");
    Atributo *atributo2 = new Atributo  ("hola","hola");
    listado.addFinal(nodo1);
    listado.addFinal(nodo1);
    listado.addFinal(nodo1);
    listado.printList();*/

    //c.searchContact(key,contactos[4]);

    /* for (int i = 0; i <  c.hashGruoup.tam; ++i) {
        if(c.hashGruoup.items[i]!= nullptr){
            std::cout<<c.hashGruoup.items[i]->key<<endl;
        }
    }*/
    c.generateFileByGruop(key);
    return EXIT_SUCCESS;
}