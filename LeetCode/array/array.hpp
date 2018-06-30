//
//  array.hpp
//  test
//
//  Created by Shulin on 2018/6/15.
//  Copyright © 2018年 Shulin. All rights reserved.
//

#ifndef array_hpp
#define array_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

void display(std::vector<int>& v);
void display(std::vector<int>& v, int size);

int removeDuplicates(std::vector<int>& nums);
int removeDuplicatesII(std::vector<int>& nums);
std::vector<int> plusOne(std::vector<int>& digits);

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2);

#endif /* array_hpp */