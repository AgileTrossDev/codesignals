//
//  main.cpp
//  tree_common_ancestor
//
//  Created by Scott Jackson on 4/4/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>
#include <math.h>

using std::cout;
using std::endl;
using std::queue;
using std::stack;
using std::to_string;



class Node;

typedef queue<Node *> builder_t;
typedef stack<Node *> path_t;

struct Node{
    Node(int v, Node * l = nullptr, Node * r = nullptr) : val(v),left(l),right(r) {};

    int val;
    Node * left;
    Node * right;
    
};


void disp(Node * root) {
    if (!root) return;
    
    
    disp(root->left);
    cout << root->val << endl;
    disp(root->right);
    
    
    
}



int lcs(int a, int b) {
    
    while(a != b) {
        if (a<b)
            b=b/2;
        else
            a=a/2;
    }
    return a;
}


Node * build_test_1(int h){
    Node * root  = new Node(1);

    builder_t build_q;
    build_q.push(root);
    int i = 1;
    while (!build_q.empty()) {
        Node * index= build_q.front();
        build_q.pop();
        index->left = new Node(index->val*2);
        index->right = new Node(index->val*2+1);
        if (i<=(pow(2,h)-1)) {
            build_q.push(index->left );
            build_q.push(index->right);
        }
        i++;
    }
    
    cout << "NODES: " << (i*2-1) << endl;
    return root;
    
    
}

Node * find_node_by_position(int v, Node * root) {
    
    if (v == root->val || root == nullptr) return root;
    if (root->left != nullptr && root->left->val == v ) return root->left;
    if (root->right != nullptr && root->right->val == v ) return root->right;
    
    if (root->right->left !=nullptr && v < root->right->left->val )
        return find_node_by_position(v,root->left);
    else  if (root->left->right !=nullptr && v > root->left->right->val )
        return find_node_by_position(v,root->right);
    
    return nullptr;
    
}


Node * path_to(Node * root, Node * a, path_t &path) {
    
    if (root==nullptr) return nullptr;
    
    if (root->val == a->val) {
        path.push(a);
        return a;
    }
    
    Node * res = path_to(root->left,a,path);
    
    if (res == nullptr) res = path_to(root->right,a,path);
    
    
    if (res != nullptr) path.push(root);
    
    return res;
    
    
}

void disp_path(path_t path) {
    cout << "DISPLAYING PATH: ";
    while (!path.empty()) {
        cout << path.top()->val << " ";
        path.pop();
    }
    cout << endl;
    
}

Node * lcs(Node* root, Node* a, Node * b) {
    path_t path_a;
    path_t path_b;
    
    path_to(root,a,path_a);
    path_to(root,b,path_b);
    Node * parent = root;
    
    disp_path(path_a);
    disp_path(path_b);
    
    while (!path_a.empty() && !path_b.empty() && path_a.top() == path_b.top()){
        parent = path_a.top();
        path_a.pop();
        path_b.pop();
    }
    
    if (path_a.empty() && path_b.empty()) parent= nullptr;
    
    
    
    return parent;
}

void tc_2() {
    
    Node * root = build_test_1(10);
    Node * a = find_node_by_position(3,root);
    Node * b = find_node_by_position(4,root);
    
    cout << "Searching for these Nodes: " << a->val << " "<<  b->val << endl;
    Node * found = lcs(root,a,b);
    
    cout << "ANCESTOR: " << (found == nullptr ? "NOT FOUND" : to_string(found->val)) << endl;
  
}


void tc_1() {
    
    Node * root = build_test_1(3);
    disp(root);
   
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int res = lcs(6,7);
    cout << "1: " << res << endl;
    
    tc_2();
    
    
    return 0;
}
