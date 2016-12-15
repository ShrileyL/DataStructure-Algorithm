//
//  DoubleList.hpp
//  test
//
//  Created by KevinLiu on 16/12/14.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef DoubleList_hpp
#define DoubleList_hpp

#include <stdio.h>

#include <iostream>
using namespace std;


//Node for Double linked list
template <typename T>
struct DNode
{
    //default public
    T data;
    DNode *prev;
    DNode *next;
    
    DNode(const T &obj=T(),DNode *p=NULL, DNode *n=NULL):data(obj),prev(p),next(n){}
};

//Double Linked list
template <typename T>
class List
{
private:
    struct DNode;
    
public:
    class const_iterator;
    class iterator : public const_iterator
    {};
    
public:
    List();
    List(const List &rhs);
    const List &operator= (const List &rhs);
    
    iterator begin();
    const_iterator begin() const;
    
    iterator end();
    const_iterator end() const;
    
    int size() const;
    bool empty() const;
    
    void clear();
    
    T & front();
    const T & front() const;
    T & back();
    const T & back() const;
    
    void push_front(const T & x);
    void push_back(const T & x);
    void pop_front();
    void pop_back();
    
    iterator insert(iterator itr, const T &x);
    
    iterator erase(iterator itr);
    iterator erase(iterator start, iterator end);
    
private:
    int theSize;
    DNode *head;
    DNode *tail;
    
    void init();
};


//class const_iterator
template <typename T>
class const_iterator
{
    
public:
    const_iterator():current(NULL){}
    
    const T & operator* () const
    {
        return retrieve();
    }
    //++a prefix
    const_iterator operator++()
    {
        current = current->next;
        return *this;
    }
    
    //a++
    const_iterator operator++(int)
    {
        const_iterator old = *this;
        ++(*this);
        return old;
    }
    
    bool operator== (const const_iterator &rhs) const
    {
        return current==rhs.current;
    }
    
    bool operator!= (const const_iterator& rhs) const
    {
        return !(*this == rhs);
    }
    
protected:
    DNode<T> *current;
    
    T& retrieve() const
    {
        return current->data;
    }
    
    const_iterator(DNode<T> *p):current(p){};
    
    friend class List<T>;
};


template <typename T>
class iterator: public const_iterator<T>
{
protected:
    iterator(DNode<T> *p):const_iterator<T>(p){}
    friend class List<T>;
    
public:
    iterator(){}
    
    T & operator*()
    {
        return retrieve();
    }
};
#endif /* DoubleList_hpp */
