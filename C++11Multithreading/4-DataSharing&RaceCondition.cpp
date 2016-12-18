//
//  main.cpp
//  test for creat multithread
//
//  Created by KevinLiu on 16/12/18.
//  Copyright © 2016年 KevinLiu. All rights reserved.

// In multithreading environment data sharing between threads is very easy. But this easy sharing of data can cause problems in application. 
// One such problem is Race Condition.

// Race Condition:
// Race condition is a kind of a bug that occurs in multithreaded applications.

// When two or more threads perform a set of operations in parallel, 
// that access the same memory location.  
// Also, one or more thread out of them modifies the data in that memory location, 
// then this can lead to an unexpected results some times.

// This is called race condition.

// Race conditions are usually hard to find and reproduce because they don’t occur every time. 
// They will occur only when relative order of execution of operations by 
// two or more threads leads to an unexpected result. 

#include <iostream>
#include <thread>
#include <vector>

class Wallet
{
    int mMoney;
public:
    Wallet() :mMoney(0){}
    int getMoney() { return mMoney; }
    void addMoney(int money)
    {
       for(int i = 0; i < money; ++i)
       {
          mMoney++;
       }
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
       std::cout << "Error at count = "<<k<<" Money in Wallet = "<<val << std::endl;
     }
  }
  return 0;
}

// As addMoney() member function of same Wallet class object is executed 5 times hence it’s internal money is expected to be 5000. 
// But as addMoney() member function is executed in parallel hence in some scenarios mMoney will be much lesser than 5000
/*
Output:
Error at count = 0 Money in Wallet = 4892
Error at count = 10 Money in Wallet = 4345
Error at count = 26 Money in Wallet = 4881
Error at count = 28 Money in Wallet = 4832
Error at count = 36 Money in Wallet = 4922
Error at count = 41 Money in Wallet = 4712
Error at count = 96 Money in Wallet = 4947
Error at count = 99 Money in Wallet = 4539
Error at count = 100 Money in Wallet = 4903
...
*/
// This is a race condition, as here two or more threads were trying to modify the same memory location 
// at same time and lead to unexpected result.
// Each thread increments the same “mMoney” member variable in parallel. 
// Although it seems a single line but this “mMoney++” is actually converted into three machine commands,

// 1.Load “mMoney” variable value in Register
// 2.Increment register’s value
// 3.Update variable “mMoney” with register’s value

// To fix this problem we need to use Lock mechanism i.e. 
// each thread need to acquire a lock before modifying or reading the shared data 
// and after modifying the data each thread should unlock the Lock.