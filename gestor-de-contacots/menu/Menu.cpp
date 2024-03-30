//
// Created by Luis on 26/03/2024.
//

#include "Menu.h"
#include <iostream>
#include "string"

using std::cout;
using std::endl;
using namespace std;


void Menu::menuPrincipapl() {
    int opcion = 0;
    do {
        printf("\n\n\n//----------------GESTOR DE CONTACTOS----------------//\n");
        printf("                  [ Mengu principal ]\n");
        printf("1. Crear grupo\n");
        printf("2. Ingresar contacto\n");
        printf("3. Buscar contacto\n");
        printf("4. Reportes\n");
        printf("5. Grafica de estructuras\n");
        printf("6. Exportar contactos\n");
        printf("7. Salir\n");
        printf("Ingrese la opcion:");
        scanf("%d", &opcion);
        if (opcion == 1) {
            createGruoup();
        } else if (opcion == 2) {
            insertContact();
        } else if (opcion == 3) {
            searchContact();
        } else if (opcion == 4) {
            menuReports();
        } else if (opcion == 5) {
            graficas();
        } else if (opcion == 6) {
            exportContacts();
        } else if (opcion == 7) {
            exit(0);
        }
    } while (opcion != 7);

}

void Menu::createGruoup() {
    /* std::string comando;

     std::cout << "Ingresa comando para crear grupo>";
     std::getline(std::cin >> std::ws, comando);
     std::cout << "\nComando ingresado: " << comando << std::endl;
     //analizamos la cadena de entrada
     dataInput.analizarContenido(comando);
     dataInput.establecerAcciones();
     //creamos un array de atributos
     Atributo **list = new Atributo *[dataInput.listaAtributos.size];
     //convertimos la lista atributos a un array
     for (int i = 0; i < dataInput.listaAtributos.size; ++i) {
         list[i] = dataInput.listaAtributos.getByIndex(i);
     }
     //creamos el grupo
     contanctManager.createGruop(dataInput.nameGruop, list, dataInput.listaAtributos.size);
     delete[] list;
     dataInput.listaAtributos.vaciarLista();
     dataInput.lista.vaciarLista();
     dataInput.nameGruop = "";*/

    Atributo *nodo1 = new Atributo("DATE", "fecha");

    Atributo *nodo2 = new Atributo("STRING", "nombre");

    Atributo *nodo3 = new Atributo("STRING", "apellido");
    Atributo *nodo4 = new Atributo("NUMBER", "edad");
    Atributo *nodo5 = new Atributo("DATE", "otraFecha");

    int tam = 5;

    Atributo **list = new Atributo *[tam];
    list[0] = nodo1;
    list[1] = nodo2;
    list[2] = nodo3;
    list[3] = nodo4;
    list[4] = nodo5;

    Atributo **list2 = new Atributo *[tam];
    list2[0] = new Atributo("DATE", "fecha");
    list2[1] = new Atributo("STRING", "nombre");
    list2[2] = new Atributo("NUMBER", "telefono");
    list2[3] = new Atributo("NUMBER", "fecha2");
    list2[4] = new Atributo("DATE", "cumple");
    std::string key = "amigos";
    std::string key2 = "amigos";

    contanctManager.createGruop(key, list, tam);
    contanctManager.createGruop(key2, list2, tam);
}

void Menu::insertContact() {
    /*std::string comando;

    std::cout << "Ingresa comando para registrar contacto>";
    std::getline(std::cin >> std::ws, comando);
    std::cout << "\nComando ingresado: " << comando << std::endl;
    //analizamos la cadena de entrada
    dataInput.analizarContenido(comando);
    dataInput.establecerAcciones();

    std::cout << "\nNombre grupo: " << dataInput.nameGruop << std::endl;
    //creamos el array de atributos del contacto
    Atributo **list = new Atributo *[dataInput.listaAtributos.size];

    printf("Datos del contacto a ingresar: \n");
    for (int i = 0; i < dataInput.listaAtributos.size; ++i) {
        std::cout << dataInput.listaAtributos.getByIndex(i)->getInfoNextPrevious() << std::endl;
    }
    //agreamos
    contanctManager.insertContact(dataInput.nameGruop, list, dataInput.listaAtributos.size);

    dataInput.listaAtributos.vaciarLista();
    dataInput.lista.vaciarLista();
    dataInput.nameGruop = "";*/

    std::string key = "amigos";
    std::string key2 = "doctores";
    int tam = 5;

    Atributo **contactos = new Atributo *[tam];
    contactos[0] = new Atributo("fecha", "12-12-12");
    contactos[1] = new Atributo("nombre", "luis1");
    contactos[2] = new Atributo("apellido", "baquiax1");
    contactos[3] = new Atributo("edad", "27");
    contactos[4] = new Atributo("otraFecha", "12-12-10");

    contanctManager.insertContact(key, contactos, tam);
    Atributo **contactos2 = new Atributo *[tam];
    contactos2[0] = new Atributo("fecha", "2-12-12");
    contactos2[1] = new Atributo("nombre", "luis2");
    contactos2[2] = new Atributo("apellido", "baquiax1");
    contactos2[3] = new Atributo("edad", "28");
    contactos2[4] = new Atributo("otraFecha", "12-12-10");

    contanctManager.insertContact(key, contactos2, tam);

    Atributo **contactos3 = new Atributo *[tam];
    contactos3[0] = new Atributo("fecha", "12-12-11");
    contactos3[1] = new Atributo("nombre", "luis3");
    contactos3[2] = new Atributo("apellido", "diaz");
    contactos3[3] = new Atributo("edad", "25");
    contactos3[4] = new Atributo("otraFecha", "12-12-10");
    for (int i = 0; i < tam; ++i) {
        contactos[i]->printInfo();
        contactos2[i]->printInfo();
        contactos3[i]->printInfo();
    }
    contanctManager.insertContact(key, contactos3, tam);
}

void Menu::searchContact() {
    std::string comando;

    std::cout << "Ingresa el comando para buscar contacto>";
    std::getline(std::cin >> std::ws, comando);
    std::cout << "\nComando ingresado: " << comando << std::endl;

    dataInput.analizarContenido(comando);
    dataInput.establecerAcciones();
    if (dataInput.tipoAccion == dataInput.acciones[2]) {
        string nameGruop = dataInput.nameGruop;
        Atributo *atributo = dataInput.atributo;

        contanctManager.searchContact(nameGruop, atributo);
        dataInput.atributo = new Atributo();
        dataInput.nameGruop = "";
    } else {
        printf("La intrucciones no esta correcta\n");
    }
    dataInput.lista.vaciarLista();
    dataInput.listaAtributos.vaciarLista();
    comando = "";
}

void Menu::menuReports() {
    string grupo = "amigos";
    string nombre = "nombre";
    //Tree *arbol = contanctManager.hashGruoup.getItemGroup(grupo)->tableAtributes->getItemAttribute(nombre)->tree;
    //contanctManager.controladorArbol.printInformacion(arbol);

    int opcion = 0;
    do {
        printf("                  [ Reportes ]\n");
        printf("1. Ver cantidad de datos por grupo\n");
        printf("2. Ver cantidad de datos del sistema\n");
        printf("3. Ver cantidad de contactos por grupo\n");
        printf("4. Ver y exportar archivo LOG\n");
        printf("5. Menu principal\n");
        printf("Ingrese la opcion:");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                verCantidadDatosPorGrupo();
                break;
            case 2:
                verCantidadDatosDelSistema();
                break;
            case 3:
                verCantidadContactosPorGrupo();
                break;
            case 4:
                verExportarArchivoLog();
                break;
            case 5:
                menuPrincipapl();
                break;
            default:
                printf("");
        }
    } while (opcion != 5);
}

void Menu::graficas() {
    int opcion = 0;
    do {
        printf("                  [ Graficas ]\n");
        printf("1. Generar grafica de la estructura completa\n");
        printf("2. Generar grafica de la estructura de un grupo\n");
        printf("3. Generar grafica de toda la estructura y datos de un grupo\n");
        printf("4. Menu principal\n");
        printf("Ingrese la opcion:");
        scanf("%d", &opcion);
        switch (opcion) {
            case 1:
                generarGraficaGrupos();
                break;
            case 2:
                generarGraficaUnGrupo();
                break;
            case 3:
                generarGraficaUnGrupoArboles();
                break;
            case 4:
                menuPrincipapl();
                break;
            default:
                printf("");
        }
    } while (opcion != 4);

}

void Menu::generarGraficaUnGrupo() {
    printGroups();
    string nameGroup;
    cout << "Ingrese el nombre del grupo:";
    cin >> nameGroup;

    Log *log = new Log(contanctManager.getFechaHora(),
                       "Exportacion de grafica sin arboles del grupo " + nameGroup);
    contanctManager.listLog.insert(log);

    std::string content = contanctManager.generarGraphizUnGrupoExceptoArboles(nameGroup);
    nameGroup += "sinarboles";

    contanctManager.controlArchivo.generarImagen(nameGroup, content);

}

void Menu::generarGraficaUnGrupoArboles() {
    printGroups();
    string nameGroup;
    cout << "Ingrese el nombre del grupo:";
    cin >> nameGroup;

    Log *log = new Log(contanctManager.getFechaHora(),
                       "Exportacion de grafica con arboles del grupo " + nameGroup);
    contanctManager.listLog.insert(log);

    std::string graficaGrupo;
    graficaGrupo.append("digraph ArbolBinario {\n");
    graficaGrupo.append(contanctManager.generarGraphizUnGrupo(nameGroup));
    graficaGrupo.append("}\n");
    std::cout << graficaGrupo;
    nameGroup += "conarboles";

    contanctManager.controlArchivo.generarImagen(nameGroup, graficaGrupo);
}

void Menu::generarGraficaGrupos() {
    Log *log = new Log(contanctManager.getFechaHora(),
                       "Exportacion de grafica de toda la estructura");
    contanctManager.listLog.insert(log);
    std::string conten = contanctManager.generarGraphizTodosGrupos();
    string nombre = "todo";
    contanctManager.controlArchivo.generarImagen(nombre, conten);
}

void Menu::exportContacts() {

    printGroups();
    string nameGroup;
    cout << "Ingrese el nombre del grupo para exportar sus contactos>";
    cin >> nameGroup;
    contanctManager.generateFileByGruop(nameGroup);
}

void Menu::printGroups() {
    printf("                  [ Grupos ]\n");
    for (int i = 0; i < contanctManager.hashGruoup.tam; ++i) {
        if (contanctManager.hashGruoup.items[i] != nullptr) {
            std::cout << "Nombre del grupo: " << contanctManager.hashGruoup.items[i]->key << std::endl;
        }
    }
}

void Menu::verCantidadDatosPorGrupo() {
    printf("\n\n\n//----------------Cantidad de datos por grupo----------------//\n");
    for (int i = 0; i < contanctManager.hashGruoup.tam; ++i) {
        if (contanctManager.hashGruoup.items[i] != nullptr) {
            report.cantidadDatosPorGrupo(contanctManager.hashGruoup.items[i]->key, contanctManager);
            std::cout << "Cantidad de datos del grupo "
                      << contanctManager.hashGruoup.items[i]->key
                      << ": "
                      << report.cantidad
                      << std::endl;
            report.cantidad = 0;
        }
    }
}

void Menu::verCantidadDatosDelSistema() {
    printf("\n\n\n//----------------Cantidad de datos del sistema----------------//\n");
    report.cantidadDatosDelSistema(contanctManager);
    std::cout << "Cantidad de datos del sistema"
              << ": "
              << report.cantidad
              << std::endl;
    report.cantidad = 0;
}

void Menu::verCantidadContactosPorGrupo() {
    printf("\n\n\n//----------------Cantidad de contactos por grupo----------------//\n");
    for (int i = 0; i < contanctManager.hashGruoup.tam; ++i) {
        if (contanctManager.hashGruoup.items[i] != nullptr) {
            report.cantidadContactosPorGrupo(contanctManager.hashGruoup.items[i]->key, contanctManager);
        }
    }
}

void Menu::verExportarArchivoLog() {
    report.generarArchivoLog(contanctManager);
}