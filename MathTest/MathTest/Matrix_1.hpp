//
//  Matrix_1.hpp
//  MathTest
//
//  Created by KevinLiu on 16/12/24.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#ifndef Matrix_1_hpp
#define Matrix_1_hpp

#include <stdio.h>
#include <iostream>
using std::cerr;
using std::endl;

//qt4type
typedef unsigned int quint32;

template <typename T>
void deletep(T &) {}
template <typename T>
void deletep(T* & ptr) {
    delete ptr;
    ptr = 0;
}
template<typename T>
class Matrix {
public:
    typedef T value_type;
    //construct
    Matrix() : _cols(0), _rows(0), _data(new T[0]), auto_delete(true) {};
    Matrix(quint32 rows, quint32 cols, bool auto_del = true);
    
    bool exists(quint32 row, quint32 col) const;
    
    //operator()
    T & operator()(quint32 row, quint32 col);
    T operator()(quint32 row, quint32 col) const;
    
    //destructor
    virtual ~Matrix();
    
    int size() const { return _rows * _cols; }
    int rows() const { return _rows; }
    int cols() const { return _cols; }
    
    void show();
private:
    Matrix(const Matrix &);
    quint32 _rows, _cols;
    mutable T * _data;
    const bool auto_delete;
};
template<typename T>
Matrix<T>::Matrix(quint32 rows, quint32 cols, bool auto_del) : _rows(rows), _cols(cols), auto_delete(auto_del)
{
    _data = new T[rows * cols];
}

template<typename T>
inline T & Matrix<T>::operator()(quint32 row, quint32 col)
{
//    return _data[_cols * row + col];
    return _data[_cols * (row-1) + (col-1)];
}

template<typename T>
inline T Matrix<T>::operator()(quint32 row, quint32 col) const
{
    return _data[_cols * (row-1) + (col-1)];
}

template<typename T>
bool Matrix<T>::exists(quint32 row, quint32 col) const {
    return (row < _rows && col < _cols);
}

template<typename T>
Matrix<T>::~Matrix()
{
    if(auto_delete)
    {
        for(int i = 0, c = size(); i < c; ++i){
            //will do nothing if T isn't a pointer
            deletep(_data[i]);
        }
    }
    delete [] _data;
}

template<typename T>
void Matrix<T>::show()
{
    if (auto_delete)
    {
        for(int x = 0; x < _rows; ++x)
        {
            for(int y = 0; y < _cols; ++y)
            {
                std::cout << _data[x*_cols + y] <<  "   " ;
            }
            std::cout << endl;
        }
    }
}

#endif /* Matrix_1_hpp */
