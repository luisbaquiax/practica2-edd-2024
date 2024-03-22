//
// Created by Luis on 21/03/2024.
//

#include "Arreglo.h"
#include <iostream>

void Arreglo::inicializar() {
    for (int i = 0; i < sizeof(numeros) / sizeof(int); ++i) {
        numeros[i] = &i;
        printf("%d \n", *numeros[i]);
    }
}

void Arreglo::redimnesionarArreglo(int *arrayOriginal[]) {
    int tam = sizeof(arrayOriginal) / sizeof(int);
    bool lleno = true;

    for (int i = 0; i < tam; ++i) {
        if (arrayOriginal[i] == nullptr) {
            lleno = false;
            break;
        }
    }

    if (lleno) {
        tam = tam + 5;
        int *auxi[tam];

        for (int i = 0; i < tam - 5; ++i) {
            auxi[i] = arrayOriginal[i];
        }

        arrayOriginal = auxi;
    }
}

void Arreglo::imprimir(int *array[], int tam) {
    printf("tam %d \n",tam);
    for (int i = 0; i < tam; ++i) {
        printf("%d", *array[i]);
    }
}