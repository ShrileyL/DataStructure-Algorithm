//
//  SHAPE.cpp
//  classtest
//
//  Created by KevinLiu on 16/9/27.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include "SHAPE.hpp"
#include <stdio.h>
#include <string>
#include <iostream>
#define PI 3.1415926;
using namespace std;

shape::shape(double px,double py)
{
    x = px;
    y = py;
    cout << "Shape constructor is called." << endl;
}

string shape::type()
{
    return 0;
}

void shape::set(double a, double b)
{
    x = a;
    y = b;
}

void shape::info()
{
    cout << "figure: " << type() << endl;
    cout << "position: x=" << x << ", y=" << y << endl;
}

Figure1P::Figure1P(double px,double py,double r):shape(px,py)
{
    p1 = r;
    cout << "Figure1P constructor is called." << endl;
}
void Figure1P::info()
{
    //shape:info();
    cout << "property 1: p1=" << p1 << endl;
}

Figure2P::Figure2P(double px,double py,double r1,double r2):Figure1P(px,py,r1)
{
    p2 = r2;
    cout << "Figure2P constructor is called." << endl;
}

void Figure2P::info()
{
    Figure1P::info();
    cout << "property 2: p2=" << p2 << endl;
}


//Square Impletement
Square::Square(double px,double py,double r):Figure1P(px,py,r)
{
    wide = r;
    cout << "Square constructor is called." << endl;
}

string Square::type()
{
    return "Square";
}

double Square::area()
{
    return wide*wide;
}


//Circle Impletement
Circle::Circle(double px,double py,double r):Figure1P(px,py,r)
{
    radiu = r;
    cout << "Circle constructor is called." << endl;
}

string Circle::type()
{
    return "Circle";
}

double Circle::area()
{
    return 2*radiu*radiu*PI;
}


//Rectangle Impletement
Rectangle::Rectangle (double px,double py,double a,double b):Figure2P(px,py,a,b)
{
    cout << "Rectangle constructor is called." << endl;
}

string Rectangle::type()
{
    return "Rectangle";
}

//Calculate area using "get" function
double Rectangle::area()
{
    return (getp1())*(getp2());
}

//Oval Impletement
Oval::Oval (double px,double py,double a,double b):Figure2P(px,py,a,b)
{
    cout << "Oval constructor is called." << endl;
}

string Oval::type()
{
    return "Oval";
}

//Calculate area using "get" function
double Oval::area()
{
    return getp1()*(getp2())*2*PI;
}
