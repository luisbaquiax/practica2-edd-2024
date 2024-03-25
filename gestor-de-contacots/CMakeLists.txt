cmake_minimum_required(VERSION 3.27)
project(gestor_de_contacots)

set(CMAKE_CXX_STANDARD 17)

add_executable(gestor_de_contacots main.cpp
        table-hash-gruoups/TableHashGruoup.cpp
        redimensionar/Arreglo.cpp
        funcionHash/FuncionHash.cpp
        atributo/Atributo.cpp
        table-hash-attributes/TableHashAttributes.cpp
        table-hash-attributes/TableHashAttributes.h
        table-hash-attributes/TableHashAttributes.h
        item-hash-table/ItemHsGroup.cpp
        item-hash-table/ItemHsGroup.h
        item-hash-table/ItemHsAttributes.cpp
        item-hash-table/ItemHsAttributes.h
        tree/Tree.cpp
        tree/Tree.h
        tree/ControladorArbol.cpp
        tree/ControladorArbol.h
        control-archivo/ControlArchivo.cpp
        control-archivo/ControlArchivo.h
)
