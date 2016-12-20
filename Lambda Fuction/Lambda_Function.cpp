//
//  main.cpp
//  test for Lambda Fuction
//
//  Created by KevinLiu on 16/12/20.
//  Copyright © 2016年 KevinLiu. All rights reserved.

// Lambda functions are a kind of anonymous functions in C++. 
// These are mainly used as callbacks in C++. Lambda function is like a normal function i.e.

// > You can pass arguments to it
// > It can return the result
// > But it doesn’t have any name. Its mainly used when we have to create very small functions to pass as a callback to an another API.

// Before going deep into lambda functions, lets understand what was the need of lambda functions.


//using a function pointer
#include <iostream>
#include <algorithm>

void display(int a)
{
	std::cout<<a<<" ";
}
int main() {
	int arr[] = { 1, 2, 3, 4, 5 };

	std::for_each(arr, arr + sizeof(arr) / sizeof(int), &display);
	   //  for (int i = 0; i < 5; ++i)
    // {
    //     display(*(arr+i));
    // }

	std::cout << std::endl;

}

// A lambda function is a kind of anonymous function which doesn’t have any name but you can pass arguments and return results from it. 
// Also all its content will work as in-line code.

// [](int x) {
//           std::cout<<x<<" ";
//     }

// > [] is used to pass the outer scope elements
// > (int x) shows argument x is passed

#include <iostream>
#include <algorithm>

int main() {
	int arr[] = { 1, 2, 3, 4, 5 };

	std::for_each(arr, arr + sizeof(arr) / sizeof(int), [](int x) {
		std::cout<<x<<" ";
		});

	std::cout << std::endl;

}


#include <iostream>
#include <algorithm>

int main() {
	int arr[] = { 1, 2, 3, 4, 5 };

	int mul = 5;

	std::for_each(arr, arr + sizeof(arr) / sizeof(int), [&](int x) {
		std::cout<<x<<" ";
		// Can modify the mul inside this lambda function because
		// all outer scope elements has write access here.
			mul = 3;
		});
	std::cout << std::endl;

	std::for_each(arr, arr + sizeof(arr) / sizeof(int), [=](int &x) {
		x= x*mul;
		std::cout<<x<<" ";
		// Can not modify the mul inside this lambda function because
		// all outer scope elements has read only access here.
		// mul = 9;

		});
	std::cout << std::endl;

	std::for_each(arr, arr + sizeof(arr) / sizeof(int), [](int x) {

		// No access to mul inside this lambda function because
		// all outer scope elements are not visible here.
		//std::cout<<mul<<" ";
		});
	std::cout << std::endl;

}

/* Output:
1 2 3 4 5 
3 6 9 12 15 

Program ended with exit code: 0

*/