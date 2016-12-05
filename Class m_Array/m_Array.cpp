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
    for (int i = lenth -1; i >= 1; i--)
    {
        int currentMaxIndex = 0;
        T currentMax = *array;
        
        for (int j = 1; j <= i; ++j)
        {
            if (currentMax < *(array+j))
            {
                currentMax =*(array+j);
                currentMaxIndex = j;
            }
        }
        
        //swap arr[j] with arr[currentMaxIndex] if necessary
        if (currentMaxIndex != i)
        {
            *(array+currentMaxIndex) = *(array+i);
            *(array+i) = currentMax;
        }
    }
}

template <typename T>
void m_Array<T>::bubbleSort()
{
    for (int i = 1; i < lenth; ++i) 
    {
        for (int j = 0; j < lenth - i; ++j)//j from 0 to lenth-i !
        {
            if (*(array+j) > *(array+(j+1)) )
            {
                //swap *(array+j)  and *(array+(j+1))
                T temp = *(array+(j+1)) ;
                *(array+(j+1))  = *(array+j);
                *(array+j)  = temp ;
            }
        }
    }
}

template <typename T>
void m_Array<T>::optimalBubbleSort()
{
    //Array may be sorted and next pass not needed
    bool needNextPass = true;
    for (int i = 1; (i < lenth)&&(needNextPass); ++i)
    {
        needNextPass = false;
        //perform the kth pass
        for (int j = 0; j < lenth - i; ++j)
        {
            if (*(array+j) > *(array+(j+1)) )
            {
                //swap *(array+j)  and *(array+(j+1))
                T temp = *(array+(j+1)) ;
                *(array+(j+1))  = *(array+j);
                *(array+j)  = temp ;
                needNextPass = true;//next pass still needed
            }
        }
    }
}
