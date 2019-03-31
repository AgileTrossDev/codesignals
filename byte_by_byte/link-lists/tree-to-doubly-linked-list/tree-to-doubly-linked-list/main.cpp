//
//  main.cpp
//  tree-to-doubly-linked-list
//
//  Created by Scott Jackson on 3/31/19.
//  Copyright © 2019 Scott Jackson. All rights reserved.
//
// Description: Given a tree, write a function to convert it
// into a circular doubly linked list from left to right by
// only modifying the existing pointers.

#include <iostream>

using std::cout;
using std::endl;
/*

struct Node_Two_Links {
    Node_Two_Links(Node_Two_Links* l1 = nullptr, Node_Two_Links * l2 = nullptr ): link1(l1), link2(l2){};
    virtual ~Node_Two_Links() {
        cout << "DELETING NODE" << endl;
        delete link1;
        link1 = nullptr;
        delete link2;
        link2 = nullptr;
    }
    Node_Two_Links * link1;
    Node_Two_Links * link2;
};

struct TreeNode : Node_Two_Links {
    TreeNode(int v):Node_Two_Links(), val(v){};
    
    
    void left(TreeNode* l) {link1 = l; }
    void right(TreeNode* r) {link2 = r; }
    TreeNode* left() {return dynamic_cast<TreeNode*>(link1);}
    TreeNode* right() {return dynamic_cast<TreeNode*>(link2);}
    
    int val;

};

struct LinkListNode : Node_Two_Links {
    LinkListNode(int v):Node_Two_Links(), val(v){};
    
    void next(LinkListNode* l) {link1 = l; }
    void back(LinkListNode* r) {link2 = r; }
    LinkListNode* next() {return dynamic_cast<LinkListNode*>(link1);}
    LinkListNode* back() {return dynamic_cast<LinkListNode*>(link2);}
    
    int val;
};


*/


struct TreeNode {
    TreeNode(int v, TreeNode* l = nullptr, TreeNode* r = nullptr ): val(v),left(l),right(r){};
    int val;
    TreeNode * left;
    TreeNode * right;
    
};

TreeNode * build_test_tree() {
    TreeNode * root = new TreeNode(1);
    
    root->left = new TreeNode(2);
    root->right= new TreeNode(3);
    
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    root->right->left = new TreeNode(6);
    root->right->right =  new TreeNode(7);
    
    
    return root;
}

TreeNode * build_test_tree_2() {
    TreeNode * root = new TreeNode(1);
    
    root->left = new TreeNode(2);
    root->right= new TreeNode(3);
    
    //root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    //root->right->left = new TreeNode(6);
    root->right->right =  new TreeNode(7);
    
    
    return root;
}

void disp_tree(TreeNode * root ) {

    if (root == nullptr) return;
    
    disp_tree(root->left);
    cout << root->val << endl;
    disp_tree(root->right);
    
}

/*
LinkListNode * convert_to_ll(TreeNode *root) {
    
    if (root == nullptr) return nullptr;
    
    
    LinkListNode * lead = convert_to_ll(root->left());
    
    lead->next((LinkListNode *)root);
    lead->next()->back(lead);
    
    LinkListNode * tail = convert_to_ll(root->left());
    lead->next()->next((LinkListNode *)tail);
    
    
    
    
}

*/


// Return null if root is null, else it either returns
// the right most node in ll so far if is_left is true,
// or it returns the left most node in ll if it is false
TreeNode * convert_util(TreeNode *  root, bool is_left = true) {
    
    if (root == nullptr ) return root;
    TreeNode * leading = convert_util(root->left, true);
    
    if (leading != nullptr) {
        leading->right = root;
    }
    root->left = leading;
    
    TreeNode * trailing = convert_util(root->right, false);
    
    if (trailing != nullptr) {
        trailing->left = root;
    }
    root->right = trailing;
    
    
    TreeNode * index= root;
    if (is_left) {
        while (index->right) index = index->right;
    } else {
        while (index->left) index = index->left;
    }
    return index;
}

TreeNode * convert(TreeNode *  root) {
    if (root == nullptr ) return root;
    root = convert_util(root);
    while(root->left) root = root->left;
    return root;
}


void disp_ll(TreeNode * root) {
    
    while (root) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
    
    
}

void tc_2() {
     cout << "\n\nTC 2: " << endl;
    TreeNode * root = build_test_tree_2();
    disp_tree(root);
    
    TreeNode * ll = convert(root);
    
    cout << "LL FRONT: " << ll->val << endl;
    disp_ll(ll);
    delete root;
    
    
}


void tc_1() {
    cout << "TC 1: " << endl;
    TreeNode * root = build_test_tree();
    disp_tree(root);
    
    TreeNode * ll = convert(root);
    
    cout << "LL FRONT: " << ll->val << endl;
     disp_ll(ll);
    
    delete root;
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    tc_1();
    
    tc_2();
    return 0;
}
