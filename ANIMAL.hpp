//
//  ANIMAL.hpp
//  classtest
//
//  Created by KevinLiu on 16/9/26.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef ANIMAL_hpp
#define ANIMAL_hpp

#include <stdio.h>
class Animal
{
private:
    int classNo;
public:
    Animal(int n);
    ~Animal();
    
    void print();
};


#endif /* ANIMAL_hpp */
