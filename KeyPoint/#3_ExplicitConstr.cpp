/**************************************************
 * Key Points and Tips
 * 
 * #3 explicit constructor
 * 
 *
 * Remark:  
 *
 * 2016/11/25 Shirley test
 *************************************************/

#include <iostream>
#include <string>

using namespace std;

class Number
{
public:
    string type;
    Number():type("void"){}
    Number(int n) : type("int"){}
    //explicit constructor 
    //do not support auto_cast
    explicit Number(short c) : type("short"){}
};

void show(const Number& n)
{
    cout << n.type <<endl;
}

int main(int argc, char const *argv[])
{
    short s = 42;
    show();

    return 0;
}
