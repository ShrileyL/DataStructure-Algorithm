CC=g++
CFLAGS=-I

out: main.o array.o
	$(CC) -o out main.o array.o

main.o: main.cpp array.hpp
	$(CC) -c main.cpp

array.o: array.cpp array.hpp
	$(CC) -c array.cpp