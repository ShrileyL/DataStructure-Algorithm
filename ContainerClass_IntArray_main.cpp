//
//  main.cpp
//  Container Class IntArray
//
//  Created by KevinLiu on 16/10/17.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//
#include <iostream>
#include "IntArray.hpp"

int main()
{
    // Declare an array with 10 elements
    IntArray array(10);
    
    // Fill the array with numbers 1 through 10
    for (int i=0; i<10; i++)
        array[i] = i+1;
    
    // Resize the array to 8 elements
    array.resize(8);
    
    // Insert the number 20 before element with index 5
    array.insertBefore(20, 5);
    
    // Remove the element with index 3
    array.remove(3);
    
    // Add 30 and 40 to the end and beginning
    array.insertAtEnd(30);
    array.insertAtBeginning(40);
    
    // Print out all the numbers
    for (int j=0; j<array.getLength(); j++)
        std::cout << array[j] << " ";
    
    return 0;
}
