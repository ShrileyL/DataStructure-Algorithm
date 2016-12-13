//
//  Heap.hpp
//  Implement of heap using vector
//
//  Created by KevinLiu on 16/12/12.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef Heap_hpp
#define Heap_hpp

#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;
template <typename T>
class Heap
{
    vector<T> v;
    
public:
    Heap();
    Heap(T ele[], int arraysize);
    T remove() throw (runtime_error);
    void add(T element);
    int getsize();
    
};

// use Heap to construct the priority queue
template <typename T>
class PriorityQueue
{
    Heap<T> heap;
    
public:
    PriorityQueue();
    void enqueue(T element);
    T dequeue();
    int getsize();
};

template <typename T>
Heap<T>::Heap()
{
    
}

template <typename T>
Heap<T>::Heap(T ele[], int arraysize)
{
    for (int i = 0; i < arraysize; ++i)
    {
        add(ele[i]);
    }
}

/*remove the root from the heap*/
template <typename T>
T Heap<T>::remove() throw (runtime_error)
{
    //empty heap
    if(v.size()==0)
        throw runtime_error("Heap is empty.");
        
    T removedElement = v[0];
    v[0] = v[v.size()-1];//move the last to root
    v.pop_back();//remove root
    
    //maintain the heap property
    int currentIndex = 0;
    while(currentIndex < v.size())
    {
        int leftChildIndex = 2 * currentIndex + 1;
        int rightChildIndex = 2 * currentIndex + 2;
        
        //find the maximum between two children
        if(leftChildIndex >= v.size()) break;//the tree is a heap
        int maxIndex = leftChildIndex;
        if(rightChildIndex < v.size())
        {
            if(v[maxIndex] < v[rightChildIndex])
            {
                maxIndex = rightChildIndex;
            }
        }
        
        //swap i the current node is less than the maximum
        if(v[maxIndex] > v[currentIndex])
        {
            T temp = v[maxIndex];
            v[maxIndex] = v[currentIndex];
            v[currentIndex] = temp;
            currentIndex = maxIndex;
        }
        else
            break;//the tree is a heap
    }
    
    return removedElement;
}

/*insert element into the heap and maintain the heap property*/
template<typename T>
void Heap<T>::add(T element)
{
    v.push_back(element);//append element to the heap
    int currentIndex = v.size() - 1;
    
    //maintain the heap property
    while (currentIndex > 0)
    {
        int parentIndex = (currentIndex - 1)/2;
        //swap if the current is greater than its parent
        if (v[currentIndex] > v[parentIndex])
        {
            T temp = v[currentIndex];
            v[currentIndex] = v[parentIndex];
            v[parentIndex] = temp;
        }
        else
            break;//the tree is heap now
        
        currentIndex = parentIndex;
    }
}

template<typename T>
int Heap<T>::getsize()
{
    return v.size();
}

template<typename T>
PriorityQueue<T>::PriorityQueue(){};

template <typename T>
void PriorityQueue<T>::enqueue(T element)
{
    heap.add(element);
}

template<typename T>
T PriorityQueue<T>::dequeue()
{
    return heap.remove();
}

template<typename T>
int PriorityQueue<T>::getsize()
{
    return heap.getsize();
}

#endif /* Heap_hpp */
