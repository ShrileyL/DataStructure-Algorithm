//
//  main.cpp
//  VectorTemplateImplement
//
//  Created by KevinLiu on 16/9/7.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include <iostream>
//#define SPACE_CAPACITY 16

using namespace std;

template <typename object>
class Vector
{
public:
	explicit Vector(int initSize = 0)
	:theSize(initSize), theCapacity(initSize + SPACE_CAPACITY)
	{ objects = new object[ theCapacity]};

	Vector(const Vector & rhs ):objects(NULL){operator=( rhs)};
	~Vector(){ delete [] objects};

	const Vector & operator= (const Vector & rhs)
	{
		if( this!= rhs)
		{
			delete [] objects;
			theSize = rhs.size();
			theCapacity = rhs.capacity();

			objects = new object [capacity()];
			for( int k = 0; k < size();k++)
				objects[k] = rhs.objects[k];
		}
		return *this;
	};

	void resize(int newSize)
	{
		if(newSize > theSize)
			reserve( newSize*2 + 1);
		theSize = newSize;
	};

	void reserve(int newCapacity)
	{
		if(newCapacity < theSize)
			return;

		object *oldArray = objects;

		objects = new object[ newCapacity ];
		for (int k = 0; k < theSize; k++)
			objects[k] = oldArray[k];

		theCapacity = newCapacity;
		delete [] oldArray;
	};

	//test for over board
	object & operator[]( int index)
	{return objects[ index ];};
	const object & operator[](int index) const
	{return objects[ index ];};

	bool empty() const
	{ return size() == 0;};
	int size() const
	{return theSize;};
	int capacity() const 
	{return theCapacity;};

	void push_back( const object & x)
	{
		if(theSize == theCapacity)
			reserve( 2*theCapacity + 1);
		objects[theSize++ ] = x;
	};

	void pop_back()
	{
		theSize--;
	};

	const object & back() const
	{
		return objects[theSize - 1 ];
	};

	typedef object *iterator;
	typedef const object *const_iterator;

	iterator begin(){return &objects[0];};
	const_iterator begin(){return &objects[0];}

	iterator end(){return &objects [ size()];}
	const_iterator end(){return &objects [ size()];}

    enum {SPACE_CAPACITY = 16};

private:
	int theSize;
	int theCapacity;
	object *objects;

};

