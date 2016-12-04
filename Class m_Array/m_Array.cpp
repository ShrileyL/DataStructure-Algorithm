//
//  m_Array.cpp
//  test
//
//  Created by KevinLiu on 16/12/4.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include "m_Array.hpp"

template <typename T>
m_Array<T>::m_Array(T arr[], int n):array(NULL),lenth(0)
{
    array = arr;
    lenth = n;
    cout << "m_Array constructor. "<< endl;
}

template <typename T>
void m_Array<T>::display()
{
    for (int i = 0; i < lenth; ++i) {
        cout << *(array+i) <<endl;
    }
}


template <typename T>
void m_Array<T>::insertSort()
{
    int i = 0, j = 0;
    T currentElement;
    for (i = 1; i < lenth; i++)
    {
        currentElement = *(array+i);
        for (j = i -1; (j >= 0) && (*(array+j) >= currentElement); j--) {
            *(array+(j+1)) = *(array+j);
        }
        
        //Insert the current element into array
        *(array+(j+1)) = currentElement;
    }
    
    display();
}


template <typename T>
void m_Array<T>::selectSort()
{
    
}
