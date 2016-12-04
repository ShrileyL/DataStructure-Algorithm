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

int* insertSort(int arr[], int n);
void display(int* arr,int n);

int main()
{
    int arr[] = {1,8,3,23,2};
    int* array = arr;
   
//    display(array,5);

    display(insertSort(array, 5),5);
    
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
