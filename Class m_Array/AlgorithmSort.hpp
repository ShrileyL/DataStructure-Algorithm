//
//  AlgorithmSort.hpp
//  test
//
//  Created by KevinLiu on 16/12/6.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef AlgorithmSort_hpp
#define AlgorithmSort_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

typedef int T;
namespace AlgorithmSort
{
    void display(T* array, int lenth);

    T* insertSort(T* array, int n);

    T* selectSort(T arr[], int n);

    T* bubbleSort(T* arr, int n);
    T* optimalBubbleSort(T* arr, int n);
    void m_swap(T& a, T& b);
    
    T* m_merge(T arr1[],int size1,T arr2[], int size2,T* dest);
    void arraycopy(T* source, int sourceStartIndex, T* target, int targetStartIndex, int lenth);
    void mergeSort(T* array, int lenth);
    
    void quickSort(T* array, int left, int right);

};

#endif /* AlgorithmSort_hpp */
