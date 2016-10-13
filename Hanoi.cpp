//
//  main.cpp
//  Hanoi Tower
//
//  Created by KevinLiu on 16/10/2.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include <iostream>
using namespace std;
void hanoi(int n,char x, char y, char z);

int main(int argc, char const *argv[])
{
	int n;
	cout << "Please input the number of hanoi tower: ";
	cin >> n;
	hanoi(n,'A','B','C');

	return 0;
}

void hanoi(int n, char x,char y,char z)
{
	if (n > 0)
	{
		hanoi(n-1,x,z,y);
		cout << "Move" << n << ":" << x << "->" << z << endl;
		hanoi(n-1,y,x,z);
	}
}