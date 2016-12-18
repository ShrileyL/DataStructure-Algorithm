//
//  main.cpp
//  test for creat multithread
//
//  Created by KevinLiu on 16/12/16.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include <iostream>
#include <thread>
#include <algorithm>
#include <vector>
class WorkerThread
{
public:
    void operator()()
    {
        std::cout<<"Worker Thread "<<std::this_thread::get_id()<<" is Executing"<<std::endl;
    }
};

int main()
{
    std::vector<std::thread> threadList;
    for(int i = 0; i < 10; i++)
    {
        threadList.push_back( std::thread( WorkerThread() ) );
    }
    // Now wait for all the worker thread to finish i.e.
    // Call join() function on each of the std::thread object
    std::cout<<"wait for all the worker thread to finish"<<std::endl;
    std::for_each(threadList.begin(),threadList.end(), std::mem_fn(&std::thread::join));
    std::cout<<"Exiting from Main Thread"<<std::endl;
return 0;
}

//Detaching Thread:
// Detached threads are also called daemon / Background threads. 
// To detach a thread we need to call std::detach() function on std::thread object i.e.
//** std::thread th(funcPtr);
//** th.detach();

/*
Mentions:
Case 1: 
   Never call join() or detach() on std::thread object with no associated executing thread
    std::thread threadObj( (WorkerThread()) );
    threadObj.join();
    threadObj.join(); // It will cause Program to Terminate
Therefore, before calling join() or detach() we should check if thread is join-able every time
*/   

/*
Mentions:
Case 2: 
   Case 2 : Never forget to call either join or detach on a std::thread object with associated executing thread 
 
Therefore, before calling join() or detach() we should check if thread is join-able every time
*/ 

#include <iostream>
#include <thread>
#include <algorithm>
class WorkerThread
{
public:
	void operator()()     
	{
		std::cout<<"Worker Thread "<<std::endl;
	}
};
int main()  
{
	std::thread threadObj( (WorkerThread()) );
	// Program will terminate as we have't called either join or detach with the std::thread object.
	// Hence std::thread's object destructor will terminate the program
	return 0;
}


//Similarly we should not forget call either join() or detach() in case of exceptions. 
//To prevents with we should use RESOURCE ACQUISITION IS INITIALIZATION (RAII)
#include <iostream>
#include <thread>
class ThreadRAII
{
    std::thread & m_thread;
public:
    ThreadRAII(std::thread & threadObj) : m_thread(threadObj)
    {

    }
    ~ThreadRAII()
    {
        // Check if thread is joinable then detach the thread
        if(m_thread.joinable())
        {
            m_thread.detach();
        }
    }
};

void thread_function()
{
    for(int i = 0; i < 10000; i++);
    std::cout<<"thread_function Executing"<<std::endl;
}

int main()
{
    std::thread threadObj(thread_function);

    // If we comment this Line, then program will crash
    ThreadRAII wrapperObj(threadObj);
    return 0;
}