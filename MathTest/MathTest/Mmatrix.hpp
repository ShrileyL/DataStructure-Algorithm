//
//  Mmatrix.hpp
//  MathTest
//
//  Created by KevinLiu on 16/12/23.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef Mmatrix_hpp
#define Mmatrix_hpp

#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <math.h>
#include <iomanip>

#define MAX = 100;
typedef unsigned int UINT;

template<typename T>
class Mmatrix
{
public:
	Mmatrix(const UINT& _rows, const UINT& _cols, const T& arr);
	Mmatrix(const T& arr);
	~Mmatrix();

	//copy constructor
	Mmatrix(const Mmatrix<T>& rmat);
	//copy assignment
	Mmatrix<T> operator=(const Mmatrix<T>& rmat);
	
private:
	UINT rows;
	UINT cols;
	T* mat;
};

#endif /* Mmatrix_hpp */
