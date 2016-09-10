//
//  main.cpp
//  Point to class
//  Sourses from:
//  http://www.tutorialspoint.com/cplusplus/cpp_pointer_to_class.htm
//  Created by KevinLiu on 16/9/9.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

/*   
   like all pointers,must initialize the pointer before using it.
   A pointer to  class is done exactly the same way as a pointer to a structure 
   access members of a pointer to a class:use the member access operator -> operator

*/

#include <iostream>
 
using namespace std;

class Box
{
   public:
      // Constructor definition
      Box(double l=2.0, double b=2.0, double h=2.0)
      {
         cout <<"Constructor called." << endl;
         length = l;
         breadth = b;
         height = h;
      }
      double Volume()
      {
         return length * breadth * height;
      }
   private:
      double length;     // Length of a box
      double breadth;    // Breadth of a box
      double height;     // Height of a box
};

int main(void)
{
   Box Box1(3.3, 1.2, 1.5);    // Declare box1
   Box Box2(8.5, 6.0, 2.0);    // Declare box2
   Box *ptrBox;                // Declare pointer to a class.

   // Save the address of first object
   ptrBox = &Box1;

   // Now try to access a member using member access operator
   cout << "Volume of Box1: " << ptrBox->Volume() << endl;

   // Save the address of first object
   ptrBox = &Box2;

   // Now try to access a member using member access operator
   cout << "Volume of Box2: " << ptrBox->Volume() << endl;
  
   return 0;
}