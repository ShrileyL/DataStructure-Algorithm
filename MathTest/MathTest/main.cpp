//
//  main.cpp
//  MathTest
//
//  Created by KevinLiu on 16/12/23.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

//#include <iostream>
//#include <valarray>
//
//int main(int argc, const char * argv[]) {
//    std::valarray<double>
//    return 0;
//}

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
    Matrix() : _cols(0), _rows(0), _data(new T[0]), auto_delete(true) {};
    Matrix(quint32 rows, quint32 cols, bool auto_del = true);
    
    bool exists(quint32 row, quint32 col) const;
    T & operator()(quint32 row, quint32 col);
    T operator()(quint32 row, quint32 col) const;
    virtual ~Matrix();
    
    int size() const { return _rows * _cols; }
    int rows() const { return _rows; }
    int cols() const { return _cols; }
private:
    Matrix(const Matrix &);
    quint32 _rows, _cols;
    mutable T * _data;
    const bool auto_delete;
};
template<typename T>
Matrix<T>::Matrix(quint32 rows, quint32 cols, bool auto_del) : _rows(rows), _cols(cols), auto_delete(auto_del) {
    _data = new T[rows * cols];
}
template<typename T>
inline T & Matrix<T>::operator()(quint32 row, quint32 col) {
    return _data[_cols * row + col];
}
template<typename T>
inline T Matrix<T>::operator()(quint32 row, quint32 col) const {
    return _data[_cols * row + col];
}

template<typename T>
bool Matrix<T>::exists(quint32 row, quint32 col) const {
    return (row < _rows && col < _cols);
}

template<typename T>
Matrix<T>::~Matrix() {
    if(auto_delete){
        for(int i = 0, c = size(); i < c; ++i){
            //will do nothing if T isn't a pointer
            deletep(_data[i]);
        }
    }
    delete [] _data;
}

int main() {
    Matrix< int > m(10,10);
    quint32 i = 0;
    for(int x = 0; x < 10; ++x) {
        for(int y = 0; y < 10; ++y, ++i) {
            m(x, y) = i;
        }
    }
    for(int x = 0; x < 10; ++x) {
        for(int y = 0; y < 10; ++y) {
            cerr << "@(" << x << ", " << y << ") : " << m(x,y) << endl;
        }
    }
}
