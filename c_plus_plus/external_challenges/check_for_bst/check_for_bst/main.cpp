//
//  main.cpp
//  check_for_bst
//
//  Created by Scott Jackson on 12/20/18.
//  Copyright © 2018 Scott Jackson. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;



struct Node {
    Node(int v): val(v), left(nullptr), right(nullptr){};
    
    Node * left;
    Node * right;
    
    int val;
    
    
};

void disp(Node * root);


bool check_for_bst(Node * root ) {
    
    if (root == nullptr) return true;
    
    
    if ((!root->left || root->val > root->left->val) && (!root->right || root->val < root->right->val) )
        return (check_for_bst(root->left) && check_for_bst(root->right));

    return false;
    
    
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
    
     disp(root);
    
    cout << "TC 0: " << check_for_bst(root) << endl;
    
}

void test_case_1() {
    Node * root = new Node(10);
    
    root->left = new Node(5);
    root->right = new Node(20);
    
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    
    root->right->left = new Node(15);
    root->right->right = new Node(25);
    
    root->left->left->right  = new Node(4);
    
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(8);
    
    disp(root);
    
    cout << "TC 1: " << check_for_bst(root) << endl;
    
}

void disp(Node * root) {
    if (root == nullptr) return;
    
    disp(root->left);
    cout << root->val << endl;
    disp(root->right);
    
    
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    test_case_0();
     test_case_1();
    return 0;
}
