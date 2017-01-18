//
//  WOLFDOG.cpp
//  classtest
//
//  Created by KevinLiu on 16/9/26.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include "WOLFDOG.hpp"
#include <iostream>

using namespace std;

WolfDog::WolfDog(int classno,int Wolfno, int Dogno,int no):Animal(classno),Wolf(classno,Wolfno),Dog(classno,Dogno)
{
    WolfDogNo = no;
    cout << "WolfDog constructor is called. No = " << WolfDogNo << endl;
}

WolfDog::~WolfDog()
{
    cout << "WolfDog destructor is called." << endl;
}
