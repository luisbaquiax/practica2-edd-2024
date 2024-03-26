cmake_minimum_required(VERSION 3.27)
project(gestor_de_contacots)

set(CMAKE_CXX_STANDARD 17)

add_executable(gestor_de_contacots main.cpp
        table-hash-gruoups/TableHashGruoup.cpp
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
        contact-manager/ContanctManager.cpp
        contact-manager/ContanctManager.h
        control-data/ControlDataInput.cpp
        control-data/ControlDataInput.h
        list/List.cpp
        list/List.h
        report/Report.cpp
        report/Report.h
        log/Log.cpp
        log/Log.h
        menu/menu.cpp
        menu/menu.h
)
