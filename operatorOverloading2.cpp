//
//  main.cpp
//  Overloading2
//  Sourses from:
//  http://www.tutorialspoint.com/cplusplus/cpp_inheritance.htm
//  Created by KevinLiu on 16/9/10.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include <iostream>
using namespace std;
 
class Time
{
   private:
      int hours;             // 0 to 23
      int minutes;           // 0 to 59
   public:
      // required constructors
      Time(){
         hours = 0;
         minutes = 0;
      }
      Time(int h, int m){
         hours = h;
         minutes = m;
      }
      // method to display time
      void displayTime()
      {
         cout << "H: " << hours << " M:" << minutes <<endl;
      }
      // overloaded prefix ++ operator
      Time operator++ ()  
      {
         ++minutes;          // increment this object
         if(minutes >= 60)  
         {
            ++hours;
            minutes -= 60;
         }
         return Time(hours, minutes);
      }
      // overloaded postfix ++ operator
      Time operator++( int )         
      {
         // save the orignal value
         Time T(hours, minutes);
         // increment this object
         ++minutes;                    
         if(minutes >= 60)
         {
            ++hours;
            minutes -= 60;
         }
         // return old original value
         return T; 
      }
};
int main()
{
    Time T1(11, 59), T2(10,40),T3;
    
    ++T1;                    // increment T1
    T1.displayTime();        // display T1
    T3 = T1++;                    // give T1 value to T3 and increment T1 again 
    T3.displayTime();        // display T3
    T1.displayTime();
    
    T2++;                    // increment T2
    T2.displayTime();        // display T2
    T2++;                    // increment T2 again
    T2.displayTime();        // display T2
    return 0;
}


//**********************
// operator ()
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
      // overload function call
      Distance operator()(int a, int b, int c)
      {
         Distance D;
         // just put random calculation
         D.feet = a + c + 10;
         D.inches = b + c + 100 ;
         return D;
      }
      // method to display distance
      void displayDistance()
      {
         cout << "F: " << feet <<  " I:" <<  inches << endl;
      }
      
};
int main()
{
   Distance D1(11, 10), D2;

   cout << "First Distance : "; 
   D1.displayDistance();

   D2 = D1(10, 10, 10); // invoke operator()
   cout << "Second Distance :"; 
   D2.displayDistance();

   return 0;
}

//**********************
// operator []
//**********************

#include <iostream>
using namespace std;
const int SIZE = 10;

class safearay
{
   private:
      int arr[SIZE];
   public:
      safearay() 
      {
         register int i;
         for(i = 0; i < SIZE; i++)
         {
           arr[i] = i;
         }
      }
      int &operator[](int i)
      {
          if( i > SIZE )
          {
              cout << "Index out of bounds" <<endl; 
              // return first element.
              return arr[0];
          }
          return arr[i];
      }
};
int main()
{
   safearay A;

   cout << "Value of A[2] : " << A[2] <<endl;
   cout << "Value of A[5] : " << A[5]<<endl;
   cout << "Value of A[12] : " << A[12]<<endl;

   return 0;
}
