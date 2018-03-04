//
//  sort.hpp
//  algorithm
//
//  Created by KevinLiu on 18/3/3.
//  Copyright © 2018年 KevinLiu. All rights reserved.
//

#ifndef sort_h
#define sort_h

void mySwap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

/* Select sort based algorithm in which the list is divided into two parts, sorted part at left and unsorted part at right
 The process continues moving unsorted array boundary by one element
 */
void SelectionSort(int* arr, int lenth)
{
    int minindex,i,j;
    for (i = 0; i < lenth; ++i)
    {
        minindex = i;
        for (j = i + 1; j < lenth; ++j)
        {
            if (*(arr+j) < *(arr+minindex))
            {
                minindex = j;
            }
        }
        if(minindex != i)
            mySwap(*(arr+minindex), *(arr+i));
    }
    
}

//create temp arr to store merged arr
int a[10] = {10,14,19,26,27,31,33,35,42,44};
int temp[7];
void MergeSort(int* arr, int start, int end)
{
    if (start >= end)
        return;
    
    int middle = (start+end)/2;
    MergeSort(arr, start, middle);
    MergeSort(arr, middle+1, end);
    
    //merging below
    int i , j, k;
    i = start;
    j = middle+1;
    k = start;
    while (i <= middle && j <=end)
    {
        if (*(arr+i) < *(arr+j))
        {
            temp[k++]= *(arr+(i++));
        }
        else
        {
            temp[k++] = *(arr+(j++));
        }
    }
    
    while (i <= middle)
    {
        temp[k++] = *(arr+(i++));
    }
    while (j <= end)
    {
        temp[k++] = *(arr+(j++));
    }
    
    for (k=start; k <= end; ++k)
    {
        *(arr+k) = temp[k];
    }
}

void BubbleSort(int* arr, int lenth)
{
    bool swapped = false;
    for (int i=0; i < lenth; ++i)
    {
        for (int j = 0; j < lenth - i -1; ++j)
        {
            if(*(arr+j) > *(arr+j+1))
            {
                mySwap(*(arr+j+1), *(arr+j));
                swapped = true;
            }
        }
        
        //if no swap in a loop means arr has sorted
        if (!swapped)
        {
            break;
        }
    }
}

void InsertSort(int* arr, int lenth)
{
    int i;
    int valueToSort;
    int holePosition;
    
    for (i=0; i < lenth; ++i)
    {
        valueToSort = *(arr+i);
        holePosition = i;
        
        while (holePosition > 0 && *(arr+holePosition-1)> valueToSort)
        {
            //need to move
            *(arr+holePosition) = *(arr+holePosition-1);
            holePosition --;
        }
        
        if (holePosition != i)
        {
            *(arr+holePosition) = valueToSort;
        }
    }
}

#endif /* sort_h */
