//
//  main.cpp
//  Inline Function
//  Sourses from:
//  http://www.tutorialspoint.com/cplusplus/cpp_inline_functions.htm
//  Created by KevinLiu on 16/9/9.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//


//   inline int min(int first, int secend) {/****/}

//  not understand completely yet


#include <iostream>
 
using namespace std;

inline int Max(int x, int y)
{
   return (x > y)? x : y;
}

// Main function for the program
int main( )
{

   cout << "Max (20,10): " << Max(20,10) << endl;
   cout << "Max (0,200): " << Max(0,200) << endl;
   cout << "Max (100,1010): " << Max(100,1010) << endl;
   return 0;
}