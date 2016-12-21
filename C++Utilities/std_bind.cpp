//
//  main.cpp
//  test for Lambda Fuction
//
//  Created by KevinLiu on 16/12/21.
//  Copyright © 2016年 KevinLiu. All rights reserved.

#include <iostream>

int add(int first, int second)
{
    return first + second;
}

int main()
{
    auto add_func = std::bind(&add,std::placeholders::_1,std::placeholders::_2);
    std::cout << add_func(4,5) << std::endl;
    
    auto new_add_func = std::bind(&add, 12,std::placeholders::_1);
    int x = new_add_func(3);
    std::cout << x << std::endl;
    
    auto mod_add_func = std::bind(&add, std::placeholders::_2, std::placeholders::_1);
    std::cout << mod_add_func(12,15) << std::endl;
//    When we call mod_add_func(12,15) it is equivalent to calling add(15, 12).
    
    return 0;
}


#include <memory>
#include <functional>
#include <iostream>
#include <algorithm>

using namespace std::placeholders;


int add(int first, int second)
{
	return first + second;
}

bool divisible(int num , int den)
{
	if(num % den == 0)
		return true;
	return false;

}
int approach_1()
{
	int arr[10] = {1,20,13,4,5,6,10,28,19,15};
	int count = 0;
	for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
	{
		if(divisible(arr[i], 5))
			count++;
	}
	return count;

}

int approach_2()
{
	int arr[10] = {1,20,13,4,5,6,10,28,19,15};
	return std::count_if(arr, arr + sizeof(arr)/sizeof(int) , std::bind(&divisible, _1, 5));

}

int main()
{
	int x = add(4,5);
	// Will return 9

	// What if we want to fix the first argument
	auto new_add_func = std::bind(&add, 12, _1);

	x = new_add_func(5);
	// Will return 17

	std::cout<<x<<std::endl;



	auto mod_add_func = std::bind(&add, _2, _1);

	x = mod_add_func(12, 15);
	// Will return 27
	std::cout<<x<<std::endl;

	std::function<int (int) > mod_add_funcObj = std::bind(&add, 20, _1);
	x = mod_add_funcObj(15);
	// Will return 35

	std::cout<<x<<std::endl;

	std::cout<<approach_1()<<std::endl;

	std::cout<<approach_2()<<std::endl;
	return 0;
}