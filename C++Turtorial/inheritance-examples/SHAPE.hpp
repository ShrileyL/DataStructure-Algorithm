//
//  SHAPE.hpp
//  classtest
//
//  Created by KevinLiu on 16/9/27.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef SHAPE_hpp
#define SHAPE_hpp

#include <stdio.h>
#include <string>
using namespace std;

class shape
{
private:
    double x;
    double y;
public:
    shape(double px,double py);
    void set(double a, double b);
    virtual string type();
    virtual void info();
    virtual double area(){return 0;};
    virtual double getx(){return x;};
    virtual double gety(){return y;};
};

class Figure1P : public shape
{
    double p1;
public:
    Figure1P(double px,double py,double r);
    virtual void info();
    virtual double getp1(){return p1;};
};

class Square : public Figure1P
{
    double wide;
public:
    Square(double px,double py,double r);
    virtual string type();
    double area();
};

class Circle : public Figure1P
{
    double radiu;
public:
    Circle(double px,double py,double r);
    virtual string type();
    double area();
};

class Figure2P : public Figure1P
{
    double p2;
public:
    
    Figure2P(double px,double py,double a,double b);
    virtual void info();
    virtual double getp2(){return p2;};
};

class Rectangle : public Figure2P
{
  //  double wide;
    //double length;
public:
    Rectangle (double px,double py,double a,double b);
    virtual string type();
    double area();
};

class Oval : public Figure2P
{
public:
    Oval (double px,double py,double a,double b);
    virtual string type();
    double area();
};
#endif /* SHAPE_hpp */
