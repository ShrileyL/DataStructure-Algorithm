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
void display(int* arr,int n);

int main()
{
    int arr[] = {1,8,3,23,2};
    int* array = arr;
   
//    display(array,5);

    display(selectSort(array, 5),5);
    
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
