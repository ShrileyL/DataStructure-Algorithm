/**************************************************
 * Effective C++ 
 * 
 * #10 have assignment operators return a referenct to *this
 * 
 * int x,y,z;
 * x = y = z = 15;//chain of assignment
 *
 * Remark:  
 *
 * 2016/11/23 Shirley test
 *************************************************/

#include <iostream>
using namespace std;

class Widget
{
public:
    Widget():num(0){};
    Widget(int n){num = n;};
    // ~Widget();
    Widget& operator=(const Widget& rhs)
    {
        this->num = rhs.num;
        return *this;//return the left-hand object
    }
    
    Widget& operator+=(const Widget& rhs)
    {
        this->num = this->num + rhs.num;
        return *this;//return the left-hand object
    }
    void display(){cout << num << endl;};
private:
    int num;
    
};

int main()
{
    Widget a,b(3);
    a=b;
    a.display();
    
}