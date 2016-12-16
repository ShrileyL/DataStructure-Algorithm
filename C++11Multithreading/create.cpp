//
//  main.cpp
//  test for creat multithread
//
//  Created by KevinLiu on 16/12/16.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//


//Creating a thread using Function Pointer
#include <iostream>
#include <thread>

void thread_function()
{
    for(int i = 0; i < 10000; i++)
        std::cout<<"thread function Executing"<<std::endl;
}

int main()
{
    std::thread threadObj(thread_function);
    for(int i = 0; i < 10000; i++)
        std::cout<<"Display From MainThread"<<std::endl;
    threadObj.join();
    std::cout<<"Exit of Main function"<<std::endl;
    return 0;
}



//Creating a thread using Function Objects
#include <iostream>
#include <thread>
class DisplayThread
{
public:
    void operator()()
    {
        for(int i = 0; i < 10000; i++)
            std::cout<<"Display Thread Executing"<<std::endl;
    }
};

int main()
{
    std::thread threadObj( (DisplayThread()) );
    for(int i = 0; i < 10000; i++)
        std::cout<<"Display From Main Thread "<<std::endl;
    std::cout<<"Waiting For Thread to complete"<<std::endl;
    threadObj.join();
    std::cout<<"Exiting from Main Thread"<<std::endl;
    return 0;
}

//Creating a thread using Lambda functions
#include <iostream>
#include <thread>
int main()
{
    int x = 9;
    std::thread threadObj([]{
        for(int i = 0; i < 10000; i++)
            std::cout<<"Display Thread Executing"<<std::endl;
        });

    for(int i = 0; i < 10000; i++)
        std::cout<<"Display From Main Thread"<<std::endl;
    
    threadObj.join();
    std::cout<<"Exiting from Main Thread"<<std::endl;
    return 0;
}


//get ID of thread
#include <iostream>
#include <thread>

void thread_function()
{
std::cout<<"Inside Thread :: ID  = "<<std::this_thread::get_id()<<std::endl;
}

int main()
{
    std::thread threadObj1(thread_function);
    std::thread threadObj2(thread_function);

    if(threadObj1.get_id() != threadObj2.get_id())
        std::cout<<"Both Threads have different IDs"<<std::endl;

    std::cout<<"From Main Thread :: ID of Thread 1 = "<<threadObj1.get_id()<<std::endl;
    std::cout<<"From Main Thread :: ID of Thread 2 = "<<threadObj2.get_id()<<std::endl;

    threadObj1.join();
    threadObj2.join();
    return 0;
}