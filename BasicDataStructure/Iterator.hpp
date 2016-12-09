//
//  Iterator.hpp
//  test
//
//  Created by KevinLiu on 16/12/9.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef Iterator_hpp
#define Iterator_hpp

#include <stdio.h>
#include <stdexcept>
#include "DataStructureBasic.hpp"
using namespace std;

template <typename T>
class Iterator {
    Node<T>* current;
    
public:
    Iterator(const Node<T>* p);
    Iterator &operator++();
    T operator*();
    bool operator==(const Iterator<T>& itr);
    bool operator!=(const Iterator<T>& itr);
};

template <typename T>
class NewLinkedList
{
    Node<T>* head;
    Node<T>* tail;
    int size;
public:
    NewLinkedList();
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
    
    Iterator<T> begin()
    {
        Iterator<T> p = Iterator<T>(head);
        return p;
    }
    
    Iterator<T> end()
    {
        Iterator<T> p = Iterator<T>(tail->next);
        return p;
    }
};

template<typename T>
Iterator<T>::Iterator(const Node<T>* p):current(p)
{
}

template<typename T>
Iterator<T>& Iterator<T>::operator++()
{
    current = current->next;
    return *this;
}

template<typename T>
T Iterator<T>::operator*()
{
    return current->element;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T> &itr)
{
    return current == itr.current;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T> &itr)
{
    return current != itr.current;
}

template<typename T>
NewLinkedList<T>::NewLinkedList()
{
    head = tail = NULL;
    size = 0;
}

template<typename T>
void NewLinkedList<T>::print()
{
    if (getSize() == 0)
    {
        cout << "Empty list."<< endl;
    }
    else
    {
        for (int i = 0; i < getSize(); ++i) {
            cout << get(i) << " ";
        }
        cout << endl;
        cout<<"current list length: "<<getSize()<<endl;
    }
}

template<typename T>
bool NewLinkedList<T>::isEmpty()
{
    //    if (head == NULL)
    //        return true;
    //    else
    //        return false;
    
    return head==NULL;
}

template<typename T>
void NewLinkedList<T>::clear()
{
    while (head!=NULL) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    
    tail = NULL;
}

template<typename T>
int NewLinkedList<T>::indexOf(const T element)
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
const int NewLinkedList<T>::getSize()
{
    return size;
}

template<typename T>
void NewLinkedList<T>::addFirst(const T element)
{
    Node<T> *newNode = new Node<T>(element);//creat new Node
    
    newNode->next = head;
    head = newNode;
    ++size;
    
    if(tail == NULL)//if list was empty, both tail and head pointer to newNode
        tail = head;
}

template<typename T>
void NewLinkedList<T>::addLast(const T element)
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
void NewLinkedList<T>::add(const T element)
{
    addLast(element);
}

template<typename T>
void NewLinkedList<T>::add(const int index, const T element)
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
const T NewLinkedList<T>::getFirst()
{
    if(size == 0)
        throw runtime_error("Index out of range");
    else
        return head->element;
}

template<typename T>
const T NewLinkedList<T>::getLast()
{
    if(size == 0)
        throw runtime_error("Index out of range");
    else
        return tail->element;
}

template<typename T>
const T NewLinkedList<T>::get(const int index)
{
    if(index < 0 || index > size-1)
        throw runtime_error("Index out of range");
    
    Node<T>* current = head;
    for(int i = 0;i < index;++i)//locate current
        current = current->next;
    
    return current->element;
}

template<typename T>
T NewLinkedList<T>::removeFirst() throw(runtime_error)//throw exception
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
T NewLinkedList<T>::removeLast() throw(runtime_error)
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
                
                T element = (p->next)->element;//return element to be delete
                tail = p;
                tail->next = NULL;
                
                --size;
            
            delete p;
            return element;
        }
}

template<typename T>
T NewLinkedList<T>::removeAt(const int index)
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


#endif /* Iterator_hpp */
