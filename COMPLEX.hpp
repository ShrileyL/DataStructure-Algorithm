//
//  COMPLEX.hpp
//  classtest
//
//  Created by KevinLiu on 16/9/27.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef COMPLEX_hpp
#define COMPLEX_hpp

#include <stdio.h>
class complex
{
    double real,imag;
public:
    complex();
    complex(double r, double i);
    complex operator +(const complex &c);
    complex operator *(const complex &c);
    friend complex operator -(const complex &c1,const complex &c2);
    friend complex operator /(const complex &c1,const complex &c2);
    friend double norm(const complex &c);
    friend void print(const complex &c);
};

#endif /* COMPLEX_hpp */
