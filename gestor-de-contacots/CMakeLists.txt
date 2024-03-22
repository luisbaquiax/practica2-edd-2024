cmake_minimum_required(VERSION 3.27)
project(gestor_de_contacots)

set(CMAKE_CXX_STANDARD 17)

add_executable(gestor_de_contacots main.cpp
        table-hash-gruoups/TableHashGruoup.cpp
        redimensionar/Arreglo.cpp
        funcionHash/FuncionHash.cpp
        atributo/Atributo.cpp
        table-hash-attributes/TableHashAtributes.cpp
        table-hash-attributes/TableHashAtributes.h
        table-hash-attributes/TableHashAtributes.h
        item-hash-table/ItemHsGroup.cpp
        item-hash-table/ItemHsGroup.h)
