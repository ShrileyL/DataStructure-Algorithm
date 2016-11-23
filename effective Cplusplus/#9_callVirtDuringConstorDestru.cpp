/**************************************************
 * Effective C++ 
 * 
 * #9 never call virtual function during construct&destructor
 * 
 * because the calls wont do what you think 
 *
 *
 * Remark: all virtual function during construct&destructor
 *         C++ will treat it as if they no longer exist   
 *
 * 2016/11/23 Shirley test
 *************************************************/

#include <iostream>
#include <string>

using namespace std;

class Transaction  //base class for all tranctions
{
public:
	Transaction();
	~Transaction(){cout << "Transaction destructor"<< endl;};
	virtual void logTransaction() const = 0; //pure virtual function
};

Transaction::Transaction()
{
	cout << "Transaction constructor. call logTransaction() here." << endl;
	logTransaction();
	// Call to pure virtual member function 'logTransaction' has undefined behavior; overrides of 'logTransaction' in subclasses are not available in the constructor of 'Transaction'
}

class SellTransction:public Transaction
{
public:
	SellTransction(){cout << "SellTransaction constructor" << endl;};
	~SellTransction(){cout << "SellTransaction destructor" << endl;};
	void logTransaction() const{cout << "SellTransaction logTransaction" << endl;}; //
};

class BuyTransaction:public Transaction
{
public:
	BuyTransaction(){cout << "BuyTransaction constructor" << endl;};
	~BuyTransaction(){cout << "BUyTransaction destructor" << endl;};
	void logTransaction() const{cout << "BuyTransaction logTransaction" << endl;};
};

int main()
{
    BuyTransaction b;//error: pure virtual function called!
    
    return 0;
}

// Output:
// Transaction constructor. call logTransaction() here.
// libc++abi.dylib: Pure virtual function called!


/* ****************************************************************** */
#include <iostream>
#include <string>

using namespace std;

class Transaction  //base class for all tranctions
{
public:
    Transaction(){init();};
    ~Transaction(){cout << "Transaction destructor"<< endl;};
    virtual void logTransaction() const {cout << "Transaction logTransaction" << endl;}; //
private:
    void init()
    {
        cout << "Transaction constructor. call logTransaction() here." << endl;
        logTransaction();//call the logTranszction in base class,not virtual(dynamic_casts)
    }
};

//Transaction::Transaction()
//{
//    cout << "Transaction constructor. call logTransaction() here." << endl;
//    logTransaction();
//}

class SellTransction:public Transaction
{
public:
    SellTransction(){cout << "SellTransaction constructor" << endl;};
    ~SellTransction(){cout << "SellTransaction destructor" << endl;};
    void logTransaction() const{cout << "SellTransaction logTransaction" << endl;}; //
};

class BuyTransaction:public Transaction
{
public:
    BuyTransaction(){cout << "BuyTransaction constructor" << endl;};
    ~BuyTransaction(){cout << "BUyTransaction destructor" << endl;};
    void logTransaction() const{cout << "BuyTransaction logTransaction" << endl;};
};

int main()
{
    BuyTransaction b;
    
    return 0;
}

// Output:
// Transaction constructor. call logTransaction() here.
// Transaction logTransaction
// BuyTransaction constructor
// BUyTransaction destructor
// Transaction destructor