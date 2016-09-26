//
//  main.cpp
//  classtest
//
//  Created by KevinLiu on 16/9/26.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include <iostream>
#include "TDATE.hpp"
#include "COUNSELLOR.hpp"
#include "STUDENT.hpp"
#include "GRADUATESTUDENT.hpp"
#include "ANIMAL.hpp"
#include "DOG.hpp"
#include "WOLF.hpp"
#include "WOLFDOG.hpp"

using namespace std;

void Assessment_Compare(Student &s1,Student &s2)
{
    if (s1.Assessment_Score > s2.Assessment_Score) {
        cout << s1.name << " is more better than " << s2.name << endl;
    }
    else
        cout << s2.name << " is more better than " << s1.name<< endl;
};

int main(int argc, const char * argv[]) {
 /*********** construct&copyconstruct_test ******
  ************************************************/
    //Tdate d,d1;
    // d.set(2016, 9, 26);
    //Tdate d2(d1);
    //d1.print();
    //d.print();
    //if(d.isLeapYear())
    //   cout << "Leap year." << endl;
    //else
    //   cout << "Not Leap year." << endl;
    
    
 /*********** frind_test ********
  ********************************/
 /*   Student stu1(1,"Shirley");
    stu1.print();
    Student stu2(2,"Kevin");
    stu2.print();
    Counsellor coun(1,"Pao");
    coun.print();
    coun.assess(stu1, 100);
    coun.assess(stu2, 99);
    Assessment_Compare(stu1, stu2);
  */
    
    
/*********** simpleDerived_test ******
 *** Base:Student
 *** Derived:GraduateStudent
 ********************************/
    /*GraduateStudent grd(1, "Shirley",100, "Kevin");
    grd.printSupervisor();
 */
 
/*********** functionOverload_test ******
 *** Base:Student
 *** Derived:GraduateStudent
********************************/
    Student S(1,"Shirley");
    S.Learn();
    GraduateStudent GS(1,"Kevin",100,"Pao");
    GS.Student::Learn();
    GS.Learn();
    

/*********** multiDerived_test ******
 *** Base:        Animal
 *** Derived:  Wolf     Dog
 *** Derived:    WolfDog
 ********************************/
/*    WolfDog WD(10,101,102,1012);
    WD.print();
*/
    
    
    
    return 0;
}
