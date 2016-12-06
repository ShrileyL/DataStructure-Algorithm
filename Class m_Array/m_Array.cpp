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


template <typename T>
void m_merge(T arr1[],int size1,T arr2[], int size2,T* dest)
{
    int current1 = 0;//index in arr1
    int current2 = 0;
    int current3 = 0;
    
    while (current1 <size1 && current2 < size2)
    {
        if (*(arr1+current1) < *(arr2 + current2))
            *(dest + (current3++)) = *(arr1 + (current1++));
        else
            *(dest + (current3++)) = *(arr2 + (current2++));
    }
    
    while (current1 < size1)
    {
        *(dest + (current3++)) = *(arr1 + (current1++));
    }
    
    while (current2 < size2)
    {
        *(dest + (current3++)) = *(arr2 + (current2++));
    }
    
}

template <typename T>
void arraycopy(T* source, int sourceStartIndex, T* target, int targetStartIndex, int lenth)
{
    for (int i = 0; i < lenth; ++i) {
        *(target+(targetStartIndex + i)) = *(source + (sourceStartIndex + i));
    }
}


template <typename T>
void mergeSort(T* array, int lenth)
{
    if (lenth > 1)//base case
    {
        int firstlenth = lenth/2;
        //merge sort the first half
        T* firsthalf = new T[firstlenth];//create firsthalf

        arraycopy(array, 0, firsthalf, 0, firstlenth);
        mergeSort(firsthalf,lenth/2);
        
        //merge sort the second half
        int secondhalflenth = lenth-lenth/2;
        T* secondhalf = new T[secondhalflenth];//create secondhalf
        
        arraycopy(array, 0, secondhalf, 0, secondhalflenth);
        mergeSort(secondhalf,secondhalflenth);
        
        //merge firsthalf with secondhalf
        T* temp = new T[lenth];
        m_merge(firsthalf, lenth/2, secondhalf, secondhalflenth, temp);
        arraycopy(temp, 0, array,0, lenth);
        
        delete [] temp;
        delete [] firsthalf;
        delete [] secondhalf;
    }
}

template <typename T>
void m_Array<T>::quickSort(int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = array[(left + right) / 2];
    
    /* partition */
    while (i <= j) {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j) {
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
            i++;
            j--;
        }
    };
    
    /* recursion */
    if (left < j)
        quickSort(array, left, j);
    if (i < right)
        quickSort(array, i, right);
}