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
#include <cstdlib>
#include <vector>
using namespace std;

//forward declaration of fibon_elem
//make function known to complier
bool fibon_elem( int pos, int &);
void print_sequence( int pos );
//Fibonacc recursion
int fibona(int pos);


vector<int> fibon_seq( int size );

//main
int main(int argc, char const *argv[])
{
  int pos = 1;
  int elem;
  while(pos)
  {
    cout << "Fibonacci Numbers, please enter a number( 0 to exit): " << endl;
    cin >> pos;
        
    if (fibon_elem(pos,elem))
      cout << "element # " << pos << " is " << elem << endl;
    else
      cout << "Sorry, Could not calculate elememt # " << pos <<endl;
    print_sequence(elem);
  }

  //test for fibon_seq()
  std::vector<int> fibonacci = fibon_seq(14);
  std::vector<int>::iterator it;
  for (it = fibonacci.begin(); it != fibonacci.end(); ++it)
  {
      cout << *it << endl;
  }


  return 0;
}


//fibon_elem
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


//print_sequence
void print_sequence( int pos ) 
{
	if ( pos <= 0 || pos > 1024 ){
		 cerr << "invalid position: " << pos 
			  << " -- cannot handle request!\n";
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
}

int fibona(int pos)
{
  if (pos <= 0 || pos > 1024)
  {
    cerr << "Warning: fibona(): " <<pos << " not supported.";
  }
  if (pos == 1 || pos == 2)
    return 1;
  else 
    return (fibona(pos - 1) +fibona(pos - 2));

}

vector<int> fibon_seq( int size )
{
   if ( size <= 0 || size > 1024 )
   {
        cerr << "Warning: fibon_seq(): "
             << size << " not supported -- resetting to 8\n";
      size = 8;
  }

   vector<int> elems( size );

   for ( int ix = 0; ix < size; ++ix )
       if ( ix == 0 || ix == 1 )
          elems[ ix ] =  1;
      else elems[ ix ] =  elems[ix-1] + elems[ix-2];

   return elems;
}