//
//  main.cpp
//  test
//
//  Created by KevinLiu on 16/11/27.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//


#include <iostream>

#include <string>
using namespace std;

int* insertSort(int *arr, int n);
int* selectSort(int* arr,int n);
int* bubbleSort(int* arr, int n);
int* optimalBubbleSort(int* arr, int n);
int* m_merge(int arr1[],int size1,int arr2[], int size2,int* dest);
void arraycopy(int* source, int sourceStartIndex, int* target, int targetStartIndex, int lenth);

void quickSort(int* arr,int left, int right);

void display(int* arr,int n);



int main()
{
    int arr[] = {1,8,3,23,2};
    int* array = arr;
   
//    display(array,5);

    // display(optimalBubbleSort(array, 5),5);
    
    int arr1[] = {1,4,66};
//    int arr2[] = {3,42,12,22,5,0};
    int arr2[] = {0,3,5,12,22,42};
    int list[10] ;
//    m_merge(arr1, 3, arr2, 6, list);
//    display(list, 9);
    // arraycopy(arr2, 0, list, 0, 4);
    // display(list, 4);

    quickSort(arr2,0,5);
    display(arr2, 6);

    return 0;
}

int* insertSort(int* array, int n)
{
    int i = 0, j = 0;
    int currentElement;
    for (i = 1; i < n; i++)
    {
        currentElement = *(array+i);
        for (j = i -1; (j >= 0) && (*(array+j) >= currentElement); j--) {
            *(array+(j+1)) = *(array+j);
        }
        
        //Insert the current element into array
        *(array+(j+1)) = currentElement;
        
    }
    return array;
};

void display(int* arr,int n)
{
    for (int i = 0; i < n; ++i) {
        cout << *(arr+i) <<endl;
    }
}

int* selectSort(int* array, int n)
{
    for (int i = n -1; i >= 1; i--)
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

int* bubbleSort(int * array, int n)
{
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            if (*(array+j) > *(array+(j+1)) ) {
                //swap *(array+j)  and *(array+(j+1))
                int temp = *(array+(j+1)) ;
                *(array+(j+1))  = *(array+j);
                *(array+j)  = temp ;
            }
        }
    }
    return array;
}

int* optimalBubbleSort(int* array, int n)
{
    bool NeedCmp = true;
    for (int i = 1; (i < n)&&(NeedCmp); ++i)
    {
        NeedCmp = false;
        for (int j = 0; j < n - i; ++j)
        {
            if (*(array+j) > *(array+(j+1)) )
            {
                //swap *(array+j)  and *(array+(j+1))
                int temp = *(array+(j+1)) ;
                *(array+(j+1))  = *(array+j);
                *(array+j)  = temp ;
                NeedCmp = true;
            }
        }
    }
    return array;
}

int* m_merge(int arr1[],int size1,int arr2[], int size2,int* dest)
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

void arraycopy(int* source, int sourceStartIndex, int* target, int targetStartIndex, int lenth)
{
    for (int i = 0; i < lenth; ++i) {
        *(target+(targetStartIndex + i)) = *(source + (sourceStartIndex + i));
    }
}

void mergeSort(int* array, int lenth)
{
    if (lenth > 1)//base case
    {
        //merge sort the first half
        int firstlenth = lenth/2;
        int* firsthalf = new int[firstlenth];//create firsthalf
        
        arraycopy(array, 0, firsthalf, 0, lenth/2);
        mergeSort(firsthalf,firstlenth);
        
        //merge sort the second half
        int secondhalflenth = lenth-(lenth/2);
        int* secondhalf = new int[secondhalflenth];//create secondhalf
        arraycopy(array, 0, secondhalf, 0, secondhalflenth);
        mergeSort(secondhalf,secondhalflenth);
        
        //merge firsthalf with secondhalf
        int* temp = new int[lenth];
        m_merge(firsthalf, lenth/2, secondhalf, secondhalflenth, temp);
        arraycopy(temp, 0, array,0, lenth);
        
        delete [] temp;
        delete [] firsthalf;
        delete [] secondhalf;
    }
    

}

void quickSort(int* arr,int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];
    
    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    
    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}