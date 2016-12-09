//
//  StackWIthLinkedList.hpp
//  test
//
//  Created by KevinLiu on 16/12/9.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef StackWIthLinkedList_hpp
#define StackWIthLinkedList_hpp

#include <stdio.h>
#include "DataStructureBasic.hpp"
#include <stdexcept>

template <class T>
class Stack
{
    LinkedList<T> list;
public:
    Stack();
    bool isEmpty();
    T peek()const;
    void push(const T& value);
    T pop();
    int getsize();
    void print();
};

template <class T>
class Queue {
    LinkedList<T> list;
    
public:
    Queue(){};
    int getsize();
    void enqueue(const T& value);
    T dequeue();
    void print();
};

template<typename T>
Stack<T>::Stack()
{
}

template<typename T>
bool Stack<T>::isEmpty()
{
    return list.isEmpty();
}

template<typename T>
T Stack<T>::peek() const
{
    return list.getLast();
}

template<typename T>
void Stack<T>::push(const T &value)
{
    list.addLast(value);
}

template<typename T>
T Stack<T>::pop()
{
    return list.removeLast();
}

template<typename T>
int Stack<T>::getsize()
{
    return list.getSize();
}

template<typename T>
void Stack<T>::print()
{
    list.print();
}

template<typename T>
int Queue<T>::getsize()
{
    return list.getSize();
}

template<typename T>
void Queue<T>::enqueue(const T &value)
{
    list.addLast(value);
}

template<typename T>
T Queue<T>::dequeue()
{
    return list.removeFirst();
}

template<typename T>
void Queue<T>::print()
{
    list.print();
}


#endif /* StackWIthLinkedList_hpp */
