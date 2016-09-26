//
//  DOG.cpp
//  classtest
//
//  Created by KevinLiu on 16/9/26.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include "DOG.hpp"
#include <iostream>

using namespace std;

Dog::Dog(int classno,int no):Animal(classno)
{
    DogNo = no;
    cout << "Dog constructor is called. No = " << DogNo << endl;
}

Dog::~Dog()
{
    cout << "Dog destructor is called." << endl;
}
