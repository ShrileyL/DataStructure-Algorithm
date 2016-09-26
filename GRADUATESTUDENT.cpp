//
//  GRADUATESTUDENT.cpp
//  classtest
//
//  Created by KevinLiu on 16/9/26.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include "GRADUATESTUDENT.hpp"
#include "STUDENT.hpp"
#include <string>
#include <iostream>
using namespace std;

GraduateStudent::GraduateStudent(int n,char *pName,int grd,char *sup):Student(n,pName)
{
    grade = grd;
    strcpy(supervisor, sup);
    cout << "GraduateStudent destructor called." << endl;
};

GraduateStudent::~GraduateStudent()
{
    cout  << "Derived class GraduateStudent destructor called." << endl;
}

void GraduateStudent::printSupervisor()
{
    print();
    cout << "[supervisor]:" << supervisor << endl;
    cout << "[grade]:" << grade << endl;
}

void GraduateStudent::Learn()
{
    cout << "GrduateStudent is learning." << endl;
}
