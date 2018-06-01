CC=g++
CFLAGS=-I

app: main.o tree.o
	$(CC) -o app main.o tree.o

main.o: main.cpp tree.hpp
	$(CC) -c main.cpp

tree.o: tree.cpp tree.hpp
	$(CC) -c tree.cpp