//
//  main.cpp
//  test for creat multithread
//
//  Created by KevinLiu on 16/12/19.
//  Copyright © 2016年 KevinLiu. All rights reserved.

// Many times we encounter a situation where we want a thread to return a result.

// Suppose in our application we created a thread that will compress a given folder 
// and we want this thread to return the new zip file name and its size in result.

// 1.) Old Way : Share data among threads using pointer

// Pass a pointer to the new thread and this thread will set the data in it. 
// Till then in main thread keep on waiting using a condition variable. 
// When new thread sets the data and signals the condition variable, 
// then main thread will wake up and fetch the data from that pointer.

// To do a simple thing we used a condition variable, a mutex and a pointer i.e. 3 items to catch a returned value.
// Now suppose we want this thread to return 3 different values at different point of time then problem will become more complex. 
// Could there be a simple solution for returning the value from threads.

// 2.) C++11 Way : Using std::future and std::promise

// std::future is a class template and its object stores the future value.
// Now what the hell is this future value.

// Actually a std::future object internally stores a value that will be assigned in future and it also provides a mechanism to access that value 
// i.e. using get() member function. But if somebody tries to access this associated value of future through get() function before it is available, 
// then get() function will block till value is not available.

// std::promise is also a class template and its object promises to set the value in future. 
// Each std::promise object has an associated std::future object that will give the value once set by the std::promise object.

// A std::promise object shares data with its associated std::future object.

#include <iostream>
#include <thread>
#include <future>

void initiazer(std::promise<int> * promObj)
{
	std::cout<<"Inside Thread"<<std::endl;
	promObj->set_value(35);
}

int main()
{
	std::promise<int> promiseObj;
	std::future<int> futureObj = promiseObj.get_future();
	std::thread th(initiazer, &promiseObj);
	std::cout<<futureObj.get()<<std::endl;
	th.join();
	return 0;
}
