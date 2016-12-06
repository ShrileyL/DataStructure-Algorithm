//
//  AlgorithmSort.cpp
//  test
//
//  Created by KevinLiu on 16/12/6.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include "AlgorithmSort.hpp"


void AlgorithmSort::display( T* array, int lenth)
{
    for (int i = 0; i < lenth; ++i)
    {
        std::cout << *(array+i) <<std::endl;
    }
}

void AlgorithmSort::m_swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

T* AlgorithmSort::insertSort(T *array, int lenth)
{
    int i = 0, j = 0;
    int currentElement;
    for (i = 1; i < lenth; i++)
    {
        currentElement = *(array+i);
        for (j = i -1; (j >= 0) && (*(array+j) >= currentElement); j--) {
            *(array+(j+1)) = *(array+j);
        }
        
        //Insert the current element into array
        *(array+(j+1)) = currentElement;
        
    }
    return array;
}

T* AlgorithmSort::selectSort(T *array, int lenth)
{
    for (int i = lenth -1; i >= 1; i--)
    {
        int currentMaxIndex = 0;
        int currentMax = *array;
        
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
    return array;
}

T* AlgorithmSort::bubbleSort(T *array, int lenth)
{
    for (int i = 1; i < lenth; ++i) {
        for (int j = 0; j < lenth - i; ++j) {
            if (*(array+j) > *(array+(j+1)) ) {
                //swap *(array+j)  and *(array+(j+1))
                m_swap(*(array+j), *(array+(j+1)));
//                int temp = *(array+(j+1)) ;
//                *(array+(j+1))  = *(array+j);
//                *(array+j)  = temp ;
            }
        }
    }
    return array;
}

T* AlgorithmSort::optimalBubbleSort(T *array, int lenth)
{
    bool needNextPass = true;
    for (int i = 1; (i < lenth)&&(needNextPass); ++i)
    {
        needNextPass = false;
        for (int j = 0; j < lenth - i; ++j)
        {
            if (*(array+j) > *(array+(j+1)) )
            {
                //swap *(array+j)  and *(array+(j+1))
                m_swap(*(array+j), *(array+(j+1)));
//                int temp = *(array+(j+1)) ;
//                *(array+(j+1))  = *(array+j);
//                *(array+j)  = temp ;
                
                needNextPass = true;//mark need next pass
            }
        }
    }
    return array;
}

T* AlgorithmSort::m_merge(T *arr1, int size1, T *arr2, int size2, T *dest)
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
    
    return dest;
}

void AlgorithmSort::arraycopy(T *source, int sourceStartIndex, T *target, int targetStartIndex, int lenth)
{
    for (int i = 0; i < lenth; ++i)
    {
        *(target+(targetStartIndex + i)) = *(source + (sourceStartIndex + i));
    }
}

void AlgorithmSort::quickSort(T *array, int left, int right)
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