/**************************************************
 * Effective C++ 
 * 
 * #7 declare destructor virtual 
 * 
 * factory function: return a base class pointer to 
 * a newly-created derived class object
 *
 * Remark: Give destructor virtual:
 *            only to polymorphic base classes!
 *
 * 2016/11/23 Shirley test
 *************************************************/

#include <iostream>
#include <string>

using namespace std;

class Timekeeper
{
public:
    Timekeeper(){cout << "Timekeeper construct."<<endl;};
    virtual ~Timekeeper(){cout << "Timekeeper destruct."<<endl;};
    virtual Timekeeper* getTimeKeeper()
    {
        Timekeeper *p = new Timekeeper;
        return p;
    };};

class AtomicClock: public Timekeeper
{
public:
    AtomicClock():Timekeeper(){cout << "AtomicClock construct."<<endl;};
    ~AtomicClock(){cout << "AtomicClock destruct."<<endl;};
    Timekeeper* getTimeKeeper()
    {
        Timekeeper *p = new AtomicClock;
        return p;
    }
};

int main()
{
    AtomicClock ac;
    Timekeeper *ptk =ac.getTimeKeeper();
    delete ptk;
    return 0;
}

// output:
// Timekeeper construct.
// AtomicClock construct.
// Timekeeper construct.
// AtomicClock construct.
// AtomicClock destruct.
// Timekeeper destruct.
// AtomicClock destruct.
// Timekeeper destruct.