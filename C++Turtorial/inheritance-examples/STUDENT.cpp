//
//  STUDENT.cpp
//  classtest
//
//  Created by KevinLiu on 16/9/26.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include "STUDENT.hpp"
#include <iostream>

using namespace std;

Student::Student(int n, char *pName)
{
    No = n;
    strcpy(name, pName);
    cout << "Student constructor called." << endl;
}

Student::~Student()
{
    cout << "class Student destructor called" << endl;
}

void Student::print()
{
    cout << "[" << No << "]" << name << endl;
}


void Student::Learn()
{
    cout << "Student " << name << " is learning." << endl;
}
