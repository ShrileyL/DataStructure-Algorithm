/**************************************************
 * Key Points and Tips
 * 
 * #5 pointer pass-by-value
 * 
 *
 * Remark:  what is mean by pointer to a pointer
 *          why need pointer to a pointer 
 *
 * 2016/11/27 Shirley test
 *************************************************/

#include <iostream>

#include <string>

using namespace std;

//change directely using pointer
//fail to change value
void swap(int* a, int* b)//pass by copy of pointer
{
    int* temp;
    temp = a;
    a = b;
    b = temp;
    cout <<"In swap(): "<< a <<" " <<b <<endl;
}

//pass by reference
//succeed
void swapRef(int* &a, int* &b)
{
    int* temp;
    temp = a;
    a = b;
    b = temp;
    cout <<"In swapRef(): "<< a <<" " <<b <<endl;
}

//pass by pointer to a pointer
//succeed
void swapPtr(int** a, int** b)
{
    int* temp;
    temp = *a;
    *a = *b;
    *b = temp;
    cout <<"In swapPtr(): "<< *a <<" " <<*b <<endl;
}

int main()
{
    int a = 3;
    int b = 4;
    int* pa = &a;
    int* pb = &b;
    swap(pa,pb);
    cout << " After swap: "<< endl;
    cout << pa << " " <<pb << endl;
    cout << *pa << " " <<*pb << endl;//3 4
    
    swapRef(pa,pb);
    cout << " After swapRef: "<< endl;
    cout << pa << " " <<pb << endl;
    cout << *pa << " " <<*pb << endl;//4 3
    
    swapPtr(&pa,&pb);
    cout << " After swapPtr: "<< endl;
    cout << pa << " " <<pb << endl;
    cout << *pa << " " <<*pb << endl;//3 4

    return 0;
}