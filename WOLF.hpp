//
//  WOLF.hpp
//  classtest
//
//  Created by KevinLiu on 16/9/26.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef WOLF_hpp
#define WOLF_hpp

#include <stdio.h>
#include "ANIMAL.hpp"
class Wolf:virtual public Animal
{
    int WolfNo;
public:
    Wolf(int classno,int no);
    ~Wolf();

};

#endif /* WOLF_hpp */
