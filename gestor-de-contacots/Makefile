CPP = g++ -std=c++17
TARGET = contactos


# all
all: .all-post

.all-post: control-archivo/ControlArchivo.o log/Log.o log/ListLog.o funcionHash/FuncionHash.o atributo/Atributo.o list/List.o tree/Tree.o tree/ControladorArbol.o control-data/ControlDataInput.o item-hash-table/ItemHsAttributes.o table-hash-attributes/TableHashAttributes.o item-hash-table/ItemHsGroup.o table-hash-gruoups/TableHashGruoup.o contact-manager/ContanctManager.o report/Report.o menu/Menu.o main.o
	$(CPP) control-archivo/ControlArchivo.o log/Log.o log/ListLog.o funcionHash/FuncionHash.o atributo/Atributo.o list/List.o tree/Tree.o tree/ControladorArbol.o control-data/ControlDataInput.o item-hash-table/ItemHsAttributes.o table-hash-attributes/TableHashAttributes.o item-hash-table/ItemHsGroup.o table-hash-gruoups/TableHashGruoup.o contact-manager/ContanctManager.o report/Report.o menu/Menu.o main.o -o $(TARGET)

TableHashGruoup.o: table-hash-gruoups/TableHashGruoup.cpp table-hash-gruoups/TableHashGruoup.h
	$(CPP) -c table-hash-gruoups/TableHashGruoup.cpp

FuncionHash.o: funcionHash/FuncionHash.cpp funcionHash/FuncionHash.h
	$(CPP) -c funcionHash/FuncionHash.cpp

Atributo.o: atributo/Atributo.cpp atributo/Atributo.h
	$(CPP) -c atributo/Atributo.cpp

TableHashAttributes.o: table-hash-attributes/TableHashAttributes.cpp table-hash-attributes/TableHashAttributes.h
	$(CPP) -c table-hash-attributes/TableHashAttributes.cpp

ItemHsGroup.o: item-hash-table/ItemHsGroup.cpp item-hash-table/ItemHsGroup.h
	$(CPP) -c item-hash-table/ItemHsGroup.cpp

ItemHsAttributes.o: item-hash-table/ItemHsAttributes.cpp item-hash-table/ItemHsAttributes.h
	$(CPP) -c item-hash-table/ItemHsAttributes.cpp

Tree.o: tree/Tree.cpp tree/Tree.h
	$(CPP) -c tree/Tree.cpp

ControladorArbol.o: tree/ControladorArbol.cpp tree/ControladorArbol.h
	$(CPP) -c tree/ControladorArbol.cpp

ControlArchivo.o: control-archivo/ControlArchivo.cpp control-archivo/ControlArchivo.h
	$(CPP) -c control-archivo/ControlArchivo.cpp

ContanctManager.o: contact-manager/ContanctManager.cpp contact-manager/ContanctManager.h
	$(CPP) -c contact-manager/ContanctManager.cpp

ControlDataInput.o: control-data/ControlDataInput.cpp control-data/ControlDataInput.h
	$(CPP) -c control-data/ControlDataInput.cpp

List.o: list/List.cpp list/List.h
	$(CPP) -c list/List.cpp

Report.o: report/Report.cpp report/Report.h
	$(CPP) -c report/Report.cpp

Log.o: log/Log.cpp log/Log.h
	$(CPP) -c log/Log.cpp

Menu.o: menu/Menu.cpp menu/Menu.h
	$(CPP) -c menu/Menu.cpp

ListLog.o: log/ListLog.cpp log/ListLog.h
	$(CPP) -c log/ListLog.cpp

main.o: main.cpp
	$(CPP) -c main.cpp

# clean
clean:
	rm -f *.o $(TARGET)
