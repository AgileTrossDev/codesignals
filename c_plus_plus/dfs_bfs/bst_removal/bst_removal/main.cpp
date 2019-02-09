//
//  main.cpp
//  bst_removal
//
//  Created by Scott Jackson on 12/18/18.
//  Copyright © 2018 Scott Jackson. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>


using std::cout;
using std::endl;
using std::vector;
using std::queue;

template<typename T>
struct Tree {
  Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
   T value;
   Tree *left;
   Tree *right;

};


void disp_v(vector<Tree<int> *>);


// Transfer tree to a vector.
void build_v(std::vector<Tree<int> *> &v, Tree<int> * t ,std::vector<int> &q) {
    
    if (t) {
        //cout << t->value << " left" << endl;
        build_v(v,t->left,q);
        
        // q and t are already sorted, so fast forward when possible
        while (!q.empty() && t->value > q.front())
            q.erase(q.begin());
        
        if (!q.empty() && t->value == q.front()) {
            q.erase(q.begin());
            if (!v.empty()) v.pop_back();
        } else {
            //cout << t->value << " added" << endl;
            v.push_back(t);
            
        }
        //cout << t->value << " right" << endl;
        build_v(v,t->right,q);
    } else {
        //cout << "NULL ADDED" << endl;
        v.push_back(nullptr);
    }
    
}

Tree<int> *  build_t(std::vector<Tree<int> *> &q,int s =0, int e=0) {
    //cout << "S: " << s << " E: " << e << endl;
    Tree<int> * node = nullptr;
    if (s <e) {
        int mid = ceil((e-s)/2);
        if (mid< s) mid = mid+s;
        if (q[mid] == nullptr) mid++;
        // cout << "S: " << s << " M: " << mid << " V: " << q[mid] << " E: " << e << endl;
        if (q[mid]) {
           
            //cout << "ADDING: " << q[mid]->value<< endl;
            node = new Tree<int>(q[mid]->value);
            node->left = build_t(q, s, mid-1);
            node->right = build_t(q, mid+1, e);
        }
        
        // if (node->left) cout <<  q[mid] <<" L: " << node->left->value;
        //if (node->right) cout << " R: " << node->right->value<< endl;
    }
    return node;
    
}

Tree<int> * deleteFromBST(Tree<int> * t, std::vector<int> queries) {
    
    if (t==nullptr) return t;
    
    std::sort(queries.begin(), queries.end() );
    std::vector<Tree<int> *> tracker;
    build_v(tracker,t,queries);
    

    
    //disp_v(tracker);
    
    
    Tree<int> * res =build_t(tracker,0, tracker.size()-1);
    //cout << "ROOT: " << res->value << endl;
    return res;
    
}

void disp_v(vector<Tree<int> *> root){
    for (int i=0; i<root.size();i++)
        if (root[i])
            cout << root[i]->value << " ";
        else
            cout << "!" << " ";
    
    cout << endl;
    cout << "V LENGTH: " << root.size() << endl;
    
}

void disp(Tree<int> * root) {
    
    if (root == nullptr) return;
    
    queue<Tree<int> *> q;
    q.push(root);
    
    int d = 1;
    int cnt =0;
    while (!q.empty()) {
        if (q.front() != nullptr) {
            cout << q.front()->value << " ";
            q.push(q.front()->left);
            q.push(q.front()->right);
        }
        q.pop();
        cnt++;
        
        if ((pow(2,d)-1) == cnt ) {
            d++;
            cout << endl;
        }
    }
    
    cout << "TOTAL POSSIBLE NODES: " << cnt << endl;
}



void test_case_1() {
    Tree<int>  * root = new Tree<int>(5);
    root->left = new Tree<int>(2);
    root->right = new Tree<int>(6);
    
    root->left->left = new Tree<int>(1);
    root->left->right = new Tree<int>(3);
    
   
    root->right->right = new Tree<int>(8);
    root->right->right->left = new Tree<int>(7);
    
    disp(root);
   
   

    vector<int> queries = {4, 5, 6};
    
    Tree<int> *  res = deleteFromBST(root,  queries);
    disp(res);
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    test_case_1();
    
    cout << "DONE" << endl;
    return 0;
}
