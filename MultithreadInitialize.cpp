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

class myFunctor
{
public:
	void operator()()
	{
		cout << "This id my function object" << endl;
	}
    void publicFunction()
    {
        cout << "Public Function of myFunctor class is called." << endl;
    }
};

void threadFunc()
{
    cout << "Welcome to Multithreading!" << endl;
}

void printSomeValues(int val, string str, double dval)
{
    cout << val << " " << str << " " << dval << endl;
}

class myFuctorParam
{
public:
    void operator()(int* arr, int length)
    {
        cout << "An array of length " << length << "is passed to thread" << endl;
        for (int i = 0; i!= length; i++) {
            cout << arr[i] << endl;
        }
        cout << endl;
    }
    void changeSign(int* arr,int length)
    {
        cout << "An array of length " << length << "is passed to thread" << endl;
        for (int i = 0; i!= length; i++) {
            cout << arr[i] << " ";
        }
        cout << endl << "Changing sign of all elements of initial array" << endl;
        for (int i= 0; i!= length; ++i) {
            arr[i] *= -1;
            cout << arr[i] << " ";
        }
    }
};

int main(int argc, const char * argv[]) {
    thread funcTest1(threadFunc);
    if(funcTest1.joinable())
        funcTest1.join();
    
    myFunctor myFunc;
    //initializing thread with object of myFunctor class
    thread funcTest(myFunc);
    //check if thread is joinable
    if (funcTest.joinable())
        //main is block until funcTest1 is not finished
        funcTest.join();

    //initializing thread using function with parameters
    string str = "hello";
    thread paramPass(printSomeValues,5,str,3.2);
    if(paramPass.joinable())
        paramPass.join();
    
    //initializing thread with an object with parameters
    int arr[] = {1,2,4,5,2};
    myFuctorParam objParamPass;
    //thread test(objParamPass,arr,5);
    //if(test.joinable())
        //test.join();
    
    //initializing thread with member function with parameters
    int arr2[] = {1,-2,-7,-5,-8};
    thread test2(&myFuctorParam::changeSign,&objParamPass,arr2,5);
    if(test2.joinable())
        test2.join();

    
    return 0;
}

************ output *************
// Welcome to Multithreading!
// This id my function object
// 5 hello 3.2
// An array of length 5is passed to thread
// 1 -2 -7 -5 -8 
// Changing sign of all elements of initial array
// -1 2 7 5 8 



 #include <string>
 #include <iostream>
 #include <thread>

 using namespace std;

 // The function we want to execute on the new thread.
 void task1(string &msg)
 {
     cout << "task1 says: " << msg << endl;
     msg = "I am Shirley.";
 }

 int main()
 {
     string s = "I am Kevin.";
     // Constructs the new thread and runs it. Does not block execution.
     thread t1(task1, std::ref(s));//pass by reference
     //thread t1(task1, std::move(s));

     // Makes the main thread wait for the new thread to finish execution, therefore blocks its own execution.
     t1.join();
     cout << "Main says: " << s << endl;
 }
