//
//  main.cpp
//  tree_to_dbl_link_list
//
//  Created by Scott Jackson on 1/13/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;

struct Node {
    Node(int v): val(v), left(nullptr), right(nullptr) {};
    
    void add_left_child(int v) { left = new Node(v); }
    void add_right_child(int v) { right = new Node(v); }
    
    int val;
    Node * left;
    Node * right;
    
    
    
};


void in_order_disp(Node * root ) {
    if (!root) return;
    in_order_disp(root->left);
    cout << root->val << endl;
    in_order_disp(root->right);
    
}

void flatten_tree_util(Node * root, Node* &start, Node* &tail) {
    if (!root) return;
    
    // Check left side and set start accordingly.
    if(root->left) {
        Node * l_start =nullptr;
        Node * l_tail = nullptr;
        flatten_tree_util(root->left, l_start, l_tail);
        start = l_start;
        l_tail->right = root;
        root->left = l_tail;
    } else {
        start = root;
        
    }
    
    // At this point, the list ends with tail
    tail = root;
    start->left = nullptr;
    
    // Check right side, and update tail accordingly
    if (root->right) {
        Node * l_start = nullptr;
        Node * l_tail = nullptr;
        flatten_tree_util(root->right, l_start, l_tail);
        tail->right = l_start;
        l_start->left = tail;
        tail = l_tail;
    }

    tail->right = nullptr;

}

Node * flatten_tree(Node * root) {
    
    Node * start = nullptr;
    Node * tail = nullptr;
    
    flatten_tree_util(root,start,tail);
    return start;
    
}


void disp_flatten_tree(Node * root ){
    if (!root) return;
    cout << root->val << endl;
    disp_flatten_tree(root->right);
    
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Node * root = new Node(10);
    root->add_left_child(12);
    root->add_right_child(15);
    root->left->add_left_child(25);
    root->left->add_right_child(30);
    root->right->add_left_child(36);
    
    in_order_disp(root);
    
    root = flatten_tree(root);

    
    cout << "NEW ROOT VAL: " << root->val << endl;
    disp_flatten_tree(root);
    
    return 0;
}
