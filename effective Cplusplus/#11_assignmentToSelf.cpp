/**************************************************
 * Effective C++ 
 * 
 * #11 Handle assignment to self in operator= 
 * 
 * 
 * 
 *
 * Remark:  
 *
 * 2016/11/23 Shirley test
 *************************************************/

class base{ };
class derived: public base
{

};
void dosomething(const base& rb, derived* pd);//rb and *pd might actually be the same object

#include <iostream>
using namespace std;

class Bitmap
{
public:
	Bitmap();
	~Bitmap();
	
};

class Wight
{
public:
	Wight& operator=(const Wight& rhs)//for assignment to self
	{                                 //*this == rhs!!
		delete pb;//stop using current bitmap
		pb = new Bitmap(*rhs.pb);//start using a copy od rhs's bitmap
		return *this;
	}
private:
	Bitmap *pb;//ptr to a heap-allocated object
};

/***************************************************************************/
//Modify

Wight& Wight::operator= (const Wight& rhs)
{
	if(this == &rhs) return *this;//identity test: if a self-assignment,do nothing
	delete pb;
	pb = new Bitmap(*rhs.pb);
	return *this;
}
/***************************************************************************/
//Modify2

Widget& Widget::operator=(const Widget& rhs)
{ 
    Bitmap *pOrig = pb;                //remember original pb
    pb = new Bitmap(*rhs.pb);      //point pb to a copy of rhs's bitmap
    delete pOrig;                           //delete original pb
    return *this;
}
