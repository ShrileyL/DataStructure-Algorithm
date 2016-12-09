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
    std::ostream & print(std::ostream & ros) const;
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

//Implemenet

template<typename T>
Node<T>::Node():next(NULL)
{
}

template<typename T>
Node<T>::Node(const T& ele)
{
    this->element = ele;
    next = NULL;
}

template<typename T>
LinkedList<T>::LinkedList()
{
    head = tail = NULL;
    size = 0;
}

template<typename T>
std::ostream & LinkedList<T>::print(std::ostream & ros) const
{
    Node<T>* p = head;
    if (p == NULL)
    {
        ros<<"empty list"<<std::endl;
//        ros<<"current list length: "<<this->getSize()<<std::endl;
        return ros;
    }
    //find the tail of the list
    while (p!=NULL)
    {
        p = p->next;
        ros<< p->element<< std::endl;
    }
//    ros<<"current list length: "<<this->getSize()<<std::endl;
    return ros;
    
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
int LinkedList<T>::indexOf(const T element)
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
const int LinkedList<T>::getSize()
{
    return size;
}

template<typename T>
void LinkedList<T>::addFirst(const T element)
{
    Node<T> *newNode = new Node<T>(element);//creat new Node
    
    newNode->next = head;
    head = newNode;
    ++size;
    
    if(tail == NULL)//if list was empty, both tail and head pointer to newNode
        tail = head;
}

template<typename T>
void LinkedList<T>::addLast(const T element)
{
    Node<T> *newNode=new Node<T>(element);
    
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
void LinkedList<T>::add(const T element)
{
    addLast(element);
}

template<typename T>
void LinkedList<T>::add(const int index, const T element)
{
    if (index == 0)
        addFirst(element);
    else if(index >= size)
        addLast(element);
    else
    {
        Node<T>* p = head;
        Node<T>* newNode=new Node<T>(element);
        for (int i = 1; i < index; ++i)
            p = p->next;//p pointer to one ahead the position to be insert
        
        Node<T>* temp = p->next;
        p->next = newNode;
        newNode->next = temp;
        
        ++size;
    }
}

template<typename T>
const T LinkedList<T>::getFirst()
{
    if(size == 0)
        throw runtime_error("Index out of range");
    else
        return head->element;
}

template<typename T>
const T LinkedList<T>::getLast()
{
    if(size == 0)
        throw runtime_error("Index out of range");
    else
        return tail->element;
}

template<typename T>
const T LinkedList<T>::get(const int index)
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
T LinkedList<T>::removeAt(const int index)
{
    if(index == 0)
        return removeFirst();
    else if(index == size-1)
        return removeLast();
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

#endif /* DataStructureBasic_hpp */
