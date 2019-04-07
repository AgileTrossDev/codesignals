//
//  main.cpp
//  link_list_cycles
//
//  Created by Scott Jackson on 4/4/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::to_string;


struct Node {
    Node(int v, Node* n = nullptr) : val(v), next(n) {};
    Node * set_next(int v) { next = new Node(v); return next;}
    void set_next(Node * n) { next = n;}
    
    int val;
    Node * next;
    
};



Node*  build_ll_with_cycle() {
    Node * root = new Node(0);
    Node * index= root;
    for (int i =1; i < 11; i++ ) {
        index = index->set_next(i);
        
    }
    
    index->set_next(root->next->next->next);
    
    
    cout << "CYCLE CREATED: " << index->val << " loops to " << index->next->val << endl;
    
    
    return root;
    
}

Node*  build_ll_without_cycle() {
    Node * root = new Node(0);
    Node * index= root;
    for (int i =1; i < 11; i++ ) {
        index = index->set_next(i);
        
    }
    return root;
}

Node * detect_cycle(Node * root) {
    Node * lead = root;
    Node * trail = root;
    
    
    
    while (lead !=nullptr) {
        lead = lead->next;
        trail = trail->next;
        if (lead) lead = lead->next;
        
        if (trail == lead) return trail;
        
    }
    
    return nullptr;
    
}


int cycle_size(Node * root) {
    Node * index = root;
    int cnt = 1;
    index = index->next;
    while (index !=  root) {
        cnt++;
        index = index->next;
    }
    return cnt;
}


void remove_cycle(Node * root, int length ){
    
    Node * lead=  root;
    Node * lead_parent = root;
    Node * tail = root;
    
    while (length) {
        lead_parent= lead;
        lead=lead->next;
        length--;
    }
    
    while (tail!=lead) {
        lead_parent= lead;
        lead=lead->next;
        tail= tail->next;
    }
    
    cout << "START OF LOOP: " << lead->val << endl;
    
    
    lead_parent->set_next(nullptr);
    
    
    
    
}

void tc_1() {
    Node * root = build_ll_without_cycle();
    Node * res = detect_cycle(root);
    
    cout << "TC 1: " << (res != nullptr ? to_string(res->val) : "NO LOOP") << endl;
}

void tc_2() {
    Node * root = build_ll_with_cycle();
    Node * res = detect_cycle(root);
    
    cout << "TC 2: " << (res !=nullptr ? to_string(res->val) : "NO LOOP") << endl;
    
    int loop_size = cycle_size(res);
    
    cout << "CYCLE SIZE: " << loop_size << endl;
    
    remove_cycle(root,loop_size);
    
    res = detect_cycle(root);
    cout << "TC 2: " << (res !=nullptr ? to_string(res->val) : "NO LOOP") << endl;
    
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    tc_2();
    return 0;
}
