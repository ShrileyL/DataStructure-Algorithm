//
//  DataStructureBasic.hpp
//  test
//
//  Created by KevinLiu on 16/12/6.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef DataStructureBasic_hpp
#define DataStructureBasic_hpp

#include <stdio.h>
#include <iostream>
#include <stdexcept>

using namespace std;

//Node
template<typename T>
class Node
{
    T element;//Element contained in the node
    Node* next;//pointer to next Node
public:
    Node():next(NULL){};
    Node(T element);
};

//LinkedList
template<typename T>
class LinkedList
{
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    LinkedList();
    void addFirst(T element);
    void addLast(T element);
    T getFirst();
    T getLast();
    T removeFirst() throw(runtime_error);
    T removeLast() throw(runtime_error);
    void add(T element);
    void add(int index,T element);
    void clear();
//    bool contains(T element);
    T get(int index);
    int indexOf(T element);
    bool isEmpty();
//    int lastIndexOf(T element);
    void remove(T element);
    int getSize();
    T removeAt(int index);
//    T set(int index,T element);
};


#endif /* DataStructureBasic_hpp */
