//
//  main.cpp
//  test
//
//  Created by KevinLiu on 16/12/7.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//


#include <iostream>

#include <string>
#include "DataStructureBasic.hpp"
using namespace std;

void printList(LinkedList<string> list)
{
    for (int i = 0; i < list.getSize(); ++i) {
        cout << list.get(i) << " ";
    }
    cout << endl;
}

int main()
{
    LinkedList<string> list;
    
    //add element to the list
    list.add("America");
    cout << "(1)";
    printList(list);
    
    list.add(0, "Canada");//add to the begining of the list
    cout << "(2)";
    printList(list);
    
    list.add("Russia");//add to the end of the list
    cout << "(3)";
    printList(list);
    
    list.add("France");//add to the end of the list
    cout << "(4)";
    printList(list);
    
    list.add(2, "Germany");
    cout << "(5)";
    printList(list);
    
    list.add(5, "Norway");
    cout << "(6)";
    printList(list);
    
    list.add(0, "Netherlands");
    cout << "(7)";
    printList(list);
    
    //remove element from the list
    list.removeAt(0);
    cout << "(8)";
    printList(list);
    
    list.removeAt(2);
    cout << "(9)";
    printList(list);
    
    list.removeAt(list.getSize() - 1);//remove the last element
    cout << "(10)";
    printList(list);
    
    return 0;
}
