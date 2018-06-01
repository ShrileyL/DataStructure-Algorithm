//
//  main.cpp
//  test
//
//  Created by Shulin on 2018/5/6.
//  Copyright © 2018年 Shulin. All rights reserved.
//

#include <iostream>
#include <vector>
#include "tree.hpp"
using namespace std;

int main(void)
{
    node *root = new node(10);
    insert(root, 6);
    insert(root, 27);
    insert(root, 18);
    insert(root, 4);
    insert(root, 9);
    insert(root, 33);

    std::cout << "Pre order: " << std::endl;
    preordertree(root);
    std::cout <<std::endl;
    std::cout << "Recursion Pre order: " << std::endl;
    iterpreordertree(root);
    
    std::cout << "Post order: " << std::endl;
    postordertree(root);
    std::cout <<std::endl;
    std::cout << "Recurdion Post order: " << std::endl;
    iterpostordertree(root);
    
    std::cout << "In order: " << std::endl;
    inordertree(root);
    std::cout <<std::endl;
    std::cout << "Recursion In order: " << std::endl;
    iterinordertree(root);
    
    return 0;
}
//int main(int argc, const char * argv[]) {
//    // insert code here...
//    std::cout << "Hello, World!\n";
//    return 0;
//}
