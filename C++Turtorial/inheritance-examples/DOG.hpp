//
//  DOG.hpp
//  classtest
//
//  Created by KevinLiu on 16/9/26.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef DOG_hpp
#define DOG_hpp

#include <stdio.h>
#include "ANIMAL.hpp"
class Dog:virtual public Animal
{
    int DogNo;
public:
    Dog(int classno,int no);
    ~Dog();
    
};
#endif /* DOG_hpp */
