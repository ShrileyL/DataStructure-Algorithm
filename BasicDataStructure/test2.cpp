//
//  main.cpp
//  test
//
//  Created by KevinLiu on 16/12/13.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//


//test for Heap
#include <iostream>
#include <string>
#include "Heap.hpp"
using namespace std;

int main()
{
    Heap<string> heap1;
    heap1.add("Gerge");
    heap1.add("Michael");
    heap1.add("Tom");
    heap1.add("Adam");
    heap1.add("Jones");
    heap1.add("Peter");
    
    while (heap1.getsize() > 0)
    {
        cout << heap1.remove() << " ";
    }
    cout << endl;
    
    int number[] = {8,9,2,3,4,1,5,6,7};
    Heap<int> heap2(number,9);
    while(heap2.getsize() > 0)
        cout << heap2.remove()<<" ";
    cout << endl;
    
    return 0;
}


//test for priority queue
#include <iostream>
#include <string>
#include "Heap.hpp"
using namespace std;

class Patient
{
    string name;
    int priority;
public:
    Patient(string name,int prio)
    {
        this->name = name;
        this->priority = prio;
    }
    
    bool operator<(Patient &rhs)
    {
        return (this->priority < rhs.priority);
    }
    
    bool operator>(Patient &rhs)
    {
        return (this->priority > rhs.priority);
    }
    
    string getName()
    {
        return name;
    }
    
    int getPriority()
    {
        return priority;
    }
};

int main()
{
    //Queue of patients
    PriorityQueue<Patient> patientQueue;
    patientQueue.enqueue(Patient("John",2));
    patientQueue.enqueue(Patient("Jim",1));
    patientQueue.enqueue(Patient("Tim",5));
    patientQueue.enqueue(Patient("Cindy",7));
    
    while (patientQueue.getsize() > 0)
    {
        Patient element = patientQueue.dequeue();
        cout << element.getName() << "(priority: " << element.getPriority() << ")"<< endl;
    }
    

    
    return 0;
}