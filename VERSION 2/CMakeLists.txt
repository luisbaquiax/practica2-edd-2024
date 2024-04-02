cmake_minimum_required(VERSION 3.27)
project(probando)

set(CMAKE_CXX_STANDARD 17)

add_executable(probando main.cpp
        tree/Tree.h
        atributo/Atributo.cpp
        contact-manager/ContanctManager.cpp
        control-data/ControlDataInput.cpp
        control-archivo/ControlArchivo.cpp
        funcionHash/FuncionHash.cpp
        item-hash-table/ItemHsAttributes.cpp
        item-hash-table/ItemHsGroup.cpp
        list/List.cpp
        log/ListLog.cpp
        log/Log.cpp
        menu/Menu.cpp
        report/Report.cpp
        table-hash-attributes/TableHashAttributes.cpp
        table-hash-gruoups/TableHashGruoup.cpp
        tree/ControladorArbol.cpp
        tree/Tree.cpp)
