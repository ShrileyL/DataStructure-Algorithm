CC=g++
CFLAGS=-I

app: main.o linkedlist.o 
	$(CC) -o app main.o linkedlist.o

main.o: main.cpp linkedlist.h
	$(CC) -c main.cpp

linkedlist.o: linkedlist.cpp linkedlist.h
	$(CC) -c linkedlist.cpp