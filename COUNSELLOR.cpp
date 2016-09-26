//
//  COUNSELLOR.cpp
//  classtest
//
//  Created by KevinLiu on 16/9/26.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include "COUNSELLOR.hpp"
#include "STUDENT.hpp"
#include <iostream>

using namespace std;

Counsellor::Counsellor(int n, char *pName)
{
    No = n;
    strcpy(name, pName);
    cout << "Counsellor constructor called." << endl;
}

Counsellor::~Counsellor()
{
    cout << "Counsellor destructor called." << endl;
}

void Counsellor::assess(Student &s, int assessment_score)
{
    s.Assessment_Score = assessment_score;
}

void Counsellor::print()
{
    cout << "Counsellor: " << "[" << No << "]" << name << endl;
}
