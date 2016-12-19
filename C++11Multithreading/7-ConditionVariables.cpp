//
//  main.cpp
//  test for creat multithread
//
//  Created by KevinLiu on 16/12/19.
//  Copyright © 2016年 KevinLiu. All rights reserved.

// Condition Variable is a kind of Event used for signaling between two or more threads. 
// One or more thread can wait on it to get signaled, 
// while an another thread can signal this.

// How things actually work with condition variable,

// 1.Thread 1 calls the wait on condition variable, which internally acquires the mutex and check if required condition is met or not.
// 2.If not then it releases the lock and waits for Condition Variable to get signaled ( thread gets blocked). 
// Condition Variable’s wait() function provides both these operations in atomic manner.
// 3.Another Thread i.e. like Thread 2 signals the Condition Variable when condition is met
// 4.Once Conditional Variable get signaled the the Thread 1 which was waiting for it resumes. 
// It then acquires the mutex lock again and checks if the condition associated with Condition Variable is actually met or if it is superiors call. 
// If more than one thread was waiting then notify_one will unblock only one thread.
// 5.If it was a superiors call then it again calls the wait() function.

#include <iostream>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>
using namespace std::placeholders;
class Application
{
	std::mutex m_mutex;
	std::condition_variable m_condVar;
	bool m_bDataLoaded;
public:
	Application()
	{
		m_bDataLoaded = false;
	}
	void loadData()
	{
		// Make This Thread sleep for 1 Second
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout<<"Loading Data from XML."<<std::endl;
		// Lock The Data structure
		std::lock_guard<std::mutex> guard(m_mutex);
		// Set the flag to true, means data is loaded
		m_bDataLoaded = true;
		// Notify the condition variable
		m_condVar.notify_one();
	}
	bool isDataLoaded()
	{
		return m_bDataLoaded;
	}
	void mainTask()
	{
		std::cout<<"Do Some Handshaking"<<std::endl;
		// Acquire the lock
		std::unique_lock<std::mutex> mlock(m_mutex);
		// Start waiting for the Condition Variable to get signaled
		// Wait() will internally release the lock and make the thread to block
		// As soon as condition variable get signaled, resume the thread and
    	// again acquire the lock. Then check if condition is met or not
		// If condition is met then continue else again go in wait.
		m_condVar.wait(mlock, std::bind(&Application::isDataLoaded, this));
		std::cout<<"Do Processing On loaded Data"<<std::endl;
	}
};
int main()
{
	Application app;
	std::thread thread_1(&Application::mainTask, app);
	std::thread thread_2(&Application::loadData, app);
	thread_2.join();
	thread_1.join();
	return 0;
}