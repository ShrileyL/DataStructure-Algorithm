//
//  using virtual method
//
//  Created by KevinLiu on 16/10/25.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include <iostream>
using namespace std;

class Animal
{
private:
    int isAge;
public:
    Animal():isAge(1){
    cout << "class Animal constructor is called. " << endl;
};
    virtual ~Animal(){cout << "class Animal destructor is called." << endl;};
    
    //virtual function
    virtual void speak() const{cout << "Animal speak!" << endl;};
    //non-virtual function
    void move() const{cout << "Animal move 1 step." << endl;};
};

class Dog:public Animal
{
public:
    Dog(){cout << "class Animal constructor is called." <<endl;};
    virtual ~Dog(){cout << "class Dog destructor is called." << endl;};

    void move() const{cout << "Dog moves 5 steps." << endl;};
    void speak() const{cout << "Woof!" << endl;};
    void WagTail(){cout << "Wagging Tail" << endl;}
    
};

int main(int argc, char const *argv[])
{
	Animal *pDog = new Dog;
	pDog->move();
    //move() is not a virtual function
    //so call the move() in class Animal
    pDog->speak();
    //speak() is a virtual function
    //so call the move() in class Dog
	return 0;
}

//******* Output *******
//class Animal constructor is called. No = 1
//Dog constructor is called. No = 2
//Animal move 1 step.
//Woof!
