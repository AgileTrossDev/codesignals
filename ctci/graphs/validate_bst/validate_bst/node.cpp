//
//  node.cpp
//  validate_bst
//
//  Created by Scott Jackson on 3/22/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include "node.hpp"


Node* Node::add_child(int v) {
    
    if (v <= val) {
        if (!left)
            left= new Node(v);
        else
            left->add_child(v);
    } else {
        if (!right)
            right= new Node(v);
        else
            right->add_child(v);
    }
    
    return (v <= val) ? left : right;
}
