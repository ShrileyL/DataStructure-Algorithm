//
//  main.cpp
//  classtest
//
//  Created by KevinLiu on 16/9/26.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include <iostream>
#include "SHAPE.hpp"
#include "COMPLEX.hpp"

using namespace std;


int main(int argc, const char * argv[]) {
 

/*********** multiDerived_test ******
 *** Base:                  shape
 *** Derived:    Figure1P          Figure2P
 *** Derived: Circle Square    Rectangle Oval
 ********************************/

//    shape **objs = new shape*[5];
    // allocate space for 10 BasePoint pointers,
    // they may be used to store derived classes
    
    // creating objects
 //   objs[0] = new Circle(7, 6, 55);
    //objs[1] = new Rectangle(12, 54, 21, 14);
    //objs[2] = new Square(19, 32, 10);
    //objs[3] = new Oval(43, 10, 4, 3);
    //objs[4] = new Square(3, 41, 3);
    
/*    bool flag=false;
    do {
        cout << endl << "We have 5 objects with numbers 0..4" << endl;
        cout << "Enter object number to view information about it " << endl;
        cout << "Enter any other number to quit " << endl;
        char onum; // in fact, this is a character, not a number
        // this allows user to enter letter and quit...
        cin >> onum;
        
        // flag -- user have entered number 0..4
        flag = ((onum >= '0')&&(onum <= '4'));
        
        if (flag)
            objs[onum-'0']->info();
        
    } while(flag);
 */
  //  objs[0]->info();
  //  cout << objs[0]->type() << " area: " << objs[0]->area() << endl;
    
    // freeing memory 
/*    for(int i=0;i<5;i++)
        delete objs[i];
    
    delete [] objs;
*/
    
/*********** OperatorOveload_test ******
 *** class complex
 *** overlop operator + - * /
 ***
 ********************************/
    
    complex c1,c2(1.0,2.0),c3(3.0,-4.0);
    print(c2);
    print(c3);
    c1 = c2 + c3;
    cout << "c2+c3=";
    print(c1);
    c1 = c2 - c3;
    cout << "c2-c3=";
    print(c1);
    c1 = c2 * c3;
    cout << "c2*c3=";
    print(c1);
    c1 = c2 / c3;
    cout << "c2/c3=";
    print(c1);
   
    
    return 0;
}
