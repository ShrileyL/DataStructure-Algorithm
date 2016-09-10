//
//  main.cpp
//  Inheritance
//  Sourses from:
//  http://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm
//  Created by KevinLiu on 16/9/10.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

/*   
   basic & derived Class
   A class can be derived from more than one classes, 
   which means it can inherit data and functions from multiple base classes

*/

 /*
    Metion:
    a derived class can access all non-private members of its basic class
    so to control access, member function should to be claimed private if do not need to be acess
    Thus base-class members that should not be accessible to the member functions of derived classes
 should be declared private in the base class.
 */

   #include <iostream>
 
using namespace std;

// Base class
class Shape 
{
   public:
      void setWidth(int w)
      {
         width = w;
      }
      void setHeight(int h)
      {
         height = h;
      }
   protected:
      int width;
      int height;
};

// Derived class
class Rectangle: public Shape
{
   public:
      int getArea()
      { 
         return (width * height); 
      }
};

int main(void)
{
   Rectangle Rect;
 
   Rect.setWidth(5);
   Rect.setHeight(7);

   // Print the area of the object.
   cout << "Total area: " << Rect.getArea() << endl;

   return 0;
}

//*********************
//multiple inheritance
//*********************

#include <iostream>
 
using namespace std;

// Base class Shape
class Shape 
{
   public:
      void setWidth(int w)
      {
         width = w;
      }
      void setHeight(int h)
      {
         height = h;
      }
   protected:
      int width;
      int height;
};

// Base class PaintCost
class PaintCost 
{
   public:
      int getCost(int area)
      {
         return area * 70;
      }
};

// Derived class
class Rectangle: public Shape, public PaintCost
{
   public:
      int getArea()
      { 
         return (width * height); 
      }
};

int main(void)
{
   Rectangle Rect;
   int area;
 
   Rect.setWidth(5);
   Rect.setHeight(7);

   area = Rect.getArea();
   
   // Print the area of the object.
   cout << "Total area: " << Rect.getArea() << endl;

   // Print the total cost of painting
   cout << "Total paint cost: $" << Rect.getCost(area) << endl;

   return 0;
}

