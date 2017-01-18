//
//  COUNSELLOR.hpp
//  classtest
//
//  Created by KevinLiu on 16/9/26.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef COUNSELLOR_hpp
#define COUNSELLOR_hpp

#include <stdio.h>
#include "STUDENT.hpp"
class Counsellor
{
private:
    int No;
    char name[10];
public:
    Counsellor(int n,char *pName);
    ~Counsellor();
    void assess(Student &s, int assessment_score);
    void print();
};

#endif /* COUNSELLOR_hpp */
