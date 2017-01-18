//
//  STUDENT.hpp
//  classtest
//
//  Created by KevinLiu on 16/9/26.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef STUDENT_hpp
#define STUDENT_hpp

#include <stdio.h>
#include <string>

class Student
{
private:
    int No;
    char name[10];
    int Assessment_Score;
    friend class Counsellor;
    friend void Assessment_Compare(Student &s1,Student &s2);
public:
    Student(int n,char *pName);
    ~Student();
    void Learn();
    void print();
    
};

#endif /* STUDENT_hpp */
