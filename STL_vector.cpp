//
//  main.cpp
//  STL_vector
//
//  Created by KevinLiu on 16/9/5.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec;
    int i;
    
    //print initial vector size
    cout << "vector size:" << vec.size() <<endl;
    
    //
    for(i = 0; i < 5; i++)
        vec.push_back(i*3);
    
    //display vector a
    for(i = 0; i < 5; i++)
        cout << "vector vec[" << i << "] = " << vec[i] <<endl;
    
    
    vec.pop_back();
    vec.push_back(67);
    //use iterator to access the value
    for(vector<int>::iterator itr = vec.begin() ; itr != vec.end() ; ++itr){
        cout << "value of vec: " << *itr <<endl;
    }

    //use of method "erase"
    cout << "After erase 2: " << endl;
    vec.erase(vec.begin() + 2);
    for(vector<int>::iterator itr = vec.begin() ; itr != vec.end() ; ++itr){
        cout << "value of vec: " << *itr <<endl;
    }
    
    cout << "After erase [1,3): " << endl;
    vec.erase(vec.begin() + 1,vec.begin()+3);
    for(vector<int>::iterator itr = vec.begin() ; itr != vec.end() ; ++itr){
        cout << "value of vec: " << *itr <<endl;
    }
    
    vec.empty();
    vec.clear();
    
    return 0;
}