//
//  main.cpp
//  random_link_list
//
//  Created by Scott Jackson on 3/26/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

// Lessons Learned
//   - solution is memory heavy
//   - effecient solution could interleave the new link-list into src list.
//     Copy the pointers and then separate list
//
//   - The trick ot the interleaving solution is that old and new are next to each other.
//     So to set the random link, you would just get the cur->random->next to get the
//     pointer to the equivalent random pointer in the cloned link list

#include <iostream>
#include <map>

using std::cout;
using std::endl;
using std::map;

struct Node{
    Node(int v, Node*  n = nullptr, Node * r = nullptr):val(v),next(n), rnd(r){};
    
    int val;
    Node* next;
    Node* rnd;
    
};





Node * build_test_ll() {
    Node * root = new Node(1,new  Node(2, (new Node(3,new Node(4)))));
    
    root->rnd = root->next->next;
    root->next->rnd = root;
    root->next->next->rnd = root->next->next;
    root->next->next->next->rnd = root->next;
    
    return root;
}

void disp (Node * root) {
    
    cout << "DISPLAYING LINK LIST:" << endl;
    
    while (root){
        cout << root->val << "-> " << ((root->rnd) ? root->rnd->val : -1) << endl;
        root = root->next;
        
    }
    
    
    
}

Node * copy_ll(Node * src) {
    Node * dest = nullptr;
    Node * s_index = src;
    Node * d_index = dest;
    
    map<int,int> src_random;
    map<int,Node *> dest_tracker;
    
    while (s_index) {
        if (!dest) {
            dest= new Node(s_index->val);
            d_index = dest;
        }else {
            d_index->next = new Node(s_index->val);
            d_index = d_index->next;
        }
        
        dest_tracker[d_index->val] = d_index;
        src_random[s_index->val] = s_index->rnd->val;
        
        s_index = s_index->next;
    }
    
    for (map<int,int>::iterator i =  src_random.begin(); i != src_random.end(); i++) {
        dest_tracker[i->first]->rnd = dest_tracker[i->second];
    }
    
    
    return dest;
}

Node * copy_ll_2(Node * src) {
    Node * dest = nullptr;
    Node * s_index = src;
    
    // Interleave new nodes into src list
    while (s_index) {
        Node * tmp  = new Node(s_index->val, s_index->next);
        s_index->next = tmp;
        s_index = tmp->next;
    }
    
    // Set Random links
    s_index = src;
    while (s_index) {
        s_index->next->rnd = s_index->rnd->next;
        s_index = s_index->next->next;
    }
    
    dest = src->next;
    Node * d_index = dest;
    Node * s_prev = src;
    s_index = src->next->next;
    while (s_index) {
        d_index->next = s_index->next;
        s_prev->next = s_index;
        s_prev = s_index;
        s_index = s_index->next->next;
        d_index = d_index->next;
    }
    s_prev->next = nullptr;
    disp (src);
    disp(dest);
    
    
    return dest;
}

void tc_1() {
    
    Node * src = build_test_ll();
    disp(src);
    Node * c = copy_ll(src);
    disp(c);
    
    c = copy_ll_2(src);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    tc_1();
    return 0;
}
