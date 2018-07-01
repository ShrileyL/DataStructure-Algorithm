//
//  main.cpp
//  test
//
//  Created by Shulin on 2018/6/15.
//  Copyright © 2018年 Shulin. All rights reserved.
//

#include <iostream>
#include <vector>
#include "array.hpp"
using namespace std;

int main(int argc, char const *argv[])
{
	//std::vector<int> v1,v2,v3;
	int v[] = {3,2,9};
	std::vector<int> v1(v, v+sizeof(v)/sizeof(int)),v2;
	v2 = plusOne(v1);
	display(v2);
	// display(v1,removeDuplicatesII(v1));
	// v1.push_back(1);
	// v1.push_back(2);
	// v1.push_back(3);
	// v1.push_back(4);

	// v2.push_back(4);
	// v2.push_back(2);
	// v3 = intersection(v1,v2);

	// for (int i = 0; i < v3.size(); ++i)
	// {
	// 	std::cout << v3[i] << " ";
	// }
	// std::cout<<std::endl;

	return 0;
}