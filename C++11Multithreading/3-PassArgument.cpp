//
//  main.cpp
//  test for creat multithread
//
//  Created by KevinLiu on 16/12/18.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

// #Tips 1: How to pass argument to thread:
// To Pass arguments to thread’s associated callable object or function 
// just pass additional arguments to the std::thread constructor.
// By default all arguments are copied into the internal storage of new thread.
#include <iostream>
#include <string>
#include <thread>
void threadCallback(int x, std::string str)
{
	std::cout<<"Passed Number = "<<x<<std::endl;
	std::cout<<"Passed String = "<<str<<std::endl;
}
int main()  
{
	int x = 10;
	std::string str = "Sample String";
	std::thread threadObj(threadCallback, x, str);
	threadObj.join();
	return 0;
}

// #Tips 2: Don’t pass arguments to threads
// Don’t pass addresses of variables from local stack to thread’s callback function. 
// Because it might be possible that local variable in Thread 1 goes out of scope 
// but Thread 2 is still trying to access it through it’s address.
// In such scenario accessing invalid address can cause unexpected behaviour.

#include <iostream>
#include <thread>
void newThreadCallback(int * p)
{
    std::cout<<"Inside Thread :  "" : p = "<<p<<std::endl;
    std::chrono::milliseconds dura( 1000 );
    std::this_thread::sleep_for( dura );
    *p = 19;
}
void startNewThread()
{
    int i = 10;
    std::cout<<"Inside Main Thread :  "" : i = "<<i<<std::endl;
    std::cout<<"Inside Main Thread :  ""address of i = "<<&i<<std::endl;
    std::thread t(newThreadCallback,&i);
    t.detach();
    std::cout<<"Inside Main Thread :  "" : i = "<<i<<std::endl;
}
int main()
{
	//thread t was create in the scope "startNewThread"
	// and destroy after the call of "startNewThread"
    startNewThread();
    std::chrono::milliseconds dura( 2000 );
    std::this_thread::sleep_for( dura );
    return 0;
}

//but we can see in output that
// thread t may not finished after main finish
// so it can access to address of the socpe varible "i"
// which may cause unexpect behavour
/*
Output:
Inside Main Thread :   : i = 10
Inside Main Thread :  address of i = 0x7fff5fbff75c
Inside Main Thread :   : i = 10
Inside Thread :   : p = 0x7fff5fbff75c
Program ended with exit code: 0
*/

// #Tips 3: Be careful while passing pointer to memory located on heap to thread
// Because it might be possible that some thread deletes that memory before new thread tries to access it.
// In such scenario accessing invalid address can cause unexpected behaviour.
#include <iostream>
#include <thread>
void newThreadCallback(int * p)
{
	std::cout<<"Inside Thread :  "" : p = "<<p<<std::endl;
	//std::cout<<"Inside Thread :  "" : *p = "<<*p<<std::endl;
	std::chrono::milliseconds dura( 1000 );
	std::this_thread::sleep_for( dura );
	*p = 19;
}
void startNewThread()
{
	int * p = new int();
	*p = 10;
	std::cout<<"Inside Main Thread :  "" : *p = "<<*p<<std::endl;
	//std::cout<<"Inside Main Thread :  "" : p = "<<p<<std::endl;
	std::thread t(newThreadCallback,p);
	t.detach();
	delete p;
	p = NULL;
}
int main()
{
	startNewThread();
	std::chrono::milliseconds dura( 2000 );
	std::this_thread::sleep_for( dura );
	return 0;
}

// #Tips 4: Pass reference to thread
// As arguments are copied to new threads stack so, 
// if you need to pass references in common way i.e.

#include <iostream>
#include <thread>
void threadCallback(int const & x)
{
	int & y = const_cast<int &>(x);
	y++;
	std::cout<<"Inside Thread x = "<<x<<std::endl;
}
int main()
{
	int x = 9;
	std::cout<<"In Main Thread : Before Thread Start x = "<<x<<std::endl;
	//by default, varible was pass by value
	std::thread threadObj(threadCallback, x);
	threadObj.join();
	std::cout<<"In Main Thread : After Thread Joins x = "<<x<<std::endl;
	return 0;
}

/* Output:
In Main Thread : Before Thread Start x = 9
Inside Thread x = 10
In Main Thread : After Thread Joins x = 9
*/

// Even if threadCallback accepts arguments as reference 
// but still changes done it are not visible outside the thread.
// Its because x in the thread function threadCallback is reference 
// to the temporary value copied at the new thread’s stack.

// Using Std::ref() to fix it:
#include <iostream>
#include <thread>
void threadCallback(int const & x)
{
	int & y = const_cast<int &>(x);
	y++;
	std::cout<<"Inside Thread x = "<<x<<std::endl;
}
int main()
{
	int x = 9;
	std::cout<<"In Main Thread : Before Thread Start x = "<<x<<std::endl;
	// use std::ref()
	std::thread threadObj(threadCallback,std::ref(x));
	threadObj.join();
	std::cout<<"In Main Thread : After Thread Joins x = "<<x<<std::endl;
	return 0;
}

/* Output:
In Main Thread : Before Thread Start x = 9
Inside Thread x = 10
In Main Thread : After Thread Joins x = 10
*/

// #Tips 5: Assigning pointer to member function of a class as thread function:
// Pass the pointer to member function as callback function 
// and pass pointer to Object as second argument.
#include <iostream>
#include <thread>
class DummyClass {
public:
	DummyClass()
	{}
	DummyClass(const DummyClass & obj)
	{}
	void sampleMemberFunction(int x)
	{
		std::cout<<"Inside sampleMemberFunction "<<x<<std::endl;
	}
};
int main() {

	DummyClass dummyObj;
	int x = 10;
	std::thread threadObj(&DummyClass::sampleMemberFunction,&dummyObj, x);
	threadObj.join();
	return 0;
}