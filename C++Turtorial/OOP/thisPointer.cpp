//
//  main.cpp
//  this pointer
//  Sourses from:
//  http://www.tutorialspoint.com/cplusplus/cpp_this_pointer.htm
//  Created by KevinLiu on 16/9/9.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

/*   
   The this pointer is an implicit parameter to all member functions. 
   Therefore, inside a member function, this may be used to refer to the invoking object.

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
      int compare(Box box)
      {
         return this->Volume() > box.Volume();
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

   if(Box1.compare(Box2))
   {
      cout << "Box2 is smaller than Box1" <<endl;
   }
   else
   {
      cout << "Box2 is equal to or larger than Box1" <<endl;
   }
   return 0;
}