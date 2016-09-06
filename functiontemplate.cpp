//
//  main.cpp
//  templatetest
//
//  Created by KevinLiu on 16/9/6.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

/*Function Template
template <class type> ret-type fuc_name(paramenter list)
{
	//body of function
}
*/
#include <iostream>
#include <string>
using namespace std;

template <typename T>
inline T const& Max (T const& a,T const& b)
{
	return a < b ? b:a;
}

int main()
{
	int i = 23;
	int j = 67;
	cout << "Max(i,j)=" << Max(i,j) << endl;

    double f1 = 23.334;
    double f2 = 67.9998;
    cout << "Max(f1,f2)=" << Max(f1,f2) << endl;
    
    string s1 = "hello";
    string s2 = "world";
    cout << "Max(s1,s2)=" << Max(s1,s2) << endl;

	return 0;
}