//
//  Multiple virtual function called in turn
//
//  Created by KevinLiu on 16/10/25.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include <iostream>
using namespace std;

class Animal
{
protected:
    int isAge;
public:
    Animal():isAge(1){}
    virtual ~Animal(){}
    
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

class Cat:public Animal
{
public:
    void speak() const{cout << "Meow!" << endl;};
};

class Horse:public Animal
{
public:
    void speak() const{cout << "Winnie!" << endl;};
};

class Pig:public Animal
{
public:
    void speak() const{cout << "Oink!" << endl;};
};


int main(int argc, char const *argv[])
{
	Animal* array[5];
    Animal* ptr;
    int choice, i;
    for (int i = 0; i < 5; ++i)
    {
        cout << "(1)Dog (2)Cat (3)Horse (4)Pig:";
        cin >> choice;
        switch(choice)
        {
            case 1: ptr = new Dog;
                    break;
            case 2: ptr = new Cat;
                    break;
            case 3: ptr = new Horse;
                    break;
            case 4: ptr = new Pig;
                    break;
            default:ptr = new Animal;
                    break;
        }
        array[i] = ptr;
    }

    for (int i = 0; i < 5; ++i)
        array[i]->speak();
    
	
	return 0;
}

//******* Output *******
//(1)Dog (2)Cat (3)Horse (4)Pig:2
//(1)Dog (2)Cat (3)Horse (4)Pig:3
//(1)Dog (2)Cat (3)Horse (4)Pig:1
//(1)Dog (2)Cat (3)Horse (4)Pig:4
//(1)Dog (2)Cat (3)Horse (4)Pig:5
//Meow!
//Winnie!
//Woof!
//Oink!
//Animal speak!

