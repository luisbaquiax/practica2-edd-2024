//
// Created by Luis on 24/03/2024.
//

#include "ControlArchivo.h"
#include <iostream>
#include<string>
#include <fstream>

using namespace std;

void ControlArchivo::generarImagen(std::string &content) {
    ofstream file("../graph.dot");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
    } else {
        file << content << endl;

        file.close();

        system("dot -Tpng ../graph.dot -o ../graph.png");

        cout << "Gráfico generado correctamente." << endl;
    }

}

void ControlArchivo::generarCarpeta(std::string &ruta) {

}

void ControlArchivo::generarArchivos(std::string &ruta, std::string &content) {}