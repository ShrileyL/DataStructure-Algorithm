//
//  ANIMAL.cpp
//  classtest
//
//  Created by KevinLiu on 16/9/26.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include "ANIMAL.hpp"
#include <iostream>

using namespace std;
Animal::Animal(int n)
{
    classNo = n;
    cout << "class Animal constructor is called. No = " << classNo << endl;
}

Animal::~Animal()
{
    cout << "class Animal destructor is called." << endl;
}

void Animal::print()
{
    cout << "Animal classNo is " << classNo << endl;
}
