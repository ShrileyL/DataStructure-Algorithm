//
//  DataStructureBasic.hpp
//  use together with DataStructureBasicDef.hpp
//
//  Created by KevinLiu on 16/12/11.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef DataStructureBasic_hpp
#define DataStructureBasic_hpp

#include <stdio.h>
#include <iostream>
#include <stdexcept>

using namespace std;

//declaration

//Node
template<typename T>
class Node
{
public:
    T element;//Element contained in the node
    //need to be "Node<T>" instead of "Node"
    Node<T>* next;//pointer to next Node

    Node();
    Node(const T& ele);

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
    void print();
    void addFirst(const T element);
    void addLast(const T element);
    const T getFirst();
    const T getLast();
    T removeFirst() throw(runtime_error);
    T removeLast() throw(runtime_error);
    void add(const T element);
    void add(const int index,const T element);
    void clear();
//    bool contains(T element);
    const T get(const int index);
    int indexOf(const T element);
    bool isEmpty();
//    int lastIndexOf(T element);
    void remove(const T element);
    const int getSize();
    T removeAt(const int index);
//    T set(int index,T element);
};

#endif /* DataStructureBasic_hpp */
