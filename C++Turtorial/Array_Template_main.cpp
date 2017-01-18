//
//  main.cpp
//  class Template Array main
//
//  Created by KevinLiu on 16/10/17.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include <iostream>

using namespace std;


#include "Array.hpp"
int main()
{
    Array<int> anArray(12);
    Array<double> adArray(12);
    
    for (int nCount = 0; nCount < anArray.GetLength(); nCount++)
    {
        anArray[nCount] = nCount;
        adArray[nCount] = nCount + 0.5;
    }
    
    for (int nCount = anArray.GetLength()-1; nCount >= 0; nCount--)
        std::cout << anArray[nCount] << "\t" << adArray[nCount] << std::endl;
    
    return 0;
}