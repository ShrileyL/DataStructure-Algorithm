//
//  COMPLEX.cpp
//  classtest
//
//  Created by KevinLiu on 16/9/27.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include "COMPLEX.hpp"
#include <iostream>

using namespace std;

complex::complex()
{
    real = imag = 0;
}

complex::complex(double r,double i)
{
    real = r;
    imag = i;
}

//// binary operator as member function
complex complex::operator+(const complex &c)
{
    return complex(real+c.real,imag+c.imag);
}

complex complex::operator *(const complex &c){
    return complex(real*c.real-imag*c.imag,imag*c.real+real*c.imag);
}

// binary operator as non-member function with 2 arguments
complex operator -(const complex &c1,const complex &c2)
{
    return complex(c1.real-c2.real,c1.imag-c2.imag);
}

complex operator /(const complex &c1,const complex &c2)
{
    double newr = (c1.real*c2.real + c1.imag*c2.imag)/norm(c2);
    double newi = (c2.real*c1.imag - c1.real*c2.imag)/norm(c2);
    return complex(newr,newi);
}

// binary operator as non-member function with 1 arguments
double norm(const complex &c)
{
    return c.real*c.real+c.imag*c.imag;
}

void print(const complex &c)
{
    if (c.imag < 0) {
        cout << c.real << c.imag <<"i" <<endl;
    } else {
        if (c.imag == 0) {
            cout << c.real<<endl;
        } else {
            cout << c.real << "+" << c.imag <<"i" <<endl;
        }
        
    }
}
