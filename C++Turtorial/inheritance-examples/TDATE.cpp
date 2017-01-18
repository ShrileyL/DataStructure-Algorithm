//
//  TDATE.cpp
//  classtest
//
//  Created by KevinLiu on 16/9/26.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include "TDATE.hpp"
#include <iostream>
using namespace std;

Tdate::Tdate():year(1000),month(1),day(1)
{
    cout << "Default constructor." << endl;
}

Tdate::Tdate(const Tdate &date)
{
    cout << "Copy constructor" << endl;
    year = date.year + 1;
    month = date.month + 1;
    day = date.day + 1;
}

Tdate::~Tdate()
{
    cout << "Destructor." << endl;
}

void Tdate::set(int y, int m, int d){
    year = y;
    month = m;
    day = d;
}

bool Tdate::isLeapYear()
{
    return ((year%4 == 0&&(year%100!= 0))||year%400 == 0);
}

void Tdate::print()
{
    cout << year <<"-" << month << "-" << day << endl;
}

