/**************************************************
 * Essential C++ -- Stanley Lippman
 * Addison-Wesley 
 * ISBN 0-201-48518-4
 * homepage: www.objectwrite.com
 * email: slippman@objectwrite.com
 *
 * 2016/11/6 Shirley test
 *************************************************/

#include <iostream>
using namespace std;

bool fibon_elem( int pos, int &elem )
{

	if ( pos <= 0 || pos > 1024 )
	{
		 cerr << "invalid position: " << pos 
			  << " -- cannot handle request!\n";

         elem = 0;
         return false;
	}

    elem = 1; 
    int n_2 = 1, n_1 = 1;
    for ( int ix = 3; ix <= pos; ++ix ) 
    {
		 elem = n_2 + n_1;
		 n_2 = n_1; n_1 = elem;
    }  
	
    return true;
}

bool print_sequence( int pos ) 
{
	if ( pos <= 0 || pos > 1024 ){
		 cerr << "invalid position: " << pos 
			  << " -- cannot handle request!\n";
         return false; 
	}

   cout << "The Fibonacci Sequence for "
        << pos << " positions: \n\t";

   // prints “1 1” for all values except pos == 1
   switch ( pos ) {
       default:
       case 2:
			 cout << "1 ";
           // no break;
       case 1:
			 cout << "1 ";
           break;
    }

   int elem;
   int n_2 = 1, n_1 = 1;
   for ( int ix = 3; ix <= pos; ++ix ) 
   {
		 elem = n_2 + n_1;
		 n_2 = n_1; n_1 = elem;

		 // print 10 elements to a line
		 cout << elem 
			 << ( !( ix % 10 ) ? "\n\t" : " " );
   }

   cout << endl;
   return true;
}