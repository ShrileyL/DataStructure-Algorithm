CC=g++
CFLAGS=-I -std=c++11

app: main.o tree.o treetraversal.o narraytree.o
	$(CC) -o app main.o tree.o narraytree.o treetraversal.o 

main.o: main.cpp tree.hpp
	$(CC) -c main.cpp

tree.o: tree.cpp tree.hpp
	$(CC) -c tree.cpp

narraytree.o: narraytree.cpp narraytree.hpp
	$(CC) -c narraytree.cpp

treetraversal.o: treetraversal.cpp tree.hpp
	$(CC) -c treetraversal.cpp