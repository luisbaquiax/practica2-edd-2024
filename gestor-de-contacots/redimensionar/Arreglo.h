//
// Created by Luis on 21/03/2024.
//

#ifndef GESTOR_DE_CONTACTOS_ARREGLO_H
#define GESTOR_DE_CONTACTOS_ARREGLO_H


class Arreglo {
public:
    int *numeros[5];
    void inicializar();
    void redimnesionarArreglo(int *arrayOriginal[]);
    void imprimir(int *array[], int tam);
};


#endif //GESTOR_DE_CONTACTOS_ARREGLO_H
