//
//  WOLF.cpp
//  classtest
//
//  Created by KevinLiu on 16/9/26.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include "WOLF.hpp"
#include <iostream>

using namespace std;

Wolf::Wolf(int classno,int no):Animal(classno)
{
    WolfNo = no;
    cout << "Wolf constructor is called. No = " << WolfNo << endl;
}

Wolf::~Wolf()
{
    cout << "Wolf destructor is called." << endl;
}
