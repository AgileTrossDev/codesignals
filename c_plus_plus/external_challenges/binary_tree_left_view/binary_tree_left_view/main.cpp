//
//  main.cpp
//  binary_tree_left_view
//
//  Created by Scott Jackson on 12/20/18.
//  Copyright © 2018 Scott Jackson. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;

struct Node {
    Node(int v) : val(v) {};
    
    Node * right;
    Node * left;
    int val;
    
    
    
};


void disp_left_view(Node * root) {
    
    
    while (root) {
        cout << root->val << endl;
        
        if (root->left)
            root = root->left;
        else
            root = root->right;
        
        
    }
 
    
}

void test_case_0() {
    
    Node * root = new Node(1);
    
    root->left = new Node(2);
    root->right = new Node(3);
    
    root->left->left = new Node(4);
     root->left->right = new Node(5);
    
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    root->left->left->right  = new Node(8);
    
    
    disp_left_view(root);
    
    

    
    
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    test_case_0();
    return 0;
}
