//
//  main.cpp
//  superbalanced
//
//  Created by Scott Jackson on 3/15/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include "BinaryTreeNode.hpp"

using std::cout;
using std::endl;


void tc_2() {
    // Full Tree;
  
    BinaryTreeNode *root  = new BinaryTreeNode(5);
    root->insertLeft(8)->insertLeft(1);
    root->insertRight(6)->insertRight(4);
    root->left_->insertRight(2);
    root->right_->insertLeft(3);
    
    root->disp();
    bool res = isBalanced(root);
    
    cout << "RESULT: " << res << endl;
}

void tc_1(){
    
    BinaryTreeNode *root  = new BinaryTreeNode(6);
    root->insertLeft(1);
    root->insertRight(0)->insertRight(7)->insertRight(8);
    
    //root->disp();
    bool res = isBalanced(root);
    
    cout << "RESULT: " << res << endl;
    
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    cout << endl;
    tc_2();
    return 0;
}
