//
//  DataStructureBasic.cpp
//  test
//
//  Created by KevinLiu on 16/12/6.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include "DataStructureBasic.hpp"
#include <stdexcept>

template<typename T>
Node<T>::Node(T n)
{
    this->element = n;
    next = NULL;
}

template<typename T>
LinkedList<T>::LinkedList()
{
    head = tail = NULL;
    size = 0;
}

template<typename T>
bool LinkedList<T>::isEmpty()
{
//    if (head == NULL)
//        return true;
//    else
//        return false;
    
    return head==NULL;
}

template<typename T>
void LinkedList<T>::clear()
{
    while (head!=NULL) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    
    tail = NULL;
}

template<typename T>
int LinkedList<T>::indexOf(T element)
{
    Node<T> *current = head;
    for (int i = 0; i <size; ++i) {
        if(current->element == element)
            return i;
        current = current->next;
    }
    
    return -1;
}

template<typename T>
int LinkedList<T>::getSize()
{
    return size;
}

template<typename T>
void LinkedList<T>::addFirst(T element)
{
    Node<T> newNode = new Node<T>(element);//creat new Node
    
    newNode->next = head;
    head = newNode;
    ++size;
    
    if(tail == NULL)//if list was empty, both tail and head pointer to newNode
        tail = head;
}

template<typename T>
void LinkedList<T>::addLast(T element)
{
    Node<T> newNode=new Node<T>(element);
    
    if (tail == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = tail->next;
    }
    
    ++size;
}


template<typename T>
void LinkedList<T>::add(T element)
{
//    Node<T> newNode=new Node<T>(element);
//    
//    if (tail == NULL)
//    {
//        head = tail = newNode;
//    }
//    else
//    {
//        tail->next = newNode;
//        tail = tail->next;
//    }
//    
//    ++size;
    
    addLast(element);
}

template<typename T>
void LinkedList<T>::add(int index, T element)
{
    if (index == 0)
        addFirst(element);
    else if(index >= size)
        addLast(element);
    else
    {
        Node<T>* p = head;
        Node<T> newNode=new Node<T>(element);
        for (int i = 1; i < index; ++i)
            p = p->next;//p pointer to one ahead the position to be insert
        
        newNode->next = p-> next->next;
        p->next = newNode;
        
        ++size;
    }
}

template<typename T>
T LinkedList<T>::getFirst()
{
    if(size == 0)
        throw runtime_error("Index out of range");
    else
        return head->element;
}

template<typename T>
T LinkedList<T>::getLast()
{
    if(size == 0)
        throw runtime_error("Index out of range");
    else
        return tail->element;
}

template<typename T>
T LinkedList<T>::get(int index)
{
    if(index < 0 || index > size-1)
        throw runtime_error("Index out of range");
    
    Node<T>* current = head;
    for(int i = 0;i < index;++i)//locate current
        current = current->next;
    
    return current->element;
}

template<typename T>
T LinkedList<T>::removeFirst() throw(runtime_error)//throw exception
{
    if(size==0)
        throw runtime_error("No elements in the list");
    else
    {
    Node<T>* p = head;//p as the same meaning of "temp"
    head = head->next;
    --size;
//    p->next = nullptr;
//    return (*p).elemet; my wrong thought
    if(head == NULL) tail = NULL;
    
    T element = p->element;
    delete p;//distroy the node
    return element;
    }
}

template<typename T>
T LinkedList<T>::removeLast() throw(runtime_error)
{
    if(size==0)
        throw runtime_error("No elements in the list");
    else if(size == 1)
    {
        Node<T>* temp = head;
        head = tail = NULL;
        size = 0;
        T element = temp->element;
        delete temp;
        return element;
    }
    else
    {
        Node<T>* p = head;
        while(p->next != tail)
            p = p->next;// p pointer to the one ahead from tail
        
        tail = p;
        tail->next = NULL;
        
        --size;
            
        T element = p->element;
        delete p;
        return element;
    }
}

template<typename T>
T LinkedList<T>::removeAt(int index)
{
    if(index == 0)
        removeFirst();
    else if(index == size-1)
        removeLast();
    else
    {
        Node<T>* previous = head;
        for(int i = 1;i < index;++i)
            previous = previous->next;//locate previous
        
        Node<T>* current = previous->next;
        previous->next = current->next;
        
        --size;//reduce size
        
        T element = current->element;
        delete current;
        return element;
    }
}
