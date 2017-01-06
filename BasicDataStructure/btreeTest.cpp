/**************************************************
 * Essential C++ -- Stanley Lippman
 * Addison-Wesley 
 * ISBN 0-201-48518-4
 * homepage: www.objectwrite.com
 * email: slippman@objectwrite.com
 *************************************************/

#include <string>
#include <algorithm>
#include <fstream>

#include "btree.hpp"
using namespace std;

int main() 
{
	/*
    BinaryTree< int > bt;

	bt.insert( 7 );
	bt.insert( 5 );
	bt.insert( 9 );
	bt.insert( 6 );
	bt.insert( 3 );
    */

	/*
	BinaryTree< string > bt;
	bt.insert( "Piglet" );
	bt.insert( "Pooh" );
	bt.insert( "Eeyore" );
	bt.insert( "Kanga" ); 
	bt.insert( "Tigger" );
	*/

	ofstream log( "logfile.txt" );
	if ( ! log ){
		 cerr << "error: unable to open file!\n";
		 return -1;
	}
	else BinaryTree<string>::current_os( &log );

	/*
	int ia[] = { 24, 18, 36, 12, 14, 8, 24, 1, 42, 24, 8, 8, 16, 55 };
	vector< int > ivec( ia, ia + 14 );
	BinaryTree<int> bt( ivec );

	log << "preorder traversal: \n";
    // cout << should see\n\t ";
	bt.preorder( log );

	bt.clear();
	log << "\nbt is now " << ( bt.empty() ? " empty! " : " oops -- not empty!" ) << endl;

	sort( ivec.begin(), ivec.end() );
	bt.insert( ivec );

	log << "\n\ninorder traversal:\n";
	bt.inorder( log );

	bt.insert( ivec );

	log << "\n\npostorder traversal:\n";
	bt.postorder( log );

	log << endl << endl;
    */

	BinaryTree<string> bt;
    bt.insert( "Piglet" );
    bt.insert( "Eeyore" );
	bt.insert( "Roo" );

	bt.insert( "Tigger" );
	bt.insert( "Chris" );
	bt.insert( "Pooh" );
	bt.insert( "Kanga" );

	log << "preorder traversal: \n";
	bt.preorder( log );

	log << "\n\nabout to remove root: Piglet\n";
	bt.remove( "Piglet" );

	log << "\n\npreorder traversal after Piglet removal: \n";
	bt.preorder( log );

	log << "\n\nabout to remove Eeyore\n";
	bt.remove( "Eeyore" );

	log << "\n\npreorder traversal after Piglet removal: \n";
	bt.preorder( log );

//	log << "\n\ninorder traversal:\n";
//	bt.inorder( log );

//	log << "\n\npostorder traversal:\n";
//	bt.postorder( log );
//
    return 0;
}