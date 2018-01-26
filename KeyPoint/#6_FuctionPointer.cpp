//
//  
//  function pointer
//
//  Created by Shirley on 18/1/26.
//  Copyright © 2018年 KevinLiu. All rights reserved.
//


#include <iostream>

void swap(int* a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool ascending(int x, int y)
{
    return (x < y);
}

bool descending(int x, int y)
{
    return (x > y);
}


void SelectionSort(int* array, int size,comparision func)
{
    for(int startIndex = 0;startIndex < size;++startIndex)
    {
        int bestIndex = startIndex;
        for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
        {
            if (func(array[currentIndex],array[bestIndex]))
            {
                bestIndex = currentIndex;
            }
        }
        swap(&array[bestIndex], &array[startIndex]);
    }
}


void display(int *array, int size)
{
    for(int i = 0; i <size ;++i)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}
int main()
{
//    int a = 2;
//    int b = 8;
//    swap(&a, &b);
//    std::cout << a << " " << b << std::endl;
    int array[9] = {5,3,4,1,6,2,8,9,7};
    display(array, 9);
    
    SelectionSort(array, 9, ascending);
    display(array, 9);
    
    SelectionSort(array, 9, descending);
    display(array, 9);
    
    return 0;
}