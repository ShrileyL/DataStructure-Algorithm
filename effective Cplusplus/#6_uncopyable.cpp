/**************************************************
 * Effective C++ 
 * 
 * #6 prevent copy 
 * solution 1: declare only
 * solution 2: uncopyable class
 *
 * 2016/11/23 Shirley test
 *************************************************/

#include <iostream>
#include <string>

using namespace std;

//declare only
class HomeForSale
{
public:
    HomeForSale(std::string &name, double ar, double prc):ownner(name),area(ar),price(prc){};
    void Info(){std::cout << ownner << " " << area << " " << price; }
private:
    double area;
    std::string ownner;
    double price;
    
    HomeForSale(const HomeForSale&);//declaration only
    HomeForSale& operator=(const HomeForSale&);
};

int main()
{
    std::string name1 = "Kevin";
    std::string name2 = "Shirley";
    HomeForSale h(name1,120,200);
    HomeForSale h2(name2,150,300);
    h.Info();
    //h2 = h;    //error:'operator='is a private member of HomeForSale
}

//////////////////////////////////////////////////////////

//uncopyable class
class uncopyable
{
protected:
    uncopyable(){}
    ~uncopyable(){}
    //allow construction and destruction of derived objects

private:
    uncopyable(const uncopyable&); //prevent copying
    uncopyable operator=(const uncopyable&);

};

class HomeForSale:private uncopyable
{
public:
    HomeForSale(std::string &name, double ar, double prc):ownner(name),area(ar),price(prc){};
    void Info(){std::cout << ownner << " " << area << " " << price; }
private:
    double area;
    std::string ownner;
    double price;
};

int main()
{
    std::string name1 = "Kevin";
    std::string name2 = "Shirley";
    HomeForSale h(name1,120,200);
    HomeForSale h2(name2,150,300);
    h.Info();

    HomeForSale h2(h);
//Call to implicitly-deleted copy constructor of 'HomeForSale'
    //h2 = h;    
//Object of type 'HomeForSale' cannot be assigned because its copy assignment operator is implicitly deleted
}