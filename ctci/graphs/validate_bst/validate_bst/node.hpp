//
//  node.hpp
//  validate_bst
//
//  Created by Scott Jackson on 3/22/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#ifndef node_hpp
#define node_hpp

#include <stdio.h>

struct Node {
    Node(int v): val(v), left(nullptr), right(nullptr){};
    
    Node* add_child(int v);
    
    int val;
    Node* left;
    Node* right;
};

#endif /* node_hpp */
