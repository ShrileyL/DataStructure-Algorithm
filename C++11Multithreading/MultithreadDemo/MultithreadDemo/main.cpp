//
//  main.cpp
//  MultithreadDemo
//
//  Created by KevinLiu on 16/10/31.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//


//demo #1
// #include <string>
// #include <iostream>
// #include <thread>
//#include <fstream>
//#include <mutex>
// using namespace std;
// std::mutex mu;
//
//class LogFile
//{
//    std::mutex m_mutex;
//    ofstream f;
//public:
//    LogFile(){f.open("log.txt");}//need destructor to close file
//    void shared_print(string id, int value)
//    {
//        std::lock_guard<std::mutex>guard(m_mutex);
//        cout << "From "<<id << ": "<< value << endl;
//    }
//};
//
//// void shared_print(string msg, int id)
////{
////    //mu.lock();
////    std::lock_guard<std::mutex>guard(mu);
////    cout << msg << id << endl;
////    //mu.unlock();
////}
//
//
// // The function we want to execute on the new thread.
// void task1(LogFile& log)
// {
//     
//     for (int i=0; i>-100; i--) {
//         log.shared_print("task1 says: ",i);
//     }
//   
// }
//
// int main()
// {
//     LogFile log;
//     thread t1(task1,std::ref(log));
//     
//     for (int i=0; i < 100; i++) {
//         log.shared_print("main says: ",i);
//     }
//
//     
//     t1.join();
// }


//demo #2
// #include <string>
// #include <iostream>
// #include <thread>
//
// using namespace std;
//
// // The function we want to execute on the new thread.
// void task1(string msg)
// {
//     cout << "task1 says: " << msg << endl;
// }
//
// int main()
// {
//     // Constructs the new thread and runs it. Does not block execution.
//     thread t1(task1, "Hello");
//     
//     for(int i = 0; i < 10; i++)
//         std::cout<<"Display From MainThread"<<std::endl;
//     // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
//     t1.join();
// }

//demo #3
//#include <iostream>
//#include <thread>
//using namespace std;
//
// void threadFunc()
// {
//     cout << "Thread initial" << endl;
// }
//
// int main(int argc, char const *argv[])
// {
//     thread t1(threadFunc);
//     thread t2(threadFunc);
//     thread t3(threadFunc);
//
//     //get id of all the thread
//     thread::id id1 = t1.get_id();
//     thread::id id2 = t2.get_id();
//     thread::id id3 = t3.get_id();
//    
//     if (t1.joinable()) {
//         t1.join();
//         cout << "Thread1 with id " << id1 <<" is terminated" <<endl;
//     }
//     if (t2.joinable()) {
//         t2.join();
//         cout << "Thread2 with id " << id2 <<" is terminated" <<endl;
//     }
//     if (t3.joinable()) {
//         t3.join();
//         cout << "Thread3 with id " << id3 <<" is terminated" <<endl;
//     }
//    
//     return 0;
// }


//demo #4
//#include <iostream>
//#include <iomanip>
//#include <thread>
//#include <chrono>
//#include <ctime>
//
//using namespace std;
//using std::__1::chrono::system_clock;
//int main(int argc, char const *argv[])
//{
//    cout << "The id of current thread is " << &this_thread::get_id <<endl;
//    
//    time_t timet = system_clock::to_time_t(std::__1::chrono::system_clock::now());
//    
//    struct tm * time = localtime(&timet);
//    cout  << "Current time: " << put_time(time, "%x") << endl;
//    cout <<"Waiting for the next minute to begin..." << endl;
//    time -> tm_min++;
//    time ->tm_sec = 0;
//    //sleep until next minute is reached
//    this_thread::sleep_until(system_clock::from_time_t(mktime(time)));
//    cout << std::put_time(time, "%x")<<" reached!"<<endl;
//    
//    //sleep for 5 second
//    this_thread::sleep_for(chrono::seconds(5));
//    
//    //get current time
//    timet =system_clock::to_time_t(std::__1::chrono::system_clock::now());
//    
//    //convert it to tm struct
//    time = std::localtime(&timet);
//    cout << "Current time: " << put_time(time, "%x") << endl;
//    return 0;
//}

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
