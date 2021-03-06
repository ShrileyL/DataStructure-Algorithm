//
//  main.cpp
//  test
//
//  Created by KevinLiu on 16/12/7.
//  Copyright © 2016年 KevinLiu. All rights reserved.
//

//test for linkedlist
#include <iostream>

#include <string>
// inclede Def.hpp file
#include "DataStructureBasicDef.hpp"
using namespace std;


int main()
{
        
    Node<string> node("hello");
//    LinkList<string> list;
//    list.addLast("America");
//    list.print(cout);


    LinkedList<string> list;
    //add element to the list
    list.add("America");
    cout << "(1)";
    list.print();
    
    list.add(0, "Canada");//add to the begining of the list
//    cout << list.getSize();
    cout << "(2)";
    list.print();
//    printList(list);
    
    list.add("Russia");//add to the end of the list
    cout << "(3)";
    list.print();
    
    list.add("France");//add to the end of the list
    cout << "(4)";
    list.print();
    
    list.add(2, "Germany");
    cout << "(5)";
    list.print();
    
    list.add(5, "Norway");
    cout << "(6)";
    list.print();
    
    list.add(0, "Netherlands");
    cout << "(7)";
    list.print();
    
    //remove element from the list
    list.removeAt(0);
    cout << "(8)";
    list.print();
    
    list.removeAt(2);
    cout << "(9)";
    list.print();
    
    list.removeAt(list.getSize() - 1);//remove the last element
    cout << "(10)";
    list.print();
    
    return 0;
}


// test for stack and queue
#include <iostream>
#include <string>
#include "DataStructureBasic.hpp"
#include "StackWIthLinkedList.hpp"


using namespace std;


int main()
{
//    Stack<int> stack;
//    stack.push(1);
//    stack.push(6);
//    stack.push(44);
//    stack.push(2);
//    stack.push(9);
//    cout << stack.pop() << endl;
//    
//    stack.print();
    
    Queue<string> que;
    que.print();

    que.enqueue("America");
    que.enqueue("Japan");
    que.enqueue("Korea");
    que.enqueue("Singapore");
    que.enqueue("Germany");
    que.print();

    cout << que.dequeue() << endl;
    
    que.print();
    

    
    return 0;
}


//test for iterator and new linkedlist
#include <iostream>
#include <string>
#include "Iterator.hpp"


using namespace std;


int main()
{
    LinkedList<string> list;
    list.add("America");
    list.add("Canada");
    list.add("Russia");
    list.add("France");

    for (Iterator<string> itr = list.begin(); itr != list.end(); ++itr)
    {
        cout << *itr << " ";
    }

    cout<<endl;

    
    return 0;
}


//test for binarytree
#include <iostream>
#include <string>
#include "BinaryTree.hpp"
using namespace std;

int main()
{
//    TreeNode<int> a=1;
//    int arraynode[] = {24,3,2,5,9};
//    BinaryTree<int> bt=BinaryTree<int>(arraynode,5);
    
//    cout << bt.getsize()<<endl;
    
//    int a[] = {2, 12,9,3,66};
//    BinaryTree<int> bi;
//    for (int i = 0; i < 5; ++i) {
//        bi.insert(a[i]);
//    }

    
    // int a = 9;
    // BinaryTree<int> bi;
    // bi.insert(a);
    // bi.inorder();

    int arraynode[] = {101,55,107,100,67,45,59,60};
    BinaryTree<int> bi=BinaryTree<int>(arraynode,8);
    cout << bi.getsize()<<endl;
    bi.inorder();
    cout << endl;
    bi.postorder();
    cout << endl;
    bi.preorder();
    cout << endl;
    
    return 0;
}

//test for BinaryTreeSearchIterative
#include <iostream>
#include <string>
#include "BinaryTreeSearchIterative.hpp"
#include <stack>
using namespace std;

int main()
{
    int arraynode[] = {101,55,107,100,67,45,59,60};
    BinaryTree<int> bi=BinaryTree<int>(arraynode,8);
    cout << bi.getsize()<<endl;
    bi.inorder();

    return 0;
}