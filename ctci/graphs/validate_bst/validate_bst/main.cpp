//
//  main.cpp
//  validate_bst
//
//  Created by Scott Jackson on 3/22/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//
// 4.5 - Write a function to validate a BST.
#include <iostream>
#include <vector>

#include "node.hpp"
#include "tree.hpp"
#include "validation.hpp"

using std::cout;
using std::endl;
using std::vector;


void tc_1() {
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    Node* root = build_tree_from_vector(v);
    int cnt = disp(root);
    
    //cout << (!root) << endl;
    
    cout << "NODES: " << cnt << " ROOT:" << root->val << endl;    
}

void tc_2() {
    vector<int> v = {1,2,3,4,5,6,7,8,9,10,11};
    Node* root = build_tree_from_vector(v);
    int cnt = disp(root);
    
    //cout << (!root) << endl;
    
    cout << "NODES: " << cnt << " ROOT:" << root->val << endl;
}


void tc_3() {
    vector<int> v = {1};
    Node* root = build_tree_from_vector(v);
    int cnt = disp(root);
    
    //cout << (!root) << endl;
    
    cout << "NODES: " << cnt << " ROOT:" << root->val << endl;
}

void tc_4() {
    vector<int> v = {};
    Node* root = build_tree_from_vector(v);
    int cnt = disp(root);
    
    //cout << (!root) << endl;
    
    if (root)
        cout << "NODES: " << cnt << " ROOT:" << root->val << endl;
    else
        cout << "NO ROOT -> " << cnt << endl;
    
}

void tc_5() {
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    Node* root = build_tree_from_vector(v);
    int cnt = disp(root);
    
    //cout << (!root) << endl;
    
    cout << "NODES: " << cnt << " ROOT:" << root->val << endl;
    
    bool res = validate(root);
    cout << "VALIDATE: " << (res ? "YES" : "NO" ) << endl;
}

void tc_6() {
    vector<int> v = {1,20,3,4,5,6,7,8,9,1};
    Node* root = build_tree_from_vector(v);
    int cnt = disp(root);
    
    //cout << (!root) << endl;
    
    cout << "NODES: " << cnt << " ROOT:" << root->val << endl;
    
    bool res = validate(root);
    cout << "VALIDATE: " << (res ? "YES" : "NO" ) << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    tc_6();
    return 0;
}
