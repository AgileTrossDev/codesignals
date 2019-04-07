//
//  main.cpp
//  tree_longest_consecutive_branch
//
//  Created by Scott Jackson on 4/7/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::queue;
using std::max;





struct Node {
    Node(int v, Node* l = nullptr, Node * r = nullptr):val(v),left(l), right(r){};
    
    int val;
    Node *left;
    Node *right;
};


typedef queue<Node*> node_q_t;

int solve(Node *root,int n, int v) {
    if (root==nullptr ) return n;
    if ((root->val - n) == 1)
        n++;
    else
        n=0;
    
    
    return max(solve(root->left,n, root->val), solve(root->right,n,root->val));
    
}


int solve(Node *root) {
    return max(solve(root->left,1, root->val), solve(root->right,1,root->val));
}


Node * build_test_tree_1() {
    
    // 1-> 0
    Node * root = new Node(0);
    Node * index = root;
    
    // 2 -> 1 2
    root->left = new Node(1);
    root->right = new Node(2);
    
    
    // 3 -> 1 2 1 3
    index = root->left;
    index->left = new Node(1);
    index->right = new Node(2);
    
    index = root->right;
    index->left = new Node(1);
    index->right = new Node(3);
    
    
    // 4-> 5 6 3 4 2 1 4 5
    index = root->left->left;
    index->left = new Node(5);
    index->right = new Node(6);
    
    index = root->left->right;
    index->left = new Node(3);
    index->right = new Node(4);
    
    
    index = root->right->left;
    index->left = new Node(2);
    index->right = new Node(1);
    
    index = root->right->right;
    index->left = new Node(4);
    index->right = new Node(5);
    
    return root;

}

void disp_tree_in_order(Node* root) {
    if (root == nullptr) return;
    
    
    disp_tree_in_order(root->left);
    cout << root->val << endl;
    disp_tree_in_order(root->right);
    
    
}


void process_queue(node_q_t & in_q,node_q_t & out_q){
    while (!in_q.empty()){
        Node * cur = in_q.front();
        in_q.pop();
        cout << cur->val << " ";
        if (cur->left ) out_q.push(cur->left);
        if (cur->right ) out_q.push(cur->right);
    }
    cout << endl;
    
}


void disp_tree_by_depth(Node* root) {
    if (root == nullptr) return;
    node_q_t q1, q2;

    q1.push(root);
    while(!q1.empty() || !q2.empty()) {
        
        while (!q1.empty()){
            process_queue(q1,q2);
            
        }
        
        while (!q2.empty()){
            process_queue(q2,q1);
            
        }
    }
}



void disp_side(Node* root ,int  side) {
    if (root == nullptr) {
        return;
    } else if (root->left == nullptr && root->right == nullptr){
        cout << root->val << endl;
    } else if (side ==1) {
        // left side
        cout << root->val << endl;
        disp_side(root->left,1);
        disp_side(root->right,0);
    } else if (side ==2) {
        // right side
        disp_side(root->left,0);
        disp_side(root->right,2);
        cout << root->val << endl;
        
    } else if (side ==0) {
        // left side
        disp_side(root->left,0);
        disp_side(root->right,0);
    }
}

void disp_edges(Node * root) {
    cout << root->val << endl;
    
    disp_side(root->left,1);
    disp_side(root->right,2);
    
    
    
    
}

void tc_1() {
    Node * root = build_test_tree_1();
    //disp_tree_in_order(root);
    disp_tree_by_depth(root);
    disp_edges(root);
    
    int result = solve(root);
    
    cout << "TC 1: " << result << endl;
    
    
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    return 0;
}
