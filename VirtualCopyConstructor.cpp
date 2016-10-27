//
//  Virtual copy constructor
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
    Animal():isAge(1){cout << "Animal constructor is called." <<endl;}
    //deconstructor need to be virtual
    virtual ~Animal(){}
    //copy constructor
    Animal(const Animal &rhs);
    //virtual copy constructor
    virtual Animal* clone(){return new Animal(*this);}

    
    //virtual function
    virtual void speak() const{cout << "Animal speak!" << endl;}
    //non-virtual function
    void move() const{cout << "Animal move 1 step." << endl;}

    int GetAge()const {return isAge;}
};

Animal::Animal(const Animal &rhs):isAge(rhs.GetAge())
{
    cout << "Animal Copy constructor.."<< endl;
}

class Dog:public Animal
{
public:
    Dog(){cout << "Dog constructor is called." <<endl;};
    virtual ~Dog(){cout << "Dog destructor is called." << endl;};
    Dog(const Dog &rhs);
    virtual Animal* clone(){return new Dog(*this);}

    void move() const{cout << "Dog moves 5 steps." << endl;};
    void speak() const{cout << "Woof!" << endl;};
    void WagTail(){cout << "Wagging Tail" << endl;}
    
};

Dog::Dog(const Dog &rhs):Dog(rhs)
{
    cout << "Dog Copy constructor.."<< endl;
}

class Cat:public Animal
{
public:
    Cat(){cout << "Cat constructor is called." <<endl;};
    virtual ~Cat(){cout << "Cat destructor is called." << endl;};
    Cat(const Cat &rhs);
    virtual Animal* clone(){return new Cat(*this);}

    void speak() const{cout << "Meow!" << endl;};
};

Cat::Cat(const Cat &rhs):Animal(rhs)
{
    cout << "Cat Copy constructor.."<< endl;
}


enum MAMALS {ANIMAL, DOG, CAT};
const int NumAnimalType = 3;
int main(int argc, char const *argv[])
{
	Animal* array[NumAnimalType];
    Animal* ptr;
    int choice, i;
    for (i = 0; i < NumAnimalType; ++i)
    {
        cout << "(1)Dog (2)Cat (3)Animal: ";
        cin >> choice;
        switch(choice)
        {
            case DOG: ptr = new Dog;
                    break;
            case CAT: ptr = new Cat;
                    break;
            default:ptr = new Animal;
                    break;
        }
        array[i] = ptr;
    }
    Animal *otherArray[NumAnimalType];
    for (i = 0; i < NumAnimalType; ++i)
        {
            array[i]->speak();
            otherArray[i] = array[i]->clone();
        }
    for (int i = 0; i < NumAnimalType; ++i)
    {
        otherArray[i]->speak();
    }
	
	return 0;
}

//******* Output *******
//(1)Dog (2)Cat (3)Animal: 1
// Animal constructor is called.
// Dog constructor is called.
// (1)Dog (2)Cat (3)Animal: 2
// Animal constructor is called.
// Cat constructor is called.
// (1)Dog (2)Cat (3)Animal: 3
// Animal constructor is called.
// Woof!
// Animal Copy constructor..
// Dog Copy constructor..
// Meow!
// Animal Copy constructor..
// Cat Copy constructor..
// Animal speak!
// Animal Copy constructor..
// Woof!
// Meow!
// Animal speak!
