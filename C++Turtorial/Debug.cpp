//
//  main.cpp
//  debug
//
//  Created by KevinLiu on 17/1/18.
//  Copyright © 2017年 KevinLiu. All rights reserved.
//

#include <iostream>

using namespace std;

#define _DEBUG

int main()
{
    #ifdef _DEBUG
    cout << "debug is defined." << endl;
    #else
    cout << "wrong." << endl;
    #endif

    cout << "Hello." << endl;
    
    return 0;
}