//
//  IntArray.hpp
//  Container Class IntArray
//
//  Created by KevinLiu on 16/10/17.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef IntArray_hpp
#define IntArray_hpp

#include <stdio.h>
#include <cassert> // for assert()

class IntArray
{
private:
    int m_length;
    //use pointer to store data
    //tio do dynamic allocation
    int *m_data;
public:
    IntArray():m_length(0),m_data(nullptr){};
    IntArray(int l):m_length(l)
    {
        m_data = new int[l];
    }
    ~IntArray();
    void erase();
    int getLength();
    int& operator[](int index);
    // reallocate resizes the array.  Any existing elements will be destroyed.  This function operates quickly.
    void reallocate(int newLength);
    
    
    // resize resizes the array.  Any existing elements will be kept.  This function operates slowly.
    void resize(int newLength);
    
    void insertBefore(int value, int index);
    
    void remove(int index);
    
    // A couple of additional functions just for convenience
    void insertAtBeginning(int value) { insertBefore(value, 0); }
    void insertAtEnd(int value) { insertBefore(value, m_length); }
   
};

#endif /* IntArray_hpp */
