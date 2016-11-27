/**************************************************
 * Key Points and Tips
 * 
 * #4 const reference
 * 
 *
 * Remark:  
 *
 * 2016/11/27 Shirley test
 *************************************************/


#include <iostream>
#include <stdio.h>
#include <string>
//#include 'malloc.h'
using namespace std;

/* wrong use
*/
string foo();
void bar(string &s);//pass-by-non-ref

int main()
{
    bar(foo());//no match function to call bar
    bar("hello");//no match function to call bar
    //because the "foo()" and "hello" will creat a
    //temp copy passed to bar, which is const 
    return 0;
}

/* correct use
*/
string foo();
void bar(const string &s);//pass-by const ref

int main()
{
    bar(foo());
    bar("hello");
    return 0;
}