//
//  main.cpp
//  FunctionTemplet and some remarks or notes
//
//  Created by KevinLiu on 16/10/14.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

#include <iostream>

using namespace std;

template <typename T>
T add(T a, T b)
{
    T c;
    c = a + b;
    return c;
}

//Note: The standard library already comes with a templated max() function.
//If you use the statement “using namespace std;”
//the compiler will be unable to tell whether you want your version of max() or std::max().
template <typename Type>
Type maxF(Type a, Type b)
{
    return a > b ? a:b;
}


template <class T>
T Average(T *atArray, int nNumValues)
{
    T tSum = 0;
    for (int nCount=0; nCount < nNumValues; nCount++)
        tSum += atArray[nCount];
 
    tSum /= nNumValues;
    return tSum;
}

class Cents
{
private:
    int m_nCents;
public:
    Cents(int nCents)
    : m_nCents(nCents)
    {
    }
    //without overload of operator >
    //the template instance in type Cents do not
    //know how to compare two Cents objects!!
    friend bool operator>(Cents &c1, Cents&c2)
    {
        return (c1.m_nCents > c2.m_nCents);
    }

	//overload operator << is essential for Cents objects to
    //the FUnction "Average" template instance
    friend ostream& operator<< (ostream &out, const Cents &cCents)
    {
        out << cCents.m_nCents << " cents ";
        return out;
    }

    //overload operator += and /= is also essential for Cents objects to
    //the FUnction "Average" template instance
    void operator+=(Cents cCents)
    {
        m_nCents += cCents.m_nCents;
    }
 
    void operator/=(int nValue)
    {
        m_nCents /= nValue;
    }

    void print()
    {
        cout << m_nCents << endl;
    }
};

int main(int argc, char const *argv[])
{
    int a = 1;
    int b = 2;
    cout << add(a,b) << endl;
    cout << maxF(a,b) << endl;
    
    double c = 1.33;
    double d = 23.2;
    cout << add(c,d) << endl;
    cout << maxF(c,d) << endl;
    
    Cents cNickle(5);
    Cents cDime(10);
    
    Cents cBigger = maxF(cNickle, cDime);
    cBigger.print();

	int anArray[] = { 5, 3, 2, 1, 4 };
	cout << Average(anArray, 5) << endl;
 
	double dnArray[] = { 3.12, 3.45, 9.23, 6.34 };
	cout << Average(dnArray, 4) << endl;
    return 0;
}