//
//  main.cpp
//  Operator +/-/<
//  Sourses from:
//  http://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm
//  Created by KevinLiu on 16/9/10.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include <iostream>
using namespace std;
 
class Distance
{
   private:
      int feet;             // 0 to infinite
      int inches;           // 0 to 12
   public:
      // required constructors
      Distance(){
         feet = 0;
         inches = 0;
      }
      Distance(int f, int i){
         feet = f;
         inches = i;
      }
      // method to display distance
      void displayDistance()
      {
         cout << "F: " << feet << " I:" << inches <<endl;
      }
      // overloaded minus (-) operator
      Distance operator- ()  
      {
         feet = -feet;
         inches = -inches;
         return Distance(feet, inches);
      }
};
int main()
{
   Distance D1(11, 10), D2(-5, 11);
 
   -D1;                     // apply negation
   D1.displayDistance();    // display D1

   -D2;                     // apply negation
   D2.displayDistance();    // display D2

   return 0;
}

//********************
//my apply of operator !
//********************

#include <iostream>
using namespace std;

class Distance
{
private:
    bool flag;
    int inches;           // 0 to 12
public:
    // required constructors
    Distance(){
        flag = true;
        inches = 0;
    }
    Distance(bool f, int i){
        flag = f;
        inches = i;
    }
    // method to display distance
    void displayDistance()
    {
        cout << "F: " << flag << " I:" << inches <<endl;
    }
    // overloaded minus (-) operator
    Distance operator! ()
    {
        flag = !flag;
        inches = -inches;
        return Distance(flag, inches);
    }
};
int main()
{
    Distance D1(true, 10), D2(false, 11);
    
    !D1;                     // apply negation
    D1.displayDistance();    // display D1
    
    !D2;                     // apply negation
    D2.displayDistance();    // display D2
    
    return 0;
}


//**********************
//Relational operators
//**********************

#include <iostream>
using namespace std;
 
class Distance
{
   private:
      int feet;             // 0 to infinite
      int inches;           // 0 to 12
   public:
      // required constructors
      Distance(){
         feet = 0;
         inches = 0;
      }
      Distance(int f, int i){
         feet = f;
         inches = i;
      }
      // method to display distance
      void displayDistance()
      {
         cout << "F: " << feet << " I:" << inches <<endl;
      }
      // overloaded minus (-) operator
      Distance operator- ()  
      {
         feet = -feet;
         inches = -inches;
         return Distance(feet, inches);
      }
      // overloaded < operator
      bool operator <(const Distance& d)
      {
         if(feet < d.feet)
         {
            return true;
         }
         if(feet == d.feet && inches < d.inches)
         {
            return true;
         }
         return false;
      }
};
int main()
{
   Distance D1(11, 10), D2(5, 11);
 
   if( D1 < D2 )
   {
      cout << "D1 is less than D2 " << endl;
   }
   else
   {
      cout << "D2 is less than D1 " << endl;
   }
   return 0;
}