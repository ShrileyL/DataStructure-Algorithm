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
#include "narraytree.hpp"
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

    // std::cout << "Pre order: " << std::endl;
    // preordertree(root);
    // std::cout <<std::endl;
    // std::cout << "Recursion Pre order: " << std::endl;
    // iterpreordertree(root);
    // std::cout << "Morris Pre order: " << std::endl;
    // morrispreorder(root);
    
    // std::cout << "Post order: " << std::endl;
    // postordertree(root);
    // std::cout <<std::endl;
    // std::cout << "Recurdion Post order: " << std::endl;
    // iterpostordertree(root);
    
    // std::cout << "In order: " << std::endl;
    // inordertree(root);
    // std::cout <<std::endl;
    // std::cout << "Recursion In order: " << std::endl;
    // iterinordertree(root);
    // std::cout << "Morris In order: " << std::endl;
    // morrisinorder(root);
    
    // std::cout << "Level first: " << std::endl;
    // breathfirst(root);

    node* t1 = new node(2);
    insert(t1,1);
    insert(t1,4);
    insert(t1,5);
    node* t2 = new node(3);
    insert(t2,1);
    insert(t2,6);
    insert(t2,7);
    insert(t2,2);

    
    std::cout << "tree 1 :" << std::endl;
    preordertree(t1);
    std::cout << "tree 2 :" << std::endl;
    preordertree(t2);
    std::cout <<"Merge two trees: " << std::endl;
    preordertree(itermergeTrees(t1,t2));
    std::cout << "max depth: " << maxDepthRecursive(t1) << std::endl;

    return 0;
}
