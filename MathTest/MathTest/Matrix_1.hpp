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

typedef unsigned int UINT;

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
    Matrix(UINT rows, UINT cols, bool auto_del = true);
    
    bool exists(UINT row,UINT col) const;
    
    //operator()
    T & operator()(UINT row, UINT col);
    T operator()(UINT row, UINT col) const;

    //copy assigment for matrix equation
    Matrix<T> operator=(const Matrix<T>& rmat);
    
    //destructor
    virtual ~Matrix();
    
    int size() const { return _rows * _cols; }
    int rows() const { return _rows; }
    int cols() const { return _cols; }
    
    //print
    void show();
    
    //overload operators for matrix to matrix mathematical operations
    Matrix<T> operator+=(const Matrix<T> &rmat)
    throw (std::runtime_error);
    
private:
    Matrix(const Matrix &rmat);
    UINT _rows, _cols;
    mutable T * _data;
    const bool auto_delete;
};

template<typename T>
Matrix<T>::Matrix(UINT rows, UINT cols, bool auto_del) : _rows(rows), _cols(cols), auto_delete(auto_del)
{
    _data = new T[rows * cols];
}

template<typename T>
inline T & Matrix<T>::operator()(UINT row, UINT col)
{
//    return _data[_cols * row + col];
    return _data[_cols * (row-1) + (col-1)];
}

template<typename T>
inline T Matrix<T>::operator()(UINT row, UINT col) const
{
    return _data[_cols * (row-1) + (col-1)];
}

template<typename T>
Matrix<T> Matrix<T>::operator=(const Matrix<T>& rmat)
{
//    if(!is_same_shape(rmat)) throw Eexception("cannot assign matrix to a different shaped matrix!!!");
    if(this==&rmat) return *this;
    
    //assign value one by one
    for(UINT i=1; i<=rows(); ++i)
        for(UINT j=1; j<=cols(); ++j)
            this->_data[this->_cols * (i-1) + (j-1)]=rmat(i,j);
    
    return *this;
}

template<typename T>
bool Matrix<T>::exists(UINT row, UINT col) const {
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

//something wrong, may be logical
template<typename T>
Matrix<T> Matrix<T>::operator+=(const Matrix<T>& rmat)  throw (std::runtime_error)
{
    //execute after evaluate the expression as true
    if(_rows!=rmat.rows() || _cols!=rmat.cols())
        throw std::runtime_error("matrix dimension do not match!!");
    
    UINT s_rows=rmat.rows();
    UINT s_cols=rmat.cols();
    Matrix<T> result(s_rows,s_cols);
    
    for(UINT i=1; i<=s_rows; ++i)
    {
        for(UINT j=1; j<=s_cols; ++j)
        {
            result(i,j)=this->_data[this->_cols * (i-1) + (j-1)]+rmat(i,j);
        }
    }
    
    return result;//copy out by value could cause performance deduct ??
}

#endif /* Matrix_1_hpp */
