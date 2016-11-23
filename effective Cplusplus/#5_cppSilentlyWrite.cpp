/**************************************************
 * Effective C++ 
 * 
 * #5 C++ default copy constructors
 * 
 *
 * 2016/11/23 Shirley test
 *************************************************/

#include <iostream>
#include <string>

using namespace std;

template<typename T>
class NamedObject
{
public:
    // NamedObject();
    // ~NamedObject();
    NamedObject(const char *name, const T& value)
    {
        nameValue = string(name);
        objectValue = value;
    }
    NamedObject(const std::string& name, const T& value)
    {
        nameValue = name;
        objectValue = value;
    }
    void display()
    {
        std::cout << nameValue << " " << objectValue<<endl;
    }
private:
    std::string nameValue;
    T objectValue;
    
};

template<typename T>
class rNamedObject
{
public:
    //this copy constructor no longer take a const name 
    // because nameValue is now a reference-to-non-const string.

    rNamedObject(std::string& name, const T& value):nameValue(name),objectValue(value){};
    void display()
    {
        std::cout << nameValue << " " << objectValue<<endl;
    }
private:
    std::string& nameValue;
    const T objectValue;
    
};


int main(int argc, char const *argv[])
{
    NamedObject<int> no1("Smallest Prime Number",2);
    NamedObject<int> no2(no1);
    no1.display();
    no2.display();

    std::string newDog("Persephone");
    std::string oldDog("Satch");
    rNamedObject<int> p(newDog,2);
    rNamedObject<int> s(oldDog,24);


    
    return 0;
}