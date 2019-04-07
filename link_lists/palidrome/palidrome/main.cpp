//
//  main.cpp
//  palidrome
//
//  Created by Scott Jackson on 3/31/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//
// Description:  Check if link list is a palidrone
//
// Lessons Learned:
//   - think through logically.
//   - Identify states of execution.
//   - Check edge cases.
#include <iostream>

using std::cout;
using std::endl;
struct Node {
    Node(int v, Node * n = nullptr): val(v), next(n) {};
    ~Node() { delete next;}
    int val;
    Node * next;
};


Node * is_palidrome(Node * lead,  Node * root ) {
     if (!lead) return  root;
    
    // Advance lead
    Node * tail =  is_palidrome(lead->next, root );
    if (!tail) return nullptr;
    if (tail == root) return root;
    
    if (tail == lead ) return root;
    
    cout << lead->val << " == " << tail->val << endl;
    if ( lead->val != tail->val) return nullptr;
    
    return tail->next;
    
    
   
}


bool is_palidrome(Node * root) {
    if (!root) return true;
    return (root == is_palidrome(root,root));
}

void disp(Node * root) {
    cout << "Link List: ";
    while (root) {
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
    
}

Node * build_valid() {
    Node * root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(3);
    
    root->next->next->next = new Node(4);
    Node * index = root->next->next->next;
    
    index->next = new Node(3);
    index->next->next = new Node(2);
    index->next->next->next = new Node(1);
    
    return root;
    
}

Node * build_valid_2() {
    Node * root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(3);
    
    root->next->next->next = new Node(4);
     root->next->next->next->next = new Node(4);
    Node * index = root->next->next->next->next;
    
    index->next = new Node(3);
    index->next->next = new Node(2);
    index->next->next->next = new Node(1);
    
    return root;
    
}



Node * build_invalid() {
    
    Node * root = new Node(1);
    root->next = new Node(2);
    root->next->next = new Node(3);
    
    root->next->next->next = new Node(4);
    Node * index = root->next->next->next;
    
    index->next = new Node(3);
    index->next->next = new Node(2);
    index->next->next->next = new Node(1);
    index->next->next->next->next = new Node(0);
    
    return root;
    
}

void tc_1(){
    
    Node * root = build_valid();
    disp(root);
    cout << is_palidrome(root) << endl;
    
    root = build_invalid();
    disp(root);
    cout << is_palidrome(root) << endl;
    
    root = build_valid_2();
    disp(root);
    cout << is_palidrome(root) << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    
    return 0;
}
