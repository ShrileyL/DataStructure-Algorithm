//
//  main.cpp
//  MultithreadDemo
//
//  Created by KevinLiu on 16/10/31.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//


#include <iostream>

#include <thread>

using namespace std;

void threadFunc()
{
    cout << "Thread initial" << endl;
}

int main(int argc, char const *argv[])
{
    thread t1(threadFunc);
    thread t2(threadFunc);
    thread t3(threadFunc);

    //get id of all the thread
    thread::id id1 = t1.get_id();
    thread::id id2 = t2.get_id();
    thread::id id3 = t3.get_id();
    
    if (t1.joinable()) {
        t1.join();
        cout << "Thread with id " << id1 <<" is terminated" <<endl;
    }
    if (t2.joinable()) {
        t2.join();
        cout << "Thread with id " << id2 <<" is terminated" <<endl;
    }
    if (t3.joinable()) {
        t3.join();
        cout << "Thread with id " << id3 <<" is terminated" <<endl;
    }
    
    return 0;
}
