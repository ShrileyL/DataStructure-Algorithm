//
//  TDATE.hpp
//  classtest
//
//  Created by KevinLiu on 16/9/26.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef TDATE_hpp
#define TDATE_hpp

#include <stdio.h>
class Tdate
{
private:
    int year;
    int month;
    int day;
    
public:
    Tdate();//constructor
    //copy constructor
    Tdate(const Tdate &date);
    //Destructor
    ~Tdate();
    void set(int y, int m, int d);
    bool isLeapYear();

    void print();
    
};


#endif /* TDATE_hpp */
