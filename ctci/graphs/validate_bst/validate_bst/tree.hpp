//
//  tree.hpp
//  validate_bst
//
//  Created by Scott Jackson on 3/22/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#ifndef tree_hpp
#define tree_hpp

#include <stdio.h>
#include <vector>
#include "node.hpp"

Node* build_tree_from_vector(std::vector<int> &v);
Node* build_tree_from_vector(std::vector<int> &v,Node* root, size_t start, size_t tail);
int disp(Node * root);

#endif /* tree_hpp */
