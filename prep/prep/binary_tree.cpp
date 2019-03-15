//
//  binary_tree.cpp
//  prep
//
//  Created by Scott Jackson on 3/14/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

// Lessons
//   - Be sure to include desctructor



#include "binary_tree.hpp"
#include <iostream>

using std::cout;
using std::endl;


BinaryTree::~BinaryTree() {
    cout <<"Cleaning tree..." << endl;
    delete root;
    cout << "Tree cleaned!" << endl;
}

Node::~Node() {
    cout << "DELETING NODE: " << val << endl;
    delete left;
    delete right;
}

void BinaryTree::add_node(int v) {
    
    if (root == nullptr ) {
        root = new Node(v);
    } else {
      
        Node * index = root;
    
        while ((v <= index->val && index->left != nullptr) ||
               (v > index->val && index->right != nullptr)) {
            index = (v <= index->val) ? index->left :index->right;
        }
        
        if (v <= index->val)
            index->left = new Node(v);
        else
            index->right = new Node(v);
    }
    
    
}


void BinaryTree::disp() {
    root->disp();
    
}

void Node::disp() {
    if (left) left->disp();
    if (right) right->disp();
    cout << val << endl;
    
}
