//
//  WOLFDOG.hpp
//  classtest
//
//  Created by KevinLiu on 16/9/26.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef WOLFDOG_hpp
#define WOLFDOG_hpp

#include <stdio.h>
#include "ANIMAL.hpp"
#include "DOG.hpp"
#include "WOLF.hpp"

class WolfDog:public Wolf,public Dog
{
    int WolfDogNo;
public:
    WolfDog(int classno, int wolfno, int dogno,int no);
    ~WolfDog();
};

#endif /* WOLFDOG_hpp */
