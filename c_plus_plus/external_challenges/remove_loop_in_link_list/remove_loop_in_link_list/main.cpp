//
//  main.cpp
//  remove_loop_in_link_list
//
//  Created by Scott Jackson on 1/13/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//

#include <iostream>
using std::cout;
using std::endl;

struct Node {
    int val;
    Node * link;
    
    Node(int v): val(v), link(nullptr){};
    
    Node* add_link(int v) {
        if (link) {
            return link->add_link(v);
        }
        
        link = new Node(v);
        return link;
    }
    
};

struct LinkList {
  
    Node * root;
    Node * tail;
    
    LinkList() : root(nullptr), tail(nullptr) {};
    LinkList(int v) {
        root = new Node(v);
        tail = root;
    }
    
    void add_link(int v){
        
        if (!root) {
            root =new Node(v);
            tail = root;
        } else if (tail) {
            tail = tail->add_link(v);
        } else {
            // assume root was defined
            root->add_link(v);
            
        }
    }
    
    void disp() {
        Node * index = root;
        cout << "Displaying Link List" << endl;
        while (index) {
            cout << index->val << endl;
            index = index->link;
        }
    }
    
    void rev_disp() {
        Node* index = root;
        rev_disp_util(index);
    }
    
    void rev_disp_util(Node * index) {
        if (index) {
            rev_disp_util(index->link);
            cout << index->val << endl;
        }
    }
    
    Node * find_nth_node(int v) {
        return find_nth_node_util(v,root);
    }
    
    Node * find_nth_node_util(int v, Node * index = nullptr) {
        v--;
        if (!index) return nullptr;
        if (v<1) return index;
        
        return find_nth_node_util(v,index->link);
        
        
    }
    
    void join_link_list(LinkList& ll) {
        if (!root) {
            root = ll.root;
        } else if (tail) {
            tail->link = ll.root;
            
        }
        tail = ll.tail;
        
    }
    
    
    void join_link_list(Node * start) {
        if (!root) {
            root = start;
          
        } else if (tail) {
            tail->link = start;
           
        }
    }
    
    
    // Note: Dangerous- no cycle detection
    Node * find_tail() {
        return  find_tail_util(root);
    }
    
    
    Node * find_tail_util(Node * index) {
        if (!index) return nullptr;
        if (index->link) return find_tail_util(index->link);
        return index;
    }
    
    
    // Returns the collision point when loop is detected
    Node * find_loop() {
        if (!root) return root;
        
        // Set up and validate initial conditions
        //
        // Important: When one index advances, the other must too, so that inital start is S:1 and F:2
        //
        Node * slow_ind = root;
        Node * fast_ind = root->link;
        
        // Root is looped
        if (slow_ind == fast_ind) return fast_ind;
        
        if (fast_ind) {
            // Check before advancing, so we can return end of loop
            if (slow_ind == fast_ind->link) return fast_ind;
            fast_ind = fast_ind->link;
            slow_ind = slow_ind->link;
        } else {
            // Short valid link list
            return nullptr;
        }
        
        return find_loop_util(slow_ind, fast_ind);
    }
    
    Node * find_loop_util( Node *slow_ind,  Node * fast_ind) {
        
        // BASE: hitting a null means no loop
        if (!slow_ind || !fast_ind) return nullptr;
        
        cout << "S: " << slow_ind->val << " F: " << fast_ind->val << endl;
        
        // Cycle found
        if (slow_ind == fast_ind) return fast_ind;
        
        // Advance slow ptr.  Fast index already validated links
        slow_ind = slow_ind->link;
        
        
        fast_ind = fast_ind->link;
        
        //if (slow_ind == fast_ind) return fast_ind;
        
        if (fast_ind) fast_ind = fast_ind->link;
        
        return find_loop_util(slow_ind, fast_ind);
        
    }
    
    
    void correct_loop() {
        Node * looped_node = find_loop();
        
        if (!looped_node) return;
        cout << "COLLISION DETECTED: " << looped_node->val << endl;
        
        int cnt = 1;
        Node * index = looped_node->link;
        
        while (index !=looped_node) {
            cnt++;
            index = index->link;
        }
        
        cout << "LOOP LENGTH: " << cnt<< endl;
        
        index = root;
        while (index != looped_node) {
            //cout << "I: " << index->val << " L:" << looped_node->val << endl;
            index = index->link;
            looped_node = looped_node->link;
        }
        
        cout << "Start of Loop: " << index->val << endl;
        
    }
    
    
    

};




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    LinkList ll;
    
    for (int i= 0; i<15; i++) ll.add_link(i);
    //ll.disp();
    //ll.rev_disp();
    
    Node* loop_marker = nullptr; //ll.find_loop();
    if (!loop_marker) cout << "NO LOOPS FOUND" << endl;
    
    Node * rec = ll.find_nth_node(6);
    cout << "6th Record: " << rec->val << endl;
    
    Node * holder = rec->link;
    
    // Cycle LL for test
    rec->link = ll.root;
    
    //loop_marker = ll.find_loop();
    //cout << "Loop Marker: " << loop_marker->val << endl;
    
    ll.correct_loop();
    
    
    
    return 0;
}
