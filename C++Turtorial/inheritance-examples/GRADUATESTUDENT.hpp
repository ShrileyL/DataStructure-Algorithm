//
//  GRADUATESTUDENT.hpp
//  classtest
//
//  Created by KevinLiu on 16/9/26.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef GRADUATESTUDENT_hpp
#define GRADUATESTUDENT_hpp

#include <stdio.h>
#include "STUDENT.hpp"
#include <string>
using namespace std;

class GraduateStudent:public Student
{
private:
    int grade;
    char supervisor[10];
public:
    GraduateStudent(int n,char *pName,int grd,char *sup);
    ~GraduateStudent();
    void printSupervisor();
    void Learn();
    
};

#endif /* GRADUATESTUDENT_hpp */
