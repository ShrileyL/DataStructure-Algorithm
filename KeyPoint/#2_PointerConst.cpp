/**************************************************
 * Key Points and Tips
 * 
 * #2 const pointer and pointer const
 * 
 *
 * Remark:  
 *
 * 2016/11/25 Shirley test
 *************************************************/

#include <iostream>

using namespace std;


int main(int argc, char const *argv[])
{
    int a = 1;
    int b = 2;

    int* p = &a;//pointer to a
    const int* cp = &a;//const pointer to a
    int* const pc = &a;//pointer const to a

    p = &b;//correct
    *p = b;//correct

    cp = &b;//correct
    //*cp = b;//error! try to modify const a through pointer

    //pc = &b;//error! try to modify "const" pointer address of pc
    *pc = b;//correct

    return 0;
}
