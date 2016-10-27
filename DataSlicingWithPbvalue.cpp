//
//  Data slicing with passsing by value
//
//  Created by KevinLiu on 16/10/27.
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


void ValueFunction(Animal);
void ptrFuction(Animal*);
void RefFunction(Animal&);

int main(int argc, char const *argv[])
{
    Animal* ptr = 0;
    int choice;

    while(1)
    {
        bool fQuit = false;
        cout << "(1)Dog (2)Cat (3)Horse (4)Pig:";
        cin >> choice;
        switch(choice)
        {
            case 0: fQuit = true;
                    break;
            case 1: ptr = new Dog;
                    break;
            case 2: ptr = new Cat;
                    break;
   
            default:ptr = new Animal;
                    break;
        }
        if (fQuit == true)
        break;
        ptrFuction(ptr);
        RefFunction(*ptr);
        ValueFunction(*ptr);
    }
    
	
	return 0;
}

void ValueFunction(Animal Animalvalue)
{
    Animalvalue.speak();
}

void ptrFuction(Animal * pAnimal)
{
    pAnimal->speak();
}

void RefFunction(Animal &rAnimal)
{
    rAnimal.speak();
}

//******* Output *******
//(1)Dog (2)Cat (0)Quit: 2
//Meow!
//Meow!
//Animal speak!
//(1)Dog (2)Cat (0)Quit: 1
//Woof!
//Woof!
//Animal speak!
//(1)Dog (2)Cat (0)Quit: 0

