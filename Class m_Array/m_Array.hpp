//
//  m_Array.hpp
//  test
//
//  Created by KevinLiu on 16/12/4.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef m_Array_hpp
#define m_Array_hpp

#include <stdio.h>
#include <iostream>


#include <string>
using namespace std;

template <typename T>
class m_Array {
    T* array;
    int lenth;
    
public:
    m_Array(T arr[], int lenth);
//    int getlenth();
    void display();
    void insertSort();
    void selectSort();
    void quickSort();
    void mergeSort();
    void bubbleSort();
    
};


#endif /* m_Array_hpp */
