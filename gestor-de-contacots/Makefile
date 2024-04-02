CPP = g++
TARGET = contactos


# all
all: .all-post

.all-post: tree/Tree.o tree/ControladorArbol.o
	$(CPP) main.o table-hash-gruoups/TableHashGruoup.o funcionHash/FuncionHash.o atributo/Atributo.o table-hash-attributes/TableHashAttributes.o item-hash-table/ItemHsGroup.o item-hash-table/ItemHsAttributes.o tree/Tree.o tree/Tree.h tree/ControladorArbol.o  contact-manager/ContanctManager.o control-data/ControlDataInput.o list/List.o report/Report.o log/Log.o menu/Menu.o log/ListLog.o -o $(TARGET)

TableHashGruoup.o: table-hash-gruoups/TableHashGruoup.cpp
	$(CPP) -c table-hash-gruoups/TableHashGruoup.cpp


main.o: main.cpp
	$(CPP) -c main.cpp

# clean
clean:
	rm -f *.o $(TARGET)
