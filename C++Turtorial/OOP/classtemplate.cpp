//
//  main.cpp
//  class template
//
//  Created by KevinLiu on 16/9/6.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;


/*General form:
 template <class type> class class-name {
 .
 .
 .
 }
 */

template <class T>
class Stack {
private:
    vector<T> elems;
    
public:
    Stack(){};
    void push(T const&);
    T pop();
    T top() const;
    bool empty() const{
        return elems.empty();
    };
    
};

template <class T>
void Stack<T>::push(T const& elem){
    //append copy of passed element
    elems.push_back(elem);
}

template <class T>
T Stack<T>::pop(){
    if(elems.empty()){
        throw out_of_range("Stack<>::top(): empty stack");
    }
    // return copy of last element
    return elems.back();

}

template <class T>
T Stack<T>::top () const
{
    if (elems.empty()) {
        throw out_of_range("Stack<>::top(): empty stack");
    }
    // return copy of last element
    return elems.back();
}

int main()
{
    try {
        Stack<int>         intStack;  // stack of ints
        Stack<string> stringStack;    // stack of strings
        
        // manipulate int stack
        intStack.push(7);
        cout << intStack.top() <<endl;
        
        // manipulate string stack
        stringStack.push("hello");
        cout << stringStack.top() << std::endl;
        stringStack.pop();
        stringStack.pop();
    }
    catch (exception const& ex) {
        cerr << "Exception: " << ex.what() <<endl;
        return -1;
    }
  
    
    return 0;
}