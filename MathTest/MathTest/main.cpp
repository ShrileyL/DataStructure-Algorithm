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
#include "Matrix_1.hpp"

int main()
{
//    Matrix< int > m(10,10);
//    quint32 i = 1;
//    
//    //assignment
//    for(int x = 1; x < 11; ++x)
//    {
//        for(int y = 1; y < 11; ++y, ++i)
//        {
//            m(x, y) = i;
//        }
//    }
//    
//    m.show();
//    
//    //print
//    for(int x = 1; x < 11; ++x)
//    {
//        for(int y = 1; y < 11; ++y)
//        {
//            cerr << "@(" << x << ", " << y << ") : " << m(x,y) << endl;
//        }
//    }
    
    Matrix<int> A(5,5);
    int x = 1;
    
    for (int i = 1; i <= A.rows(); ++i)
    {
        for (int j = 1; j <= A.cols(); ++j,++x)
        {
            A(i,j) = x;
        }
    }
    
    A.show();
}
