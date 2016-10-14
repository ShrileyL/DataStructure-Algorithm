//
//  main.cpp
//  MonsterGame
//
//  Created by KevinLiu on 16/10/14.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include <iostream>
#include "Moster.hpp"

using namespace std;


int main()
{
    //Moster skele(Moster::Skeleton, "Bones", "*rattle*", 4);
    //skele.print();
    
    //Moster m = MonsterGenerator::generateMonster();
    //m.print();
    
    srand(static_cast<unsigned int>(time(0))); // set initial seed value to system clock
    rand(); // If using Visual Studio, discard first random value
    
    Moster m = MonsterGenerator::generateMonster();
    m.print();
    
    return 0;
}
 

