//
// Created by Luis on 24/03/2024.
//

#include "ControlArchivo.h"
#include <iostream>
#include<string>
#include <fstream>
#include <filesystem>
#include <cstdlib> /

#ifdef _WIN32

#include <direct.h> // Para Windows

#define mkdir _mkdir
#else
#include <sys/stat.h> // Para sistemas basados en Unix
#endif

using namespace std;
namespace fs = std::filesystem;


using namespace std;

void ControlArchivo::generarImagen(std::string &ruta, std::string &content) {
    string path = "../contactos/" + ruta;
    ofstream file(path + ".dot");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
    } else {
        file << content << endl;

        file.flush();

        file.close();
        string comando;
        comando += "dot -Tpng  " + path + ".dot -o " + path + ".png";
        system(comando.c_str());
        //system("dot -Tpng ../graph.dot -o ../graph.png");

        cout << "Gráfico generado correctamente." << endl;
    }

}

void ControlArchivo::generarCarpeta(std::string ruta) {
    // Crear una carpeta
    string folderName = "../contactos/";
    folderName += ruta;
    if (fs::exists(folderName) && fs::is_directory(folderName)) {
        cout << "La carpeta ya existe." << endl;
    } else {
        //Creamos la carpeta.
#ifdef _WIN32
        int folderCreated = mkdir(folderName.c_str());
#else
        int folderCreated = mkdir(folderName.c_str(), 0777); // Permisos en sistemas Unix
#endif

        if (folderCreated == 0) {
            cout << "Carpeta creada correctamente." << endl;
        } else {
            cout << "Error al crear la carpeta. Es posible que ya exista" << endl;
        }
    }
}

void ControlArchivo::generarArchivos(std::string carpeta, std::string nombreArchivo, std::string &content) {
    string ruta = "../contactos/";
    // Crear un archivo de texto dentro de la carpeta
    ruta += carpeta + "/" + nombreArchivo;
    ofstream outputFile(ruta);
    if (outputFile.is_open()) {
        outputFile << content << endl;
        outputFile.flush();
        outputFile.close();
        cout << "Archivo creado correctamente." << endl;
    } else {
        cout << "Error al crear el archivo." << endl;
    }
}