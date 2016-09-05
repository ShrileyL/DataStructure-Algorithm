//
//  main.cpp
//  STL_list
//
//  Created by KevinLiu on 16/9/5.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include <iostream>
#include <list>
#include <vector>
#include <time.h>
using namespace std;

int main() {
    
    clock_t tStart = clock();
    /* Do your stuff here */

    /*list test
     test how to use template list in cpp
     */
    
    //different constrctors
    list<int> link;
    srand (time_t(NULL));
    for(int i = 0; i < 100000; i++){
        int a = rand()%100000 + 1;
        link.push_back(a);
    }
    link.sort();
    //link.unique();
    
    cout << "vector size:" << link.size() <<endl;
    
    for(list<int>::iterator it = link.begin() ; it != link.end() ; ++it){
        cout << "value of list: " << *it <<endl;
    }
    
    /*link.pop_back();
    cout << "vector size:" << link.size() <<endl;
    
    for(list<int>::iterator it = link.begin() ; it != link.end() ; ++it){
        cout << "value of list: " << *it <<endl;
    }
    */
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    
    return 0;
}
