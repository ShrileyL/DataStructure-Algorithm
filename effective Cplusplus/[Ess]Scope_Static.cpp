/**************************************************
 * Essential C++ -- Stanley Lippman
 * Addison-Wesley 
 * ISBN 0-201-48518-4
 * homepage: www.objectwrite.com
 * email: slippman@objectwrite.com
 *
 * 2016/11/7 Shirley test
 *************************************************/

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

const vector<int>*
fibon_seq2( int size )
{
    const int max_size = 1024;
    //"static" variable
    static vector< int > elems;
    
    if ( size <= 0 || size > max_size ){
        cerr << "fibon_seq(): oops: invalid size: "
        << size << " -- can’t fulfill request.\n";
        return 0;
    }
    
    // if size is equal to or greater than elems.size(),
    // no calculations are necessary ...
    for ( int ix = elems.size(); ix < size; ++ix ){
        if ( ix == 0 || ix == 1 )
            elems.push_back( 1 );
        else elems.push_back( elems[ix-1]+elems[ix-2] );
    }
    //return elems by pointer is OK here
    //because it's static 
    //for variables exist only inside function
    //only return by value is correct
    return &elems;
}

void display(const vector<int>*);

int main()
{
    const vector<int>* fib = fibon_seq2(12);
    display(fib);
}

void display(const vector<int>* p)
{
    vector<int>::const_iterator itr =p->begin();
    for (itr; itr != p->end(); itr++) {
        cout << *itr<< " ";
    }
    
}
