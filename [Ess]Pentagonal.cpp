#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

inline bool check_validity( int pos );
const vector<int>* pentagonal_series( int pos );
bool pentagonal_elem( int po, int &elem );

int main(int argc, char const *argv[])
{
	
	return 0;
}

inline bool check_validity( int pos ) 
{
	return ( pos <= 0 || pos > 64 )
          ? false : true;
}

const vector<int>*
pentagonal_series( int pos )
{
    static vector<int> _elems;
    if ( check_validity( pos ) && ( pos > _elems.size() ))
    {	
         for ( int ix = _elems.size()+1; ix <= pos; ++ix ) {
// cout << "ix: " << ix << " == " << (ix*(3*ix-1))/2 << endl;
               _elems.push_back( (ix*(3*ix-1))/2 );
		 }
     }
   return &_elems;
}

bool pentagonal_elem( int pos, int &elem )
{
	    if ( ! check_validity( pos )){
		 cout << "Sorry. Invalid position: " << pos << endl;
         elem = 0;
		 return false;
	 }

    const vector<int> *pent = pentagonal_series( pos );
    elem = (*pent)[pos-1];
    return true;
}

