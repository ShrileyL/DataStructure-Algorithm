//
//  main.cpp
//  test for creat multithread
//
//  Created by KevinLiu on 16/12/18.
//  Copyright © 2016年 KevinLiu. All rights reserved.

// In this article we will discuss how to use mutex locks 
// to protect shared data in multithreaded environment and avoid race conditions.

// each thread needs to lock a mutex before modifying or reading the shared data 
// and after modifying the data each thread should unlock the mutex.

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

// std::mutex
class Wallet
{
	int mMoney;
	std::mutex mutex;
public:
	Wallet() :mMoney(0){}
    int getMoney()   { 	return mMoney; }
    void addMoney(int money)
    {
		mutex.lock();
    	for(int i = 0; i < money; ++i)
		{
			mMoney++;
		}
		mutex.unlock();
    }
};

int testMultithreadedWallet()
{
    Wallet walletObject;
    std::vector<std::thread> threads;
    for(int i = 0; i < 5; ++i){
        threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 1000));
    }

    for(int i = 0; i < threads.size() ; i++)
    {
        threads.at(i).join();
    }
    return walletObject.getMoney();
}

int main()
{

	int val = 0;
	for(int k = 0; k < 1000; k++)
	{
		if((val = testMultithreadedWallet()) != 5000)
		{
			std::cout << "Error at count = "<<k<<"  Money in Wallet = "<<val << std::endl;
			//break;
		}
	}
	std::cout << "Total money: " << testMultithreadedWallet() << std::endl;
	return 0;
}

// It’s guaranteed that it will not found a single scenario where money in wallet is less than 5000.
// Because mutex lock in addMoney makes sure that 
// once one thread finishes the modification of money then only any other thread modifies the money in Wallet.

// But what if we forgot to unlock the mutex at the end of function. 
// In such scenario, one thread will exit without releasing the lock and other threads will remain in waiting.
// This kind of scenario can happen in case some exception came after locking the mutex. 
// To avoid such scenarios we should use std::lock_guard.

// std::lock_guard<std::mutex>
class Wallet
{
	int mMoney;
	std::mutex mutex;
public:
    Wallet() :mMoney(0){}
    int getMoney()   { 	return mMoney; }
    void addMoney(int money)
    {
		std::lock_guard<std::mutex> lockGuard(mutex);
		// In constructor it locks the mutex

    	for(int i = 0; i < money; ++i)
		{
			// If some exception occurs at this
			// poin then destructor of lockGuard
			// will be called due to stack unwinding.
			//
			mMoney++;
		}
		// Once function exits, then destructor
		// of lockGuard Object will be called.
		// In destructor it unlocks the mutex.
    }
 };