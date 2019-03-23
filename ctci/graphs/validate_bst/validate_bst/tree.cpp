//
//  tree.cpp
//  validate_bst
//
//  Created by Scott Jackson on 3/22/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include "tree.hpp"
#include <iostream>


using std::vector;
using std::cout;
using std::endl;

Node* build_tree_from_vector(vector<int> &v,Node* root, size_t start, size_t tail) {
    
    if (start>tail || start <0 || tail > v.size() || start == v.size() ) return nullptr;
    
    size_t mid = start + (tail-start)/2;
    cout << "BUILDING NODE: " << mid << " start: " << start << " tail: " << tail <<  endl;
    Node * n = new Node(v[mid]);
    
    n->left = build_tree_from_vector(v,root, start,mid-1);
    n->right = build_tree_from_vector(v,root, mid+1,tail);
    
    return n;
}


//
Node* build_tree_from_vector(vector<int> &v) {
    if (v.empty()) return nullptr;
    Node * root = new Node(v[v.size()/2]);
    return build_tree_from_vector(v, root,0,v.size());
}


int disp(Node * root) {
    
    if (!root) return 0;
    
    int cnt = 1 ;
    cnt += disp(root->left);
    cout << "-> " << root->val << " <- " <<  endl;
    cnt += disp(root->right);
    
    return cnt;
}
