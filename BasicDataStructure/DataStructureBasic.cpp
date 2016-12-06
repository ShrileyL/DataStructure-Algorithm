//
//  DataStructureBasic.cpp
//  test
//
//  Created by KevinLiu on 16/12/6.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include "DataStructureBasic.hpp"

template<typename T>
Node<T>::Node(T n)
{
    this->element = n;
    next = nullptr;
}

template<typename T>
LinkedList<T>::LinkedList()
{
    head = tail = nullptr;
    size = 0;
}

template<typename T>
bool LinkedList<T>::isEmpty()
{
    if (head == nullptr)
        return true;
    else
        return false;
}

template<typename T>
void LinkedList<T>::addFirst(T element)
{
    Node<T> newNode = new Node<T>(element);//creat new Node
    
    newNode->next = head;
    head = newNode;
    ++size;
    
    if(tail == nullptr)//if list was empty, both tail and head pointer to newNode
        tail = head;
}

template<typename T>
void LinkedList<T>::addLast(T element)
{
    Node<T> newNode=new Node<T>(element);
    
    if (tail == nullptr)
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
    Node<T> newNode=new Node<T>(element);
    
    if (tail == nullptr)
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