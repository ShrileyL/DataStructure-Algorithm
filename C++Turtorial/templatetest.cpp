//
//  main.cpp
//  templatetest
//
//  Created by KevinLiu on 16/9/6.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include <iostream>

#include <vector>
using namespace std;

template <typename Container>
void printCollection( const Container &c, ostream & out = cout)
{
    if(c.empty() )
        out << "(empty)";
    else
    {
        typename Container ::const_iterator itr = c.begin();
        out << "[" <<*itr++;//print first item
        
        while( itr != c.end())
            out << ", " << *itr++;
        out <<"]" << endl;
    }
}

int main()
{
    vector<int> v;
    
    v.push_back(1);
    v.push_back(2);
    v.push_back(8);
    v.push_back(9);
    
    
    printCollection(v);
    
    return 0;
}