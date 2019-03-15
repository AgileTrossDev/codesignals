//
//  binary_tree.hpp
//  prep
//
//  Created by Scott Jackson on 3/14/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#ifndef binary_tree_hpp
#define binary_tree_hpp

#include <stdio.h>

struct Node {
    Node (int v): val(v), left(nullptr), right(nullptr){};
    ~Node();
    void disp();
   
    
    int val;
    Node *right;
    Node *left;
    
};

struct BinaryTree {
    BinaryTree():root(nullptr){};
    ~BinaryTree();
    void add_node(int v);
    void disp();
    
    
    
    Node * root;
    
};

#endif /* binary_tree_hpp */
